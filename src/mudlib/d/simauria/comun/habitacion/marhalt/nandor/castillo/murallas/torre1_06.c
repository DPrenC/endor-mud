/****************************************************************************
Fichero: torre1_06.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: la torre noroeste del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("una armer�a");
    SetIntLong("Est�s en una gran sala que hace las veces de armer�a. De los muros de "
    "piedra cuelgan hileras de espadas envainadas, arcos, lanzas y atos de flechas. La "
    "luz de las antorchas se refleja en las aristas y las superficies met�licas. Al sur "
    "una puerta conduce a la sala de entrada al torre�n, mientras que la armer�a "
    "contin�a hacia el oeste.\n");
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
    AddDetail("espadas", "A pesar de no estar muy bien cuidadas ni ser de gran calidad, "
    "son unas armas �tiles.\n");
    AddDetail("lanzas", "Sencillas lanzas de infanter�a.\n");
    AddDetail("arcos", "Arcos de madera que por su aspecto son de una calidad media.\n"
    "Cuelgan de ganchos en la pared sin encordar.\n");
    AddDetail("flechas", "Se amontonan junto a la pared en apretados haces.\n");
    SetIntBright(30);

    AddExit("sur", "./torre1_05");
    AddExit("oeste", "./torre1_07");
    AddDoor("sur", "una puerta reforzada",
    "Es una puerta casi el doble de ancha que las dem�s. Aunque es de madera maciza, "
    "est� reforzada por l�minas de acero negro.\n",
    ({"puerta", "puerta de madera", "puerta reforzada", "puerta del sur"}));
    SetLocate("el castillo de Nandor");
}

