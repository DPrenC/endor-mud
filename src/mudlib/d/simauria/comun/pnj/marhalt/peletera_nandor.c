/****************************************************************************
Fichero: PELETERA_NANDOR.C
Autor: Ratwor
Fecha: 05/11/2006
Descripci�n: La tendera de la sastrer�a de Nandor.
****************************************************************************/

#include <properties.h>
#include <gremios.h>
#include "./path.h"

inherit NPC;

create()
{
    ::create();
    AddId(({"mujer", "tendera", "humana", "peletera", "melian", "Melian"}));
    SetStandard("Melian", "humano",10 , GENDER_FEMALE);
    SetShort("Melian la temdera");
    SetLong("Esta es Melian, una mujer ya bastante mayor, pues calculas que rondar� cerca"
        " de los 60 a�os. El pelo blanco y largo destaca ante todo del resto de su "
        "anatom�a, m�s incluso que su larga nariz y sus extra�as arrugas del cuello.\n"
        " Lleva su negocio familiar con gran entusiasmo, pues es la herencia de generaciones"
        ", quiz� m�s de las que pueda recordar cualquier habitante de la aldea. Aun as� "
        "ella bien se podr�a haber dedicado a otras labores teniendo en cuenta su robusto"
        " cuerpo, m�s voluminoso que el de cualquier humana.\n");
    Set(P_CANT_LURE,1);
    SetWeight(85000);
    SetSmell("El olor de las telas con las que trabaja se le ha impregnado en el cuerpo.\n");
    AddSubDetail(({"pelo", "cabello", "pelo blanco", "pelo largo"}), "Una larga cabellera"
        " blanca.\n");
    AddSubDetail(({"cuello","arrugas"}), "Unas extra�as arrugas le llenan el cuello "
        "verticalmente.\n");
    InitAChats(5, ({"La tendera grita horrorizada.\n",
        "La tendera grita: �d�jame en paz que yo no te he hecho nada!.\n"}));
    InitChats(2,({"La tendera ordena unas prendas.\n",
        "La tendera te mira interrogante.\n", "la tendera se toca el pelo.\n"}));
    AddQuestion(({"pieles","piel","ropa","productos"}), "La peletera te dice: Son de buena"
        " calidad, si quieres pideme la lista y te digo lo que me queda y sus precios.\n");
    SetNoGet("�Eh!, soy muy mayor ya para esas cosas.\n");
    SetCitizenship("nandor");
}
