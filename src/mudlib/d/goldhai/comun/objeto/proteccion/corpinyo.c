/****************************************************************************
Fichero: corpi�o.c
Autor: Ratwor
Fecha: 18/04/2008
Descripci�n: un corpi�o
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create() {
    ::create();
    SetStandard(AT_TABARDO,0,P_SIZE_LARGE,M_TELA);
    SetIds(({"corpi�o", "corpino", "corpi�o ajustado"}));
    SetShort("un corpi�o ajustado");
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
   SetLong("Es un ajustado corpi�o, su misi�n es recoger los pechos femeninos mientras "
   "permite lucir hombros y brazos al desnudo. Est� realizado en suave sat�n con "
   "florecillas bordadas en el borde del escote.\n");
    SetWeight(450);
    SetValue(2500);
}
