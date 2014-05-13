/* parser auto-generated by mparse */
#include "libmapi/libmapi.h"
#include "libmapi/libmapi_private.h"
#include <locale.h>
#include <langinfo.h>

/**
  \file codepage_lcid.c

  \brief Codepage and Locale ID operations
 */

#define	CP_UNICODE_ONLY                              0
#define	CP_WESTERN_EUROPE_AND_US                     1
#define	CP_CENTRAL_EUROPE                            2
#define	CP_BALTIC                                    3
#define	CP_GREEK                                     4
#define	CP_CYRILLIC                                  5
#define	CP_TURKIC                                    6
#define	CP_JAPANESE                                  7
#define	CP_KOREAN                                    8
#define	CP_TRADITIONAL_CHINESE                       9
#define	CP_SIMPLIFIED_CHINESE                       10
#define	CP_THAI                                     11
#define	CP_HEBREW                                   12
#define	CP_ARABIC                                   13
#define	CP_VIETNAMESE                               14
#define	CP_INDIC                                    15
#define	CP_GEORGIAN                                 16
#define	CP_ARMENIAN                                 17
struct cpid_lcid {
	const char	*language;
	const char	*locale;
	uint32_t	lcid;
	uint32_t	cpid;
	uint32_t	language_group;
};

static const struct cpid_lcid locales[] =
{
	{ "Afrikaans",                     "af_ZA",           0x0436, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Albanian",                      "sq_AL",           0x041c, 1250, CP_CENTRAL_EUROPE        },
	{ "Amharic (Ethiopia)",            "am_ET",           0x045e, 0   , CP_UNICODE_ONLY          },
	{ "Arabic (Algeria)",              "ar_DZ",           0x1401, 1256, CP_ARABIC                },
	{ "Arabic (Bahrain)",              "ar_BH",           0x3c01, 1256, CP_ARABIC                },
	{ "Arabic (Egypt)",                "ar_EG",           0x0c01, 1256, CP_ARABIC                },
	{ "Arabic (Iraq)",                 "ar_SA",           0x0801, 1256, CP_ARABIC                },
	{ "Arabic (Jordan)",               "ar_JO",           0x2c01, 1256, CP_ARABIC                },
	{ "Arabic (Kuwait)",               "ar_KW",           0x3401, 1256, CP_ARABIC                },
	{ "Arabic (Lebanon)",              "ar_LB",           0x3001, 1256, CP_ARABIC                },
	{ "Arabic (Libya)",                "ar_LY",           0x1001, 1256, CP_ARABIC                },
	{ "Arabic (Morocco)",              "ar_MA",           0x1801, 1256, CP_ARABIC                },
	{ "Arabic (Oman)",                 "ar_OM",           0x2001, 1256, CP_ARABIC                },
	{ "Arabic (Qatar)",                "ar_QA",           0x4001, 1256, CP_ARABIC                },
	{ "Arabic (Saudi Arabia)",         "ar_SA",           0x0401, 1256, CP_ARABIC                },
	{ "Arabic (Syria)",                "ar_SY",           0x2801, 1256, CP_ARABIC                },
	{ "Arabic (Tunisia)",              "ar_TN",           0x1c01, 1256, CP_ARABIC                },
	{ "Arabic (U.A.E.)",               "ar_AE",           0x3801, 1256, CP_ARABIC                },
	{ "Arabic (Yemen)",                "ar_YE",           0x2401, 1256, CP_ARABIC                },
	{ "Armenian",                      "hy_AM",           0x042b, 0   , CP_ARMENIAN              },
	{ "Assamese",                      "as_IN",           0x044d, 0   , CP_INDIC                 },
	{ "Azeri (Cyrillic)",              "az_Cyrl_AZ",      0x082c, 1251, CP_CYRILLIC              },
	{ "Azeri (Latin)",                 "az_Latn_AZ",      0x042c, 1254, CP_TURKIC                },
	{ "Basque",                        "eu_ES",           0x042d, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Belarusian",                    "be_BY",           0x0423, 1251, CP_CYRILLIC              },
	{ "Bengali (India)",               "bn_IN",           0x0445, 0   , CP_INDIC                 },
	{ "Bosnian (Bosnia/Herzegovina)",  "bs_Latn_BA",      0x141A, 1250, CP_CENTRAL_EUROPE        },
	{ "Breton (France)",               "br_FR",           0x047e, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Bulgarian",                     "bg_BG",           0x0402, 1251, CP_CYRILLIC              },
	{ "Catalan",                       "ca_ES",           0x0403, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Chinese (Hong Kong S.A.R.)",    "zh_HK",           0x0c04, 950 , CP_TRADITIONAL_CHINESE   },
	{ "Chinese (Macau S.A.R.)",        "zh_MO",           0x1404, 950 , CP_TRADITIONAL_CHINESE   },
	{ "Chinese (PRC)",                 "zh_CN",           0x0804, 936 , CP_SIMPLIFIED_CHINESE    },
	{ "Chinese (Singapore)",           "zh_SG",           0x1004, 936 , CP_SIMPLIFIED_CHINESE    },
	{ "Chinese (Taiwan)",              "zh_TW",           0x0404, 950 , CP_TRADITIONAL_CHINESE   },
	{ "Croatian",                      "hr_HR",           0x041a, 1250, CP_CENTRAL_EUROPE        },
	{ "Croatian (Bosnia/Herzegovina)", "hr_BA",           0x101a, 1250, CP_CENTRAL_EUROPE        },
	{ "Czech",                         "cz_CZ",           0x0405, 1250, CP_CENTRAL_EUROPE        },
	{ "Danish",                        "da_DK",           0x0406, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Dari (Afghanistan)",            "gbz_AF",          0x048c, 1256, CP_ARABIC                },
	{ "Divehi",                        "dv_MV",           0x0465, 0   , CP_UNICODE_ONLY          },
	{ "Dutch (Belgium)",               "nl_BE",           0x0813, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Dutch (Netherlands)",           "nl_NL",           0x0413, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "English (Australia)",           "en_AU",           0x0c09, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "English (Belize)",              "en_BZ",           0x2809, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "English (Canada)",              "en_CA",           0x1009, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "English (Caribbean)",           "en_CB",           0x2409, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "English (India)",               "en_IN",           0x4009, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "English (Ireland)",             "en_IE",           0x1809, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "English (Jamaica)",             "en_JM",           0x2009, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "English (New Zealand)",         "en_NZ",           0x1409, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "English (Philippines)",         "en_PH",           0x3409, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "English (South Africa)",        "en_ZA",           0x1c09, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "English (Trinidad)",            "en_TT",           0x2c09, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "English (United Kingdom)",      "en_GB",           0x0809, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "English (United States)",       "en_US",           0x0409, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "English (Zimbabwe)",            "en_ZW",           0x3009, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Estonian",                      "et_EE",           0x0425, 1257, CP_BALTIC                },
	{ "Faroese",                       "fo_FO",           0x0438, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Farsi",                         "fa_IR",           0x0429, 1256, CP_ARABIC                },
	{ "Filipino",                      "fil_PH",          0x0464, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Finnish",                       "fi_FI",           0x040b, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "French (Belgium)",              "fr_BE",           0x080c, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "French (Cameroon)",             "fr_CM",           0x2c0c, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "French (Canada)",               "fr_CA",           0x0c0c, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "French (Congo,DRC)",            "fr_CG",           0x240c, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "French (Cote d'Ivoire)",        "fr_CI",           0x300c, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "French (France)",               "fr_FR",           0x040c, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "French (Luxembourg)",           "fr_LU",           0x140c, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "French (Mali)",                 "fr_ML",           0x340c, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "French (Monaco)",               "fr_MC",           0x180c, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "French (Morocco)",              "fr_MA",           0x380c, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "French (Senegal)",              "fr_SN",           0x280c, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "French (Switzerland)",          "fr_CH",           0x100c, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "French (West Indies)",          "fr_West_Indies",  0x1c0c, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Frisian (Netherlands)",         "fy_NL",           0x0462, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "FYRO Macedonian",               "mk_MK",           0x042f, 1251, CP_CYRILLIC              },
	{ "Gaelic Ireland",                "ga_IE",           0x083c, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Galician (Spain)",              "gl_ES",           0x0456, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Georgian",                      "ka_GE",           0x0437, 0   , CP_GEORGIAN              },
	{ "German (Austria)",              "de_AT",           0x0c07, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "German (Germany)",              "de_DE",           0x0407, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "German (Liechtenstein)",        "de_LI",           0x1407, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "German (Luxembourg)",           "de_LU",           0x1007, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "German (Switzerland)",          "de_CH",           0x0807, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Greek",                         "el_GR",           0x0408, 1253, CP_GREEK                 },
	{ "Gujarati",                      "gu_IN",           0x0447, 0   , CP_INDIC                 },
	{ "Hebrew",                        "he_IL",           0x040d, 1255, CP_HEBREW                },
	{ "Hindi",                         "hi_IN",           0x0439, 0   , CP_INDIC                 },
	{ "Hungarian",                     "hu_HU",           0x040e, 1250, CP_CENTRAL_EUROPE        },
	{ "Icelandic",                     "is_IS",           0x040f, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Igbo (Nigeria)",                "ig_NG",           0x0470, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Indonesian",                    "id_ID",           0x0421, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Italian (Italy)",               "it_IT",           0x0410, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Italian (Switzerland)",         "it_CH",           0x0810, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Japanese",                      "ja_JP",           0x0411, 932 , CP_JAPANESE              },
	{ "Kannada",                       "kn_IN",           0x044b, 0   , CP_UNICODE_ONLY          },
	{ "Kazakh",                        "kk_KZ",           0x043f, 1251, CP_CYRILLIC              },
	{ "Khmer",                         "km_KH",           0x0453, 0   , CP_UNICODE_ONLY          },
	{ "Konkani",                       "kok_IN",          0x0457, 0   , CP_INDIC                 },
	{ "Korean",                        "ko_KR",           0x0412, 949 , CP_KOREAN                },
	{ "Kyrgyz (Cyrillic)",             "ky_KG",           0x0440, 1251, CP_CYRILLIC              },
	{ "Lao",                           "lo_LA",           0x0454, 0   , CP_UNICODE_ONLY          },
	{ "Latvian",                       "lv_LV",           0x0426, 1257, CP_BALTIC                },
	{ "Lithuanian",                    "lt_LT",           0x0427, 1257, CP_BALTIC                },
	{ "Macedonian",                    "mk_MK",           0x042f, 1251, CP_CYRILLIC              },
	{ "Malay (Brunei Darussalam)",     "ms_BN",           0x083e, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Malay (Malaysia)",              "ms_MY",           0x043e, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Malayalam",                     "ml_IN",           0x044c, 0   , CP_UNICODE_ONLY          },
	{ "Maltese",                       "mt_MT",           0x043a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Maori (New Zealand)",           "mi_NZ",           0x0481, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Marathi",                       "ms_IN",           0x044e, 0   , CP_INDIC                 },
	{ "Mongolian (Cyrillic)",          "mn_MN",           0x0450, 1251, CP_CYRILLIC              },
	{ "Mongolian (Mongolia)",          "mn_Mong_CN",      0x0850, 0   , CP_UNICODE_ONLY          },
	{ "Nepali",                        "ne_NP",           0x0461, 0   , CP_UNICODE_ONLY          },
	{ "Norwegian (Bokmal)",            "nb_NO",           0x0414, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Norwegian (Nynorsk)",           "nn_NO",           0x0814, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Oriya",                         "or_IN",           0x0448, 0   , CP_INDIC                 },
	{ "Polish",                        "pl_PL",           0x0415, 1250, CP_CENTRAL_EUROPE        },
	{ "Portuguese (Brazil)",           "pt_BR",           0x0416, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Portuguese (Portugal)",         "pt_PT",           0x0816, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Punjabi",                       "pa_IN",           0x0446, 0   , CP_INDIC                 },
	{ "Rhaeto-Romanic",                "rm_CH",           0x0417, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Romanian",                      "ro_RM",           0x0418, 1250, CP_CENTRAL_EUROPE        },
	{ "Romanian (Moldova)",            "ro_MO",           0x0818, 819 , CP_CENTRAL_EUROPE        },
	{ "Russian",                       "ru_RU",           0x0419, 1251, CP_CYRILLIC              },
	{ "Sami Lappish",                  "se_NO",           0x043b, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Sanskrit",                      "sa_IN",           0x044f, 0   , CP_INDIC                 },
	{ "Serbian (Cyrillic)",            "sr_Cyrl_CS",      0x0c1a, 1251, CP_CYRILLIC              },
	{ "Serbian (Latin)",               "sr_Latn_CS",      0x081a, 1250, CP_CENTRAL_EUROPE        },
	{ "Sindhi",                        "sd_IN",           0x0459, 0   , CP_INDIC                 },
	{ "Sinhalese (Sri Lanka)",         "si_LK",           0x045b, 0   , CP_UNICODE_ONLY          },
	{ "Slovak",                        "sk_SK",           0x041b, 1250, CP_CENTRAL_EUROPE        },
	{ "Slovenian",                     "sl_SI",           0x0424, 1250, CP_CENTRAL_EUROPE        },
	{ "Spanish (Argentina)",           "es_AR",           0x2c0a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (Bolivia)",             "es_BO",           0x400a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (Chile)",               "es_CL",           0x340a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (Colombia)",            "es_CO",           0x240a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (Costa Rica)",          "es_CR",           0x140a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (Dominican Republic)",  "es_DO",           0x1c0a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (Ecuador)",             "es_EC",           0x300a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (El Salvador)",         "es_SV",           0x440a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (Guatemala)",           "es_GT",           0x100a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (Honduras)",            "es_HN",           0x480a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (International Sort)",  "es_ES",           0x0c0a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (Mexico)",              "es_MX",           0x080a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (Nicaragua)",           "es_NI",           0x4c0a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (Panama)",              "es_PA",           0x180a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (Paraguay)",            "es_PY",           0x3c0a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (Peru)",                "es_PE",           0x280a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (Puerto Rico)",         "es_PR",           0x500a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (Traditional Sort)",    "es_ES_tradnl",    0x040a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (Uruguay)",             "es_UY",           0x380a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Spanish (Venezuela)",           "es_VE",           0x200a, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Swahili",                       "sw_KE",           0x0441, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Swedish",                       "sv_SE",           0x041d, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Swedish (Finland)",             "sv_FI",           0x081d, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Tajik",                         "tg_Cyrl_TJ",      0x0428, 1251, CP_CYRILLIC              },
	{ "Tamil",                         "ta_IN",           0x0449, 0   , CP_INDIC                 },
	{ "Tatar",                         "tt_RU",           0x0444, 1251, CP_CYRILLIC              },
	{ "Telegu",                        "te_IN",           0x044a, 0   , CP_INDIC                 },
	{ "Thai",                          "th_TH",           0x041e, 874 , CP_THAI                  },
	{ "Tibetan",                       "bo_CN",           0x0451, 0   , CP_UNICODE_ONLY          },
	{ "Tsonga",                        "ts_ZA",           0x0431, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Twana",                         "tn_ZA",           0x0432, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Turkish",                       "tr_TR",           0x041f, 1254, CP_TURKIC                },
	{ "Turkmen",                       "tk_TM",           0x0442, 1251, CP_CYRILLIC              },
	{ "Ukrainian",                     "uk_UA",           0x0422, 1251, CP_CYRILLIC              },
	{ "Urdu",                          "ur_PK",           0x0420, 1256, CP_ARABIC                },
	{ "Uzbek (Cyrillic)",              "uz_Cyrl_UZ",      0x0843, 1251, CP_CYRILLIC              },
	{ "Uzbek (Latin)",                 "uz_Latn_UZ",      0x0443, 1254, CP_TURKIC                },
	{ "Venda",                         "ven_ZA",          0x0433, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Vietnamese",                    "vi_VN",           0x042a, 1258, CP_VIETNAMESE            },
	{ "Welsh",                         "cy_GB",           0x0452, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Wolof (Senegal)",               "wo_SN",           0x0488, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Xhosa",                         "xh_ZA",           0x0434, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "Zulu",                          "zu_ZA",           0x0435, 1252, CP_WESTERN_EUROPE_AND_US },
	{ "C",                             "C",               0x0409, 1252, CP_WESTERN_EUROPE_AND_US },
	{ NULL, NULL, 0, 0, 0 }
};

/**
  \details Returns current locale used by the system

 \return pointer to locale string on success, otherwise NULL
 */
_PUBLIC_ char *mapi_get_system_locale(void)
{
	char	*locale;
	
	locale = setlocale(LC_CTYPE, "");
	return locale;
}

/**
  \details Verify if the specified codepage is valid

  \param cpid the codepage to lookup

  \return 0 on success, otherwise 1
 */
_PUBLIC_ bool mapi_verify_cpid(uint32_t cpid)
{
	uint32_t	i;
	
	for (i = 0; locales[i].lcid; i++) {
		if (cpid == locales[i].cpid) {
			return true;
		}
	}
	
	return false;
}

/**
  \details Returns codepage for a given LCID (Locale ID)

  \param lcid the locale ID to lookup

  \return non-zero codepage on success, otherwise 0 if
   only unicode is supported for this language
 */
_PUBLIC_ uint32_t mapi_get_cpid_from_lcid(uint32_t lcid)
{
	uint32_t	i;
	
	for (i = 0; locales[i].lcid; i++) {
		if (lcid == locales[i].lcid) {
			return locales[i].cpid;
		}
	}
	
	return 0;
}

/**
  \details Return codepage associated to specified locale

  \param locale The locale string to lookup

  \return non-zero codepage on success, otherwise 0
 */
_PUBLIC_ uint32_t mapi_get_cpid_from_locale(const char *locale)
{
	uint32_t	i;
	
	/* Sanity Checks */
	if (!locale) return 0;
	
	for (i = 0; locales[i].locale; i++) {
		if (locales[i].locale && !strncmp(locales[i].locale, locale, strlen(locales[i].locale))) {
			return locales[i].cpid;
		}
	}
	
	return 0;
}

/**
  \details Return codepage associated to specified language

  \param language The language string to lookup

  \return non-zero codepage on success, otherwise 0
 */
_PUBLIC_ uint32_t mapi_get_cpid_from_language(const char *language)
{
	uint32_t	i;
	
	/* Sanity Checks */
	if (!language) return 0;
	
	for (i = 0; locales[i].language; i++) {
		if (locales[i].language && !strncmp(locales[i].language, language, strlen(locales[i].language))) {
			return locales[i].cpid;
		}
	}
	
	return 0;
}

/**
  \details Returns LCID (Locale ID) for a given locale

  \param locale the locale string to lookup

  \return non-zero LCID on success, otherwise 0
 */
_PUBLIC_ uint32_t mapi_get_lcid_from_locale(const char *locale)
{
	uint32_t	i;
	
	/* Sanity Checks */
	if (!locale) return 0;
	
	for (i = 0; locales[i].locale; i++) {
		if (locales[i].locale && !strncmp(locales[i].locale, locale, strlen(locales[i].locale))) {
			return locales[i].lcid;
		}
	}
	
	return 0;
}

/**
  \details Returns LCID (Locale ID) for a given language

  \param language the language string to lookup

  \return non-zero LCID on success, otherwise 0
 */
_PUBLIC_ uint32_t mapi_get_lcid_from_language(const char *language)
{
	uint32_t	i;
	
	/* Sanity Checks */
	if (!language) return 0;
	
	for (i = 0; locales[i].language; i++) {
		if (locales[i].language && !strncmp(locales[i].language, language, strlen(locales[i].language))) {
			return locales[i].lcid;
		}
	}
	
	return 0;
}

/**
  \details Returns Locale for a given Locale ID

  \param lcid the locale ID to lookup

  \return locale string on success, otherwise NULL
 */
_PUBLIC_ const char *mapi_get_locale_from_lcid(uint32_t lcid)
{
	uint32_t	i;
	
	for (i = 0; locales[i].lcid; i++) {
		if (locales[i].lcid == lcid) {
			return locales[i].locale;
		}
	}
	
	return NULL;
}

/**
  \details Returns Locale for a given language

  \param language the language string to lookup

  \return Locale string on success, otherwise NULL
 */
_PUBLIC_ const char *mapi_get_locale_from_language(const char *language)
{
	uint32_t	i;
	
	/* Sanity Checks */
	if (!language) return NULL;
	
	for (i = 0; locales[i].language; i++) {
		if (locales[i].language && !strncmp(locales[i].language, language, strlen(locales[i].language))) {
			return locales[i].locale;
		}
	}
	
	return NULL;
}

/**
  \details Returns Language for a given Locale

  \param locale the language string to lookup

  \return Language string on success, otherwise NULL
 */
_PUBLIC_ const char *mapi_get_language_from_locale(const char *locale)
{
	uint32_t	i;
	
	/* Sanity Checks */
	if (!locale) return NULL;
	
	for (i = 0; locales[i].locale; i++) {
		if (locales[i].locale && !strncmp(locales[i].locale, locale, strlen(locales[i].locale))) {
			return locales[i].language;
		}
	}
	
	return NULL;
}

/**
  \details Returns Language for a given Locale ID

  \param lcid the locale ID to lookup

  \return language string on success, otherwise NULL
 */
_PUBLIC_ const char *mapi_get_language_from_lcid(uint32_t lcid)
{
	uint32_t	i;
	
	for (i = 0; locales[i].lcid; i++) {
		if (locales[i].lcid == lcid) {
			return locales[i].language;
		}
	}
	
	return NULL;
}

/**
  \details Returns List of languages for a given Language Group

  \param mem_ctx pointer to the memory context
  \param group the locale group to lookup

  \return Array of languages string on success, otherwise NULL
 */
_PUBLIC_ char **mapi_get_language_from_group(TALLOC_CTX *mem_ctx, uint32_t group)
{
	uint32_t	i;
	uint32_t	counter = 0;
	char		**languages;
	
	/* Sanity Checks */
	if (!mem_ctx) return NULL;
	
	languages = talloc_array(mem_ctx, char *, counter + 1);
	for (i = 0; locales[i].language; i++) {
		if (locales[i].language_group == group) {
			languages = talloc_realloc(mem_ctx, languages, char *, counter + 1);
			languages[counter] = talloc_strdup(languages, locales[i].language);
			counter += 1;
		}
	}
	
	if (!counter) {
		talloc_free(languages);
		return NULL;
	}
	
	return languages;
}

void mapi_get_language_list(void)
{
	uint32_t	i;
	
	for (i = 0; locales[i].language; i++) {
		printf("%s\n", locales[i].language);
	}
}