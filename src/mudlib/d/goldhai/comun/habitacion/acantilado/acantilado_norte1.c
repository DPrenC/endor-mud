/*=============================================================*
 |         << GOLDHAI.Acantilado [w] Woo@simauria >>           |
 *=============================================================*
 |            Creacion.................. 29-10-98              |
 |            Ultima Modificacion....... 08-02-99              |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GACANTILADO;

create()
{
 ::create();
 SetIntLong("\
Avanzas por la orilla de un enorme precipicio que acaba varias decenas de\n\
metros abajo en unas tremendas rocas. El mar se ve perfectamente desde este\n\
lugar así como el faro noroeste de la isla. Al Sur ves una pequeña senda\n\
que te aleja de este acantilado que prosigue por el Norte.\n");

 AddExit("norte",ACANTILADO("acantilado_norte2"));
 AddExit("sur",BNORTE("alrededor_crowy1"));

 SetLocate("acantilado del noroeste de Goldhai");
}
