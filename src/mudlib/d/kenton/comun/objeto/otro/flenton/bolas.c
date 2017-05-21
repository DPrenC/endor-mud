/***************************************************************************************
 ARCHIVO:	bolas.c
 AUTOR:		[o] Okkita
 FECHA:		29-05-1997
 COMENTARIOS:	Unas bolas de malabares
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit "/std/unit";
inherit THING;

int njbolas;
int nbolas;

create(){
  ::create();
  Set(P_GENDER,GENERO_FEMENINO);
  SetShort("bola de malabares");
  SetPluralShort("bolas de malabares");
  SetIds(({"bola"}));
  SetPluralIds(({"bolas"}));
  SetAds(({"de malabares"}));
  SetValuePerUnit(5);
  SetWeightPerUnit(125);
  SetAmount(1);

  SetLong("Una bola para hacer juegos malabares. Es pequeña, ligera y suave "
  	"al tacto. Con más como esta podrías hacer fantasticos trucos.\n");
  SetPluralLong("Un juego de bolas de malabares. Son pequeñas, ligeras y suaves al "
  	"tacto. Con ellas podrías hacer fantasticos trucos y figuras.\n");
}

init(){
  ::init();
  add_action("fjugar","jugar");
  add_action("fpracticar","practicar");
  add_action("fparar","parar");
}

int QueryBola()
{
	return 1;
}

fjugar(str)
{
	nbolas=TO->QueryAmount();
	if (njbolas!=0)
	{
		if (njbolas==1)
		{
			notify_fail("Ya juegas con una bola.\n");
			return 0;
		}
		if (njbolas!=1)
		{
			notify_fail("Ya estás jugando con "+njbolas+".\n");
			return 0;
		}
	}
	if ((!str) || (str=="con") || (str=="bola") || (str=="bolas") || (nbolas <= 0))
	{
		notify_fail("Jugar con que o a que?\n");
		return 0;
	}
	if ((str=="con bola") || (str=="con una bola") || (str=="con 1 bola"))
	{
		write("Empiezas a jugar con una bola... (que aburrido, no?). "
		"Para dejar de jugar, escribe 'parar'\n");
      		njbolas=1;
      		TP->AddExtraLook("Esta jugando a los malabares con una bola.\n");
		call_out("fseguir_jugando",5);
		return 1;
	}
	if (str=="con bolas")
	{
		nbolas==TO->QueryAmount();
		if (nbolas==1)
		{
			write("Empiezas a jugar con una bola... (que aburrido, no?). "
			"Para dejar de jugar, escribe 'parar'\n");
			njbolas=1;
			TP->AddExtraLook("Esta jugando a los malabares con una bola.\n");
			call_out("fseguir_jugando",5);
			return 1;
		}
		else
		{
			write("Empiezas a hacer malabares con "+nbolas+" bolas.\n");
			njbolas=nbolas;
			TP->AddExtraLook("Esta jugando a los malabares con "+njbolas+" bolas.\n");
			call_out("fseguir_jugando",5);
			return 1;
		}
	}
	if (sscanf(str,"con %d bolas",nbolas)==1)
	{
		if ( (TO->QueryAmount()) < nbolas)
		{
			notify_fail("Solo tienes "+TO->QueryAmount()+" bolas.\n");
			return 0;
		}
		else
		{
			write("Empiezas a hacer malabares con "+nbolas+" bolas.\n");
			njbolas=nbolas;
			TP->AddExtraLook("Esta jugando a los malabares con "+njbolas+" bolas.\n");
			call_out("fseguir_jugando",5);
			return 1;
		}
	}
}

fseguir_jugando()
{
	if (njbolas==1)
	{
		write("Lanzas una bola hacia arriba, y la recoges antes de que "
			"caiga al suelo.\n");
		call_out("fseguir_jugando",10);
	}
	if (njbolas==2)
	{
		write("Estás malabareando dos bolas en una sola mano.\n");
		call_out("fseguir_jugando",9);
	}
	if (njbolas==3)
	{
		write("Malabareas una bonita cascada con las tres bolas.\n");
		call_out("fseguir_jugando",8);
	}
	if (njbolas==4)
	{
		write("Haces malabares con cuatro bolas a la vez. Estás hecho "
		"un experto ya!\n");
		call_out("fseguir_jugando",7);
	}
	if (njbolas==5)
	{
		write("Malabareas una cascada de cinco bolas. Impresionante!\n");
		call_out("fseguir_jugando",6);
	}
	if ((njbolas>5)&&(njbolas<=nbolas))
	{
		write("Increible, estás malabareando "+nbolas+" bolas!!!\n");
		call_out("fseguir_jugando",5);
	}
	else
	{
		notify_fail("Argo shungo pasa en er espashio-tiempo. "
		"Comunicashelo a un wisha.\n");
		return 0;
	}
}

fparar(str)
{
	if (njbolas < 1)
	{
		notify_fail("No estás jugando a los malabares.\n");
		return 0;
	}
	if (njbolas >= 1)
	{
		remove_call_out("fseguir_jugando");
		njbolas=0;
		write("Dejas de jugar a los malabares.\n");
		return 1;
	}
	else
	{
		notify_fail("Argo shungo pasa en er espashio-tiempo. "
		"Comunicashelo a un wisha.\n");
		return 0;
	}
}
