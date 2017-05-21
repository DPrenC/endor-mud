/***************************************************************************************
 ARCHIVO:	vi�edo_03.c
 AUTOR:		[z] Zomax
 FECHA:		01-11-2001
 COMENTARIOS:	Vi�edo n� 03, en Koek.
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

string fvinyedo()
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
			write(W("Coges algo de nieve con las manos, pero de repente "
			"notas como si mil cuchillos se te clavaran en ellas y la sueltas "
			"enseguida, con el fr�o que hace no deber�as hacer esas cosas.\n"));
			say(W(CATP+" coge algo de nieve con las manos, pero pone un cara "
			"de espanto y dolor y tira todo otra vez al suelo, quiz�s sea porque "
			"hace demasiado fr�o como para ir cogiendo nieve por aqu�.\n"),TP);
			return 1;
		}
		if ((str=="cepa") || (str=="cepas") || (str=="vi�a") || (str=="vi�as") || (str=="vinya") || (str=="vinyas"))
		{
			write(W("Todas las cepas est�n demasiado enterradas en la nieve como "
			"para coger ninguna, adem�s seguro que est�n firmemente cogidas al "
			"suelo. Y desde luego no te vas a poner a cavar en la nieve.\n"));
			say(W(CATP+" intenta coger una cepa, pero est� demasiado cogida "
			"al suelo y no puede.\n"),TP);
			return 1;
		}
	}
	/****************************** PRIMAVERA ******************************/
	if (CHRONOS->QueryEstacion()==2)
	{
		if (str=="nieve")
		{
			write(W("Coges algo de la poca nieve que queda con las manos, "
			"pero antes de que te des cuenta se ha derretido del calor.\n"));
			say(W(CATP+" coge algo de nieve con las manos, pero apenas "
			"la toca se derrite del calor.\n"),TP);
			return 1;
		}
		if ((str=="cepa") || (str=="cepas") || (str=="vi�a") || (str=="vi�as") || (str=="vinya") || (str=="vinyas"))
		{
			write(W("Todas las cepas est�n demasiado firmemente cogidas al "
			"suelo. Es imposible que puedas coger una.\n"));
			say(W(CATP+" intenta coger una cepa, pero est� demasiado cogida "
			"al suelo y no puede.\n"),TP);
			return 1;
		}
	}
	/******************************   VERANO  ******************************/
	if (CHRONOS->QueryEstacion()==3)
	{
		if ((str=="brote") || (str=="brotes") || (str=="uva") || (str=="uvas") || (str=="racimo") || (str=="racimos") || (str=="racimo de uva") || (str=="racimos de uva"))
		{
			write(W("Piensas en coger algo de uva, pero reflexionas y te "
			"das cuenta de que si no coges nada habr� m�s materia prima "
			"para elaborar el vino que tanto te gusta, as� que decides "
			"esperar.\n"));
			say(W(CATP+" se dispone a coger algo de uva, pero de repente "
			"se para y decide no hacerlo. Sus razones tendr�.\n"),TP);
			return 1;
		}
		if ((str=="cepa") || (str=="cepas") || (str=="vi�a") || (str=="vi�as") || (str=="vinya") || (str=="vinyas"))
		{
			write(W("Todas las cepas est�n demasiado firmemente cogidas al "
			"suelo. Es imposible que puedas coger una.\n"));
			say(W(CATP+" intenta coger una cepa, pero est� demasiado cogida "
			"al suelo y no puede.\n"),TP);
			return 1;
		}
	}
	/******************************   OTO�O   ******************************/
	if (CHRONOS->QueryEstacion()==4)
	{
		if ((str=="uva") || (str=="uvas") || (str=="racimo") || (str=="racimos") || (str=="racimo de uva") || (str=="racimos de uva"))
		{
			write(W("Piensas en coger algo de uva, pero reflexionas y te "
			"das cuenta de que si no coges nada habr� m�s materia prima "
			"para elaborar el vino que tanto te gusta, as� que decides "
			"esperar.\n"));
			say(W(CATP+" se dispone a coger algo de uva, pero de repente "
			"se para y decide no hacerlo. Sus razones tendr�.\n"),TP);
			return 1;
		}
		if ((str=="cepa") || (str=="cepas") || (str=="vi�a") || (str=="vi�as") || (str=="vinya") || (str=="vinyas"))
		{
			write(W("Todas las cepas est�n demasiado firmemente cogidas al "
			"suelo. Es imposible que puedas coger una.\n"));
			say(W(CATP+" intenta coger una cepa, pero est� demasiado cogida "
			"al suelo y no puede.\n"),TP);
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
		write(W("Te pones a cavar en la nieve y nada m�s hacer el primer movimiento "
		"tus manos se enrrojecen del fr�o y se te quedan paralizadas, como congeladas. "
		"En ese momento decides parar y dejar todo como est�.\n"));
		say(W(CATP+" se pone a cavar en la nieve, pero nada m�s empezar se le paralizan "
		"las manos, ahora todas rojas del fr�o, y decide no seguir.\n"),TP);
		return 1;
	}
	/******************************   DEM�S   ******************************/
	else
	{
		write(W("Haces un primer impulso para ponerte a cavar, pero la verdad es que "
		"no tienes ni tiempo ni ganas, y no quieres estropear nada del vi�edo.\n"));
		say(W(CATP+" hace un primer impulso de ponerse a cavar, pero se lo piensa "
		"mejor y lo deja, no sea cosa que estropee algo.\n"),TP);
		return 1;
	}
    return 0;
}

