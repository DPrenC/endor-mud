/*=============================================================*
 |            << GOLDHAI.Playa [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 29-10-98                |
 |               Ultima Modificacion.. 08-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GPLAYA;

create()
{
 ::create();
 SetIntLong("\
Te encuentras en la parte oeste de la gran playa que recorre todo el norte\n\
de la isla. El agua muere lentamente en la orilla mientras que en el Sur un\n\
camino sube por una montaña hacia el acantilado.\n");

 AddExit("este",PLAYA("playa2"));
 AddExit("sur",ACANTILADO("acantilado_norte8"));

 SetLocate("playa norte de Goldhai");
}
