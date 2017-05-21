/***************************************************************************************
 ARCHIVO:	kendarg_03.c
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
  SetIntNoise("No hay mucho ruido por aqu�... solo silencio\n");
  SetIntSmell("No huele a nada en especial.\n");

  SetIntShort("la calle de Kendarg");
  SetIntLong("Est�s en la calle de Kendarg. A lo lejos divisas el Gran "
  	"�rbol, destacando en medio del poblado. Al sur hay una casa de "
  	"paja y barro. La calle Kendarg contin�a hacia el este y el oeste. "
  	"Parece una zona algo abandonada.\n");

  AddDetail(({"arbol","�rbol"}),"A lo lejos ves un gran �rbol que sobresale "
  	"en el medio del poblado.\n");
  AddDetail(({"casa"}),"Ves una casa al sur hecha de paja y barro.\n");

  AddExit("sur",FLENHAB+"casas/casa_06");
  AddExit("este",FLENHAB+"calles/kendarg_02");
  AddExit("oeste",FLENHAB+"calles/kendarg_04");
  AddItem(FLENPNJ+"poblado/hombre",REFRESH_DESTRUCT,1);
}