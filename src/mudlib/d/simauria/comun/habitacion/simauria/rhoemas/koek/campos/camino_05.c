/***************************************************************************************
 ARCHIVO:	camino_05.c
 AUTOR:		[z] Zomax
 FECHA:		03-11-2001
 COMENTARIOS:	Camino de los cultivos, en Koek
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

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
				"con el frío que hace no deberías hacer esas "
				"cosas.\n"));
			say(W(CATP+" coge algo de nieve con las manos, pero "
				"pone un cara de espanto y dolor y tira todo "
				"otra vez al suelo, quizás sea porque hace "
				"demasiado frío como para ir cogiendo nieve "
				"por aquí.\n"),TP);
			return 1;
		}
	}
	/******************************  PRIMAVERA ******************************/
	if (CHRONOS->QueryEstacion()==2)
 	{
 		if (str=="hierba" || str=="hierbas" || str=="pequeña hierba" || str=="pequeñas hierbas")
 		{
 			write(W("Son hierbas sin ningún tipo de valor, así que "
 				"no te molestas en cogerlas.\n"));
 			say(W(CATP+" se dispone a coger una hierba, pero al ver "
 				"que no tienen más valor que una piedra desiste.\n"),TP);
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
		write(W("Te pones a cavar en la nieve y nada más hacer el "
			"primer movimiento tus manos se enrrojecen del frío "
			"y se te quedan paralizadas, como congeladas. En ese "
			"momento decides parar y dejar todo como está.\n"));
		say(W(CATP+" se pone a cavar en la nieve, pero nada más "
			"empezar se le paralizan las manos, ahora todas "
			"rojas del frío, y decide no seguir.\n"),TP);
		return 1;
	}
	/******************************   DEMÁS   ******************************/
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
 SetLocate("Camino de los cultivos de Koek");
 SetIntShort("un camino");
 AddRoomCmd("coger","fcoger");
 AddRoomCmd("cavar","fcavar");
 AddExit("este",RHOEHAB("koek/campos/camino_06"));
 AddExit("oeste",RHOEHAB("koek/campos/camino_04"));
 AddDetail(({"camino"}),SF(fcamino));
 AddItem(RHOEPNJ("koek/campos/ave"),REFRESH_DESTRUCT,1+random(3));
 /******************************  INVIERNO ******************************/
 if (CHRONOS->QueryEstacion()==1)
 {
 	SetIntLong(W("Estás en el camino que lleva a los campos de "
 		"cultivos de Koek, al sur del pueblo. Ahora está todo "
 		"muy nevado, y apenas distingues por donde discurre salvo "
 		"por unas huellas en la nieve. Hacia el norte lados puedes "
 		"ver campos cubiertos de nieve.\n"));
 	AddDetail(({"nieve"}),W("Debido a las grandes nevadas del invierno, "
 		"todo el lugar está teñido de blanco por la nieve. No ha "
 		"quedado nada al descubierto. Puedes ver algunas huellas en "
 		"la nieve.\n"));
 	AddDetail(({"tierra","suelo"}),W("Supones que debe estar ahí, pero "
 		"lo cierto es que con tanta nieve no ves nada de eso.\n"));
 	AddDetail(({"huella","huellas"}),W("Hay varias huellas en la nieve. "
 		"De personas, animales...\n"));
 	AddDetail(({"campo","campos"}),W("Los campos que ves al norte están "
 		"nevados en esta época del año.\n"));
 	SetIntSmell("Tienes la nariz tan fría que no hueles nada.\n");
 	SetIntNoise("Oyes los silbidos del aire gélido al chocar con tus orejas.\n");
 }
 /****************************** PRIMAVERA ******************************/
 if (CHRONOS->QueryEstacion()==2)
 {
 	SetIntLong(W("Estás en el camino que lleva a los campos de cultivos "
 		"de Koek, al sur del pueblo. La nieve ya se ha derretido casi "
 		"por completo y pequeñas hierbas empiezan a renacer dando un "
 		"toque de colorido al camino. Hacia el norte puedes ver campos que "
 		"empiezan a despertar del invierno.\n"));
 	AddDetail(({"nieve"}),W("Prácticamente ya no hay nieve, salvo en "
 		"algunas zonas muy escondidas y pequeñas donde no llega el "
 		"sol, pero la mayor parte ya se ha derretido.\n"));
 	AddDetail(({"tierra","suelo"}),W("La tierra de esta zona es algo "
 		"rojiza y muy fértil gracias a su proximidad con el río Hedrikon.\n"));
 	AddDetail(({"hierba","hierbas","pequeña hierba","pequeñas hierbas"}),W(
 		"Algunas hierbas salvajes crecen a los lados del camino.\n"));
 	AddDetail(({"campo","campos"}),"Al norte ves campos renaciendo tras el duro invierno.\n");
 	SetIntSmell("El olor a tierra mojada invade el ambiente.\n");
 	SetIntNoise("Apenas oyes el sonido del viento acariciando cuanto toca.\n");
 }
 /******************************   VERANO  ******************************/
 if (CHRONOS->QueryEstacion()==3)
 {
 	SetIntLong(W("Estás en el camino que lleva a los campos de cultivos "
 		"de Koek, al sur del pueblo. Es un camino de tierra rojiza con "
 		"varias hierbas a los lados del camino que dan un toque de "
 		"colorido. Hacia el norte puedes ver campos llenos de todo tipo "
 		"de cultivos.\n"));
 	AddDetail(({"tierra","suelo"}),W("La tierra de esta zona es algo rojiza "
 		"y muy fértil gracias a su proximidad con el río Hedrikon.\n"));
 	AddDetail(({"hierba","hierbas","pequeña hierba","pequeñas hierbas"}),W(
 		"Algunas hierbas salvajes crecen a los lados del camino.\n"));
 	AddDetail(({"campo","campos","cultivo","cultivos"}),W("Al norte ves "
 		"campos llenos de todo tipo de cultivos.\n"));
 	SetIntSmell("El olor a tierra mojada invade el ambiente.\n");
 	SetIntNoise("Oyes el trinar de algún pájaro no muy lejos.\n");
 }
 /******************************   OTOÑO   ******************************/
 if (CHRONOS->QueryEstacion()==4)
 {
 	SetIntLong(W("Estás en el camino que lleva a los campos de cultivos "
 		"de Koek, al sur del pueblo. Es un camino de tierra rojiza con "
 		"varias hierbas a los lados del camino que dan un toque de "
 		"colorido. Hacia el norte puedes ver campos de cultivo.\n"));
 	AddDetail(({"tierra","suelo"}),W("La tierra de esta zona es algo "
 		"rojiza y muy fértil gracias a su proximidad con el río "
 		"Hedrikon.\n"));
 	AddDetail(({"hierba","hierbas","pequeña hierba","pequeñas hierbas"}),W(
 		"Algunas hierbas salvajes crecen a los lados del camino.\n"));
 	AddDetail(({"campo","campos","cultivo","cultivos","campo de cultivo","campos de cultivo"}),W(
 		"Al norte ves campos llenos de todo tipo de cultivos.\n"));
 	SetIntSmell("El olor a tierra mojada invade el ambiente.\n");
 	SetIntNoise(W("Oyes el sonido del viento que empieza a soplar con "
 		"algo de fuerza.\n"));
 }
}
