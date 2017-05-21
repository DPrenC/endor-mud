/***************************************************************************************
 ARCHIVO:	thobwyn.c
 AUTOR:		[z] Zomax
 FECHA:		08-01-2002
 COMENTARIOS:	Thobwyn, el graciosillo de Koek
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

private string fchiste()
{
	int linea;
	mixed archivo;
	string chiste;
	if (!random(3))
	{
		switch(random(4))
		{
			case 0:	 return "Thobwyn te mira y suelta una carcajada que te mosquea.\n";
			case 1:	 return "Thobwyn empieza a reirse solo.\n";
			case 2:	 return "Thobwyn copia tus movimientos como un mimo. Tienes ganas de matarle.\n";
			default: return "Thobwyn empieza a llorar de risa hasta casi perder el aliento.\n";
		}
	}
	else if (archivo=RHOETXT("chistes/chistes.t"))
	{
		linea=1+random(31);
		if (chiste=read_file(archivo,linea,1))
		{
			chiste=regreplace(chiste,"FIN","\n",1);
			chiste=W(chiste);
			return "Thobwyn cuenta un chiste:\n[52m"+chiste+"[0m";
		}
		return "Thobwyn se concentra.\n";
	}
	else return "Thobwyn se concentra.\n";
}

create(){
  ::create();
  SetStandard("Thobwyn el gracioso","humano",10,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Thobwyn");
  SetIds(({"humano","thobwyn","Thobwyn","gracioso"}));
  SetShort("Thobwyn el gracioso");
  SetLong(W("Thobwyn es el bufón del pueblo. Es un humano algo bajito con aspecto "
  	"de kender que tiene un sentido del humor algo especial. Siempre está haciendo "
  	"bromas y contando chistes sin que nadie le diga nada. La verdad es que a veces "
  	"dan ganas de matarle.\n"));
  AddQuestion(({"chiste","chistes","broma","bromas"}),W("Thobwyn te dice: No hay nada "
  	"como un buen chiste para animar el ambiente.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Thobwyn te dice: Si no fuera por mi este pueblo estaría echado a perder desde hace mucho.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Thobwyn te dice: Es el único lugar donde no iría a contar chistes.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W(
	"Thobwyn te dice: Son demasiado serios, la verdad es que prefiero el pueblo.\n"),1);
  InitChats(7,({SF(fchiste)}));
  InitAChats(5,"Thobwyn dice:[53m ¡¿Pero es que no tienes sentido del humor?!.[0m\n");
  AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["oro":random(10)])]));
}
