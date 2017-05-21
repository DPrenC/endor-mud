/**
 * /sys/combat.h
 */

#ifndef __COMBAT_H__
#define __COMBAT_H__

#include <equipment.h>
#include <damage.h>

#define DEBUG_TOTAL
#define DEBUG_SIMPLE
//#define DEBUG_CANKILL
#define DEBUG_HIT
#define DEBUG_DAM

//----------------------------------------------------------------------------
#define COMBATACTION_ATTACK    "Attack" //Atacar
#define COMBATACTION_FINTAR    "Feint"  //Fintar (habilidad)

#define COMBATACTION_DEFAULT    COMBATACTION_ATTACK

#define ATTACK_NORMAL   0    //un golpe normal
#define ATTACK_SNEAK    1    // (1<<0) un sneak attack
#define ATTACK_THROW    2    // (1<<1) lanzando algo

#define COMBATMESSAGE_NORMAL    ATTACK_NORMAL
#define COMBATMESSAGE_SNEAK     ATTACK_SNEAK
#define COMBATMESSAGE_THROW     ATTACK_THROW

#define LAST_COMBATMESSAGE      COMBATMESSAGE_THROW

#define COMBATMESSAGE_SPELL     (LAST_COMBATMESSAGE<<1)
//----------------------------------------------------------------------------
#define ATK_CURO      -7 //si al pasar por dodamage me cura (resistencias)
#define ATK_RESISTO   -6 //si al pasar por  " reduce el daño a 0 (resistencias)
#define ATK_BLOQUEADO -5 //escudo
#define ATK_TAICHI    -4 //taichi (sin armas)
#define ATK_PARADO    -3 //parada (con armas)
#define ATK_ESQUIVADO -2 //esquivar

#define ATK_PIFIA      -1
#define ATK_FALLO       0
#define ATK_ACIERTO     1
// numeros superiores indican aciertos criticos

#define ATK_LOWER_RES ATK_CURO

#define TAM_BONUS ([P_SIZE_SMALL: 5, P_SIZE_MEDIUM: 0, P_SIZE_LARGE: -5, P_SIZE_HUGE: -10])
//----------------------------------------------------------------------------
#define COMBAT_SKILL ([\
 WT_HAND:    HAB_SINARMAS, WT_MANOPLA: HAB_MANOPLA , WT_ESGRIMA:HAB_ESGRIMA,\
 WT_ESPADA:  HAB_ESPADA  , WT_HACHA:   HAB_HACHA   , WT_MAZA:   HAB_MAZA,\
 WT_LANZA:   HAB_LANZA   , WT_CUCHILLO:HAB_CUCHILLO, WT_VARA:   HAB_VARA,\
 WT_LATIGO:  HAB_LATIGO  , WT_ALABARDA:HAB_ALABARDA, WT_CADENA: HAB_CADENA,\
 WT_MANGUAL: HAB_MANGUAL , WT_DAGA: HAB_DAGA, WT_GARROTE: HAB_GARROTE,\
    WT_ESPADA_CORTA:HAB_ESPADA_CORTA, WT_CIMITARRA:HAB_CIMITARRA, WT_MANDOBLE:HAB_MANDOBLE,\
    WT_CAYADO: HAB_CAYADO, WT_JABALINA:HAB_JABALINA, WT_PICA:HAB_PICA, WT_CIMITARRA_PESADA: HAB_CIMITARRA_PESADA, \
    WT_MAZA_PESADA:HAB_MAZA_PESADA, WT_MARTILLO:HAB_MARTILLO, WT_MARTILLO_PESADO:HAB_MARTILLO_PESADO, \
    WT_HACHA_PESADA:HAB_HACHA_PESADA, WT_HACHA_KHAZAD:HAB_HACHA_KHAZAD, WT_MANGUAL_PESADO:HAB_MANGUAL_PESADO, \
    WT_ESPADA_SINDA:HAB_ESPADA_SINDA, WT_PICO:HAB_PICO, WT_AZADON:HAB_AZADON, \
    WT_ESPADA_MEDIANA:HAB_ESPADA_MEDIANA, WT_IMPROVISADA:HAB_IMPROVISADA, ])

