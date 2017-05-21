/****************************************************************************
Fichero: yelmo_ornamentado.c
Autor: Ratwor
Fecha: 17/04/2008
Descripci�n: un yelmo con descripciones aleatorias.
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
            SetLong("Se trata de un yelmo bru�ido hasta brillar con luz propia. Est� "
            "muy recargado con una decoraci�n felina. Su Cimera est� coronada por "
            "un penacho de pelo de le�n, mientras su celada imita los ojos rasgados y "
            "las fauces de un felino de gran tama�o.\n");
            break;
        case 2:
            SetLong("Se trata de un yelmo bru�ido hasta brillar como la plata. Est� muy "
            "recargado de una decoraci�n taurina. Su Cimera est� coronada por un par "
            "de enormes cuernos plateados, mientras su celada imita los grandes hoyares "
            "de la bestia.\n");
            break;
        case 3:
            SetLong("Se trata de un yelmo del m�s oscuro acero, tanto que se dir�a "
            "que es totalmente negro. Est� muy recargado de una decoraci�n "
            "fantasmag�rica. Su Cimera est� realizada a imitaci�n de la parte superior "
            "de un cr�neo, mientras su celada imita las cuencas vac�as y la hilera "
            "de dientes de una calavera.\n");
            break;
        case 4:
            SetShort("un yelmo flam�gero");
            SetLong("Es el m�tico yelmo del drag�n dorado. Realizado en el m�s bru�ido oro "
            "esmaltado, imita a la perfecci�n la cabeza del reptil m�tico.\n Su cimera "
            "escamada y su celada de grandes colmillos, transmiten a los adversarios todo "
            "el miedo y poder emanados de este yelmo m�tico, del cual se cuenta que es capaz "
            "de soportar los m�s intensos fuegos, protegiendo a su portador de "
            "cualquier da�o ocasionado por la batalla o el fuego.\n");
            SetValue(50000);
            break;
    }

}

