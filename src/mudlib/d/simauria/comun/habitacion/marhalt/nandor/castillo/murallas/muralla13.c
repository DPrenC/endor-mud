/****************************************************************************
Fichero: muralla13.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: En la muralla del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("murallas/muralla_base");

create(){
    ::create();
            SetIntLong("Te encuentras en un recodo en el que se unen los dos lienzos de muralla "
    "que protegen el castillo por el norte y el este. Al noreste y obstruyendo tu "
    "visión hacia el exterior, se encuentra el torreón de Cónor, al cual se "
    "accede por un alto arco de piedra. Desde aquí puedes ver el patio de armas, la "
    "torre de la Dama que se levanta bastante al sur, mientras que hacia el oeste la "
    "muralla de aspecto mas sólido se extiende hasta las puertas y mas allá hasta el "
    "torreón de la Inmolación, en el extremo occidental de la muralla norte.\n");
    AddDetail("arco", "Es bastante alto y ancho, permitiendo el paso de dos hombres a "
    "la par.\n Está rodeado de elaboradas tallas geométricas y algunos símbolos "
    "borrados por el paso del tiempo. Mirándolos mas de cerca, te parece descubrir la "
    "forma muy esquemática de un yelmo alado.\n");
    AddDetail("puertas", "Las puertas del castillo se sitúan justo en el centro de la "
    "muralla norte. Se adelantan ligeramente con respecto a la muralla, y la parte alta "
    "está defendida por una garita volada a cada lado, lo que les da un aspecto de "
    "gran solidez.\n");
    AddDetail(({"torreón", "torreón de Cónor", "torreón de cónor", "cónor"}),
    "El torreón de Cónor recibe éste nombre en honor al famoso héroe que inició la "
    "línea Desh'Blain.\n"
    "Está construído en forma cilíndrica para evitar los puntos débiles ofrecidos en las "
    "torres con esquinas que al ser derrumbadas ocasionan la ruina de toda la "
    "fortificación, y con el objetivo de dotar a la estructura de mas resistencia al "
    "estar repartido por igual el peso sobre la obra exterior. Se apoya sobre "
    "robustos contrafuertes, una especie de cortos muros laterales de no mas de un "
    "metro de anchura que se van estrechando hacia arriba. Unas angostas aspilleras "
    "oradadas a lo largo de los muros proporcionan puntos de vigilancia y disparo a los "
    "defensores. La parte superior está protegida por almenas algo sobresalientes, "
    "apoyadas sobre una serie de gradas invertidas, de forma que la parte superior del "
    "torreón es mas amplia que el cuerpo propiamente dicho.\n");
    AddDetail("almenas", "Un muro de unos cincuenta centímetros de espesor que llega a "
    "la altura del pecho de un hombre rematado a intervalos regulares por cortos fustes "
    "cuadrados entre los cuales los defensores se asoman para disparar o derribar a los "
    "asaltantes. A cada pocos metros en la parte baja hay saeteras, estrechas aberturas "
    "mas anchas en la parte interior que en la esterior, utilizadas para disparar desde "
    "una posición cubierta o deslizar armas penetrantes como lanzas para ensartar a "
    "cualquier enemigo que trepe por escalas de asalto sin que éste pueda hacer "
    "nada para evitarlo.\n");

    AddExit("sur", "./muralla14");
    AddExit("oeste", "./muralla12");
    AddExit("nordeste", "./torre2_08");
}


