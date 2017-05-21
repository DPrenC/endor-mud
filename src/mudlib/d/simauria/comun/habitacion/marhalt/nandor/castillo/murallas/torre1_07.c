/****************************************************************************
Fichero: torre1_07.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: la torre noroeste del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("una armer�a");
    SetIntLong("Est�s en el oeste de la armer�a en la que se provee la guarnici�n del "
    "castillo. Colgadas de las paredes hay cotas de malla en distintos estados de "
    "conservaci�n junto a escudos, cascos y otros pertrechos. Algunas antorchas "
    "acrecentan la escasa luz  de las aspilleras del muro exterior.\n");
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
    AddDetail("cotas", "Est�n en distintos estados de conservaci�n, algunas viejas y mas "
    "oxidadas, otras con anillas sueltas, y algunas completamente nuevas y brillantes.\n");
    AddDetail("cascos", "Sencillos cascos de cuero y metal.\n");
    AddDetail("escudos", "Escudos de madera y armaz�n demetal que cuelgan de los muros "
    "con la flor de lis y el mandoble de los Dhes-Bl�in pintadas en el centro.\n");
    SetIntBright(30);
    AddExit("este", "./torre1_06");
    SetLocate("el castillo de Nandor");
}

