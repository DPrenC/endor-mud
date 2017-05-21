/***************************************************************************************
 ARCHIVO:	arrozal_01.c
 AUTOR:		[z] Zomax
 FECHA:		02-11-2001
 COMENTARIOS:	Arrozal n� 01, en Koek.
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

string farrozal()
{
	return TO->QueryIntLong();
}

int fbeber(string str)
{
	if (CHRONOS->QueryEstacion()==2)
	{
		if (str=="agua")
		{
			write("El agua est� algo turbia, mejor no beber de ella.\n");
			say(W(CATP+" se dispone a beber algo de agua, pero al ver "+
			"que est� turbia desiste.\n"),TP);
			return 1;
		}
	}
    return 0;
}

int fcoger(string str)
{
	/******************************  INVIERNO ******************************/
	if (CHRONOS->QueryEstacion()==1)
	{
		if (str=="nieve")
		{
			write(W("Coges algo de nieve con las manos, pero de repente "+
			"notas como si mil cuchillos se te clavaran en ellas y la sueltas "+
			"enseguida, con el fr�o que hace no deber�as hacer esas cosas.\n"));
			say(W(CATP+" coge algo de nieve con las manos, pero pone un cara "+
			"de espanto y dolor y tira todo otra vez al suelo, quiz�s sea porque "+
			"hace demasiado fr�o como para ir cogiendo nieve por aqu�.\n"),TP);
			return 1;
		}
	}
	/****************************** PRIMAVERA ******************************/
	if (CHRONOS->QueryEstacion()==2)
	{
		if (str=="agua")
		{
			write("El agua est� algo turbia, mejor no cogerla.\n");
			say(W(CATP+" se dispone a coger algo de agua, pero al ver "+
			"que est� turbia desiste.\n"),TP);
			return 1;
		}
	}
	/******************************   VERANO  ******************************/
	if (CHRONOS->QueryEstacion()==3)
	{
		if (str=="arroz")
		{
			write(W("Piensas... �para qu� quiero yo arroz crudo?, "+
			"mejor irme a la posada a comer.\n"));
			say(W(CATP+" se dispone a coger algo de arroz, se lo "+
			"piensa y decide que no.\n"),TP);
			return 1;
		}
	}
	/******************************   OTO�O   ******************************/
	if (CHRONOS->QueryEstacion()==4)
	{
		if ((str=="rastrojo") || (str=="rastrojos"))
		{
			write(W("Mejor no cogerlos, no sirven para nada y puede "+
			"haber alguno a�n ardiendo.\n"));
			say(W(CATP+" parece que va a coger un rastrojo, pero al "+
			"final no lo hace.\n"),TP);
			return 1;
		}
		if ((str=="ceniza") || (str=="cenizas"))
		{
			write("�Para qu� quieres ceniza?, mejor la dejas donde estaba.\n");
			say(W(CATP+" coge algo de ceniza, pero la vuelve a tirar.\n"),TP);
		}
	}
 return 0;
}

int fcavar(string str)
{
	/******************************  INVIERNO ******************************/
	if (CHRONOS->QueryEstacion()==1)
	{
		write(W("Te pones a cavar en la nieve y nada m�s hacer el primer movimiento "+
		"tus manos se enrrojecen del fr�o y se te quedan paralizadas, como congeladas. "+
		"En ese momento decides parar y dejar todo como est�.\n"));
		say(W(CATP+" se pone a cavar en la nieve, pero nada m�s empezar se le paralizan "+
		"las manos, ahora todas rojas del fr�o, y decide no seguir.\n"),TP);
		return 1;
	}
	/******************************   DEM�S   ******************************/
	else
	{
		write(W("Haces un primer impulso para ponerte a cavar, pero la verdad es que "+
		"no tienes ni tiempo ni ganas, y no quieres estropear nada del arrozal.\n"));
		say(W(CATP+" hace un primer impulso de ponerse a cavar, pero se lo piensa "+
		"mejor y lo deja, no sea cosa que estropee algo.\n"),TP);
		return 1;
	}
    return 0;
}

