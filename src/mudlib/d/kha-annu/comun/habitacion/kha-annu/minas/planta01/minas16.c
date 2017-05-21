/**************************************************************************
fichero: minas16.c
Autor: Riberales
Creación: 31/10/05
Descripción: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"
#include <materials.h>

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("una cámara en las minas");
    SetIntLong("Te encuentras en una de las muchas cámaras que han "
               "sobreexplotado los enanos para la extracción de mineral. Las "
               "paredes están totalmente destrozadas a golpe de pico, y debido"
               " a la oscuridad del lugar, sólo interrumpida por leves "
               "destellos del norte, hacen que imagines escenas escalofriantes"
               " viendo la roca. Aún así, puede que quede algo por picar.\n");

    SetTipo(M_HIERRO);
    DetalleVeta();


    AddExit("norte",HAB_PRIMERA_MINAS("minas15"));

    AddItem(PNJ_MINAS("minero_primera"),REFRESH_DESTRUCT);
    AddGuardia();
}
