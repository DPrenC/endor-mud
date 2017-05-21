/****************************************************************************
Fichero: /d/simauria/comun/pnj/abadia/sieghen.c
Autor: Lug y Yalin
Fecha: 01/09/2006
Descripción: Monje del templo de la aldea.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>
#include <skills.h>
#include <spellmonster.h>
inherit PNJ("sherek/abadia/monje");

create()
{
    ::create();
    SetName("Sieghen");
    AddId("sieghen");
    SetShort("Sieghen, el monje");
    SetLong("Sieghen es un clérigo fuerte y astuto.\nEs un monje numerario de la abadía de "
        "Sherek.\nEs el representante de los monjes en la aldea, o tal vez el espía, o tal vez "
        "las dos cosas.\n");
    SetGoChance(0);
    InitChats(5,({"Sieghen reza: ¡Oh, Sherek! ¡Derrama tu fuerza sobre nosotros!\n",
        "Sieghen hace una reverencia hacia el altar.\n",
        "Sieghen te mira y dice: ¡No profanarás este lugar sagrado!\n",
        "Sieghen te pregunta: ¿Has venido a buscar el perdón, o tal vez buscas la luz del espíritu?\n",
        "Sieghen murmura: ¿Oh, sublime diosa! Ilumina nuestras vidas, y defiende nuestras propiedades.\n"}));
    InitAChats(5,({"Sieghen grita: ¡Maldit"+(TP->QueryGenderEndString())+" infiel! ¡Ahora "
            "conocerás la ira de Sherek!\n",
        "Sieghen ruge: ¡No sabes lo que has hecho, miserable!\n",
        "Sieghen dice en un mugido: ¡Vas a pagar por esto, impí"+(TP->QueryGenderEndString())+"!\n"}));
}

