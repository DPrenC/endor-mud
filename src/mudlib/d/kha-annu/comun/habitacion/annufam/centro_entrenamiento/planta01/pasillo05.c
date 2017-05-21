/****************************************************************************
Fichero: pasillo05.c
Autor: Riberales
Fecha: 06/03/2006
Descripci�n: Pasillo del CAGE, escaleras.
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("pasillo_base");

create()
{
    ::create();

    SetIntShort("el Centro de Adiestramiento");
    SetIntLong("Est�s junto a las escaleras del Centro de Adiestramiento de "
               "Guerreros Enanos de Annufam. La decoraci�n de este lugar es "
               "verdaderamente austera aunque est� bien iluminado por las "
               "salidas que tiene al norte y al sur. Hacia arriba podr�s ir a "
               "las habitaciones de los reclutas, hacia el norte puedes ir a "
               "la Arena, hacia el sur tienes la entrada del centro y el "
               "pasillo se prolonga de este a oeste.\n");

    AddDetail(({"escalera","escaleras"}),
                "Son unas escaleras de piedra sin mayor ornamentaci�n que una "
                "cabeza de le�n al principio de la barandilla. Si subes por "
                "ellas llegar�s al piso donde los reclutas tienen sus "
                "habitaciones.\n");

    AddExit("norte",HAB_PRIMERA_ANNUFAM("pasillo06"));
    AddExit("sur",HAB_PRIMERA_ANNUFAM("entrada"));
    AddExit("este",HAB_PRIMERA_ANNUFAM("pasillo07"));
    AddExit("oeste",HAB_PRIMERA_ANNUFAM("pasillo04"));
//    AddExit("arriba",HAB_SEGUNDA_ANNUFAM("pasillo05"));
    AddExit("arriba",HAB_SEGUNDA_ANNUFAM("c114"));

    AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
    AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);

}

