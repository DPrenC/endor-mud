/*****************************************************************************************
 ARCHIVO:       tdhab32.c
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

    SetIntShort("la enfermería");
    SetIntLong("Te encuentras en lo que antes era una enfermería. La habitación está "
          "llena de camas polvorientas y varios armarios.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail("armarios", "Hay uno al lado de una cama. A saber lo que quedará "
          "dentro.\n");
    //FUNCIÓN QUE CLONE ALGÚN OBJETO DENTRO DE UNO DE LOS ARMARIOS

    AddExit("sudeste", ALULAGO("templo/tdhab30.c"));
    AddExit("sur", ALULAGO("templo/tdhab31.c"));

    AddItem(ALUPNJ("adepto"), REFRESH_DESTRUCT, 1);
}
