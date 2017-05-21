/****************************************************************************
Fichero: camino36.c
Autor: Ratwor
Fecha: 27/12/2007
Descripción: El camino del norte de Marhalt.
****************************************************************************/

#include "./path.h"

inherit CAMINOS "/norte_marhalt/camino_base";
create(){
    ::create();
    SetIntLong(QueryIntLong()+ "Esta falda norte de la colina tiene una pendiente más "
    "suave, hasta el punto que se puede apreciar lo que parece una senda de acceso "
    "al castillo, algo más hacia el oeste.\n");
    AddDetail(({"Nandor", "aldea", "villa", "nandor"}),
    "Desde tu posición distingues, medio ocultos por la colina, los tejados de la villa "
    "de nandor, que se encuentra cerca, hacia el sureste.\n");
    AddDetail(({"bosque", "bosque de marhalt", "bosque de Marhalt"}),
    "Desde tu posición distingues las verdes copas de los árboles, meciéndose en la "
    "distancia como un verde mar, recortándose contra el cielo y pareciéndo fusionarse "
    "con él.\n");
    AddDetail(({"cored", "Cored"}),
    "El bosque viejo de Cored parece emanar una negrura sobrenatural en el norte. "
    "Es denso y no eres capaz de apreciar ningún detalle a través de su gama de colores "
    "oscuros. Al mirarlo solo puedes sentir intranquilidad.\n");
    AddDetail("arboleda", "La arboleda de marhalt es una gran extensión de terreno "
    "situada al norte de Nandor. Por el este se transforma paulatinamente en el bosque "
    "de Cored, mientras hacia el sureste parece fusionarse con el bosque de Marhalt, "
    "aunque bien puede ser una sensación provocada por la distancia.\n");


    AddExit("noroeste", "./camino37");
    AddExit("nordeste", "./camino35");
}

