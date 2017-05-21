/*=============================================================*
 |         << GOLDHAI.Acantilado [w] Woo@simauria >>           |
 *=============================================================*
 |            Creacion.................. 29-10-98              |
 |                                                             |
 *=============================================================*/

#include "path.h"
inherit GACANTILADO;

public create()
{
 ::create();

 AddExit("oeste",ACANTILADO("acantilado_norte2"));
 AddExit("norte",ACANTILADO("acantilado_norte4"));

 SetLocate("acantilado del noroeste de Goldhai");
}
