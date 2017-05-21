#ifndef __COLOURS_H__
#define __COLOURS_H__

#include <ansi.h>

// Especiales
#define TC_KEY_NORMAL   "Normal"
#define TC_KEY_BRIGHT   "Bright"
#define TC_KEY_DIM      "Dim"
#define TC_KEY_ITALIC   "Italic"
#define TC_KEY_UNDERL   "Underl"
#define TC_KEY_BLINK    "Blink"
#define TC_KEY_INVERS   "Invers"
#define TC_KEY_HIDDEN   "Hidden"
#define TC_KEY_STRIKE   "Strike"

#define TC_KEY_BOLD     TC_KEY_BRIGHT

#define TC_KEY_BOLD_OFF         "BoldOff" // Apagar negrita
#define TC_KEY_ITALIC_OFF       "ItalicOff" // Apagar cursiva
#define TC_KEY_UNDERLINE_OFF    "UnderlOff" // Apagar subrayado
#define TC_KEY_BLINK_OFF        "BlinkOff"  // Apagar parpadear
#define TC_KEY_INVERSE_OFF      "InversOff" // Apagar inversa
#define TC_KEY_HIDDEN_OFF       "HiddenOff" // Apagar hidden?
#define TC_KEY_STRIKETHROUGH_OFF   "StrikeOff" // Apagar tachada

#define TC_KEY_UNDERL_OFF     TC_KEY_UNDERLINE_OFF
#define TC_KEY_INVERS_OFF     TC_KEY_INVERSE_OFF
#define TC_KEY_STRIKE_OFF     TC_KEY_STRIKETHROUGH_OFF

// Colores
#define TC_KEY_BLACK        "Black"
#define TC_KEY_RED          "Red"
#define TC_KEY_GREEN        "Green"
#define TC_KEY_YELLOW       "Yellow"
#define TC_KEY_BLUE         "Blue"
#define TC_KEY_PURPLE       "Purple"
#define TC_KEY_CYAN         "Cyan"
#define TC_KEY_WHITE        "White"
#define TC_KEY_DEFAULT      "Default"
#define TC_KEY_CNORMAL      TC_KEY_DEFAULT

// Fondo
#define TC_KEY_BG_BLACK     "BGBlack"
#define TC_KEY_BG_RED       "BGRed"
#define TC_KEY_BG_GREEN     "BGGreen"
#define TC_KEY_BG_YELLOW    "BGYellow"
#define TC_KEY_BG_BLUE      "BGBlue"
#define TC_KEY_BG_PURPLE    "BGPurple"
#define TC_KEY_BG_CYAN      "BGCyan"
#define TC_KEY_BG_WHITE     "BGWhite"
#define TC_KEY_BG_DEFAULT   "BGDefault"
#define TC_KEY_BG_CNORMAL   TC_KEY_BG_DEFAULT

// Combate
#define TC_KEY_COMBAT_ATACO     "Ataco"
#define TC_KEY_COMBAT_DEFIENDO  "Defiendo"
#define TC_KEY_COMBAT_OTRO      "Otro"

// Salidas
#define TC_KEY_EXIT         "Exit"

// Tels
#define TC_KEY_TEL_WHO     "TelWho"
#define TC_KEY_TEL_MSG     "TelMsg"

