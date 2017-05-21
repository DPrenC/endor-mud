/**************************************************************************
fichero: minas15.c
Autor: Riberales
Creación: 11/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"
#include <materials.h>

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("una galería sin salida");
    SetIntLong("Has llegado al término de una de las galerías de la mina. "
               "Estás totalmente rodead" +SEXO + " de roca, excepto en "
               "dirección nordeste donde sales a un cruce de túneles. Parece "
               "que han dejado varias zonas de roca sin tratar y podrías "
               "sacar algo de mineral, con un poco de suerte.\n");

    SetTipo(M_PLATA);
    DetalleVeta();

    AddExit("nordeste",HAB_SEGUNDA_MINAS("minas14"));
    AddGuardia();
}
