/*****************************************************************************************
 ARCHIVO:       robledal00.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Embarcadero Isilhopa en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit PORT;

create()
{
    if(::create()) return 1;

    SetIntShort("el embarcadero Isilhopa");
    SetIntLong("Te encuentras en un pequeño embarcadero a orillas del lago Glinnael. "
        "El agua del lago es nítida y transparente. Toda la isla está sumida en una "
        "intensa niebla. Apenas puedes divisar un conjunto de casas hacia el "
        "nordeste.\n");
    AddDetail(({"embarcadero", "muelle"}), "Es de madera.\n");
    AddDetail("suelo", "De entre las rendijas crecen hierbecillas.\n");
    AddDetail(({"hierbecillas", "hierbecilla"}), "Dan un aspecto bastante envejecido al "
        "muelle.\n");
    SetIntSmell("Huele a las hojas mojadas por la lluvia y al denso matojo que rodea al "
        "muelle.\n");
    SetIntNoise("Escuchas el chapoteo del agua contra la vieja madera el embarcadero.\n");

    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal04.c"));
    AddExit("este", HAB_BOSQUE_ISLA("robledal01.c"));

    AddShip(BARCO("barca_faeria/barca_glinnael"));
}