#define VALOR_MEDIO_SKILLS    15
#define COMBAT_STAT_SCALE(x)    (x-VALOR_MEDIO_SKILLS)/2
//----------------------------------------------------------------------------
#define DEFAULT_GUILD_COMBAT_MODIFIER 75 //es un %
#define DEFAULT_ATTACK_WORD "ataque"

#define COMBAT_GUILD_BONUS(level, type) ((level* (type||COMBATE_REGULAR)))

#define QUALITY     (1<<0)    //tomara en cuenta el quality
#define NO_DODGE    (1<<1)    //solo usa el ac (en el evade, si estas stun,
                //tu habilidad esquivando (DODGE) no cuenta,
                //solo cuenta lo ke tengas por objetos

#define AC_NORMAL   0
#define AC_TOUCH    1
#define AC_NO_DEX   2
#define AC_FLAT-FOOTED  AC_NO_DEX

#define BASE_AC         10 //bonos a dar
#define BASE_CHANCE     50
#define BONUS_EXPERTISE 10
#define MALUS_NO_SKILL -20
#define BONUS_REFLEXES  10    //Esta es defensiva!!!
#define BONUS_GUERRERO  10 //bono a dar
#define MALUS_THROW     20 //penalizacion al dar, rebajada por la habilidad

// Bonos al ataque


// Penalizadores al defensor
#define DEFENDER_BLINDED  -10
#define DEFENDER_HELPLESS -20
#define DEFENDER_STUNNED  -10
#define DEFENDER_PRONE    -20

//bonos al daño
#define BONUS_SNEAK    200 //esto es solo la base, luego se modifica por nivel
#define BONUS_CIRCLE    50
#define BONUS_DORMIDO  100
#define BONUS_ZEN       20 //aumentar daño sin armas
#define BONUS_MASDANYO  20 //aumentar daño con armas
#define BONUS_CRITICO   20 //aumentar daño general
#define BONUS_ODIO      15

// Valores del tercer parámetro de Defend()
#define DEFEND_F_NOLIV      (1<<0) // El atacante no es un living y no irá a la
                                   // lista de enemigos.
#define DEFEND_F_NOMSG      (1<<1) //Suprime los mensajes de combate
#define DEFEND_F_FORCEMSG   (1<<2) //Forzar los mensajes del combate

// Valores más usuales:
#define DEFEND_NOLIV        DEFEND_F_NOLIV
#define DEFEND_NOMSG        DEFEND_F_NOMSG
#define DEFEND_SPELL        (1<<3)    //el ataque es un conjuro
#define DEFEND_NO_DEF_SK    (1<<4)  //no usar defensive skills (ni normal ni magicas)
#define DEFEND_NO_AC        (1<<5)  //no defiende la armadura (ni las defences)
// -------------------------------------------------------------------

// Combat skills, partially used as weapontypes as well

#define CS_HAND      "CsHand"     // Martial arts, also defensive
#define CS_DISTANT   "CsDistant"  // just a skill: Bows etc
#define CS_BULLET    "CsBullet"   // just a type: Bullets, Arrows, etc
#define CS_MANOPLA   "CsManopla"
#define CS_ESGRIMA   "CsEsgrima"
#define CS_ESPADA    "CsEspada"
#define CS_HACHA     "CsHacha"
#define CS_CUCHILLO  "CsCuchillo"
#define CS_LANZA     "CsLanza"
#define CS_MAZA      "CsMaza"
#define CS_VARA      "CsVara"
#define CS_LATIGO    "CsLatigo"
#define CS_ALABARDA  "CsAlabarda"
#define CS_CADENA    "CsCadena"
#define CS_MANGUAL   "CsMangual"
#define CS_DAGA   "CsDaga"
#define CS_GARROTE   "CsGarrote"
#define CS_ESPADA_CORTA  "CsEspadaCorta"
#define CS_CIMITARRA   "CsCimitarra"
#define CS_MANDOBLE   "CsMandoble"
#define CS_CAYADO       "CsCayado"
#define CS_JABALINA     "CsJabalina"
#define CS_PICA         "CsPica"
#define CS_CIMITARRA_PESADA "CsCimitarraPesada"
#define CS_MAZA_PESADA  "CsMazaPesada"
#define CS_MARTILLO     "CsMartillo"
#define CS_MARTILLO_PESADO "CsMartilloPesado"
#define CS_HACHA_PESADA "CsHachaPesada"
#define CS_HACHA_KHAZAD "CsHachaKhazad"
#define CS_MANGUAL_PESADO "CsMangualPesado"
#define CS_ESPADA_SINDA "CsEspadaSinda"
#define CS_PICO         "CsPico"
#define CS_AZADON       "CsAzadon"
#define CS_ESPADA_MEDIANA  "CsEspadaMediana"
#define CS_IMPROVISADA  "CsImprovisada"
#define DEFAULT_WT    CS_HAND

