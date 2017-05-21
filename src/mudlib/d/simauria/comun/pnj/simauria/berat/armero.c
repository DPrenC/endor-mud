/*
DESCRIPCION : herrero kolkson
FICHERO     : /d/simauria/comun/pnj/simauria/berat/armero.c
MODIFICACION: 4-11-99 [Icaro];2-06-00[Maler] eliminados los retornos de carro, arregladas faltas
MODIFICACION: 2-06-00 [Maler];sustituido AddId por SetIds(Id solo coge el primer identificativo)
MODIFICACION: 15-06-00 [Nyh] No se que habra cambiado el maler, pero no habia
			ningun Id, asi que se los he metido y tb le he metido
			adjetivos, y le he puesto a dos manos
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <gremios.h>

inherit NPC;

create()
{
    ::create();
    int arma;
        SetCitizenship("berat");
    SetStandard("Kolkson","humano",([GC_LUCHADOR: 20]),GENDER_MALE);
    AddAdjective("fuerte");
    AddId(({"herrero","armero","tendero","kolkson","herrero kolkson"}));
    SetShort("el herrero Kolkson");
    SetLong("Es Kolkson el herrero, un humano con una constitución fuera de lo normal. Parece "
        "muy fuerte, pero afable.\n");
    SetWeight(100000);

    SetStr(QueryStr()+5);
    Set(P_CANT_LURE,1);
    arma=clone_object("/std/weapon");
        arma->SetStandard(WT_MAZA, 12, P_SIZE_MEDIUM, M_ACERO);
        arma->Set(P_SHORT, "un martillo pesado");
        arma->Set(P_LONG, "Un enorme martillo de acero, fuerte y eficaz.\n");
        arma->SetIds(({"martillo", "martillo pesado"}));
        arma->AddAdjective(({"un","enorme","de acero"}));
        arma->SetNumberHands(2);
    AddItem(arma, REFRESH_REMOVE, SF(wieldme));
}
