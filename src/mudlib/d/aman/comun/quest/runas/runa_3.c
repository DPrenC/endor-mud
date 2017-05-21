/*****************************************************************************************
 ARCHIVO:       runa_3.c
 AUTOR:         Ztico
 FECHA:         14-01-2006
 COMENTARIOS:   Runa de Morgana
 ****************************************************************************************/

#include "./path.h"
#include <moving.h>
#include <properties.h>

inherit THING;

public string pOwner;

public string SetOwner(string name) { return pOwner = name; }
public string QueryOwner() { return pOwner; }
public string QueryRuna() { return "Morgana"; }

public void create()
{
    ::create();

    SetShort("la Runa de Morgana");
    SetLong("Es una piedra rojiza de aspecto granítico. Está muy fría y no pesa "
        "demasiado. Lleva grabado en el centro el símbolo de la diosa Morgana, un hacha "
        "y un sable cruzados.\n");
    AddId(({"runa", "runa morgana", "morgana", "Morgana", "Runa de Morgana", "piedra",
    	      "piedra rojiza"}));
    Set(P_CANT_STEAL, 1);
    Set(P_NOSELL, 1);
    Set(P_NODROP, 1);

    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
}

public varargs int move(mixed dest, int method, mixed extra)
{
    object ob = PO;
    object from = ENV(TO);
    int val = ::move(dest, method, extra);

    //Coge la runa...
    if(val == ME_OK && method == M_GET && ob && query_once_interactive(ob)
        && from && !pOwner)
    {
        pOwner = NREAL(ob);  //No tiene dueño, así que se setea al player como
    }                        //como tal
    return val;
}

