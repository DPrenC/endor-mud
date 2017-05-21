#include <rooms.h>
#include <money.h>
#include <combat.h>
#include <properties.h>
#include <gremios.h>

inherit NPC;



create()
{
    object arma;
    ::create();
   SetStandard("Dulan","humano",([GC_LUCHADOR: 20]), GENDER_MALE);
    AddAdjective("fuerte");
    AddId(({"Dulan","dulan","humano","herrero"}));
    SetName("Dulan");
    SetShort("el herrero Dulan.");
    SetLong("El Herrero es un engendro de la naturaleza, repleto de músculos y tatuajes "
        "sugestivos...\n");
    SetAlign(0);
    Set(P_CANT_LURE,1);
    arma=clone_object("/std/weapon");
        arma->SetStandard(WT_MAZA, 10, P_SIZE_MEDIUM, M_ACERO);
        arma->Set(P_SHORT, "un martillo pesado");
        arma->Set(P_LONG, "Un enorme martillo de acero, fuerte y eficaz.\n");
    AddItem(arma, REFRESH_REMOVE, SF(wieldme));
}

