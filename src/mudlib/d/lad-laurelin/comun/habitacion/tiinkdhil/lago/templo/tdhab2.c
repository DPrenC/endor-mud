/*****************************************************************************************
 ARCHIVO:       tdhab2.c
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

    SetIntShort("el herbolario");
    SetIntLong("Contin�as en el herbolario. Aqu� hay menos cantidad de vegetales, ves "
          "un �rbol de la altura de un hombre, enredaderas, algunas plantas en flor y "
          "otras con raros frutos.\n");
    SetIndoors(0);
    SetIntBright(55);
    AddDetail("techo", "NO hay techo, pero observas restos de cristales en sus "
          "esquinas, lo cual te indica que tal vez fuera de vidrio.\n");
    AddDetail("plantas", "Llevan a�os aqu�, y estan muy desarrolladas. Algunas "
          "alcanzan el techo.\n");

    AddExit("este", ALULAGO("templo/tdhab1.c"));
    AddExit("oeste", ALULAGO("templo/tdpas8.c"));

    // A�adir alguna planta mas que pueda distinguir el player
    AddItem(ALUPNJ("entm"), REFRESH_DESTRUCT, 1);
}
