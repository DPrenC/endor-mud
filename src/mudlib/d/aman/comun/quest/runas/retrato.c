/*****************************************************************************************
 ARCHIVO:       retrato.c
 AUTOR:         Ztico
 FECHA:         23-01-2006
 COMENTARIOS:   Retrato de Koili, tatarabuelo de Thualin (guildmaster de kha-annu)
 ****************************************************************************************/

#include "./path.h"
#include <moving.h>
#include <properties.h>

inherit THING;

public string pOwner;

public string SetOwner(string name) { return pOwner = name; }
public string QueryOwner() { return pOwner; }
public int QueryRetrato() { return 1; }

public void create()
{
    ::create();

    SetShort("un retrato");
    SetLong("Es un retrato del General Koili. Se trata de un viejo enano con una gran "
        "barba trenzada. En el dorso hay unas indicaciones para Melm escritas por "
        "Thualin.\n");
    AddId(({"retrato", "retrato de koili", "retrato_koili"}));
    Set(P_NOGIVE, 1);
    Set(P_NOSELL, 1);

    Set(P_GENDER, GENERO_MASCULINO);
    Set(P_NUMBER, NUMERO_SINGULAR);
}
