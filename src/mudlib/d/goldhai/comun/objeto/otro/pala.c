/*=============================================================*
 |           << GOLDHAI.Crowy [w] Woo@simauria >>              |
 *=============================================================*
 |              Creacion............. 05-10-98                 |
 |              Ultima Modificacion...05-10-98                 |
 |                                                             |
 *=============================================================*/

#include "path.h"
#include <properties.h>


inherit THING;

create() {
 ::create();

 SetShort("una pala");
 SetLong("\
Es una simple pala de cavar hecha de metal y con el mango de madera.\n");
 SetIds(({"pala","pala de cavar"}));
 SetValue(20);
 SetWeight(2500);
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
}
