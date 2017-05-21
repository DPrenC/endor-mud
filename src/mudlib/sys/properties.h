/**
 * ENDOR-MUD'/sys/properties.h'
 */

#ifndef __PROPERTIES_H__
#define __PROPERTIES_H__

#include <materials.h>
#include <size.h>

/* define out own file name, for the proplist-handling tools Pepel, 10-01-95 */
#define PROPERTY_HEADER         "/sys/properties.h"

// Para los Query/Set
#define REAL    1
#define FAKE    0

//[Nyh] usadas en living y objetos para el combate:
//traido desde el combat.h
//los comentados es ke ya existian
//#define P_WC          "WC"        //WC del ataque
//#define P_DAM_TYPE    "DamType"    //Tipo de daño (DT_XXX)
#define P_HIT           "Hit"        //Bono al hit
#define P_DAM           "Dam"        //Bono al dam
#define P_ATTACK_WORD   "AttackWord"    //Palabra de ataque
//#define P_WEAPON_TYPE "WeaponType"    //Tipo de arma *Ver nota abajo*
#define P_SKILL         "Skill"        //Habilidad a usar *idem*
//#define P_MAGIC       "Magic"        //Nivel de magia
#define P_CALLOBJ       "CallObj"    //CallObj
#define P_BLESSED       "Blessed"    //Si esta bless o cursed
//Nota: Si hay ATK_SKILL se usara esa habilidad, si no existe uso el WT
//    para ver la habilidad, y si no uso la habilidad por defecto

#define P_EVADE         "Evade"
#define P_DEFENCE       "Defence"

//lo cambio de (1<<X) a su valor para poder usarlos en switchs...
#define P_STATUS        "Status"
#define STATUS_NORMAL   0    //normal
#define STATUS_REST     1//(1<<0)    //flag de descanso (no usar solo!!)
#define STATUS_TRIPPED  2//(1<<1)    //caido
#define STATUS_HELPLESS 4//(1<<2)    //indefenso
#define STATUS_RESTING  3//(STATUS_REST|STATUS_TRIPPED)    //descansando
#define STATUS_SLEEPING 5//(STATUS_REST|STATUS_HELPLESS)//durmiendo

//fin traido
#define P_COMBATE_COLOR_ATACO   "ColorAtaco"
#define P_COMBATE_COLOR_ATACADO "ColorAtacado"
#define P_COMBATE_COLOR_AJENO   "ColorAjeno"
#define P_COMBATE_BREVE         "CombateBreve"

// --- /std/base ---

#define P_CREATOR          "Creator"
#define P_CREATION_TIME    "CreationTime"
#define P_ICREATOR         "ICreator"
#define P_INHERITED        "Inherited"
#define P_IS_VIRTUAL       "IsVirtual"
#define P_PROPERTIES       "Properties"
#define P_VMASTER          "VMaster"

// Not builtin in /std/base

#define P_CLEAN_UP         "CleanUp"
#define P_CLEANUP          P_CLEAN_UP
#define P_LAST_RESET       "LastReset"
#define P_RESET_INTERVAL   "ResetInterval"

// --- /std/corpse ---

#define P_DECAY            "Decay"
#define P_DECAY_TIME       "DecayTime"

// --- /std/container ---

// --- /std/equipment ---

#define P_USAGE_MODE       "UsageMode"
#define P_NUMBER_HANDS     "NumberHands"
#define P_QUALITY          "Quality"
#define P_QUALITY_MSG      "QualityMsg"
#define P_RESET_QUALITY    "ResetQuality"
#define P_USAGE            "Usage"
#define P_EQUIPPED         "Equipped"
#define P_EQUIP_DATA       "EquipData"

// Not builtin in /std/equipment

#define P_NOEQUIP          "NoEquip"
#define P_NOUNEQUIP        "NoUnequip"

// --- /std/living ---
// See also /sys/attributes.h
#define P_CANT_STEAL        "CantSteal"
#define P_CANT_FIGHT        "CantFight"
#define P_CANT_LURE         "CantLure"
// not builtin in /std/living

#define P_FLYING            "Flying"
#define P_SEE_INVIS         "SeeInvis"
#define P_SEE_HIDDEN        "SeeHidden" //[i]
#define P_WATERBREATHING    "WaterBreathing"

//   -- /std/living/attributes --
#define P_ATTRIBUTES        "Attributes"
#define P_ATTRS             "Attrs"
#define P_BONI              "Boni"
#define P_STATS             "Stats"
#define P_GENTLE            "Gentle"

