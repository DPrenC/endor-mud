/*****************************************************************************************
 ARCHIVO:       tdhab21.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCI�N:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit ROOM;

int a�adir_bicho();

public void create()
{
    ::create();

    SetIntShort("el dormitorio de invitados");
    SetIntLong("La falta de objetos decorativos y personales te hace ver que esta "
          "habitaci�n estaba destinada a los hu�spedes. Posiblemente a alg�n "
          "peregrino.\n");
    SetIndoors(1);
    SetIntBright(40);

    AddExit("norte", ALULAGO("templo/tdhab26.c"));
    AddExit("sur", ALULAGO("templo/tdpas12.c"));
    AddExit("este", ALULAGO("templo/tdpas11"));
    AddDoor("este", "una puerta",
        "Est� en muy malas condiciones.\n");
    a�adir_bicho();
}

int a�adir_bicho()
{
    if ((1 + random(2)) == 1)
    {
      AddItem(ALUPNJ("vampiro"), REFRESH_DESTRUCT, 2);
      return 1;
    }
    AddItem(ALUPNJ("vampiro"),REFRESH_DESTRUCT,3);
    return 1;
}
