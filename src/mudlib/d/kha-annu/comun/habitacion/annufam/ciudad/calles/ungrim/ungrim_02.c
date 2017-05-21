/****************************************************************************
Fichero: ungrim_02.c
Autor: Riberales
Creación: 27/09/2005
Descripción: Un tramo de la calle Ungrim.
****************************************************************************/

#include "./path.h"
inherit BASE_CIUDAD_ANNUFAM;
int ir_norte();


public void create()
{
    ::create();

    SetIntShort("la calle Ungrim");
    SetIntLong(W("Sigues paseando por la calle Ungrim, donde se encuentran las"
                 " tiendas y tabernas de la ciudad. Al norte observas la casa "
                 "de Gemin, la tendera de ropa. También ves un par de "
                 "antorchas para alumbrar esto cuando sea menester. En direc"
                 "ción oeste observas, a lo lejos, un cruce de calles.\n"));


    AddSuelo();
    AddAntorchas();


    AddDetail(({"norte","pared norte","casa","casa de Gemin"}),
              W("Es la vivienda donde vive la enana que atiende la tienda que "
                "hay más al este. Tiene una antorcha sobre la puerta para "
                "alumbrar la calle.\n"));



    AddExit("norte",SF(ir_norte));
    AddExit("oeste",HAB_UNGRIM_ANNUFAM("ungrim_01"));
    AddExit("este",HAB_UNGRIM_ANNUFAM("ungrim_03"));
}

int ir_norte()
{
    return notify_fail("La puerta está cerrada, no puedes entrar.\n",
           NOTIFY_NOT_VALID);
}
