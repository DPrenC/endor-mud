/****************************************************************************
Fichero: pasillo_base
Autor: Riberales
Fecha: 19/02/2006
Descripción: Base del pasillo de la planta baja del CAGE.
****************************************************************************/


#include "path.h"

inherit BASE_ANNUFAM;

create()
{
    ::create();

    AddDetail(({"pared","paredes"}),
                "Las paredes de los pasillos de este centro son muy parecidas "
                "al suelo. Están hechas con piedra oscura y sin ningún tipo "
                "de decoración más que algunos faroles.\n");

    AddDetail("suelo",
            "Está formado por piedras de color verde y marrón a imitación de "
            "la enseña oficial del dominio de Kha-annu.\n");

    AddDetail("techo","Es un techo abovedado del que cuelgan algunos "
            "faroles.\n");

    AddDetail(({"farol","faroles"}),
              "Son faroles metálicos en cuyo interior arde una pequeña "
              "mecha.\n");

    SetIndoors(1);
    SetIntBright(45);
}
