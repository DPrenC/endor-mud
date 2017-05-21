/*
DESCRIPCION  : Room especial para la zona de Akallab. Contiene algunas
               funciones adicionales.
FICHERO      : /d/akallab/std/ak_room.c
MODIFICACION : 20-05-97 [angor] Creacion.
               29-10-04 [greywolf] Se añade la funcion para registrar la hab
               21-11-04 [greywolf] Se añade la función de némesis para mirar
               			   el tiempo
*/


#include "../sys/akallab.h"
inherit ROOM; // Habitacion standard.

#include <colours.h>

haz_mirar(str) {
 object room;
 if (!str||str!="tiempo") return 0;
 else {
 room=TO;
 if(room->QueryIndoors()==1) {
 write("No puedes ver el tiempo que hace desde aqui.\n");
 return 42;
 }
 write(AK_SERVER->QueryWeatherMsg());
 return 42;
 }
}

string SetLongWrap(string texto) {
 return SetIntLong(texto+"\n");
}
create() {

    ::create();
    SetIntLong("En algun lugar de Akallab.\n");
    SetIntShort("algun lugar de Akallab");
    seteuid(getuid(TO));
    SetLocate(AKALLAB);
    SetServer(AK_SERVER);


}

init() {

add_action("haz_mirar","mirar");
add_action("haz_mirar","m");
add_action("haz_mirar","exa");
add_action("haz_mirar","examinar");
 ::init();
}



