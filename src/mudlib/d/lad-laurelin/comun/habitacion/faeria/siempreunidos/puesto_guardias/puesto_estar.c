/***
Fichero: puesto_estar.c
Autor: kastwey@simauria
Descripci�n: Sala de descanso de los guardias.
Segunda vezque la codeo... puto shift + supr... ;)
Creaci�n: 06/12/2004
23/12/2004 Pongo que los que se crean aqu� no pidan refuerzos... �A qui�n van a pedir refuerzos? :)
***/

#include "path.h"

inherit STD_FAERIA("hab_siempreunidos");

create()
{
    ::create();
    SetIntShort("la zona de descanso");
    SetIntLong(W("Te encuentras en lo que parece una zona destinada al descanso de los guardias.\n"
    "Esta habitaci�n tiene un gran sill�n y una mesa frente a �l. Pegada a la pared norte, puedes ver un peque�o fog�n y algunos cacharros de cocina.\n"));
    SetOficina(HAB_PUESTO("puesto_guardias/puesto_piso1"));
    SetIndoors(1);
    SetIntBright(25);
    AddDetail(({"mesa"}), "Es una mesa alargada, situada delante del sill�n. Encima de ella puedes ver una baraja de cartas y algunos vasos sucios.\n");
    AddDetail(({"sillon"}), "Es un sill�n que ocupa toda la pared sur. Parece muy c�modo.\n");
    AddDetail(({"baraja", "baraja de cartas", "cartas"}), "Es un mazo de cartas unido por una cuerdecita. Al mirarlo m�s detenidamente, observas que en las cartas hay pintadas diferentes escenas del pueblo �lfico.\n");
    AddDetail(({"cocina", "cocinita", "cocinilla"}), "Es una peque�a cocina situada en la pared norte de la sala. B�sicamente consta de un peque�o fog�n y unos cuantos cacharros: una sart�n, una oya, un caldero y un cuchar�n.\n");
    AddDetail(({"cacharros", "cuchar�n", "cucharon", "olla", "sart�n", "sarten", "caldero"}), "Son unos cacharros de cocina, que aunque oxidados, a�n pueden realizar perfectamente su trabajo.\n");
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