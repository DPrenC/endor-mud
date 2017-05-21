/**
 * SIMAURIA '/sys/ts.h'
*/

#ifndef _TS_H_
#define _TS_H_

#include <gremios.h>

//------------------------------------------------------------------------------

#define SAVE_TYPE_NOSAVE    0
#define SAVE_TYPE_FORTITUDE 1
#define SAVE_TYPE_REFLEX    2
#define SAVE_TYPE_WILL      4

//------------------------------------------------------------------------------

#define SAVE_TYPE_FORTITUDE_TXT "Fort"
#define SAVE_TYPE_REFLEX_TXT    "Ref"
#define SAVE_TYPE_WILL_TXT      "Will"

//------------------------------------------------------------------------------

#define TS_MAP_KISALAS       ([                        \
                               SAVE_TYPE_FORTITUDE: 0, \
                               SAVE_TYPE_REFLEX:    2, \
                               SAVE_TYPE_WILL:      0, \
                              ])
#define TS_MAP_GUERREROS     ([                        \
                               SAVE_TYPE_FORTITUDE: 2, \
                               SAVE_TYPE_REFLEX:    0, \
                               SAVE_TYPE_WILL:      0, \
                              ])
#define TS_MAP_CONJURADORES  ([                        \
                               SAVE_TYPE_FORTITUDE: 0, \
                               SAVE_TYPE_REFLEX:    0, \
                               SAVE_TYPE_WILL:      2, \
                              ])
#define TS_MAP_GUARDABOSQUES ([                        \
                               SAVE_TYPE_FORTITUDE: 1, \
                               SAVE_TYPE_REFLEX:    1, \
                               SAVE_TYPE_WILL:      0, \
                              ])
#define TS_MAP_HECHICEROS   ([                         \
                               SAVE_TYPE_FORTITUDE: 0, \
                               SAVE_TYPE_REFLEX:    0, \
                               SAVE_TYPE_WILL:      2, \
                             ])
#define TS_MAP_ASESINOS     ([                         \
                               SAVE_TYPE_FORTITUDE: 0, \
                               SAVE_TYPE_REFLEX:    2, \
                               SAVE_TYPE_WILL:      0, \
                             ])
#define TS_MAP_AVENTUREROS  ([                         \
                               SAVE_TYPE_FORTITUDE: 1, \
                               SAVE_TYPE_REFLEX:    1, \
                               SAVE_TYPE_WILL:      0, \
                             ])
#define TS_MAP_EXPERTO      ([                         \
                               SAVE_TYPE_FORTITUDE: 1, \
                               SAVE_TYPE_REFLEX:    1, \
                               SAVE_TYPE_WILL:      1, \
                             ])
#define TS_MAP_LUCHADOR     ([                         \
                               SAVE_TYPE_FORTITUDE: 2, \
                               SAVE_TYPE_REFLEX:    0, \
                               SAVE_TYPE_WILL:      0, \
                             ])
#define TS_MAP_NINGUNO      ([                         \
                               SAVE_TYPE_FORTITUDE: 0, \
                               SAVE_TYPE_REFLEX:    0, \
                               SAVE_TYPE_WILL:      0, \
                             ])
#define TS_MAP_MAGO         ([                         \
                               SAVE_TYPE_FORTITUDE: 0, \
                               SAVE_TYPE_REFLEX:    0, \
                               SAVE_TYPE_WILL:      2, \
                             ])
#define TS_MAP_TORPE        ([                         \
                               SAVE_TYPE_FORTITUDE: 0, \
                               SAVE_TYPE_REFLEX:    0, \
                               SAVE_TYPE_WILL:      0, \
                             ])

//------------------------------------------------------------------------------

#define TS_MAP ([ GC_KISALAS:       TS_MAP_KISALAS,       \
                  GC_GUERREROS:     TS_MAP_GUERREROS,     \
                  GC_CONJURADORES:  TS_MAP_CONJURADORES,  \
                  GC_GUARDABOSQUES: TS_MAP_GUARDABOSQUES, \
                  GC_HECHICEROS:    TS_MAP_HECHICEROS,    \
                  GC_ASESINOS:      TS_MAP_ASESINOS,      \
                  GC_AVENTUREROS:   TS_MAP_AVENTUREROS,   \
                  GC_EXPERTO:       TS_MAP_EXPERTO,       \
                  GC_LUCHADOR:      TS_MAP_LUCHADOR,      \
                  GC_NINGUNO:       TS_MAP_NINGUNO,       \
                  GC_MAGO:          TS_MAP_MAGO,          \
                  GC_TORPE:         TS_MAP_TORPE,         \
              ])

//------------------------------------------------------------------------------

#endif
