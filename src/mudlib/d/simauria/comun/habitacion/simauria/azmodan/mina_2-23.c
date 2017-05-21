/***********************************************************/
//  "mina_2-23"
//  Mina abandonada
//  14-12-01 : Creación -> Kodex
//  14-12-01 : Modificación -> Kodex
//
//
#include "path.h"
#include <rooms.h>
inherit STD_AZMODAN("mina");


create() {
    ::create();
    SetIntShort("la segunda planta de la mina");
    SetIntLong(W("Estás en el segundo nivel de la mina, en lo que parece "
                 "ser un gran conducto que gira justo aquí. Al norte ves un "
                 "gran agujero que lleva a una sala donde puedes ver las "
                 "escaleras para subir al primer nivel y poder salir de esta "
                 "pesadilla.\n"));
    AddExit("norte",MINA_AZMODAN("mina_2-25"));
    AddExit("sur",MINA_AZMODAN("mina_2-18"));
    AddExit("oeste",MINA_AZMODAN("mina_2-22"));
    if (random(100) < 50)
    {
        switch(random(3))
        {
            case 0 .. 1:
                AddItem(NPC_AZMODAN("uruk"),REFRESH_DESTRUCT,1);
                break;
            case 2:
                AddItem(NPC_AZMODAN("orco"),REFRESH_DESTRUCT,1);
                break;
            default: break;
        }
    }
}
