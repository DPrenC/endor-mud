// Libreria de Armas de Simauria.
// Elaborada por [Gw]Greywolf, usando objetos creados por
// Woo, Angor, Nemesis, Kodex, Izet, Kintups y todos aquellos
// que han hecho algun arma en el mud. Gracias a ellos por
// su esfuerzo. Tambien son añadidas varias armas nuevas.
// Arma: Vara de Metal
// Fichero: vara_metal.c
// Fecha de creación: 22/11/04 [Gw]

#include <mud.h>
#include <combat.h>
#include <properties.h>

inherit WEAPON;


create()
{

 ::create();
 SetStandard(WT_VARA,6,P_SIZE_MEDIUM,M_ACERO);
 SetWeight(2000);
 SetShort("una vara de acero");
 SetIds(({"vara","vara de metal"}));
 AddAdjective("acero");
 AddAdjective("de acero");
 SetNumberHands(1);
 Set(P_GENDER,GENDER_FEMALE);
 SetLong("\
Ves una larga vara de acero con una cuerda atada en el centro para que puedas\n\
sujetarla mejor en el combate.\n");
}
