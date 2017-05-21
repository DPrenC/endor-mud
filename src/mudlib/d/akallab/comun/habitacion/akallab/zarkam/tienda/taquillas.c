/****************************************************************************
Fichero: /d/akallab/comun/habitacion/akallab/zarkam/tienda/taquillas.c
Autor: Lug y Yalin
Fecha: 27/04/2007 10:49
Descripci�n: Oficina de cajas de seguridad de Zarkam
****************************************************************************/
#include "path.h"
#include <door.h>
#include <properties.h>
#include <materials.h>
#include <scheduler.h>


inherit SECUREBOX;

private int irnorte()
{
    return notify_fail("S�lo el personal especializado de la hermandad de "
        "banqueros puede abrir esa puerta. Yo que t� no la tocar�a, nunca se "
        "sabe lo que estos banqueros pueden haber hecho para protegerla.\n");
}

create()
{
    ::create();
    SetIntShort("la oficina de la hermandad de consignas");
    SetIntLong("�sta es la sede de Zarkam de la secci�n de gesti�n de cajas "
        "de seguridad de la Hermandad de Banqueros de Simauria.\nAqu� es "
        "donde los clientes realizan los tr�mites de alquiler de cajas "
        "fuertes, as� como el dep�sito y retirada de objetos en las mismas.\n"
        "Estas oficinas est�n atendidas por personal especializado, dotado de "
        "poderes para desplazarse autom�ticamente a cualquier oficina del "
        "mundo donde tu caja se encuentre actualmente.\nUna puerta al norte "
        "conduce al �rea de seguridad, donde los clientes realizan sus "
        "movimientos de objetos en completa intimidad.\n");
    SetIntBright(45);
    SetPlace("Zarkam");
    SetKeeper(PNJ_Z_CIUDAD("enrok"),REFRESH_DESTRUCT,1);
    AddExit("norte",SF(irnorte));
    AddExit("sur",Z_CIUDAD("calle_19"));
    AddExit("este",Z_TIENDA("banco"));
    SetMainRoom("banco");
    SetNotifyExits("sur");
    SetLastDest(Z_CIUDAD("calle_19"));
    AddDoor("sur", "la puerta de la calle", "Se trata de una gran puerta de madera maciza.\n",
        ({"puerta", "puerta maciza", "puerta de madera"}), GENDER_FEMALE,
        ([P_MATERIAL : M_MADERA, P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}
