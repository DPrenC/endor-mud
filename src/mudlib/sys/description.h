/**
 * /sys/description.h
 */
#ifndef __DESCRIPTION_H__
#define __DESCRIPTION_H__

//------------------------------------------------------------------------------
// Altura relativa a tu raza:
#define D_HEIGHT_VERY_SHORT  -2
#define D_HEIGHT_SHORT       -1
#define D_HEIGHT_NORMAL       0
#define D_HEIGHT_TALL         1
#define D_HEIGHT_VERY_TALL    2

//------------------------------------------------------------------------------
// Peso relativo a tu raza
#define D_WEIGHT_SKINNY      -2
#define D_WEIGHT_LEAN        -1
#define D_WEIGHT_NORMAL       0
#define D_WEIGHT_PLUMP        1
#define D_WEIGHT_FAT          2

//------------------------------------------------------------------------------
// Mano buena
#define D_HANDED_RIGHT       0
#define D_HANDED_LEFT        1

//------------------------------------------------------------------------------
// Colores disponibles para ojos/pelo
#define D_COLOUR_NONE       0
#define D_COLOUR_AMBER      1
#define D_COLOUR_BLACK      2
#define D_COLOUR_BLOND      3
#define D_COLOUR_BLUE       4
#define D_COLOUR_BROWN      5
#define D_COLOUR_CHESTNUT   6
#define D_COLOUR_COPPER     7
#define D_COLOUR_DARK       8
#define D_COLOUR_EMERALD    9
#define D_COLOUR_GOLDEN    10
#define D_COLOUR_GRAY      11
#define D_COLOUR_GREEN     12
#define D_COLOUR_ORANGE    13
#define D_COLOUR_PURPLE    14
#define D_COLOUR_RED       15
#define D_COLOUR_SILVER    16
#define D_COLOUR_WHITE     17
#define D_COLOUR_YELLOW    18

#define D_ALL_HAIR_COLOUR ([ D_COLOUR_AMBER, D_COLOUR_BLACK, D_COLOUR_BLOND,    \
                             D_COLOUR_BLUE,  D_COLOUR_BROWN, D_COLOUR_CHESTNUT, \
                             D_COLOUR_COPPER, D_COLOUR_DARK, D_COLOUR_EMERALD,  \
                             D_COLOUR_GOLDEN, D_COLOUR_GRAY, D_COLOUR_GREEN,    \
                             D_COLOUR_ORANGE, D_COLOUR_PURPLE, D_COLOUR_RED,    \
                             D_COLOUR_SILVER, D_COLOUR_WHITE, D_COLOUR_YELLOW ])

#define D_ALL_EYES_COLOUR ([ D_COLOUR_AMBER, D_COLOUR_BLACK, D_COLOUR_BLOND,    \
                             D_COLOUR_BLUE,  D_COLOUR_BROWN, D_COLOUR_CHESTNUT, \
                             D_COLOUR_COPPER, D_COLOUR_DARK, D_COLOUR_EMERALD,  \
                             D_COLOUR_GOLDEN, D_COLOUR_GRAY, D_COLOUR_GREEN,    \
                             D_COLOUR_ORANGE, D_COLOUR_PURPLE, D_COLOUR_RED,    \
                             D_COLOUR_SILVER, D_COLOUR_WHITE, D_COLOUR_YELLOW ])

//------------------------------------------------------------------------------

#define D_MALE      0
#define D_FEMALE    1
#define D_PLURAL    2
#define D_SINGULAR  0

#define MALE_SINGULAR   0 // (D_MALE & D_SINGULAR)
#define FEMALE_SINGULAR 1 // (D_FEMALE & D_SINGULAR)
#define MALE_PLURAL     2 // (D_MALE & D_PLURAL)
#define FEMALE_PLURAL   3 // (D_FEMALE & D_PLURAL)

