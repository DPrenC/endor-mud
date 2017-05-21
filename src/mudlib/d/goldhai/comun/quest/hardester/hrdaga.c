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
    SetLong("Es una daga forjada por alg�n artesano y con una empu�adura "
            "de marfil en la "
            "que puedes leer un mensaje.\n");
    AddSubDetail(({"empu�adura","empunyadura"}),"Tiene unas letras grabadas "
                                                "que quiz�s debieras leer.\n");
    AddSubReadMsg(({"empu�adura","empunyadura","letras","inscripci�n",
                    "inscripcion"}),"Observas las iniciales 'H.R.' "
                                      "talladas en la empu�adura.\n");

}

public varargs int move(mixed dest, int method, mixed extra)
{
    object ob = PO;
    object from = environment();
    int val = ::move(dest, method, extra);
    if (   val == ME_OK && method == M_GET && ob && query_once_interactive(ob)
        && from && !sizeof(all_environment(from)) && !pOwner)
    // est� cogiendo la daga del suelo
    // no tiene due�o, as� que se setea al player como tal
    {
        pOwner = ob->QueryRealName();
    }
    return val;
}

