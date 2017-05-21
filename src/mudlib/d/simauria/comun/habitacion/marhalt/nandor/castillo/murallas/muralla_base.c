/****************************************************************************
Fichero: muralla_base.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: El archivo base para la muralla del castillo.
****************************************************************************/
#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntShort("la muralla");
    SetIndoors(0);
    SetLocate("el castillo de Nandor");
    AddDetail(({"adarbe", "suelo"}), "El adarbe es la parte superior de la muralla, un "
    "paso ancho de piso firme por el que se desplazan las tropas defensoras y donde se "
    "colocan las máquinas de guerra, y demás armas ofensivas para evitar que el atacante "
    "penetre en la fortaleza. El suelo está formado por bloques o losas de piedra, no "
    "sabrías decirlo ya que solo se puede ver la cara superior, prácticamente sin alisar "
    "para evitar que la sangre o el agua derramadas lo hagan resbaladizo y alguien "
    "pueda despeñarse por el borde interior carente de barandilla.\n");

    AddDetail("foso", "Te asomas a las almenas para observar el foso. Es una profunda "
    "zanja cabada a los pies de los contrafuertes que sostienen las murallas en cuyo "
    "terroso fondo hay algunos charcos negruzcos de barro malholiente procedente de las "
    "aguas fecales y demás desperdicios del castillo. Ésta zona ha sido descuidada, "
    "pues sus bordes aparecen desmoronados, las estacas de hierro que rematan el fondo "
    "están oxidadas e inclinadas, y en la parte baja crecen algunas plantas rastreras.\n");
    AddDetail(({"estacas", "estaca"}), "Son unas barras de hierro de metro y medio de "
    "longitud que se estrechan desde la base para terminar en punta. Habitualmente este "
    "tipo de defensa se coloca en el fondo de fosos y zanjas defensivas para ensartar a "
    "cualquier hombre o caballo que caiga desde arriba, lo que suele resultar en una "
    "muerte agónica y terrible. Éstas estacas en particular están recubiertas por una "
    "gruesa capa de óxido ya antiguo, aparecido por causa de la humedad y al descuido.\n"
    "Algunas se inclinan precariamente, mientras que otras reposan medio enterradas "
    "en el barro.\n");
    AddDetail("patio", "El patio de armas es un amplio espacio empedrado delimitado por "
    "las murallas y la torre del homenaje. En él se sitúa el pozo, la entrada a los "
    "diferentes edificios auxiliares como la herrería y las caballerizas y los accesos "
    "a murallas y torres. En él se entrenan las tropas del señor, los arqueros afinan su "
    "puntería en las dianas y los pocos hombres que combaten a caballo ejercitan sus "
    "habilidades con el estafermo.\n");
    AddDetail(({"torre", "torre del homenaje", "homenaje"}), "La torre del homenaje es "
    "el edificio mas importante del castillo y donde se hallan las dependencias "
    "principales y habita el señor. También es el mejor construído, mejor defendido y "
    "normalmente es la última parte de la fortaleza en caer en caso de ataque.\n"
    "ES una gran construcción de planta cuadrada, que forma el ángulo sudoccidental del "
    "recinto amurallado, levantado justo en el borde del acantilado que corta la colina "
    "por el sur, y sobresaliendo ligeramente hacia el oeste con respecto a la muralla "
    "occidental. Sus muros construídos con bloques rectangulares de piedra de gran "
    "tamaño, su amplio tejado de pizarra bordeado por gárgolas desgastadas por el "
    "tiempo, las tres chimeneas que lo coronan junto con la pequeña plataforma almenada "
    "de la cúspide y las trabajadas ventanas ojibales que dan al patio de armas le "
    "proporcionan un aspecto de robustez e inexpugnabilidad.\n");
    AddDetail(({"torreón del noroeste", "inmolación", "Inmolación", "torreón de la inmolación",
        "torreon del noroeste", "inmolacion", "Inmolacion", "torreon de la inmolacion"}),
    "El torreón de la Inmolación, situado en la esquina noroeste de la fortaleza, recibe"
    " éste nombre por cierto acontecimiento ocurrido en uno de los múltiples asedios "
    "sufridos por este castillo.\n Está construído en forma cilíndrica para evitar los "
    "puntos débiles ofrecidos en las torres con esquinas que al ser derrumbadas "
    "ocasionan la ruina de toda la fortificación, y con el objetivo de dotar a la "
    "estructura de mas resistencia al estar repartido por igual el peso sobre la obra "
    "exterior. Se apoya sobre robustos contrafuertes, una especie de cortos muros "
    "laterales de no mas de un metro de anchura que se van estrechando hacia arriba. "
    "Unas angostas aspilleras oradadas a lo largo de los muros proporcionan puntos de "
    "vigilancia y disparo a los defensores. La parte superior está protegida por "
    "almenas algo sobresalientes, apoyadas sobre una serie de gradas invertidas, de "
    "forma que la parte superior del torreón es mas amplia que el cuerpo propiamente dicho.\n");
    AddDetail(({"torreón del nordeste", "torreón de Cónor", "torreón de cónor", "cónor",
        "torreon del nordeste", "torreon de Cónor", "torreon de cónor", "cónor"}),
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
    AddDetail(({"torre delgada", "torre de la dama", "dama", "torre del sudeste",
        "torre pequeña"}), "La torre de la Dama, algo mas "
    "alta que los torreones y la torre del homenaje, se iergue en la unión de las "
    "partes sur y este de las murallas, justo al borde del acantilado cortado a pico "
    "sobre los verdes pastos de Nandor a orillas del río.\n"
    "Es una edificación cuadrada y espigada, sirviendo mas como torre de vigilancia que "
    "como parte defensiva. Su construcción es algo tosca, no comparable a la de los "
    "grandes torreones y la muralla norte.\n");
    SetIntSmell("Percibes el olor de agua estancada procedente del foso.\n");
    if(d4()==1)
        AddItem(PNJCASTILLO("hombre_armas"), REFRESH_DESTRUCT);
}

