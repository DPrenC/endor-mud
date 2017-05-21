/***
Fichero: puesto_estar.c
Autor: kastwey@simauria
Descripción: Sala de descanso de los guardias.
Segunda vezque la codeo... puto shift + supr... ;)
Creación: 06/12/2004
23/12/2004 Pongo que los que se crean aquí no pidan refuerzos... ¿A quién van a pedir refuerzos? :)
***/

#include "path.h"

inherit STD_FAERIA("hab_siempreunidos");

create()
{
    ::create();
    SetIntShort("la zona de descanso");
    SetIntLong(W("Te encuentras en lo que parece una zona destinada al descanso de los guardias.\n"
    "Esta habitación tiene un gran sillón y una mesa frente a él. Pegada a la pared norte, puedes ver un pequeño fogón y algunos cacharros de cocina.\n"));
    SetOficina(HAB_PUESTO("puesto_guardias/puesto_piso1"));
    SetIndoors(1);
    SetIntBright(25);
    AddDetail(({"mesa"}), "Es una mesa alargada, situada delante del sillón. Encima de ella puedes ver una baraja de cartas y algunos vasos sucios.\n");
    AddDetail(({"sillon"}), "Es un sillón que ocupa toda la pared sur. Parece muy cómodo.\n");
    AddDetail(({"baraja", "baraja de cartas", "cartas"}), "Es un mazo de cartas unido por una cuerdecita. Al mirarlo más detenidamente, observas que en las cartas hay pintadas diferentes escenas del pueblo élfico.\n");
    AddDetail(({"cocina", "cocinita", "cocinilla"}), "Es una pequeña cocina situada en la pared norte de la sala. Básicamente consta de un pequeño fogón y unos cuantos cacharros: una sartén, una oya, un caldero y un cucharón.\n");
    AddDetail(({"cacharros", "cucharón", "cucharon", "olla", "sartén", "sarten", "caldero"}), "Son unos cacharros de cocina, que aunque oxidados, aún pueden realizar perfectamente su trabajo.\n");
    AddItem(PNJ_PUESTO("sargento"), REFRESH_REMOVE, ([
        "Aggressive":1,
        "PedirRefuerzos":0
    ]), 2);
    AddItem(PNJ_PUESTO("conjurador"), REFRESH_REMOVE, ([
        "Aggressive":1,
        "PedirRefuerzos":0
    ]), 1);
    AddExit("oeste", HAB_PUESTO("puesto_guardias/puesto_piso1"));
}