#define COLOR2STRING ([ \
        D_COLOUR_NONE    : "desconocido";  "desconocida";  "desconocido";  "desconocida",  \
        D_COLOUR_AMBER   : "ámbar";    "ámbar";    "ámbar";     "ámbar",     \
        D_COLOUR_BLACK   : "negro";    "negra";    "negros";    "negras",    \
        D_COLOUR_BLOND   : "rubio";    "rubia";    "rubios";    "rubias",    \
        D_COLOUR_BLUE    : "azul";     "azul";     "azules";    "azules",    \
        D_COLOUR_BROWN   : "marrón";   "marrón";   "marrónes";  "marrónes",  \
        D_COLOUR_CHESTNUT: "castaño";  "castaña";  "castaños";  "castañas",  \
        D_COLOUR_COPPER  : "cobrizo";  "cobriza";  "cobrizos";  "cobrizas",  \
        D_COLOUR_DARK    : "oscuro";   "oscura";   "oscuros";   "oscuras",   \
        D_COLOUR_EMERALD : "esmeralda";"esmeralda";"esmeralda"; "esmeralda", \
        D_COLOUR_GOLDEN  : "dorado";   "dorada";   "dorados";   "doradas",   \
        D_COLOUR_GRAY    : "gris";     "gris";     "grises";    "grises",    \
        D_COLOUR_GREEN   : "verde";    "verde";    "verdes";    "verdes",    \
        D_COLOUR_ORANGE  : "naranja";  "naranja";  "naranjas";  "naranjas",  \
        D_COLOUR_PURPLE  : "púrpura";  "púrpura";  "púrpuras";  "púrpuras",  \
        D_COLOUR_RED     : "rojo";     "roja";     "rojos";     "rojas",     \
        D_COLOUR_SILVER  : "plateado"; "plateada"; "plateados"; "plateadas", \
        D_COLOUR_WHITE   : "blanco";   "blanca";   "blancos";   "blancas",   \
        D_COLOUR_YELLOW  : "amarillo"; "amarilla"; "amarillos"; "amarillas", \
                      ])

#define DESCRIPTION_AREAS
#define DA_AGE       "edad"
#define DA_ARMS      "brazos"
#define DA_BEARD     "barba"
#define DA_EYES      "ojos"
#define DA_FACE      "cara"
#define DA_HAIR      "pelo"
#define DA_LEGS      "piernas"
#define DA_MENTALITY "mentalidad"
#define DA_PHYSIQUE  "físico"
#define DA_SKIN      "piel"

// AGE
#define DA_AGE_AGELESS                "sin edad clara"
#define DA_AGE_VERY_YOUNG             "muy jóven"
#define DA_AGE_ADOLESCENT             "adolescente"
#define DA_AGE_YOUNG                  "jóven"
#define DA_AGE_MIDDLE_AGED            "de mediana edad"
#define DA_AGE_OLD                    "viejo"
#define DA_AGE_VERY_OLD               "muy viejo"
#define DA_AGE_ANCIENT                "anciano"
#define DA_AGE_YOUTHFUL               "juvenil"
#define DA_AGE_CHILDLIKE              "infantil"
#define DA_AGE_ELDERLY                "muy viejo"
#define DA_AGE_HOARY                  "canoso"
#define DA_AGE_CALLOW                 "sin experiencia"
#define DA_AGE_MATURE                 "maduro"

// ARMS
#define DA_ARMS_LONG_ARMED            "de brazos largos"
#define DA_ARMS_SHORT_ARMED           "de brazos largos"
#define DA_ARMS_THICK_ARMED           "de brazos gruesos"
#define DA_ARMS_THIN_ARMED            "de brazos finos"
#define DA_ARMS_BROAD_SHOULDERED      "espalda ancha"

// BEARD
#define DA_BEARD_BLOND_BEARDED        "barba rubia"
#define DA_BEARD_GRAY_BEARDED         "barba gris"
#define DA_BEARD_BLACK_BEARDED        "barba negra"
#define DA_BEARD_WHITE_BEARDED        "barba blanca"
#define DA_BEARD_BROWN_BEARDED        "barba marrón"
#define DA_BEARD_RED_BEARDED          "barba roja"
#define DA_BEARD_GREEN_BEARDED        "barba verde"
#define DA_BEARD_BLUE_BEARDED         "barba azul"
#define DA_BEARD_ORANGE_BEARDED       "barba naranja"
#define DA_BEARD_PURPLE_BEARDED       "barba púrpura"

