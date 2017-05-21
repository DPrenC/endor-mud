/*****************************************************************************************
 ARCHIVO:       fresas.c
 AUTOR:         Ztico
 FECHA:         13-12-2005
 DESCRIPCIÓN:   Unas fresas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <properties.h>

inherit FOOD;

create()
{
    if(::create()) return 1;
    SetFoodKind("food");
    SetShort("unas fresas");
    SetLong("Son unas apetitosas fresas de color rojo-azulado.\n");
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    AddAdjective("apetitosas");
    AddId(({"fresas", "fresas_faeria"}));
    SetFoodMsgs("Te comes una apetitosa fresa.\n");
    SetFoodStuff(11);
    SetFoodHeal(6);
    SetFoodKind("food");
    SetFoodStuff(5);
    SetWeight(50);
    SetValue(35);
}



