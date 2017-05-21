#ifndef __EFFECTS_H__
#define __EFFECTS_H__

#define EFFECTS_ID "_effect_"

#define EFFECTS_PATH "/obj/effects/"

#define EFFECT_LUZ_CEGADORA    EFFECTS_PATH "effect_luz_cegadora"
#define EFFECT_VISION_NOCTURNA EFFECTS_PATH "effect_vision_nocturna"
#define EFFECT_PARALYZE        EFFECTS_PATH "effect_paralyze"

// --- Propiedades de /std/effect.c ---

#define P_TIME_LEFT     "TimeLeft"
#define P_AFFECTED      "Affected"
#define P_INIT_CHAT     "InitChat"
#define P_EXEC_CHAT     "ExecChat"
#define P_END_CHAT      "EndChat"
#define P_ENV_INIT_CHAT "EnvInitChat"
#define P_ENV_EXEC_CHAT "EnvExecChat"
#define P_ENV_END_CHAT  "EnvEndChat"

//------------------------------------------------------------------------------
// Esto NO se usa, pero NO borrar, porfa
//------------------------------------------------------------------------------
/*
#if 0 // Esto es en prevision del futuro sistema
  
// Efectos
#define EFFECT_NAME      "Name"     // string
#define EFFECT_PROP      "Prop"     // string prop o mapping ([string prop: mixed modifier])
#define EFFECT_MOD       "Mod"      // mixed modifier
#define EFFECT_INIT      "Init"     // mixed init
#define EFFECT_FINISH    "Finish"   // mixed finish
#define EFFECT_RUN       "Run"      // mixed run
#define EFFECT_LAST_TIME "LastTime" // int lasttime
#define EFFECT_TIME_LEFT "TimeLeft" // int timeleft
#define EFFECT_TIME_INIT "TimeInit" // int timeinit
#define EFFECT_TYPE      "Type"     // string type
#define EFFECT_DURATION  "Duration" // int duration (lastime=timeinit+duration)

#define EFFECT_CHECK_EQUAL ({ EFFECT_NAME, EFFECT_PROP, EFFECT_TYPE, EFFECT_MOD,\
                              EFFECT_INIT, EFFECT_FINISH, EFFECT_TIME_INIT, EFFECT_DURATION })

// Defines de los tipos de efectos:
// ET = EFFECT_TYPE
#define ET_NONE  "None"  // Bonificadores micelaneos, se apilan todos, al que lo use le capo.

#define ET_PENALTY              "Penalty"   // Penalizadores, se apilan si son distintos nombres.

#define ET_ARMOR                "Armor"         // Mod. a AC dado por la armadura
#define ET_SHIELD               "Shield"        // Mod. a AC dado por el escudo
#define ET_DEFLECTION           "Deflection"    // Mod. a AC por deflección
#define ET_DODGE                "Dodge"         // Mod. a AC por esquiva, se apilan
#define ET_NATURAL_ARMOR        "NaturalArmor"  // Mod. a AC por armadura natural
#define ET_PROFANE              "Profane"       // Mod. profanos
#define ET_SACRED               "Sacred"        // Mod. sagrados
#define ET_INSIGHT              "Insight"       // Mod. introspectivo
#define ET_LUCK                 "Luck"          // Mod. de suerte
#define ET_CIRCUMSTANCE         "Circumstance"  // Mod. de circunstancia, se apilan algunos
#define ET_COMPETENCE           "Competence"    // Mod. de competencia
#define ET_ENHANCEMENT          "Enhancement"   // Mod. de mejora
#define ET_MORALE               "Morale"        // Mod. de moral
#define ET_SINERGY              "Sinergy"       // Mod. de sinergia, se apilan
#define ET_INHERENT             "Inherent"      // Mod. inherentes
#define ET_NATURAL_ARMOR_BONUS  "NaturalArmorBonus" // Mod. de mejora de armadura natural

//#define ET_ENLARGEMENT          "Enlargement"   // Mod. de variacion de tamaño
//#define EFFECT_TYPE_HASTE       "Haste"         // Mod. a AC por aceleracion/relentizado
           
#endif // del if 0 en en prevision del futuro sistema
*/
//------------------------------------------------------------------------------
// Fin de Esto NO se usa, pero NO borrar, porfa
//------------------------------------------------------------------------------
           
#endif