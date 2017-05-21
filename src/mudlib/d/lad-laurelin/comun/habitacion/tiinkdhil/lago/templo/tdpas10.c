/*****************************************************************************************
 ARCHIVO:       tdpas10.c
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

    SetIntShort("un corredor");
    SetIntLong("Este pasillo parece bastante largo. Sigue al noroeste.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail(({"pared", "paredes"}), "El sitio deber�a ser iluminado por las l�mparas "
          "que tiene... de aceite.\n");
    //aqu� puedo a�adir una funci�n que encienda las l�mparas (con fuego)

    AddExit("noroeste", ALULAGO("templo/tdpas11.c"));
    AddExit("sur", ALULAGO("templo/tdhab10.c"));

    AddItem(ALUPNJ("vampiro"), REFRESH_DESTRUCT, 1);
}
