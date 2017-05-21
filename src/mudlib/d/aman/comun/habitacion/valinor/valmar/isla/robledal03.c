/*****************************************************************************************
 ARCHIVO:       robledal03.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Robledal en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("un acantilado sobre el lago");
    SetIntLong("Te encuentras encima de unas rocas negras desgastadas por el viento que "
        "se abren paso sobre el bosque con sus perfiles irregulares. Presiden y vigilan "
        "desde lo alto las tranquilas aguas del lago Glinnael.\n");
    AddDetail(({"rocas", "negras rocas"}), "Están perfectamente pulidas por la tenue "
        "brisa que da vida a la isla.\n");
    AddDetail(({"aguas", "agua", "lago", "Glinnael", "lago glinnael"}), "Parece que el "
        "agua es imperturbable. Desde este punto puedes atisbar, a lo lejos, la "
        "espesura del Gran Bosque de Faeria.\n");

    SetIntSmell("Huele a hojas frescas y a humedad.\n");
    SetIntNoise("Escuchas el leve choque de las aguas contra las rocas.\n");

    AddExit("noreste", HAB_BOSQUE_ISLA("robledal08.c"));
    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal06.c"));
}
