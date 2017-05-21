/*****************************************************************************************
 ARCHIVO:       tdhab33.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCI�N:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit ROOM;

public void create()
{
    ::create();

    SetIntShort("la habitaci�n del segundo de la orden");
    SetIntLong("Est�s en una habitaci�n bastante mas lujosa que el resto. A tu "
          "alrededor hay bellos armarios, una cama y un escritorio.\n");

    SetIndoors(1);
    SetIntBright(30);

    AddDetail("armarios", "Algunos tienen libros, otros figurillas destrozadas y "
          "otros, restos de objetos.\n");
    AddDetail("escritorio", "Est� tallado en madera y m�rmol. Es una obra de arte.\n");
    AddDetail("cama", "Es un bonito camastro, sucio y lleno de telara�as.\n");
    //A�adir alg�n que otro libro que se pueda leer

    AddExit("sur", ALULAGO("templo/tdpas13.c"));

    //A�adido al monje segundo en la orden, al cual se le podran hacer preguntas de Quest
    AddItem(ALUPNJ("sacerdote"), REFRESH_DESTRUCT, 1);
}
