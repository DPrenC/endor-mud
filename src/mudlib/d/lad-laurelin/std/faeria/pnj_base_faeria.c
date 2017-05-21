/***
Fichero: pnj_base_faeria.c
autor:kastwey@simauria
Descripción: PNJ base de los ciudadanos de la zona de Faeria.
Creación: 01/12/2004
09/12/2004
Arreglo el die para que si es un familiar o un elemental, el enemigo sea el dueño.
***/
#include "path.h"

inherit NPC;


public string SetLongDesprecio(string str);
string pMensajeDesprecio;

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
        (: call_other($1, "QueryIsGuardia")?$1->AddEnemy($2):0 :) , TP || PO );
    return ::DoDamage(dmg, type, gentle, &xtras);
}

public mixed QueryLong()
{
    if (!TP) return "";
    if (member(RAZASENEMIGAS, TP->QueryRace()) >= 0 && pMensajeDesprecio)
        return pMensajeDesprecio;
    else
        return ::QueryLong();
}

public string SetLongDesprecio(string str)
{
    return pMensajeDesprecio = str;;
}

