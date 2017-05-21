/****************************************************************************
Fichero: damila.c
Autor: Ratwor
Fecha: 19/04/2008
Descripci�n: la tendera de la tienda de ropa
****************************************************************************/
#include "./path.h"
#include <properties.h>

#include DOM_SYS "crowiano.h"

inherit PNJ_CROWY("crowiano_civil_base");
create(){
    ::create();
    SetStandard("Damila", "elfo", 11, GENDER_FEMALE);
    AddId(({"elfa", "tendera"}));
    SetShort("Damila la tendera");
    SetLong("Damila es la tendera de esta antigua sastrer�a de la ciudad de Crowy. "
    "Fund� la tienda su abuelo elfo antes de que ella naciera, y ha ido pasando "
    "de generaci�n en generaci�n hasta llegar a ella. Al igual que sus descendientes, "
    "conserva la calidad y elegancia en las prendas que confecciona.\n");
    SetEdad(MEDIANA);
}
