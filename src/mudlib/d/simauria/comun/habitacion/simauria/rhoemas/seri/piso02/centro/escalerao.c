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
  SetLocate("Seri-Solderteg, segundo piso");
  SetIntShort("una escalera");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntLong(W("Consigues llegar a la escalera que comunica los diferentes pisos del "
  	"templo de Seri-Solderteg. Puedes ver que va desde el último piso, arriba, hasta "
  	"la base del templo, mucho más abajo, pasando por cada uno que se encuentra a su "
  	"paso. A diferencia del resto del templo parece que se olvidaron de manterner "
  	"en buen estado la escalera.\n"));
  AddDetail(({"escalera"}),W("Es una retorcida escalera de caracol que se enreda sobre si "
  	"misma hasta comunicar todos los pisos. Parece algo vieja, pero aún es de utilidad.\n"));
  AddExit("sur",RHOEHAB("seri/piso02/oeste/pasillo_00")); 
  AddExit("arriba",RHOEHAB("seri/piso03/escalerao")); 
  AddExit("abajo",RHOEHAB("seri/piso01/centro/escalerao"));
}
