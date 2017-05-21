/**************************************************************************
fichero: botella_cerveza.c
Autor: Riberales
Creación: 27/09/2005
Descripción: Una litrona.

**************************************************************************/

#include "path.h"
#include <properties.h>

inherit DRINK;


public void create()
{
    ::create();
    Set_Drink_Name("cerveza");
    SetLong("Es una botella de cerveza.\n");
    SetFoodMsg1("Das un largo trago de cerveza. ¡Está fresquita!\n");
    SetFoodMsg2("da un largo trago de una botella de cerveza.\n");
    SetFoodAlc(60);
    Set_Vessel_Name("botella");
    Set_Vessel_Value(100);
    Set_Vessel_Weight(1050);
    Set_Vessel_Volume(4500);
    Set_Vessel_Gender(GENDER_FEMALE);
    AddId(({"botella","botella de cerveza","cerveza"}));
}