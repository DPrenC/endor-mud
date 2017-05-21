/****************************************************************************
Fichero: torre2_05.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: la torre nordeste del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("un almacén vacío");
    SetIntLong("Esta estancia no parece tener uso en la actualidad, pues está "
    "completamente vacío, a excepción de una buena capa de polvo que invade el triste "
    "suelo.\n");
    SetIntBright(20);
    AddDetail("suelo", "El suelo está formado por pesadas losas de piedra perfectamente "
    "encajadas entre sí.\n");
    AddDetail(({"paredes", "muros"}), "Se percibe la diferencia entre el muro exterior "
    "del torreón, mas grueso, y construído con bloques mucho mas grandes que los de los "
    "tabiques que lo dividen.\n");
    AddDetail("bloques", "Grandes bloques de piedra que forman los muros.\n");
    AddDetail("antorchas", "Antorchas encajadas en soportes de hierro sujetos a la pared.\n");
    AddDetail("aspilleras", "Una serie de aberturas rectangulares, mas anchas en la "
    "parte interior que en la exterior para evitar en lo posible la entrada de las "
    "flechas.\n");

    AddExit("oeste", "./torre2_08");
    SetLocate("el castillo de Nandor");
}

