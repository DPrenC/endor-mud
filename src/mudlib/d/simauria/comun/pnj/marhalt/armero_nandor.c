/****************************************************************************
Fichero: armero_nandor.c
Autor: Ratwor
Fecha: 05/11/2006
Descripci�n: el armero de la armer�a de nandor.
****************************************************************************/


#include <properties.h>
#include <gremios.h>
#include "./path.h"

inherit NPC;

create()
{
    ::create();
    AddId(({"armero", "tendero", "gamanor", "Gamanor"}));
    SetStandard("Gamanor", "humano", ([GC_GUERRERO:22]), GENDER_MALE);
    SetShort("Gamanor el armero");
    SetLong("Gamanor es un antiguo guerrero, que aunque sigue siendo miembro del gremio"
        ", una fuerte ca�da le impide realizar grandes esfuerzos.\n Su pasi�n, entonces y"
        " ahora, son las armas y siempre va intentando venderle alguna a cualquier "
        "ciudadano del gremio.\n Se mont� el negocio cerca del cuartel,  aparte del "
        "buen negocio que le supondr�a, para estar informado de todo lo que concern�a a "
        "los guerreros, y as� de paso ofrecerle su primer arma a los nuevos miembros.\n");
    SetSmell("Huele a la grasa de las armas.\n");
    Set(P_CANT_LURE,1);
    InitAChats(7,({"El armero dice: �no sabes con quien te est�s metiendo!.\n",
        "Gamanor respira aceleradamente.\n", "Gamanor te intenta dar un cabezazo.\n",
        "El armero se mueve torpemente.\n"}));
    InitChats(3,({"Gamanor se arregla el flequillo.\n", "el armero engrasa una daga.\n",
        "Gamanor te mira interrogante.\n", "El armero te mira con mala cara.\n"}));
    AddQuestion(({"armas","arma"}),"Gamanor te dice: las armas lo son todo en la vida,"
       " sin ellas estamos indefensos.\n");
    SetNoGet("El armero te dice: si me tocas te parto la cabeza como si fuera un mel�n.\n");
    SetCitizenship("nandor");
}
