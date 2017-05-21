#ifndef _SECURE_CONFIG_
#define _SECURE_CONFIG_

/*
 * secure/config.h
 *
 * nowadays, the driver pre#defines symbols that tell which mode the driver
 * is running in, on what host it is running on, etc.
 * SEE ALSO
 *	predefined(D)
 *
 * also special configuration is done here, the selection of special uids
 * and pathnames
 */

#define MUDNAME     "Endor-Mud"
#define MUDVERSION  "0.5.1.1"

//#define CLOSED_FOR_PLAYERS

/* define general pathnames */
#define SAVEPATH        "/save/"

#define SECUREDIR       "secure"
#define SECUREPATH      "/" SECUREDIR "/"
#define SECURESAVEPATH  SECUREPATH "save/"
#define SECUREBANPATH   SECUREPATH "baneados/"
#define SECUREMUMMYPATH SECUREPATH "momias/"
#define SECUREBINPATH   SECUREPATH "bin/"
#define SECURELOGPATH   SECUREPATH "log/"
#define SECUREOBJECTPATH   SECUREPATH "obj/"
#define MASTER          SECUREPATH "master"

#define DAEMONDIR       "daemons"
#define DAEMONPATH      SECUREPATH DAEMONDIR "/"

#define STDDIR          "std"
#define STDPATH         "/" STDDIR "/"

#define LIBDIR          "lib"
#define LIBPATH         "/" LIBDIR "/"

#define ROOMDIR         "room"
#define ROOMPATH        "/" ROOMDIR "/"

#define LOGDIR          "log"
#define LOGPATH         "/" LOGDIR "/"
#define DOMAINDIR       "dominios"
#define DOMAINLOGPATH   LOGPATH DOMAINDIR "/"
#define SBOXDIR         "securebox"
#define SBOXLOGPATH     LOGPATH SBOXDIR "/"
#define SAVEBOXPATH     SBOXLOGPATH "savebox/"
#define CHARACTERSDIR   "characters"
#define CHARACTERSLOGPATH LOGPATH CHARACTERSDIR "/"
#define WIZARDSDIR      "wizards"
#define WIZARDSLOGPATH  LOGPATH WIZARDSDIR "/"
#define GUILDDIR        "gremios"
#define GUILDLOGPATH    LOGPATH GUILDDIR "/"
#define REGISTERDIR     "register"
#define REGISTERLOGPATH LOGPATH REGISTERDIR "/"
#define FINANCEDIR      "finance"
#define FINANCELOGPATH  LOGPATH FINANCEDIR "/"
#define QUESTDIR        "quest"
#define QUESTLOGPATH    LOGPATH QUESTDIR "/"
#define REPORTDIR       "rep"
#define REPORTLOGPATH   LOGPATH REPORTDIR "/"
#define QUIZDIR         "quiz"
#define QUIZLOGPATH     LOGPATH QUIZDIR "/"

#define DAEMONLOGPATH   LOGPATH DAEMONDIR   "/"

#define DDIR            "d"
#define DPATH           "/" DDIR "/"

#define PDIR            "guilds"
#define PPATH           "/" PDIR "/"

#define XDIR            "log/xtools"    // El dir y el path donde las xtools
#define XPATH           "/" XDIR "/"  // pueden escribir, es absoluto

#define OBJECTDIR       "obj"
#define OBJECTPATH      "/" OBJECTDIR "/"

#define RACEMASTER      OBJECTPATH "racemaster"
#define QUESTMASTER     OBJECTPATH "quest_control"
#define CHANNELMASTER   OBJECTPATH "chmaster"
#define CHMASTER        CHANNELMASTER
#define EXPLOREMASTER   OBJECTPATH "explorador"
#define GAMECLOCK       OBJECTPATH "gameclock"
#define VIRTUALMASTER   OBJECTPATH "virtualmaster"
#define REPORTMASTER    OBJECTPATH "reportmaster"
#define REGISTER        OBJECTPATH "lib/register"
#define QUIZMASTER      OBJECTPATH "quizmaster"
#define SBOXOBJECT      STDPATH SBOXDIR "/box"
#define SBOXREGISTER    STDPATH SBOXDIR "/registerbook"
#define CHARMASTER      DAEMONPATH       "charmaster"
#define DBMASTER        DAEMONPATH       "dbmaster"
#define GUILDMASTER     DAEMONPATH "guildmaster"
#define WEAPONMASTER    DAEMONPATH "weaponmaster"
#define MONEY_DEMON     OBJECTPATH FINANCEDIR "/money_demon"
#define BANKOBJECT      OBJECTPATH FINANCEDIR "/bankobject"
#define MONEYLOGGER     OBJECTPATH FINANCEDIR "/moneylogger"
#define COMBATMASTER    OBJECTPATH "combatmaster"


#define SHUTDEMON       SECUREPATH "shut"

#define LOGIN           SECUREPATH "login"

/* special IMP protocol extension */
#define MWHOD_DAEMON    "/secure/net/mwhod"
#define INETD "/secure/inetd/inetd"
#define UDP_HEADER	    "/secure/udp.h"

#if __HOST_NAME__ == "silvia"
#define LOCAL_NAME  "Poniente"
#endif

/* multiple port logical constants */
// #define NORMAL_PORT 4242
// #define BACKUP_PORT 4252
#define WWW_PORT 4250

#define NORMAL_PORT 4117

#define TEST_PORT   8081 // mud de pruebas
#define BACKUP_PORT 8888

/* define special userids */
#define NULLID      "no/ne"
#define BACKBONEID  "std"
#define ROOTID      "ze/us"	/* prevent cheating - Pepel */

/* decomment as you wish: */
#define LOG_SET_QUEST
#define LOG_ENTER
#define LOG_SHUTDOWN
#define LOG_KILLS
#define LOG_EXP

#endif /* _SECURE_CONFIG_ */
