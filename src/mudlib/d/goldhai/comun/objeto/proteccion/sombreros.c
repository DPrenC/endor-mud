/****************************************************************************
Fichero: sombreros.c
Autor: Ratwor
Fecha: 18/04/2008
Descripci�n: una pamela y un sombrero.
****************************************************************************/

#include <combat.h>
#include <properties.h>

inherit ARMOUR;

create()
{
    ::create();
    switch(d2()){
        case 1: SetStandard(AT_CAPUCHA,1,P_SIZE_MEDIUM,M_PIEL); break;
        case 2: SetStandard(AT_CAPUCHA,1,P_SIZE_SMALL,M_PIEL); break;
    }
    SetWeight(300);
    switch(d2()){
        case 1:
            SetShort("una pamela blanca");
            SetLong("Se trata de un amplio sombrero que protege de los rayos del "
            "sol. Est� confeccionado de una fina urdimbre de paja y adornado con una "
            "cinta azul.\n");
            Set(P_GENDER,GENERO_FEMENINO);
        AddId("pamela");
            break;
        case 2:
            SetShort("un sombrero aristocr�tico");
            SetLong("Un sombrero de ala ancha que est� realizado en tejido negro, de "
            "alta calidad. Se adorna con una gran pluma de fais�n.\n");
            AddId(({"sombrero", "sombrero aristocr�tico", "sombrero aristrocratico"}));
            Set(P_GENDER,GENERO_MASCULINO);
            break;
    }
   Set(P_NUMBER,NUMERO_SINGULAR);
   SetValue(1200);
}

