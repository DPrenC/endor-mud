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
  SetLocate("Seri-Solderteg, planta baja");
  SetIntShort("una escalera");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntLong(W("Contemplas una escalera de piedra un tanto estrecha y retorcida que "
  	"lleva al piso de arriba. Aún con su mal aspecto parece que es muy sólida, "
  	"sólo está algo descuidada.\n"));
  AddDetail(({"escalera"}),W("Observas con detalle una estrecha escalera de piedra que se "
  	"enreda sobre si misma hasta subir al piso de arriba.\n"));
  AddExit("sur",RHOEHAB("seri/piso00/oeste/pasillo_09")); 
  AddExit("arriba",RHOEHAB("seri/piso01/centro/escalerao")); 
}