// Defensive combat skills

#define CS_DODGE     "CsDodge"

// Armourtypes
// Negative types protect the living everywhere (mostly non-physical)
// Positive types are also target zones for physical attacks.
// 0 is illegal.

#define AT_SKIN      -1  // internally used by livings!
#define AT_RING      -2
#define AT_AMULET    -3
#define AT_BROCHE    -4    //nuevo para endor
#define AT_PULSERA    -5    //nuevo para endor
#define AT_TIARA    -6    //nuevo para endor

#define AT_BOOTS      1  // pies
#define AT_CLOAK      2  // Remaining open skin supongo que túnica
#define AT_MAIL       3  // coraza
#define AT_GLOVES     4  // guantes
#define AT_HELMET     5  // casco
#define AT_SHIELD     6  // escudo?
#define AT_TROUSERS   7  // pantalones
#define AT_MANTO    8    //nuevo para endor
#define AT_CAPUCHA    9    //nuevo para endor
#define AT_GREBAS    10    //nuevo para endor
#define AT_CINTURON    11    //nuevo para endor
#define AT_TALABARTE    12    //nuevo para endor
#define AT_BRAZALES    13    //nuevo para endor
#define AT_TABARDO    14    //nuevo para endor
#define AT_FALDA    15  // nuevo para endor
#define AT_CAMISA   16  // nuevo para endor

#define AT_HITZONES   16  // Number of target zones

// Compatibilidad (paso de quitar a saco las variables en ingles, que luego
// me toca cambiarlas a mi en el mud y PASSSSO!)

#define AT_BOTAS       AT_BOOTS
#define AT_TUNICA      AT_CLOAK
#define AT_CORAZA      AT_MAIL
#define AT_GUANTES     AT_GLOVES
#define AT_CASCO       AT_HELMET
#define AT_ESCUDO      AT_SHIELD
#define AT_PANTALONES  AT_TROUSERS
#define AT_ANILLO      AT_RING
#define AT_AMULETO     AT_AMULET

// Optional argument to QueryWimpy() to return the absolute value.

#define ABS_WIMPY 1

// ---------- Compatibility ----------

#define WT_MANOPLA      CS_MANOPLA
#define WT_GUANTELETE   CS_MANOPLA
#define WT_ESGRIMA      CS_ESGRIMA
#define WT_ESPADA       CS_ESPADA
#define WT_HACHA        CS_HACHA
#define WT_MAZA         CS_MAZA
#define WT_LANZA        CS_LANZA
#define WT_CUCHILLO     CS_CUCHILLO
#define WT_VARA         CS_VARA
#define WT_LATIGO       CS_LATIGO
#define WT_ALABARDA     CS_ALABARDA
#define WT_CADENA       CS_CADENA
#define WT_MANGUAL      CS_MANGUAL
#define WT_DAGA      CS_DAGA
#define WT_GARROTE      CS_GARROTE
#define WT_ESPADA_CORTA CS_ESPADA_CORTA
#define WT_CIMITARRA    CS_CIMITARRA
#define WT_MANDOBLE     CS_MANDOBLE
#define WT_CAYADO       CS_CAYADO
#define WT_JABALINA     CS_JABALINA
#define WT_PICA         CS_PICA
#define WT_CIMITARRA_PESADA CS_CIMITARRA_PESADA
#define WT_MAZA_PESADA  CS_MAZA_PESADA
#define WT_MARTILLO     CS_MARTILLO
#define WT_MARTILLO_PESADO CS_MARTILLO_PESADO
#define WT_HACHA_PESADA CS_HACHA_PESADA
#define WT_HACHA_KHAZAD CS_HACHA_KHAZAD
#define WT_MANGUAL_PESADO CS_MANGUAL_PESADO
#define WT_ESPADA_SINDA CS_ESPADA_SINDA
#define WT_PICO         CS_PICO
#define WT_AZADON       CS_AZADON
#define WT_ESPADA_MEDIANA CS_ESPADA_MEDIANA
#define WT_IMPROVISADA  CS_IMPROVISADA
#define WT_HAND         CS_HAND

