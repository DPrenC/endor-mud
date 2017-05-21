/*****************************************************************************************
 ARCHIVO:       tdpas8.c
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

    SetIntShort("el pasillo");
    SetIntLong("Te encuentras en un pasillo que contin�a delante de ti. �sto est� "
          "bastante m�s destrozado que las primeras habitaciones del templo, pero el "
          "techo a�n se mantiene gracias a los pilares que hay.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail(({"pared", "paredes"}), "Est�n muy sucias, pero no lo suficiente como "
          "para no ver las manchas oscuras que tienen, un tanto rojizas...\n");

    AddExit("noroeste", ALULAGO("templo/tdpas7.c"));
    AddExit("este", ALULAGO("templo/tdhab2.c"));
    AddExit("oeste", ALULAGO("templo/tdhab34.c"));

    AddItem(ALUPNJ("monjef"), REFRESH_DESTRUCT, 1);
}
