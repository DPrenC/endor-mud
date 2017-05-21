/****************************************************************************
Fichero: thualin_003.c
Autor: Kastwey
Creación: 28/07/2005
Descripción: Continúa la calle Thualin
****************************************************************************/

#include "./path.h"
  inherit HAB_THUALIN_ANNUFAM("thualin_base");



public void create()
{
    ::create();
    SetIntShort("la calle Thualin");
    SetIntLong(W("Te encuentras en la Calle Thualin, famoso enano que "
                 "participó activamente en la lucha contra los orcos y del "
                 "que hoy por hoy se desconoce su paradero. Al sur se "
                 "encuentra la posada de Annufam, para cuando algún familiar "
                 "viene a visitar a los guerreros o a hacer algún negocio en "
                 "la ciudad. Al norte sigue inexorable la pared sur del "
                 "Centro de Adiestramiento de Guerreros Enanos. La calle "
                 "sigue tanto al oeste como al este.\n"));

    AddLuzAntorchas();

    AddDetail(({"fachada sur","sur","posada","pared sur"}),
              W("Es la posada de la ciudad, dirigida por Roin el enano. Te "
                "das cuenta de que tiene dos alturas, y que la "
                "superior está ocupada por habitaciones.\n"));

    AddExit("oeste",HAB_THUALIN_ANNUFAM("thualin_02"));
    AddExit("este",HAB_THUALIN_ANNUFAM("thualin_04"));
    AddExit("sur",HAB_POSADA_ANNUFAM("entrada_posada"));
}
