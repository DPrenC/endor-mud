/****************************************************************************
Fichero: sirvienta_lady.c
Autor: Ratwor
Fecha: 17/09/2006
Descripción: una sirvienta para la hija del noble.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <combat.h>
inherit NPC;
inherit GUARD;
create()
{
    "*"::create();

    SetStandard("Una sirvienta", "humano", 10, GENDER_FEMALE);
    AddId(({"sirvienta", "sirviente", "mujer", "humana", "gorda"}));
    SetShort("la sirvienta personal de Lady Sherilin");
    SetLong("Se trata de una sirvienta de avanzada edad. Su orondo cuerpo y sus abultadas"
        " enaguas, le impiden que realice movimientos muy rápidos.\n  Si bien sus largos y "
        "ágiles dedos suplen con garantía, sus limitaciones corporales. En su redondo "
        "rostro, destacan unas sonrosadas mejillas, y lleva el pelo recogido en un moño y"
        " tocado con un copete.\n");
    SetAlign(100);
    SetCitizenship("nandor");
    SetGuardDefendMsg("La sirvienta grita: ¡Salvaje!\n");
    InitAChats(4, ({"La sirvienta dice: ¡salvaje fuera de aquí!\n",
        "La sirvienta te grita: ¡te veo en el infierno!.\n"}));
    InitChats(3, ({"La sirvienta prepara un vestido para Lady Sherilin.\n",
        "La sirvienta dobla unas toallas.\n",
        "La sirvienta intenta quitarle las arrugas a una prenda.\n"}));
    SetShrugMsg("La sirvienta dice: no deberías de estar aquí, mejor que te vayas.\n");

    AddItem("/std/armour",REFRESH_REMOVE,SF(wearme),
    ([P_SHORT: "una túnica de sirvientes",
    P_LONG:  "Es  una túnica de color granate, utilizada por los sirvientes del "
        "castillo de Nandor.\n",
    P_ARMOUR_TYPE:AT_ARMOUR,
    P_IDS: ({"tunica","túnica granate","tunica_sirvientes","túnica"}),
    P_AC: 2, P_SIZE:P_SIZE_MEDIUM,
    P_WEIGHT: 750,
    P_VALUE: 200]) );

}

public void init()
{
    ::init();
    call_out("saludo",1);
}

public void saludo(){
    if (TP->QueryIsPlayer() && !TP->QueryInvis())
    {
        write("La sirvienta te mira con mala cara al entrar, parece que no deberías de "
        "estar aquí.\n");
        say("La sirvienta mira con mala cara a "+CAP(TNAME)+" cuando entra en la "
        "habitación, quizá, al igual que tú, tampoco debería de estar aquí.\n", TP);
    }
    return 0;
}
