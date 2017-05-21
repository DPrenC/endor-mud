/****************************************************************************
Fichero: torre2_02.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: la torre nordeste del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("los barracones de la servidumbre");
    SetIntLong("Te encuentras en una estancia bastante grande que ocupa toda la mitad "
    "norte de la planta baja del torre�n de C�nor. Es aqu� donde la servidumbre del castillo "
    "tiene sus humildes jergones de paja alineados junto a las paredes. El lugar "
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

    AddExit("oeste", "./torre2_03");
    SetLocate("el castillo de Nandor");
}

