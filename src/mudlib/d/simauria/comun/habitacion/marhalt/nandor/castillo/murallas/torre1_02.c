/****************************************************************************
Fichero: torre1_02.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: la torre noroeste del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("los barracones de la guarnición");
    SetIntLong("Te encuentras en una estancia bastante grande que ocupa toda la mitad "
    "norte de la planta baja del torreón de la Inmolación. Es aquí donde la guarnición del "
    "castillo tiene sus humildes jergones de paja alineados junto a las paredes. El lugar "
    "resulta  desagradable debido a la suciedad acumulada por muchas personas ocupando "
    "el mismo espacio, situación agravada con la ESCASA ventilación proporcionada por "
    "algunas aspilleras situadas en lo alto del muro exterior, y la poca iluminación del "
    "lugar.\n Los barracones continúan hacia el oeste.\n");
    AddDetail(({"jergones", "jergon", "jergón"}),
    "Los jergones son amasijos de paja embutidos en mugrientas fundas de tela "
    "o arpillera. Muchos de ellos están rajados, rotos o medio vacíos, con lo que no "
    "deben de ofrecer un cómodo descanso.\n");
    AddDetail("aspilleras", "Estrechas aberturas situadas en la zona alta del muro "
    "exterior, cuyo grosor solo permite colarse una leve luminosidad.\n");
    AddDetail("suelo", "El suelo está formado por pesadas losas de piedra perfectamente "
    "encajadas entre sí.\n");
    AddDetail(({"paredes", "muros"}), "Se percibe la diferencia entre el muro exterior "
    "del torreón, mas grueso, y construído con bloques mucho mas grandes que los de los "
    "tabiques que lo dividen.\n");
    AddDetail("bloques", "Grandes bloques de piedra que forman los muros.\n");
    AddDetail("antorchas", "Antorchas encajadas en soportes de hierro sujetos a la pared.\n");
    SetIntSmell("Huele a el inconfundible hedor de muchos cuerpos apiñados.\n");

    SetIntBright(20);

    AddExit("sur", "./torre1_01");
    AddExit("oeste", "./torre1_03");
    AddDoor("sur", "una puerta de madera",
    "Es una puerta vieja de madera sin ningún dibujo ni relieve, por ahí se sale de "
    "los barracones.\n",
    ({"puerta", "puerta del sur", "puerta de madera"}));

    SetLocate("el castillo de Nandor");
}

