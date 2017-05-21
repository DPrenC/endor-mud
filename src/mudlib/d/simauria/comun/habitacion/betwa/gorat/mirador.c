// 04-06-08 [Angor] Creacion

#include "./path.h"
inherit GORAT("room_base.c");


create () {
    ::create();
    replace_program();
    SetIntShort("el mirador junto al faro de Gorat");
    SetIntLong(
"Aqu� acaba el sendero que asciende desde Gorat a la parte superior de esta "
"colina. Un viento marino fr�o y cargado de sal sopla fuerte y agita los "
"matojos de hierba que se han atrevido a crecer en esta cima. Desde este "
"punto se divisa pr�cticamente todo el golfo de Betria al suroeste y es por "
"ello que se ha edificado el faro que queda al norte.\n");

    AddExit("este", GORAT("calle_faro_1") );
    AddExit("norte", GORAT("faro1") );
}
