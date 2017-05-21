/****************************************************************************
Fichero: chaleco_roorg_m.c
Autor: Ratwor
Fecha: 29/06/2010
Descripci�n: un chaleco de piel de roorg para hombres.
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_TABARDO, 1, P_SIZE_LARGE, M_PIEL);
    SetShort("un chaleco de piel de roorg");
    SetLong("Es un chaleco confeccionado con la piel escamosa de un roorg, pez "
    "carn�voro de la desembocadura del R�o Raxal.\n El material de esta prenda no "
    "es tan gruesa y r�gida como la utilizada para los petos de defensa usados por "
    "la guardia del puerto, pero a�n as� posee cierta rigidez y dureza.\n Esto se "
    "debe a que la piel m�s delicada y ductil de estos animales se suele utilizar "
    "en las prendas femeninas  y otros usos m�s espec�ficos.\n El chaleco se cierra "
    "por delante con unos botones confeccionados con las espinas dorsales de un "
    "roorg rebajadas y pulidas.\n");
    SetIds(({"chaleco", "ropa"}));
    AddAdjective(({"de", "piel", "roorg", "masculino"}));
    SetWeight(450);
    Set(P_GENDER, GENDER_MALE);

}
