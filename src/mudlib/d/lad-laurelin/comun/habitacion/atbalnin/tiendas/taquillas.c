/****************************************************************************
Fichero: /d/lad-laurelin/comun/habitacion/atbalnin/tiendas/taquillas.c
Autor: Lug y Yalin
Fecha: 28/04/2007 10:41
Descripci�n: Oficina de cajas de seguridad de Atbalnin
****************************************************************************/
#include "path.h"
inherit SECUREBOX;

private int irsur()
{
    return notify_fail("S�lo el personal especializado de la hermandad de "
        "banqueros puede abrir esa puerta. Yo que t� no la tocar�a, nunca se "
        "sabe lo que estos banqueros pueden haber hecho para protegerla.\n");
}

create()
{
    ::create();
    SetIntShort("la oficina de la hermandad de consignas");
    SetIntLong("�sta es la sede en Atbalnin de la secci�n de gesti�n de cajas "
        "de seguridad de la Hermandad de Banqueros de Simauria.\nAqu� es "
        "donde los clientes realizan los tr�mites de alquiler de cajas "
        "fuertes, as� como el dep�sito y retirada de objetos en las mismas.\n"
        "Estas oficinas est�n atendidas por personal especializado, dotado de "
        "poderes para desplazarse autom�ticamente a cualquier oficina del "
        "mundo donde tu caja se encuentre actualmente.\nUna puerta al sur "
        "conduce al �rea de seguridad, donde los clientes realizan sus "
        "movimientos de objetos en completa intimidad.\n");
    SetPlace("Atbalnin");
    SetKeeper(PNJ("atbalnin/ciudad/ashiel"),REFRESH_DESTRUCT,1);
    AddExit("sur",SF(irsur));
    AddExit("este",ATB_TI("banco"));
}
