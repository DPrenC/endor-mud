/**************************************************************************
fichero: minas16.c
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

    SetIntShort("una c�mara en las minas");
    SetIntLong("Te encuentras en una de las muchas c�maras que han "
               "sobreexplotado los enanos para la extracci�n de mineral. Las "
               "paredes est�n totalmente destrozadas a golpe de pico, y debido"
               " a la oscuridad del lugar, s�lo interrumpida por leves "
               "destellos del norte, hacen que imagines escenas escalofriantes"
               " viendo la roca. A�n as�, puede que quede algo por picar.\n");

    SetTipo(M_HIERRO);
    DetalleVeta();


    AddExit("norte",HAB_PRIMERA_MINAS("minas15"));

    AddItem(PNJ_MINAS("minero_primera"),REFRESH_DESTRUCT);
    AddGuardia();
}