// Canales
// Generales
#define TC_KEY_GOD_WHO      "GodWho"
#define TC_KEY_GOD_MSG      "GodMsg"
#define TC_KEY_ARCH_WHO     "ArchWho"
#define TC_KEY_ARCH_MSG     "ArchMsg"
#define TC_KEY_WIZ_WHO      "WizWho"
#define TC_KEY_WIZ_MSG      "WizMsg"
#define TC_KEY_JAN_WHO      "JanWho"
#define TC_KEY_JAN_MSG      "JanMsg"
#define TC_KEY_JUGADORES_WHO "JugadoresWho"
#define TC_KEY_JUGADORES_MSG "JugadoresMsg"
// Del mud
#define TC_KEY_ERROR_WHO    "ErrorWho"
#define TC_KEY_ERROR_MSG    "ErrorMsg"
#define TC_KEY_MUD_WHO      "MudWho"
#define TC_KEY_MUD_MSG      "MudMsg"
#define TC_KEY_INFO_WHO     "InfoWho"
#define TC_KEY_INFO_MSG     "InfoMsg"
#define TC_KEY_INFOMUD_WHO     "InfoMudWho"
#define TC_KEY_INFOMUD_MSG     "InfoMudMsg"
// Especiales
#define TC_KEY_INTERMUD_WHO "IntermudWho"
#define TC_KEY_INTERMUD_MSG "IntermudMsg"
#define TC_KEY_LPC_WHO      "LpcWho"
#define TC_KEY_LPC_MSG      "LpcMsg"
#define TC_KEY_VALENCIA_WHO "ValenciaWho"
#define TC_KEY_VALENCIA_MSG "ValenciaMsg"
#define TC_KEY_AYUDA_WHO    "AyudaWho"
#define TC_KEY_AYUDA_MSG    "AyudaMsg"
#define TC_KEY_COLISEUM_WHO "ColiseumWho"
#define TC_KEY_COLISEUM_MSG "ColiseumMsg"
#define TC_KEY_TRIVIAL_WHO  "TrivialWho"
#define TC_KEY_TRIVIAL_MSG  "TrivialMsg"
// Gremios
#define TC_KEY_ASESINOS_MSG         "AsesinosMsg"
#define TC_KEY_ASESINOS_WHO         "AsesinosWho"
#define TC_KEY_AVENTUREROS_MSG      "AventurerosMsg"
#define TC_KEY_AVENTUREROS_WHO      "AventurerosWho"
#define TC_KEY_CONJURADORES_MSG     "ConjuradoresMsg"
#define TC_KEY_CONJURADORES_WHO     "ConjuradoresWho"
#define TC_KEY_GUARDABOSQUES_MSG    "GuardabosquesMsg"
#define TC_KEY_GUARDABOSQUES_WHO    "GuardabosquesWho"
#define TC_KEY_GUERREROS_MSG        "GuerrerosMsg"
#define TC_KEY_GUERREROS_WHO        "GuerrerosWho"
#define TC_KEY_HECHICEROS_MSG       "HechicerosMsg"
#define TC_KEY_HECHICEROS_WHO       "HechicerosWho"
#define TC_KEY_KISALAS_MSG          "KisalasMsg"
#define TC_KEY_KISALAS_WHO          "KisalasWho"
// Dominios
#define TC_KEY_AKALLAB_MSG          "AkallabMsg"
#define TC_KEY_AKALLAB_WHO          "AkallabWho"
#define TC_KEY_GOLDHAI_MSG          "GoldhaiMsg"
#define TC_KEY_GOLDHAI_WHO          "GoldhaiWho"
#define TC_KEY_KENTON_MSG           "KentonMsg"
#define TC_KEY_KENTON_WHO           "KentonWho"
#define TC_KEY_KHA_ANNU_MSG         "Kha-annuMsg"
#define TC_KEY_KHA_ANNU_WHO         "Kha-annuWho"
#define TC_KEY_LAD_LAURELIN_MSG     "Lad-laurelinMsg"
#define TC_KEY_LAD_LAURELIN_WHO     "Lad-laurelinWho"
#define TC_KEY_LIMBO_MSG            "LimboMsg"
#define TC_KEY_LIMBO_WHO            "LimboWho"
#define TC_KEY_SIMAURIA_MSG         "SimauriaMsg"
#define TC_KEY_SIMAURIA_WHO         "SimauriaWho"
#define TC_KEY_AMAN_MSG         "AmanMsg"
#define TC_KEY_AMAN_WHO         "AmanWho"
#define TC_KEY_BREE_MSG         "BreeMsg"
#define TC_KEY_BREE_WHO         "BreeWho"
/*
#define TC_KEY__WHO         "Who"
#define TC_KEY__MSG         "Msg"
*/

#define TC_KEY      "%^"

// Especiales
#define TC_NORMAL       TC_KEY  TC_KEY_NORMAL       TC_KEY
#define TC_BRIGHT       TC_KEY  TC_KEY_BRIGHT       TC_KEY
#define TC_DIM          TC_KEY  TC_KEY_DIN          TC_KEY
#define TC_BOLD         TC_KEY  TC_KEY_BOLD         TC_KEY
#define TC_ITALIC       TC_KEY  TC_KEY_ITALIC       TC_KEY
#define TC_UNDERL       TC_KEY  TC_KEY_UNDERL       TC_KEY
#define TC_BLINK        TC_KEY  TC_KEY_BLINK        TC_KEY
#define TC_INVERS       TC_KEY  TC_KEY_INVERS       TC_KEY
#define TC_HIDDEN       TC_KEY  TC_KEY_HIDDEN       TC_KEY
#define TC_STRIKE       TC_KEY  TC_KEY_STRIKE       TC_KEY

