/**************************************************************************
fichero: minas29.c
Autor: Riberales
Creaci�n: 02/11/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("una hosca galer�a");
    SetIntLong("Te encuentras en lo que te parece el t�nel m�s oscuro que has "
               "inspeccionado hasta el momento. Las paredes se adhieren a tu "
               "cuerpo casi de forma �ntegra, y debes caminar con cuidado "
               "para no chocar con ning�n saliente. Este t�nel sigue al "
               "nordeste y al sudeste, donde se dislumbra algo m�s de "
               "claridad.\n");

    DetalleParedes();
    SetIntBright(0);
    AddItem(OTRO_MINAS("carretilla_vacia"),REFRESH_DESTRUCT);

    AddExit("nordeste",HAB_PRIMERA_MINAS("minas28"));
    AddExit("sudeste",HAB_PRIMERA_MINAS("minas30"));
    AddGuardia();
}
