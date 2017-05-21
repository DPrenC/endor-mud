/****************************************************************************
Fichero: PELETERA_NANDOR.C
Autor: Ratwor
Fecha: 05/11/2006
Descripción: La tendera de la sastrería de Nandor.
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
    SetLong("Esta es Melian, una mujer ya bastante mayor, pues calculas que rondará cerca"
        " de los 60 años. El pelo blanco y largo destaca ante todo del resto de su "
        "anatomía, más incluso que su larga nariz y sus extrañas arrugas del cuello.\n"
        " Lleva su negocio familiar con gran entusiasmo, pues es la herencia de generaciones"
        ", quizá más de las que pueda recordar cualquier habitante de la aldea. Aun así "
        "ella bien se podría haber dedicado a otras labores teniendo en cuenta su robusto"
        " cuerpo, más voluminoso que el de cualquier humana.\n");
    Set(P_CANT_LURE,1);
    SetWeight(85000);
    SetSmell("El olor de las telas con las que trabaja se le ha impregnado en el cuerpo.\n");
    AddSubDetail(({"pelo", "cabello", "pelo blanco", "pelo largo"}), "Una larga cabellera"
        " blanca.\n");
    AddSubDetail(({"cuello","arrugas"}), "Unas extrañas arrugas le llenan el cuello "
        "verticalmente.\n");
    InitAChats(5, ({"La tendera grita horrorizada.\n",
        "La tendera grita: ¡déjame en paz que yo no te he hecho nada!.\n"}));
    InitChats(2,({"La tendera ordena unas prendas.\n",
        "La tendera te mira interrogante.\n", "la tendera se toca el pelo.\n"}));
    AddQuestion(({"pieles","piel","ropa","productos"}), "La peletera te dice: Son de buena"
        " calidad, si quieres pideme la lista y te digo lo que me queda y sus precios.\n");
    SetNoGet("¡Eh!, soy muy mayor ya para esas cosas.\n");
    SetCitizenship("nandor");
}
