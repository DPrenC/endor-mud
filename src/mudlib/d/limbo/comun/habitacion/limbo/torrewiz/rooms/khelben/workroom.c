/**
 * /torrewiz/rooms/khelben/workroom.c
 */

#include "path.h"
inherit ROOM;

create () {
    ::create();

    SetIntShort("la habitaci�n de Khelben");
    SetIntLong(
"Esta es la habitaci�n de Khelben. Es una habitaci�n espaciosa y tranquila, "
"decorada cuidadosamente con recuerdos de sus viajes y aventuras. En el "
"centro de la habitaci�n hay una enorme esfera de colores. Las paredes "
"est�n llenas de posters y dibujos. En un lado de la habitaci�n hay unas "
"estanter�as con algunos libros.\n");

    AddDetail("esfera",
"Es una esfera blanca con algunas partes coloreadas en verde, azul...\n"
"Parece el mapa de un mundo.\n");

    AddDetail( ({ "poster","dibujo","posters","dibujos" }),
"Son unos dibujos muy interesantes. Si te acercas m�s los ver�s mejor.\n"
"'ampliar <n�mero>'\n");
    SetIntBright(50);
    SetIndoors(1);

    AddExit("torre", TORRE("piso4/center"));
}

init() {
  ::init();
  add_action("ampliar","ampliar");
}

int ampliar(string str) {
    int num;
    string file;

    if (!str || sscanf(str,"%d",num) != 1) {
        return notify_fail("Apliar qu� n�mero?\n");
    }
    file = sprintf(TORRE("/rooms/khelben/cuadros/dibujo%d"),num);
    if ( file_size( file) < 0) {
        return notify_fail("Ese cuadro no existe, mira bien el n�mero que miras.\n");
    }
    STR->smore(read_file(file));
    return 1;
}
