/***************************************************************************************
 ARCHIVO:	nyrem.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Nyrem, el banquero
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Nyrem, el banquero","humano",10,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Nyrem");
  SetIds(({"humano","nyrem","Nyrem","banquero"}));
  Set(P_CANT_LURE,1);
  SetShort("Nyrem el banquero");
  SetLong(W("Nyrem es el banquero del pueblo. Es un hombre muy atareado y honrado "
  	"que guarda con mucho cuidado los ahorros de todos los que confían en él. "
  	"Siempre tiene la compañía de dos o más guardias, con los que habla sin cesar "
  	"para mitigar el aburrimiento. Parece una buena persona.\n"));
  AddQuestion(({"banco"}),W("Nyrem te dice: El banco es mi vida. Mi padre fue banquero, el padre de mi "
  	"padre fue banquero... lo llevo en la sangre.\n"),1);
  AddQuestion(({"guardia","guardias"}),W("Nyrem te dice: Pasan tanto tiempo conmigo que ya son como de "
  	"la familia... la verdad es que se agradece tanta protección, nunca se sabe lo "
  	"que los caminos traen al valle.\n"),1);
  AddQuestion(({"folleto"}),"Nyrem te dice: Um... dejame mirar.... creo que tenía uno por aquí...\n",1);

  InitChats(5,({"Nyrem revisa las cuentas.\n",
  		"Nyrem dice: Um... si cogiera un cobre de cada cuenta no se notaria...\n",
		"Nyrem dice: ¿Quieres algo forastero?.\n",
		"Nyrem dice: Si quieres saber mas puedes coger un folleto.\n"}));
  InitAChats(5,({"Nyrem grita: [52m ¡Guardias! ¡Guardias![0m.\n"}));
}