/****************************************************************************
Fichero: salteador.c
Autor: Ratwor
Fecha: 14/11/2006
Descripción: uno de los salteadores, discipulo del jefe jerenas de los salteadores..
Sólo sale por la noche, en cualquier otro estado del día se destruye.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <nightday.h>
inherit NPC;

create()
{
    ::create();

    SetStandard("un salteador","humano", ([GC_LUCHADOR:24+d20()]), GENDER_MALE);
    AddId(({"hombre", "bandido", "ladron", "ladrón", "salteador", "discipulo"}));
    SetAggressive(1);
    SetShort("un salteador de caminos");
    switch(d3())
    {
        case 1:
            SetLong("Es uno de los miembros de la banda de salteadores que controlan estas "
            "tierras. Ya de mediana edad, y con distintas cicatrices en el rostro, se puede "
            "pensar que está para retirarse, pero su forma de luchar contradice su apariencia"
            " débil.\n");
            break;
        case 2:
            SetLong("Este es otro de los tantos salteadores de la banda de Jeremas, quizá "
            "de los más altos de los que tiene a su servicio, pero no por ello más hábil. A"
            "ún así tampoco es de fiar, pues multitud de asaltos le han dado algo de "
            "esperiencia.\n");
            break;
        case 3:
            SetLong("Es un delgaducho salteador de caminos, miembro y discipulo de la banda "
            "de Jeremas. Muy ágil y listo, posible sucesor como jefe de los salteadores de "
            "esta zona.\n");
            break;
    }

    SetAlign(-200);
    SetSmell("Huele a sudor y suciedad.\n");
    InitAChats(12,({"El salteador esquiva los ataques.\n",
        "El salteador se aparta un poco.\n",
        "El salteador grita: no te resistas!\n"}));
    AddItem(ARMANANDOR("daga"), REFRESH_REMOVE, SF(wieldme));

}

init(){
    ::init();
    if (NIGHTDAY->QueryState() != ND_NIGHT)
    {
        foreach(object inv:all_inventory())
        {
            inv->remove();
            if (inv) destruct(inv);
        }
        remove();
    }
}
