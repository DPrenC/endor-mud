/*****************************************************************************************
 ARCHIVO:       estatua_koili.c
 AUTOR:         Ztico
 FECHA:         23-01-2006
 COMENTARIOS:   Estatua de Koili, tatarabuelo de Thualin (guildmaster de kha-annu)
 ****************************************************************************************/

#include "./path.h"
#include <moving.h>
#include <properties.h>

inherit THING;

public string pOwner;

public string SetOwner(string name) { return pOwner = name; }
public string QueryOwner() { return pOwner; }
public int QueryEstatua() { return 1; }

public void create()
{
    ::create();

    SetShort("la estatua de Koili");
    SetLong("Ésta es la escultura que ha realizado Melm. Está hecha de barro blanco "
        "y el parecido con el hombre del retrato es realmente increible. El escultor "
        "tiene bien merecida su fama.\n");
    AddId(({"estatua", "estatua de koili", "escultura", "estatua_koili"}));
    Set(P_NOSELL, 1);
    Set(P_GENDER, GENERO_FEMENINO);
    Set(P_NUMBER, NUMERO_SINGULAR);
    SetWeight(2000);
}