#define TC_BOLD_OFF     TC_KEY  TC_KEY_BOLD_OFF     TC_KEY
#define TC_ITALIC_OFF   TC_KEY  TC_KEY_ITALIC_OFF   TC_KEY
#define TC_UNDERL_OFF   TC_KEY  TC_KEY_UNDERL_OFF   TC_KEY
#define TC_BLINK_OFF    TC_KEY  TC_KEY_BLINK_OFF    TC_KEY
#define TC_INVERS_OFF   TC_KEY  TC_KEY_INVERS_OFF   TC_KEY
#define TC_HIDDEN_OFF   TC_KEY  TC_KEY_HIDDEN_OFF   TC_KEY
#define TC_STRIKE_OFF   TC_KEY  TC_KEY_STRIKE_OFF   TC_KEY

// Colores
#define TC_BLACK        TC_KEY  TC_KEY_BLACK        TC_KEY
#define TC_RED          TC_KEY  TC_KEY_RED          TC_KEY
#define TC_GREEN        TC_KEY  TC_KEY_GREEN        TC_KEY
#define TC_YELLOW       TC_KEY  TC_KEY_YELLOW       TC_KEY
#define TC_BLUE         TC_KEY  TC_KEY_BLUE         TC_KEY
#define TC_PURPLE       TC_KEY  TC_KEY_PURPLE       TC_KEY
#define TC_CYAN         TC_KEY  TC_KEY_CYAN         TC_KEY
#define TC_WHITE        TC_KEY  TC_KEY_WHITE        TC_KEY
#define TC_CNORMAL      TC_KEY  TC_KEY_CNORMAL      TC_KEY

// Fondo
#define TC_BG_BLACK     TC_KEY  TC_KEY_BG_BLACK     TC_KEY
#define TC_BG_RED       TC_KEY  TC_KEY_BG_RED       TC_KEY
#define TC_BG_GREEN     TC_KEY  TC_KEY_BG_GREEN     TC_KEY
#define TC_BG_YELLOW    TC_KEY  TC_KEY_BG_YELLOW    TC_KEY
#define TC_BG_BLUE      TC_KEY  TC_KEY_BG_BLUE      TC_KEY
#define TC_BG_PURPLE    TC_KEY  TC_KEY_BG_PURPLE    TC_KEY
#define TC_BG_CYAN      TC_KEY  TC_KEY_BG_CYAN      TC_KEY
#define TC_BG_WHITE     TC_KEY  TC_KEY_BG_WHITE     TC_KEY
#define TC_BG_DEFAULT   TC_KEY  TC_KEY_BG_DEFAULT   TC_KEY
#define TC_BG_CNORMAL   TC_KEY  TC_KEY_BG_CNORMAL   TC_KEY

// Combate
#define TC_COMBAT_ATACO    TC_KEY TC_KEY_COMBAT_ATACO       TC_KEY
#define TC_COMBAT_DEFIENDO TC_KEY TC_KEY_COMBAT_DEFIENDO    TC_KEY
#define TC_COMBAT_OTRO     TC_KEY TC_KEY_COMBAT_OTRO        TC_KEY

// Salidas
#define TC_EXIT         TC_KEY TC_KEY_EXIT       TC_KEY

// Tels
#define TC_TEL_WHO     TC_KEY TC_KEY_TEL_WHO   TC_KEY
#define TC_TEL_MSG     TC_KEY TC_KEY_TEL_MSG   TC_KEY

