// Libreria de Armas de Simauria.
// Elaborada por [Gw]Greywolf, usando objetos creados por
// Woo, Angor, Nemesis, Kodex, Izet, Kintups y todos aquellos
// que han hecho algun arma en el mud. Gracias a ellos por
// su esfuerzo. Tambien son añadidas varias armas nuevas.
// Arma: Espada de Madera
// Fichero: Espada_madera.c
// Fecha de creación: 22/11/04 [Gw]

#include <mud.h>
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_ESPADA,1,P_SIZE_MEDIUM,M_MADERA);
 SetWeight(550);
 SetShort("una espada de madera");
 SetIds(({"espada","espada de madera"}));
 Set(P_GENDER,GENERO_FEMENINO);
 SetNumberHands(1);
 SetLong("\
Es una pequeña espada hecha de madera para que los niños puedan jugar.\n");
}

