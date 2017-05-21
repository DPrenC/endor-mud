/****************************************************************************
Fichero: blusa.c
Autor: Dharkus
Fecha: 30/05/2010
Descripción: dos blusas para las ciudadanas de Koek
****************************************************************************/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create() {
    ::create();
    SetStandard(AT_TUNICA,1,P_SIZE_LARGE,M_TELA);
    SetIds(({"blusa","ropa"}));
    switch(d2()){
        case 1:
            SetShort("una blusa rosa");
            SetLong("Es una blusa rosa de tela fina, y con bonitos botones plateados.\n");
            AddAdjective(({"de","tela","rosa"}));
            break;
        case 2:
            SetShort("una blusa de seda");
            SetLong("Es una elegante blusa de seda blanca.\n");
            AddAdjective(({"de","seda","elegante","blanca"}));
            break;
    }
    SetWeight(400);
    Set(P_GENDER,GENDER_FEMALE);
}