#define LIGHT_WEAPONS    ({WT_CUCHILLO, WT_ESGRIMA, WT_LATIGO, WT_DAGA, WT_CAYADO, WT_IMPROVISADA})

#define AT_ARMOUR AT_MAIL

#define WEAPON_TYPES ({ WT_ESPADA, WT_HACHA, WT_MAZA, WT_LANZA, WT_CUCHILLO, \
            WT_VARA, WT_LATIGO, WT_ALABARDA, WT_MANGUAL,\
            WT_MANOPLA, WT_ESGRIMA, WT_CADENA,  WT_DAGA, WT_GARROTE, \
            WT_ESPADA_CORTA, WT_CIMITARRA, WT_MANDOBLE, \
            WT_CAYADO, WT_JABALINA, WT_PICA, WT_CIMITARRA_PESADA, WT_MAZA_PESADA, \
            WT_MARTILLO, WT_MARTILLO_PESADO, WT_HACHA_PESADA, WT_HACHA_KHAZAD, \
            WT_MANGUAL_PESADO, WT_ESPADA_SINDA, WT_PICO, WT_AZADON, WT_ESPADA_MEDIANA, WT_IMPROVISADA, \
             })
#define VALID_WEAPON_TYPE(t) (member(WEAPON_TYPES, t) != -1)

#define ARMOUR_TYPES ({ AT_ARMOUR, AT_HELMET, AT_RING, AT_GLOVES, AT_CLOAK,\
            AT_BOOTS, AT_SHIELD, AT_AMULET, AT_TROUSERS, AT_MANTO, \
            AT_CAPUCHA, AT_GREBAS, AT_CINTURON, AT_TALABARTE, AT_BROCHE, AT_BRAZALES, AT_PULSERA, \
            AT_TABARDO, AT_TIARA, AT_FALDA, AT_CAMISA, "armadura", "casco", "anillo", "guantes", "tunica", \
            "botas", "escudo", "amuleto","pantalones", \
            "manto", "capucha", "grebas", "cinturon", "talabarte", "broche", "brazales", \
             "pulsera", "tabardo", "tiara", "falda", "camisa" \
             })
#define VALID_ARMOUR_TYPE(t) (member(ARMOUR_TYPES, t) != -1)

#define DAMAGE_TYPES ({ DT_INTR, DT_SLASH, DT_BLUDGEON, DT_PIERCE, TD_LACERACION, TD_ABRASIVO, DT_FIRE, \
            DT_COLD, DT_ELECTRO, DT_WATER, DT_GAS, DT_ZAP, \
            DT_ACID, DT_POISON, DT_PSYCHO, DT_NOAIR, \
            MT_INTR, MT_SLASH, MT_BLUDGEON, MT_PIERCE, MT_FIRE, \
            MT_COLD, MT_ELECTRO, MT_WATER, MT_GAS, MT_ZAP, \
            MT_ACID, MT_POISON, MT_PSYCHO, MT_NOAIR \
             })
#define VALID_DAMAGE_TYPE(t) (member(DAMAGE_TYPES, t) != -1)

#ifndef WEAPON_CLASS_OF_HANDS
#define WEAPON_CLASS_OF_HANDS   1
#endif

#ifndef HAND_SHORT
#define HAND_SHORT  0
#define HAND_WEAPON 1
#define HAND_WC     2
#endif

// tipos de lucha
#define C_NORMAL_FIGHT      1
#define C_MAGIC_FIGHT       2
#define C_ALL_FIGHT         C_NORMAL_FIGHT | C_MAGIC_FIGHT
#endif
