/**************************************************************************
fichero: entrada_minas.c
Autor: Riberales
Creación: 05/01/06
Descripción: Entrada de las minas. Antes existía, pero estaba cerrada, y como
             no había encabezado, me agencio el archivo íntegro xD.
             **************************************************************************/

#include "./camino.h"

public void create()
{
    ::create();

    SetIntShort("el camino hacia las minas");
    SetIntLong("Te encuentras en un desvío que hay en el camino de Kha-annu y "
               "que llega hasta las minas enanas. La entrada de las mismas se "
               "encuentra al oeste, descendiendo al corazón de la montaña, "
               "mientras que en dirección este llegas al cruce con el "
               "camino.\n");


    SetOutdoors(1);
    AddDetail("entrada","Parece un túnel hacia el corazón de la montaña.\n");




    AddExit("este",CAMINO+"kha-kenton4");
    AddExit("oeste",HAB_MINAS("entrada_minas"));

}