/*SIMAURIA '/sys/races.h'
  =======================
  27-04-97 Theuzifan, Anyadidas las definiciones de ORC, HUMAN...
  20-03-01 Nyh, añado los atk
  16-04-01 Nyh, añado algunas definiciones de razas y las castellanizo
*/
#ifndef RACES_H
#define RACES_H

/* Definitions for races and the race-objects */

#define DEMON        "demon"
#define DEMONIO      DEMON
#define DRACO        "draconiano"
#define DRACONIANO   DRACO
#define DUENDE       "duende"
#define ELF          "elf"
#define ELFO         ELF
#define DARKELF      "darkelf"
#define ELFO_OSCURO  DARKELF
#define DWARF        "dwarf"
#define ENANO        DWARF
#define GIANT        "giant"
#define GIGANTE      GIANT
#define GNOME        "gnome"
#define GNOMO        GNOME
#define HUMAN        "human"
#define HUMANO       HUMAN
#define KAINOAK      "kainoak"
#define KENDER       "kender"
#define LOGATH       "logath"
#define HALFELF      "half-elf"
#define SEMI_ELFO    HALFELF
#define ORC          "orc"
//#define ORCO         ORC
#define TROLL        "troll"

#define MEDIO-ORCO    "medio-orco"
#define HALFLING     "halfling"
#define PELOSO     "peloso"
#define ALBO    "albo"
#define FUERTE    "fuerte"
#define DUNADAN     "dunadan"
#define  ORCO    "orco-comun" 
#define URUK     "uruk" 
#define TRASGO     "trasgo"
#define NOLDO     "noldo"
#define AINU     "ainu"
#define SINDA     "sinda"
#define SILVANO     "silvano"
#define BEORNIDA     "Beornida"
#define WOSE     "wose"
#define ROHIR     "rohir"
#define  HOMBRE    "HOMBRE-COMUN"
#define  DUNLENDINO    "dunlendino"
#define  HARADAN "haradan"
#define ORIENTAL    "oriental"
#define  BOSQUE    "hombre-del-bosque"
#define  ALTO    "alto-hombre"
#define  LOSSADAN    "lossadan"
#define  VARIAG    "variag"
#define  NUMENOREANO    "numenoreano-negro"
#define  CORSARIO    "corsario"
#define  BARBILUENGOS   "barbiluengos"
#define  BARBAFUEGO    "barbafuego"
#define BARBATIESA    "barbatiesa"
#define  PUÑOFERREO    "puñoferreo"
#define CINTURANCHA    "cintura-ancha"
#define  PIEPETREO    "piepetreo"
#define  RIZOSNEGROS    "rizosnegros"

 //------------------------------------------------------------------------------

#define RD_ALIGN      0  /* Basic alignment */
#define RD_FOOD       1  /* value for P_MAX_FOOD */
#define RD_DRINK      2  /* value for P_MAX_DRINK */
#define RD_ALC        3  /* value for P_MAX_ALC */
#define RD_WEIGHT     4  /* default WEIGHT */
#define RD_HANDS      5  /* default P_HANDS */
#define RD_HOME       7  /* default entry-point */
#define RD_LONG       8  /* long description */
#define RD_STAT       9  /* Alist of intrinsic stats */
#define RD_ATTR      10  /* Alist of intrinsic attributes */
#define RD_SIZE      13  /* The livings default size */
#define RD_RESISTANCES    20 /*resistencias */

#define RD_NO_ITEMS  25

#endif
