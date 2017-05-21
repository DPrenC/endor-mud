/***************************************************************************************
 ARCHIVO:	muelle_sur.c
 AUTOR:		[z] Zomax
 FECHA:		18-11-2001
 COMENTARIOS:	Extremo Sur del muelle
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("muelle");
int hielo;

create () {
  ::create();

  load_object(CHRONOS);
  SetLocate("Koek");
  SetIntShort("el extremo sur del muelle");
  carcel=(RHOEHAB("koek/muelle/muelle_centro"));

  AddExit("norte",RHOEHAB("koek/muelle/muelle_centro"));
  AddItem(RHOEPNJ("koek/varios/gato"),1,2);
  if (CHRONOS->QueryEstacion()==1)
  {
  	AddItem(RHOEVAR("koek/muelle/roca"),2,1);
  	hielo=1;
  }
  else hielo=0;
  AddItem(RHOEPNJ("koek/muelle/zaesh"),1,1);
  AddRoomCmd("empujar","fempujar");
  map[neu,des]= "Este es el extremo m�s al sur del muelle, y el que m�s se adentra en "
  	"el lago. Aqu� los pescadores lanzan sus ca�as al mar con la esperanza de "
  	"pescar alguna pieza y poder fanfarronear un poco con los amigos en la taberna. "
  	"Esta pesca es m�s deportiva que comercial, y rara vez ver�s aqu� a un pescador "
  	"muri�ndose de fr�o para pescar algo. ";
}

reset(){
  ::reset();
  if (CHRONOS->QueryEstacion()==1) hielo=1;
  else hielo=0;

  AddDetail(({"lago"}),W("Desde aqu� puedes ver el lago. Est� completamente helado, "
  	"pero no consigues adivinar el grosor de la capa de hielo. Mejor no andar "
  	"sobre el hielo, puede ser peligroso.\n"));
}

int QueryPescar()	{ return 1; }
int QueryHielo()	{ return hielo; }

int fempujar(string str)
{
	if ((str=="roca" || str=="roca pesada") && CHRONOS->QueryEstacion()==1)
	{
		if (present("roca pesada",TO))
		{
			write("Empujas la pesada roca al lago que rompe el hielo f�cilmente.\n");
			say(W(CATP+" empuja una pesada roca al lago que rompe el hielo con "
				"facilidad.\n"),TP);
			AddDetail(({"lago"}),W(
			"Desde aqu� puedes ver el lago. Est� completamente helado menos en "
			"un gran boquete justo debajo de este muelle, pero no consigues "
			"adivinar el grosor de la capa de hielo. Mejor no andar sobre el "
			"hielo, puede ser peligroso.\n"));
			present("roca pesada",TO)->remove();
			hielo=0;
		}
		else write("No encuentras ninguna roca para empujar.\n");
		return 1;
	}
}

	
	