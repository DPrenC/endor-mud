/*
DESCRIPCION  : cantera al norte del bosque de Morak
FICHERO      : cantera5.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_MORAK("cantera");

create()
{
    ::create();
   SetIntShort("la parte superior de la pared de roca de la cantera de Morak");
    SetIntLong("En esta parte superior de la pared de roca de la cantera se "
        "hace muy evidente el desgaste sufrido por la continua extracción "
        "de bloques de piedra. Sobre la superficie de la roca puedes ver las "
        "líneas trazadas por los canteros para marcar por donde se ha de "
        "partir la roca.\n");
    AddDetail(({"lineas","líneas"}),"Las líneas rectas que ves marcadas "
        "sobre la pared de la roca han sido trazadas por los canteros para "
        "marcar el lugar por donde pretenden cortar la piedra. Para ello, "
        "primero harán una serie de agujeros a lo largo de las líneas y "
        "luego, mediante cinceles y palancas harán que la roca se agriete "
        "por esos lugares.\n");
    AddDetail(({"trozos","rocas"}),"El suelo esta lleno de trozos de rocas, "
        "desprendidos de la pared al cortar los canteros las piedras.\n");
    AddDetail(({"pared","pared de roca"}),"Es una alta y prácticamente "
        "maciza roca al pie de las montañas. Calculas que al menos tendrá en "
        "esta parte unos 10 o 12 metros hasta donde alcanzas a ver. Es de "
        "ella de donde los canteros cortan los bloques de piedra.\n");
    AddDetail(({"andamios","andamio"}),"Los robustos andamios de madera que "
        "ves junto a la pared de roca, permiten a los canteros bajar las "
        "rocas que cortan en la parte superior de la pared al suelo, donde "
        "luego se cincelarán con más precisión.\n");
    AddExit("abajo",BOSQUE_MORAK("cantera3"));
    AddExit("este",BOSQUE_MORAK("cantera4"));
}
