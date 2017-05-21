/****************************************************************************
Fichero: /guilds/kisalas/habitacion/varios/taquillas.c
Autor: Lug y Yalin
Fecha: 27/04/2007 10:49
Descripci�n: Oficina de cajas de seguridad de Nandor
****************************************************************************/
#include "path.h"
#include <rooms.h>
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
    SetIntLong("�sta es la sede de la secci�n de gesti�n de cajas de "
        "seguridad de la Hermandad de Banqueros de Simauria en el gremio de "
        "kisalas.\nAqu� es donde los clientes realizan los tr�mites de "
        "alquiler de cajas fuertes, as� como el dep�sito y retirada de "
        "objetos en las mismas.\nEstas oficinas est�n atendidas por personal "
        "especializado, dotado de poderes para desplazarse autom�ticamente a "
        "cualquier oficina del mundo donde tu caja se encuentre actualmente.\n"
        "Una puerta al oeste conduce al �rea de seguridad, donde los clientes "
        "realizan sus movimientos de objetos en completa intimidad.\n");
    SetIntBright(45);
    SetPlace("Gremio de Kisalas");
    SetKeeper(AM_PNJ("geneibr"),REFRESH_DESTRUCT);
    SetMainRoom(AM_VARIOS("banco"));
    SetLastDest(AM_PASILLO("pasillo3"));
    SetNotifyExits(({}));
    SetInformCloseMsg("Del sur oyes a nika gritar: �Geneibr, ve terminando ah�, que nos vamos!\n"
        "�sta comienza a recoger los libros diciendo: Est� bien, si alguien quiere algo m�s, "
        "que lo pida rapidito, que vamos a cerrar.\n");
    SetThrowOutMsg("Geneibr bloquea la puerta de seguridad del almac�n, y con gesto cansado te "
        "empuja hacia afuera diciendo: Bien, se acab�, ma�ana ser� otro d�a.\n");
    AddExit("oeste",SF(iroeste));
    AddExit("sur",AM_VARIOS("banco"));
}
