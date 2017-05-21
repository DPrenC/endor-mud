/**************************************************************************
fichero: fignus.c
Autor: kastwey
Creación: 21/07/2005
Descripción: El tabernero de la taverna de Annufam
********************************************************
******************/

#include "./path.h"
#include <properties.h>

#define OB_AO (ob->QueryGender() == GENDER_FEMALE?"a":"o")

#define MENSAJES_ENANOS  ({"Fignus grita: Venga chicos, otra ronda para \
    celebrar nuestra prosperidad...\n",\
    "Fignus dice: Buf, parece que han bebido demasiado. Como llegaran ahora \
los orcos estaríamos perdidos.\n"})

#define MENSAJES_ENANO   ({"Fignus dice: Hmmm Un solo cliente habitual... que \
raro...\n","Fignus mira al enano y le dice: ¡eh! ¿Dónde están los demás? \
Más os vale que no me entere de que han cambiado de taberna y ahora se van a \
ese tugurio de posada ojo de orco...\n"})

#define MENSAJES_PLAYERS ({"Fignus dice: Hey chicos. No os conozco. ¿Deseais \
algo?\n","Fignus te mira y te sonríe.\n","Fignus dice: Heeeey. ¿No pensais \
pedir nada?\n"})

#define MENSAJES_PLAYER  ({"Fignus te mira y te dice: Hey. Tu cara me suena. ¿\
Nos hemos visto antes?","Fignus dice: Hey foraster" + OB_AO + ". ¿Deseas \
algo? Esta taberna tiene las mejores cervezas de Kha-annu.\n"})

#define MENSAJES_PNJ     ({"Fignus te mira y te dice: ¿Una cervecita?\n"})
inherit NPC;


string chats();

public void create()
{
    ::create();
    SetStandard("fignus","enano",15,GENDER_MALE);
    AddId("tabernero");
    SetShort("fignus, el tabernero");
    SetLong(W("Se trata del tabernero de Mi Entrañable Cerveza. Es un enano "
              "de cara afable, y que siempre está de aquí para allá, pues la "
              "afluencia de personal es notable en su local.\n"));
    InitChats(5,#'chats);
}

string chats()
// función para hacer los chats
{
    int personal;
    object ob, *inv;

    if ((personal = sizeof(filter((inv = all_inventory(environment())),
                                   (:living($1) && $1->id("enano_borracho"):)
                                   ))) > 1)
    // almacenamos en personal la cantidad de enanos que hay en la room
    // y en inv el inventario de la room para futuras comprobaciones

    // hay más de un enano borracho
    {
        return W(MENSAJES_ENANOS[random(sizeof(MENSAJES_ENANOS))]);
    }
    if (personal == 1)
    // solo queda un enano borracho
    {
        return W(MENSAJES_ENANO[random(sizeof(MENSAJES_ENANO))]);
    }
    // no hay enanos.
    // hay players?
    if ((personal = sizeof(filter(inv,(:query_once_interactive($1):)))) > 1)
    // hay más de un player
    {
        return W(MENSAJES_PLAYERS[random(sizeof(MENSAJES_PLAYERS))]);
    }
    if (personal = 1)
    // solo hay un player
    {
        ob = filter(inv,(:query_once_interactive($1):))[0];
        return W(MENSAJES_PLAYER[random(sizeof(MENSAJES_PLAYER))]);
    }
    // no hay players ni enanos...
    // puede que sea otro pnj...
    return W(MENSAJES_PNJ[random(sizeof(MENSAJES_PNJ))]);
}








