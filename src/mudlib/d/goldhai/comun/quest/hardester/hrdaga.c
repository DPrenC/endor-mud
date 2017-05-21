/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 26-12-97                |
 |                                                             |
 *=============================================================*/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>
#include <moving.h>

inherit WEAPON;

string pOwner;
public string SetOwner(string owner) { return pOwner = owner; }
public string QueryOwner() { return pOwner; }


public create()
{
    if (!clonep(TO)) return;
    ::create();
    SetStandard(WT_CUCHILLO,2,P_SIZE_MEDIUM,M_ACERO);
    SetWeight(320);
    SetShort("una daga");
    SetIds(({"daga","hrdaga"}));
    SetValue(500);
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetNumberHands(1);
    SetLong("Es una daga forjada por algún artesano y con una empuñadura "
            "de marfil en la "
            "que puedes leer un mensaje.\n");
    AddSubDetail(({"empuñadura","empunyadura"}),"Tiene unas letras grabadas "
                                                "que quizás debieras leer.\n");
    AddSubReadMsg(({"empuñadura","empunyadura","letras","inscripción",
                    "inscripcion"}),"Observas las iniciales 'H.R.' "
                                      "talladas en la empuñadura.\n");

}

public varargs int move(mixed dest, int method, mixed extra)
{
    object ob = PO;
    object from = environment();
    int val = ::move(dest, method, extra);
    if (   val == ME_OK && method == M_GET && ob && query_once_interactive(ob)
        && from && !sizeof(all_environment(from)) && !pOwner)
    // está cogiendo la daga del suelo
    // no tiene dueño, así que se setea al player como tal
    {
        pOwner = ob->QueryRealName();
    }
    return val;
}

