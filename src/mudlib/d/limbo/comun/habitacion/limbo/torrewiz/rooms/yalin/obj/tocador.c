#include "path.h"
#include <properties.h>
#include <colours.h>
#include <moving.h>
#include <lock.h>
#include <search.h>
inherit "/std/room/items";
inherit "/std/container";
#define AO (TP->QueryGender()==GENERO_FEMENINO?"a":"o")

public int abrir_(string str)
{
    if (TO->id(str))
    {
        write("No ves "+str+" que abrir.\n");
        return 1;
    }
    return 0;
}

public int cerrar_(string str)
{
    if (TO->id(str))
    {
        write("No ves "+str+" que cerrar.\n");
        return 1;
    }
    return 0;
}

create()
{
    "*"::create();
    SetIds(({"tocador"}));
    SetShort("el tocador");
    SetLong("Es un mueble peque�o y alargado, con forma de mesa, pero con adornos tallados en sus "
        "bordes, que cubren en parte el arranque de las patas.\nSe usa para dejar sobre �l objetos "
        "de uso personal, generalmente frascos de perfume, ung�ento etc, joyeros, peines...\nEst� "
        "hecho de la misma madera de s�ndalo que el resto de los muebles de la alcoba, y tiene un "
        "espejo peque�o sobre su borde posterior, contra la pared, a prop�sito para peinarse.\n");
    AddId(({"tocador"}));
    SetAds(({"de madera"}));
    AddSubDetail(({"espejo"}),"Ves tu cara en el espejo, y no te lo crees. Tal vez debieras "
        "mirarte en el del armario...\n");
    Set(P_GENDER,GENERO_MASCULINO);
    SetPreContent("Sobre �l hay: ");
    Set(P_NOGET,"�Qu� inocente eres! �En serio pensabas cogerlo?\n");
    Set(P_LOCKSTATE,LOCK_OPEN);
    SetMaxIntWeight(10000);
}
  
init()
{
    ::init();
    add_action("cerrar_","cerrar");
    add_action("abrir_","abrir");
}
        