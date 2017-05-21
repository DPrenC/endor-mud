/****************************************************************************
Fichero: muralla20.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: En la muralla del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("murallas/muralla_base");

create(){
    ::create();
            SetIntLong("Te encuentras en un recodo de la muralla que sigue al norte hasta el "
    "torre�n de C�nor y al oeste, aunque algo ruinosa y descuidada hasta la torre del "
    "homenaje. Al sureste un bajo arco de piedra da paso al interior de la Torre de "
    "la Dama.\n");
    AddDetail("arco", "Es un bajo arco de piedra toscamente tallado.\n");
    AddDetail("almenas", "Un muro de unos cincuenta cent�metros de espesor que llega a "
    "la altura del pecho de un hombre rematado a intervalos regulares por cortos fustes "
    "cuadrados entre los cuales los defensores se asoman para disparar o derribar a los "
    "asaltantes. A cada pocos metros en la parte baja hay saeteras, estrechas aberturas "
    "mas anchas en la parte interior que en la esterior, utilizadas para disparar desde "
    "una posici�n cubierta o deslizar armas penetrantes como lanzas para ensartar a "
    "cualquier enemigo que trepe por escalas de asalto sin que �ste pueda hacer "
    "nada para evitarlo.\n");
    AddExit("oeste", "./muralla21");
    AddExit("norte", "./muralla19");
    AddExit("sudeste", "./torre3_2");
}


