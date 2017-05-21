/****************************************************************************
Fichero: salteador_jefe.c
Autor: Ratwor
Fecha: 14/11/2006
Descripción: el jefe de los salteadores. Sólo sale por la noche, el resto del día se destruye.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <nightday.h>
#include <combat.h>
inherit NPC;

create()
{
    ::create();

    SetStandard("Jerenas","humano", ([GC_LUCHADOR:65]), GENDER_MALE);
    AddId(({"salteador", "jefe", "hombre", "bandido", "ladron", "ladrón", "bandido"}));
    SetAggressive(1);
    SetIVision(0);
    SetShort("jerenas el salteador");
    SetLong("Jerenas es el jefe de los salteadores de estas zonas, aunque no hace mucho "
        "todavía era un discipulo del antiguo jefe de la banda, el cual murió a manos de "
        "unos guardias en pleno asalto.\n A pesar de su juventud, domina bien a los  de "
        "su banda, pues tiene buena madera de líder. Hasta el momento ha  organizado"
        " interesantes asaltos, aunque no todos le salen bien y, en ocasiones, se "
        "encuentra con asaltados más poderosos de lo que aparentaban.\n");
    SetAlign(-250);
    SetSmell("Huele a sudor y suciedad.\n");
    InitAChats(12,({"Jeremas se ríe a carcajada.\n",
        "Jerenas dice: no pasará nadie sin ser visitado por mí.\n",
        "Jerenas dice: ¡dame todo el dinero!.\n",
        "Jerenas parece que se tropieza, pero mantiene la compostura.\n"}));
    AddItem(ARMANANDOR("daga"), REFRESH_REMOVE,
            ([P_SHORT:"una daga larga",
            P_LONG:"Es una reluciente daga larga de acero brillante y bien afilada.\n"
            "Llevaba una inscripción en el mango, pero parece que ha sido "
            "deteriorado intencionadamente.\n",
            P_IDS:({"daga","daga de acero", "daga larga"})]), SF(wieldme));

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
