/****************************************************************************
Fichero: camisa.c
Autor: Dharkus
            
Fecha: 30/05/2010
Descripción: Varias camisas para los ciudadanos de Koek
****************************************************************************/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;

create() {
    ::create();
    SetStandard(AT_TUNICA,1,P_SIZE_LARGE,M_TELA);
    SetIds(({"camisa","ropa"}));
    switch(d4()){
        case 1:
            SetShort("una camisa con lunares");
            SetLong("Es una camisa blanca con lunares grises.\n");
            AddAdjective(({"blanca","con","lunares"}));
            break;
        case 2:
            SetShort("una camisa marrón");
            SetLong("Es una camisa marrón con dos bolsillos frontales; uno en cada "
            "lado.\n");
            AddAdjective(({"marron","marrón"}));
            break;
        case 3:
            SetShort("una camisa negra");
            SetLong("Se trata de una camisa negra con unas extrañas figuras en su "
            "parte superior.\n");
            AddAdjective("negra");
            break;
        case 4:
            SetShort("una camisa a cuadros");
            SetLong("Es una camisa verde, con grandes cuadros grises por toda ella.\n");
            AddAdjective(({"a","cuadros"}));
            break;
    }
    SetWeight(450);
    Set(P_GENDER,GENDER_FEMALE);
}
