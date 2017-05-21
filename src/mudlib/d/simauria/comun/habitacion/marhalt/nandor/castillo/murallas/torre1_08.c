/****************************************************************************
Fichero: torre1_08.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: la torre noroeste del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("una peque�a sala com�n");
    SetIntLong("Esta es una peque�a sala com�n para parte de la guarnici�n del "
    "castillo. Unos pocos bancos y caballetes es lo �nico que se puede apreciar de "
    "inter�s en la estancia.\n");
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

    AddExit("este", "./torre1_05");
    SetLocate("el castillo de Nandor");
    AddItem(PNJCASTILLO("hombre_armas"), REFRESH_DESTRUCT,d2());
}

