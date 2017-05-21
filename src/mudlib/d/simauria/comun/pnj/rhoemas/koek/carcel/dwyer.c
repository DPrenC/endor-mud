/***************************************************************************************
 ARCHIVO:	dwyer.c
 AUTOR:		[z] Zomax
 FECHA:		01-12-2001
 COMENTARIOS:	Dwyer, preso nº2 del calabozo nº3.
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 		22-04-2003 Cosas para el quest de Draego.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

create(){
  ::create();
  SetStandard("Dwyer","humano",10,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(50);
  SetAggressive(0);
  SetName("Dwyer");
  SetIds(({"humano","dwyer","Dwyer","preso"}));
  SetShort("Dwyer el delincuente");
  SetLong(W("Dwyer es un humano, un preso con el que compartes celda que no parece "
  	"tener muy buenas intenciones...\n"));
  AddQuestion(({"jabón","jabon","pastilla","pastilla de jabon","pastilla de jabón"}),W(
  	"Dwyer se pone a llorar y te dice: ¡No me recuerdes esas cosas!... snif ... aún "
  	"tengo pesadillas por las noches...\n"),1);
  AddQuestion(({"fuga","salir","carcel","fugarse","calabozo","salida"}),W("Dwyer te dice: "
  	"Solo alguien valiente como el que más puede escapar de la cárcel...\n"),1);
  AddQuestion(({"maestro"}),W("Dwyer te dice: Ahh... el maestro... la verdad es que las "
  	"cosas no nos han ido muy bien desde que se fue, casi pasamos más tiempo aquí "
  	"dentro que 'entrenando'.\n"),1);
}

init(){
  ::init();
  if (environment(TO)->QueryJabon())
  {
  	SetLong(W("Este es Dwyer, uno de los presos de aquí. Está muy "
  	"nervioso, de pie en una esquina y con la espalda completamente "
  	"pegada a la pared. No hace mas que mirar hacia todos lados y "
  	"hacia la pastilla de jabón que hay en el centro de la celda.\n"));
  }
  else
  {
  	SetLong(W("Este es Dwyer, uno de los presos de este calabozo. Está "
  	"muy relajado, tumbado en el suelo sin preocuparse de los demás. "
  	"No se molesta ni en mirarte.\n"));
  }
}
