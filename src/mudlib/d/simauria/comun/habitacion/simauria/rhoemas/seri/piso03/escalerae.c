/***************************************************************************************
 ARCHIVO:	altare.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Escalera este
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, tercer piso");
  SetIntShort("una escalera");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntLong(W("Estás en la parte superior de una de las escaleras que recorren el "
  	"templo por completo. Desde aquí tienes una perspectiva diferente y aún "
  	"no logras comprender cómo has sido capaz de subir por este maltrecho "
  	"montón de peldaños.\n"));
  
  AddDetail(({"escalera"}),W("Es una escalera de caracol de piedra algo descascarillada "
  	"por muchos sitios. No inspira mucha confianza, pero es lo que hay.\n"));
  AddExit("sur",RHOEHAB("seri/piso03/pasillo_11")); 
  AddExit("abajo",RHOEHAB("seri/piso02/centro/escalerae"));
}
