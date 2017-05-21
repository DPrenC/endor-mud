/*
DESCRIPCION : alforjas para una caballeria en las que transportar objetos
FICHERO     : /obj/alforjas.c
MODIFICACION: 31-01-00 [Angor@Simauria] Creacion basada en chest.c
---------------------------------------------------------------------------
*/

#include <properties.h>

inherit "/std/room/items"; // reset() is here
inherit CONTAINER;

string owner;

create () {
  ::create();
  owner="";
  SetShort("unas alforjas");
  SetLong("Son unas alforjas ordinarias utilizadas para transportar objetos "
            "a lomos de una caballeria.\n");
  SetPreIntShort("dentro de");
  SetIntShort("unas alforjas");
  SetIntLong ("Estas en el interior de unas alforjas.\n");
  SetPreContent("Contienen:\n");
  SetValue (250);
  SetWeight(2000);
  SetMaxIntWeight(30000);
  AddId ("alforjas");
  AddId ("alforja");
}

int    IsObjBag(){return 1;}
string QueryOwner(){return owner;}
int    SetOwner(string s){owner=s; return 1;}

init() {
  ::init();
    add_action("poner_cmd","poner");
}

int poner_cmd(string str) {
object obj, queobj,quienobj;
string que,quien;

 que="";
 quien="";
 if (!TP || !str) return 0;
 if (sscanf(str,"%s a %s",que,quien)==1)
    {
	if (que!="") write("Poner que a "+quien+"?\n");
			else write("Poner "+que+" a quien?\n");
	return 0;
	}
 if (sscanf(str,"%s a %s",que,quien)==2)
 	{
    for(obj=first_inventory(TP);obj;obj=next_inventory(obj))
	    if (que==obj->QueryName()) queobj=obj;
		if (obj->QueryIds())
		   {
		   if (member(obj->QueryIds(), que)!=-1) queobj=obj;
   		   }

 	for(obj=first_inventory(environment(TP));obj;obj=next_inventory(obj))
		{
		if ((!queobj) && (member(obj->QueryIds(), que)!=-1)) queobj=obj;
		if (member(obj->QueryIds(), quien)!=-1) quienobj=obj;
		}
    if ((!queobj) && (!quien))
		{
		write("Por aqui no hay ni "+que+" ni "+quien+" al que ponerlo!\n");
		return 0;
		}
    if (!queobj)
		{
		write("Por aqui no hay "+que+" para ponerselo a "+quien+".\n");
		return 0;
		}
    if (!quienobj)
		{
		write("Por aqui no hay "+quien+" al que ponerle "+que+".\n");
		return 0;
		}
     if (quienobj->QueryPuedeLlevarCarga()==1)
	    {
		write("Le pones "+que+" a "+quien+".\n");
		return 1;
		}
	 else
	    {
	 	if ((quienobj->QueryIsPlayer()) || (quienobj->QueryIsNPC()))
			{
			write(capitalize(quien)+" no deja que le pongas "+que+".\n");
			tell_object(quienobj, capitalize(TP->QueryName())+" trata de ponerte "+que+" pero tu no le dejas que lo haga.\n");
			return 1;
			}
		else
			{
			write("No puedes poner "+que+" a "+quien+".\n");
			return 1;
			}
		}
	}

   return 0;
}