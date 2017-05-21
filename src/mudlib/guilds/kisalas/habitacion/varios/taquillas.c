/****************************************************************************
Fichero: /guilds/kisalas/habitacion/varios/taquillas.c
Autor: Lug y Yalin
Fecha: 27/04/2007 10:49
Descripción: Oficina de cajas de seguridad de Nandor
****************************************************************************/
#include "path.h"
#include <rooms.h>
inherit SECUREBOX;

private int iroeste()
{
    return notify_fail("Sólo el personal especializado de la hermandad de "
        "banqueros puede abrir esa puerta. Yo que tú no la tocaría, nunca se "
        "sabe lo que estos banqueros pueden haber hecho para protegerla.\n");
}

create()
{
    ::create();
    SetIntShort("la oficina de la hermandad de consignas");
    SetIntLong("Ésta es la sede de la sección de gestión de cajas de "
        "seguridad de la Hermandad de Banqueros de Simauria en el gremio de "
        "kisalas.\nAquí es donde los clientes realizan los trámites de "
        "alquiler de cajas fuertes, así como el depósito y retirada de "
        "objetos en las mismas.\nEstas oficinas están atendidas por personal "
        "especializado, dotado de poderes para desplazarse automáticamente a "
        "cualquier oficina del mundo donde tu caja se encuentre actualmente.\n"
        "Una puerta al oeste conduce al área de seguridad, donde los clientes "
        "realizan sus movimientos de objetos en completa intimidad.\n");
    SetIntBright(45);
    SetPlace("Gremio de Kisalas");
    SetKeeper(AM_PNJ("geneibr"),REFRESH_DESTRUCT);
    SetMainRoom(AM_VARIOS("banco"));
    SetLastDest(AM_PASILLO("pasillo3"));
    SetNotifyExits(({}));
    SetInformCloseMsg("Del sur oyes a nika gritar: ¡Geneibr, ve terminando ahí, que nos vamos!\n"
        "Ésta comienza a recoger los libros diciendo: Está bien, si alguien quiere algo más, "
        "que lo pida rapidito, que vamos a cerrar.\n");
    SetThrowOutMsg("Geneibr bloquea la puerta de seguridad del almacén, y con gesto cansado te "
        "empuja hacia afuera diciendo: Bien, se acabó, mañana será otro día.\n");
    AddExit("oeste",SF(iroeste));
    AddExit("sur",AM_VARIOS("banco"));
}
