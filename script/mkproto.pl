#!/usr/bin/perl
# Simple script for generating prototypes for C functions
# Written by Jelmer Vernooij
# based on the original mkproto.sh by Andrew Tridgell

use strict;

# don't use warnings module as it is not portable enough
# use warnings;

use Getopt::Long;

#####################################################################
# read a file into a string

my $public_file = undef;
my $private_file = undef;
my $public_define = undef;
my $private_define = undef;
my $_public = "";
my $_private = "";
my $public_data = \$_public;
my $private_data = \$_private;

sub public($)
{
	my ($d) = @_;
	$$public_data .= $d;
}

sub private($)
{
	my ($d) = @_;
	$$private_data .= $d;
}

sub usage()
{
	print "Usage: mkproto.pl [options] [c files]\n";
	print "OPTIONS:\n";
	print "  --public=FILE          Write prototypes for public functions to FILE\n";
	print "  --private=FILE         Write prototypes for private functions to FILE\n";
	print "  --define=DEF           Use DEF to check whether header was already included\n";
	print "  --public-define=DEF    Same as --define, but just for public header\n";
	print "  --private-define=DEF   Same as --define, but just for private header\n";
	print "  --help                 Print this help message\n\n";
	exit 0;
}

GetOptions(
	'public=s' => sub { my ($f,$v) = @_; $public_file = $v; },
	'private=s' => sub { my ($f,$v) = @_; $private_file = $v; },
	'define=s' => sub { 
		my ($f,$v) = @_; 
		$public_define = $v; 
		$private_define = "$v\_PRIVATE"; 
	},
	'public-define=s' => \$public_define,
	'private-define=s' => \$private_define,
	'help' => \&usage
) or exit(1);

if (not defined($public_define) and defined($public_file)) {
	$public_define = ".." . uc($public_file) . "__";
	$public_define =~ tr{./}{__};
} elsif (not defined($public_define)) {
	$public_define = '_PROTO_H_';
}

if (not defined($private_define) and defined($private_file)) {
	$private_define = "__" . uc($private_file) . "__";
	$private_define =~ tr{./}{__};
} elsif (not defined($public_define)) {
	$public_define = '_PROTO_H_';
}

if ((defined($private_file) and defined($public_file) and ($private_file eq $public_file)) or 
	(not defined($private_file) and not defined($public_file))) {
	$private_data = $public_data;
}

sub file_load($)
{
    my($filename) = shift;
    local(*INPUTFILE);
    open(INPUTFILE, $filename) || return undef;
    my($saved_delim) = $/;
    undef $/;
    my($data) = <INPUTFILE>;
    close(INPUTFILE);
    $/ = $saved_delim;
    return $data;
}

sub print_header($$)
{
	my ($file, $header_name) = @_;
	$file->("#ifndef $header_name\n");
	$file->("#define $header_name\n\n");
	$file->("#undef _PRINTF_ATTRIBUTE\n");
	$file->("#define _PRINTF_ATTRIBUTE(a1, a2) PRINTF_ATTRIBUTE(a1, a2)\n\n");
	$file->("#ifndef __BEGIN_DECLS\n");
	$file->("#ifdef __cplusplus\n");
	$file->("#define __BEGIN_DECLS		extern \"C\" {\n");
	$file->("#define __END_DECLS		}\n");
	$file->("#else\n");
	$file->("#define __BEGIN_DECLS\n");
	$file->("#define __END_DECLS\n");
	$file->("#endif\n");
	$file->("#endif\n");
	$file->("\n__BEGIN_DECLS\n\n");
	$file->("/* This file was automatically generated by mkproto.pl. DO NOT EDIT */\n\n");
}

sub print_footer($$) 
{
	my ($file, $header_name) = @_;
	$file->("\n__END_DECLS\n\n");
	$file->("#undef _PRINTF_ATTRIBUTE\n");
	$file->("#define _PRINTF_ATTRIBUTE(a1, a2)\n");
	$file->("\n#endif /* $header_name */\n\n");
}

sub handle_loadparm($$) 
{
	my ($file,$line) = @_;

	if ($line =~ /^_PUBLIC_ FN_(GLOBAL|LOCAL)_(CONST_STRING|STRING|bool|CHAR|INTEGER|LIST)\((\w+),.*\)/o) {
		my $scope = $1;
		my $type = $2;
		my $name = $3;

		my %tmap = (
			    "bool" => "bool ",
			    "CONST_STRING" => "const char *",
			    "STRING" => "const char *",
			    "INTEGER" => "int ",
			    "CHAR" => "char ",
			    "LIST" => "const char **",
			    );

		my %smap = (
			    "GLOBAL" => "void",
			    "LOCAL" => "int "
			    );

		$file->("$tmap{$type}$name($smap{$scope});\n");
	}
}