create () {
 ::create();

 SetIndoors(0);
 SetLocate("Vi�edos de Koek");
 SetIntShort("un vi�edo");
 AddRoomCmd("coger","fcoger");
 AddRoomCmd("cavar","fcavar");
 AddDetail(({"vi�edo","vinyedo","vi�edos","vinyedos"}),SF(fvinyedo));
 AddExit("norte",RHOEHAB("koek/campos/vinyedo_00"));
 AddExit("este",RHOEHAB("koek/campos/vinyedo_04"));
 AddItem(RHOEPNJ("koek/campos/ave"),REFRESH_DESTRUCT,1+random(3));
 /******************************  INVIERNO ******************************/
 if (CHRONOS->QueryEstacion()==1)
 {
 	SetIntLong(W("Est�s en uno de los vi�edos de Koek, a las afueras "
 		"del pueblo. Est� todo nevado, y apenas puedes distinguir "
 		"las cepas al estar enterradas bajo un gran manto blanco. "
 		"Parece que el lugar est� muerto, pero como cada a�o, tras "
 		"la nieve, en la primavera volver� ha resurgir todo. Muy al "
 		"norte puedes ver el r�o Hedrikon.\n"));
 	AddDetail(({"vi�a","vi�as","cepa","cepas"}),W("Si te fijas mucho, "
 		"puedes ver alguna que otra cepa semienterrada en la nieve. "
 		"Ahora solo parece una rama de un �rbol seca y muerta, pero "
 		"espera a la primavera y tendr�s una bonita vi�a renaciendo.\n"));
 	AddDetail(({"nieve"}),W("Debido a las grandes nevadas del invierno, "
 		"todo el lugar est� te�ido de blanco por la nieve. No ha "
 		"quedado nada al descubierto.\n"));
 	AddDetail(({"tierra","suelo"}),W("Supones que debe estar ah�, pero "
 		"lo cierto es que con tanta nieve no ves nada de eso.\n"));
 	AddDetail(({"r�o","r�o","r�o hedrikon","r�o hedrikon","r�o hedrikon","r�o Hedrikon","hedrikon","Hedrikon"}),W(
 		"El r�o discurre muy por el norte, aunque ahora no es m�s que "
 		"una gran capa de hielo.\n"));
 	SetIntSmell("Tienes la nariz tan fr�a que no hueles nada.\n");
 	SetIntNoise("Oyes los silbidos del aire g�lido al chocar con tus orejas.\n");
 }
 /****************************** PRIMAVERA ******************************/
 if (CHRONOS->QueryEstacion()==2)
 {
 	SetIntLong(W("Est�s en uno de los vi�edos de Koek, a las afueras "
 		"del pueblo. Puedes ver como la nieve del invierno ya se "
 		"ha derretido casi por completo y las cepas han empezado a "
 		"resurgir llenas de brotes verdes por todas partes que "
 		"auguran una muy buena cosecha para el oto�o. Muy al norte ves "
 		"el r�o Hedrikon, bastante crecido.\n"));
 	AddDetail(({"vi�a","vi�as","cepa","cepas","brotes"}),W("Ves "
 		"peque�as ramas oscuras y retorcidas llenas de brotes verdes "
 		"que luchan por conseguir los mejores rayos de sol para seguir "
 		"creciendo.\n"));
 	AddDetail(({"nieve"}),W("Pr�cticamente ya no hay nieve, salvo en "
 		"algunas zonas muy escondidas y peque�as donde no llega el "
 		"sol, pero la mayor parte ya se ha derretido.\n"));
 	AddDetail(({"tierra","suelo"}),W("La tierra de esta zona es algo "
 		"rojiza y muy f�rtil gracias a su proximidad con el r�o Hedrikon.\n"));
 	AddDetail(({"r�o","r�o","r�o hedrikon","r�o hedrikon","r�o hedrikon","r�o Hedrikon","hedrikon","Hedrikon"}),W(
 		"El r�o Hedrikon, que discurre muy por el norte, est� ahora muy "
 		"crecido por el deshielo, inundando el arrozal.\n"));
 	SetIntSmell("El olor a tierra mojada invade el ambiente.\n");
 	SetIntNoise("Apenas oyes el sonido del viento acariciando cuanto toca.\n");
 }
 /******************************   VERANO  ******************************/
 if (CHRONOS->QueryEstacion()==3)
 {
 	SetIntLong(W("Est�s en uno de los vi�edos de Koek, a las afueras del "
 		"pueblo. Las vi�as del lugar est�n repletas de hojas, con "
 		"peque�os brotes de racimos de uva en miniatura. Por la "
 		"cantidad que ves debe esperarse una buena cosecha para el "
 		"oto�o. Muy por el norte discurre el r�o Hedrikon.\n"));
 	AddDetail(({"vi�a","vi�as","cepa","cepas"}),W("Las vi�as est�n "
 		"llenas de hojas verdes y tienen un aspecto inmejorable. "
 		"Adem�s se ven muchos brotes de futuros racimos de uva a�n "
 		"verdes.\n"));
 	AddDetail(({"brotes","uva","racimo","racimos","racimo de uva","racimos de uva"}),W(
 		"Los peque�os brotes de futura uva se esconden bajo las hojas "
 		"ya crecidas, para no ser presa f�cil de los p�jaros. Por ahora "
 		"s�lo son unos min�sculos conjuntos de granitos verdes.\n"));
 	AddDetail(({"tierra","suelo"}),W("La tierra de esta zona es algo "
 		"rojiza y muy f�rtil gracias a su proximidad con el r�o Hedrikon.\n"));
 	AddDetail(({"r�o","r�o","r�o hedrikon","r�o hedrikon","r�o hedrikon","r�o Hedrikon","hedrikon","Hedrikon"}),W(
 		"Al r�o discurre muy por el norte, ahora m�s tranquilo, despu�s "
 		"de los deshielos y el calor del verano.\n"));
 	SetIntSmell("El olor a tierra mojada invade el ambiente.\n");
 	SetIntNoise("Oyes el trinar de alg�n p�jaro no muy lejos.\n");
 }
 /******************************   OTO�O   ******************************/
 if (CHRONOS->QueryEstacion()==4)
 {
 	SetIntLong(W("Est�s en uno de los vi�edos de Koek, a las afueras "
 		"del pueblo. Al ser la �poca de recogida, las vi�as rebosan "
 		"uva por todas partes y dan un toque de color al lugar. "
 		"Dentro de nada vendr�n las nieves del invierno y cubrir�n "
 		"todo de blanco, as� que los agricultores aprovechan los "
 		"�ltimos d�as. El r�o Hedrikon discurre muy por el norte.\n"));
 	AddDetail(({"vi�a","vi�as","cepa","cepas"}),W("Las vi�as est�n llenas "
 		"de hojas verdes y tienen un aspecto inmejorable. Adem�s "
 		"tienen toques de color morado, de los racimos de uva ya "
 		"maduros, por donde miras, lo cual hace presagiar una muy "
 		"buena cosecha.\n"));
 	AddDetail(({"uva","racimo","racimos","racimo de uva","racimos de uva"}),W(
 		"La uva ya crecida descansa en la vi�a hasta que el agricultor "
 		"se decida a recogerla, no dentro de mucho, piensas, puesto "
 		"que con el invierno todo se perder�, eso si los p�jaros no "
 		"acaban antes con ella.\n"));
 	AddDetail(({"tierra","suelo"}),W("La tierra de esta zona es algo "
 		"rojiza y muy f�rtil gracias a su proximidad con el r�o "
 		"Hedrikon.\n"));
 	AddDetail(({"r�o","r�o","r�o hedrikon","r�o hedrikon","r�o hedrikon","r�o Hedrikon","hedrikon","Hedrikon"}),W(
 		"Observas el r�o Hedrikon, muy al norte, que proporciona gran "
 		"riqueza a las tierras del lugar.\n"));
 	SetIntSmell("El olor a tierra mojada invade el ambiente.\n");
 	SetIntNoise("Oyes el sonido del viento que empieza a soplar con algo de fuerza.\n");
 }
}
