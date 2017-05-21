/*****************************************************************************************
 ARCHIVO:       tdhab2.c
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

    SetIntShort("el herbolario");
    SetIntLong("Continúas en el herbolario. Aquí hay menos cantidad de vegetales, ves "
          "un árbol de la altura de un hombre, enredaderas, algunas plantas en flor y "
          "otras con raros frutos.\n");
    SetIndoors(0);
    SetIntBright(55);
    AddDetail("techo", "NO hay techo, pero observas restos de cristales en sus "
          "esquinas, lo cual te indica que tal vez fuera de vidrio.\n");
    AddDetail("plantas", "Llevan años aquí, y estan muy desarrolladas. Algunas "
          "alcanzan el techo.\n");

    AddExit("este", ALULAGO("templo/tdhab1.c"));
    AddExit("oeste", ALULAGO("templo/tdpas8.c"));

    // Añadir alguna planta mas que pueda distinguir el player
    AddItem(ALUPNJ("entm"), REFRESH_DESTRUCT, 1);
}
