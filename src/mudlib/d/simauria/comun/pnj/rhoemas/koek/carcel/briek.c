/***************************************************************************************
 ARCHIVO:	briek.c
 AUTOR:		[z] Zomax
 FECHA:		01-12-2001
 COMENTARIOS:	Briek, preso nº1 del calabozo nº3.
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 		22-04-2003 Cosas para el quest de Draego.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

create(){
  ::create();
  SetStandard("Briek","humano",10,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(50);
  SetAggressive(0);
  SetName("Briek");
  SetIds(({"humano","briek","Briek","preso"}));
  SetShort("el preso Briek");
  SetLong(W("Briek es un humano, un preso con el que compartes celda que no parece "
  	"tener muy buenas intenciones...\n"));
  AddQuestion(({"jabón","jabon","pastilla","pastilla de jabon","pastilla de jabón"}),W(
  	"Briek se pone a temblar y te dice: ¡No menciones eso aquí nunca!.\n"),1);
  AddQuestion(({"fuga","salir","carcel","fugarse","calabozo","salida"}),W("Briek te dice "
  	"con voz temerosa: Solo alguien valiente como el que más puede escapar de la cárcel.\n"),1);
  AddQuestion(({"maestro"}),W("Briek te dice: Nosotros aprendimos todo lo que sabemos de "
  	"nuestro famoso maestro... era como un padre para nosotros, nos adoptó de pequeños "
  	"y nos formó en el noble arte de... esto... ya sabes.\n"),1);
}

init(){
  ::init();
  if (environment(TO)->QueryJabon())
  {
  	SetLong(W("Este es Briek, uno de los presos de aquí. Está muy "
  	"nervioso, de pie en una esquina y con la espalda completamente "
  	"pegada a la pared. No hace mas que mirar hacia todos lados y "
  	"hacia la pastilla de jabón que hay en el centro de la celda.\n"));
  }
  else
  {
  	SetLong(W("Este es Briek, uno de los presos de este calabozo. Está "
  	"muy relajado, tumbado en el suelo sin preocuparse de los demás. "
  	"No se molesta ni en mirarte.\n"));
  }
}
