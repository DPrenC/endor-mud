/*
DESCRIPCION  : pequenya balanza para pesar objetos
FICHERO      : /d/akallab/comun/objeto/otro/balanza.c
MODIFICACION : 20-01-00 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit THING;
#include "path.h"
#include <properties.h>
#include <config.h>            //por el NOTIFY
#include "/secure/wizlevels.h" //para distinguir a los wizs

#define AO   (TP->QueryGender()==GENDER_FEMALE?"a":"o")
#define PESOMAX 5000 //maximo pesable con la balanza

create() {
  ::create();
  AddId("balanza");
  AddId("balanza de metal");
  AddAdjective("pequenya");
  AddAdjective("de metal");
  SetShort("una pequenya balanza de metal");
  SetLong("Es un pequenya balanza de metal con un juego de pesas. Sirve para "
  "pesar objetos pequenyos. Esta formada por dos pequenyo cuencos de metal que "
  "cuelgan de sendos extremos de una varilla horizontal. Para pesar se coge con "
  "una mano un tirante sujeto al centro de varilla y con la otra se van colocando "
  "las pesas en uno de los cuencos hasta que se equilibra el peso con el del "
  "objeto a pesar que esta en el otro.\n");
  SetWeight(500);
  SetValue(100);
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
if (gr!=0) s+="unos "+(string)gr+" gr";
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
	 		write(capitalize(ob->QueryShort())+" es demasiado grande para pesarlo en la balanza.\n");
		else
		{
	   		write("Pesas con la balanza "+lower_case(ob->QueryShort())+" que llevas. "
	    	      "Dirias que pesa "+QuePeso(ob)+".\n");
			say(capitalize(TP->QueryName())+" pesa algo con una balanza.\n",TP);
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
		  	write(capitalize(ob->QueryShort())+" es demasiado grande para pesarlo en la balanza.\n");
		  else
		  {
		  	if (living(ob))
		    	{
		  		write(capitalize(ob->QueryName())+" no se deja pesar con la balanza.\n");
		  		say(capitalize(ob->QueryName())+" no deja que "+capitalize(TP->QueryName())+" lo pese con la balanza.\n",TP);
		  		}
			else
				{
		  		write("Pesas con la balanza "+lower_case(ob->QueryShort())+" que hay aqui. "
          		      "Dirias que pesa "+QuePeso(ob)+".\n");
		  		say(capitalize(TP->QueryName())+" pesa algo con una balanza.\n",TP);
				}
	      }
          ok=1;
          i=sizeof(ids);
          }
    }

if (ok==0) return notify_fail("No ves ningun "+que+" por aqui.\n",NOTIFY_NOT_VALID)&&0;
return 1;
}
