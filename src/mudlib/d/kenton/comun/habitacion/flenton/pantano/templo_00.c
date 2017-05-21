/***************************************************************************************
 ARCHIVO:	templo_00.c
 AUTOR:		[k] Korsario
 FECHA:		13-11-1998
 COMENTARIOS:	Templo en el pantano de la muerte
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit ROOM;

int entrar()
{
	call_out("advertencia",1);
	TP->move(FLENHAB+"pantano/templo_01",M_GO);
	return 1;
}

int advertencia()
{
	write("Una voz de ultratumba te dice: ¡Mortal! ¡Aléjate de aquí ahora que estás "
		"a tiempo... o lo pagarás con la muerte!\nSe oye una carcajada que te hiela "
		"la sangre en las venas.\n");
	return 1;
}

create() {
  ::create();

  SetIndoors(1);
  SetIntBright(40);
  SetLocate("pantano de la muerte");
  SetIntNoise("Escuchas los lamentos que trae el viento, gritos de agonía, el "
  	"dolor de los no muertos...\n");
  SetIntSmell("Huele fatal aquí, como a algo podrido.\n");

  SetIntShort("el templo del pantano de la muerte");
  SetIntLong("Estás en la entrada de lo que fue un gran templo antaño. Mas el "
  	"paso del tiempo o algo peor lo redujo a las ruinas que estás contemplando. "
  	"Las paredes y columnas que lo sostienen están cubiertas de plantas y musgos. "
  	"Ves un largo y oscuro corredor que se adentra en la estructura.\n");

  AddDetail(({"templo","ruinas"}),"Es un gran edificio, que en su tiempo debió ser "
  	"muy hermoso, mas ahora está casi sepultado por las plantas y está practicamente "
  	"en ruinas.\n");
  AddDetail(({"corredor","entrada"}),"Ves un oscuro corredor que se adentra en el templo.\n");
  AddExit("pantano",FLENHAB+"pantano/pantano_09");
  AddExit("entrar",SF(entrar));
}