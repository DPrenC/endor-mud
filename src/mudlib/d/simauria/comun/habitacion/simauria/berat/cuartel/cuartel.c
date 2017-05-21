/****************************************************************************
Fichero: cuartel.c
Autor: Dharkus
Fecha: 23/03/2010
Descripción: Un cuartel para la guardia en Berat
****************************************************************************/

#include "./path.h"
#include <door.h>
#include <properties.h>
inherit ROOM;

create()
{
    ::create();
    SetLocate("Berat");
    SetIntShort("el cuartel de la guardia de Berat");
    SetIntLong("Este es el cuartel de la guardia de Berat.\n Es una habitación "
    "reducida con un mostrador, donde se atienden las demandas o denuncias de los "
    "lugareños. Hay un gran armario al lado de la entrada, y al este, puedes ver el "
    "rellano que conduce a las escaleras que suben al piso superior.\n");
    AddDetail("armario", "es un robusto armario de madera, donde la guardia guarda "
    "todo el papeleo de las distintas gestiones que realizan.\n");
    AddDetail("mostrador", "Se trata de un tablero de madera con cuatro troncos; uno "
    "en cada esquina del mismo, donde los guardianes atienden las peticiones y "
    "gestionan las necesidades de los marinos y ciudadanos de Berat.\n");
    AddDetail(({"pared","paredes"}), "En las paredes puedes observar cartas de "
    "navegación y un gran mapa de Berat y su enclave costero.\n");
    SetIntNoise("Puedes escuchar el trasiego de los guardias deambulando por el "
    "edificio.\n");
    SetIntSmell("No hueles nada especial: sólo de vez en cuando te llega el perfume "
    "del mar.\n");
    SetIntBright(30);
    AddExit("oeste",SIMA( "berat/cprin8"));
    AddExit("este", "./rellano1");
    AddDoor("oeste", "Una gran puerta doble",
    "Es la puerta de salida a la calle principal.\n Consiste en dos grandes alas de roble "
    "oscuro y viejo.\n",({"puerta","puerta doble","puerta oeste","puerta del oeste"}));
    AddItem(PNJ("simauria/berat/guardia"),REFRESH_DESTRUCT,d2());
    AddItem(PNJ("simauria/berat/guardia_anciano"),REFRESH_DESTRUCT);
}