//   -- /std/living/body --
#define P_CORPSE            "Corpse"
#define P_DEG_POISON        "DegPoison"
#define P_HP                "HP"
#define P_KILL_XP           "KillXP"
#define P_MAX_HP            "MaxHP"
#define P_MAX_POISON        "MaxPoison"
#define P_MAX_SP            "MaxSP"
#define P_POISON            "Poison"
#define P_RATE_HP           "RateHP"
#define P_RATE_POISON       "RatePoison"
#define P_RATE_SP           "RateSP"
#define P_REG_HP            "RegHP"
#define P_REG_SP            "RegSP"
#define P_SP                "SP"
#define P_XP                "XP"
#define P_WHIMPY            "Whimpy"
#define P_REG_TP            "RegTP"
#define P_RATE_TP           "RateTP"
#define P_MAX_TP            "MaxTP"
#define P_TP                "TP"
#define P_STUNNED           "Stunned"

//     Not builtin in /std/living/body:
#define P_HEALTH            "Health"
#define P_HEALTH_MSG        "HealthMsg"
#define P_RESISTANCE        "Resistance"

//   -- /std/living/chat --
#define P_ACHAT_CHANCE      "AChatChance"
#define P_ACHATS            "AChats"
#define P_CHAT_CHANCE       "ChatChance"
#define P_CHATS             "Chats"
#define P_QUESTIONS         "Questions"
#define P_SHRUG_MSG         "ShrugMsg"
#define P_TALK_DELAY        "TalkDelay"
#define P_TALK_FUN          "TalkFun"
#define P_TALK_MATCH        "TalkMatch"
#define P_TALK_OBJ          "TalkObj"
#define P_TALK_TYPE         "TalkType"

//   -- /std/living/description --
#define P_ACTIONS           "Actions"
#define P_ALIGN             "Align"
#define P_FROG              "Frog"
#define P_GENDER            "Gender"
#define P_GHOST             "Ghost"
#define P_OWN_LONG          "OwnLong"
#define P_OWN_TITLE         "OwnTitle"
#define P_OWN_PRESAY        "OwnPresay"
#define P_INWIZ             "Inwiz"
#define P_INVIS             "Invis"
#define P_HIDDEN            "Hidden" // [i]
#define P_SEEN_BY           "SeenBy"
#define P_ALLOW_SHADOW      "AllowShadow"
#define P_IS_NPC            "IsNPC"
#define P_IS_PET            "IsPet"
#define P_IS_GUARD          "IsGuard"
#define P_CITIZENSHIP       "Citizenship"
#define P_GUARD_DEFEND_MSG  "GuardDefendMsg"
#define P_IS_PLAYER         "IsPlayer"
#define P_IVISION           "IVision"
#define P_LEVEL             "Level"
#define P_LSTATE            "LState"
//    Don't use DEFENSE - it is compat only. Use DEFENCE instead
#define P_MAGIC_DEFENSE     "MagicDefence"
#define P_MAGIC_DEFENCE     "MagicDefence"
#define P_MSGIN             "MsgIn"
#define P_MSGOUT            "MsgOut"
#define P_MMSGIN            "MMsgIn"
#define P_MMSGOUT           "MMsgOut"
#define P_NAME              "Name"
#define P_RACE              "Race"
#define P_RAZABASE              "Razabase"
#define P_RACE_OBJ          "RaceObj"
#define P_REALNAME          "RealName"
#define P_UVISION           "UVision"

//     Not builtin in /std/living/description:
#define P_BLIND             "Blind"  // Ciego
#define P_DEAF              "Deaf"   // Sordo
#define P_DESCRIPTION       "Description"

// Values of P_GENDER

#ifndef GENDER_OTHER

#define GENDER_OTHER    0
#define GENDER_NEUTER   GENDER_OTHER
#define GENDER_MALE     1
#define GENDER_FEMALE   2
#define NUMBER_SINGULAR 0
#define NUMBER_PLURAL   1

#endif

// Valores de P_GENDER y P_NUMBER (castellano)

#define GENERO_NEUTRO       GENDER_NEUTER
#define GENERO_MASCULINO    GENDER_MALE
#define GENERO_FEMENINO     GENDER_FEMALE
#define NUMERO_SINGULAR     NUMBER_SINGULAR
#define NUMERO_PLURAL       NUMBER_PLURAL

// Values of P_LSTATE

#ifndef LSTATE_NORMAL

#define LSTATE_NORMAL  0
#define LSTATE_GHOST   1
#define LSTATE_FROG    2

