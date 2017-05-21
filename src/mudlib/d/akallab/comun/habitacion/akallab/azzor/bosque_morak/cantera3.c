/*
DESCRIPCION  : cantera al norte del bosque de Morak
FICHERO      : cantera3.c
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
    SetIntLong("Te encuentras junto a la alta pared de roca vertical de la "
        "cantera. Es de esta maciza mole de roca de donde los canteros "
        "cortan las piedras que de aquí se extraen y que luego se emplearán "
        "en la construcción.\nJunto a la pared de roca, se han construido "
        "unos robustos andamios de madera en los que trabajan los canteros.\n"
        "Al oeste de aquí se halla una rústica cabaña de madera.\n");
    AddDetail(({"pared","pared de roca"}),"Es una alta y prácticamente "
        "maciza roca al pie de las montañas. Calculas que al menos tendrá en "
        "esta parte unos 10 o 12 metros hasta donde alcanzas a ver. Es de "
        "ella de donde los canteros cortan los bloques de piedra.\n");
    AddDetail(({"andamios","andamio"}),"Los robustos andamios de madera que "
        "ves junto a la pared de roca, permiten a los canteros bajar las "
        "rocas que cortan en la parte superior de la pared al suelo, donde "
        "luego se cincelarán con más precisión.\n");
    AddExit("arriba",BOSQUE_MORAK("cantera5"));
    AddExit("este",BOSQUE_MORAK("cantera2"));
    AddExit("sur",BOSQUE_MORAK("cantera1"));
    AddExit("oeste",BOSQUE_MORAK("cantera_almacen"));
}
