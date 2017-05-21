/**************************************************************************
fichero: minas03.c
Autor: Riberales
Creación: 23/10/05
Descripción: Room en primera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();
    SetIntShort("una bifurcación de las minas");
    SetIntLong("Has llegado a un punto de las minas donde hay varias "
               "direcciones para elegir. La del noroeste parece que sea más "
               "transitada, pues el suelo aparenta estar en mejores "
               "condiciones para caminar. Aún así, la que va al suroeste no "
               "está mal del todo y podría contener vetas sin tratar. La "
               "del norte es la más angosta y oscura, mientras que la del "
               "este es la más ancha de todas.\n");


    DetalleParedes();

    AddExit("norte",HAB_PRIMERA_MINAS("minas04"));
    AddExit("noroeste",HAB_PRIMERA_MINAS("minas05"));
    AddExit("suroeste",HAB_PRIMERA_MINAS("minas11"));
    AddExit("este",HAB_PRIMERA_MINAS("minas02"));

    AddItem(PNJ_MINAS("minero_primera"),REFRESH_DESTRUCT);
    AddGuardia();
}
