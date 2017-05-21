#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntLong(
"A partir de aqui se extiende un área verde al noroeste de la ciudad "
"hasta el muro que la rodea. Es un lugar de reposo donde no es infrecuente "
"ver animales. La salida del parque queda al este.\n");

 AddExit("norte",CROWY("parque8"));
 AddExit("oeste",CROWY("parque1"));
 AddExit("este",CROWY("calle1"));

#include "./parque.inc"

}


