/**************************************************************************
fichero: vigia.c
Autor: Riberales.
Creación: 7/10/2005
Descripción: El vigía que hay en Annufam.
**************************************************************************/

#include "./path.h"
#include <properties.h>
#include <combat.h>


inherit PNJ_CIUDAD_ANNUFAM("murallas/soldado_base");
string chats();

public void create()
{
    ::create();

    seteuid(getuid());

    SetStandard("un vigía","enano",50+random(4),GENDER_MALE);
    AddId(({"soldado_murallas","vigia","vigía","enano vigía","soldado"}));
    SetShort("un vigía enano");
    SetLong(W("Se trata de un enano cuya misión es ser el primero en dar la "
              "alarma en caso de invasión. Se pasa el día mirando más allá "
              "de las montañas con un catalejo, y no tienen problemas para "
              "vigilar de noche, ya que por su naturaleza, ven en la "
              "oscuridad.\n"));


    AddItem(ARMA_ANNUFAM("ciudad/espada_murallas"),REFRESH_REMOVE,SF(wieldme));
    AddItem(OTRO_ANNUFAM("catalejo"),REFRESH_REMOVE);

    InitChats(3,SF(chats));
}


string chats()
{
    switch (random(3))
    {
        case 0:
            return "El vigía suspira.\n";
            break;
        case 1:
            if(!present("catalejo",TO)) return "El vigía busca su catalejo.\n";
            return "El vigía observa el horizonte a través del catalejo.\n";
            break;
        case 2:
            return "El vigía grita: Arquero, todo bien.\n";
            break;
    }

	return "El vigía silba: fiuuuuu.\n";
}
public int remove()
{
    dtell("kastwey",sprintf("borrando!\n el previous es %O.\n",PO));
    return ::remove();
}

