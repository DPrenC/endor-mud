/****************************************************************************
Fichero: yelmo_ornamentado.c
Autor: Ratwor
Fecha: 17/04/2008
Descripción: un yelmo con descripciones aleatorias.
****************************************************************************/

#include <combat.h>
#include <properties.h>

inherit ARMOUR;

create()
{
   ::create();
    switch(d2()){
        case 1:
            SetStandard(AT_HELMET,4,P_SIZE_LARGE,M_ACERO);
            SetWeight(2500);
            SetValue(25000);
            break;
        case 2:
            SetStandard(AT_HELMET,4,P_SIZE_LARGE,M_ACERO);
            SetWeight(3900);
            SetValue(30000);
            break;
    }
    SetShort("un yelmo ornamentado");
    AddId(({"yelmo", "yelmo ornamentado"}));
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    switch(d4()){
        case 1:
            SetLong("Se trata de un yelmo bruñido hasta brillar con luz propia. Está "
            "muy recargado con una decoración felina. Su Cimera está coronada por "
            "un penacho de pelo de león, mientras su celada imita los ojos rasgados y "
            "las fauces de un felino de gran tamaño.\n");
            break;
        case 2:
            SetLong("Se trata de un yelmo bruñido hasta brillar como la plata. Está muy "
            "recargado de una decoración taurina. Su Cimera está coronada por un par "
            "de enormes cuernos plateados, mientras su celada imita los grandes hoyares "
            "de la bestia.\n");
            break;
        case 3:
            SetLong("Se trata de un yelmo del más oscuro acero, tanto que se diría "
            "que es totalmente negro. Está muy recargado de una decoración "
            "fantasmagórica. Su Cimera está realizada a imitación de la parte superior "
            "de un cráneo, mientras su celada imita las cuencas vacías y la hilera "
            "de dientes de una calavera.\n");
            break;
        case 4:
            SetShort("un yelmo flamígero");
            SetLong("Es el mítico yelmo del dragón dorado. Realizado en el más bruñido oro "
            "esmaltado, imita a la perfección la cabeza del reptil mítico.\n Su cimera "
            "escamada y su celada de grandes colmillos, transmiten a los adversarios todo "
            "el miedo y poder emanados de este yelmo mítico, del cual se cuenta que es capaz "
            "de soportar los más intensos fuegos, protegiendo a su portador de "
            "cualquier daño ocasionado por la batalla o el fuego.\n");
            SetValue(50000);
            break;
    }

}

