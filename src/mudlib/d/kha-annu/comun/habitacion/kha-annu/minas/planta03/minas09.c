/**************************************************************************
fichero: minas09.c
Autor: Riberales
Creación: 23/12/05
Descripción: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("un pasillo de las minas");
    SetIntLong("Estás en cualquier lugar de las minas de Kha-annu, en alguno "
               "de sus túneles. Observas una carretilla aparcada al lado "
               "oriental del túnel, para no obstruir el paso. La galería "
               "continúa al sur y al norte, donde hay unas antorchas que "
               "ofrecen un poco de luz al lugar.\n");

    DetalleParedes();
    AddItem(OTRO_MINAS("carretilla_rota"));


    AddExit("norte",HAB_TERCERA_MINAS("minas07"));
    AddExit("sur",HAB_TERCERA_MINAS("minas10"));
    AddGuardia();
    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
}

