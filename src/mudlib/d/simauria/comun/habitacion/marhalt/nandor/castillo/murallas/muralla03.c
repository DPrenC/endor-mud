/****************************************************************************
Fichero: muralla03.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: En la muralla del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("murallas/muralla_base");

create(){
    ::create();
        SetIntLong("Te encuentras en un recodo en el que se unen los dos lienzos de muralla "
    "que protegen el castillo por el norte y el oeste.\n Al noroeste y obstruyendo tu "
    "visi�n hacia el exterior, se encuentra el torre�n de la Inmolaci�n, al cual se "
    "accede por un alto arco de piedra.\n Desde aqu� puedes ver el patio de armas, la "
    "torre del homenaje que se levanta bastante al sur, mientras que hacia el este la "
    "muralla de aspecto mas s�lido se extiende hasta las puertas y mas all� hasta el "
    "torre�n de C�nor, en el extremo oriental de la muralla norte.\n");
    AddDetail("arco", "Es bastante alto y ancho, permitiendo el paso de dos hombres a "
    "la par,  y est� rodeado de elaboradas tallas geom�tricas y algunos s�mbolos "
    "borrados por el paso del tiempo. Mir�ndolos mas de cerca, te parece descubrir la "
    "forma muy esquem�tica de un yelmo alado.\n");
    AddDetail("puertas", "Las puertas del castillo se sit�an justo en el centro de la "
    "muralla norte. Se adelantan ligeramente con respecto a la muralla, y la parte alta "
    "est� defendida por una garita volada a cada lado, lo que les da un aspecto de "
    "gran solidez.\n");

    AddDetail("almenas", "Un muro de unos cincuenta cent�metros de espesor que llega a "
    "la altura del pecho de un hombre rematado a intervalos regulares por cortos fustes "
    "cuadrados entre los cuales los defensores se asoman para disparar o derribar a los "
    "asaltantes. A cada pocos metros en la parte baja hay saeteras, estrechas aberturas "
    "mas anchas en la parte interior que en la esterior, utilizadas para disparar desde "
    "una posici�n cubierta o deslizar armas penetrantes como lanzas para ensartar a "
    "cualquier enemigo que trepe por escalas de asalto sin que �ste pueda hacer "
    "nada para evitarlo.\n");
    AddExit("este", "./muralla04");
    AddExit("sur", "./muralla02");
    AddExit("noroeste", "./torre1_05");
}


