/****************************************************************************
Fichero: ciuda1.c
Autor: Ratwor
Fecha: 06/06/2010
Descripci�n: unos ciudadanos para Berat con distintos short y descripciones.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
inherit NPC;

create() {
    ::create();
    switch(d2()){
        case 1: // femeninos
            switch(d3()){
                case 1:
                    SetStandard("una joven", "humano", ([GC_NINGUNO:11+d2()]), GENDER_FEMALE);
                    SetShort("una joven");
                    SetLong("Es una j�ven de estatura baja y constituci�n delgada, "
                    "como los juncos que crecen en el delta del Raxal. Esto junto "
                    "con sus cabellos casta�os, que lleva largos por debajo de los "
                    "hombros y sus ojos, denota que desciende de los antiguos "
                    "habitantes del delta del r�o antes de la fundaci�n de Verat.\n");
                    SetIds(({"ciudadana", "humana", "joven"}));
                    break;
                case 2:
                    SetStandard("una anciana", "humano", ([GC_NINGUNO:10]), GENDER_FEMALE);
                    SetShort("una anciana");
                    SetLong("Es una mujer mayor, baja y de constituci�n ligera.\n"
                    "Sus cabellos son completamente blancos pero entre ellos todav�a "
                    "queda alguna hebra casta�a que denotan que desciende de las "
                    "tribus de los Verati.\n");
                    SetIds(({"humana", "anciana", "mujer", "ciudadana"}));
                    break;
                case 3:
                    SetStandard("una ciudadana", "humano", ([GC_TORPE:12]),GENDER_FEMALE);
                    SetShort("una ciudadana");
                    SetLong("Es una mujer de mediana edad, baja y de figura gr�cil "
                    "y estilizada. Con cabellos oscuros y rizados, al contrario de "
                    "la mayor�a de la poblaci�n de Verat, lo que indica que no es "
                    "descendiente de los hombres que habitaron el delta del r�o Raxal "
                    "hace cientos de a�os.\n");
                    SetIds(({"ciudadana", "humana", "mujer"}));
                    break;
            }
            AddItem(PROT("berat/falda_roorg"), REFRESH_REMOVE, SF(wearme));
            AddItem(PROT("berat/chaleco_roorg_f"), REFRESH_REMOVE, SF(wearme));
            break; //femeninos
        case 2: //masculinos
            switch(d3()){
                case 1:
                    SetStandard("un joven", "humano", ([GC_NINGUNO:15+d3()]), GENDER_MALE);
                    SetShort("un joven");
                    SetLong("Es uno de los habitantes de Verat, un humano j�ven  "
                    "de baja estatura, constituci�n ligera y cabellos casta�os; "
                    "descendiente de los hombres que fundaron el puerto de Verat.\n");
                    AddId(({"joven", "ciudadano"}));
                    break;
                case 2:
                    SetStandard("un ciudadano", "humano", ([GC_TORPE:13+d2()]), GENDER_MALE);
                    SetShort("un ciudadano");
                    SetLong("Es un hombre de mediana edad, anchos hombros, cabellos "
                    "negros y rostro amplio y bonach�n.\n Pese a ser un habitante "
                    "de Verat no parece ser descendiente de sus fundadores, y de "
                    "serlo su sangre se ha mezclado con la de otras gentes.\n");
                    AddId(({"ciudadano", "hombre"}));
                    break;
                case 3:
                    SetStandard("un anciano", "humano", ([GC_NINGUNO: 9]), GENDER_MALE);
                    SetShort("un anciano");
                    SetLong("Es un viejo ciudadano de Berat, con porte notablemente "
                    "deteriorado. Sus cabellos, a pesar de ser bastante canoso, denotan "
                    "su origen Berati.\n Aunque en sus tiempos fue un hombre de mar, "
                    "ahora ya en su vejez poco queda de aquello.\n");
                    AddId(({"anciano", "ciudadano", "viejo"}));
                    break;
            }
            AddItem(PROT("berat/pantalon_roorg"), REFRESH_REMOVE, SF(wearme));
            AddItem(PROT("berat/chaleco_roorg_m"), REFRESH_REMOVE, SF(wearme));
            break; // masculinos
    }    
    if (d2()==1) SetGoChance(30);
    AddWalkZones(SIMA("berat"));
    SetCitizenship("berat");
    AddItem(PROT("berat/botas_roorg"), REFRESH_REMOVE, SF(wearme));

}

