// 07-06-2008 [Angor] 

#include "path.h"
inherit "/obj/fountain";

create()
{
::create();
SetShort("una fuente");
SetLong(
"Es una pileta de piedra toscamente tallada llega el agua de un manantial "
"cercano. El agua cristalina cae alegremente mientras trata en vano de "
"llenar la pileta ya que un caño se la lleva antes de allí a otra parte.\n");

AddId(({"fuente","pileta","caño"}));

SetNoGet("Deberías hacer más ejercicio, que con esta fuente no puedes...\n");
}

