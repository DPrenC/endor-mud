/****************************************************************************
Fichero: foso_01.c
Autor: Riberales
Creaci�n: 4/10/2005
Descripci�n: Un tramo de la calle Ungrim.
****************************************************************************/

#include "./path.h"
inherit HAB_FOSO_ANNUFAM("foso_base");



public void create()
{
    object avenida;
    ::create();
    // comprobamos el estado del port�n
    avenida = load_object(HAB_AVENIDA_ANNUFAM("avenida_01"));
    SetIndoors(avenida->QueryPortonAbierto());
    // si el port�n est� abierto, esta habitaci�n queda interior, ay que
    // el port�n tapa el "cielo" del foso.




    SetIntShort("un foso");
    SetIntLong(W("Has ido a parar a un foso de unos cinco metros de "
                 "profundidad, todo rodeado de paredes de tierra. el agua "
                 "te cubre unos tres palmos. La verdad es que no parece un "
                 "buen sitio para pasar una tranquila noche. Ser�a mejor "
                 "que buscases la forma de salir de aqu� antes de que sea "
                 "peor.\n"));

    AddExit("oeste",HAB_FOSO_ANNUFAM("foso_02"));
    AddExit("este",HAB_FOSO_ANNUFAM("foso_03"));
}

public void CambioPorton(int estado)
// cuando el port�n se abre o se cierra, se ejecutar� esta funci�n
{
    SetIndoors(estado);
    if (estado)
    // el port�n se ha abierto, por lo que el foso queda tapado
    {
        tell_room(TO,"Escuchas como el port�n se cierra, dejando el lugar "
                     "completamente a oscuras.\n");
                     return;
    }
    tell_room(TO,"Observas como el port�n se alza, dejando al descubierto "
                 "la parte superior del foso.\n");
}

