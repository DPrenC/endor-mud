/****************************************************************************
Fichero: ciego.c
Autor: Ratwor
Fecha: 05/11/2006
Descripción: un ciego algo chorizo.
La acción de robar la he copiado de los ladrones de cored, con el permiso de quien
corresponda...
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <gremios.h>
#include <moving.h>
inherit NPC;

public string f_pregunta();

create()
{
    ::create();
   seteuid(getuid());
    SetStandard("tozoun","humano",([GC_TORPE:10]), GENDER_MALE);
    SetLong("Tozoun es un pequeño hombre que llegó no hace mucho a la aldea de Nandor "
        "para vivir en paz y armonía, aunque pocos saben de donde vino ni quien es.\n "
        "Cuenta que perdió la vista en una incursión orca, pero su apariencia física "
        "no demuestra corpulencia suficiente como para sobrevivir a una cosa así.\n"
       " Va siempre solo tropezándose con todo lo que se encuentra en el camino, más "
        "de una vez ha tirado a alguien al suelo, y eso que se ayuda de un palo largo.\n"
        "Hay quien rumorea que no se gana la vida decentemente y fué miembro del gremio de "
        "ladrones del que lo echaron por unos asuntos turvios.\n");
    SetShort("tozoun el ciego");
    AddId(({"ladron","ladrón", "ciego","hombre","tozoun","Tozoun"}));
    SetAlign(-50);
    SetMsgIn("viene tanteando el terreno con su palo");
    SetMsgOut("se va tanteando el terreno con su palo");

    InitChats(3,({"Tozoun va tanteando el suelo.\n",
        "Tozoun se sube un poco los pantalones que se le bajaban.\n",
        "Tozoun se toca los ojos.\n", "Tozoun escucha atentamente.\n",
         SF(f_pregunta)}));
    AddSubDetail(({"camisa", "pantalón", "pantalon", "pantalones", "ropa", "ropas"}),
        "Tozoun lleva unos pantalones rosas y una camisa de un color que se parece a la"
        " miel.\n");
    SetIVision(-20);  // es que sino de noche no ve para robar.
    SetGoChance(40);
    AddWalkZones(MARH("nandor"));
    
    AddItem(WEAPON,REFRESH_REMOVE,
            ([P_WEAPON_TYPE:WT_VARA, P_WC:2, P_SIZE:P_SIZE_MEDIUM,
            P_MATERIAL:M_MADERA,P_SHORT:"un palo largo",
            P_LONG:"Sólo es un palo largo de apenas metro y medio.\n",
            P_IDS:({"palo", "palo largo"}), P_GENDER:GENDER_MALE,
            P_NUMBER_HANDS:2, P_WEIGHT:400, P_VALUE: 130]), SF(wieldme));

}

public string f_pregunta()
{
    string *preguntas =
        ({": ¿En qué calle estamos?", ":¿Quién eres?", ": ¿voy bien por aquí al cementerio?",
            ": ¿me podría llevar a la tienda de Leyma?", ": ¿estoy perdido?",
            ": ¿Estoy todavía en Nandor?", ": ¿me dice de que color llevo los pantalones?",
            ": ¿me ayuda a buscar a Gulkas?", ": ¿es usted hombre o mujer?"});

    object *a_preguntar = filter(all_inventory(environment()) - ({TO}), (:living($1):));
    if (!sizeof(a_preguntar)) return "";
    object elegido = a_preguntar[random(sizeof(a_preguntar))];
    tell_room(environment(), QueryShort()+ " pregunta a "+elegido->QueryShort()
    + preguntas[random(sizeof(preguntas))] + ".\n", ({elegido}));
    tell_object(elegido, QueryShort()+" te pregunta" + preguntas[random(sizeof(preguntas))]
    + ".\n");
    return "";
}

void robar()
{
    object player, *players, * cosas, env;
    if (!(env = environment()) || Fighting()) return;
    
    players = filter(all_inventory(env) - ({TO}),
           (:!query_wiz_level($1) && CanSeeObject($1) && query_once_interactive($1):));
    if (!sizeof(players)) return;
    player = players[random(sizeof(players))];
    cosas = all_inventory(player);
    cosas -=player->QueryArmours();
    cosas-=player->QueryWeapons();
    cosas = filter(cosas,(:    $1->QueryWeight() < 5000 && !$1->id("dinero")
                            && !living($1) && !$1->Query(P_CANT_STEAL):));
    if (!sizeof(cosas)) return;
    // elegimos qué vamos a robar
    if (cosas[random(sizeof(cosas))]->move(TO) == ME_OK)
    {
        tell_room(environment(),"Tozoun se tropieza contigo.\n");
    }
}


public void heart_beat()
{
    ::heart_beat();
    if (!QueryCombatDelay() && random(100) >= 98) robar();
}
