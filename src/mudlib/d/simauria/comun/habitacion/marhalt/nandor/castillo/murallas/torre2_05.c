/****************************************************************************
Fichero: torre2_05.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: la torre nordeste del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("un almac�n vac�o");
    SetIntLong("Esta estancia no parece tener uso en la actualidad, pues est� "
    "completamente vac�o, a excepci�n de una buena capa de polvo que invade el triste "
    "suelo.\n");
    SetIntBright(20);
    AddDetail("suelo", "El suelo est� formado por pesadas losas de piedra perfectamente "
    "encajadas entre s�.\n");
    AddDetail(({"paredes", "muros"}), "Se percibe la diferencia entre el muro exterior "
    "del torre�n, mas grueso, y constru�do con bloques mucho mas grandes que los de los "
    "tabiques que lo dividen.\n");
    AddDetail("bloques", "Grandes bloques de piedra que forman los muros.\n");
    AddDetail("antorchas", "Antorchas encajadas en soportes de hierro sujetos a la pared.\n");
    AddDetail("aspilleras", "Una serie de aberturas rectangulares, mas anchas en la "
    "parte interior que en la exterior para evitar en lo posible la entrada de las "
    "flechas.\n");

    AddExit("oeste", "./torre2_08");
    SetLocate("el castillo de Nandor");
}

