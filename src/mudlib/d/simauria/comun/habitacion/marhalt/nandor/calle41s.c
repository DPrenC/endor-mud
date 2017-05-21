
/****************************************************************************
Fichero: calle41s.c
Autor: Buh
Fecha: 13/08/2007
Descripci�n: Una parte de la plaza de Nandor.
****************************************************************************/

#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create () {
    ::create();

    SetIntShort("la plaza de Nandor");
    SetIntLong("Te encuentras en la plaza de la villa de Nandor. En esta zona ves el "
        "pozo al que las mujeres del pueblo deben venir a buscar el agua. Por aqu�"
    " la tierra del suelo est� m�s compacta y con varias huellas de pies "
        "humanos. \n Al este ves un poste con un cartel de madera que no puedes leer "
        "desde aqu�.\n");

    SetLocate("Villa de Nandor");
    SetIndoors(0);
    AddDetail(({"encina","arbol"}),
        "Est� hacia el nordeste y es enorme. Sus ramas deben dar buena sombra.\n");
    AddDetail(({"pozo"}),
        "Es un simple pozo al que las mujeres se acercan a llenar sus c�ntaros.\n");
    AddDetail(({"mujeres","se�oras"}),
        "Las hay de todas las edades. Parece que el pozo es el centro de reuni�n y "
        "un lugar perfecto para el cotilleo, ya que todas charlan y rien animadamente.\n");
    AddDetail("fuente",
        "Es una peque�a fuente que est� en la parte norte de la plaza. Quiz� puedas "
        "beber agua de ella.\n");
    AddDetail("poste", "Est� en la parte este de la plaza  y parece que pertenece a la "
    "parada de la diligencia.\n");
    AddDetail(({"suelo", "tierra"}), "La tierra del suelo est� muy pisoteada en esta "
    "parte y se ha compactado considerablemente.\n");
    AddExit("norte","calle41n");
    AddExit("este", "calle42s");
    AddExit("sudeste","calle5");

}

