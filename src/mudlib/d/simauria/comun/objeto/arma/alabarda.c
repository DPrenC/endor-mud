/****************************************************************************
Fichero: alabarda.c
Autor: Ratwor
Fecha: 24/11/2007
Descripción: Una alabarda para el dominio de simauria.
****************************************************************************/


#include <properties.h>
#include <combat.h>
inherit WEAPON;
create()
{
    ::create();
    SetStandard(WT_ALABARDA, 11, P_SIZE_MEDIUM, M_ACERO);
    SetShort("una alabarda");
    SetLong("La alabarda está formada por una larga asta   de madera de un metro"
    "ochenta de longitud  rematada por una afilada punta de lanza.\n"
    "Justo detrás de  ésta posee una hoja similar a la de un hacha pero algo mas"
    "pequeña cuyo filo  de curvatura convexa   está dotado de unos extremos que se"
    "alargan hacia adelante y atrás respectivamente ampliando el corte del arma.\n"
    "En la parte adversa de la hoja se sitúa una pequeña uña curvada hacia  atrás,"
    "utilizada usualmente para engancharla en las armaduras de jinetes enemigos para"
    "derribarlos y poder luego neutralizarlos usando la hoja  o la punta.\n"
    "Se trata de un arma muy versátil y fácil de producir, por lo cual es ampliamente"
    "utilizada por las tropas de infantería en su mayoría humanas pertenecientes a"
    "guarniciones   fronterizas o feudos alejados de las grandes ciudades.\n");
    AddId(({"alabarda", "arma"}));
    Set(P_GENDER, GENDER_FEMALE);
    SetWeight(6300);
    SetNumberHands(2);
}
