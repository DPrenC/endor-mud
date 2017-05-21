/***************************************************************************************
 ARCHIVO:	gusanos_seda.c
 AUTOR:		[z] Zomax
 FECHA:		25-04-2003
 COMENTARIOS:	Unos gusanos de seda.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit THING;

create () {
  ::create();

  SetShort("unos gusanos de seda");
  SetLong(W("Son unos pequeños gusanos blancos que segregan un líquido con el que hacen "
  	"capullos. Son muy feos, muy peludos, muy blancos y muy raros.\n"));
  SetIds(({"gusanos de seda","gusanos"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  Set(P_SIZE,P_SIZE_SMALL);
  SetWeight(50);
  SetValue(0);

  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
  Set(P_CANT_STEAL,1);
}

init(){
  ::init();

  add_action("fcoger","coger");
}

public int fcoger(string str)
{
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (!str) return 0;
	else lower_case(str);

	if (TO->id(str) && quest && member(quest,"tunica") && quest["tunica",0]==2)
	{
		quest+=(["tunica":3]);
		TO->move(TP,M_NOCHECK);
		write("Coges unos gusanos de seda.\n");
		return 1;
	}
	else if (TO->id(str))
	{
		write("Los gusanos son más listos de lo que pensabas y se te escurren al cogerlos.\n");
		return 1;
	}
}
