/*****************************************************************************************
 ARCHIVO:       robledal19.c
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

    SetIntShort("un pequeño camino");
    SetIntLong("Te encuentras en la zona mas profunda de este gran bosque, si pensabas "
        "que el fin de este laberinto arbóreo se encontraba cerca, la densidad con la "
        "que crecen aquí robles y todo tipo de árboles te hace cambiar de idea. Aquí "
        "la alfombra que cubre el suelo es más densa y las mantas de líquenes de los "
        "árboles son mucho más tupidas.\nBuscas algo de luz para poderte orientar "
        "pero la penumbra lo envuelve todo, ni siquiera un tenue rayo de luz es capaz "
        "de filtrarse entre las copas de estos majestuosos árboles.\n");
    AddDetail(({"robles", "arboles", "árboles"}), "En este punto del bosque la "
        "vegetación es mucho más tupida. Los árboles son altos, y sus troncos muy "
        "gruesos.\n");
    AddDetail(({"alfombra", "agujas", "hojarasca"}), "Montones de bellotas, agujas de "
        "pino y hojarasca se mezclan en el suelo formando una capa practicamente "
        "impenetrable.\n");
    AddDetail(({"manta", "mantas", "liquenes", "líquenes"}), "A duras penas permiten "
        "atisbar cualquier rastro de corteza en los árboles.\n");
    AddDetail(({"corteza", "cortezas"}), "Te resulta muy difícil percibir las cortezas "
        "a causa de los líquenes.\n");

    AddExit("noreste", HAB_BOSQUE_ISLA("robledal25.c"));
    AddExit("sureste", HAB_BOSQUE_ISLA("robledal15.c"));
}
