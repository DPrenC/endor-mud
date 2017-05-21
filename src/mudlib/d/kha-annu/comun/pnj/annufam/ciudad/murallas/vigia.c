/**************************************************************************
fichero: vigia.c
Autor: Riberales.
Creaci�n: 7/10/2005
Descripci�n: El vig�a que hay en Annufam.
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

    SetStandard("un vig�a","enano",50+random(4),GENDER_MALE);
    AddId(({"soldado_murallas","vigia","vig�a","enano vig�a","soldado"}));
    SetShort("un vig�a enano");
    SetLong(W("Se trata de un enano cuya misi�n es ser el primero en dar la "
              "alarma en caso de invasi�n. Se pasa el d�a mirando m�s all� "
              "de las monta�as con un catalejo, y no tienen problemas para "
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
            return "El vig�a suspira.\n";
            break;
        case 1:
            if(!present("catalejo",TO)) return "El vig�a busca su catalejo.\n";
            return "El vig�a observa el horizonte a trav�s del catalejo.\n";
            break;
        case 2:
            return "El vig�a grita: Arquero, todo bien.\n";
            break;
    }

	return "El vig�a silba: fiuuuuu.\n";
}
public int remove()
{
    dtell("kastwey",sprintf("borrando!\n el previous es %O.\n",PO));
    return ::remove();
}

