/**************************************************************************
fichero: patrullero.c
Autor: Riberales.
Creación: 7/10/2005
Descripción: El arquero que hay en Annufam.
**************************************************************************/

#include "./path.h"
#include <properties.h>
#include <combat.h>


inherit PNJ_CIUDAD_ANNUFAM("murallas/soldado_base");

public void create()
{
    ::create();

    seteuid(getuid());

    SetStandard("un arquero","enano",50+random(4),GENDER_MALE);
    SetIds(({"soldado_murallas","soldado arquero","arquero","soldado"}));
    SetShort("un soldado arquero");
    SetLong(W("Observas al soldado arquero. Se trata de un enano que, a orden "
              "del vigía o de motu propio, dispara sobre cualquier sospecha "
              "que ronde por las cercanías de Annufam.\n"));
    AddItem(ARMA_ANNUFAM("ciudad/arco_murallas"),REFRESH_REMOVE,SF(wieldme));
    AddItem(ARMA_ANNUFAM("ciudad/espada_murallas"),REFRESH_REMOVE,SF(wieldme));
    //AddItem(ARMA_ANNUFAM("ciudad/carcaj_murallas"),REFRESH_REMOVE,1);
    AddItem(PROT_ANNUFAM("ciudad/coraza_murallas"),REFRESH_REMOVE,SF(wearme));


    InitChats(3,({
                "el arquero mira al horizonte.\n",
              W("El enano tensa la cuerda del arco, y la suelta disparando "
                "una flecha imaginaria.\n"),
            "El arquero murmura: Paaaz y tranquilidad en los "
            "alrededores.\n"}));


}