// EYES (=ojos [x] )
//#define DA_EYES_BLACK_EYED            "negros"
//#define DA_EYES_RED_EYED              "rojos"
//#define DA_EYES_YELLOW_EYED           "amarillos"
//#define DA_EYES_GRAY_EYED             "grises"
//#define DA_EYES_ONE_EYED              ""
#define DA_EYES_ROUND_EYED            "redondos"
#define DA_EYES_SLANT_EYED            "sesgados"
//#define DA_EYES_SQUINTY_EYED          ""
//#define DA_EYES_GREEN_EYED            "verdes"
//#define DA_EYES_BLUE_EYED             "azules"
//#define DA_EYES_BROWN_EYED            "marrones"
#define DA_EYES_DARK_EYED             "oscuros"
//#define DA_EYES_PURPLE_EYED           "púrpura"
#define DA_EYES_HAZEL_EYED            "pardos"
//#define DA_EYES_AMBER_EYED            "ambar"
#define DA_EYES_SHARP_EYED            "agudos"
#define DA_EYES_ALMOND_EYED           "almendrados"
//#define DA_EYES_BLEARY_EYED           ""
#define DA_EYES_EAGLE_EYED            "de aguila"
#define DA_EYES_SILVER_EYED           "plateados"
#define DA_EYES_GOLDEN_EYED           "dorados"
#define DA_EYES_HARD_EYED             "duros"
#define DA_EYES_EMERALD_EYED          "esmeralda"
#define DA_EYES_NEARSIGHTED           "miopes"
#define DA_EYES_SHIFTY_EYED           "cambiantes"
#define DA_EYES_STARRY_EYED           "chispeantes"
#define DA_EYES_CAT_EYED              "felinos"
#define DA_EYES_WIDE_EYED             "anchos"
#define DA_EYES_SAD_EYED              "tristes"
#define DA_EYES_WILD_EYED             "salvajes"

// FACE
#define DA_FACE_HOOK_NOSED            "nariz aguileña"
#define DA_FACE_UPNOSED               "nariz respingona"
//#define DA_FACE_KNOBNOSED             ""
#define DA_FACE_POTATO_NOSED          "nariz chata"
#define DA_FACE_WIDE_MOUTHED          "boca grande"
#define DA_FACE_DOUBLE_CHINNED        "hoyuelo en la barbilla"
#define DA_FACE_SQUARE_JAWED          "mandibulas anchas"
//#define DA_FACE_DIMPLED               ""
#define DA_FACE_CHINLESS              "sin barbilla"
#define DA_FACE_ROMAN_NOSED           "nariz griega"
//#define DA_FACE_PUG_NOSED             ""
#define DA_FACE_RED_NOSED             "nariz roja"
#define DA_FACE_BIG_NOSED             "gran nariz"
#define DA_FACE_JUG_EARED             "orejas salidas"
#define DA_FACE_POINTY_EARED          "nariz puntiaguda"
#define DA_FACE_FURRY_EARED           "orejas peludas"
#define DA_FACE_SAD_FACED             "gesto triste"
#define DA_FACE_ROUND_FACED           "cara redonda"
#define DA_FACE_SQUARE_FACED          "cara cuadrada"
#define DA_FACE_STONE_FACED           "cara petrea"
#define DA_FACE_LONG_FACED            "cara alargada"
#define DA_FACE_THIN_FACED            "cara delgada"
#define DA_FACE_COLD_FACED            "gesto frio"
#define DA_FACE_BUTTON_NOSED          "nariz diminuta"
#define DA_FACE_THIN_LIPPED           "labios delgados"
#define DA_FACE_THICK_LIPPED          "labios carnosos"
#define DA_FACE_OVAL_FACED            "cara ovalada"
#define DA_FACE_FINE_BONED            "huesos delicados"
#define DA_FACE_BLACK_TOOTHED         "dientes negros"
//#define DA_FACE_SNAGGLE_TOOTHED       ""
#define DA_FACE_HIGH_BROWED           "cejas altas"

// HAIR
//#define DA_HAIR_WHITE_HAIRED          ""
//#define DA_HAIR_GRAY_HAIRED           ""
//#define DA_HAIR_BLACK_HAIRED          ""
//#define DA_HAIR_BLOND_HAIRED          ""
//#define DA_HAIR_BROWN_HAIRED          ""
//#define DA_HAIR_RED_HAIRED            ""
//#define DA_HAIR_GREEN_HAIRED          ""
//#define DA_HAIR_BLUE_HAIRED           ""
//#define DA_HAIR_ORANGE_HAIRED         ""
//#define DA_HAIR_PURPLE_HAIRED         ""
//#define DA_HAIR_DARK_HAIRED           ""
//#define DA_HAIR_CHESTNUT_HAIRED       ""
//#define DA_HAIR_COPPER_HAIRED         ""
#define DA_HAIR_FAIR_HAIRED           "pelo elegante"
#define DA_HAIR_CURLY_HAIRED          "pelo rizado"
#define DA_HAIR_BALDING               "calvo"
//#define DA_HAIR_GOLDEN_HAIRED         ""
#define DA_HAIR_SOFT_HAIRED           "pelo sedoso"
#define DA_HAIR_LIGHT_HAIRED          "pelo fino"
#define DA_HAIR_SHAGGY_HAIRED         "pelo ondulado"
#define DA_HAIR_SILVER_HAIRED         "pelo plateado"

