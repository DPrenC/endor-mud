/****************************************************************************
Fichero: /d/kha-annu/comun/habitacion/annufam/ciudad/tiendas/taquillas.c
Autor: [T] Tagoras
Fecha: 08/03/2009
Descripci�n: Oficina de cajas de seguridad de Annufam
[T] 11/03/2009: A�ado puerta
****************************************************************************/
#include "path.h"
#include <door.h>
#include <properties.h>
#include <materials.h>
#include <scheduler.h>
#include <sounds.h>

inherit SECUREBOX;

private int irsur()
{
    return notify_fail("S�lo el personal especializado de la hermandad de "
        "consignas puede abrir esa puerta. Yo que t� no la tocar�a, nunca se "
        "sabe lo que estos interventores pueden haber hecho para protegerla.\n");
}

create()
{
    ::create();
    SetIntShort("la oficina de la hermandad de consignas");
    SetIntLong("�sta es la sede de Annufam de la secci�n de gesti�n de cajas "
        "de seguridad de la Hermandad de Consignas de Simauria.\nAqu� es "
        "donde los clientes realizan los tr�mites de alquiler de cajas "
        "fuertes, as� como el dep�sito y retirada de objetos en las mismas.\n"
        "Estas oficinas est�n atendidas por personal especializado, dotado de "
        "poderes para desplazarse autom�ticamente a cualquier oficina del "
        "mundo donde tu caja se encuentre actualmente.\nUna puerta al sur "
        "conduce al �rea de seguridad, donde los clientes realizan sus "
        "movimientos de objetos en completa intimidad.\n");
    SetIntBright(45);
    SetPlace("Annufam");
    SetKeeper(PNJ_CIUDAD_ANNUFAM("feinan"), REFRESH_DESTRUCT);
    AddExit("sur",SF(irsur));
    AddExit("norte",HAB_THUALIN_ANNUFAM("thualin_05"));
	SetCloseTime(S_CLOSED_AT_NIGHT);
    SetNotifyExits("norte");
	SetLastDest(HAB_THUALIN_ANNUFAM("thualin_05"));
	AddDoor("norte", "la puerta de la calle", "Se trata de una gran puerta de madera maciza.\n",
        ({"puerta", "puerta maciza", "puerta de madera"}), GENDER_FEMALE,
        ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta2"),
        P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta2"),
		P_MATERIAL : M_MADERA, P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}
