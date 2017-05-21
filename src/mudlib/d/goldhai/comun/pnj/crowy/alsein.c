/****************************************************************************
Fichero: banquero.c
Autor: Riberales
Fecha: 07/03/2006
Descripci�n: El banquero de Crowy.
****************************************************************************/


#include "path.h"
#include DOM_SYS "crowiano.h"
#include <properties.h>

inherit PNJ_CROWY("crowiano_civil_base");

create()
{
    ::create();
    SetStandard("alsein","humano",10,GENDER_MALE);

    SetShort("alsein el banquero");
    SetLong("Alsein es el banquero de la ciudad de Crowy, y m�ximo "
            "responsable de las finanzas de sus habitantes. Es un humano de "
            "constituci�n fornida, lo que hace que la gente se lo piense dos "
            "veces antes de intentar atacarle.\n");

    SetIds(({"banquero","humano","alsein","Alsein"}));

    InitChats(3,({
              "El banquero te pregunta: �Deseas algo?\n",
              "El banquero murmura: Hum, �ste vendr� en breve a pedir un pr�stamo.\n",
            "El banquero dice: Vaya, en esta ciudad son muy ahorradores.\n"}));

}
