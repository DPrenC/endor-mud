/*
DESCRIPCION  : romana para pesar objetos
FICHERO      : /d/akallab/comun/objeto/otro/romana.c
MODIFICACION : 20-01-00 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit THING;
#include "path.h"
#include <properties.h>
#include <config.h>            //por el NOTIFY
#include "/secure/wizlevels.h" //para distinguir a los wizs

#define AO   (TP->QueryGender()==GENDER_FEMALE?"a":"o")
#define PESOMAX 30000 //maximo pesable con la romana

create() {
  ::create();
  AddId("romana");
  AddId("romana de metal");
  AddAdjective("de metal");
  SetShort("una romana de metal");
  SetLong("Es una balanza del tipo romana hecha de metal con un juego de pesas. "
  "Sirve para pesar objetos. Esta formada por una larga barra de metal en uno de "
  "cuyos extremos se cuelga en un gancho el objeto a pesar. Para pesar se coge "
  "con una mano un tirante sujeto al extremo de la barra que tiene el gancho y se "
  "desplazan las pesas a lo largo de la barra hasta que se equilibra la barra y queda "
  "horizontal. El peso del objeto se lee de las marcas en la barra que esten en la "
  "posicion hasta la que se hayan desplazado las pesas.\n");
  SetWeight(3000);
  SetValue(500);
}

init() {
  ::init();
  add_action("pesar_cmd","pesar");
}

private string QuePeso(object ob)
{
string s;
int kg,gr;

if IS_WIZARD(TP) s="exactamente "+(string)(ob->QueryWeight())+" gr";
else
{
kg=(ob->QueryWeight())/1000;
gr=((ob->QueryWeight())/100)*100-kg*1000; //redondea en multiplos de 100gr
s="";
if (kg!=0) s=(kg>1?"unos ":"")+(string)kg+" kg";
if ((kg!=0)&&(gr!=0)) s+=" y ";
if (gr!=0) s+=(gr>500?"medio"+(kg==0?" kg":""):"");
if (s=="") s="nada";
}
return s;
}

int pesar_cmd(string que)
{
int i, ok;
object ob;
string str,str2;
string *ids;

if (!que) {write("Que es lo que quieres pesar?\n");return 1;}
ok=0;
//peso de un objeto del inventorio
for(ob=first_inventory(TP);ob;ob=next_inventory(ob))
    {
    ids=ob->QueryIds();
    for(i=0;i<sizeof(ids);i++)
       if (ids[i]==que)
	   	{
		if (ob->QueryWeight()>PESOMAX)
	 		write(capitalize(ob->QueryShort())+" es demasiado grande para pesarlo en la romana.\n");
		else
		{
	   		write("Pesas con la romana "+lower_case(ob->QueryShort())+" que llevas. "
	    	      "Dirias que pesa "+QuePeso(ob)+".\n");
			say(capitalize(TP->QueryName())+" pesa algo con una romana.\n",TP);
		}
		i=sizeof(ids);
		ok=1;
	    }
   }

//peso de un objeto del entorno
for(ob=first_inventory(environment(TP));ob;ob=next_inventory(ob))
    {
    ids=ob->QueryIds();
    for(i=0;i<sizeof(ids);i++)
       if (ids[i]==que)
          {
		  if (ob->QueryWeight()>PESOMAX)
		  	write(capitalize(ob->QueryShort())+" es demasiado grande para pesarlo en la romana.\n");
		  else
		  {

		  	if (living(ob))
		    	{
		  		write(capitalize(ob->QueryName())+" no se deja pesar con la romana.\n");
		  		say(capitalize(ob->QueryName())+" no deja que "+capitalize(TP->QueryName())+" lo pese con la romana.\n",TP);
		  		}
			else
				{
		  		write("Pesas con la romana "+lower_case(ob->QueryShort())+" que hay aqui. "
          		      "Dirias que pesa "+QuePeso(ob)+".\n");
		  		say(capitalize(TP->QueryName())+" pesa algo con una romana.\n",TP);
				}
	      }
          ok=1;
          i=sizeof(ids);
          }
    }

if (ok==0) return notify_fail("No ves ningun "+que+" por aqui.\n",NOTIFY_NOT_VALID)&&0;
return 1;
}
