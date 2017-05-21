/****************************************************************************
Fichero: /guilds/kisalas/pnj/sylana.c
Autor: Yalin
Fecha: 28/01/2008 17:16
Descripción: Hechicera de la tienda de magia.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <spellmonster.h>
#include <guild.h>
#include <rooms.h>
inherit SPELLMONSTER;
#define ART(x)   (x->QueryGenderEndString())

int c_luz();

create()
{
    ::create();
    SetStandard("Sylana","medio-elfo",([GC_KISALA:30 ]),GENERO_FEMENINO);
    SetName("Sylana");
    SetShort("Sylana, la experta hechicera");
    SetLong("Es la hechicera encargada de la tienda.\nEs una medio elfa no muy alta, y un poco "
        "delgada.\nTiene un pelo negro y largo, cayendo sobre su espalda, y unos inquisitivos "
        "ojos castaños, que miran con extrema atención los mínimos detalles de cuanto la rodea. "
        "Sus gruesos labios, muy rojos, nunca pierden la franca sonrisa con que parece "
        "obsequiarte.\n");
    AddId(({"Sylana","sylana","hechicera","tendera","kisala","medio elfa","medio-elfa","medio_elfa"}));
    AddSpell("luz cegadora",([
        S_FUN:SF(c_luz),
        S_SP:20,
        S_CHANCE:1000,
        S_VICTIMS:1,
    ]));
    AddItem(ARMA_GOLDHAI("abanico"),REFRESH_REMOVE,1,SF(wieldme));
    InitChats(5,({
        "Sylana mira dentro de una caja y mueve la cabeza.\n",
        "Sylana coloca unos frascos en los anaqueles.\n",
        "Sylana coge puñados de algo de varias cajas, y los mezcla en una gran vasija de barro.\n",
        "Sylana te mira y dice: ¿Quieres algo?\n",
        "Sylana observa el contenido de un frasco diciendo: Esto no me gusta...\n",
        "Sylana musita unas extrañas palabras, mientras añade unos polvos a un líquido que se "
            "va volviendo rojizo.\n"}));
}

int c_luz()
{
    object *adversarios, enemigo,bola;
    adversarios = QueryEnemies() || ({});
    if(!sizeof(adversarios)) return 0;
    enemigo = adversarios[random(sizeof(adversarios))];
    if (QuerySP() <10) return 0;
    AddSP(-10);
    seteuid(getuid(TO));
    bola=clone_object(EFFECT_LUZ_CEGADORA);
    bola->SetInitChat("Los ojos  deSylana te deslumbran.\n");
    bola->SetEndChat("Los ojos de Sylana dejan de deslumbrarte.\n");
    bola->SetEnvInitChat("Sylana deslumbra a "+capitalize(enemigo->QueryName())+".\n",enemigo);
    bola->SetEnvEndChat("Sylana deja de deslumbrar a "+capitalize(enemigo->QueryName())+".\n",
        enemigo);
    say("Sylana se concentra y mira a "+capitalize(enemigo->QueryName())+". De sus ojos emana "
        "una potente luz.\n",enemigo);
    tell_object(enemigo,"Sylana se concentra y fija su mirada en ti. De sus ojos emana una "
        "potente luz.\n");
    if (bola->Affect(enemigo,8)) play_sound(environment(),SND_MAGIA("luz_cegadora"));
}
        