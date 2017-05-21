/***
Fichero: pnj_spell_base_faeria.c
autor:kastwey@simauria
Descripción: PNJ mágico base de los ciudadanos de la zona de Faeria.
Creación: 01/12/2004
26/12/2004: Cambio el Die para adaptarlo a la nueva forma de hacerse enemigo
***/

#include "path.h"
inherit SPELLMONSTER;

public string SetLongDesprecio(string str);
public string QuerySpellName();
public string SetSpellName(string nombre_conj);
string pMensajeDesprecio;
string pSpellName;

public varargs void Die(mixed silent)
{
    if (sizeof(filter(all_inventory(environment()),
        (: call_other($1, "QueryIsGuardia") :))) - call_other(TO, "QueryIsGuardia"))
    {
        if (QueryKiller())
        {
	        if (QueryKiller()->QueryIsPet())
            {
                if (QueryKiller()->QueryOwner())
                {
                	  filter(all_inventory(environment()),
                        (: call_other($1, "QueryIsGuardia")?$1->AddInformEnemy($2):0 :) , QueryKiller()->QueryOwner() );
                }
            }
            else
            {
                filter(all_inventory(environment()),
                    (: call_other($1, "QueryIsGuardia")?$1->AddInformEnemy($2):0 :) , QueryKiller() );
            }
        }
    }
    ::Die(silent);
}


public varargs int DoDamage (int dmg, int type, int gentle, mixed xtras) // Si le atacan busca a los guardias para que le defiendan.
{
    filter(all_inventory(environment()),
        (: call_other($1, "QueryIsGuardia")?$1->AddEnemy($2):0 :), TP || PO );
    return ::DoDamage(dmg, type, gentle, &xtras);
}

public mixed QueryLong()
{
    if (!TP) return "";
    if (member(RAZASENEMIGAS, TP->QueryRace()) > -1) return pMensajeDesprecio;
    else return ::QueryLong();
}

public string SetLongDesprecio(string str) {
    return pMensajeDesprecio = str;
}
public string QuerySpellName() { return pSpellName; }

public string SetSpellName(string nombre_conj) { return pSpellName = nombre_conj; }
