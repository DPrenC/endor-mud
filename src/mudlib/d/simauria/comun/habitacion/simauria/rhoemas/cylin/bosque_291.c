/***************************************************************************************

 ARCHIVO:	bosque_291.c

 AUTOR:		[z] Zomax

 FECHA:		14-11-2001

 COMENTARIOS:	Bosque Cylin, en Koek

 ***************************************************************************************/



#include <moving.h>

#include "path.h"



inherit RHOESTD("bosque");



int pulsado1,pulsado2,pulsado3;



int fabrir()

{

	if (pulsado1 && pulsado2 && pulsado3)

	{

		write(W("Intentas abrir la puerta, sin ningún esfuerzo lo consigues y "

			"la cruzas hacia el templo.\n"));

		say(W(CATP+" intenta abrir la puerta, lo consigue y se marcha hacia el "

			"templo.\n"),TP);

		TP->move(RHOEHAB("seri/piso00/centro/cylin"),M_SILENT);

		tell_room(RHOEHAB("seri/piso00/centro/cylin"),W("Oyes como de repente "

		"las puertas se abren y "+CATP+" aparece cruzandolas con la cara "

		"pálida como la misma muerte. Sin darte tiempo a reaccionar las "

		"puertas se cierran.\n"),({TP}));

		TP->LookAfterMove();

		pulsado1=0;

		pulsado2=0;

		pulsado3=0;

		HideExit("sur",1);

		return ME_NO_ENTER;

	}

	else

	{

		write(W("Intentas abrir la puerta, pero lo único que consigues es cansarte. "

			"Quizás debieras buscar otro método.\n"));

		say(W(CATP+" intenta abrir la puerta, pero no lo consigue.\n"));

		tell_room(RHOEHAB("seri/piso00/centro/cylin"),W("Oyes ruidos extraños como "

			"si alguien o algo intentara entrar desde el otro lado de la "

			"puerta pero, afortunadamente para ti, no lo consigue.\n"));

		return ME_NO_ENTER;

	}

}



int fpuerta(string str)

{

	if (str=="puerta" && pulsado1 && pulsado2 && pulsado3)

	{

		fabrir();

		return 1;

	}

	else if (str=="puerta")

	{

		write(W("En la vida lograrás abrir esta puerta de una forma convencional, "

			"es demasiado pesada.\n"));

		return 1;

	}

}



int fembestir(string str)

{

	if (str=="puerta")

	{

		if (TP->QueryHP()<=50)

		{

			object brecha;

			write(W("Te dispones a embestir la puerta... coges carrerilla "

			"y... BOOOOOOOOOOOOOOOOOOOMMMMMMM.\n"));

			say(W(CATP+" se dispone a embestir la puerta... coge carrerilla "

			"y.... BOOOOOOOOOOOOOOOOOOOMMMMMMM.\n"),TP);

			tell_room(RHOEHAB("seri/piso00/centro/cylin"),W("Oyes un "

			"golpe seco en la puerta que viene de la otra parte. "

			"Rezas para que no se abra.\n"),({TP}));

			brecha=clone_object(RHOEVAR("koek/carcel/brecha"));

			brecha->move(TP,M_SILENT);

		}

		else

		{

			TP->AddHP(-50);

			write(W("Te dispones a embestir la puerta... coges "

			"carrerilla y... BOOOOOOOOOOOOOOOOOOOMMMMMMM un golpe "

			"seco en tu cuerpo te deja hecho polvo... te encuentras mal.\n"));

			say(W(CATP+" se dispone a embestir la puerta... coge "

			"carrerilla y... BOOOOOOOOOOOOOOOOOOOMMMMMMM un golpe "

			"seco en su cuerpo le deja hecho polvo... tiene mala "

			"pinta.\n"),TP);

			tell_room(RHOEHAB("seri/piso00/centro/cylin"),W("Oyes un "

			"golpe seco en la puerta que viene de la otra parte. "

			"Rezas para que no se abra.\n"),({TP}));

		}

		return 1;

	}

}



int fpulsar(string str)

