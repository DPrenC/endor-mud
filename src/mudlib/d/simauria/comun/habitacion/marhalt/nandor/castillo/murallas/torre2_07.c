/****************************************************************************
Fichero: torre2_07.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: la torre nordeste del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("una sala com�n");
    SetIntLong("Te encuentras en una amplia estancia con numerosos bancos y caballetes "
    "distribuidos por doquier. Es aqu� donde los hombres de armas y sirvientes del castillo "
    "realizan sus magras comidas, pasan el tiempo libre jugando a los dados, "
    "charlando sobre tal o cual aldeana, o reparando su equipo. Las aspilleras del muro "
    "proporcionan puntos de observaci�n y de disparo.\n La sala com�n contin�a hacia el este.\n");
    AddDetail("bancos", "Sencillos bancos de madera sin respaldo.\n");
    AddDetail("caballetes", "Caballetes de tablas en los que se reparten los hombres de "
    "armas.\n");
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

    AddExit("sur", "./torre2_08");
    AddExit("este", "./torre2_06");
    SetLocate("el castillo de Nandor");
}

