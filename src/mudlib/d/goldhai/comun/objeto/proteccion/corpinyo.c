/****************************************************************************
Fichero: corpiño.c
Autor: Ratwor
Fecha: 18/04/2008
Descripción: un corpiño
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create() {
    ::create();
    SetStandard(AT_TABARDO,0,P_SIZE_LARGE,M_TELA);
    SetIds(({"corpiño", "corpino", "corpiño ajustado"}));
    SetShort("un corpiño ajustado");
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
   SetLong("Es un ajustado corpiño, su misión es recoger los pechos femeninos mientras "
   "permite lucir hombros y brazos al desnudo. Está realizado en suave satén con "
   "florecillas bordadas en el borde del escote.\n");
    SetWeight(450);
    SetValue(2500);
}
