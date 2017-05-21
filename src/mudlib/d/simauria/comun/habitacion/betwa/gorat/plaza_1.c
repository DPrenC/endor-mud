// 07-06-08 [Angor] Creacion

#include "./path.h"
inherit GORAT("room_base.c");

create () {
    ::create();
    replace_program();
    SetIntShort("la plaza principal de Gorat");
    SetIntLong(
"De esta esquina de la plaza principal de Gorat sale un sendero hacia el "
"noroeste que asciende hasta la cima de la colina donde se halla el faro. "
"La plaza es una extensión triangular con adoquines rodeada de casas bajas "
"en cuyo extremo sur mana una alegre fuente. La calle de arriba, que va "
"rodeando la colina desciende hacia el norte. La fresca brisa del golfo se "
"hace sentir incluso aqui.\n");

 AddDetail(({"fuente"}),
"La fuente está al otro extremo de la plaza al sur de aquí.\n");

 AddExit("noroeste", GORAT("calle_faro_3") );
 AddExit("este", GORAT("plaza_3") );
 AddExit("sur", GORAT("plaza_2") );

 SetIntNoise("La fuente mana alegremente.\n");
 SetIntSmell("Alguien debe estar cocinando en una de las casas cercanas.\n");
}
