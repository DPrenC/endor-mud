/***************************************************************************************
 ARCHIVO:	cadaver_minero_vacia.c
 AUTOR:		Riberales
 FECHA:		24/11/05
 Descripción: El cadáver de un minero.
 ***************************************************************************************/

#include "path.h"



inherit "/std/corpse";



public void create ()
{
    ::create();
    object perneras;

    SetShort("el cadáver de un minero");
    SetLong("Observas los restos mortales de algún minero que se quedó "
            "encerrado en esta galería. Apenas quedan los huesos y las "
            "ropas del desgraciado.\n");

    SetIntShort("un cadáver");
    SetIntLong("En un cadáver.\n");
    SetIds(({"minero","cadaver","cadáver","enano","cadaver de minero"}));


    SetNoGet("Deja a los muertos tranquilos.\n");
    SetMaxIntWeight(35000);
    SetWeight(60000);

    perneras = clone_object(PROT_MINAS("perneras"));
    perneras->move(TO);


}
