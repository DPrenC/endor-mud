/****************************************************************************
Fichero: /d/goldhai/comun/habitacion/crowy/taquillas.c
Autor: Lug y Yalin
Fecha: 27/04/2007 10:49
Descripci�n: Oficina de cajas de seguridad de Crowy
****************************************************************************/
#include "./path.h"
inherit SECUREBOX;

private int ireste()
{
    return notify_fail("S�lo el personal especializado de la hermandad de "
        "banqueros puede abrir esa puerta. Yo que t� no la tocar�a, nunca se "
        "sabe lo que estos banqueros pueden haber hecho para protegerla.\n");
}

create()
{
    ::create();
    SetLocate("crowy");
    SetIntShort("la oficina de la hermandad de consignas de Crowy");
    SetIntLong("�sta es la sede de Crowy de la secci�n de gesti�n de cajas "
        "de seguridad de la Hermandad de Banqueros.\nAqu� es "
        "donde los clientes realizan los tr�mites de alquiler de cajas "
        "fuertes, as� como el dep�sito y retirada de objetos en las mismas.\n"
        "Estas oficinas est�n atendidas por personal especializado, dotado de "
        "poderes para desplazarse autom�ticamente a cualquier oficina del "
        "mundo donde tu caja se encuentre actualmente.\nUna puerta al este "
        "conduce al �rea de seguridad, donde los clientes realizan sus "
        "movimientos de objetos en completa intimidad.\n");
    SetPlace("Crowy");
    SetKeeper(PNJ("crowy/glondel"));
    AddExit("este",SF(ireste));
    AddExit("oeste",CROWY("calle3"));
    SetLastDest(CROWY("calle3"));
    SetNotifyExits("fuera");
}
