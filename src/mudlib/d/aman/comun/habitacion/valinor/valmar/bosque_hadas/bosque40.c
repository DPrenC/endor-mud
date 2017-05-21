/*****************************************************************************************
 ARCHIVO:       bosque40.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCI�N:   Bosque de las Hadas.
 COMENTARIOS:   Details...
*****************************************************************************************/

#include "./path.h"

inherit BASE_HADAS;

create()
{
    if(::create()) return 1;

    SetIntShort("una bifurcaci�n de las profundidades");
    SetIntLong("La sala en la que te encuentras es de tama�o reducido y forma "
        "triangular, sin ning�n adorno aparente, tan s�lo tres aberturas en cada una "
        "de sus paredes, a trav�s de las cuales podr�as pasar; la abertura del sur y "
        "la del sudeste est�n rodeadas por un aura rosada, totalmente transl�cida.\n");
    AddDetail(({"abertura", "aberturas"}), ".\n");
    AddDetail(({"aura", "aura rosada"}), ".\n");
    SetIndoors(1);
    SetIntBright(20);

    AddExit("noroeste", HAB_BOSQUE_HADAS("bosque43.c"));
    AddExit("suroeste", HAB_BOSQUE_HADAS("bosque36.c"));
    AddExit("sur", HAB_BOSQUE_HADAS("bosque37.c"));
}
