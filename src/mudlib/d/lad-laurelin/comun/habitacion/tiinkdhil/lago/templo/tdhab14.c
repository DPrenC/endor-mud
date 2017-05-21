/*****************************************************************************************
 ARCHIVO:       tdhab14.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCIÓN:   Templo de Dehim.
 COMENTARIOS:   Trampilla secreta
*****************************************************************************************/

#include "./path.h"
//#include <door.h>
//#include <cerradura.h>

inherit ROOM;

public void create()
{
    ::create();

    SetIntShort("habitación secreta");
    SetIntLong("Estás en una austera habitación escavada en piedra. Por su aspecto no "
          "parece que haya sido hecha para habitar.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddExit("trampilla", ALULAGO("templo/tdhab13.c"));
    /*
    AddDoor("idtrampilla","arriba",ALULAGO("templo/tdhab13.c"),"trampilla","De un salto llegas hasta ella.\n",
       ([P_MATERIAL: M_BRONCE, P_PUERTA_VIDA:173,P_PUERTA_VIDA_MAX:173 ]) );
    AddDoor("poo","oeste","ALULAGO("templo/tdhab15.c"),"puerta secreta","Apenas ves su contorno.\n",
       ([P_CERRADURA: CERRADURA_ACTIVO, P_CERRADURA_IDS: "llavedepl",P_PUERTA_VIDA:73,P_PUERTA_VIDA_MAX:73 ]) );
    */

    AddItem(ALUPNJ("guardian"), REFRESH_DESTRUCT, 1);
    AddItem(ALUOBJ("otro/estatui"), REFRESH_REMOVE, 1);

}
