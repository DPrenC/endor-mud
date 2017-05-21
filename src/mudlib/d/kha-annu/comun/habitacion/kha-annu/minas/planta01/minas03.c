/**************************************************************************
fichero: minas03.c
Autor: Riberales
Creaci�n: 23/10/05
Descripci�n: Room en primera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();
    SetIntShort("una bifurcaci�n de las minas");
    SetIntLong("Has llegado a un punto de las minas donde hay varias "
               "direcciones para elegir. La del noroeste parece que sea m�s "
               "transitada, pues el suelo aparenta estar en mejores "
               "condiciones para caminar. A�n as�, la que va al suroeste no "
               "est� mal del todo y podr�a contener vetas sin tratar. La "
               "del norte es la m�s angosta y oscura, mientras que la del "
               "este es la m�s ancha de todas.\n");


    DetalleParedes();

    AddExit("norte",HAB_PRIMERA_MINAS("minas04"));
    AddExit("noroeste",HAB_PRIMERA_MINAS("minas05"));
    AddExit("suroeste",HAB_PRIMERA_MINAS("minas11"));
    AddExit("este",HAB_PRIMERA_MINAS("minas02"));

    AddItem(PNJ_MINAS("minero_primera"),REFRESH_DESTRUCT);
    AddGuardia();
}
