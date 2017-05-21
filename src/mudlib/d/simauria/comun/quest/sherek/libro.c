/****************************************************************************
Fichero: /d/simauria/comun/objeto/otro/sherek/aldea/libro.c
Autor: Lug y Yalin
Fecha: 07/10/2006
Descripci�n: Diario del asesino Marath.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <messages.h>
inherit THING;

string pOwner;
public string SetOwner(string name) { return pOwner = name; }
public string QueryOwner() { return pOwner; }

create()
{
    ::create();
    AddId("libro");
    AddId("quest_libro_daryl");
    SetShort("un libro");
    SetLong("Ves un libro encuadernado en piel, con finas hojas depapiro "
        "bien satinado.\nEst� sujeto por una tira de pergamino lacrada.\n");
    Set(P_CANT_STEAL,1);
    Set(P_NOSELL, 1);
    Set(P_NODROP, 1);
    Set(P_NOBUY, 1);
    SetReadMsg("Mejor no lo abras, podr�as meterte en l�os, no sabes lo que contiene, y si "
        "rompes el sello, podr�an inculparte de manipulaci�n de pruebas...\n");
}

public varargs int move(mixed dest, int method, mixed extra)
{
	   if (method == M_GIVE && !dest->QueryGuardiaDarylQuest()) return ME_NO_GIVE;
	   if (method == M_GET && QueryOwner() != TP->QueryRealName())
	   {
	       write("Eso no es tuyo, d�jalo donde est�.\n");
	       return ME_NO_GET;
	   }
    return ::move(dest, method, extra);
}
