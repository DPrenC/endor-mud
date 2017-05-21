/**************************************************************************
fichero: entrada_minas.c
Autor: Riberales
Creaci�n: 05/01/06
Descripci�n: Entrada de las minas. Antes exist�a, pero estaba cerrada, y como
             no hab�a encabezado, me agencio el archivo �ntegro xD.
             **************************************************************************/

#include "./camino.h"

public void create()
{
    ::create();

    SetIntShort("el camino hacia las minas");
    SetIntLong("Te encuentras en un desv�o que hay en el camino de Kha-annu y "
               "que llega hasta las minas enanas. La entrada de las mismas se "
               "encuentra al oeste, descendiendo al coraz�n de la monta�a, "
               "mientras que en direcci�n este llegas al cruce con el "
               "camino.\n");


    SetOutdoors(1);
    AddDetail("entrada","Parece un t�nel hacia el coraz�n de la monta�a.\n");




    AddExit("este",CAMINO+"kha-kenton4");
    AddExit("oeste",HAB_MINAS("entrada_minas"));

}