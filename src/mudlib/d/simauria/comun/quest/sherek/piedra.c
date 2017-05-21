/****************************************************************************
Fichero: /d/simauria/comun/quest/sherek/piedra.c
Autor: Lug y Yalin
Fecha: 12/10/2006
Descripción: Piedra para el ninño del quest
****************************************************************************/

#include "path.h"
#include <moving.h>
#include <properties.h>
inherit THING;

string pOwner;
public string SetOwner(string name) { return pOwner = name; }
public string QueryOwner() { return pOwner; }

create()
{
    ::create();
    AddId(({"piedra","piedra preciosa","topacio","quest_piedra_ninyo"}));
    SetShort("un topacio");
    SetLong("Es una preciosa piedra fina, de color amarillo. Quizá sea "
        "auténtico, o quizá no, no entiendes mucho de piedras.\n");
    Set(P_CANT_STEAL,1);
    Set(P_NOSELL, 1);
    Set(P_NODROP, 1);
    Set(P_NOBUY, 1);
    Set(P_WEIGHT,25);
}

public varargs int move(mixed dest, int method, mixed extra)
{
	   if (method == M_GIVE && !dest->QueryNinyoDarylQuest()) return ME_NO_GIVE;
	   if (method == M_GET && QueryOwner() != TP->QueryRealName())
	   {
	       write("Eso no es tuyo, déjalo donde está.\n");
	       return ME_NO_GET;
	   }
	   return ::move(dest, method, extra);
}