sub delete_arguments($)
{
	my ($proto) = @_;

	chomp($proto);

	# If function with void argument do not process it
	return $proto if ($proto =~ /\(void\)/);

	# Remove the argument name
	$proto =~ s/([\w],[\s])*([\*]*)(\w)*([\,\)])/$1$2$4/g;

	# Remove extra space between type and sep
	$proto =~ s/([\w]+)([\s]+)([\,\)])/$1$3/g;

	# Remove any spaces between , and the next char
	$proto =~ s/([\,])(^[\w]+)([\w\)]+)/$1 $3/g;
	
	# Remove tabulations
	$proto =~ s/[\s]{2,}//g;

	# Remove \n
	$proto =~ s/[\n]+/ /g;

	return $proto;
}

sub process_file($$$) 
{
	my ($public_file, $private_file, $filename) = @_;

	$filename =~ s/\.o$/\.c/g;

	open(FH, "< $filename") || die "Failed to open $filename";

	$private_file->("\n/* The following definitions come from $filename  */\n\n");

	while (my $line = <FH>) {	      
		my $target = \&private;
		my $is_public = 0;

		# these are ordered for maximum speed
		next if ($line =~ /^\s/);
	      
		next unless ($line =~ /\(/);

		next if ($line =~ /^\/|[;]/);

		if ($line =~ /^_PUBLIC_ FN_/) {
			handle_loadparm($public_file, $line);
			next;
		}

		if ($line =~ /^_PUBLIC_[\t ]/) {
			$target = \&public;
			$is_public = 1;
		}

		next unless ( $is_public || $line =~ /
			      ^void|^bool|^int|^struct|^char|^const|^\w+_[tT]\s|^uint|^unsigned|^long|
			      ^NTSTATUS|^ADS_STATUS|^enum\s.*\(|^DATA_BLOB|^WERROR|^XFILE|^FILE|^DIR|
			      ^double|^TDB_CONTEXT|^TDB_DATA|^TALLOC_CTX|^NTTIME|^FN_|^init_module|
			      ^GtkWidget|^GType|^smb_ucs2_t
			      /xo);

		next if ($line =~ /^int\s*main/);

		if ( $line =~ /\(.*\)\s*$/o ) {
			chomp $line;
			$line = delete_arguments($line);
			$target->("$line;\n");
			next;
		}

		$line = delete_arguments($line);
		$target->($line);

		while ($line = <FH>) {
			if ($line =~ /\)\s*$/o) {
				chomp $line;
				$line = delete_arguments($line);
				$target->("$line;\n");
				last;
			}
			$target->($line);
		}
	}

	close(FH);
}

print_header(\&public, $public_define);
if ($public_file ne $private_file) {
	print_header(\&private, $private_define);

	private("/* this file contains prototypes for functions that " .
			"are private \n * to this subsystem or library. These functions " .
			"should not be \n * used outside this particular subsystem! */\n\n");

	public("/* this file contains prototypes for functions that " . 
			"are part of \n * the public API of this subsystem or library. */\n\n");

}

public("#ifndef _PUBLIC_\n#define _PUBLIC_\n#endif\n\n");

process_file(\&public, \&private, $_) foreach (@ARGV);
print_footer(\&public, $public_define);
if ($public_file ne $private_file) {
	print_footer(\&private, $private_define);
}

if (not defined($public_file)) {
	print STDOUT $$public_data;
}

if (not defined($private_file) and defined($public_file)) {
	print STDOUT $$private_data;
}

my $old_public_data = file_load($public_file);
my $old_private_data = file_load($private_file);

if (not defined($old_public_data) or ($old_public_data ne $$public_data))
{
	open(PUBLIC, ">$public_file") or die("Can't open `$public_file': $!"); 
	print PUBLIC "$$public_data";
	close(PUBLIC);
} 

if (($public_file ne $private_file) and (
	not defined($old_private_data) or ($old_private_data ne $$private_data))) {

	open(PRIVATE, ">$private_file") or die("Can't open `$private_file': $!"); 
	print PRIVATE "$$private_data";
	close(PRIVATE);
}