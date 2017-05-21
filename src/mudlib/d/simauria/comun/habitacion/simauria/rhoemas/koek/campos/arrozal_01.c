/***************************************************************************************
 ARCHIVO:	arrozal_01.c
 AUTOR:		[z] Zomax
 FECHA:		02-11-2001
 COMENTARIOS:	Arrozal nº 01, en Koek.
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
			write("El agua está algo turbia, mejor no beber de ella.\n");
			say(W(CATP+" se dispone a beber algo de agua, pero al ver "+
			"que está turbia desiste.\n"),TP);
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
			"enseguida, con el frío que hace no deberías hacer esas cosas.\n"));
			say(W(CATP+" coge algo de nieve con las manos, pero pone un cara "+
			"de espanto y dolor y tira todo otra vez al suelo, quizás sea porque "+
			"hace demasiado frío como para ir cogiendo nieve por aquí.\n"),TP);
			return 1;
		}
	}
	/****************************** PRIMAVERA ******************************/
	if (CHRONOS->QueryEstacion()==2)
	{
		if (str=="agua")
		{
			write("El agua está algo turbia, mejor no cogerla.\n");
			say(W(CATP+" se dispone a coger algo de agua, pero al ver "+
			"que está turbia desiste.\n"),TP);
			return 1;
		}
	}
	/******************************   VERANO  ******************************/
	if (CHRONOS->QueryEstacion()==3)
	{
		if (str=="arroz")
		{
			write(W("Piensas... ¿para qué quiero yo arroz crudo?, "+
			"mejor irme a la posada a comer.\n"));
			say(W(CATP+" se dispone a coger algo de arroz, se lo "+
			"piensa y decide que no.\n"),TP);
			return 1;
		}
	}
	/******************************   OTOÑO   ******************************/
	if (CHRONOS->QueryEstacion()==4)
	{
		if ((str=="rastrojo") || (str=="rastrojos"))
		{
			write(W("Mejor no cogerlos, no sirven para nada y puede "+
			"haber alguno aún ardiendo.\n"));
			say(W(CATP+" parece que va a coger un rastrojo, pero al "+
			"final no lo hace.\n"),TP);
			return 1;
		}
		if ((str=="ceniza") || (str=="cenizas"))
		{
			write("¿Para qué quieres ceniza?, mejor la dejas donde estaba.\n");
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
		write(W("Te pones a cavar en la nieve y nada más hacer el primer movimiento "+
		"tus manos se enrrojecen del frío y se te quedan paralizadas, como congeladas. "+
		"En ese momento decides parar y dejar todo como está.\n"));
		say(W(CATP+" se pone a cavar en la nieve, pero nada más empezar se le paralizan "+
		"las manos, ahora todas rojas del frío, y decide no seguir.\n"),TP);
		return 1;
	}
	/******************************   DEMÁS   ******************************/
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
 	"Durante el crudo invierno, la zona está totalmente cubierta "+
 	"por la nieve, y apenas puedes distinguir nada más que no sea eso. "+
 	"Por el norte y el este está el helado río Hedrikon, que baña las "+
 	"tierras del lugar haciéndolas muy buenas para el cultivo.\n"));
 	AddDetail(({"nieve"}),W(
 	"Debido a las grandes nevadas del invierno, todo el lugar está "+
 	"teñido de blanco por la nieve. No ha quedado nada al descubierto.\n"));
 	AddDetail(({"tierra","suelo"}),W(
 	"Supones que debe estar ahí, pero lo cierto es que con tanta nieve no "+
 	"ves nada de eso.\n"));
 	AddDetail(({"río","río","río hedrikon","río hedrikon","río hedrikon","río Hedrikon","hedrikon","Hedrikon"}),W(
 	"El río discurre por el norte y el este, aunque ahora no es más que una gran "+
 	"capa de hielo.\n"));
 	SetIntSmell(W(
 	"Tienes la nariz tan fría que no hueles nada.\n"));
 	SetIntNoise(W(
 	"Oyes los silbidos del aire gélido al chocar con tus orejas.\n"));
 }
 /****************************** PRIMAVERA ******************************/
 if (CHRONOS->QueryEstacion()==2)
 {
 	SetIntLong(W(
 	"Te encuentras en uno de los arrozales a las afueras de Koek. "+
 	"En esta época del año los arrozales están completamente inundados "+
 	"por las aguas del río Hedrikon, que discurre por el norte y el este, y no "+
 	"llegas a distinguir nada más que agua por todas partes salvo "+
 	"unos pequeños brotes verdes que sobresalen.\n"));
 	AddDetail(({"nieve"}),W(
 	"Prácticamente ya no hay nieve, salvo en algunas zonas muy escondidas y "+
 	"pequeñas donde no llega el sol, pero la mayor parte ya se ha derretido.\n"));
 	AddDetail(({"tierra","suelo"}),W(
 	"La tierra de esta zona es algo rojiza y muy fértil gracias a su proximidad "+
 	"con el río Hedrikon.\n"));
 	AddDetail(({"río","río","río hedrikon","río hedrikon","río hedrikon","río Hedrikon","hedrikon","Hedrikon"}),W(
 	"El río Hedrikon, que discurre por el norte y el este, está ahora muy crecido por "+
 	"el deshielo, inundando el arrozal.\n"));
 	AddDetail(({"brote","brotes"}),W(
 	"Los brotes de arroz asoman tímidamente sus tallos entre el agua.\n"));
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
 	"norte y al este puedes ver el río Hedrikon, ya más calmado después de "+
 	"los deshielos de la primavera.\n"));
 	AddDetail(({"tierra","suelo"}),W(
 	"La tierra de esta zona es algo rojiza y muy fértil gracias a su proximidad "+
 	"con el río Hedrikon.\n"));
 	AddDetail(({"río","río","río hedrikon","río hedrikon","río hedrikon","río Hedrikon","hedrikon","Hedrikon"}),W(
 	"Al río discurre por el norte y el este, ahora más tranquilo, después de los "+
 	"deshielos y el calor del verano.\n"));
 	AddDetail(({"arroz","planta de arroz"}),W(
 	"Las plantas del arroz están ya en su punto, y ya están siendo recogidas, "+
 	"ha sido una buena cosecha.\n"));
 	SetIntSmell(W(
 	"El olor a tierra mojada invade el ambiente.\n"));
 	SetIntNoise(W(
 	"Oyes el trinar de algún pájaro no muy lejos.\n"));
 }
 /******************************   OTOÑO   ******************************/
 if (CHRONOS->QueryEstacion()==4)
 {
 	SetIntLong(W(
 	"Te encuentras en uno de los arrozales a las afueras de Koek. "+
 	"Después de la cosecha los agricultores se han dedicado a quemar "+
 	"los rastrojos que quedaban, y sólo ves cenizas por todas partes. "+
 	"Aún queda algo de humo en el ambiente, incluso dirías que hay "+
 	"zonas ardiendo en este momento.\n"));
 	AddDetail(({"tierra","suelo"}),W(
 	"La tierra de esta zona es algo rojiza y muy fértil gracias a su proximidad "+
 	"con el río Hedrikon.\n"));
 	AddDetail(({"río","río","río hedrikon","río hedrikon","río hedrikon","río Hedrikon","hedrikon","Hedrikon"}),W(
 	"Observas el río Hedrikon, al norte y al este, que proporciona gran riqueza a las "+
 	"tierras del lugar.\n"));
 	AddDetail(({"rastrojo","rastrojos","ceniza","cenizas"}),W(
 	"Hay restos de rastrojos y cenizas humeantes por todo el suelo.\n"));
 	AddDetail(({"humo"}),W(
 	"Aún queda humo en el ambiente de la quema de los rastrojos.\n"));
 	SetIntSmell(W(
 	"Huele a hierba quemada.\n"));
 	SetIntNoise(W(
 	"Oyes el sonido del viento que empieza a soplar con algo de fuerza.\n"));
 }
}
