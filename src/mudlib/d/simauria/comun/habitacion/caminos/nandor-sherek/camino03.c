/*
Archivo        /d/simauria/comun/habitacion/caminos/nandor-sherek/camino03.c
Autor:         Yalin y Lug
Fecha:         30/04/2006
Descripci�n:   Camino de Nandor a Sherek.
*/

#include "path.h"
inherit ABDCAM;

create ()
{
    object portal;
    ::create();
    SetIntLong("Caminas por una senda que transcurre entre los �rboles "
        "comunicando el bosque de Marhalt con la abad�a de Sherek. A trav�s de "
        "los �rboles, hacia el norte puedes ver un alto muro con unas grandes puertas "
        "como aparente entrada. A lo lejos, se aprecia una peque�a ermita. Detr�s "
        "del muro ves unos altos cipreses y entre las rejas de las puertas puedes "
        "distinguir algunas l�pidas, lo cual parece indicar que se trata de un "
        "cementerio. Tanto al este como al oeste contin�a el camino, mientras que el "
        "bosque se extiende hacia el sur.\n");
    AddDetail(({"bosque"}),"Al sur del camino se extiende un bosque joven de robles y encinas.\n");
    AddDetail(({"cipreses","cipres","cipr�s"}),"Son unos �rboles altos y frondosos, parecen "
        "ser bastante antiguos.\n");
    AddDetail(({"muralla", "murallas", "tapia","muro"}),"Es un alto muro de piedra. No vas a "
        "poder saltarlo.\n");
    AddDetail(({"ermita","iglesia"}), "Parece bastante antigua y ruinosa.\n");
    AddDetail(({"lapidas","lapida","l�pidas","l�pida","cementerio"}),
        "Desde aqu� no lo puedes ver bien, tendr�s que entrar dentro del cementerio "
        "para verlo en su totalidad y apreciar los detalles.\n");
    AddExit("oeste", CNSH("camino02"));
    AddExit("este", CNSH("camino04"));
    AddExit("norte","caminoc");
    AddExit("sureste", MARH("nandor/bosque/bosque003"));
    Bichejo();
    portal=clone_object("obj/monolito");
    portal->SetRaza("logath");
    portal->move(TO);
}
