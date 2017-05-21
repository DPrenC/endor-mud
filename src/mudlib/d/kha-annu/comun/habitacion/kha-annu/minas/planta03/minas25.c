/**************************************************************************
fichero: minas25.c
Autor: Riberales
Creaci�n: 2/1/06
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/




#include "path.h"


inherit HAB_TERCERA_MINAS("tercera_base");


        create()
{

    ::create();

    SetIntShort("una estrecha galer�a");
    SetIntLong("Te encuentras en una galer�a donde apenas puedes ponerte en "
               "pie, y mucho menos alargar los brazos, pues parece que est� "
               "hecha por los enanos m�s peque�os de todo el reino. El t�nel "
               "sigue al este, mientras que al noroeste parece que se va "
               "haciendo algo m�s ancho.\n");


    DetalleParedes();



    AddExit("noroeste",HAB_TERCERA_MINAS("minas24"));
    AddExit("este",HAB_TERCERA_MINAS("minas26"));
    AddGuardia();

    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
}

