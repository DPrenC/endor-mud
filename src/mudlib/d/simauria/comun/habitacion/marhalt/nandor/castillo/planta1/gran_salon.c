/****************************************************************************
Fichero: gran_salon.c
Autor: Ratwor
Fecha: 01/01/2008
Descripción: El gran salón donde se encuentra el noble.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
public string mirar_defecto();
create(){
    ::create();
    SetIntBright(40);
    SetIntShort("el gran salón");
    SetIntLong("En esta parte del salón hay un estrado de madera sobre el que suele "
    "levantarse la mesa principal durante los banquetes, aunque en estos momentos "
    "solo hay una silla tallada de alto respaldo. Tapices con escenas de antiguas "
    "batallas cuelgan de las paredes y tras el estrado un gran estandarte muestra "
    "las insignias de la casa Dhes-Bláin. Justo debajo, una lanza larga ocupa parte "
    "de la pared. El suelo está cubierto de juncos.\n");
    AddDetail("estrado", "Una baja tarima de madera que ocupa el fondo del salón.\n");
    AddDetail(({"silla", "silla tallada", "silla tallada de alto respaldo"}),
    "Una enorme silla de respaldo muy alto, y amplios brazos desde la que "
    "el señor del castillo preside banquetes y audiencias. Toda su superficie "
    "muestra elaboradas tallas y relieves.\n");
    AddDetail("estandarte", "El estandarte desplegado sobre el muro muestra un "
    "mandoble en campo marrón verdoso sobre cuyo pomo hay una flor de lis dorada.\n");
    AddDetail("lanza", "Es la lanza que los Dhes-Bláin usan cuando acuden montados a la "
    "batalla. La punta está pulida y bien afilada, y la parte posterior del mango "
    "tras la cazoleta de metal trabajado que protege la mano está recubierta de cuero "
    "blando.\n");
    AddDetail("tapices", "Los tres tapices de esta zona del salón son mas lujosos y están "
    "mejor bordados, con brillantes colores que causan un efecto muy realista en las "
    "escenas de batallas que representan.\n");
    AddDetail(({"tapiz 1", "tapiz uno"}),
    "Representa a un poderoso guerrero con armadura completa que  "
    "empuña el mandoble de los Dhes-Bláin acompañado por unos cuantos hombres de armas "
    "ataviados con cota de malla y armados de alabardas, espadas y lanzas. Están "
    "reunidos sobre un túmulo en ruinas, rodeando el estandarte del señorío, mientras "
    "una horda de orcos embutidos en hierro los acosan con salvajes cimitarras, hachas "
    "y porras erizadas de pinchos.\n");
    AddDetail(({"tapiz 2", "tapiz dos"}),
    "Éste magnífico tapiz muestra un campo de batalla devastado "
    "en el centro del cual un enorme guerrero de pelo y barba oscuros y erizados "
    "ataviado con pieles apoya el pie derecho sobre el pecho de un cuerpo decapitado "
    "cubierto con armadura negra. En la mano izquierda lleva la cabeza de un ser de "
    "rasgos demoniacos y en la derecha sujeta descuidadamente un  hacha cubierta de "
    "gotas oscuras. El rostro barbudo y feroz alzado hacia el cielo encapotado emite un "
    "silencioso grito de victoria.\n");
    AddDetail(({"tapiz 3", "tapiz tres"}),
    "Este amplio tapiz muestra el vado de un río en el cual se "
    "desarrolla una sangrienta batalla. De un lado hay una columna de guerreros "
    "cubiertos por armaduras negras y rojas grabadas con runas y rostros diabólicos, "
    "dirigidos por un demonio alado. A su alrrededor se amontonan ogros de cara "
    "aplastada, kainoaks de ojos inexpresivos, y media docena de trolls. Una horda "
    "harapienta de kobolds y goblins se amontonan en retaguardia, rodeando un par de "
    "gigantes que se disponen a arrojar sendos peñascos sobre los defensores del vado.\n"
    "Hundido hasta la cintura en el centro de la corriente, un caudillo vestido con la "
    "armadura de los Dhes-Bláin y la cabeza descubierta pelea con su mandoble codo con "
    "codo con un altivo señor de aspecto noble ataviado con magnífica armadura de "
    "malla, manto oscuro bordado en plata y  cuyo  alto yelmo alado sobresale entre la "
    "multitud de guerreros. A su alrrededor se distinguen tres clases de combatientes: "
    "hombres de aspecto rudo ataviados con pieles, una falange de nobles soldados "
    "vestidos de negro y plata y tocados con cascos alados, y un grupo poco numeroso "
    "de guerreros armados de arcos largos y largas espadas, vestidos de verde y "
    "castaño con las capuchas cubriendoles el rostro.\n"
    "Todas y cada una de los centenares de figuras bordadas en el tapiz, están "
    "realizadas con gran perfección y colorido, cuidándose hasta el último detalle.\n"
    "Aún así, hay algo que no parece encajar, quizás algún defecto que nadie pasaría "
    "por alto en un segundo vistazo.\n");
    AddDetail(({"defecto de tapiz", "defecto"}), SF(mirar_defecto));
    AddDetail(({"suelo", "juncos"}), "Una capa de juncos cubre el suelo de piedra y, "
    "a pesar de que suelen cambiarse a menudo, algún que otro excremento de perro  o "
    "hueso roído se ve aquí y allí.\n");
    AddDetail("pilares", "Sencillos pilares de piedra sin talla alguna que sostienen el "
    "techo del salón.\n");
    AddExit("este", "./salon_recepcion");
    AddItem(PNJCASTILLO("noble_nandor"), REFRESH_DESTRUCT);
    AddItem(PNJCASTILLO("guardia_noble"), REFRESH_DESTRUCT, 2);
    AddItem(PNJCASTILLO("ujier_castillo"), REFRESH_DESTRUCT);
    SetLocate("el castillo de Nandor");
}


public string mirar_defecto(){
    TP->SetExplored();
    return "Te acercas al tapiz y tras "
    "examinarlo detenidamente descubres una vaga figura entre los hombres vestidos de "
    "verde y castaño. Los hilos que la conforman parecen haber sido cortados y "
    "remendados, tratando de cambiar su aspecto, aunque el resultado ha sido poco "
    "satisfactorio. Puedes ver lo que parece un brazo extendido cuya mano sujeta algo "
    "que podría ser una vara o una espada, aunque la parte que sobresale de los dedos "
    "ha sido eliminada. Parece haber sido un guerrero mas bajo y ligero que los que "
    "lo rodean, aunque poco mas se puede deducir pues los rasgos del rostro están "
    "deshechos y recosidos. Quizás alguien el castillo sepa algo mas sobre este tapiz "
    "y la razón por la que ha sido manipulado.\n";
}
