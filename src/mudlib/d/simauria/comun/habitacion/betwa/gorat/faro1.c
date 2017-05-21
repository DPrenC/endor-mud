// 03-06-08 [Angor] Rehecha
#include "./path.h"
inherit GORAT("room_base.c");

create () {
    ::create();
    replace_program();
    SetIntShort("el faro de Gorat");
    SetIntLong(
"Te hallas en la parte inferior del faro de Gorat junto a la vieja puerta de "
"madera que permite salir al exterior. El faro es una torre cilíndrica "
"construida con grandes bloques de piedra gris. Unas escaleras de madera "
"apoyadas en salientes de las paredes permiten subir en espiral a su parte "
"superior. Ves arena en los rincones que el viento del golfo que sopla "
"continuamente ha conseguido colar.\n");

AddDetail(({"escaleras","salientes"}),
"Las escaleras de madera permiten el acceso a la parte superior del faro. "
"No tienen barandilla y estan compuestas de secciones rectas que siguen la "
"curva del muro del faro. Sus peldaños son planchas de madera sujetas a dos "
"dos barras paralelas que se encajan unas piezas de madera triangulares "
"sujetas de los salientes que hay en el muro del faro.\n");

AddDetail(({"puerta"}),
"La vieja puerta de madera que permite salir del faro.\n");

AddDetail(({"arena"}),
"Parece que la playa no debe andar lejos...\n");

    AddItem(GORPNJ("farero"),REFRESH_DESTRUCT);
    AddExit("arriba",GORAT("faro2"));
    AddExit("sur",GORAT("mirador") );

    SetIntBright(30);
    SetIndoors(1);
}