// LEGS

//#define DA_LEGS_BANDY_LEGGED          ""
#define DA_LEGS_LONG_LEGGED           "de piernas largas"
#define DA_LEGS_SHORT_LEGGED          "de piernas cortas"
#define DA_LEGS_SKINNY_LEGGED         "de piernas flacas"
#define DA_LEGS_THIN_LEGGED           "de piernas delgadas"
#define DA_LEGS_THICK_LEGGED          "de piernas gruesas"
#define DA_LEGS_BOW_LEGGED            "de piernas arqueadas"
//#define DA_LEGS_GANGLY                ""
//#define DA_LEGS_RANGY                 ""
//#define DA_LEGS_LANKY                 ""

// MENTALITY (=carácter [X] )
#define DA_MENTALITY_DIRTY            "sucio"
//#define DA_MENTALITY_DISHEVELED       ""
#define DA_MENTALITY_MELANCHOLY       "melancólico"
#define DA_MENTALITY_JOVIAL           "jovial"
#define DA_MENTALITY_DEPRESSED        "deprimido"
#define DA_MENTALITY_ANGRY            "iracundo"
//#define DA_MENTALITY_DOUR             ""
#define DA_MENTALITY_DULL             "idiota"
#define DA_MENTALITY_EXCITING         "excitante"
#define DA_MENTALITY_PHILOSOPHICAL    "filosófico"
//#define DA_MENTALITY_HAUGHTY          ""
#define DA_MENTALITY_FRIENDLY         "amistoso"
#define DA_MENTALITY_WEATHERED        "temperamental"
#define DA_MENTALITY_HARDENED         "endurecido"
#define DA_MENTALITY_MERRY            "alegre"
#define DA_MENTALITY_ANIMATED         "animado"
#define DA_MENTALITY_TALKATIVE        "hablador"
#define DA_MENTALITY_NERVOUS          "nervioso"
#define DA_MENTALITY_MENACING         "amenazante"
#define DA_MENTALITY_FURTIVE          "furtivo"
#define DA_MENTALITY_ENERGETIC        "energético"
#define DA_MENTALITY_BOUNCY           "cambiante"
//#define DA_MENTALITY_LOOMING          ""
//#define DA_MENTALITY_SPRITELY         ""
#define DA_MENTALITY_GLOOMY           "sombrío"
//#define DA_MENTALITY_BLITHE           "alegre"
//#define DA_MENTALITY_JOLLY            "alegre"
#define DA_MENTALITY_ARROGANT         "arrogante"
#define DA_MENTALITY_LORDLY           "mandatorial"
#define DA_MENTALITY_SNOBBISH         "snob"
#define DA_MENTALITY_SINISTER         "siniestro"
#define DA_MENTALITY_AMIABLE          "amigable"
#define DA_MENTALITY_SWEET_TEMPERED   "dulce"
#define DA_MENTALITY_KINDLY           "amable"
//#define DA_MENTALITY_SILVER_TONGUED   ""
#define DA_MENTALITY_SENSUAL          "sensual"
#define DA_MENTALITY_MYSTERIOUS       "misterioso"
#define DA_MENTALITY_INQUISITIVE      "inquisitivo"
//#define DA_MENTALITY_FUN_LOVING       ""
//#define DA_MENTALITY_TOUSLED          ""
//#define DA_MENTALITY_BALEFUL          ""
#define DA_MENTALITY_OBNOXIOUS        "odioso"
#define DA_MENTALITY_ENTICING         "seductor"