#endif
//   -- /std/living/heart --
#define P_HEART            "Heart"
#define P_HEART_USER       "HeartUser"
#define P_HBHOOK           "HBHook"
#define P_HB_OBJ           "HbObj"
#define P_HB_FUN           "HbFun"
#define P_HB_INTERVAL      "HbInterval"

//   -- /std/living/moving --
#define P_GO_CHANCE        "GoChance"

//   -- /std/living/stats --
#define P_CON       "Con"
#define P_DEX       "Dex"
#define P_INT       "Int"
#define P_STR       "Str"
#define P_TMPCON    "TmpCon"
#define P_TMPDEX    "TmpDex"
#define P_TMPINT    "TmpInt"
#define P_TMPSTR    "TmpStr"
#define P_TMPWIS    "TmpWis"
#define P_TMPCHA    "TmpCha"
 //#define P_CHA              "Cha"
#define P_WIS              "Wis"
// #define P_GNO              "Gno"

//   -- /std/living/restrictions --
#define P_LOAD             "Load"
#define P_MAX_CONTENT      "MaxContent"

// -- forward --
#define P_COMBAT_STYLE     "CombatStyle"
#define P_FREE_HANDS       "FreeHands"
#define P_BRIEF            "Brief"
#define P_OBVIOUS          "Obvious"

//   -- this too? --
#define P_DEFENSE          "Defense"

// --- /std/npc ---
// See also <attributes.h>

// --- /std/npc/body
#define P_ALCOHOL       "Alcohol"
#define P_DEG_ALCOHOL   "DegAlcohol"
#define P_DEG_DRINK     "DegDrink"
#define P_DEG_FOOD      "DegFood"
#define P_DRINK         "Drink"
#define P_FOOD          "Food"
#define P_MAX_ALCOHOL   "MaxAlcohol"
#define P_MAX_DRINK     "MaxDrink"
#define P_MAX_FOOD      "MaxFood"
#define P_RATE_ALCOHOL  "RateAlcohol"

// --- /std/player/comm ---
#define P_PROMPT        "Prompt"
#define P_IGNORE_ALL    "IgnoreAll"
#define P_AWAY          "Away"
#define P_CH_LINE       "ChLine"
#define P_ECHO_MODE     "EchoMode"
#define P_IGNORED       "Ignored"

// --- /std/thing ---

#define P_ADS               "Ads"
#define P_BRIGHT            "Bright"
#define P_CLASS_ADS         "ClassAds"
#define P_CLASS_IDS         "ClassIds"
#define P_EXTRA_DESC        "ExtraDesc"
#define P_FOLLOWERS         "Followers"
#define P_IDS               "Ids"
#define P_LAST_ID           "LastId"
#define P_LAST_PLAYER       "LastPlayer"
#define P_LAST_VERB         "LastVerb"
#define P_LIGHT             "Light"
#define P_LONG              "Long"
#define P_EXA_LONG          "ExaLong"
#define P_MAGIC             "Magic"
#define P_NOGET             "NoGet"
#define P_NOTAKE            P_NOGET
#define P_NODROP            "NoDrop"
#define P_NOGIVE            "NoGive"
#define P_NOISE             "Noise"
#define P_READ_MSG          "ReadMsg"
#define P_SHORT             "Short"
#define P_SMELL             "Smell"
#define P_SUB_DETAILS       "SubDetails"
#define P_SUB_READMSGS      "SubReadMsgs"
#define P_VALUE             "Value"
#define P_WEIGHT            "Weight"
#define P_NUMBER            "Number"
#define P_MATERIAL          "Material"
#define P_COOKED            "Cocinado"
#define P_COCINADO          P_COOKED


// Not builtin in /std/thing:

#define P_AUTOOBJECT        "AutoObject"
#define P_EXTRALOOK         "Extralook"
#define P_IS_FOLLOWER       "IsFollower"
#define P_IS_FOLLOWING      "IsFollowing"
#define P_NO_QUITDROP       "NoQuitDrop"
#define P_NOFOLLOW          "NoFollow"
#define P_NOBUY             "NoBuy"
#define P_NOSELL            "NoSell"
#define P_SIZE              "Size"
#define P_BANDO             "Bando"
#define P_EXIT_SIZE         "ExitSize"
#define P_INFO              "Info"
#define P_VERSION           "Version"
#define P_STANDARD          "Standard" // [w] Anyadido para el SetStandard

// --- /std/room ---

