/*****************************************************************************************
 ARCHIVO:       runa_7.c
 AUTOR:         Ztico
 FECHA:         14-01-2006
 COMENTARIOS:   Runa de Belisama

                En una chimenea de Siempreunidos
 ****************************************************************************************/

#include "./path.h"
#include <moving.h>
#include <properties.h>

inherit THING;

public string pOwner;

public string SetOwner(string name) { return pOwner = name; }
public string QueryOwner() { return pOwner; }
public string QueryRuna() { return "Belisama"; }

public void create()
{
    ::create();

    SetShort("la Runa de Belisama");
    SetLong("Es ante todo peculiar. Tiene el símbolo del fuego grabado en el centro, "
        "y podría pasar desapercibida entre un montón de piedras.\n");
    AddId(({"runa", "runa belisama", "belisama", "Belisama", "Runa de Belisama",
    	      "piedra"}));
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
