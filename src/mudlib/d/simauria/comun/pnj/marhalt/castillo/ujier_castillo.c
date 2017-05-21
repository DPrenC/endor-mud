/****************************************************************************
Fichero: ujier_castillo.c
Autor: Ratwor
Fecha: 23/09/2006
Descripción: El ujier que anuncia la llegada de los players en presencia del noble de nandor.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>
inherit NPC;
inherit GUARD;
create()
{
    "*"::create();

    SetStandard("el ujier", "humano", ([GC_LUCHADOR:20]), GENDER_MALE);
    AddId(({"sirviente", "chambelan", "ujier", "hombre"}));
    SetShort("el ujier");
    SetLong("Es el ujier del noble, que se encarga de anunciar la llegada de las visitas "
        "cuando hacen su entrada en el salón.\n Antiguamente era un guardia del castillo,"
        " como el resto que se pueden encontrar haciendo la ronda, pero como castigo el"
        " noble lo ha puesto a desempeñar tan aburrida y simple tarea para una persona de"
        " acción como él.\n  No disimula nada su malestar con su trabajo, pues muestra "
        "siempre cara de aburrimiento y tarda mucho en reconocer a la gente para"
        " anunciarles.\n");
    SetCitizenship("nandor");
    SetGuardDefendMsg("El ujier se une airoso al combate.\n");
    SetSmell("Parece que huele a ropa usada, muy usada.\n");
    InitChats(2, ({"El ujier parece que se cansa de pié y mueve un poco las piernas.\n",
        "El ujier mira al techo.\n",
        "El ujier pone cara de aburrimiento.\n"}));
    AddQuestion(({"señor", "noble", "rocher"}), "El ujier pone cara de susto al"
    " preguntarle y mira de reojo a su alrededor como buscando a alguien con la mirada,"
    " parece que va a hablar, pero al final hace una desganada sonrisa y se queda mudo.\n");

}

init()
{
    ::init();
    if (TP->QueryIsPlayer() && !Fighting())
        call_out("entrada",1);
}
public void entrada(){
    tell_room(environment(), CAP(QueryShort())+
        " levanta la voz diciendo:\n ¡Atención, atención!, "
        +CAP(TP->QueryPresay())+CAP(TP->QueryName())+ " hace entrada en el salón.\n");
}
