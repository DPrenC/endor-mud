/**************************************************************************
fichero: arco_murallas.c
Autor: Riberales
Creaci�n: 9/10/2005
Descripci�n: Un arco para los enanos de la muralla y los del centro
**************************************************************************/

#include "./path.h"
#include <combat.h>
#include <properties.h>


inherit "obj/arco";

public void create()
{
    ::create();

    SetShort("un arco");
    SetLong(W("Es un arco de madera y bastante flexible. Si tienes punter�a "
              "y buen pulso es una buena arma de distancia, sin lugar a "
              "dudas.\n"));

}

