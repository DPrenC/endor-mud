/***************************************************************************************
 ARCHIVO:	kendarg_01.c
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
  SetIntNoise("Escuchas un ruido entre los matorrales.\n");
  SetIntSmell("No hueles nada en especial.\n");

  SetIntShort("la calle de Kendarg");
  SetIntLong("Est�s en la calle de Kendarg. Mirando hacia el centro del "
  	"poblado divisas el Gran �rbol. Hacia el norte ves a lo lejos la "
  	"empalizada que rodea al poblado. Hacia el sur hay unos peque�os "
  	"matorrales. La calle Kendarg continua hacia el este y hacia el oeste.\n");

  AddDetail(({"arbol","�rbol"}),"A lo lejos ves un gran �rbol que sobresale "
  	"en el medio del poblado.\n");
  AddDetail(({"matorrales"}),"Ves unos peque�os matorrales...de repente "
  	"notas algo moverse entre la maleza\n");
  AddDetail(({"empalizada","valla"}),"Ves una alta empalizada de madera "
  	"que rodea todo el poblado.\n");

  AddExit("este",FLENHAB+"calles/kendarg_00");
  AddExit("oeste",FLENHAB+"calles/kendarg_02");
  AddItem(FLENPNJ+"poblado/gato",REFRESH_DESTRUCT);
}