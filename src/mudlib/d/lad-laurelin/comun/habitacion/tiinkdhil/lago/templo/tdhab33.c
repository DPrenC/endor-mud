/*****************************************************************************************
 ARCHIVO:       tdhab33.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCIÓN:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit ROOM;

public void create()
{
    ::create();

    SetIntShort("la habitación del segundo de la orden");
    SetIntLong("Estás en una habitación bastante mas lujosa que el resto. A tu "
          "alrededor hay bellos armarios, una cama y un escritorio.\n");

    SetIndoors(1);
    SetIntBright(30);

    AddDetail("armarios", "Algunos tienen libros, otros figurillas destrozadas y "
          "otros, restos de objetos.\n");
    AddDetail("escritorio", "Está tallado en madera y mármol. Es una obra de arte.\n");
    AddDetail("cama", "Es un bonito camastro, sucio y lleno de telarañas.\n");
    //Añadir algún que otro libro que se pueda leer

    AddExit("sur", ALULAGO("templo/tdpas13.c"));

    //Añadido al monje segundo en la orden, al cual se le podran hacer preguntas de Quest
    AddItem(ALUPNJ("sacerdote"), REFRESH_DESTRUCT, 1);
}
