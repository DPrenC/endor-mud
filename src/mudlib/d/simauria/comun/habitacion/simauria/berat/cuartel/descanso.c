/****************************************************************************
Fichero: descanso.c
Autor: Dharkus
Fecha: 20/04/2010
Descripción: Una sala de descanso para el cuartel de Berat.
****************************************************************************/


#include "./path.h"
#include <properties.h>
inherit ROOM;

create()
{
    ::create();
    SetLocate("Berat");
    SetIntShort("la sala de descanso");
    SetIntLong("Esta es la sala de descanso del cuartel de Berat.\n Se trata de "
    "una habitación cuadrada con una mesita central y rodeándola, se sitúan unos "
    "cojines donde los guardianes se recuestan y descansan de sus largas horas "
    "de guardia.\n Al oeste está la puerta que da al rellano donde se comunican las "
    "escaleras y el despacho del capitán de la guardia.\n");
    AddDetail(({"mesa","mesita","mesilla"}),"Se trata de una larga mesa de madera "
    "alrededor de la cual, se disponen los cojines donde los guardianes descansan.\n");
    AddDetail(({"cojin","cojín","cojines"}),"Estos son unos grandes almuadones de "
    "tela rellenos de plumas, que facilitan el descanso o relax de los hombres "
    "de la ley en Berat.\n");
    SetIntNoise("Escuchas a los guardianes departir animadamente, y algún que otro "
    "ronquido de vez en cuando.\n");
    SetIntSmell("No aprecias ningún olor especial.\n");
    SetIntBright(25);
    AddItem(PNJ("simauria/berat/guardia02"),REFRESH_DESTRUCT,d3());
    AddItem(PNJ("simauria/berat/sanbernardo"),REFRESH_DESTRUCT);
    AddExit("oeste", "./rellano2");
    AddDoor("oeste", "la puerta del rellano", "Es la puerta que separa la sala de "
    "descanso con el rellano.\n", ({"puerta del rellano", "puerta oeste",
    "puerta del oeste", "puerta"}));
}