// PHYSIQUE
#define DA_PHYSIQUE_FLABBY            "de complexión flácida"
#define DA_PHYSIQUE_SKINNY            "de esquelética"
#define DA_PHYSIQUE_LEAN              "de complexión delgada"
#define DA_PHYSIQUE_SLENDER           "de complexión esbelta"
//#define DA_PHYSIQUE_STOUT             ""
#define DA_PHYSIQUE_STOCKY            "de complexión rechoncha"
#define DA_PHYSIQUE_VOLUPTUOUS        "con complexión voluptuosa"
#define DA_PHYSIQUE_HUNCHBACKED       "con joroba"
//#define DA_PHYSIQUE_SLIGHT            ""
#define DA_PHYSIQUE_THIN              "de complexión delgada"
//#define DA_PHYSIQUE_WILLOWY           ""
#define DA_PHYSIQUE_SMALL             "de complexión pequeña"
#define DA_PHYSIQUE_LEGGY             "patilargo"
#define DA_PHYSIQUE_SPINDLY           "de constitución larguirucha"
//#define DA_PHYSIQUE_WIZENED           ""
#define DA_PHYSIQUE_LARGE             "complexión muy grande"
//#define DA_PHYSIQUE_SQUAT             ""
#define DA_PHYSIQUE_BARREL_CHESTED    "de torso con forma de barril"
#define DA_PHYSIQUE_BIG               "de complexión grande"
#define DA_PHYSIQUE_HEAVY             "de complexión pesada"
#define DA_PHYSIQUE_MASSIVE           "de complexión voluminosa"
#define DA_PHYSIQUE_TINY              "de complexión diminuta"
#define DA_PHYSIQUE_WELL_MUSCLED      "de complexión musculosa"
//#define DA_PHYSIQUE_CURVACEOUS        ""
//#define DA_PHYSIQUE_SHAPELY           ""
//#define DA_PHYSIQUE_BUXOM             ""
//#define DA_PHYSIQUE_LIMBER            ""
#define DA_PHYSIQUE_WELL_PROPORTIONED "de complexión bien proporcionada"
#define DA_PHYSIQUE_TWISTED           "de complexión retorcida"
//#define DA_PHYSIQUE_MAIMED            ""
#define DA_PHYSIQUE_LIGHT_FOOTED      "de complexión ligera"
#define DA_PHYSIQUE_GRACEFUL          "de complexión elegante"
//#define DA_PHYSIQUE_STOOP_SHOULDERED  ""
#define DA_PHYSIQUE_DELICATE          "de complexión delicada"

// SKIN
#define DA_SKIN_SWARTHY               "de piel tostada"
#define DA_SKIN_EBONY_SKINNED         "de piel de ébano"
#define DA_SKIN_IVORY_SKINNED         "de piel de marfil"
#define DA_SKIN_DARK_SKINNED          "de piel oscura"
#define DA_SKIN_LIGHT_SKINNED         "de piel clara"
#define DA_SKIN_BROWN_SKINNED         "de piel morena"
#define DA_SKIN_OLIVE_SKINNED         "de piel aceituna"
#define DA_SKIN_GREEN_SKINNED         "de piel verde"
#define DA_SKIN_BLACK                 "de piel negra"
#define DA_SKIN_WHITE                 "de piel blanca"
#define DA_SKIN_PALE                  "de piel pálida"
#define DA_SKIN_PALLID                "de piel pálida"
#define DA_SKIN_SMOOTH_SKINNED        "de piel suave"
#define DA_SKIN_POCKED_MARKED         "de piel con marcas de acné"
#define DA_SKIN_WRINKLED              "de piel arrugada"
#define DA_SKIN_WEATHERWORN           "de piel ajada por el tiempo"
#define DA_SKIN_ROSY_CHEEKED          "de mejillas sonrosadas"
#define DA_SKIN_WELL_TANNED           "de piel morena"
#define DA_SKIN_FRECKLED              "de piel con pecas"
#define DA_SKIN_GREASY                "de piel grasa"
#define DA_SKIN_SOFT_SKINNED          "de piel delicada"
#define DA_SKIN_FAIR_COMPLEXIONED     "de piel tersa"
#define DA_SKIN_LEATHERED             "de piel curtida"
#define DA_SKIN_BURNED                "de piel quemada"
#define DA_SKIN_SCARED                "de piel con cicatrices"
#define DA_SKIN_HAIRY                 "con mucho pelo"
#define DA_SKIN_FURRY                 "peludo"


#endif

