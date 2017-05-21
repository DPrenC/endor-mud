/****************************************************************************
Fichero: alto_torre.c
Autor: Ratwor
Fecha: 01/04/2008
Descripción: un archivo base para lo alto de las 3 torres del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();

    SetIndoors(0);
    SetLocate("el castillo de Nandor");
    AddDetail(({"alrededores", "los alrededores", "el entorno", "entorno"}), 
    "Hechas un vistazo alrededor, disfrutando de las amplias vistas que se te ofrecen. "
    "Allá abajo al sur, la línea del río Kandal bordea los pastos de la aldea de "
    "Nandor situada al este, a la sombra de la colina sobre la que se alza el "
    "castillo rodeado por un profundo foso.\n");
    AddDetail("castillo", "El castillo de Nandor se extiende al norte y al oeste de tu "
    "posición, con las grandes murallas y puertas defendidas por el torreón de Cónor y "
    "el torreón de la Inmolación, con la torre del Homenaje alzándose al oeste. Todo el "
    "conjunto rodea el patio de armas.\n");
    AddDetail("cobertizos", "Una hilera de cobertizos adosados a la muralla oriental.\n");
    AddDetail("caballerizas", "Un amplio cobertizo de paredes de piedra y techo de "
    "pizarra donde se guardan las monturas de los Dhes-Bláin.\n");
    AddDetail("pozo", "Es el pozo que proporciona agua al castillo.\n");
    AddDetail("escalera", "Una empinada escalera de piedra con algunos escalones a "
    "medio derrumbar que une el patio de armas con la muralla sur.\n");
    AddDetail(({"murallas", "muralla"}), "Las fuertes murallas que protegen el castillo "
    "cercan el patio de armas por tres de sus lados, alzándose en hileras de grandes "
    "bloques de piedra cada una de las cuales se apoya sobre otras dos, haciendo el "
    "muro mas resistente y evitando que se derrumbe por el peso. Una escalera une el "
    "patio con la parte sur de la muralla.\n");
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
    "diferentes edificios auxiliares como las caballerizas y los accesos "
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
    AddDetail("almenas", "Un muro de unos cincuenta centímetros de espesor que llega a "
    "la altura del pecho de un hombre rematado a intervalos regulares por cortos fustes "
    "cuadrados entre los cuales los defensores se asoman para disparar o derribar a los "
    "asaltantes.\n");
    AddDetail(({"río", "rio", "kandal", "Kandal", "río Kandal"}),
    "El río Kandal procedente del este, limita por el sur las tierras de Nandor, "
    "dirigiéndose hacia el mar al oeste. En su orilla sur se extiende el jóven bosque "
    "de Marhalt, en el que los animales de caza abundan, y un territorio montañoso, "
    "deshabitado y salvaje.\n");
    AddDetail("pastos", "Al pie de la pared de la colina sobre la que se alza el "
    "castillo, se extiende una pradera larga y estrecha que desciende suavemente hasta "
    "la baja orilla del río. Es allí donde los aldeanos de Nandor apacentan sus escasos "
    "animales.\n");
    AddDetail("riscos", "La orilla sur del río Kandal se levanta en una serie de "
    "terrazas y riscos hasta las grandes peñas y barrancos que forman un terreno "
    "anfractuoso y de dificil acceso, en el que nadie suele aventurarse, pues es "
    "imposible precisar que clase de criaturas podrían vivir en tales baldíos.\n");
   AddDetail(({"aldea", "nandor", "Nandor", "villa"}), "Al este del castillo y al "
    "pie de la colina, se encuentra la pequeña aldea de Nandor, un conjunto de "
    "humildes moradas que rodean la casa de tributos y el pequeño templo. Al norte se "
    "extiende una arboleda, al sur el río Kandal y el bosque de Marhalt, y al "
    "este un viejo cementerio.\n");
    AddDetail("puertas", "Las puertas del castillo se sitúan justo en el centro de la "
    "muralla norte. Se adelantan ligeramente con respecto a la muralla, y la parte alta "
    "está defendida por una garita volada a cada lado, lo que les da un aspecto de "
    "gran solidez.\n");
    AddDetail(({"torreón", "torreón de Cónor", "torreón de cónor", "cónor"}),
    "El torreón de Cónor recibe éste nombre en honor al famoso héroe que inició la "
    "línea Desh-Blain.\n"
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
    AddDetail(({"bosque", "bosque de Cored", "bosque de cored"}),
    "Al norte del camino de Marhalt, se extiende el bosque de "
    "Cored, una oscura masa de añosos árboles de aspecto ominoso.\n");
    AddDetail("foso", "Un profundo foso erizado de estacas que jalona las murallas del "
    "castillo.\n");

    AddDetail("estandarte", "Izado sobre su mástil, el estandarte de los Dhes-Bláin "
    "con el mandoble y la flor de lis bordados en hilo de oro sobre campo marrón verdoso, "
    "ondea sobre el castillo de Nandor.\n");
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

    if(d6()==1)
        AddItem(PNJCASTILLO("hombre_armas"), REFRESH_DESTRUCT);
    }


