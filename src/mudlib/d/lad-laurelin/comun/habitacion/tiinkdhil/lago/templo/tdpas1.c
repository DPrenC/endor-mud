/*****************************************************************************************
 ARCHIVO:       tdpas1.c
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

    SetIntShort("un peque�o pasillo");
    SetIntLong("El suelo est� lleno de pedruscos debido al desmoronamiento de parte "
          "del techo. Bichos y varios tipos de insectos se mueven por �l. Al nordeste y "
          "noroeste ves m�s corredores, mientras que al sur se encuentra tu posible "
          "salvaci�n. Del oeste viene un olor intenso.\n");
    SetIntSmell("Notas un fuerte olor a ... �bosque?\n");
    SetIndoors(1);
    SetIntBright(40);

    AddExit("sur", ALULAGO("templo/tdent.c"));
    AddExit("nordeste", ALULAGO("templo/tdpas2.c"));
    AddExit("noroeste", ALULAGO("templo/tdpas3.c"));
    AddExit("oeste", ALULAGO("templo/tdhab1.c"));

    AddItem(ALUPNJ("rata"), REFRESH_DESTRUCT, 1);
}
