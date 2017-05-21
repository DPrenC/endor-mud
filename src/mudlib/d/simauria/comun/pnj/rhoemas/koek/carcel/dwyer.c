/***************************************************************************************
 ARCHIVO:	dwyer.c
 AUTOR:		[z] Zomax
 FECHA:		01-12-2001
 COMENTARIOS:	Dwyer, preso n�2 del calabozo n�3.
 MODIFICACI�N:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
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
  AddQuestion(({"jab�n","jabon","pastilla","pastilla de jabon","pastilla de jab�n"}),W(
  	"Dwyer se pone a llorar y te dice: �No me recuerdes esas cosas!... snif ... a�n "
  	"tengo pesadillas por las noches...\n"),1);
  AddQuestion(({"fuga","salir","carcel","fugarse","calabozo","salida"}),W("Dwyer te dice: "
  	"Solo alguien valiente como el que m�s puede escapar de la c�rcel...\n"),1);
  AddQuestion(({"maestro"}),W("Dwyer te dice: Ahh... el maestro... la verdad es que las "
  	"cosas no nos han ido muy bien desde que se fue, casi pasamos m�s tiempo aqu� "
  	"dentro que 'entrenando'.\n"),1);
}

init(){
  ::init();
  if (environment(TO)->QueryJabon())
  {
  	SetLong(W("Este es Dwyer, uno de los presos de aqu�. Est� muy "
  	"nervioso, de pie en una esquina y con la espalda completamente "
  	"pegada a la pared. No hace mas que mirar hacia todos lados y "
  	"hacia la pastilla de jab�n que hay en el centro de la celda.\n"));
  }
  else
  {
  	SetLong(W("Este es Dwyer, uno de los presos de este calabozo. Est� "
  	"muy relajado, tumbado en el suelo sin preocuparse de los dem�s. "
  	"No se molesta ni en mirarte.\n"));
  }
}
