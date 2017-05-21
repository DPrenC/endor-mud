/****************************************************************************
Fichero: peto_roorg.c
Autor: Ratwor
Fecha: 08/05/2010
Descripción: Un peto de piel de roorg para la guardia de Berat.
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_CORAZA, 5, P_SIZE_LARGE, M_PIEL);
    SetShort("un peto de piel de roorg");
    SetLong("Este peto está confeccionado con la gruesa piel oscura del lomo de "
    "un roorg, pez carnívoro que habita en los canales del río Raxal. La piel del "
    "lomo de estos animales es mas gruesa y menos flexible que el resto, pero a "
    "cambio sus escamas son mas grandes y duras aunque livianas.\n El peto está "
    "constituído por dos grandes secciones de piel escamosa unidas sobre los hombros "
    "y en los flancos, y con las costuras recubiertas por otras capas superpuestas "
    "de piel más fína y flexible.\n La resistencia del material junto con la "
    "disposición de las escamas hacen que las armas resbalen sobre estos petos, "
    "que desvían los golpes más que detenerlos.\n");
    AddId("peto");
    SetWeight(800);
    Set(P_GENDER, GENDER_MALE);

}
