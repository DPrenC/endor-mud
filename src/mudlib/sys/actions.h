/**
 * ENDOR-MUD'/sys/actions.h'
 * ============================
 */

#ifndef _ACTIONS_
#define _ACTIONS_
//------------------------------------------------------------------------------

// ACTIONS_NOT: No son acciones, son comandos del mud
#define ACTIONS_NOT  ({   "-" \
                        , "--" \
                        , "-nobel"\
                        , "--nobel"\
                        , "-endor"\
                        , "--endor"\
                        , "-chat"\
                        , "--chat"\
                        , "-ayuda"\
                        , "--ayuda"\
                        , "-trivial"\
                        , "-jan"\
                        , "--jan"\
                                                , "alias" \
                        , "ausente" \
                        , "ayuda" \
                        , "beep" \
                        , "bug" \
                        , "calcular" \
                        , "charset" \
                        , "car" \
                        , "clave" \
                        , "cls" \
                        , "color" \
                        , "con" \
                        , "conectados" \
                        , "conjuros" \
                        , "coraje" \
                        , "des" \
                        , "designorar" \
                        , "email" \
                        , "equipo" \
                        , "error" \
                        , "estado" \
                        , "fecha" \
                        , "ficha" \
                        , "fue" \
                        , "gquien" \
                        , "habilidades" \
                        , "hechizos" \
                        , "hora" \
                        , "i" \
                        , "idea" \
                        , "ignorar" \
                        , "int" \
                        , "inv" \
                        , "inventario" \
                        , "listar" \
                        , "mensajes" \
                        , "modoeco" \
                        , "pagina" \
                        , "parar" \
                        , "poder" \
                                                , "prompt" \
                        , "quien" \
                        , "reiniciar" \
                        , "sab" \
                        , "salidas" \
                        , "salvar" \
                        , "stty" \
                        , "suicidar" \
                        , "tel" \
                        , "telepatia" \
                        , "telepatía" \
                        ,"textos" \
                        , "tiflo" \
                        , "unalias" \
                        , "vida" \
                        , "vigor" \
                        , "version" \
                    })

// Tipos de acciones del d20:
#define ACTIONS_FREE      ({ })
#define ACTIONS_SWIFT     ({ })
#define ACTIONS_MOVEMENT  ({ })
#define ACTIONS_STANDARD  ({ })
#define ACTIONS_FULLROUND ({ })

// Acciones permitidas bajo ciertas circunstancias
// dormir, descansando y escondido
#define ACTIONS_SLEEPING    ( ({ "dormir", "descansar", "despertar", "levantarse" }) + ACTIONS_NOT )
#define ACTIONS_RESTING     ( ({ "m", "mirar", "decir", "'", "sal", "obj", "-", "escuchar", "oler" }) + ACTIONS_SLEEPING )

#define ACTIONS_HIDDEN      ( ({ "compararse", "esconderse", "m", "mirar", "sigilo", "sal", "obj", "oler", "escuchar" }) + ACTIONS_NOT )

//------------------------------------------------------------------------------

#define ACTION_IS_NOT(s)        (member(ACTIONS_NOT,       s) >= 0)
#define ACTION_IS_FREE(s)       (member(ACTIONS_FREE,      s) >= 0)
#define ACTION_IS_SWIFT(s)      (member(ACTIONS_SWIFT,     s) >= 0)
#define ACTION_IS_MOVEMENT(s)   (member(ACTIONS_MOVEMENT,  s) >= 0)
#define ACTION_IS_STANDARD(s)   (member(ACTIONS_STANDARD,  s) >= 0)
#define ACTION_IS_FULLROUND(s)  (member(ACTIONS_FULLROUND, s) >= 0)

#define ACTION_IS_SLEEPING(s)   (member(ACTIONS_SLEEPING,  s) >= 0)
#define ACTION_IS_RESTING(s)    (member(ACTIONS_RESTING,   s) >= 0)

#define ACTION_IS_HIDDEN(s)     (member(ACTIONS_HIDDEN,    s) >= 0)

//------------------------------------------------------------------------------
#endif
