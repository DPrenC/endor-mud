/****************************************************************************
Fichero: torre2_08.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: la torre nordeste del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("la segunda planta del torre�n de C�nor");
    SetIntLong("Est�s en una sala en la segunda planta del torre�n de C�nor, "
    "iluminada por la luz que se cuela  por un arco que al suroeste da a la muralla y las "
    "aspilleras practicadas en los gruesos muros. �sta sala parece tener la mera "
    "funci�n de distribuidor para las dem�s estancias del edificio, ya que al norte y al "
    "este hay sendos arcos, al nordeste se ve  una empinada escalera de caracol "
    "mientras que al suroeste otro arco  da paso a la muralla. Suelos y paredes est�n tan "
    "bien construidos que pese a su palpable antig�edad, se mantienen sin mostrar "
    "ninguna clase de grieta o desperfecto.\n");
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
    SetIntBright(30);

    AddExit("este", "./torre2_05");
    AddExit("nordeste", "./escalera2_2");
    AddExit("norte", "./torre2_07");
    AddExit("suroeste", "./muralla13");
    SetLocate("el castillo de Nandor");
    AddItem(PNJCASTILLO("hombre_armas"), REFRESH_DESTRUCT);
}

