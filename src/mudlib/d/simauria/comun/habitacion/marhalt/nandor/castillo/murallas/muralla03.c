/****************************************************************************
Fichero: muralla03.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: En la muralla del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("murallas/muralla_base");

create(){
    ::create();
        SetIntLong("Te encuentras en un recodo en el que se unen los dos lienzos de muralla "
    "que protegen el castillo por el norte y el oeste.\n Al noroeste y obstruyendo tu "
    "visión hacia el exterior, se encuentra el torreón de la Inmolación, al cual se "
    "accede por un alto arco de piedra.\n Desde aquí puedes ver el patio de armas, la "
    "torre del homenaje que se levanta bastante al sur, mientras que hacia el este la "
    "muralla de aspecto mas sólido se extiende hasta las puertas y mas allá hasta el "
    "torreón de Cónor, en el extremo oriental de la muralla norte.\n");
    AddDetail("arco", "Es bastante alto y ancho, permitiendo el paso de dos hombres a "
    "la par,  y está rodeado de elaboradas tallas geométricas y algunos símbolos "
    "borrados por el paso del tiempo. Mirándolos mas de cerca, te parece descubrir la "
    "forma muy esquemática de un yelmo alado.\n");
    AddDetail("puertas", "Las puertas del castillo se sitúan justo en el centro de la "
    "muralla norte. Se adelantan ligeramente con respecto a la muralla, y la parte alta "
    "está defendida por una garita volada a cada lado, lo que les da un aspecto de "
    "gran solidez.\n");

    AddDetail("almenas", "Un muro de unos cincuenta centímetros de espesor que llega a "
    "la altura del pecho de un hombre rematado a intervalos regulares por cortos fustes "
    "cuadrados entre los cuales los defensores se asoman para disparar o derribar a los "
    "asaltantes. A cada pocos metros en la parte baja hay saeteras, estrechas aberturas "
    "mas anchas en la parte interior que en la esterior, utilizadas para disparar desde "
    "una posición cubierta o deslizar armas penetrantes como lanzas para ensartar a "
    "cualquier enemigo que trepe por escalas de asalto sin que éste pueda hacer "
    "nada para evitarlo.\n");
    AddExit("este", "./muralla04");
    AddExit("sur", "./muralla02");
    AddExit("noroeste", "./torre1_05");
}


