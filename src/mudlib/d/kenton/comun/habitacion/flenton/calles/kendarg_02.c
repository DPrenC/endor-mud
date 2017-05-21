/***************************************************************************************
 ARCHIVO:	kendarg_02.c
 AUTOR:		[k] Korsario
 FECHA:		27-02-1998
 COMENTARIOS:	Calle de Kendarg
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

create() {
  ::create();

  SetIndoors(0);
  SetLocate("flenton");
  SetIntNoise("Escuchas el bullicio del poblado.\n");
  SetIntSmell("Huele a cuero.\n");

  SetIntShort("la calle de Kendarg");
  SetIntLong("Estás en la calle de Kendarg. Mirando hacia el centro del "
  	"poblado divisas el Gran Árbol. Hacia el norte ves una casa con un "
  	"letrero, en el exterior hay varias pieles colgadas. Al sur hay una "
  	"casa de paja y barro. La calle Kendarg continúa hacia el este y el "
  	"oeste.\n");
  AddDetail(({"arbol","árbol"}),"A lo lejos ves un gran árbol que sobresale "
  	"en el medio del poblado.\n");
  AddDetail(({"casa","casas"}),"Ves dos casas, una al sur hecha de paja y "
  	"barro, y otra al norte, algo más grande, con un letrero y varias "
  	"pieles colgadas.\n");
  AddReadMsg(({"cartel","letrero"}),"Lees el letrero:\n  'La piel de oso', "
  	"tienda de cuero y pieles.\n");

  AddExit("norte",FLENHAB+"tiendas/cuero");
  AddExit("sur",FLENHAB+"casas/casa_05");
  AddExit("este",FLENHAB+"calles/kendarg_01");
  AddExit("oeste",FLENHAB+"calles/kendarg_03");
}