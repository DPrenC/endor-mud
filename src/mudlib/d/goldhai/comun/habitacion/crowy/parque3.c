#include "./path.h"
inherit GROOM;
inherit GRAF;

create()
{
 ::create();
 SetIntLong(
"Este es uno de los claros de este parque, un lugar perfecto para pararse a "
"respirar aire fresco. Al sur se alza un viejo muro.\n");
  
 AddExit("este",CROWY("parque1"));
 AddExit("oeste",CROWY("parque4"));
 AddExit("norte",CROWY("parque5"));
 
#include "./parque.inc"
 
 SetGrafPlaces(({"el muro","muro"}));
}

void init()
{::init();
 add_graf_commands();
}

