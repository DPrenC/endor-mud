/*
DESCRIPCION  : cantera al norte del bosque de Morak
FICHERO      : cantera0.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_MORAK("cantera");

create()
{
    ::create();
   SetIntShort("la entrada a la cantera del bosque de Morak");
    SetIntLong("Te encuentras en la entrada de la cantera del bosque de "
        "Morak. La cantera es una explanada de mediano tama�o junto a una "
        "gran pared rocosa al pie mismo de las monta�as de la cordillera de "
        "Kova.\nJunto a la pared de la que se extraen los bloques de piedra, "
        "se han construido varios andamios de madera. En el l�mite oeste de "
        "la cantera se han construido tambi�n un par de r�sticas caba�as.\n"
        "Un camino parte de aqu� hacia el sur adentr�ndose en el bosque.\n");
    AddExit("norte",BOSQUE_MORAK("cantera2"));
    AddExit("este",BOSQUE_MORAK("bosque39"));
    AddExit("sur",BOSQUE_MORAK("camino05"));
    AddExit("oeste",BOSQUE_MORAK("cantera1"));
}
