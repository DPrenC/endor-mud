/**************************************************************************
fichero: minas19.c
Autor: Riberales
Creaci�n: 31/10/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("la continuaci�n de un  t�nel");
    SetIntLong("Sigues uno de los t�neles principales de estas minas. En este "
               "punto, las paredes se ensanchan ligeramente, quit�ndote de la "
               "cabeza esa sensaci�n de claustrofobia. Adem�s, una buena dosis"
               " de luz llega del sur y tambi�n te calma. En esa direcci�n "
               "observas un arco que va a dar a un cruce, mientras que la "
               "galer�a sigue su curso hacia el nordeste.\n");

    DetalleParedes();
    AddDetail("arco","Es el resultado de la escavaci�n por el t�nel. Permite "
              "la comunicaci�n del t�nel con el cruce que hay al sur.\n");


    AddExit("nordeste",HAB_PRIMERA_MINAS("minas20"));
    AddExit("sur",HAB_PRIMERA_MINAS("minas18"));
    AddGuardia();
}

