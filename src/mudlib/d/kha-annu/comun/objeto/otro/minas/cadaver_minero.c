/***************************************************************************************
 ARCHIVO:	cadaver_minero_vacia.c
 AUTOR:		Riberales
 FECHA:		24/11/05
 Descripci�n: El cad�ver de un minero.
 ***************************************************************************************/

#include "path.h"



inherit "/std/corpse";



public void create ()
{
    ::create();
    object perneras;

    SetShort("el cad�ver de un minero");
    SetLong("Observas los restos mortales de alg�n minero que se qued� "
            "encerrado en esta galer�a. Apenas quedan los huesos y las "
            "ropas del desgraciado.\n");

    SetIntShort("un cad�ver");
    SetIntLong("En un cad�ver.\n");
    SetIds(({"minero","cadaver","cad�ver","enano","cadaver de minero"}));


    SetNoGet("Deja a los muertos tranquilos.\n");
    SetMaxIntWeight(35000);
    SetWeight(60000);

    perneras = clone_object(PROT_MINAS("perneras"));
    perneras->move(TO);


}
