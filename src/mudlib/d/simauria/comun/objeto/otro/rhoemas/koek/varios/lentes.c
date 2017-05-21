/***************************************************************************************
 ARCHIVO:	lentes.c
 AUTOR:		[z] Zomax
 FECHA:		20-12-2001
 COMENTARIOS:	Unas lentes (o gafas, lo que sea)
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("unas lentes");
  SetLong(W("Son unas lentes para poder ver con claridad. Sobre todo para leer. "
  	"En esencia son un par de cristales curvos unidos entre si por unas varillas "
  	"metálicas.\n"));
  AddSubDetail(({"cristales","cristal"}),W("Hay un par de cristales cogidos a unas "
  	"varillas. Son bastante gruesos.\n"));
  AddSubDetail(({"varilla","varillas"}),W("Unas simples varillas metálicas que sujetan "
  	"los cristales.\n"));
  SetIds(({"lentes"}));
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(50);
  SetValue(500);
  SetMaterial(M_CRISTAL);
}

init(){
  ::init();
  add_action("fponerse","ponerse");
}

int fponerse(string str)
{
	if (str=="lentes")
	{
		write("Te pones las lentes... lo ves todo tan borroso que decides quitártelas.\n");
		say(W(CATP+" se pone unas lentes, pero parece mareado, así que decide quitárselas.\n"),TP);
		return 1;
	}
}
