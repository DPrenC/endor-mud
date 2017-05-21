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
  SetLocate("Seri-Solderteg, primer piso");
  SetIntShort("una escalera");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntLong(W("Estás en una retorcida escalera que conecta el segundo piso y la planta baja "
  	"del templo pasando por este. Está hecha de piedra, como el resto del templo, y a pesar "
  	"de no estar en su mejor momento parece muy resistente.\n"));
  AddDetail(({"escalera"}),W("La escalera es de roca gris, como las paredes, pero no parece "
  	"haber sido conservada tan cuidadosamente como el resto del templo.\n"));
  AddExit("sur",RHOEHAB("seri/piso01/oeste/pasillo_00")); 
  AddExit("arriba",RHOEHAB("seri/piso02/centro/escalerao")); 
  AddExit("abajo",RHOEHAB("seri/piso00/centro/escalerao"));
}
