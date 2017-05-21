/**************************************************************************
fichero: patrullero.c
Autor: Riberales.
Creación: 7/10/2005
Descripción: El soldado que se pasea por las murallas.
**************************************************************************/

#include "./path.h"
#include <properties.h>
#include <moving.h>
#include <combat.h>


inherit PNJ_CIUDAD_ANNUFAM("murallas/soldado_base");

public void create()
{
    ::create();

    seteuid(getuid());

    SetStandard("un patrullero","enano",50+random(4),GENDER_MALE);
    SetIds(({"patru_annufam","soldado_murallas","soldado patrullero","patrullero","soldado"}));
    SetShort("un soldado patrullero");
    SetLong(W("Se trata de un soldado patrullero. La función de este enano es "
              "ir paseando por toda la muralla por si hay algún imprevisto o por si alguno de sus "
              "compañeros necesita alguna cosa.\n"));

    AddItem(ARMA_ANNUFAM("ciudad/hacha_murallas"),REFRESH_REMOVE,SF(wieldme));
    AddItem(PROT_ANNUFAM("ciudad/coraza_murallas"),REFRESH_REMOVE,SF(wearme));
    SetGoChance(60);
    AddWalkZones(HAB_MURALLAS_ANNUFAM(""));


    InitChats(2,({
              "El soldado dice: Bien, por ahora todo tranquilo.\n",
              "El soldado te vigila por el rabillo del ojo.\n",
            "El soldado enano patrulla cerca de ti.\n"}));


}


public varargs int move(mixed dest, int method, mixed extra)
{
    object env = environment();
    if (method == M_GO && env)
    {
        tell_room(env,W("El patrullero canta: Apatrullaaaando "
                       "en Annufaaaam.... Apatrullaaando en Annufam...\n"));
    }
    return ::move(dest, method, extra);
}



