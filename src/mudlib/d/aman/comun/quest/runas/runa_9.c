/*****************************************************************************************
 ARCHIVO:       runa_9.c
 AUTOR:         Ztico
 FECHA:         14-01-2006
 COMENTARIOS:   Runa de Balor
 ****************************************************************************************/

#include "./path.h"
#include <properties.h>
#include <moving.h>

inherit THING;

public string pOwner;

public string SetOwner(string name) { return pOwner = name; }
public string QueryOwner() { return pOwner; }
public string QueryRuna() { return "Balor"; }

public void create()
{
    ::create();

    SetShort("la Runa de Balor");
    SetLong("Es una piedra de color negro opaco. No tiene ningún símbolo grabado en "
        "ella, no obstante, en su interior flamea una especie de neblina blanca.\n");
    AddId(({"runa", "runa balor", "balor", "Balor", "Runa de Balor", "piedra"}));
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
