/****************************************************************************
Fichero: botas_roorg.c
Autor: Ratwor
Fecha: 08/05/2010
Descripci�n: unas botas de piel de roorg para la guardia de Berat.
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_BOTAS, 2, P_SIZE_LARGE, M_PIEL);
    SetShort("unas botas de piel de roorg");
    SetLong("Son unas botas de ca�a corta, confeccionadas con la resistente piel "
    "cubierta de diminutas escamas de los grandes peces carn�voros llamados roorgs "
    "que habitan en el delta del Raxal.\n La piel es oscura, el�stica y d�ctil, "
    "adapt�ndose perfectamente a la pierna y el pie, y a pesar de ser fina es "
    "completamente impermeable, algo muy �til en una zona tan h�meda como es Verat y "
    "sus alrrededores.\n");
    SetWeight(600);
    AddId(({"botas", "botas de piel"}));
    Set(P_GENDER, GENDER_FEMALE);
    Set(P_NUMBER, NUMBER_PLURAL); 
}
