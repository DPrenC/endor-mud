/****************************************************************************
Fichero: tabernero_cored.c
Autor: Buh
Fecha: 26/08/2006
Descripci�n: el tabernero bandido de la taberna de cored.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>
inherit NPC;

create()
{
    ::create();

    SetStandard("furelt", "humano", ([GC_LUCHADOR:25]), GENDER_MALE);
    SetShort("furelt el tabernero");
    SetLong("Furelt es el tabernero de esta taberna de maleantes, contrabandistas y "
        "bandidos de la fortaleza.\n  Por su ocupaci�n, y a pesar de la protecci�n del mism�simo "
        "Cored, le es imprescindible tener una fuerza f�sica y un mal car�cter "
        "considerable.\n Se mont� este negocio tras sufrir una importante lesi�n en "
        "la espalda en uno de sus multiples asaltos a diligencias, que tan frecuentemente "
        "perpetraba.\n");
    AddId(({"tabernero", "bandido", "furelt"}));
    SetWeight(72000);
    Set(P_CANT_LURE,1);
    SetSmell("Un olor de no haber pasado en semanas por agua sale de sus poros.\n");
    InitAChats(9, ({"Furelt grita: �No saldr�s vivo de aqu�!.\n",
    "furelt grita: �Cored, socorro!.\n",
    "El tabernero dice: si no estuviera lesionado te ibas a enterar.\n"}));
    InitChats(1, ({"Furelt te dice: �le sirvo algo?.\n",
        "El tabernero alza la voz y dice: �a ver si vamos consumiendo, que no me alimento del aire!.\n",
        "El tabernero limpia un vaso.\n",
        "el tabernero parece poner cara de pocos amigos.\n",
        "El tabernero te mira esperando que le pidas algo.\n"}));
    AddQuestion("taberna", "El tabernero te dice: es mi taberna y estar� aqu� mientras "
        "ocupemos la fortaleza.\n", 1);
    AddQuestion("tamara", "Furelt te dice: umm, esa debe de ser esa chica tan hermosa "
        "que hay en la tienda y pertenece a Cored, pero no conozco nada de ella.\n", 1);
}
