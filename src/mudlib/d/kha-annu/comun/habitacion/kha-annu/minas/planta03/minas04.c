/**************************************************************************
fichero: minas04.c
Autor: Riberales
Creación: 22/12/05
Descripción: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"
#include <materials.h>
#include <properties.h>

inherit HAB_TERCERA_MINAS("tercera_base");



create()
{
    ::create();

    SetIntShort("una estancia de las minas");
    SetIntLong("Contemplas una de las múltiples cámaras que hay en las minas "
               "enanas. La roca de las paredes parece estar bastante "
               "machacada, aunque puede que queden algunos restos de mineral. "
               "La única salida se encuentra en dirección nordeste, donde te "
               "parece ver una galería bastante ancha.\n");

    SetTipo(M_MITHRIL);
    DetalleVeta();


    AddExit("nordeste",HAB_TERCERA_MINAS("minas03"));

    AddGuardia();
    AddItem(PNJ_MINAS("minero_tercera"),REFRESH_DESTRUCT,([P_GO_CHANCE:0]),1);
}


