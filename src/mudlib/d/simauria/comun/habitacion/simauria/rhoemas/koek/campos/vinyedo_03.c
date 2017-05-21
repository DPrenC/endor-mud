/***************************************************************************************
 ARCHIVO:	viñedo_03.c
 AUTOR:		[z] Zomax
 FECHA:		01-11-2001
 COMENTARIOS:	Viñedo nº 03, en Koek.
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
			"enseguida, con el frío que hace no deberías hacer esas cosas.\n"));
			say(W(CATP+" coge algo de nieve con las manos, pero pone un cara "
			"de espanto y dolor y tira todo otra vez al suelo, quizás sea porque "
			"hace demasiado frío como para ir cogiendo nieve por aquí.\n"),TP);
			return 1;
		}
		if ((str=="cepa") || (str=="cepas") || (str=="viña") || (str=="viñas") || (str=="vinya") || (str=="vinyas"))
		{
			write(W("Todas las cepas están demasiado enterradas en la nieve como "
			"para coger ninguna, además seguro que están firmemente cogidas al "
			"suelo. Y desde luego no te vas a poner a cavar en la nieve.\n"));
			say(W(CATP+" intenta coger una cepa, pero está demasiado cogida "
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
		if ((str=="cepa") || (str=="cepas") || (str=="viña") || (str=="viñas") || (str=="vinya") || (str=="vinyas"))
		{
			write(W("Todas las cepas están demasiado firmemente cogidas al "
			"suelo. Es imposible que puedas coger una.\n"));
			say(W(CATP+" intenta coger una cepa, pero está demasiado cogida "
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
			"das cuenta de que si no coges nada habrá más materia prima "
			"para elaborar el vino que tanto te gusta, así que decides "
			"esperar.\n"));
			say(W(CATP+" se dispone a coger algo de uva, pero de repente "
			"se para y decide no hacerlo. Sus razones tendrá.\n"),TP);
			return 1;
		}
		if ((str=="cepa") || (str=="cepas") || (str=="viña") || (str=="viñas") || (str=="vinya") || (str=="vinyas"))
		{
			write(W("Todas las cepas están demasiado firmemente cogidas al "
			"suelo. Es imposible que puedas coger una.\n"));
			say(W(CATP+" intenta coger una cepa, pero está demasiado cogida "
			"al suelo y no puede.\n"),TP);
			return 1;
		}
	}
	/******************************   OTOÑO   ******************************/
	if (CHRONOS->QueryEstacion()==4)
	{
		if ((str=="uva") || (str=="uvas") || (str=="racimo") || (str=="racimos") || (str=="racimo de uva") || (str=="racimos de uva"))
		{
			write(W("Piensas en coger algo de uva, pero reflexionas y te "
			"das cuenta de que si no coges nada habrá más materia prima "
			"para elaborar el vino que tanto te gusta, así que decides "
			"esperar.\n"));
			say(W(CATP+" se dispone a coger algo de uva, pero de repente "
			"se para y decide no hacerlo. Sus razones tendrá.\n"),TP);
			return 1;
		}
		if ((str=="cepa") || (str=="cepas") || (str=="viña") || (str=="viñas") || (str=="vinya") || (str=="vinyas"))
		{
			write(W("Todas las cepas están demasiado firmemente cogidas al "
			"suelo. Es imposible que puedas coger una.\n"));
			say(W(CATP+" intenta coger una cepa, pero está demasiado cogida "
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
		write(W("Te pones a cavar en la nieve y nada más hacer el primer movimiento "
		"tus manos se enrrojecen del frío y se te quedan paralizadas, como congeladas. "
		"En ese momento decides parar y dejar todo como está.\n"));
		say(W(CATP+" se pone a cavar en la nieve, pero nada más empezar se le paralizan "
		"las manos, ahora todas rojas del frío, y decide no seguir.\n"),TP);
		return 1;
	}
	/******************************   DEMÁS   ******************************/
	else
	{
		write(W("Haces un primer impulso para ponerte a cavar, pero la verdad es que "
		"no tienes ni tiempo ni ganas, y no quieres estropear nada del viñedo.\n"));
		say(W(CATP+" hace un primer impulso de ponerse a cavar, pero se lo piensa "
		"mejor y lo deja, no sea cosa que estropee algo.\n"),TP);
		return 1;
	}
    return 0;
}

create () {
 ::create();

 SetIndoors(0);
 SetLocate("Viñedos de Koek");
 SetIntShort("un viñedo");
 AddRoomCmd("coger","fcoger");
 AddRoomCmd("cavar","fcavar");
 AddDetail(({"viñedo","vinyedo","viñedos","vinyedos"}),SF(fvinyedo));
 AddExit("norte",RHOEHAB("koek/campos/vinyedo_00"));
 AddExit("este",RHOEHAB("koek/campos/vinyedo_04"));
 AddItem(RHOEPNJ("koek/campos/ave"),REFRESH_DESTRUCT,1+random(3));
 /******************************  INVIERNO ******************************/
 if (CHRONOS->QueryEstacion()==1)
 {
 	SetIntLong(W("Estás en uno de los viñedos de Koek, a las afueras "
 		"del pueblo. Está todo nevado, y apenas puedes distinguir "
 		"las cepas al estar enterradas bajo un gran manto blanco. "
 		"Parece que el lugar está muerto, pero como cada año, tras "
 		"la nieve, en la primavera volverá ha resurgir todo. Muy al "
 		"norte puedes ver el río Hedrikon.\n"));
 	AddDetail(({"viña","viñas","cepa","cepas"}),W("Si te fijas mucho, "
 		"puedes ver alguna que otra cepa semienterrada en la nieve. "
 		"Ahora solo parece una rama de un árbol seca y muerta, pero "
 		"espera a la primavera y tendrás una bonita viña renaciendo.\n"));
 	AddDetail(({"nieve"}),W("Debido a las grandes nevadas del invierno, "
 		"todo el lugar está teñido de blanco por la nieve. No ha "
 		"quedado nada al descubierto.\n"));
 	AddDetail(({"tierra","suelo"}),W("Supones que debe estar ahí, pero "
 		"lo cierto es que con tanta nieve no ves nada de eso.\n"));
 	AddDetail(({"río","río","río hedrikon","río hedrikon","río hedrikon","río Hedrikon","hedrikon","Hedrikon"}),W(
 		"El río discurre muy por el norte, aunque ahora no es más que "
 		"una gran capa de hielo.\n"));
 	SetIntSmell("Tienes la nariz tan fría que no hueles nada.\n");
 	SetIntNoise("Oyes los silbidos del aire gélido al chocar con tus orejas.\n");
 }
 /****************************** PRIMAVERA ******************************/
 if (CHRONOS->QueryEstacion()==2)
 {
 	SetIntLong(W("Estás en uno de los viñedos de Koek, a las afueras "
 		"del pueblo. Puedes ver como la nieve del invierno ya se "
 		"ha derretido casi por completo y las cepas han empezado a "
 		"resurgir llenas de brotes verdes por todas partes que "
 		"auguran una muy buena cosecha para el otoño. Muy al norte ves "
 		"el río Hedrikon, bastante crecido.\n"));
 	AddDetail(({"viña","viñas","cepa","cepas","brotes"}),W("Ves "
 		"pequeñas ramas oscuras y retorcidas llenas de brotes verdes "
 		"que luchan por conseguir los mejores rayos de sol para seguir "
 		"creciendo.\n"));
 	AddDetail(({"nieve"}),W("Prácticamente ya no hay nieve, salvo en "
 		"algunas zonas muy escondidas y pequeñas donde no llega el "
 		"sol, pero la mayor parte ya se ha derretido.\n"));
 	AddDetail(({"tierra","suelo"}),W("La tierra de esta zona es algo "
 		"rojiza y muy fértil gracias a su proximidad con el río Hedrikon.\n"));
 	AddDetail(({"río","río","río hedrikon","río hedrikon","río hedrikon","río Hedrikon","hedrikon","Hedrikon"}),W(
 		"El río Hedrikon, que discurre muy por el norte, está ahora muy "
 		"crecido por el deshielo, inundando el arrozal.\n"));
 	SetIntSmell("El olor a tierra mojada invade el ambiente.\n");
 	SetIntNoise("Apenas oyes el sonido del viento acariciando cuanto toca.\n");
 }
 /******************************   VERANO  ******************************/
 if (CHRONOS->QueryEstacion()==3)
 {
 	SetIntLong(W("Estás en uno de los viñedos de Koek, a las afueras del "
 		"pueblo. Las viñas del lugar están repletas de hojas, con "
 		"pequeños brotes de racimos de uva en miniatura. Por la "
 		"cantidad que ves debe esperarse una buena cosecha para el "
 		"otoño. Muy por el norte discurre el río Hedrikon.\n"));
 	AddDetail(({"viña","viñas","cepa","cepas"}),W("Las viñas están "
 		"llenas de hojas verdes y tienen un aspecto inmejorable. "
 		"Además se ven muchos brotes de futuros racimos de uva aún "
 		"verdes.\n"));
 	AddDetail(({"brotes","uva","racimo","racimos","racimo de uva","racimos de uva"}),W(
 		"Los pequeños brotes de futura uva se esconden bajo las hojas "
 		"ya crecidas, para no ser presa fácil de los pájaros. Por ahora "
 		"sólo son unos minúsculos conjuntos de granitos verdes.\n"));
 	AddDetail(({"tierra","suelo"}),W("La tierra de esta zona es algo "
 		"rojiza y muy fértil gracias a su proximidad con el río Hedrikon.\n"));
 	AddDetail(({"río","río","río hedrikon","río hedrikon","río hedrikon","río Hedrikon","hedrikon","Hedrikon"}),W(
 		"Al río discurre muy por el norte, ahora más tranquilo, después "
 		"de los deshielos y el calor del verano.\n"));
 	SetIntSmell("El olor a tierra mojada invade el ambiente.\n");
 	SetIntNoise("Oyes el trinar de algún pájaro no muy lejos.\n");
 }
 /******************************   OTOÑO   ******************************/
 if (CHRONOS->QueryEstacion()==4)
 {
 	SetIntLong(W("Estás en uno de los viñedos de Koek, a las afueras "
 		"del pueblo. Al ser la época de recogida, las viñas rebosan "
 		"uva por todas partes y dan un toque de color al lugar. "
 		"Dentro de nada vendrán las nieves del invierno y cubrirán "
 		"todo de blanco, así que los agricultores aprovechan los "
 		"últimos días. El río Hedrikon discurre muy por el norte.\n"));
 	AddDetail(({"viña","viñas","cepa","cepas"}),W("Las viñas están llenas "
 		"de hojas verdes y tienen un aspecto inmejorable. Además "
 		"tienen toques de color morado, de los racimos de uva ya "
 		"maduros, por donde miras, lo cual hace presagiar una muy "
 		"buena cosecha.\n"));
 	AddDetail(({"uva","racimo","racimos","racimo de uva","racimos de uva"}),W(
 		"La uva ya crecida descansa en la viña hasta que el agricultor "
 		"se decida a recogerla, no dentro de mucho, piensas, puesto "
 		"que con el invierno todo se perderá, eso si los pájaros no "
 		"acaban antes con ella.\n"));
 	AddDetail(({"tierra","suelo"}),W("La tierra de esta zona es algo "
 		"rojiza y muy fértil gracias a su proximidad con el río "
 		"Hedrikon.\n"));
 	AddDetail(({"río","río","río hedrikon","río hedrikon","río hedrikon","río Hedrikon","hedrikon","Hedrikon"}),W(
 		"Observas el río Hedrikon, muy al norte, que proporciona gran "
 		"riqueza a las tierras del lugar.\n"));
 	SetIntSmell("El olor a tierra mojada invade el ambiente.\n");
 	SetIntNoise("Oyes el sonido del viento que empieza a soplar con algo de fuerza.\n");
 }
}
