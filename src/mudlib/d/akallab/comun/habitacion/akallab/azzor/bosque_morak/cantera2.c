/*
DESCRIPCION  : cantera al norte del bosque de Morak
FICHERO      : cantera2.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_MORAK("cantera");

create()
{
    ::create();
   SetPreIntShort("junto a");
    SetIntShort("la pared de roca de la cantera de Morak");
    SetIntLong("Frente a ti se alza una pared de roca vertical prácticamente "
        "maciza de al menos 10 o 12 metros de altura. Es de aquí de donde se "
        "extraen los bloques de piedra que los orcos emplean en sus "
        "construcciones de piedra, principalmente fortalezas y murallas.\n"
        "Junto a la pared de roca, se han construido unos robustos andamios "
        "de madera sobre los que trabajan los canteros. El suelo está lleno "
        "de trozos de roca, desprendidos de la pared al cortar los canteros "
        "las piedras.\n");
    AddDetail(({"trozos","rocas"}),"El suelo esta lleno de trozos de roca, "
        "desprendidos de la pared al cortar los canteros las piedras.\n");
    AddDetail(({"pared","pared de roca"}),"Es una alta y prácticamente "
        "maciza roca al pie de las montañas. Calculas que al menos tendrá en "
        "esta parte unos 10 o 12 metros hasta donde alcanzas a ver. Es de "
        "ella de donde los canteros cortan los bloques de piedra.\n");
    AddDetail(({"andamios","andamio"}),"Los robustos andamios de madera que "
        "ves junto a la pared de roca, permiten a los canteros bajar las "
        "rocas que cortan en la parte superior de la pared al suelo, donde "
        "luego se cincelarán con más precisión.\n");
    AddExit("arriba",BOSQUE_MORAK("cantera4"));
    AddExit("este",BOSQUE_MORAK("bosque46"));
    AddExit("sur",BOSQUE_MORAK("cantera0"));
    AddExit("oeste",BOSQUE_MORAK("cantera3"));
}
