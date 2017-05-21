/****************************************************************************
Fichero: /d/simauria/comun/quest/sherek/llave.c
Autor: Lug y Yalin
Fecha: 13/10/2006
Descripción: Llave para el cofre del quest.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit THING;

string pOwner;
public string SetOwner(string name) { return pOwner = name; }
public string QueryOwner() { return pOwner; }

create()
{
    ::create();
    SetShort("una llave pequeña");
    SetLong("Es una llave pequeña y dorada, probablemente la llave de un cofre.\n");
    AddId(({"llave","llave pequeña","llave pequenya","quest_llave_cofre"}));
    Set(P_CANT_STEAL,1);
    Set(P_NODROP,1);
    Set(P_NOBUY,1);
    Set(P_NOGIVE,1);
    Set(P_NOSELL,1);
}

public varargs int move(mixed dest, int method, mixed extra)
{
	   if (method == M_GET && QueryOwner() != TP->QueryRealName())
	   {
	       write("Eso no es tuyo, déjalo donde está.\n");
	       return ME_NO_GET;
	   }
	   return ::move(dest, method, extra);
}
    