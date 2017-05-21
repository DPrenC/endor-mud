/*****************************************************************************************
 ARCHIVO:       robledal19.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCI�N:   Robledal en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("un peque�o camino");
    SetIntLong("Te encuentras en la zona mas profunda de este gran bosque, si pensabas "
        "que el fin de este laberinto arb�reo se encontraba cerca, la densidad con la "
        "que crecen aqu� robles y todo tipo de �rboles te hace cambiar de idea. Aqu� "
        "la alfombra que cubre el suelo es m�s densa y las mantas de l�quenes de los "
        "�rboles son mucho m�s tupidas.\nBuscas algo de luz para poderte orientar "
        "pero la penumbra lo envuelve todo, ni siquiera un tenue rayo de luz es capaz "
        "de filtrarse entre las copas de estos majestuosos �rboles.\n");
    AddDetail(({"robles", "arboles", "�rboles"}), "En este punto del bosque la "
        "vegetaci�n es mucho m�s tupida. Los �rboles son altos, y sus troncos muy "
        "gruesos.\n");
    AddDetail(({"alfombra", "agujas", "hojarasca"}), "Montones de bellotas, agujas de "
        "pino y hojarasca se mezclan en el suelo formando una capa practicamente "
        "impenetrable.\n");
    AddDetail(({"manta", "mantas", "liquenes", "l�quenes"}), "A duras penas permiten "
        "atisbar cualquier rastro de corteza en los �rboles.\n");
    AddDetail(({"corteza", "cortezas"}), "Te resulta muy dif�cil percibir las cortezas "
        "a causa de los l�quenes.\n");

    AddExit("noreste", HAB_BOSQUE_ISLA("robledal25.c"));
    AddExit("sureste", HAB_BOSQUE_ISLA("robledal15.c"));
}
