/****************************************************************************
Fichero: /d/goldhai/comun/habitacion/crowy/taquillas.c
Autor: Lug y Yalin
Fecha: 27/04/2007 10:49
Descripción: Oficina de cajas de seguridad de Crowy
****************************************************************************/
#include "./path.h"
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
    SetLocate("crowy");
    SetIntShort("la oficina de la hermandad de consignas de Crowy");
    SetIntLong("Ésta es la sede de Crowy de la sección de gestión de cajas "
        "de seguridad de la Hermandad de Banqueros.\nAquí es "
        "donde los clientes realizan los trámites de alquiler de cajas "
        "fuertes, así como el depósito y retirada de objetos en las mismas.\n"
        "Estas oficinas están atendidas por personal especializado, dotado de "
        "poderes para desplazarse automáticamente a cualquier oficina del "
        "mundo donde tu caja se encuentre actualmente.\nUna puerta al este "
        "conduce al área de seguridad, donde los clientes realizan sus "
        "movimientos de objetos en completa intimidad.\n");
    SetPlace("Crowy");
    SetKeeper(PNJ("crowy/glondel"));
    AddExit("este",SF(ireste));
    AddExit("oeste",CROWY("calle3"));
    SetLastDest(CROWY("calle3"));
    SetNotifyExits("fuera");
}
