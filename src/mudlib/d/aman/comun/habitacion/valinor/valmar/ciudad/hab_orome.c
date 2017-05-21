/*
Fichero: orome.c
Autor: Aul�
Fecha: 15/10/2012
Descripci�n: workroom de Orom�
*/
#include "./path.h"
inherit STD_VALINOR("hab_valinor");
create()
{
    ::create();
    	SetLocate("Valmar");
    SetIntShort("las estancias de Orom�");
    SetIntLong("Te encuentras en un inmenso sal�n que simula el umbr�o interior de "
    "un bosque antiguo.\n"
     "Los enormes pilares cil�ndricos simulan a�osos troncos de intrincada corteza cuyas "
     "poderosas ramas p�treas sostienen el techo abovedado. Este simula en todo "
     "momento el cielo exterior, sea mostrando las esplendorosas estrellas en las "
     "magn�ficas noches de Valinor o el Sol de d�a.\n"
     "Bajo esta cubierta cincelada, el suelo est� tapizado por espesa hojarasca y un "
     "humus negro y f�rtil, al que poca luz llega filtrada entre las hojas y ramas de "
     "los gigantes arb�reos.\n"
     "Estas son las estancias de Orom�, el vala Cazador, que ama por encima de todo los "
     "enormes bosques v�rgenes y las bestias que los habitan.\n"
     "Cuando Orom� habita en Valmar, ocupa este gran sal�n donde ofrece banquetes a sus "
     "seguidores y a cualquier vala, maia o elfo que quiera asistir.\n");
     AddDetail(({"arboles", "�rboles", "enormes", "troncos"}),
     "No aciertas a discernir el g�nero de estos gigantes arb�reos ni si est�n hechos de "
     "madera viva o piedra magn�ficamente cincelada.\n");
     AddDetail(({"enramado", "ramas", "ramaje"}),
     "Las intrincadas ramas se entretejen sosteniendo la b�veda del sal�n.\n");
     SetIntBright(20);
     SetIntSmell("Huele a madera h�meda, humus y hojas muertas.\n");
     SetIntNoise("Crees o�r el leve susurrar secreto de las ramas movidas por una brisa intangible.\n");
     //AddExit("trans", "./trans_endor");
     AddExit("norte", "./gavenida3");

     }
     public void init()
     {
        ::init();
                play_music(TO,"music/01");
            write("Te internas entre los grandes �rboles de las estancias de Orom�.\n");
	}
