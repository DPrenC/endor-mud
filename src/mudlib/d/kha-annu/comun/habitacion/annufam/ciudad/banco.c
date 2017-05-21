/****************************************************************************
Fichero: banco.c
Autor: Kastwey
		[T] Tagoras
Creación: 27/07/2005
Descripción: Banco de Annufam
[T] 20/02/2009 Añadido el nombre del banco.
[T] 10/03/2009 Añado puerta
****************************************************************************/

#include "./path.h"
#include <moving.h>
#include <properties.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit BANK;

public void create()
{
    ::create();
	SetLocate("Annufam");
	SetBankName("annufam");
    SetIntShort("el banco de Annufam");
    SetIntLong("Has entrado a la oficina de la Hermandad de Banqueros de la "
               "ciudad de Annnufam. Aquí puedes abrir o cancelar cuentas, "
               "pedir préstamos, ingresar y retirar dinero, etc...\n");

    SetKeeper(PNJ_CIUDAD_ANNUFAM("albaun"));
    AddExit("norte",HAB_THUALIN_ANNUFAM("thualin_01"));
	SetNotifyExits("norte");
	SetLastDest(HAB_THUALIN_ANNUFAM("thualin_01"));
    AddDoor("norte", "la puerta de la calle",
    "Es la puerta que da a la calle principal.\n",
    ({"puerta de la calle", "puerta del norte", "puerta"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
}