#define P_COMMANDS         "Commands"
#define P_DAY_DATA         "DayData"
#define P_DAY_DESC         "DayDesc"
#define P_DAY_STATE        "DayState"
#define P_DETAILS          "Details"
#define P_DOORS            "Doors"
#define P_EXIT_STRINGS     "ExitStrings"
#define P_EXITS            "Exits"
#define P_EXITS_DEST       "ExitsDest"
#define P_EXITS_DATA       "ExitsData"
#define P_EXPLORABLE       "Explorable"
#define P_HEAL_ROOM       "HealRoom"
#define P_INDOORS          "Indoors"
#define P_PRE_INT_SHORT    "PreIntShort"
#define P_INT_SHORT        "IntShort"
#define P_INT_LONG         "IntLong"
#define P_EXA_INT_LONG     "ExaIntLong"
#define P_INT_NOISE        "IntNoise"
#define P_INT_SMELL        "IntSmell"
#define P_INT_LIGHT        "IntLight"
#define P_ITEMS            "Items"
#define P_ITEMS_REFRESH    "ItemsRefresh"
#define P_MAGIC_PROTECTION "MagicProtection"
#define P_MAX_INV          "MaxInv"
#define P_MAX_WEIGHT       "MaxWeight"
#define P_MONEY            "Money"
#define P_NOISES           "Noises"
#define P_NOWAY_MSG        "NowayMsg"
#define P_NOWAY_MSGS       "NowayMsgs"
#define P_OUTDOORS         "Outdoors"
#define P_PRE_CONTENT       "PreContent"
#define P_READ_MSGS        "ReadMsgs"
#define P_SAFE           "Safe"
#define P_SERVER           "Server"
#define P_SMELLS           "Smells"
#define P_SUNBRIGHT        "SunBright"
#define P_TPORT            "TPort"
#define P_WEIGHT_CONTENT   "WeightContent"


// Not builtin in /std/room

#define P_KILLZONE         "KillZone"     // must be hardcoded !
#define P_PREOUTSIDE       "PreOutside"
#define P_OUTSIDE          "Outside"
#define P_TPORT_REASON     "TPortReason"

// -- /obj/lib/ship

#define P_HARBOUR          "Harbour" // soft prop for the deck of ship
#define P_PORTS            "Ports"
#define P_SHIP_ENTER_MSGS  "ShipEnterMsgs"
#define P_SHIP_LEAVE_MSGS  "ShipLeaveMsgs"
#define P_ROOMS            "Rooms"
#define P_DECKS            "Decks"
#define P_MOVE_SCENES      "MoveScenes"
#define P_MOVE_MSGS        "MoveMsgs"
#define P_ENTER_MSGS       "EnterMsgs"
#define P_LEAVE_MSGS       "LeaveMsgs"

// -- /room/port

#define P_SHIPS            "Ships"
#define P_AUTOCALL         "Autocall"

// --- /std/shop

#define P_VALUTA           "Valuta"
#define P_SECURITY         "Security"
#define P_SIGN_DESC        "SignDesc"
#define P_MARKET           "Market"
#define P_ARTICLES         "Articles"
#define P_ARTICLES_REFRESH "ArticlesRefresh"
#define P_BUY_FACTOR       "BuyFactor"
#define P_DYNAMIC          "Dynamic"
#define P_MIN_CASH         "MinCash"
#define P_LIST             "List"
#define P_IDENTIFY         "Identify"
#define P_APPRAISE         "Appraise"
#define P_SHOW             "Show"
#define P_SELL             "Sell"
#define P_BUY              "Buy"
#define P_LIVING_TRADE     "LivingTrade"

// --- /std/weather

#define P_CLIENTS          "Clients"
#define P_CHANGEDESC       "ChangeDesc"
#define P_STATELENGTH      "StateLength"
#define P_SUNLIGHT         "SunLight"
#define P_STATEDATA        "StateData"
#define P_STATEDESC        "StateDesc"

// --- /std/weather with numberable set of states

#define P_STATE           "State"
#define P_STATES          "States"

// --- /std/unit

#define P_AMOUNT           "Amount"
#define P_VALUE_PER_UNIT   "ValuePerUnit"
#define P_BRIGHT_PER_UNIT  "BrightPerUnit"
#define P_WEIGHT_PER_UNIT  "WeightPerUnit"
#define P_PLURAL_IDS       "PluralIds"
#define P_PLURAL_SHORT     "PluralShort"
#define P_PLURAL_LONG      "PluralLong"
#define P_LAST_AMOUNT      "LastAmount"

// --- /obj/inroom

#define P_USE_LOCK         "UseLock"

