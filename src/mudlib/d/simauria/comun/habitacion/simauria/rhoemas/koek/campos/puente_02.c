/***************************************************************************************
 ARCHIVO:	puente_02.c
 AUTOR:		[z] Zomax
 FECHA:		17-12-2001
 COMENTARIOS:	Tramo 02 del puente que lleva a los cultivos, en Koek
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

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
    return 0;
}

create () {
 ::create();

 SetIndoors(0);
 SetLocate("Cultivos de Koek");
 SetIntShort("un puente");
 AddRoomCmd("coger","fcoger");
 AddRoomCmd("cavar","fcavar");
 AddExit("norte",RHOEHAB("koek/campos/puente_01"));
 AddExit("sur",RHOEHAB("koek/campos/camino_00"));
 AddDetail(({"puente"}),W("Es un puente de piedra muy robusto que se alza sobre "
 	"el r�o Hedrikon. Parece bastante transitado, seg�n se ve por el desgaste "
 	"que tiene, sobre todo en �poca de recolecci�n.\n"));
 /******************************  INVIERNO ******************************/
 if (CHRONOS->QueryEstacion()==1)
 {
 	SetIntLong(W("Est�s en el final del puente que lleva a los campos "
 		"de cultivo, al sur de Koek. Por debajo del puente pasa el r�o "
 		"Hedrikon, ahora helado. Hacia el norte regresas a Koek.\n"));
 	AddDetail(({"nieve"}),W("Debido a las grandes nevadas del invierno, "
 		"todo el lugar est� te�ido de blanco por la nieve. No ha "
 		"quedado nada al descubierto.\n"));
 	AddDetail(({"suelo"}),W("Supones que debe estar ah�, pero lo cierto "
 		"es que con tanta nieve no ves nada de eso.\n"));
 	AddDetail(({"r�o","r�o","r�o hedrikon","r�o hedrikon","r�o hedrikon","r�o Hedrikon","hedrikon","Hedrikon"}),W(
 		"El r�o discurre por el norte, aunque ahora no es m�s que una "
 		"gran capa de hielo.\n"));
 	SetIntSmell("Tienes la nariz tan fr�a que no hueles nada.\n");
 	SetIntNoise("Oyes los silbidos del aire g�lido al chocar con tus orejas.\n");
 }
 /****************************** PRIMAVERA ******************************/
 if (CHRONOS->QueryEstacion()==2)
 {
 	SetIntLong(W("Est�s en el final del puente que lleva a los campos "
 		"de cultivo, al sur de Koek. Por debajo del puente pasa el r�o "
 		"Hedrikon, muy crecido por el deshielo. Hacia el norte regresas a Koek.\n"));
 	AddDetail(({"nieve"}),W("Pr�cticamente ya no hay nieve, salvo en algunas "
 		"zonas muy escondidas y peque�as donde no llega el sol, pero la "
 		"mayor parte ya se ha derretido.\n"));
 	AddDetail(({"suelo"}),W("Es un suelo empedrado, para que no se desgaste "
 		"con el paso de los carruajes.\n"));
 	AddDetail(({"r�o","r�o","r�o hedrikon","r�o hedrikon","r�o hedrikon","r�o Hedrikon","hedrikon","Hedrikon"}),W(
 		"El r�o discurre bajo el puente. En este momento est� muy crecido "
 		"gracias al deshielo de las nieves del invierno.\n"));
 	SetIntSmell("El olor a tierra mojada invade el ambiente.\n");
 	SetIntNoise(W("Apenas oyes el sonido del viento acariciando cuanto toca y "
 		"el murmullo del agua al pasar.\n"));
 }
 /******************************   VERANO  ******************************/
 if (CHRONOS->QueryEstacion()==3)
 {
 	SetIntLong(W("Est�s en el final del puente que lleva a los campos "
 		"de cultivo, al sur de Koek. Por debajo del puente pasa el r�o "
 		"Hedrikon. Hacia el norte regresas a Koek.\n"));
 	AddDetail(({"suelo"}),W("Es un suelo empedrado, para que no se desgaste "
 		"con el paso de los carruajes.\n"));
 	AddDetail(({"r�o","r�o","r�o hedrikon","r�o hedrikon","r�o hedrikon","r�o Hedrikon","hedrikon","Hedrikon"}),W(
 		"Al r�o discurre por el norte, ahora m�s tranquilo, despu�s de "
 		"los deshielos y el calor del verano.\n"));
 	SetIntSmell("El olor a tierra mojada invade el ambiente.\n");
 	SetIntNoise("S�lo oyes el ruido del agua al pasar bajo el puente.\n");
 }
 /******************************   OTO�O   ******************************/
 if (CHRONOS->QueryEstacion()==4)
 {
 	SetIntLong(W("Est�s en el final del puente que lleva a los campos "
 		"de cultivo, al sur de Koek. Por debajo del puente pasa el r�o "
 		"Hedrikon. Hacia el norte regresas a Koek.\n"));
 	AddDetail(({"suelo"}),W("Es un suelo empedrado, para que no se desgaste "
 		"con el paso de los carruajes.\n"));
 	AddDetail(({"r�o","r�o","r�o hedrikon","r�o hedrikon","r�o hedrikon","r�o Hedrikon","hedrikon","Hedrikon"}),W(
 		"Miras l r�o Hedrikon, que pasa por debajo del puente. Est� algo "
 		"crecido por las lluvias\n"));
 	SetIntSmell("El olor a tierra mojada invade el ambiente.\n");
 	SetIntNoise(W("Oyes el sonido del viento que empieza a soplar con algo "
 		"de fuerza y el agua que pasa embravecida bajo el puente.\n"));
 }
}
