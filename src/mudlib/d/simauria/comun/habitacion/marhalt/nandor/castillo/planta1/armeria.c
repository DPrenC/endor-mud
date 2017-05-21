/****************************************************************************
Fichero: armeria.c
Autor: Ratwor
Fecha: 01/01/2008
Descripción: Una armeria
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
public int espada_cogida;
create(){
    ::create();

    SetIntBright(25);
    SetIntShort("una armería");
    SetIntLong("Te hallas en la armería personal de los Dhes-Bláin, una estancia "
    "pequeña de cuyas paredes cuelgan espadas, escudos, y algunas armaduras. A un lado, "
    "colocadas sobre sendos caballetes hay tres bardas para caballos, y junto "
    "a las armas  cuelgan unos cuantos cinturones, vainas y dos talabartes.\n");
    AddDetail(({"pared", "paredes"}), "La piedra de las paredes está cuidadosamente "
    "pulida, ofreciendo un aspecto menos tosco que la cara exterior del muro de la "
    "torre.\n De la pared del norte cuelgan las espadas, de la del sur las armaduras, "
    "mientras que de la del este y oeste están repartidas el resto de las piezas de equipo.\n");
    AddDetail("pared del norte", "De ella cuelgan relucientes espadas.\n");
    AddDetail("pared del sur", "Algunas piezas de armaduras cuelgan de esta pared.\n");
    AddDetail(({"pared del oeste", "pared del este"}), "Multitud de piezas de equipo "
    "adornan esta pared.\n");
    AddDetail(({"suelo", "emlosado", "losas"}), "El suelo de la torre está hecho de "
    "losas cuadradas bien pulidas y perfectamente encajadas, denotando la importancia "
    "del edificio en el que habita la nobleza.\n");
    AddDetail("escudos", "Grandes escudos con la flor de lis y el mandoble de los "
    "Dhes-Bláin.\n");
    AddDetail("espadas", "En la pared del norte están colgadas algunas espadas largas "
    "de acero y una calidad mayor que las de los simples hombres de armas del castillo.\n");
    AddDetail("bardas", "Son un conjunto de placas de metal y malla con las que se "
    "equipa a los caballos para protegerlos en el combate.\n");
    AddDetail("vainas", "Simples vainas de cuero y metal para envainar las espadas.\n");
    AddDetail("talabartes", "Dos talabartes de cuero, en los cuales se envainan armas "
    "grandes como mandobles, espadones o grandes hachas. Están formados por una serie "
    "de correas que cruzan la espalda y el pecho, con una anilla o tiras de cuero "
    "reforzado para sujetar el arma.\n");
    AddDetail("armaduras", "Cuelgan de la pared separadas unas piezas de otras: "
    "guanteletes, brazales, corazas petos y grebas.\n");
    AddDetail("yelmos", "Varios pesados yelmos cuelgan junto a las corazas.\n");
    AddDetail("cinturones", "Simples cinturones para ceñir la cota demalla o "
    "sostener las armas.\n");
    AddExit("este", "./pasillo5");
    AddDoor("este", "una puerta de madera",
    "Es una puerta de madera para salir de esta estancia.\n",
    ({"puerta", "puerta de madera", "puerta del pasillo", "puerta del este"}));
    SetLocate("el castillo de Nandor");
    AddRoomCmd("descolgar", "cmd_descolgar");
    if(d2()==1) espada_cogida=1;
}

public int cmd_descolgar(string str){
    if(!str || str!="espada de la pared del norte")
        return notify_fail("No descuelgues nada que no es tuyo.\n");
        if(!espada_cogida){
            espada_cogida=1;
            object espada = clone_object(ARMANANDOR("espada_1mano"));
            espada->move(TP);
            write("Con todo el disimulo que tu cuerpo puede ejecutar, descuelgas una de "
            "las espadas de una mano que colgaban de la pared del norte.\n");
            say(CAP(TNAME)+ " parece que ha tocado alguna de las armas, o eso te "
            "ha parecido...\n");
            return 1;
        }
        return notify_fail("No tientes a tu suerte...\n");
}

