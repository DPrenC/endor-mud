/* SIMAURIA '/sys/spells.h'
   ========================
   [t] Theuzifan

   27-11-99 [t] Creación.
   29-02-00 [t] Añadido el spell de Transmutación.
   10-03-03 [t] Añadido piel de piedra y hierro.
*/

#ifndef _SPELLS_H
#define _SPELLS_H

#include <gremios.h>

/* =========================== */
/* SPELLS DE LOS GUARDABOSQUES */
/* =========================== */

#define MAG_CONVOCAR   "convocar animales"
#define MAG_CALMAR     "calmar animal"
#define MAG_CORTEZA    "piel de corteza"
#define MAG_PIEDRA     "piel pétrea"
#define MAG_HIERRO     "piel férrea"
#define MAG_SANGRE     "sangre de arbol"
#define MAG_TRANSMUTAR "transmutación"
#define MAG_MIEDO      "miedo paralizante"

#define MAG_GUARDABOSQUES ({MAG_PIEDRA, MAG_HIERRO, MAG_CONVOCAR, MAG_CALMAR, MAG_CORTEZA, MAG_SANGRE, MAG_TRANSMUTAR, MAG_MIEDO})

#define MAG_GREMIOS   MAG_GUARDABOSQUES

//Aunque no sea correcto el termino hechizos...
#define HECHIZOS   ([GC_GUARDABOSQUES: MAG_GUARDABOSQUES])

#endif /* _SPELLS_H */
