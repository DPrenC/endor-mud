/*
2008-09-14 [Angor] Creacion
*/

#include "path.h"
inherit THING;
#include <properties.h>

private int foodStuff;
private int foodHeal;
private string foodMsgs;

int cmd_beber(string s) {
    int i;
    if (s){
    	object ob = present(s,TP);
    	if (ob){
	    	if ((i = member(TO->QueryIds(),s)) >= 0) {
				write(foodMsgs);
				TP->AddDrink(foodStuff);
				object ob = present("Asthar",environment(TP));
				if (ob) {
					//write("debug:asthar aqui, tutorial\n");
					environment(TP)->comer_cmd("cerveza");
				}
				TO->remove();
			}
		}
    }
    return 1;
}

create() {
   ::create();
   SetShort("una cerveza");
   SetLong("Es una jarra comun llena de cerveza.\n");
   AddId("cerveza");
   SetWeight(100);
   SetValue(20);
   foodStuff=10;
   foodHeal=5;
   foodMsgs="Te bebes la cerveza de un trago y tiras la jarra.\n";
   Set(P_NOSELL,1);
}

init()
{
  ::init();
  add_action("cmd_beber","beber");
}