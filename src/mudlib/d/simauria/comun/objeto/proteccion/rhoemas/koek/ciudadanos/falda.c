/****************************************************************************
Fichero: falda.c
Autor: Dharkus
Fecha: 30/05/2010
Descripción: dos faldas para las ciudadanas de Koek.
****************************************************************************/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create() {
    ::create();
    SetStandard(AT_TROUSERS,1,P_SIZE_LARGE,M_TELA);
    SetIds(({"falda","ropa"}));
    switch(d2()){
        case 1:
            SetShort("una falda de cuero");
            SetLong("Es una falda de cuero marrón, con un par de evillas que la "
            "adornan.\n");
            AddAdjective(({"De","cuero","marron","marrón"}));
            Set(P_MATERIAL,M_CUERO);
            break;
        case 2:
            SetShort("una falda gris");
            SetLong("Es una elegante y delicada falda de color gris.\n");
            AddAdjective(({"delicada","gris"}));
            break;
    }
    SetWeight(500);
    Set(P_GENDER,GENDER_FEMALE);
    Set(P_NUMBER,NUMBER_SINGULAR);
}
