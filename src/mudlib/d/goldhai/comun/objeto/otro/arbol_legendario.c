/*=============================================================*
 |          << GOLDHAI.Bosque Wald [w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 13-09-98            |
 |             Ultima Modificacion........ 20-02-99            |
 |                                                             |
 *=============================================================*/

#include "path.h"
inherit THING;

create() {
 ::create();

 SetShort("el arbol legendario");
 SetLong("\
Ves ante ti un un inmenso arbol de ramas largas y llenas de hojas verdes que\n\
te impiden ver la copa. Igual, si eres agil, puedes subir a él.\n");
 SetIds(({"arbol","arbol legendario"}));
 SetNoGet("Está fuertemente sujeto al suelo, es imposible que lo puedas coger.\n");
}

