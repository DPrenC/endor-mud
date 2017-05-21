/*****************************************************************************************
 ARCHIVO:       tdpas10.c
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

    SetIntShort("un corredor");
    SetIntLong("Este pasillo parece bastante largo. Sigue al noroeste.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail(({"pared", "paredes"}), "El sitio debería ser iluminado por las lámparas "
          "que tiene... de aceite.\n");
    //aquí puedo añadir una función que encienda las lámparas (con fuego)

    AddExit("noroeste", ALULAGO("templo/tdpas11.c"));
    AddExit("sur", ALULAGO("templo/tdhab10.c"));

    AddItem(ALUPNJ("vampiro"), REFRESH_DESTRUCT, 1);
}
