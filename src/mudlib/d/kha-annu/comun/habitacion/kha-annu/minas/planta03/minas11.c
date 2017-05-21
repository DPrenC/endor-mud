/**************************************************************************
fichero: minas11.c
Autor: Riberales
Creaci�n: 26/12/05
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("las minas enanas");
    SetIntLong("Te hallas en las entra�as de estas minas enanas. Observas un "
               "par de antorchas que permiten ver lo que tienes a tu "
               "alrededor, y un cartel debajo de las mismas. El t�nel sigue "
               "hacia el noroeste y hacia el sur.\n");


    DetalleParedes();
    DetalleAntorchas();
    AddDetail("cartel",
              "Es un cartel con algo escrito, quiz� sea bueno que lo leas.\n");

    AddReadMsg("cartel",
               "***\nNota para nuestros queridos hermanos.\n\n"
               "Avisamos de alg�n peligro en el sur de este nivel... y "
               "recordad, la curiosidad mat� al orco.\n\n"
               "El gremio de mineros enanos.\n***\n");


    AddExit("noroeste",HAB_TERCERA_MINAS("minas10"));
    AddExit("sur",HAB_TERCERA_MINAS("minas12"));
    AddGuardia();
}
