/*
DESCRIPCION  : camino a la cantera a traves del bosque de Morak
FICHERO      : camino05.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_MORAK("camino");

create()
{
    ::create();
   SetIntShort("el camino a la cantera, en el bosque de Morak");
    SetIntLong("La ascensi�n del camino se va haciendo cada vez m�s abrupta "
        "a medida que te encuentras m�s cerca de las monta�as de la "
        "cordillera de Kova. La cantera que se halla al pie de las monta�as "
        "no debe quedar muy lejos de aqu�, ya que las huellas de las "
        "carretas que transportan las pesadas piedras que de ella se extraen "
        "son muy frecuentes en esta parte del camino.\n");
    AddDetail(({"marcas","huellas"}),"En el suelo de tierra del camino se "
        "pueden ver algunas de las huellas que a su paso por aqu� dejan las "
        "carretas cargadas con las pesadas piedras que se extraen de la "
        "cantera.\n");
    AddExit("este",BOSQUE_MORAK("bosque15"));
    AddExit("oeste",BOSQUE_MORAK("bosque16"));
    AddExit("norte",BOSQUE_MORAK("cantera0"));
    AddExit("sur",BOSQUE_MORAK("camino11"));
}
