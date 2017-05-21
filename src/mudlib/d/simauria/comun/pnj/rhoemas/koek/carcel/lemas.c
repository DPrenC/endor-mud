/***************************************************************************************
 ARCHIVO:	lemas.c
 AUTOR:		[z] Zomax
 FECHA:		01-12-2001
 COMENTARIOS:	Lemas, preso n�3 del calabozo n�3.
 MODIFICACI�N:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 		22-04-2003 Questions para el quest de Draego.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

create(){
  ::create();
  SetStandard("Lemas","humano",10,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(50);
  SetAggressive(0);
  SetName("Lemas");
  SetIds(({"humano","lemas","Lemas","preso"}));
  SetShort("el recluso Lemas");
  SetLong(W("Lemas es un humano, un preso con el que compartes celda que no parece "
  	"tener muy buenas intenciones...\n"));
  AddQuestion(({"jab�n","jabon","pastilla","pastilla de jabon","pastilla de jab�n"}),W(
  	"Lemas grita desesperado: Por favor... ll�vate el jab�n cuando te vayas... �MAM� TENGO MIEDO!.\n"),1);
  AddQuestion(({"fuga","salir","carcel","fugarse","calabozo","salida"}),W("Lemas te dice: "
  	"Solo alguien valiente como el que m�s puede escapar de la c�rcel...\n"),1);
  AddQuestion(({"maestro"}),W("Lemas te dice: Es una pena que el maestro se retirara. "
  	"De vez en cuando Rakon nos lee alguna de sus cartas, es el �nico de nosotros "
  	"que sabe leer...\n"),1);
}

init(){
  ::init();
  if (environment(TO)->QueryJabon())
  {
  	SetLong(W("Este es Lemas, uno de los presos de aqu�. Est� muy "
  	"nervioso, de pie en una esquina y con la espalda completamente "
  	"pegada a la pared. No hace mas que mirar hacia todos lados y "
  	"hacia la pastilla de jab�n que hay en el centro de la celda.\n"));
  }
  else
  {
  	SetLong(W("Este es Lemas, uno de los presos de este calabozo. Est� "
  	"muy relajado, tumbado en el suelo sin preocuparse de los dem�s. "
  	"No se molesta ni en mirarte.\n"));
  }
}
