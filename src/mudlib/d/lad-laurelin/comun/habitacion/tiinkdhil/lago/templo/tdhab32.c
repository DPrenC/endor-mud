/*****************************************************************************************
 ARCHIVO:       tdhab32.c
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

    SetIntShort("la enfermer�a");
    SetIntLong("Te encuentras en lo que antes era una enfermer�a. La habitaci�n est� "
          "llena de camas polvorientas y varios armarios.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail("armarios", "Hay uno al lado de una cama. A saber lo que quedar� "
          "dentro.\n");
    //FUNCI�N QUE CLONE ALG�N OBJETO DENTRO DE UNO DE LOS ARMARIOS

    AddExit("sudeste", ALULAGO("templo/tdhab30.c"));
    AddExit("sur", ALULAGO("templo/tdhab31.c"));

    AddItem(ALUPNJ("adepto"), REFRESH_DESTRUCT, 1);
}