{

	if (str=="ojo" || str=="ojos" || str=="ojos brillantes")

	{

		if (pulsado1)

		{

			write(W("Pulsas en los ojos de las criaturas dibujadas en la "

			"puerta, pero no notas nada especial.\n"));

			say(W(CATP+" se pone a tocar por la puerta, pero no encuentra nada.\n"),TP);

		}

		else

		{

			write(W("Pulsas en los ojos de las criaturas que hay representadas "

			"en la puerta... de repente uno de ellos se hunde. Parece que has "

			"activado parte de un mecanismo.\n"));

			say(W(CATP+" se pone a tocar por la puerta y acciona un mecanismo.\n"),TP);

			pulsado1=1;

			if (pulsado1 && pulsado2 && pulsado3)

			{

				write("Parece que la puerta está abierta. Ahora puedes pasar.\n");

				say(W("Parece que "+CATP+" ha conseguido abrir la puerta.\n"));

				AddExit("sur",SF(fabrir));

			}

		}

		return 1;

	}

	else if (str=="diente")

	{

		if (pulsado2)

		{

			write(W("Empujas el diente de la criatura dibujada en la "

			"puerta, pero no notas nada especial.\n"));

			say(W(CATP+" se pone a tocar por la puerta, pero no encuentra nada.\n"),TP);

		}

		else

		{

			write(W("Empujas el diente de la criaturas que hay representada "

			"en la puerta... de repente se hunde. Parece que has "

			"activado parte de un mecanismo.\n"));

			say(W(CATP+" se pone a tocar por la puerta y acciona un mecanismo.\n"),TP);

			pulsado2=1;

			if (pulsado1 && pulsado2 && pulsado3)

			{

				write("Parece que la puerta está abierta. Ahora puedes pasar.\n");

				say(W("Parece que "+CATP+" ha conseguido abrir la puerta.\n"));

				AddExit("sur",SF(fabrir));

			}

		}

		return 1;

	}

	else

	{

		notify_fail("¿Pulsar <qué>?\n");

		return 0;

	}

}



int fbuscar(string str)

{

	if (str=="mecanismo" && !pulsado3)

	{

		write(W("Te pones a buscar y encuentras una cosa muy rara en la puerta. "

		"Parece algún tipo de mecanismo. Lo pulsas.\n"));

		say(W(CATP+" se pone a buscar por todas partes y encuentra un mecanismo. "

		"Lo activa de inmediato.\n"),TP);

		pulsado3=1;

		if (pulsado1 && pulsado2 && pulsado3)

		{

			write("Parece que la puerta está abierta. Ahora puedes pasar.\n");

			say(W("Parece que "+CATP+" ha conseguido abrir la puerta.\n"));

			AddExit("sur",SF(fabrir));

		}

		return 1;

	}

	else if (str=="mecanismo" && pulsado3)

	{

		write("Encuentras un mecanismo, pero ya está activado.\n");

		return 1;

	}

}



reset(){

 ::reset();

 pulsado1=0;

 pulsado2=0;

 pulsado3=0;

 HideExit("sur",1);

}



create () {

 ::create();



 SetLocate("Bosque de Cylin");

 SetIntShort("el bosque de Cylin");

 AddExit("norte",RHOEHAB("cylin/bosque_281"));

 AddExit("sur",SF(fabrir));

 HideExit("sur",1);

 AddRoomCmd("abrir","fpuerta");

 AddRoomCmd("embestir","fembestir");

 AddRoomCmd("pulsar","fpulsar");

 AddRoomCmd("empujar","fpulsar");

 AddRoomCmd("buscar","fbuscar");

 fanimales();

 pulsado1=0;

 pulsado2=0;

 pulsado3=0;

 AddDetail(({"puerta","puerta de metal"}),W("Una extraña puerta se alza delante de ti. "

 	"Tiene unos dibujos muy extraños, algunos con ojos brillantes y aterradores. En "

 	"uno de los dibujos puedes ver unos dientes afilados que devoran a algún incauto.\n"));

 AddDetail(({"dientes","dientes afilados","dientes afilados"}),W("Piensas en que como la "

 	"escena ocurriera de verdad no te gustaría estar bajo esos dientes. Ves uno en "

 	"particular muy extraño.\n"));

 AddDetail(({"ojos","ojos brillantes"}),"Sólo de verlos te dan escalofríos.\n");

 AddDetail(({"diente","diente extraño","diente extranyo","diente particular"}),W("Si no supieras "

 	"que es imposible, dirías que se parece sospechosamente a una palanca o botón.\n"));

 AddDetail(({"incauto","víctima","victima"}),W("El pobre lo debe pasar mal entre "

 	"esas mandíbulas. Te alegras de no ser tú.\n"));

 AddDetail(({"dibujos","dibujos extraños","dibujos extranyos"}),W("Representan horripilantes seres "

 	"demoniacos. Un escalofrío recorre tu espalda al pensar qué pasaría si de repente "
 	"cobraran vida.\n"));

}



init(){

  ::init();

  SetIntLong(W(TO->QueryIntLong()+"Puedes ver una enorme puerta de metal "

  	"fuertemente cerrada.\n"));

}

