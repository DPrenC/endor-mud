/*****************************************************************************************
 ARCHIVO:       tdhab10.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCIÓN:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
//#include <door.h>
//#include <cerradura.h>

inherit ROOM;

public void create()
{
    ::create();

    SetIntShort("la habitacion de oración");
    SetIntLong("Aquí es donde los monjes solían contarle sus cosillas a su dios Dehim. "
          "No hay muchas cosas, más que un pequeño altar vacío y unos bancos llenos de "
          "polvo.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail("altar", "Deberia tener alguna imagen del dios, pero esta vacio.\n");

    AddExit("norte", ALULAGO("templo/tdpas10.c"));
    AddExit("sur", ALULAGO("templo/tdpas9.c"));
    //AddDoor("idpuu","sur",ALULAGO("templo/tdpas9.c"),"puerta metalica oxidada","Con el tiempo se ha oxidado.\n",([P_MATERIAL: M_BRONCE, P_CERRADURA: CERRADURA_ACTIVO, P_CERRADURA_IDS: "nollave", P_PUERTA_VIDA:73,P_PUERTA_VIDA_MAX:73 ]) );

    AddItem(ALUPNJ("monjer"), REFRESH_DESTRUCT, 1);
}
