/*=============================================================*
 |         << GOLDHAI.Acantilado [w] Woo@simauria >>           |
 *=============================================================*
 |            Creacion.................. 29-10-98              |
 |            Ultima Modificacion....... 29-10-98              |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GACANTILADO;

create()
{
 ::create();
 SetIntLong("\
Estás en la parte alta del acantilado. Ves y oyes como las olas golpean\n\
fuertemente sobre las rocas. Si miras hacia el este podrás ver un pequeño\n\
camino que se adentra en el bosque y que quizás te lleve a algún sitio\n\
de interes. Puedes continuar por la orilla del acantilado en dirección\n\
Norte y Oeste.\n");

 AddExit("oeste",ACANTILADO("acantilado_norte4"));
 AddExit("norte",ACANTILADO("acantilado_norte6"));
 AddExit("este",BNORTE("bosque11"));

AddDetail(({"senda","camino","pequeño camino"}),
"Ves una pequeña senda que se adentra en el bosque.\n");

 SetLocate("acantilado del noroeste de Goldhai");
}
