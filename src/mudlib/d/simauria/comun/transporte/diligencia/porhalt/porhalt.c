/****************************************************************************
Fichero: /d/simauria/comun/transporte/diligencia/porhalt/porhalt.c
Autor: Ratwor
Fecha: 30/03/2008
Descripción: La diligencia Porhalt, que hace el recorrido entre Enalel y Nandor
****************************************************************************/

#include "./path.h"
#include <properties.h>
inherit STAGECOACH;

create(){
    seteuid(getuid(TO));
    ::create();
    SetShort("La diligencia Porhalt");
    SetLong("Esta es la diligencia Porhalt, también llamada 'La Norteña' debido "
    "a que su trayecto lo acostumbra a hacer por la parte norte del dominio de "
    "Simauria.\n Actualmente su recorrido es entre Enalel y Nandor.\n");
    Set(P_NOGET, "Mejor no la muevas mucho que se pueden alterar los caballos.\n");
    Set(P_NOSELL, "No deberías.\n");
    SetDnombre("porhalt");
    SetDhabitacion(PORHALT("intporhalt"));
    SetDmensajes_entrar(({"entra en la diligencia",
        "sube a la Norteña",
        "Subes a la diligencia Porhalt"}));
    SetDmensaje_llega("La diligencia Porhalt llega tirada fuertemente por sus caballos.\n");
    SetDmensaje_seva("La diligencia Porhalt se aleja velozmente.\n");
    SetRecorrido(PORHALT("porhalt.txt"));
    SetInicio(ENALHAB"poblado/calles/calle05");
    SetParadas(({({ENALHAB"poblado/calles/calle05",50,1000}),
        ({MARH("nandor/calle42s"),50,1000})}));
    SetDestinos(({"Enalel","Nandor"}));
    SetDconductor(PNJ("diligencia/porhalt"));
    SetNombreConductor("Brand");
}

