/****************************************************************************
Fichero: patio_base.c
Autor: Ratwor
Fecha: 28/12/2007
Descripci�n: El archivo base para el patio del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntShort("el patio de armas");
    SetIntLong("El patio de armas es un espacio existente entre las murallas del "
    "castillo, y desde el que se accede a los edificios principales. El suelo est� "
    "conformado por un empedrado de superficies redondeadas, algo tosco pero que evita "
    "resbalones a las monturas.\n");
    AddDetail(({"murallas", "muralla", "muro", "pared", "paredes"}),
    "Las fuertes murallas que protegen el castillo "
    "cercan el patio de armas por tres de sus lados, alz�ndose en hileras de grandes "
    "bloques de piedra cada una de las cuales se apoya sobre otras dos, haciendo el "
    "muro mas resistente y evitando que se derrumbe por el peso.\n");
    AddDetail("patio", "El patio de armas es un amplio espacio empedrado delimitado por "
    "las murallas y la torre del homenaje. En �l se sit�a el pozo, la entrada a los "
    "diferentes edificios auxiliares como la herrer�a y las caballerizas y los accesos "
    "a murallas y torres. En �l se entrenan las tropas del se�or, los arqueros afinan su "
    "punter�a en las dianas y los pocos hombres que combaten a caballo ejercitan sus "
    "habilidades con el estafermo.\n");
        AddDetail(({"torre", "torre del homenaje", "homenaje"}), "La torre del homenaje es "
    "el edificio mas importante del castillo y donde se hallan las dependencias "
    "principales y habita el se�or. Tambi�n es el mejor constru�do, mejor defendido y "
    "normalmente es la �ltima parte de la fortaleza en caer en caso de ataque.\n"
    "ES una gran construcci�n de planta cuadrada, que forma el �ngulo sudoccidental del "
    "recinto amurallado, levantado justo en el borde del acantilado que corta la colina "
    "por el sur, y sobresaliendo ligeramente hacia el oeste con respecto a la muralla "
    "occidental. Sus muros constru�dos con bloques rectangulares de piedra de gran "
    "tama�o, su amplio tejado de pizarra bordeado por g�rgolas desgastadas por el "
    "tiempo, las tres chimeneas que lo coronan junto con la peque�a plataforma almenada "
    "de la c�spide y las trabajadas ventanas ojibales que dan al patio de armas le "
    "proporcionan un aspecto de robustez e inexpugnabilidad.\n");
    AddDetail(({"torre�n del noroeste", "inmolaci�n", "Inmolaci�n", "torre�n de la inmolaci�n",
        "torreon del noroeste", "inmolacion", "Inmolacion", "torreon de la inmolacion"}),
    "El torre�n de la Inmolaci�n, situado en la esquina noroeste de la fortaleza, recibe"
    " �ste nombre por cierto acontecimiento ocurrido en uno de los m�ltiples asedios "
    "sufridos por este castillo.\n Est� constru�do en forma cil�ndrica para evitar los "
    "puntos d�biles ofrecidos en las torres con esquinas que al ser derrumbadas "
    "ocasionan la ruina de toda la fortificaci�n, y con el objetivo de dotar a la "
    "estructura de mas resistencia al estar repartido por igual el peso sobre la obra "
    "exterior. Se apoya sobre robustos contrafuertes, una especie de cortos muros "
    "laterales de no mas de un metro de anchura que se van estrechando hacia arriba. "
    "Unas angostas aspilleras oradadas a lo largo de los muros proporcionan puntos de "
    "vigilancia y disparo a los defensores. La parte superior est� protegida por "
    "almenas algo sobresalientes, apoyadas sobre una serie de gradas invertidas, de "
    "forma que la parte superior del torre�n es mas amplia que el cuerpo propiamente dicho.\n");
    AddDetail(({"torre�n del nordeste", "torre�n de C�nor", "torre�n de c�nor", "c�nor",
        "torreon del nordeste", "torreon de C�nor", "torreon de c�nor", "c�nor"}),
    "El torre�n de C�nor recibe �ste nombre en honor al famoso h�roe que inici� la "
    "l�nea Desh'Blain.\n"
    "Est� constru�do en forma cil�ndrica para evitar los puntos d�biles ofrecidos en las "
    "torres con esquinas que al ser derrumbadas ocasionan la ruina de toda la "
    "fortificaci�n, y con el objetivo de dotar a la estructura de mas resistencia al "
    "estar repartido por igual el peso sobre la obra exterior. Se apoya sobre "
    "robustos contrafuertes, una especie de cortos muros laterales de no mas de un "
    "metro de anchura que se van estrechando hacia arriba. Unas angostas aspilleras "
    "oradadas a lo largo de los muros proporcionan puntos de vigilancia y disparo a los "
    "defensores. La parte superior est� protegida por almenas algo sobresalientes, "
    "apoyadas sobre una serie de gradas invertidas, de forma que la parte superior del "
    "torre�n es mas amplia que el cuerpo propiamente dicho.\n");
    AddDetail(({"torre delgada", "torre de la dama", "dama"}), "La torre de la Dama, algo mas "
    "alta que los torreones y la torre del homenaje, se iergue en la uni�n de las "
    "partes sur y este de las murallas, justo al borde del acantilado cortado a pico "
    "sobre los verdes pastos de Nandor a orillas del r�o.\n"
    "Es una edificaci�n cuadrada y espigada, sirviendo mas como torre de vigilancia que "
    "como parte defensiva. Su construcci�n es algo tosca, no comparable a la de los "
    "grandes torreones y la muralla norte.\n");
    SetIndoors(0);
    SetLocate("el castillo de Nandor");
    if(d6()==1)
        AddItem(PNJCASTILLO("hombre_armas"), REFRESH_DESTRUCT);
    if(d6()==1)
        AddItem(PNJCASTILLO("hombre_armas1"), REFRESH_DESTRUCT);
}


