/***************************************************************************************
 ARCHIVO:	kendarg_00.c
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
  SetIntNoise("Escuchas un ruido, como si alguien golpease dos cosas metálicas.\n");
  SetIntSmell("No hueles nada en especial.\n");

  SetIntShort("la calle de Kendarg");
  SetIntLong("Estás en la calle de Kendarg. Mirando hacia el centro del "
  	"poblado divisas el Gran Árbol. Hacia el norte ves a lo lejos la "
  	"empalizada que rodea al poblado. Al sur hay una casa con un letrero "
  	"de madera y rodeada de trastos diversos. Al nordeste esta la plaza "
  	"principal. La calle Kendarg continua hacia el oeste.\n");

  AddDetail(({"arbol","árbol"}),"A lo lejos ves un gran árbol que sobresale "
  	"en el medio del poblado.\n");
  AddDetail(({"plaza"}),"Al nordeste ves la gran plaza principal.\n");
  AddDetail(({"empalizada","valla"}),"Ves una alta empalizada de madera que "
  	"rodea todo el poblado.\n");
  AddDetail(({"herreria","herrería"}),"Es una casa mas grande que las demás, "
  	"tiene un gran cartel de madera. Esta rodeada de muchos trastos, "
  	"herramientas rotas, arados, etc.\n");
  AddDetail(({"cartel","letrero"}),"Un gran letrero de madera que puedes leer.\n");
  AddReadMsg(({"cartel","letrero"}),"Lees el letrero:\n   Herreria del gran "
  	"Manodehierro, la mejor herreria de Flenton.\n");

  AddExit("sur",FLENHAB+"tiendas/herreria");
  AddExit("oeste",FLENHAB+"calles/kendarg_01");
  AddExit("nordeste",FLENHAB+"calles/plaza_00");
  AddItem(FLENPNJ+"poblado/hombre",REFRESH_DESTRUCT,1);
}