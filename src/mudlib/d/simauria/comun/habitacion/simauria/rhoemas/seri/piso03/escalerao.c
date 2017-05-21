/***************************************************************************************
 ARCHIVO:	escalerao.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Escalera oeste
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
  SetIntLong(W("Estás en la parte superior de una larga escalera de caracol que baja "
  	"por todos los pisos hasta la base del templo. Puedes ver que la escalera no "
  	"es un ejemplo de seguridad y sin duda la caída será inolvidable como pongas "
  	"un pie donde no toca.\n"));
  AddDetail(({"escalera"}),W("Es una retorcida escalera de caracol que se enreda sobre si "
  	"misma hasta comunicar todos los pisos. Parece algo vieja, pero aún es de utilidad.\n"));
  AddExit("sur",RHOEHAB("seri/piso03/pasillo_01")); 
  AddExit("abajo",RHOEHAB("seri/piso02/centro/escalerao"));
}
