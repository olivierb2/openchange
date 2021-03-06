This is the README file for OpenChange

About OpenChange
----------------

The OpenChange Project aims to provide a portable Open Source
implementation of Microsoft Exchange Server and Exchange
protocols. Exchange is a groupware server designed to work with
Microsoft Outlook, and providing features such as a messaging server,
shared calendars, contact databases, public folders, notes and tasks. 

The OpenChange project has three goals:
* To provide a library for interoperability with Exchange protocols, and
to assist implementers to use this to create groupware that
interoperates with both Exchange and other OpenChange-based software. 

* To provide an alternative to Microsoft Exchange Server which uses
native Exchange protocols and provides exactly equivalent
functionality when viewed from Microsoft Outlook clients. 

* To develop a body of knowledge about the most popular groupware
protocols in use commercially today in order to promote development of
a documented and unencumbered standard, with all the benefits that
standards bring. 


Documentation
-------------

There are two sources of documentation - text files in the doc/
directory, and API documentation generated from the source files using
doxygen. You can create the API documentation yourself (using "make
doxygen" at the top level) or you can refer to the copy on the
OpenChange web site at
http://apidocs.openchange.org/overview/index.html

doc/howto.txt contains instructions on how to install and set up
client libraries, client utilities and the server / proxy parts of
OpenChange.
doc/man/ contains man(1) pages for several OpenChange utilities. Note
that man pages for programming (i.e. the parts that would appear in
man3) are generated by doxygen, and will be found in apidocs/ if you
generate the documentation yourself.
doc/doxygen/ provides static content used as part of the doxygen API
documentation generation process.
doc/examples/ provides programming examples for libmapi.


Structure
---------

- bin/	This directory is created during the build process. It
contains the binaries (executable programs) that are compiled during
the "make" step. The source for most of these is in the utils/
directory, described below.

- doc/  This directory contains documentation - see description above
(in DOCUMENTATION) for the various contents of this directory.

- gen_ndr/  This directory contains routines for handling the Network
Data Representation (NDR) for various Exchange RPC calls. The contents
of this directory are generated (using Samba's pidl IDL compiler) at
build time. The main input file is exchange.idl (see top level
directory).

- libexchange2ical  This directory provides functionality for 
converting between Exchange calendar appointments and ICalendar (RFC2445 /
RFC5545) format. Exchange -> ICalendar is fairly mature, ICalendar to 
Exchange is in work.

- libmapi/  This directory contains the main client-side library,
called libmapi. libmapi closely reflects the underlying protocol
operations (Exchange RPC) being performed between the client and the
server. For more information, consult the API documentation (either
build yourself, or online at
http://apidocs.openchange.org/libmapi/index.html)

- libmapi++/  This directory contains C++ bindings for libmapi. It is
not a replacement for libmapi, but is intended to provide easier
access to many libmapi functions for C++ programmers. For more
information, consult the API documentation (either build yourself, or
online at http://apidocs.openchange.org/libmapi++/index.html)

- libmapiadmin/  This directory contains client-side library functions
for administering OpenChange or Exchange servers. For more
information, consult the API documentation (either build yourself, or
online at http://apidocs.openchange.org/libmapiadmin/index.html). If
you are looking for a program you can run, instead of library
functions to write your own program, "openchangepfadmin" might be of
interest.

- libocpf/  This directory contains library functions for the
OpenChange Property Files (OCPF). This allows building of mail
messages, address book entries, appointments and similar objects from
text files. For more information, consult the API documentation
(either build yourself, or online at
http://apidocs.openchange.org/libocpf/index.html) 

- mapiproxy/ This directory provides an Exchange RPC proxy. You can
use this to provide transparent proxying, or to change / monitor 
connections between the client and server. For more information,
consult the API documentation (either build yourself, or online at
http://apidocs.openchange.org/mapiproxy/index.html) 

- python/  This directory contains python scripts used to set up
("provision") the server side. They are not required for the client
side.

- qt/   This directory contains Qt4 bindings (lib/ subdirectory) and
a sample application (demo/ subdirectory). The sample application 
is intended for research and development use, not as a complete
end-user application.

- samba4/  This directory will be created during the build process if
you call "make samba" or execute the ./script/installsamba4.sh
script. It is used to build samba4, if required.

- script/  This directory contains a range of scripts useful for
development or use of OpenChange. [TODO: document the scripts -
perhaps write script/README?] 

- setup/  This directory contains data for setting up ("provisioning")
the server.

- testprogs/  This directory contains developer test tools

- utils/  This directory contains the source code for a range of
applications / utilities that can be used to interact with an exchange
server. They include:
 - utils/backup/  	backup and restore tools
 - utils/exchange2ical  converts Exchange calendar into an ICal file
 - utils/exchange2mbox	two way conversion between Exchange mail and mbox
 - utils/mapiprofile	set up client side profiles (login information)
 - utils/mapitest/	test tools for libmapi functionality
 - utils/mapitrace/	test tool for tracing MAPI calls
 - utils/openchangeclient	command line client for Exchange RPC
 - utils/openchangepfadmin	Public Folders admin tools and 
				administration of Exchange users (add/del) 
 - utils/schemaIDGUID
For more information on these tools, refer to the man(1) pages in doc/man/man1
