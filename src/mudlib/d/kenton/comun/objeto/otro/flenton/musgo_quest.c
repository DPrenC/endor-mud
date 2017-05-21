/***************************************************************************************
 ARCHIVO:	musgo_quest.c
 AUTOR:		[k] Karu
 FECHA:		20-02-2002
 COMENTARIOS:	Un poco de musgo para cocinar
 MODIFICACIÓN:  Quito Give,Drop... y añado el owner en el init
 ***************************************************************************************/


#include "path.h"
#include <properties.h>

inherit THING;

string powner;

public void SetOwner(string name) { powner = name; }

public string QueryOwner() { return powner; }


create () {
 ::create();

  SetShort("un poco de musgo");
  SetLong("Un poco de musgo. Quizás si supieses cocinarlo diese mejor gusto a tus "
  	"comidas.\n");
  SetIds(({"musgo","musgo de Flenton","musgo de flenton"}));
  Set(P_GENDER,GENERO_MASCULINO);
  SetValue(0);
  SetWeight(100);
  Set(P_NOSELL, 1);
}

init(){
  ::init();

  if (!TO->QueryOwner() && environment(TO) && environment(TO)->QueryIsPlayer())
  	TO->SetOwner(environment(TO)->QueryRealName());
}