// Canales
// Generales
#define TC_GOD_WHO              TC_KEY TC_KEY_GOD_WHO            TC_KEY
#define TC_GOD_MSG              TC_KEY TC_KEY_GOD_MSG            TC_KEY
#define TC_ARCH_WHO             TC_KEY TC_KEY_ARCH_WHO           TC_KEY
#define TC_ARCH_MSG             TC_KEY TC_KEY_ARCH_MSG           TC_KEY
#define TC_WIZ_WHO              TC_KEY TC_KEY_WIZ_WHO            TC_KEY
#define TC_WIZ_MSG              TC_KEY TC_KEY_WIZ_MSG            TC_KEY
#define TC_JAN_WHO              TC_KEY TC_KEY_JAN_WHO            TC_KEY
#define TC_JAN_MSG              TC_KEY TC_KEY_JAN_MSG            TC_KEY
#define TC_JUGADORES_WHO        TC_KEY TC_KEY_JUGADORES_WHO      TC_KEY
#define TC_JUGADORES_MSG        TC_KEY TC_KEY_JUGADORES_MSG      TC_KEY
// Del mud
#define TC_ERROR_WHO            TC_KEY TC_KEY_ERROR_WHO          TC_KEY
#define TC_ERROR_MSG            TC_KEY TC_KEY_ERROR_MSG          TC_KEY
#define TC_MUD_WHO              TC_KEY TC_KEY_MUD_WHO            TC_KEY
#define TC_MUD_MSG              TC_KEY TC_KEY_MUD_MSG            TC_KEY
#define TC_INFO_WHO             TC_KEY TC_KEY_INFO_WHO           TC_KEY
#define TC_INFO_MSG             TC_KEY TC_KEY_INFO_MSG           TC_KEY
#define TC_INFOMUD_WHO              TC_KEY TC_KEY_INFOMUD_WHO            TC_KEY
#define TC_INFOMUD_MSG              TC_KEY TC_KEY_INFOMUD_MSG            TC_KEY
// Especiales
#define TC_LPC_WHO              TC_KEY TC_KEY_LPC_WHO            TC_KEY
#define TC_LPC_MSG              TC_KEY TC_KEY_LPC_MSG            TC_KEY
#define TC_VALENCIA_WHO         TC_KEY TC_KEY_VALENCIA_WHO       TC_KEY
#define TC_VALENCIA_MSG         TC_KEY TC_KEY_VALENCIA_MSG       TC_KEY
#define TC_AYUDA_WHO            TC_KEY TC_KEY_AYUDA_WHO          TC_KEY
#define TC_AYUDA_MSG            TC_KEY TC_KEY_AYUDA_MSG          TC_KEY
#define TC_COLISEUM_WHO         TC_KEY TC_KEY_COLISEUM_WHO       TC_KEY
#define TC_COLISEUM_MSG         TC_KEY TC_KEY_COLISEUM_MSG       TC_KEY
#define TC_TRIVIAL_WHO          TC_KEY TC_KEY_TRIVIAL_WHO        TC_KEY
#define TC_TRIVIAL_MSG          TC_KEY TC_KEY_TRIVIAL_MSG        TC_KEY
// Gremios
#define TC_ASESINOS_MSG         TC_KEY TC_KEY_ASESINOS_MSG       TC_KEY
#define TC_ASESINOS_WHO         TC_KEY TC_KEY_ASESINOS_WHO       TC_KEY
#define TC_AVENTUREROS_MSG      TC_KEY TC_KEY_AVENTUREROS_MSG    TC_KEY
#define TC_AVENTUREROS_WHO      TC_KEY TC_KEY_AVENTUREROS_WHO    TC_KEY
#define TC_CONJURADORES_MSG     TC_KEY TC_KEY_CONJURADORES_MSG   TC_KEY
#define TC_CONJURADORES_WHO     TC_KEY TC_KEY_CONJURADORES_WHO   TC_KEY
#define TC_GUARDABOSQUES_MSG    TC_KEY TC_KEY_GUARDABOSQUES_MSG  TC_KEY
#define TC_GUARDABOSQUES_WHO    TC_KEY TC_KEY_GUARDABOSQUES_WHO  TC_KEY
#define TC_GUERREROS_MSG        TC_KEY TC_KEY_GUERREROS_MSG      TC_KEY
#define TC_GUERREROS_WHO        TC_KEY TC_KEY_GUERREROS_WHO      TC_KEY
#define TC_HECHICEROS_MSG       TC_KEY TC_KEY_HECHICEROS_MSG     TC_KEY
#define TC_HECHICEROS_WHO       TC_KEY TC_KEY_HECHICEROS_WHO     TC_KEY
#define TC_KISALAS_MSG          TC_KEY TC_KEY_KISALAS_MSG        TC_KEY
#define TC_KISALAS_WHO          TC_KEY TC_KEY_KISALAS_WHO        TC_KEY
// Dominios
#define TC_AKALLAB_MSG          TC_KEY TC_KEY_AKALLAB_MSG        TC_KEY
#define TC_AKALLAB_WHO          TC_KEY TC_KEY_AKALLAB_WHO        TC_KEY
#define TC_GOLDHAI_MSG          TC_KEY TC_KEY_GOLDHAI_MSG        TC_KEY
#define TC_GOLDHAI_WHO          TC_KEY TC_KEY_GOLDHAI_WHO        TC_KEY
#define TC_KENTON_MSG           TC_KEY TC_KEY_KENTON_MSG         TC_KEY
#define TC_KENTON_WHO           TC_KEY TC_KEY_KENTON_WHO         TC_KEY
#define TC_KHA_ANNU_MSG         TC_KEY TC_KEY_KHA_ANNU_MSG       TC_KEY
#define TC_KHA_ANNU_WHO         TC_KEY TC_KEY_KHA_ANNU_WHO       TC_KEY
#define TC_LAD_LAURELIN_MSG     TC_KEY TC_KEY_LAD_LAURELIN_MSG   TC_KEY
#define TC_LAD_LAURELIN_WHO     TC_KEY TC_KEY_LAD_LAURELIN_WHO   TC_KEY
#define TC_LIMBO_MSG            TC_KEY TC_KEY_LIMBO_MSG          TC_KEY
#define TC_LIMBO_WHO            TC_KEY TC_KEY_LIMBO_WHO          TC_KEY
#define TC_SIMAURIA_MSG         TC_KEY TC_KEY_SIMAURIA_MSG       TC_KEY
#define TC_SIMAURIA_WHO         TC_KEY TC_KEY_SIMAURIA_WHO       TC_KEY
#define TC_AMAN_MSG          TC_KEY TC_KEY_AMAN_MSG        TC_KEY
#define TC_AMAN_WHO          TC_KEY TC_KEY_AMAN_WHO        TC_KEY
#define TC_BREE_MSG          TC_KEY TC_KEY_BREE_MSG        TC_KEY
#define TC_BREE_WHO          TC_KEY TC_KEY_BREE_WHO        TC_KEY
//----------------------------------------------------------------------------
#define NO_COLOURS      ([ 0: "" ])
#define DEFAULT_COLOURS ([                                              \
TC_KEY_NORMAL       : ANSI_NORMAL       ,    \
TC_KEY_BRIGHT       : ANSI_BRIGHT       ,    \
TC_KEY_DIM          : ANSI_DIM          ,    \
TC_KEY_BOLD         : ANSI_BOLD         ,    \
TC_KEY_ITALIC       : ANSI_ITALIC       ,    \
TC_KEY_UNDERL       : ANSI_UNDERL       ,    \
TC_KEY_BLINK        : ANSI_BLINK        ,    \
TC_KEY_INVERS       : ANSI_INVERS       ,    \
TC_KEY_HIDDEN       : ANSI_HIDDEN       ,    \
TC_KEY_STRIKE       : ANSI_STRIKE       ,    \
                                             \
