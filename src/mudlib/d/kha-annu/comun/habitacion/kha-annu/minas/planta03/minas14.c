/**************************************************************************
fichero: minas14.c
Autor: Riberales
Creación: 26/12/05
Descripción: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"
#include <materials.h>
#include <properties.h>


inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("un recodo de las minas");
    SetIntLong("Estás adentrado en las galerías y túneles de las minas "
               "enanas del sur de Kha-annu. En este recodo observas algo de "
               "mineral en la roca sin extraer, aunque en menor cantidad de "
               "lo que sueles observar. La mina sigue al sudeste y al "
               "suroeste.\n");

    SetTipo(M_MITHRIL);
    p_veces_picadas = 5; //Para que saquen menos mt.
    DetalleVeta();


    AddExit("sudeste",HAB_TERCERA_MINAS("minas16"));
    AddExit("suroeste",HAB_TERCERA_MINAS("minas13"));
    AddGuardia();
    AddItem(PNJ_MINAS("minero_tercera"),REFRESH_DESTRUCT,([P_GO_CHANCE:0]),1);
}

