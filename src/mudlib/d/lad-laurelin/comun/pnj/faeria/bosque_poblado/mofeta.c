/***
Fichero: mofeta.c
Autor: kastwey@simauria
Descripción: Una mofeta para el bosque de Siempreunidos.
Creación: 18/12/2004
***/

#include "path.h"
#include <gremios.h>

inherit NPC;

create()
{
    ::create();
   SetStandard("una mofeta","mofeta",([GC_TORPE:3+random(3)]),2);
    SetLong(W("Es una mofeta. Tiene el pelaje pardo en el lomo y en el vientre, y blanco en los costados y la cola.\n"
    "Cuando la miras, comienza a hacer nerviosos movimientos... Mejor no molestarla, no sea que emplee su método de defensa favorito.\n"));
    SetWhimpy(QueryHP());
    InitChats(6,({"La mofeta mira hacia todos lados con evidente nerviosismo.\n",
    "La mofeta olisquea el aire.\n"}));
}

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras)
{
	  tell_room(environment(),W("La mofeta alza la cola y escuchas un suave psssssssss.\n"
	  "Al momento, un nauseabundo hedor inunda el lugar.\n"));
	  environment()->SetIntSmell("Puagg! huele a.. a... hmm. Es un hedor indescriptible!\n");
	  return ::DoDamage(damage,type,gentle,&xtras);
}
