/****************************************************************************
Fichero: pasillo_base
Autor: Riberales
Fecha: 19/02/2006
Descripci�n: Base del pasillo de la planta baja del CAGE.
****************************************************************************/


#include "path.h"

inherit BASE_ANNUFAM;

create()
{
    ::create();

    AddDetail(({"pared","paredes"}),
                "Las paredes de los pasillos de este centro son muy parecidas "
                "al suelo. Est�n hechas con piedra oscura y sin ning�n tipo "
                "de decoraci�n m�s que algunos faroles.\n");

    AddDetail("suelo",
            "Est� formado por piedras de color verde y marr�n a imitaci�n de "
            "la ense�a oficial del dominio de Kha-annu.\n");

    AddDetail("techo","Es un techo abovedado del que cuelgan algunos "
            "faroles.\n");

    AddDetail(({"farol","faroles"}),
              "Son faroles met�licos en cuyo interior arde una peque�a "
              "mecha.\n");

    SetIndoors(1);
    SetIntBright(45);
}
