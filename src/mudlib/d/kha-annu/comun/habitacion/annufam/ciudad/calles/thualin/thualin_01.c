/****************************************************************************
Fichero: thualin_01.c
Autor: Kastwey
		[T] Tagoras
Creación: 27/07/2005
Descripción: calle thualin
[T] 10/03/2009: Añado puerta
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit HAB_THUALIN_ANNUFAM("thualin_base");

public void create()
{
    ::create();
    SetIntShort("la calle Thualin");
    SetIntLong(W("Paseas por la Calle Thualin que atraviesa la ciudad de "
                 "este a oeste. Al norte puedes ver la pared sur del "
                 "espartano Centro de Adiestramiento de Guerreros Enanos, "
                 "mientras que al sur se encuentra el banco de la ciudad. "
                 "Al este sigue la calle y al oeste la plaza Belthain, por "
                 "donde puedes acceder al susodicho Centro.\n"));


    AddDetail("banco",W("Es la fachada frontal de la sucursal de la "
                        "Hermandad de Banqueros aquí en Annufam.\n"));

    AddLuzAntorchas();

    AddExit("este",HAB_THUALIN_ANNUFAM("thualin_02"));
    AddExit("oeste",HAB_CIUDAD_ANNUFAM("plaza"));
    AddExit("sur",HAB_CIUDAD_ANNUFAM("banco"));
    AddDoor("sur", "la puerta del banco", "Es la puerta para entrar en el banco.\n",
    ({"puerta", "puerta del banco", "puerta del sur"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME: S_CLOSED_AT_NIGHT]));
}
