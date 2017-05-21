/*****************************************************************************************
 ARCHIVO:       bosque40.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCIÓN:   Bosque de las Hadas.
 COMENTARIOS:   Details...
*****************************************************************************************/

#include "./path.h"

inherit BASE_HADAS;

create()
{
    if(::create()) return 1;

    SetIntShort("una bifurcación de las profundidades");
    SetIntLong("La sala en la que te encuentras es de tamaño reducido y forma "
        "triangular, sin ningún adorno aparente, tan sólo tres aberturas en cada una "
        "de sus paredes, a través de las cuales podrías pasar; la abertura del sur y "
        "la del sudeste están rodeadas por un aura rosada, totalmente translúcida.\n");
    AddDetail(({"abertura", "aberturas"}), ".\n");
    AddDetail(({"aura", "aura rosada"}), ".\n");
    SetIndoors(1);
    SetIntBright(20);

    AddExit("noroeste", HAB_BOSQUE_HADAS("bosque43.c"));
    AddExit("suroeste", HAB_BOSQUE_HADAS("bosque36.c"));
    AddExit("sur", HAB_BOSQUE_HADAS("bosque37.c"));
}
