/****************************************************************************
Fichero: muralla_base.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: El archivo base para la muralla del castillo.
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
    "colocan las m�quinas de guerra, y dem�s armas ofensivas para evitar que el atacante "
    "penetre en la fortaleza. El suelo est� formado por bloques o losas de piedra, no "
    "sabr�as decirlo ya que solo se puede ver la cara superior, pr�cticamente sin alisar "
    "para evitar que la sangre o el agua derramadas lo hagan resbaladizo y alguien "
    "pueda despe�arse por el borde interior carente de barandilla.\n");

    AddDetail("foso", "Te asomas a las almenas para observar el foso. Es una profunda "
    "zanja cabada a los pies de los contrafuertes que sostienen las murallas en cuyo "
    "terroso fondo hay algunos charcos negruzcos de barro malholiente procedente de las "
    "aguas fecales y dem�s desperdicios del castillo. �sta zona ha sido descuidada, "
    "pues sus bordes aparecen desmoronados, las estacas de hierro que rematan el fondo "
    "est�n oxidadas e inclinadas, y en la parte baja crecen algunas plantas rastreras.\n");
    AddDetail(({"estacas", "estaca"}), "Son unas barras de hierro de metro y medio de "
    "longitud que se estrechan desde la base para terminar en punta. Habitualmente este "
    "tipo de defensa se coloca en el fondo de fosos y zanjas defensivas para ensartar a "
    "cualquier hombre o caballo que caiga desde arriba, lo que suele resultar en una "
    "muerte ag�nica y terrible. �stas estacas en particular est�n recubiertas por una "
    "gruesa capa de �xido ya antiguo, aparecido por causa de la humedad y al descuido.\n"
    "Algunas se inclinan precariamente, mientras que otras reposan medio enterradas "
    "en el barro.\n");
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
    AddDetail(({"torre delgada", "torre de la dama", "dama", "torre del sudeste",
        "torre peque�a"}), "La torre de la Dama, algo mas "
    "alta que los torreones y la torre del homenaje, se iergue en la uni�n de las "
    "partes sur y este de las murallas, justo al borde del acantilado cortado a pico "
    "sobre los verdes pastos de Nandor a orillas del r�o.\n"
    "Es una edificaci�n cuadrada y espigada, sirviendo mas como torre de vigilancia que "
    "como parte defensiva. Su construcci�n es algo tosca, no comparable a la de los "
    "grandes torreones y la muralla norte.\n");
    SetIntSmell("Percibes el olor de agua estancada procedente del foso.\n");
    if(d4()==1)
        AddItem(PNJCASTILLO("hombre_armas"), REFRESH_DESTRUCT);
}

