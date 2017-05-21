/*****************************************************************************************
 ARCHIVO:       tdhab25.c
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

    SetIntShort("el salón");
    SetIntLong("Ves un enorme trono situado justo al lado del altar. Parece que está "
          "vacío.\n");
    SetIndoors(1);
    SetIntBright(38);
    AddDetail("trono", "Debió estar ocupado por algún monje importante, tal vez un "
          "orador.\n");

    AddExit("este", ALULAGO("templo/tdhab24.c"));
    AddExit("sur", ALULAGO("templo/tdhab20.c"));
    AddExit("sudeste", ALULAGO("templo/tdhab19.c"));

    AddItem(ALUPNJ("esquel"), REFRESH_DESTRUCT, 1);
    AddItem(ALUPNJ("esquel"), REFRESH_DESTRUCT, 1);
}