TC_KEY_BOLD_OFF     : ANSI_BOLD_OFF     ,    \
TC_KEY_ITALIC_OFF   : ANSI_ITALIC_OFF   ,    \
TC_KEY_UNDERL_OFF   : ANSI_UNDERL_OFF   ,    \
TC_KEY_BLINK_OFF    : ANSI_BLINK_OFF    ,    \
TC_KEY_INVERS_OFF   : ANSI_INVERS_OFF   ,    \
TC_KEY_HIDDEN_OFF   : ANSI_HIDDEN_OFF   ,    \
TC_KEY_STRIKE_OFF   : ANSI_STRIKE_OFF   ,    \
                                             \
TC_KEY_BLACK        : ANSI_BLACK        ,    \
TC_KEY_RED          : ANSI_RED          ,    \
TC_KEY_GREEN        : ANSI_GREEN        ,    \
TC_KEY_YELLOW       : ANSI_YELLOW       ,    \
TC_KEY_BLUE         : ANSI_BLUE         ,    \
TC_KEY_PURPLE       : ANSI_PURPLE       ,    \
TC_KEY_CYAN         : ANSI_CYAN         ,    \
TC_KEY_WHITE        : ANSI_WHITE        ,    \
TC_KEY_DEFAULT      : ANSI_DEFAULT      ,    \
TC_KEY_CNORMAL      : ANSI_CNORMAL      ,    \
                                             \
