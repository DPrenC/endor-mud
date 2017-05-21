/**************************************************************************
fichero: minas05.c
Autor: Riberales
Creación: 27/10/05
Descripción: Room en primera planta de las minas.
**************************************************************************/


#include "path.h"
#include <materials.h>


inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("una galería de las minas");
    SetIntLong("Sigues por una galería bastante bien iluminada, ya que un "
               "poco más al norte observas una antorcha que proporciona luz "
               "hasta tu posición. Parece que esta parte la han explotado "
               "mucho, aunque en la pared este podría quedar algún residuo "
               "de mineral. La galería se extiende en dirección norte y en dirección sudeste, donde "
               "observas una bifurcación.\n");

    SetTipo(M_HIERRO);
    DetalleVeta();

    AddExit("norte",HAB_PRIMERA_MINAS("minas06"));
    AddExit("sudeste",HAB_PRIMERA_MINAS("minas03"));
    AddGuardia();
}
