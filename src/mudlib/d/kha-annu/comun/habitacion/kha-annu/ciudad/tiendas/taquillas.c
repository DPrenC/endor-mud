/****************************************************************************
Fichero: /d/kha-annu/comun/habitacion/kha-annu/ciudad/tiendas/taquillas.c
Autor: Lug y Yalin
Fecha: 05/05/2007 10:41
Descripción: Oficina de cajas de seguridad de Kha-annu
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
    SetIntLong("Ésta es la sede de la sección de gestión de cajas de seguridad "
    "de la Hermandad de Banqueros de Simauria en Kha-annu.\nAquí es "
        "donde los clientes realizan los trámites de alquiler de cajas "
        "fuertes, así como el depósito y retirada de objetos en las mismas.\n"
        "Estas oficinas están atendidas por personal especializado, dotado de "
        "poderes para desplazarse automáticamente a cualquier oficina del "
        "mundo donde tu caja se encuentre actualmente.\nUna puerta al este "
        "conduce al área de seguridad, donde los clientes realizan sus "
        "movimientos de objetos en completa intimidad.\n");
    SetPlace("Kha-annu");
    SetKeeper(PNJ("ruffus"),REFRESH_DESTRUCT,1);
    SetMainRoom("./banco");
    AddExit("este",SF(ireste));
    AddExit("norte","./banco");
}