TC_KEY_BG_BLACK     : ANSI_BG_BLACK     ,    \
TC_KEY_BG_RED       : ANSI_BG_RED       ,    \
TC_KEY_BG_GREEN     : ANSI_BG_GREEN     ,    \
TC_KEY_BG_YELLOW    : ANSI_BG_YELLOW    ,    \
TC_KEY_BG_BLUE      : ANSI_BG_BLUE      ,    \
TC_KEY_BG_PURPLE    : ANSI_BG_PURPLE    ,    \
TC_KEY_BG_CYAN      : ANSI_BG_CYAN      ,    \
TC_KEY_BG_WHITE     : ANSI_BG_WHITE     ,    \
TC_KEY_BG_DEFAULT   : ANSI_BG_DEFAULT   ,    \
TC_KEY_BG_CNORMAL   : ANSI_BG_CNORMAL   ,    \
                                             \
TC_KEY_EXIT         : ANSI_BLUE        ,    \
                                             \
TC_KEY_TEL_WHO      : ANSI_BOLD         ,    \
                                             \
TC_KEY_GOD_WHO          : ANSI_GREEN    ,    \
TC_KEY_ARCH_WHO         : ANSI_GREEN    ,    \
TC_KEY_WIZ_WHO          : ANSI_GREEN    ,    \
TC_KEY_JAN_WHO          : ANSI_GREEN    ,    \
TC_KEY_JUGADORES_WHO    : ANSI_GREEN    ,    \
TC_KEY_ERROR_WHO        : ANSI_GREEN    ,    \
TC_KEY_MUD_WHO          : ANSI_GREEN    ,    \
TC_KEY_INFO_WHO         : ANSI_GREEN    ,    \
TC_KEY_INTERMUD_WHO     : ANSI_GREEN    ,    \
TC_KEY_LPC_WHO          : ANSI_GREEN    ,    \
TC_KEY_VALENCIA_WHO     : ANSI_GREEN    ,    \
TC_KEY_AYUDA_WHO        : ANSI_GREEN    ,    \
TC_KEY_COLISEUM_WHO     : ANSI_GREEN    ,    \
TC_KEY_TRIVIAL_WHO      : ANSI_GREEN    ,    \
TC_KEY_ASESINOS_MSG     : ANSI_GREEN    ,    \
TC_KEY_AVENTUREROS_MSG  : ANSI_GREEN    ,    \
TC_KEY_CONJURADORES_MSG : ANSI_GREEN    ,    \
TC_KEY_GUARDABOSQUES_MSG: ANSI_GREEN    ,    \
TC_KEY_GUERREROS_MSG    : ANSI_GREEN    ,    \
TC_KEY_HECHICEROS_MSG   : ANSI_GREEN    ,    \
TC_KEY_KISALAS_MSG      : ANSI_GREEN    ,    \
TC_KEY_AKALLAB_MSG      : ANSI_GREEN    ,    \
TC_KEY_GOLDHAI_MSG      : ANSI_GREEN    ,    \
TC_KEY_KENTON_MSG       : ANSI_GREEN    ,    \
TC_KEY_KHA_ANNU_MSG     : ANSI_GREEN    ,    \
TC_KEY_LAD_LAURELIN_MSG : ANSI_GREEN    ,    \
TC_KEY_LIMBO_MSG        : ANSI_GREEN    ,    \
TC_KEY_SIMAURIA_MSG     : ANSI_GREEN    ,    \
                                             \
TC_KEY_COMBAT_ATACO   : ANSI_CYAN       ,    \
TC_KEY_COMBAT_DEFIENDO: ANSI_RED        ,    \
TC_KEY_COMBAT_OTRO    : ANSI_YELLOW     ,    \
                                             \
 0                  : ANSI_NONE         ,    \
                          ])
//----------------------------------------------------------------------------


#endif // __COLOURS_H__
