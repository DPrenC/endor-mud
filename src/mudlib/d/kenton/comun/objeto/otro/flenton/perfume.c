/***************************************************************************************
 ARCHIVO:	vitrina.c
 AUTOR:		[k] Korsario
 FECHA:		10-02-1999
 COMENTARIOS:	La vitrina de la plazoleta del dragón.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

int cantidad;
int dedicado;
string msg;

create(){
  ::create();
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"frasco","perfume","colonia"}));
  SetWeight(50);
  SetValue(1000);
  cantidad=100;
  dedicado=0;
  msg="";
  SetNoise("Escuchas la dulce melodia que desprende el frasco de perfume.\n");
  SetSmell("Es una fragancia que encierra la belleza en si de las cosas. "
  	"Olerla es recordar aquello que es para ti mas querido. Esta hecha "
  	"de la misma esencia de los sueños, y es distinta para cada persona "
  	"y para cada momento.\n");

  SetShort("un frasco de permufe");
  SetLong("Ves un bonito frasco de perfume. Es de cristal y es muy "
  	"delicado. Su color varía a cada instante, dependiendo de desde "
  	"donde incida la luz. Es como si hubieran capturado el mismo "
  	"arcoiris en su interior.\n");
}

init(){
  ::init();

  add_action("perfumar","perfumar");
  add_action("fdedicar","dedicar");
  add_action("fleer","leer");
}

perfumar(string ello)
{
	object obj;
	if(!ello) return 0;
	if(cantidad==0) return notify_fail("El frasco de perfume esta vacio.\n");
	if(obj=present(ello,TP))
	{
		write("Perfumas "+obj->QueryShort()+".\n");
		obj->SetSmell(QuerySmell());
		cantidad--;
		return 1;
	}
	if(obj=present(ello,environment(TP)))
	{
		if(interactive(obj))
		{
			tell_object(obj,CATP+" te perfuma con un maravilloso aroma.\n");
			write("Perfumas a "+obj->QueryName()+".\n");
			obj->SetSmell(QuerySmell());
			cantidad--;
			return 1;
		}
		else
		{
			write("Perfumas "+obj->QueryShort()+".\n");
			obj->SetSmell(QuerySmell());
			cantidad--;
			return 1;
		}
	}
	return notify_fail("Perfumar que o quien?\n");
}

fdedicar(string str)
{
	object ded;
  	if(!str)  return notify_fail("Dedicar el perfume a quien?\n");
	if(dedicado) return notify_fail("El frasco ya esta dedicado.\n");
	if(!ded=find_object(lower_case(str)))
	return notify_fail("No se encuentra dicho jugador.\n");
	write("Dedicas el perfume a "+ded->QueryName()+".\n");
	SetLong(QueryLong()+"Hay una notita en el.\n");
	msg="Dedicado a "+ded->QueryName()+" de parte de "+TP->QueryName()+".\n";
	dedicado=1;
	return 1;
}

fleer(string str)
{
	if(!str||!dedicado) return 0;
	if(str=="notita"||str=="nota"||str=="perfume")
	{
		write("En la nota esta escrito lo siguiente:\n\t"+msg);
		return 1;
	}
	return 0;
}
