/****************************************************************************
Fichero: torre1_02.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: la torre noroeste del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("los barracones de la guarnici�n");
    SetIntLong("Te encuentras en una estancia bastante grande que ocupa toda la mitad "
    "norte de la planta baja del torre�n de la Inmolaci�n. Es aqu� donde la guarnici�n del "
    "castillo tiene sus humildes jergones de paja alineados junto a las paredes. El lugar "
    "resulta  desagradable debido a la suciedad acumulada por muchas personas ocupando "
    "el mismo espacio, situaci�n agravada con la ESCASA ventilaci�n proporcionada por "
    "algunas aspilleras situadas en lo alto del muro exterior, y la poca iluminaci�n del "
    "lugar.\n Los barracones contin�an hacia el oeste.\n");
    AddDetail(({"jergones", "jergon", "jerg�n"}),
    "Los jergones son amasijos de paja embutidos en mugrientas fundas de tela "
    "o arpillera. Muchos de ellos est�n rajados, rotos o medio vac�os, con lo que no "
    "deben de ofrecer un c�modo descanso.\n");
    AddDetail("aspilleras", "Estrechas aberturas situadas en la zona alta del muro "
    "exterior, cuyo grosor solo permite colarse una leve luminosidad.\n");
    AddDetail("suelo", "El suelo est� formado por pesadas losas de piedra perfectamente "
    "encajadas entre s�.\n");
    AddDetail(({"paredes", "muros"}), "Se percibe la diferencia entre el muro exterior "
    "del torre�n, mas grueso, y constru�do con bloques mucho mas grandes que los de los "
    "tabiques que lo dividen.\n");
    AddDetail("bloques", "Grandes bloques de piedra que forman los muros.\n");
    AddDetail("antorchas", "Antorchas encajadas en soportes de hierro sujetos a la pared.\n");
    SetIntSmell("Huele a el inconfundible hedor de muchos cuerpos api�ados.\n");

    SetIntBright(20);

    AddExit("sur", "./torre1_01");
    AddExit("oeste", "./torre1_03");
    AddDoor("sur", "una puerta de madera",
    "Es una puerta vieja de madera sin ning�n dibujo ni relieve, por ah� se sale de "
    "los barracones.\n",
    ({"puerta", "puerta del sur", "puerta de madera"}));

    SetLocate("el castillo de Nandor");
}