create () {
 ::create();

 SetIndoors(0);
 SetLocate("Arrozales de Koek");
 SetIntShort("un arrozal");
 AddRoomCmd("coger","fcoger");
 AddRoomCmd("cavar","fcavar");
 AddRoomCmd("beber","fbeber");
 AddDetail(({"arrozal"}),SF(farrozal));
 AddExit("sur",RHOEHAB("koek/campos/arrozal_03"));
 AddExit("oeste",RHOEHAB("koek/campos/arrozal_00"));
 AddExit("sudeste",RHOEHAB("koek/campos/arrozal_04"));
 AddItem(RHOEPNJ("koek/campos/ave"),REFRESH_DESTRUCT,1+random(3));
 /******************************  INVIERNO ******************************/
 if (CHRONOS->QueryEstacion()==1)
 {
 	SetIntLong(W(
 	"Te encuentras en uno de los arrozales a las afueras de Koek. "+
 	"Durante el crudo invierno, la zona est� totalmente cubierta "+
 	"por la nieve, y apenas puedes distinguir nada m�s que no sea eso. "+
 	"Por el norte y el este est� el helado r�o Hedrikon, que ba�a las "+
 	"tierras del lugar haci�ndolas muy buenas para el cultivo.\n"));
 	AddDetail(({"nieve"}),W(
 	"Debido a las grandes nevadas del invierno, todo el lugar est� "+
 	"te�ido de blanco por la nieve. No ha quedado nada al descubierto.\n"));
 	AddDetail(({"tierra","suelo"}),W(
 	"Supones que debe estar ah�, pero lo cierto es que con tanta nieve no "+
 	"ves nada de eso.\n"));
 	AddDetail(({"r�o","r�o","r�o hedrikon","r�o hedrikon","r�o hedrikon","r�o Hedrikon","hedrikon","Hedrikon"}),W(
 	"El r�o discurre por el norte y el este, aunque ahora no es m�s que una gran "+
 	"capa de hielo.\n"));
 	SetIntSmell(W(
 	"Tienes la nariz tan fr�a que no hueles nada.\n"));
 	SetIntNoise(W(
 	"Oyes los silbidos del aire g�lido al chocar con tus orejas.\n"));
 }
 /****************************** PRIMAVERA ******************************/
 if (CHRONOS->QueryEstacion()==2)
 {
 	SetIntLong(W(
 	"Te encuentras en uno de los arrozales a las afueras de Koek. "+
 	"En esta �poca del a�o los arrozales est�n completamente inundados "+
 	"por las aguas del r�o Hedrikon, que discurre por el norte y el este, y no "+
 	"llegas a distinguir nada m�s que agua por todas partes salvo "+
 	"unos peque�os brotes verdes que sobresalen.\n"));
 	AddDetail(({"nieve"}),W(
 	"Pr�cticamente ya no hay nieve, salvo en algunas zonas muy escondidas y "+
 	"peque�as donde no llega el sol, pero la mayor parte ya se ha derretido.\n"));
 	AddDetail(({"tierra","suelo"}),W(
 	"La tierra de esta zona es algo rojiza y muy f�rtil gracias a su proximidad "+
 	"con el r�o Hedrikon.\n"));
 	AddDetail(({"r�o","r�o","r�o hedrikon","r�o hedrikon","r�o hedrikon","r�o Hedrikon","hedrikon","Hedrikon"}),W(
 	"El r�o Hedrikon, que discurre por el norte y el este, est� ahora muy crecido por "+
 	"el deshielo, inundando el arrozal.\n"));
 	AddDetail(({"brote","brotes"}),W(
 	"Los brotes de arroz asoman t�midamente sus tallos entre el agua.\n"));
 	SetIntSmell(W(
 	"El olor a tierra mojada invade el ambiente.\n"));
 	SetIntNoise(W(
 	"Apenas oyes el sonido del viento acariciando cuanto toca.\n"));
 }
 /******************************   VERANO  ******************************/
 if (CHRONOS->QueryEstacion()==3)
 {
 	SetIntLong(W(
 	"Te encuentras en uno de los arrozales a las afueras de Koek. "+
 	"Es un campo de un color verde que alegra la vista con el arroz "+
 	"ya crecido y dispuesto para que los agricultores lo recojan. Al "+
 	"norte y al este puedes ver el r�o Hedrikon, ya m�s calmado despu�s de "+
 	"los deshielos de la primavera.\n"));
 	AddDetail(({"tierra","suelo"}),W(
 	"La tierra de esta zona es algo rojiza y muy f�rtil gracias a su proximidad "+
 	"con el r�o Hedrikon.\n"));
 	AddDetail(({"r�o","r�o","r�o hedrikon","r�o hedrikon","r�o hedrikon","r�o Hedrikon","hedrikon","Hedrikon"}),W(
 	"Al r�o discurre por el norte y el este, ahora m�s tranquilo, despu�s de los "+
 	"deshielos y el calor del verano.\n"));
 	AddDetail(({"arroz","planta de arroz"}),W(
 	"Las plantas del arroz est�n ya en su punto, y ya est�n siendo recogidas, "+
 	"ha sido una buena cosecha.\n"));
 	SetIntSmell(W(
 	"El olor a tierra mojada invade el ambiente.\n"));
 	SetIntNoise(W(
 	"Oyes el trinar de alg�n p�jaro no muy lejos.\n"));
 }
 /******************************   OTO�O   ******************************/
 if (CHRONOS->QueryEstacion()==4)
 {
 	SetIntLong(W(
 	"Te encuentras en uno de los arrozales a las afueras de Koek. "+
 	"Despu�s de la cosecha los agricultores se han dedicado a quemar "+
 	"los rastrojos que quedaban, y s�lo ves cenizas por todas partes. "+
 	"A�n queda algo de humo en el ambiente, incluso dir�as que hay "+
 	"zonas ardiendo en este momento.\n"));
 	AddDetail(({"tierra","suelo"}),W(
 	"La tierra de esta zona es algo rojiza y muy f�rtil gracias a su proximidad "+
 	"con el r�o Hedrikon.\n"));
 	AddDetail(({"r�o","r�o","r�o hedrikon","r�o hedrikon","r�o hedrikon","r�o Hedrikon","hedrikon","Hedrikon"}),W(
 	"Observas el r�o Hedrikon, al norte y al este, que proporciona gran riqueza a las "+
 	"tierras del lugar.\n"));
 	AddDetail(({"rastrojo","rastrojos","ceniza","cenizas"}),W(
 	"Hay restos de rastrojos y cenizas humeantes por todo el suelo.\n"));
 	AddDetail(({"humo"}),W(
 	"A�n queda humo en el ambiente de la quema de los rastrojos.\n"));
 	SetIntSmell(W(
 	"Huele a hierba quemada.\n"));
 	SetIntNoise(W(
 	"Oyes el sonido del viento que empieza a soplar con algo de fuerza.\n"));
 }
}
