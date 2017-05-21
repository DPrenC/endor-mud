/**
 * /torrewiz/rooms/khelben/workroom.c
 */

#include "path.h"
inherit ROOM;

create () {
    ::create();

    SetIntShort("la habitación de Khelben");
    SetIntLong(
"Esta es la habitación de Khelben. Es una habitación espaciosa y tranquila, "
"decorada cuidadosamente con recuerdos de sus viajes y aventuras. En el "
"centro de la habitación hay una enorme esfera de colores. Las paredes "
"están llenas de posters y dibujos. En un lado de la habitación hay unas "
"estanterías con algunos libros.\n");

    AddDetail("esfera",
"Es una esfera blanca con algunas partes coloreadas en verde, azul...\n"
"Parece el mapa de un mundo.\n");

    AddDetail( ({ "poster","dibujo","posters","dibujos" }),
"Son unos dibujos muy interesantes. Si te acercas más los verás mejor.\n"
"'ampliar <número>'\n");
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
        return notify_fail("Apliar qué número?\n");
    }
    file = sprintf(TORRE("/rooms/khelben/cuadros/dibujo%d"),num);
    if ( file_size( file) < 0) {
        return notify_fail("Ese cuadro no existe, mira bien el número que miras.\n");
    }
    STR->smore(read_file(file));
    return 1;
}
