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

 AddExit("este",ACANTILADO("acantilado_norte5"));
 AddExit("sur",ACANTILADO("acantilado_norte3"));

 SetLocate("acantilado del noroeste de Goldhai");
}
