/****************************************************************************
Fichero: avenida_05.c
Autor: Kastwey
Creación: 27/07/2005
Descripción: Sigue la avenida real de Annufam
****************************************************************************/

#include "./path.h"

inherit BASE_CIUDAD_ANNUFAM;

public void create()
{
    ::create();
    SetIntShort("la avenida real de Annufam");
    SetIntLong(W("Te encuentras en la parte más norteña de la avenida que "
                 "divide en dos la ciudad de Annufam. Al norte ya divisas el "
                 "gran edificio del centro de entrenamiento, detrás de lo "
                 "que te parece una plaza. Al este puedes ver la pared "
                 "lateral del banco, y al oeste, la de la sucursal de "
                 "consignas.\n"));

    AddDetail(({"pared este","este"}),
              W("Esta es la pared del banco de la ciudad. Es una pared "
                "como otra cualquiera, sin nada destacable.\n"));

    AddDetail("pared","¿Qué pared quieres mirar exactamente?\n");

    AddDetail(({"pared oeste","oeste"}),
              W("Se trata de la pared de la sucursal de consignas.\n"
                "La verdad es que no tiene mucho de interesante.\n"));

    AddSuelo();
    AddLuzAntorchas();

    AddExit("sur",HAB_AVENIDA_ANNUFAM("avenida_04"));
    AddExit("norte",HAB_CIUDAD_ANNUFAM("plaza"));

}

