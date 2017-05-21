/**************************************************************************
fichero: botella_vino.c
Autor: Riberales
Creación: 27/09/2005
Descripción: Una botella de vino.

**************************************************************************/

#include "path.h"
#include <properties.h>

inherit DRINK;


public void create()
{
    ::create();
    Set_Drink_Name("vino");
    SetLong("Es una botella de vino tinto.\n");
    SetFoodMsg1("Pegas un trago vino. Entra bastante bien.\n");
    SetFoodMsg2("da un trago de una botella de vino.\n");
    Set_Vessel_Name("botella");
    Set_Vessel_Value(110);
    Set_Vessel_Weight(1750);
    Set_Vessel_Volume(4000);
    Set_Vessel_Gender(GENDER_FEMALE);
    AddId(({"botella","botella de vino","vino"}));
}