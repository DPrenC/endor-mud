/*
2008-09-14 [Angor] Creacion
*/

#include "path.h"
inherit THING;
#include <properties.h>

private int foodStuff;
private int foodHeal;
private string foodMsgs;

int cmd_comer(string s) {
    int i;
    if (s){
    	object ob = present(s,TP);
    	if (ob){
	    	if ((i = member(TO->QueryIds(),s)) >= 0) {
				write(foodMsgs);
				TP->AddFood(foodStuff);
				object ob = present("Asthar",environment(TP));
				if (ob) {
					//write("debug:asthar aqui, tutorial\n");
					environment(TP)->comer_cmd("manzana");
				}
				TO->remove();
			}
		}
    }
    return 1;
}

create() {
   ::create();
   SetShort("una manzana");
   SetLong("Es una manzana roja de buen tamaño.\n");
   AddId("manzana");
   SetWeight(100);
   SetValue(20);
   foodStuff=10;
   foodHeal=5;
   foodMsgs="Te comes una manzana roja.\n";
   Set(P_NOSELL,1);
}

init()
{
  ::init();
  add_action("cmd_comer","comer");
}