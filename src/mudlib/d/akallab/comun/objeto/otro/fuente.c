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
"llenar la pileta ya que un ca�o se la lleva antes de all� a otra parte.\n");

AddId(({"fuente","pileta","ca�o"}));

SetNoGet("Deber�as hacer m�s ejercicio, que con esta fuente no puedes...\n");
}

