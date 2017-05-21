/*****************************************************************************************
 ARCHIVO:       tdhab15.c
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
    
    SetIntShort("el salón");
    SetIntLong("Te hallas en la zona este de esta gran sala. Al norte ves un altar. "
          "Todas las direcciones te mueven por el salón.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail("altar", "No lo distingues bien, está oscuro.\n");
    AddDetail("techo", "Es una inmensa bóveda decorada con expresivos dibujos del "
          "dios. Dehim es el sanador celestial, la esperanza de los enfermos.\n");

    AddExit("oeste", ALULAGO("templo/tdhab16.c"));
    AddExit("norte", ALULAGO("templo/tdhab19.c"));
    AddExit("sur", ALULAGO("templo/tdhab7.c"));
    AddExit("noroeste", ALULAGO("templo/tdhab20.c"));
    AddExit("suroeste", ALULAGO("templo/tdhab8.c"));
    /*
    AddDoor("poo","este",ALULAGO("templo/tdhab14.c"),"puerta secreta","Apenas ves su contorno.\n",
      ([P_CERRADURA: CERRADURA_ACTIVO, P_CERRADURA_IDS: "llavedepl",P_PUERTA_VIDA:73,P_PUERTA_VIDA_MAX:73]) );
    */

    AddItem(ALUPNJ("adepto"), REFRESH_DESTRUCT, 1);
}
