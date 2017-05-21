/****************************************************************************
Fichero: /d/simauria/comun/habitacion/betua/gorat/tiendas/taquillas.c
Autor: Lug y Yalin
Fecha: 27/04/2007 10:49#include "path
Descripci�n: Oficina de cajas de seguridad de Gorat
****************************************************************************/
#include "path.h"
inherit SECUREBOX;

private int iroeste()
{
    return notify_fail("S�lo el personal especializado de la hermandad de "
        "banqueros puede abrir esa puerta. Yo que t� no la tocar�a, nunca se "
        "sabe lo que estos banqueros pueden haber hecho para protegerla.\n");
}

create()
{
    ::create();
    SetIntShort("la oficina de la hermandad de consignas");
    SetIntLong("�sta es la sede de Gorat de la secci�n de gesti�n de cajas "
        "de seguridad de la Hermandad de Banqueros de Simauria.\nAqu� es "
        "donde los clientes realizan los tr�mites de alquiler de cajas "
        "fuertes, as� como el dep�sito y retirada de objetos en las mismas.\n"
        "Estas oficinas est�n atendidas por personal especializado, dotado de "
        "poderes para desplazarse autom�ticamente a cualquier oficina del "
        "mundo donde tu caja se encuentre actualmente.\nUna puerta al oeste "
        "conduce al �rea de seguridad, donde los clientes realizan sus "
        "movimientos de objetos en completa intimidad.\n");
    SetPlace("Gorat");
    SetKeeper(GORPNJ("fenrim"),REFRESH_DESTRUCT,1);
    AddExit("oeste",SF(iroeste));
    AddExit("sur","../tiendas/bancoh");
    SetMainRoom("./bancoh");
    SetNotifyExits(({}));
    SetLastDest("../calles/callep6");
}
