/*=============================================================*
 |            << GOLDHAI.Wald [w] Woo@simauria >>              |
 *=============================================================*
 |               Creacion............ 20-02-99                 |
 |               Ultima Modificacion..20-02-99                 |
 |                                                             |
 *=============================================================*/

#include "path.h"
#include <properties.h>

inherit THING;

create() {
 ::create();

 SetShort("unos restos de arbol");
 SetLong("\
Ves los restos de un gran arbol tirados por suelo rodeado de ramas y hojas.\n");
 SetIds(({"restos","restos de arbol"}));
 SetWeight(800000); // Puedes cogerlo pero pesa mucho
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_PLURAL);
}
