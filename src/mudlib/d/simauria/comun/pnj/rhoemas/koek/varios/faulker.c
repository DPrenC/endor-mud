/***************************************************************************************
 ARCHIVO:	faulker.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Faulker, el cartero
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Faulker el cartero","humano",10,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Faulker");
  SetIds(({"humano","faulker","Faulker","cartero"}));
  SetShort("Faulker el cartero");
  SetLong(W("Faulker es el cartero del pueblo. Es un hombre mayor que lleva unas "
  	"gafas para poder leer bien las direcciones de las cartas. Tiene un aspecto "
  	"gentil pero al mismo tiempo sabes que será un duro contrincante en caso "
  	"de que te de por molestarle.\n"));
  AddQuestion(({"correo","correos","oficina de correo","oficina de correos"}),W("Faulker "
  	"te dice: Esta oficina es mi mayor tesoro... la verdad es que paso tanto tiempo aquí "
  	"porque es lo que mejor se me da y más me gusta.\n"),1);
  AddQuestion(({"folleto"}),"Faulker te dice: Um... dejame mirar.... creo que tenía uno por aquí...\n",1);
  AddItem(RHOEVAR("koek/varios/lentes"),REFRESH_REMOVE);
  InitChats(5,({"Faulker coge una carta, la abre y se pone a leerla.\n",
  		"Faulker bosteza aburrido.\n",
		"Faulker mira al trasluz una carta para ver que tiene dentro.\n",
		"Faulker ordena el correo.\n"}));
  InitAChats(5,({"Faulker grita: [52m ¡Guardias! ¡Guardias![0m.\n"}));
}