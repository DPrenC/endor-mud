/***************************************************************************************
 ARCHIVO:	empalizada_10.c
 AUTOR:		[k] Korsario
 FECHA:		27-10-1998
 COMENTARIOS:	Empalizada que rodea Flenton
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

create() {
  ::create();

  SetIndoors(0);
  SetLocate("empalizada de flenton");
  SetIntNoise("Escuchas risa tras la empalizada del poblado.\n");
  SetIntSmell("Huele a frescor primaveral.\n");

  SetIntShort("los alrededores del poblado Flenton");
  SetIntLong("Est�s en las afueras del poblado de Flenton. Ves la alta "
  	"empalizada de madera que rodea el poblado y la copa de un gran "
  	"�rbol que sobresale en el centro del mismo.\n");

  AddDetail(({"madera","empalizada"}),"Ves la alta empalizada de madera "
  	"que rodea al poblado. Parece s�lida.\n");
  AddDetail(({"arbol","copa de un gran arbol","copa de arbol","�rbol"}),"Ves "
  	"la copa del gran �rbol que se encuentra en el centro del poblado.\n");

  AddExit("este",FLENHAB+"empalizada/empalizada_09");
  AddExit("noroeste",FLENHAB+"empalizada/empalizada_11");
}