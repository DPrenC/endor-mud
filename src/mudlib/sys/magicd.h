/**
 * SIMAURIA '/sys/magicd.h'
 */

#ifndef __MAGICD__
#define __MAGICD__

#include <config.h>

#ifndef MAGICD
#define MAGICD				DAEMONPATH "magicd"
#endif

#define MAGICD_DIR		    DAEMONPATH
#define MAGICD_FILE         MAGICD_DIR+"magicd"
#define MAGICD_SPELLS       MAGICD_DIR+"spells"
#define MAGICD_SAVER        MAGICD_DIR+"saver"
//#define MAGICD_FILE            "/secure/daemons/test"

#define MCD_CASTER            MAGICD->mdQueryCaster()
#define MAGICD_CASTER         MCD_CASTER

#define MAGICD_VERB         "magia"
#define MAGICD_CASTVERB     "lanzar"
#define MAGICD_ABORTVERB    "abortar"
#define MAGICD_INFOVERB     "info"
#define MAGICD_STATUSVERB   "estado"
#define MAGICD_BUGVERB      "bug"
#define MAGICD_IDEAVERB     "idea"

#define MAGICD_SPELL_DIR    "/std/magia/"
#define MAGICD_LOG_DIR      DAEMONLOGPATH
#define MAGICD_LOG_FILE     MAGICD_LOG_DIR+"magicd.log"
#define MAGICD_REPORTS_FILE MAGICD_LOG_DIR+"reports.log"

#define DB_SPELL_LONGNAME        0
#define DB_SPELL_LAST_UPDATE     1
#define DB_SPELL_TYPE            2

#define MT_NO_MAGIA             -1
#define MT_MAGIA                 0
#define MT_ESENCIA               1
#define MT_CANALIZACION          2
#define MT_MENTALISMO            3

#endif
