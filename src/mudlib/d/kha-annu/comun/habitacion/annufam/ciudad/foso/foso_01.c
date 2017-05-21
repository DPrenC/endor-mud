/****************************************************************************
Fichero: foso_01.c
Autor: Riberales
Creación: 4/10/2005
Descripción: Un tramo de la calle Ungrim.
****************************************************************************/

#include "./path.h"
inherit HAB_FOSO_ANNUFAM("foso_base");



public void create()
{
    object avenida;
    ::create();
    // comprobamos el estado del portón
    avenida = load_object(HAB_AVENIDA_ANNUFAM("avenida_01"));
    SetIndoors(avenida->QueryPortonAbierto());
    // si el portón está abierto, esta habitación queda interior, ay que
    // el portón tapa el "cielo" del foso.




    SetIntShort("un foso");
    SetIntLong(W("Has ido a parar a un foso de unos cinco metros de "
                 "profundidad, todo rodeado de paredes de tierra. el agua "
                 "te cubre unos tres palmos. La verdad es que no parece un "
                 "buen sitio para pasar una tranquila noche. Sería mejor "
                 "que buscases la forma de salir de aquí antes de que sea "
                 "peor.\n"));

    AddExit("oeste",HAB_FOSO_ANNUFAM("foso_02"));
    AddExit("este",HAB_FOSO_ANNUFAM("foso_03"));
}

public void CambioPorton(int estado)
// cuando el portón se abre o se cierra, se ejecutará esta función
{
    SetIndoors(estado);
    if (estado)
    // el portón se ha abierto, por lo que el foso queda tapado
    {
        tell_room(TO,"Escuchas como el portón se cierra, dejando el lugar "
                     "completamente a oscuras.\n");
                     return;
    }
    tell_room(TO,"Observas como el portón se alza, dejando al descubierto "
                 "la parte superior del foso.\n");
}

