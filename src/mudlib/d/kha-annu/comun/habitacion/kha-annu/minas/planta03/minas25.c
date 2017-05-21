/**************************************************************************
fichero: minas25.c
Autor: Riberales
Creación: 2/1/06
Descripción: Room en tercera planta de las minas.
**************************************************************************/




#include "path.h"


inherit HAB_TERCERA_MINAS("tercera_base");


        create()
{

    ::create();

    SetIntShort("una estrecha galería");
    SetIntLong("Te encuentras en una galería donde apenas puedes ponerte en "
               "pie, y mucho menos alargar los brazos, pues parece que esté "
               "hecha por los enanos más pequeños de todo el reino. El túnel "
               "sigue al este, mientras que al noroeste parece que se va "
               "haciendo algo más ancho.\n");


    DetalleParedes();



    AddExit("noroeste",HAB_TERCERA_MINAS("minas24"));
    AddExit("este",HAB_TERCERA_MINAS("minas26"));
    AddGuardia();

    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
}

