/***************************************************************************************
 ARCHIVO:	jefe_02.c
 AUTOR:		[k] Korsario
 FECHA:		27-02-1998
 COMENTARIOS:	Calle del Jefe
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

create() {
  ::create();

  SetIndoors(0);
  SetLocate("flenton");
  SetIntNoise("Escuchas voces y risas.\n");
  SetIntSmell("Hueles el aroma de las flores en primavera.\n");
  SetIntShort("la calle del Jefe");
  SetIntLong("Estás en el final de la Calle del Jefe. Al norte divisas el "
  	"Gran Árbol. Al oeste se encuentra la plaza principal, que es el centro "
  	"del poblado. Al este el resto de la Calle del Jefe. Al sur divisas la "
  	"empalizada que rodea el poblado.\n");

  AddDetail(({"arbol","árbol"}),"A lo lejos ves un gran árbol que sobresale "
  	"en el medio del poblado.\n");
  AddDetail(({"plaza","plaza principal"}),"Ves al oeste una gran plaza "
  	"rodeada de varias casas y comercios.\n");
  AddDetail(({"empalizada","valla"}),"Ves una alta empalizada de madera "
  	"que rodea todo el poblado.\n");

  AddExit("oeste",FLENHAB+"calles/plaza_00");
  AddExit("este",FLENHAB+"calles/jefe_01");
  AddItem(FLENPNJ+"poblado/perro",REFRESH_DESTRUCT,1);
}