//====================================================
// Old properties following

/* defines for specifing where to add a new element into an array property */
#define AT_FRONT -1
#define AT_END   -2

/*
 * some predefined properties
 */

/* Builtins of livings (NOT /std/living!) */
//[Nyh] del combat.c
#define P_AGGRESSIVE       "Aggressive"
#define P_ARMOURS          "Armours"
#define P_ATTACK_CHANCE    "AttackChance"
#define P_CAST_OBJ         "CastObj"
#define P_COMBAT_DELAY     "CombatDelay"
#define P_COMBAT_DELAY_MSG "CombatDelayMsg"
#define P_DEFENCES         P_DEFENCE
#define P_ENEMIES          "Enemies"
#define P_FRIEND_OBJ       "FriendObj"
#define P_FRIEND_FUNCTION  "FriendFunction"
#define P_CHK_FIGHT_FUNCTION "ChkFightFunction"
#define P_CHK_MAGIC_FUNCTION "ChkMagicFunction"
#define P_HANDS            "Hands"
#define P_HUNTERS          "Hunters"
#define P_PRESAY           "Presay"
#define P_TITLE            "Title"
//#define P_TOTAL_AC         "TotalAC"
//#define P_TOTAL_WC         "TotalWC"
#define P_WEAPONS          "Weapons"

/* Builtins of /std/npc: */

// --- /obj/monster/spellmonster ---

#define P_SPELLS           "Spells"
#define P_SPELL_CHANCE     "SpellChance" // for /obj/spellmonster
#define P_CAST_CHANCE      "CastChance" // for /obj/monster/spellmonster

/* Builtins of /std/player: */

#define P_ALIASES       "Aliases"
#ifndef P_BONI
#define P_BONI          "Boni"
#endif
#define P_CHANNELS      "Channels"
#define P_CITIZEN       "Citizen"
#define P_CURRENTDIR    "CurrentDir"
#define P_FACTIVE       "FActive"
#define P_FALIASES      "FAliases"
#define P_GUILD         "Guild"
#define P_OLDGUILD      "OldGuild"
#define P_HOME          "Home"
#ifndef P_INVIS
#define P_INVIS         "Invis"
#endif
#define P_LAST_SAVE     "LastSave"
#define P_PAGESIZE      "PageSize"
#define P_REAL_LEVEL    "RealLevel"
#define P_QUESTS        "Quests"
#define P_SEER_QP       "SeerQP"
#define P_TTY           "TTY"
#define P_WIZ_QP        "WizQP"
#define P_CHARSET       "Charset"

#define EXTENDED        1
#define USASCII         2
/* Not builtin of /std/player */

#define P_WEAR_OBJ         "WearObj"
#define P_WIELD_OBJ        "WieldObj"
#define P_NOWIZ            "NoWiz"

/* Builtins of /std/weapon: */

#define P_DAM_TYPE         "DamType"
#define P_WC               "WC"
#define P_WEAPON_HANDS     P_NUMBER_HANDS
#define P_WEAPON_TYPE      "WeaponType"
#define P_WP_PER_QP        "WPperQP"

/* Builtins of /std/armour: */

#define P_AC               "AC"
#define P_AP_PER_QP        "APperQP"
#define P_ARMOUR_TYPE      "ArmourType"

/* Builtins of /std/food and /std/drink
 * (bert nase && organimedes && pepel)
 */

#define P_DRINK_REFILL  "DrinkRefill"
#define P_REFILL  P_DRINK_REFILL

#define P_FOOD_KIND       "FoodKind"
#define P_FOOD_SOAK       "FoodSoak"
#define P_FOOD_STUFF      "FoodStuff"
#define P_FOOD_ALC        "FoodAlc"
#define P_FOOD_HEAL       "FoodHeal"
#define P_FOOD_MSGS       "FoodMsgs"

#define P_FD_KIND       P_FOOD_KIND
#define P_FD_SOAK       P_FOOD_SOAK
#define P_FD_STUFF      P_FOOD_STUFF
#define P_FD_ALC        P_FOOD_ALC
#define P_FD_HEAL       P_FOOD_HEAL
#define P_FD_MSG1       "FoodMsg1"
#define P_FD_MSG2       "FoodMsg2"

// Niveles para la mdt 2.0
#define LORD 3
#define VICELORD 2
#define MEMBER 1
#define NOTHING 0

// Auxiliares para salvar atributos de los objetos cuando se graba el inventario
#define P_AUX1        "Aux1"
#define P_AUX2        "Aux2"

#endif
