/****************************************************************************
Fichero: peto_roorg.c
Autor: Ratwor
Fecha: 08/05/2010
Descripci�n: Un peto de piel de roorg para la guardia de Berat.
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_CORAZA, 5, P_SIZE_LARGE, M_PIEL);
    SetShort("un peto de piel de roorg");
    SetLong("Este peto est� confeccionado con la gruesa piel oscura del lomo de "
    "un roorg, pez carn�voro que habita en los canales del r�o Raxal. La piel del "
    "lomo de estos animales es mas gruesa y menos flexible que el resto, pero a "
    "cambio sus escamas son mas grandes y duras aunque livianas.\n El peto est� "
    "constitu�do por dos grandes secciones de piel escamosa unidas sobre los hombros "
    "y en los flancos, y con las costuras recubiertas por otras capas superpuestas "
    "de piel m�s f�na y flexible.\n La resistencia del material junto con la "
    "disposici�n de las escamas hacen que las armas resbalen sobre estos petos, "
    "que desv�an los golpes m�s que detenerlos.\n");
    AddId("peto");
    SetWeight(800);
    Set(P_GENDER, GENDER_MALE);

}
