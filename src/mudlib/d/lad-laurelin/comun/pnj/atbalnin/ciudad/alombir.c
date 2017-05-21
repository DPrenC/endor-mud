/*
	Alombir, Shopkeeper de la tienda de Atbalnin
	07-03-99, Theuzifan, creación
*/
	
#include "path.h"
#include <properties.h>
inherit NPC;


create()
{
  ::create();
  SetStandard("alombir", "medio-elfo", 8, GENDER_MALE);
  SetShort("Alombir, el tendero");
  SetLong(W("Alombir es un sujeto, cuando menos, "+
  	"curioso. Es alto comparado con sus congéneres, pero aún así no es "+
  	"lo que se puede decir un gigante."));
  	
  SetIds(({"tendero", "medio-elfo", "alombir", "Alombir"}));

  AddQuestion(({"silla", "taburete", "asiento"}),
  	W("Mmm... quizas tú puedas ayudarme -Alombir carraspea- tengo en la "+
  	"trastienda una silla bastante confortable que me gustaría que "+
  	"alguien llevase a Atlargon para reparar; Digamos que le daría unas "+
  	"monedas a quien quisiera echarme una mano.\n"));

  AddQuestion(({"cansancio", "cansado", "de pié", "de pie"}),
  	W("Algo cansado si que estoy (*suspiro*). Todo el mundo dice que "+
  	"podría usar otra para sentarme, pero si en algún sitio he de poner "+
  	"mi culo, será en mi vieja y querida silla, o en ningún otro sitio "+
  	"-le acabas de notar la influencia extremadamente y desde luego poco "+
  	"pragmática que supone tener sangre humana en las venas-.\n"));
  	
  InitChats(1,({
  	"Ves cómo Alombir cambia de postura, cansado de estar de pié.\n",
  	"Alombir va de un lado a otro de la tienda.\n",
  	"Alombir coge una escoba y se pone a menear un poco el polvo.\n",
  	"Alombir empieza a ordenar unos estantes; suspira y parece dejarlo.\n",
  	"Alombir te mira.\n"}));
}
