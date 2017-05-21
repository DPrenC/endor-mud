/**************************************************************************
fichero: minas20.c
Autor: Riberales
Creaci�n: 31/10/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"
#include <materials.h>

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("un t�nel");
    SetIntLong("Te hallas en las enrevesadas minas de Kha-annu. "
               "Por m�s que miras, no eres capaz de ver m�s que roca y m�s "
               "roca, aunque a tu lado, en la pared norte, hay una peque�a "
               "veta sin apenas tratar. La galer�a sigue hacia el este y el "
               "suroeste.\n");

    SetTipo(M_HIERRO);
    DetalleVeta();
    AddItem(OTRO_MINAS("carretilla_vacia"),REFRESH_DESTRUCT);



    AddExit("este",HAB_PRIMERA_MINAS("minas21"));
    AddExit("suroeste",HAB_PRIMERA_MINAS("minas19"));
    AddGuardia();
}

