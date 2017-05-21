
#include <rooms.h>

#include <properties.h>
#include "path.h"

inherit ROOM;
inherit DRINK;

int beber_cmd(string str)
{
	if (str!="agua del manantial" && str!="agua")
	{
		return ::_drink(str);
	}
	else
	{
		//el jugador recupera sed y recupera algo de sobriedad y
		//recupera argo de magia
		if (TP->QueryDrink()<TP->QueryMaxDrink()-20)
		{
			TP->AddDrink(20);
		  	if (TP->QuerySP()<=TP->QueryMaxSP()-10) TP->AddSP(10);
		  	if (TP->QueryAlcohol()>0) TP->AddAlcohol(-5);
		  	tell_object(TP,"Notas una sensación refrescante como nunca habias tenido al beber.\n");
		  	return 1;
		}
		else
		{
		  	TP->AddDrink(TP->QueryMaxDrink()-TP->QueryDrink());
		  	//TP->AddSP(TP->QueryMaxsP()-TP->QuerySP());
		  	tell_object(TP, "Ya no tienes sed.\n");
		  	return 1;
		  }
	}
	return 1;
}

create(){
  ::create();
  SetIndoors(0);
  SetLocate("bosqueDehim");
  SetIntSmell("Huele a hierba fresca y a flores.\n");
  SetIntNoise("Escuchas el piar de los pájaros y el sonido de algún otro animal.\n");
  SetIntShort("un manantial");
  SetIntLong("Compruebas que el lago es donde desemboca un riachuelo que cae en cascada de"
    		"sde la roca de la montaña que tienes enfrente tuyo.\n");
  AddItem(ALUPNJ("duendeLago"),REFRESH_DESTRUCT,1);

  AddExit("noroeste",ALULAGO("bosque/lago1"));
}

init(){
  ::init();
  add_action("beber_cmd","beber");
}