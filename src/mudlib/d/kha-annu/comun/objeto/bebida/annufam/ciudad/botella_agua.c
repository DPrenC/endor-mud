/**************************************************************************
fichero: botella_agua.c
Autor: Riberales
Creación: 27/09/2005
Descripción: Una botella de agua.

**************************************************************************/

#include "path.h"
#include <properties.h>

inherit DRINK;


public void create()
{
    ::create();
    Set_Drink_Name("agua");
    SetLong("Es una botella de agua cristalina.\n");
    SetFoodMsg1("Pegas un trago de agua de tu botella.\n");
    SetFoodMsg2("da un trago de una botella de agua.\n");
    Set_Vessel_Name("botella");
    Set_Vessel_Value(60);
    Set_Vessel_Weight(1000);
    Set_Vessel_Volume(3000);
    Set_Vessel_Gender(GENDER_FEMALE);
    AddId(({"botella","botella de agua","agua"}));
}