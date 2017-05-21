/**************************************************************************
fichero: minas05.c
Autor: Riberales
Creaci�n: 27/10/05
Descripci�n: Room en primera planta de las minas.
**************************************************************************/


#include "path.h"
#include <materials.h>


inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("una galer�a de las minas");
    SetIntLong("Sigues por una galer�a bastante bien iluminada, ya que un "
               "poco m�s al norte observas una antorcha que proporciona luz "
               "hasta tu posici�n. Parece que esta parte la han explotado "
               "mucho, aunque en la pared este podr�a quedar alg�n residuo "
               "de mineral. La galer�a se extiende en direcci�n norte y en direcci�n sudeste, donde "
               "observas una bifurcaci�n.\n");

    SetTipo(M_HIERRO);
    DetalleVeta();

    AddExit("norte",HAB_PRIMERA_MINAS("minas06"));
    AddExit("sudeste",HAB_PRIMERA_MINAS("minas03"));
    AddGuardia();
}
