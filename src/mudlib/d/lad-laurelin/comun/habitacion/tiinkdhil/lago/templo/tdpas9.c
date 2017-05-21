/*****************************************************************************************
 ARCHIVO:       tdpas9.c
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

    SetIntShort("el pasillo");
    SetIntLong("En este pasillo lo único que llama la atención es un cuadro en la "
          "pared. Aunque cada vez está más oscuro, consigues ver, al fondo del corredor, "
          "una puerta.\n");
    SetIndoors(1);
    SetIntBright(32);
    AddDetail("cuadro", "Representa una lucha entre humanos y criaturas de la noche. "
          "Labradores y monjes pelean mano a mano contra un ejército de muertos, "
          "encabezado por un alto y siniestro personaje.\n");

    AddExit("norte", ALULAGO("templo/tdhab10.c"));
    AddExit("suroeste", ALULAGO("templo/tdpas2.c"));
    //AddDoor("idpuu","norte",ALULAGO("templo/tdhab10.c"),"puerta metalica oxidada","Con el tiempo se ha oxidado.\n",([P_MATERIAL: M_BRONCE, P_CERRADURA: CERRADURA_ACTIVO, P_CERRADURA_IDS: "nollave", P_PUERTA_VIDA:73,P_PUERTA_VIDA_MAX:73 ]));
}
