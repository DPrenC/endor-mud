/*
Fichero: orome.c
Autor: Aulë
Fecha: 15/10/2012
Descripción: workroom de Oromë
*/
#include "./path.h"
inherit STD_VALINOR("hab_valinor");
create()
{
    ::create();
    	SetLocate("Valmar");
    SetIntShort("las estancias de Oromë");
    SetIntLong("Te encuentras en un inmenso salón que simula el umbrío interior de "
    "un bosque antiguo.\n"
     "Los enormes pilares cilíndricos simulan añosos troncos de intrincada corteza cuyas "
     "poderosas ramas pétreas sostienen el techo abovedado. Este simula en todo "
     "momento el cielo exterior, sea mostrando las esplendorosas estrellas en las "
     "magníficas noches de Valinor o el Sol de día.\n"
     "Bajo esta cubierta cincelada, el suelo está tapizado por espesa hojarasca y un "
     "humus negro y fértil, al que poca luz llega filtrada entre las hojas y ramas de "
     "los gigantes arbóreos.\n"
     "Estas son las estancias de Oromë, el vala Cazador, que ama por encima de todo los "
     "enormes bosques vírgenes y las bestias que los habitan.\n"
     "Cuando Oromë habita en Valmar, ocupa este gran salón donde ofrece banquetes a sus "
     "seguidores y a cualquier vala, maia o elfo que quiera asistir.\n");
     AddDetail(({"arboles", "árboles", "enormes", "troncos"}),
     "No aciertas a discernir el género de estos gigantes arbóreos ni si están hechos de "
     "madera viva o piedra magníficamente cincelada.\n");
     AddDetail(({"enramado", "ramas", "ramaje"}),
     "Las intrincadas ramas se entretejen sosteniendo la bóveda del salón.\n");
     SetIntBright(20);
     SetIntSmell("Huele a madera húmeda, humus y hojas muertas.\n");
     SetIntNoise("Crees oír el leve susurrar secreto de las ramas movidas por una brisa intangible.\n");
     //AddExit("trans", "./trans_endor");
     AddExit("norte", "./gavenida3");

     }
     public void init()
     {
        ::init();
                play_music(TO,"music/01");
            write("Te internas entre los grandes árboles de las estancias de Oromë.\n");
	}
