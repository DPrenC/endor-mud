/****************************************************************************
Fichero: /d/lad-laurelin/comun/habitacion/atbalnin/tiendas/taquillas.c
Autor: Lug y Yalin
Fecha: 28/04/2007 10:41
Descripción: Oficina de cajas de seguridad de Atbalnin
****************************************************************************/
#include "path.h"
inherit SECUREBOX;

private int irsur()
{
    return notify_fail("Sólo el personal especializado de la hermandad de "
        "banqueros puede abrir esa puerta. Yo que tú no la tocaría, nunca se "
        "sabe lo que estos banqueros pueden haber hecho para protegerla.\n");
}

create()
{
    ::create();
    SetIntShort("la oficina de la hermandad de consignas");
    SetIntLong("Ésta es la sede en Atbalnin de la sección de gestión de cajas "
        "de seguridad de la Hermandad de Banqueros de Simauria.\nAquí es "
        "donde los clientes realizan los trámites de alquiler de cajas "
        "fuertes, así como el depósito y retirada de objetos en las mismas.\n"
        "Estas oficinas están atendidas por personal especializado, dotado de "
        "poderes para desplazarse automáticamente a cualquier oficina del "
        "mundo donde tu caja se encuentre actualmente.\nUna puerta al sur "
        "conduce al área de seguridad, donde los clientes realizan sus "
        "movimientos de objetos en completa intimidad.\n");
    SetPlace("Atbalnin");
    SetKeeper(PNJ("atbalnin/ciudad/ashiel"),REFRESH_DESTRUCT,1);
    AddExit("sur",SF(irsur));
    AddExit("este",ATB_TI("banco"));
}
