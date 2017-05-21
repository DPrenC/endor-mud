/****************************************************************************
Fichero: /d/simauria/comun/habitacion/simauria/berat/taquillas.c
Autor: Lug y Yalin
Fecha: 27/04/2007 10:49
Descripción: Oficina de cajas de seguridad de Berat
****************************************************************************/
#include "path.h"
inherit SECUREBOX;

private int ireste()
{
    return notify_fail("Sólo el personal especializado de la hermandad de "
        "banqueros puede abrir esa puerta. Yo que tú no la tocaría, nunca se "
        "sabe lo que estos banqueros pueden haber hecho para protegerla.\n");
}

create()
{
    ::create();
    SetIntShort("la oficina de la hermandad de consignas");
    SetIntLong("Ésta es la sede de Berat de la sección de gestión de cajas "
        "de seguridad de la Hermandad de Banqueros de Simauria.\nAquí es "
        "donde los clientes realizan los trámites de alquiler de cajas "
        "fuertes, así como el depósito y retirada de objetos en las mismas.\n"
        "Estas oficinas están atendidas por personal especializado, dotado de "
        "poderes para desplazarse automáticamente a cualquier oficina del "
        "mundo donde tu caja se encuentre actualmente.\nUna puerta al este "
        "conduce al área de seguridad, donde los clientes realizan sus "
        "movimientos de objetos en completa intimidad.\n");
    SetIntBright(45);
    SetPlace("Berat");
    SetKeeper(PNJ("simauria/berat/taylor"),REFRESH_DESTRUCT,1);
    AddExit("este",SF(ireste));
    //AddExit("oeste","./cprin2");
    AddExit("sur","./bancoh");
    SetMainRoom("./bancoh");
    SetNotifyExits(({}));
    SetLastDest("./cprin5");
}
