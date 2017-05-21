/****************************************************************************
Fichero: patio01.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"
#include <scheduler.h>
inherit CASTILLO("patio/patio_base");

private string DescLarga()
{
    object entrada = find_object(resolve_file("./entrada"));
    int estado;
    string msg;
    if (!entrada)
    // no está cargada, así que pillamos el estado de la hora
    {
        estado = member(
        ({ND_NIGHT, ND_PREDAWN}), QueryDayState()) >= 0 ? S_CLOSED : S_OPENED;
    }
    else
    // sí está cargada, así que lo pillamos de la entrada diréctamente
    {
        estado = entrada->QueryRoomState();
    }
    if (estado == S_CLOSED)
        msg = "El rastrillo de la entrada está bajado impidiendo la salida del castillo.\n";
        else msg = "El rastrillo de la entrada está subido dejando el paso libre para "
        "salir del castillo.\n";
    return "Al norte, las murallas se acercan entre sí hasta "
    "unirse en la gran arcada defendida por un rastrillo que forma la puerta del "
    "castillo. Esta parte del patio forma una especie de embudo que deja a cualquier "
    "invasor que entre por las puertas bajo el fuego cruzado de las murallas de "
    "alrededor. El pavimento de piedras redondeadas está gastado por el ir y venir de "
    "hombres y animales durante siglos.\n"
    "Al sur se abre el patio de armas  con los cobertizos auxiliares hacia el este, la "
    "torre del homenaje al sur, y dos estrechas escaleras al este y el oeste "
    "respectivamente que permiten a los defensores moverse con gran facilidad entre las "
    "murallas y el interior de la puerta.\n" + msg;
}

create(){
    ::create();
    SetIntLong(SF(DescLarga));

    AddDetail("cobertizos", "Una hilera de cobertizos adosados a la muralla oriental.\n");
    AddDetail("escaleras", "Dos estrechas y empinadas escaleras de piedra que ascienden "
    "a la muralla a ambos lados de la puerta.\n");
    AddDetail("arcada", "Oradada en la muralla,  las puertas del castillo la cierran  "
    "por el norte y el rastrillo por el sur.\n");
    AddDetail("rastrillo", "Una verja de hierro formada por barrotes verticales "
    "terminados en punta con tres travesaños horizontales que los conexionan: uno en "
    "la parte superior, otro en la media y otro en la inferiorr, justo antes de las "
    "puntas. El rastrillo se alza y se deja caer mediante una serie de poleas "
    "instaladas sobre la puerta. Resulta muy útil para cerrar el paso al enemigo sin "
    "perder la oportunidad de asaetearlo y hostigarlo por entre los barrotes, y debido  "
    "a su posición resguardada respecto a la puerta, resulta difícil de derribar "
    "con un ariete.\n");
    AddServerNotification("./entrada");
    AddExit("norte", "./entrada");
    AddExit("sur", "./patio05");
    AddExit("suroeste", "./patio04");
    AddExit("sudeste", "./patio06");
}


