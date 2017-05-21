/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/casas/huerto.c
Autor: Lug y Yalin
Fecha: 14/01/2007
Descripción: Base para los huertos de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("abroom");


create()
{
    ::create();
    SetIntShort("un pequeño huerto");
    SetIntLong("Estás sobre un pequeño huerto de forma cuadrangular entre "
        "las casas de la aldea de Sloch. Observas cultivados aquí distintos "
        "tipos de plantas destinadas al abastecimiento de los habitantes de "
        "la aldea.\n");
    SetIntNoise("Escuchas pájaros cantando y zumbidos de insectos.\n");
    SetIntSmell("La fragancia de las plantas cultivadas llega hasta ti.\n");
    AddDetail(({"suelo","tierra","surcos"}), "Cruzan el huerto unos cuantos "
        "surcos cultivados con diferentes plantas y hierbas.\n");
    AddDetail(({"plantas","planta","vegetales","tubérculos","legumbres"}),
        "Se trata de una buena variedad de vegetales, tubérculos y legumbres "
        "para consumir en la cocina.\n");
    AddDetail(({"hierba","hierbas"}), "Son algunas hierbas para aromatizar y "
        "realzar el sabor de los alimentos.\n");
    AddDetail(({"ventana"}), "Por ella se puede ver el interior de la casa.\n");
    AddDetail(({"interior","interior de la casa"}), "¡No está nada bien espiar "
        "por la ventana! Quizás fuese mejor que pidas permiso y entres por "
        "la puerta para curiosear.\n");
    AddItem(PNJ("sherek/aldea/aldeanoh"), REFRESH_DESTRUCT,1);
}


