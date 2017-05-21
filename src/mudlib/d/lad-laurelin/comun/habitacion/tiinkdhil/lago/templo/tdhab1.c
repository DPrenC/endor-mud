/*****************************************************************************************
 ARCHIVO:       tdhab1.c
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
    SetIntLong("¡Vaya, ésto parece una selva! A tu alrededor no ves más que plantas "
          "que invaden hasta el descubierto techo. ¡Incluso hay un pequeño árbol! Esto "
          "debió ser un invernadero.\n");
    SetIndoors(0);
    SetIntBright(40);
    AddDetail("techo", "NO hay techo, pero observas restos de cristales en sus "
          "esquinas, lo cual te indica que tal vez fuera de vidrio.\n");

    AddExit("este", ALULAGO("templo/tdpas1.c"));
    AddExit("oeste", ALULAGO("templo/tdhab2.c"));

    // Aquí se meten unas cuantas plantas curativas, sedantes y adictivas.
    AddItem(ALUOBJ("comida/hierba_c"), REFRESH_DESTRUCT, 1);
    AddItem(ALUOBJ("comida/hierba_n"), REFRESH_DESTRUCT, 1);
}
