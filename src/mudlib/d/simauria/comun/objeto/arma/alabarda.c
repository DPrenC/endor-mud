/****************************************************************************
Fichero: alabarda.c
Autor: Ratwor
Fecha: 24/11/2007
Descripci�n: Una alabarda para el dominio de simauria.
****************************************************************************/


#include <properties.h>
#include <combat.h>
inherit WEAPON;
create()
{
    ::create();
    SetStandard(WT_ALABARDA, 11, P_SIZE_MEDIUM, M_ACERO);
    SetShort("una alabarda");
    SetLong("La alabarda est� formada por una larga asta   de madera de un metro"
    "ochenta de longitud  rematada por una afilada punta de lanza.\n"
    "Justo detr�s de  �sta posee una hoja similar a la de un hacha pero algo mas"
    "peque�a cuyo filo  de curvatura convexa   est� dotado de unos extremos que se"
    "alargan hacia adelante y atr�s respectivamente ampliando el corte del arma.\n"
    "En la parte adversa de la hoja se sit�a una peque�a u�a curvada hacia  atr�s,"
    "utilizada usualmente para engancharla en las armaduras de jinetes enemigos para"
    "derribarlos y poder luego neutralizarlos usando la hoja  o la punta.\n"
    "Se trata de un arma muy vers�til y f�cil de producir, por lo cual es ampliamente"
    "utilizada por las tropas de infanter�a en su mayor�a humanas pertenecientes a"
    "guarniciones   fronterizas o feudos alejados de las grandes ciudades.\n");
    AddId(({"alabarda", "arma"}));
    Set(P_GENDER, GENDER_FEMALE);
    SetWeight(6300);
    SetNumberHands(2);
}
