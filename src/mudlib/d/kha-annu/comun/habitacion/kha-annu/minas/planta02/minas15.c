/**************************************************************************
fichero: minas15.c
Autor: Riberales
Creaci�n: 11/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"
#include <materials.h>

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("una galer�a sin salida");
    SetIntLong("Has llegado al t�rmino de una de las galer�as de la mina. "
               "Est�s totalmente rodead" +SEXO + " de roca, excepto en "
               "direcci�n nordeste donde sales a un cruce de t�neles. Parece "
               "que han dejado varias zonas de roca sin tratar y podr�as "
               "sacar algo de mineral, con un poco de suerte.\n");

    SetTipo(M_PLATA);
    DetalleVeta();

    AddExit("nordeste",HAB_SEGUNDA_MINAS("minas14"));
    AddGuardia();
}
