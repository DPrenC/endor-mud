/****************************************************************************
Fichero: vestido.c
Autor: Dharkus
Fecha: 30/05/2010
Descripción: cuatro vestidos para las ciudadanas de Koek
**********************************************************/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
 create() {
    ::create();
    SetStandard(AT_TABARDO,1,P_SIZE_LARGE,M_TELA);
    SetIds(({"vestido","ropa"}));
    switch(d4()){
        case 1:
            SetShort("un vestido blanco");
            SetLong("Es un vestido blanco de una tela fina y suave.\n Tiene unas "
            "flores bordadas en su parte superior.\n");
            AddAdjective("blanco");
            break;
        case 2:
            SetShort("un vestido azul");
            SetLong("Es un vestido azul de tela gruesa, adornado con lazos y cintas "
            "de color blanco.\n");
            AddAdjective("azul");
            break;
        case 3:
            SetShort("un vestido amarillo");
            SetLong("Es un vestido amarillo con lunares verdes.\n");
            AddAdjective("amarillo");
            break;
        case 4:
            SetShort("un vestido floreado");
            SetLong("Es un elegante vestido largo de color blanco, con grandes "
            "flores rojas que lo adornan.\n");
            AddAdjective(({"elegante","floreado","blanco"}));
            break;
    }
    SetWeight(500);
}
