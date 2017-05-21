/*****************************************************************************************
 ARCHIVO:       barquero.c
 AUTOR:         Ztico
 FECHA:         06-05-2005
 DESCRIPCI�N:   Es el barquero de la nube flotante.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <gremios.h>

inherit NPC;

create()
{
    if(::create()) return 1;

    SetStandard("barquero", "humano", ([GC_NINGUNO: 30]), GENERO_MASCULINO);
    SetShort("el barquero");
    SetLong("Se trata de un humano entrado en edad. De su cara crece una poblada barba "
        "blanca, la cual oculta practicamente todos sus rasgos. Va vestido con una "
        "t�nica negra y cubre su cabeza con la capucha.\n");
    AddItem(ARMOUR, REFRESH_REMOVE, SF(wearme),
        ([
            P_SHORT: "una t�nica negra",
            P_LONG:  "Es una t�nica vieja y ra�da.\n",
            P_ARMOUR_TYPE: AT_TUNICA,
            P_IDS: ({"tunica", "t�nica negra", "t�nica", "tunica negra"}),
            P_AC: 3,
            P_SIZE: P_SIZE_MEDIUM,
            P_RESET_QUALITY: 100,
            P_WEIGHT: 350,
            P_VALUE: 200
         ]));
}