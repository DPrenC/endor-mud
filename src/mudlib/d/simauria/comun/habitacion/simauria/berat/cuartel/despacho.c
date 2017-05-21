/****************************************************************************
Fichero: despacho.c
Autor: Dharkus
Fecha: 20/04/2010
Descripci�n: El despacho del capit�n de la guardia en Berat
****************************************************************************/


#include "./path.h"
#include <properties.h>
inherit ROOM;

create()
{
    ::create();
    SetLocate("Berat");
    SetIntShort("el despacho del capit�n de la guardia");
    SetIntLong("Este es el despacho de Pirkn, el capit�n de la guardia de Berat.\n "
    "Se trata de una peque�a habitaci�n enmoquetada, con una mesa donde el capit�n "
    "atiende los asuntos de los guardianes.\n En la pared sur puedes ver un precioso "
    "ventanal con vistas al puerto.\n");
    AddDetail("moqueta", "se trata de una gran alfombra tejida con las mejores "
    "telas �lficas.\n Est� toda hecha a mano, y cubre la casi totalidad de la "
    "estancia.\n");
    AddDetail(({"ventanal","ventana"}),"Es un precioso ventanal que ocupa toda "
    "la pared sur.\n");
    SetIntNoise("Aparte del trasiego de algunos guardias en el resto del edificio, "
    "tan solo se aprecia a lo lejos el rumor del mar.\n");
    SetIntBright(30);
    AddItem(PNJ("simauria/berat/pirkn"),REFRESH_DESTRUCT);
    AddExit("este", "./rellano2");
    AddDoor("este", "la puerta del rellano",
    "Se trata de la puerta que comunica el despacho del capit�n de la guardia con el "
    "rellano.\n", ({"puerta del rellano", "puerta este",
    "puerta del este", "puerta"}));
}
