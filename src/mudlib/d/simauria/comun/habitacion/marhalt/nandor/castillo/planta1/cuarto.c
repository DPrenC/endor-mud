/****************************************************************************
Fichero: despensa1.c
Autor: Ratwor
Fecha: 01/01/2008
Descripción: La despensa del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntBright(25);
    SetIntShort("un cuarto");
    SetIntLong("Te encuentras en un cuarto sin ventanas, de forma cuadrada y aspecto "
    "humilde. El mobiliario se limita a una serie de camastros alineados junto a las "
    "paredes. Parece ser una habitación para la servidumbre o  los guardias escogidos "
    "del señor, aunque ningún detalle permite saberlo.\n");
    AddDetail("camastros", "Unos pobres camastros con colchón de paja y una manta de "
    "lana sucia.\n");
    AddDetail(({"pared", "paredes"}), "La piedra de las paredes está cuidadosamente "
    "pulida, ofreciendo un aspecto menos tosco que la cara exterior del muro de la torre.\n");
    AddDetail(({"suelo", "emlosado", "losas"}), "El suelo de la torre está hecho de "
    "losas cuadradas bien pulidas y perfectamente encajadas, denotando la importancia "
    "del edificio en el que habita la nobleza.\n");
    AddExit("sur", "./pasillo1");
    AddDoor("sur", "una puerta de madera",
    "Es una puerta de madera para salir de este cuarto.\n",
    ({"puerta", "puerta de madera", "puerta del pasillo", "puerta del sur"}));
    SetLocate("el castillo de Nandor");
}
