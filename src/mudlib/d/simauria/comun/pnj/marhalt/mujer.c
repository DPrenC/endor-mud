/****************************************************************************
Fichero: mujer.c
Autor: Nemesis. Modificaciones por Yalin y Ratwor
Fecha: 14/08/2007
Descripción: Una mujer limpiadora para Nandor.
****************************************************************************/
#include <combat.h>
#include "path.h"
#include <properties.h>
#include <moving.h>
#include <messages.h>
inherit NPC;

void recoger_(object carta, object pl)
{
    if (!pl || member(carta->QueryIds(),"carta_betky") <0) return;
    if (!pl->QueryAttribute("carta_betky") || carta->QueryOwner() != TP->QueryRealName())
    {
        write("Betky abre la carta, y mirándote con cara de pocos amigos te grita: ¿A qué "
            "viene eso de darme papeles en blanco? ¿Crees que no tengo ya bastantes cosas "
            "inútiles? ¡Fuera, fuera de aquí! Estoy muy ocupada para tonterías.\nY a escobazos, "
            "te saca de la casa.\n");
        say("Betky abre la carta, y mira a "+capitalize(pl->QueryName())+" con cara de pocos "
            "amigos, gritándole: ¿A qué viene eso de darme papeles en blanco? ¿Crees que no "
            "tengo ya bastantes cosas inútiles? ¡Fuera, fuera de aquí! Estoy muy ocupada para "
            "tonterías.\nY a escobazos, le saca de la casa.\n",pl);
        carta->remove();
        if (carta) destruct(carta);
        pl->move(MARH("nandor/calle1"),M_GO);
        return;
    }
    write("Betky lee la carta, y su cara va dibujando una sonrisa irónica. Tira la carta al "
        "montón de basura que está recogiendo y dice: Ya sabía yo que algo de eso sería... "
        "¿Sabes? El pobrecito es tonto, ni siquiera para robar una manzana de un árbol sirve "
        "el muy zoquete, pero él se considera un salteador de caminos... En fin, al menos "
        "estará una temporadita a cubierto y alimentado, y yo no tendré que limpiar tanto.\n"
        "Luego te mira con gratitud en sus ojos y añade: Muchas gracias por traerme noticias, "+
        capitalize(pl->QueryName())+". Me gustaría hacerte algún regalo, pero entre toda esta "
        "basura que Jashim trae a casa dudo que haya algo que valga la pena... ¡Ah, claro! "
        "Mira, este pergamino es muy antiguo, quizá tenga algún valor.\n");
    pl->RemoveAttribute("carta_betky");
    carta->remove();
    if (carta) destruct(carta);
    object perga=clone_object("/guilds/conjuradores/pergamino/pergamino_lanza_acida");
    pl->SetAttribute("lanzaacido",time());
    write("Betky te da un pergamino antiguo.\n");
    if (!perga->move(pl))
    {
        perga->move(environment());
        write("Sin poder evitarlo, el pergamino se te cae de las manos.\n");
        say("a "+capitalize(pl->QueryName())+" se le cae un pergamino de las manos.\n",pl);
    }
    return;
}

string informa()
{
    if(TP->QueryAttribute("lanzaacido")) return "Betky sonríe y dice: Pues en la cárcel, aún "
        "no le han soltado, ¿sabes? Mejor así, no se creará problemas más serios.\n";
    return "Betky pone cara seria y dice: Jashim es un buen chico, ¿sabes?, lo que pasa es que "
        "no ha terminado de madurar..., y dudo que lo haga ya. El caso es que tiene la manía "
        "de..., esto..., conseguir cosas de forma no demasiado correcta, así que con toda "
        "probabilidad estará en alguna prisión, o ¡Dios mío! Tal vez se haya metido con algún "
        "desaprensivo y esté muerto...\nBetky se echa a llorar.\n";
}

create()
{
    ::create();
   seteuid(getuid());
    AddId(({"Betky", "betky", "humana", "mujer"}));
    SetStandard("Betky", "humano", 9, GENDER_FEMALE);
    SetShort("Betky");
    SetLong(
        "Betky es una mujer de mediana edad, regordeta y bajita, con unos graciosos "
        "mechones de pelo sueltos por la cara.\n Es una fregona auténtica. Empuña "
        "la escoba con destreza, y un plumero se asoma en su delantal.\n  Está "
        "levantando toda la roña acumulada en el suelo durante años y años.\n");
    AddQuestion("hermano",SF(informa),1);
    InitChats(5,({
        "Betky dice: 'Hay que ver, ¡qué asco de suelo!\n",
        "Betky te mira y dice: 'Tal vez quisieras echarme una mano.'\n",
        "Betky dice: '¡Mi hermano es un guarro!'\n",
        "Betky dice: '¡Estoy harta de barrer!'\n",
        "Betky canta: 'Láa laráa larita...'\n",
        "Betky mira inquisidoramente tus pies llenos de barro.\n",
        "Betky barre enérgicamente con su escoba.\n"}));
    SetCitizenship("nandor");
    AddItem(WEAPON,REFRESH_REMOVE,
            ([P_WEAPON_TYPE:WT_VARA, P_WC:2, P_SIZE:P_SIZE_MEDIUM,
            P_MATERIAL:M_MADERA,P_SHORT:"una escoba vieja",
            P_LONG:"Es una vieja escoba que parece que se vaya a romper en cualquier "
                "momento, tiene el cepillo bastante desplumado.\n",
            P_IDS:({"escoba", "escoba vieja"}), P_GENDER:GENDER_FEMALE,
            P_NUMBER_HANDS:2, P_WEIGHT:400]), SF(wieldme));
}

public int QueryBetky() { return 1; }

void notify_enter(mixed from,int method,mixed extra)
{
	  if (method == M_GIVE) call_out("recoger_",1,PO,from);
}
