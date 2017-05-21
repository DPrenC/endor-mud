/****************************************************************************
Fichero: sirvienta_lady.c
Autor: Ratwor
Fecha: 17/09/2006
Descripci�n: una sirvienta para la hija del noble.
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
        " enaguas, le impiden que realice movimientos muy r�pidos.\n  Si bien sus largos y "
        "�giles dedos suplen con garant�a, sus limitaciones corporales. En su redondo "
        "rostro, destacan unas sonrosadas mejillas, y lleva el pelo recogido en un mo�o y"
        " tocado con un copete.\n");
    SetAlign(100);
    SetCitizenship("nandor");
    SetGuardDefendMsg("La sirvienta grita: �Salvaje!\n");
    InitAChats(4, ({"La sirvienta dice: �salvaje fuera de aqu�!\n",
        "La sirvienta te grita: �te veo en el infierno!.\n"}));
    InitChats(3, ({"La sirvienta prepara un vestido para Lady Sherilin.\n",
        "La sirvienta dobla unas toallas.\n",
        "La sirvienta intenta quitarle las arrugas a una prenda.\n"}));
    SetShrugMsg("La sirvienta dice: no deber�as de estar aqu�, mejor que te vayas.\n");

    AddItem("/std/armour",REFRESH_REMOVE,SF(wearme),
    ([P_SHORT: "una t�nica de sirvientes",
    P_LONG:  "Es  una t�nica de color granate, utilizada por los sirvientes del "
        "castillo de Nandor.\n",
    P_ARMOUR_TYPE:AT_ARMOUR,
    P_IDS: ({"tunica","t�nica granate","tunica_sirvientes","t�nica"}),
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
        write("La sirvienta te mira con mala cara al entrar, parece que no deber�as de "
        "estar aqu�.\n");
        say("La sirvienta mira con mala cara a "+CAP(TNAME)+" cuando entra en la "
        "habitaci�n, quiz�, al igual que t�, tampoco deber�a de estar aqu�.\n", TP);
    }
    return 0;
}
