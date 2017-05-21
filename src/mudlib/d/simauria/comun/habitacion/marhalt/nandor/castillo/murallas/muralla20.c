/****************************************************************************
Fichero: muralla20.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: En la muralla del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("murallas/muralla_base");

create(){
    ::create();
            SetIntLong("Te encuentras en un recodo de la muralla que sigue al norte hasta el "
    "torreón de Cónor y al oeste, aunque algo ruinosa y descuidada hasta la torre del "
    "homenaje. Al sureste un bajo arco de piedra da paso al interior de la Torre de "
    "la Dama.\n");
    AddDetail("arco", "Es un bajo arco de piedra toscamente tallado.\n");
    AddDetail("almenas", "Un muro de unos cincuenta centímetros de espesor que llega a "
    "la altura del pecho de un hombre rematado a intervalos regulares por cortos fustes "
    "cuadrados entre los cuales los defensores se asoman para disparar o derribar a los "
    "asaltantes. A cada pocos metros en la parte baja hay saeteras, estrechas aberturas "
    "mas anchas en la parte interior que en la esterior, utilizadas para disparar desde "
    "una posición cubierta o deslizar armas penetrantes como lanzas para ensartar a "
    "cualquier enemigo que trepe por escalas de asalto sin que éste pueda hacer "
    "nada para evitarlo.\n");
    AddExit("oeste", "./muralla21");
    AddExit("norte", "./muralla19");
    AddExit("sudeste", "./torre3_2");
}


