/**************************************************************************
fichero: jarra_cerveza.c
Autor: kastwey
Creación: 20/07/2005
Descripción: Una jarra de cerveza para los enanos.

**************************************************************************/

#include "path.h"
#include <properties.h>

inherit DRINK;


public void create()
{
    ::create();
    Set_Drink_Name("cerveza");
    SetLong("Es una jarra de cerveza.\n");
    SetFoodMsg1("Das un largo trago de cerveza. ¡Está buenísima!");
    SetFoodMsg2("da un largo trago de una jarra de cerveza.");
    SetFoodAlc(50);
    Set_Vessel_Name("jarra");
    Set_Vessel_Value(150);
    Set_Vessel_Weight(750);
    Set_Vessel_Volume(2000);
    Set_Vessel_Gender(GENDER_FEMALE);
    AddId(({"jarra","jarra de cerveza","cerveza","jarra_cerveza"}));
}
