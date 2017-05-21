/*****************************************************************************************
 ARCHIVO:       elfo.c
 AUTOR:         Ztico
 FECHA:         02-05-2005
 DESCRIPCIÓN:   Elfo de Faeria.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;

create()
{
    if(::create()) return 1;

    SetStandard("un elfo", "elfo", ([GC_GUARDABOSQUE: 50 + d10()]), GENERO_MASCULINO);
    SetShort("un elfo silvano");
    SetLong("Posee rasgos que son delicadamente cincelados, angulosos y hermosos. Es "
        "delgado y oculta su fuerza natural bajo un velo de fragilidad. Su tez es "
        "blanquecina y su cabello, rojo cobrizo, está trenzado y cae elegantemente "
        "sobre su espalda. Como todo elfo, tiene las orejas puntiagudas, que le "
        "proporcionan un oído extremadamente agudo.\n");
    AddId("elfo silvano");
    SetGoChance(4);
    AddWalkZones(({HAB_VALMAR("senderos/"), HAB_VALMAR("bosque_central/"),
    	             HAB_VALMAR("bosque_driadas/")}));

    AddItem(OBJ_ARMA_VALINOR("espada_corta"), REFRESH_REMOVE, SF(wieldme));
}
