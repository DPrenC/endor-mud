/*
Fichero: antepuertao.c
Autor: aul�
Fecha: 12/03/2013
Descripci�n: Lugar ante la puerta oeste de Bree.
*/
#include "./path.h"
inherit HABITACION+"caminos/base_camino";
create()
{
    ::create();
    	SetIntShort("ante las puertas de Bree");
    	SetIntLong(
    	"El camino procedente de la encrucijada situada algo m�s al oeste termina aqu�, "
    	"ante una s�lida puerta de trancas que cierra el camino. A ambos lados se extiende "
    	"una empalizada reforzada por un espeso seto que defiende la aldea de Bree de "
    	"amenazas exteriores. El camino cruza en este punto un foso que rodea, a su vez, "
    	"la empalizada. M�s all� de esta distingues las primeras casas de la aldea y "
    	"arriba, en las laderas m�s empinadas, los agujeros de los hobbits que habitan en "
    	"la poblaci�n.\n");
    AddExit("oeste", "./camino_e3");
     AddExit("este", HABITACION+"bree/traspuertao");
          AddDoor("este", "una robusta puerta de trancas",
     "Es una robusta puerta de unos dos metros de altura constituida por gruesas "
     "trancas de madera reforzadas con herrajes y con la punta aguzada.\n"
     "Varios pesados cerrojos y pestillos la aseguran y posee un par de ventanucos "
     "a la altura de un Hobbit y de un Hombre respectivamente para examinar el "
     "exterior e identificar a quien llame tras la puesta de sol.\n",
     ({"puerta", "trancas", "puerta de trancas", "e", "este"}));
     

    }