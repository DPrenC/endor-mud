/***************************************************************************************
 ARCHIVO:	camino_00.c
 AUTOR:		[z] Zomax
 FECHA:		24-12-2001	�Feliz Nochebuena!
 COMENTARIOS:	Camino que lleva a la granja
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO

string fcamino()
{
	return TO->QueryIntLong();
}

int fcoger(string str)
{
	/******************************  INVIERNO ******************************/
	if (CHRONOS->QueryEstacion()==1)
	{
		if (str=="nieve")
		{
			write(W("Coges algo de nieve con las manos, pero de "
				"repente notas como si mil cuchillos se te "
				"clavaran en ellas y la sueltas enseguida, "
				"con el fr�o que hace no deber�as hacer esas "
				"cosas.\n"));
			say(W(CATP+" coge algo de nieve con las manos, pero "
				"pone un cara de espanto y dolor y tira todo "
				"otra vez al suelo, quiz�s sea porque hace "
				"demasiado fr�o como para ir cogiendo nieve "
				"por aqu�.\n"),TP);
			return 1;
		}
	}
	/******************************  PRIMAVERA ******************************/
	if (CHRONOS->QueryEstacion()==2)
 	{
 		if (str=="hierba" || str=="hierbas" || str=="peque�a hierba" || str=="peque�as hierbas")
 		{
 			write(W("Son hierbas sin ning�n tipo de valor, as� que "
 				"no te molestas en cogerlas.\n"));
 			say(W(CATP+" se dispone a coger una hierba, pero al ver "
 				"que no tienen m�s valor que una piedra desiste.\n"),TP);
 			return 1;
 		}
 	}
return 0;
}

int fcavar(string str)
{
	/******************************  INVIERNO ******************************/
	if (CHRONOS->QueryEstacion()==1)
	{
		write(W("Te pones a cavar en la nieve y nada m�s hacer el "
			"primer movimiento tus manos se enrrojecen del fr�o "
			"y se te quedan paralizadas, como congeladas. En ese "
			"momento decides parar y dejar todo como est�.\n"));
		say(W(CATP+" se pone a cavar en la nieve, pero nada m�s "
			"empezar se le paralizan las manos, ahora todas "
			"rojas del fr�o, y decide no seguir.\n"),TP);
		return 1;
	}
	/******************************   DEM�S   ******************************/
	else
	{
		write(W("Haces un primer impulso para ponerte a cavar, pero "
			"la verdad es que no tienes ni tiempo ni ganas, y no "
			"quieres estropear nada.\n"));
		say(W(CATP+" hace un primer impulso de ponerse a cavar, pero "
			"se lo piensa mejor y lo deja, no sea cosa que estropee "
			"algo.\n"),TP);
		return 1;
	}
return 0;
}

create () {
 ::create();

 SetIndoors(0);
 SetLocate("Koek");
 SetIntShort("un camino");
 carcel=(RHOEHAB("koek/granja/camino_01"));
 AddRoomCmd("matar","fmatar");
 AddRoomCmd("robar","frobar");
 AddRoomCmd("confesar","fconfesar");
 AddRoomCmd("entregarse","fentregarse");
 AddRoomCmd("coger","fcoger");
 AddRoomCmd("cavar","fcavar");
 AddExit("norte",RHOEHAB("koek/granja/granja"));
 AddExit("sur",RHOEHAB("koek/granja/camino_01"));
 AddExit("este",RHOEHAB("koek/granja/gallinero"));
 AddExit("oeste",RHOEHAB("koek/granja/cuadra"));
 AddDetail(({"camino"}),SF(fcamino));
 AddDetail(({"porche"}),"Parece un lugar tranquilo para descansar en verano.\n");
 SetIntLong(W("Est�s en el camino que lleva a la granja. Al norte "
 	"puedes ver la casa del granjero, con su porche de madera "
 	"pintado de blanco. Al sur el camino sigue hacia la calle "
 	"Folker m�s all�. Al este puedes ver el gallinero, y al "
 	"oeste las cuadras.\n"));
 /******************************  INVIERNO ******************************/
 if (CHRONOS->QueryEstacion()==1)
 {
 	AddDetail(({"nieve"}),W("Debido a las grandes nevadas del invierno, "
 		"todo el lugar est� te�ido de blanco por la nieve. No ha "
 		"quedado nada al descubierto. Puedes ver algunas huellas en "
 		"la nieve.\n"));
 	AddDetail(({"tierra","suelo"}),W("Supones que debe estar ah�, pero "
 		"lo cierto es que con tanta nieve no ves nada de eso.\n"));
 	AddDetail(({"huella","huellas"}),W("Hay varias huellas en la nieve. "
 		"De personas, animales...\n"));
 	SetIntSmell("Tienes la nariz tan fr�a que no hueles nada.\n");
 	SetIntNoise("Oyes los silbidos del aire g�lido al chocar con tus orejas.\n");
 }
 /****************************** PRIMAVERA ******************************/
 if (CHRONOS->QueryEstacion()==2)
 {
 	AddDetail(({"nieve"}),W("Pr�cticamente ya no hay nieve, salvo en "
 		"algunas zonas muy escondidas y peque�as donde no llega el "
 		"sol, pero la mayor parte ya se ha derretido.\n"));
 	AddDetail(({"tierra","suelo"}),W("La tierra de esta zona es algo "
 		"rojiza y muy f�rtil gracias a su proximidad con el r�o Hedrikon.\n"));
 	AddDetail(({"hierba","hierbas","peque�a hierba","peque�as hierbas"}),W(
 		"Algunas hierbas salvajes crecen a los lados del camino.\n"));
 	SetIntSmell("El olor a tierra mojada invade el ambiente.\n");
 	SetIntNoise("Apenas oyes el sonido del viento acariciando cuanto toca.\n");
 }
 /******************************   VERANO  ******************************/
 if (CHRONOS->QueryEstacion()==3)
 {
 	AddDetail(({"tierra","suelo"}),W("La tierra de esta zona es algo rojiza "
 		"y muy f�rtil gracias a su proximidad con el r�o Hedrikon.\n"));
 	AddDetail(({"hierba","hierbas","peque�a hierba","peque�as hierbas"}),W(
 		"Algunas hierbas salvajes crecen a los lados del camino.\n"));
 	SetIntSmell("El olor a tierra mojada invade el ambiente.\n");
 	SetIntNoise("Oyes el trinar de alg�n p�jaro no muy lejos.\n");
 }
 /******************************   OTO�O   ******************************/
 if (CHRONOS->QueryEstacion()==4)
 {
 	AddDetail(({"tierra","suelo"}),W("La tierra de esta zona es algo "
 		"rojiza y muy f�rtil gracias a su proximidad con el r�o "
 		"Hedrikon.\n"));
 	AddDetail(({"hierba","hierbas","peque�a hierba","peque�as hierbas"}),W(
 		"Algunas hierbas salvajes crecen a los lados del camino.\n"));
 	SetIntSmell("El olor a tierra mojada invade el ambiente.\n");
 	SetIntNoise(W("Oyes el sonido del viento que empieza a soplar con "
 		"algo de fuerza.\n"));
 }
}

int QueryEntrarPatrullero()
{
	return 1;
}

int QueryEntrarGato()
{
	return 1;
}
