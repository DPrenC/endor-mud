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
  SetLocate("Seri-Solderteg, planta baja");
  SetIntShort("una escalera");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntLong(W("Te encuentras en en lo que parece ser una escalera de caracol que conecta "
  	"los pisos de este templo. Desde aquí puedes subir con cuidado al primer piso. Es "
  	"bastante estrecha y algo inestable, pero merece la pena subir, piensas.\n"));
  AddDetail(({"escalera"}),W("Observas con detalle una estrecha escalera de piedra que se "
  	"enreda sobre si misma hasta subir al piso de arriba.\n"));
  AddExit("sur",RHOEHAB("seri/piso00/este/pasillo_09")); 
  AddExit("arriba",RHOEHAB("seri/piso01/centro/escalerae"));
}
