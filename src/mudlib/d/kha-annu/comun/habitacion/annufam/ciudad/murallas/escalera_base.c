/****************************************************************************
Fichero: escalera_base.c
Autor: Riberales
Creaci�n: 7/10/2005
Descripci�n: Base de Torre  que va a lo alto de las murallas.
****************************************************************************/

#include "./path.h"


inherit BASE_CIUDAD_ANNUFAM;

public void create()
{
    ::create();

    AddDetail ("suelo",
             "Es de piedra, como el resto de la torre donde te "
             "encuentras.\n");

    AddDetail(({"escalera","escaleras"}),
              "Est�n hechas con el mismo material que el suelo y las "
              "paredes. As� se evita que se puedan quemar y que los enanos "
              "que patrullan en las murallas queden incomunicados.\n");

    AddDetail(({"pared","paredes"}),
              "Son de piedra, y bastante gruesas por lo que puedes "
              "comprobar. En una de sus paredes observas un emblema.\n");

    AddEstandarte(EST_NORMAL);

    SetIndoors(1);
    SetIntBright(70);

}
