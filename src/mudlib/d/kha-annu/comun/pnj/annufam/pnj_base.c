/***************************************************************************
Fichero: pnj_base.c
autor: kastwey
Creación: 12/10/2005
Descripción: PNJ base de la zona de annufam
***************************************************************************/

#include "./path.h"

inherit NPC;

public int AddEnemy(object en)
{
    int result = ::AddEnemy(en);
    // dtell("kastwey",sprintf("El previous es %O.\n",PO));
    if (result == 1 && (!PO || !PO->QueryDefensorAnnufam()))
    // propaga la llamada a todos los defensores que haya en esta room.
    {
        filter(all_inventory(environment()),(:(   $1->QueryDefensorAnnufam()
                                               && $1 != TO ? $1->AddEnemy($2)
                                           : 0):), en);
    }
    return result;
}

