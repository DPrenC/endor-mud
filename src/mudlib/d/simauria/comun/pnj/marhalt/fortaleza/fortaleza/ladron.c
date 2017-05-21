/*=============================================================*
 |             << Fortaleza:Simauria [m] Maler >> 	           |
 *=============================================================*
 |               Creacion............. 06-07-00                |
 *=============================================================*/
//chorizo, robara cada cierto tiempo
#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <moving.h>
#include <gremios.h>

//#define APAGADA 1
//#define GASTADA 2
inherit NPC;


create()
{
    ::create();
    seteuid(getuid());
    SetStandard("un ladr�n","humano",([GC_LUCHADOR: 25+random(5)]),
                GENERO_MASCULINO);
    SetLong("Es un ladr�n humano. Va totalmente envuelto en una t�nica "
              "negra que te impide observar ning�n detalle de �l.\n");
    AddId(({"ladron","ladr�n"}));
    SetAlign(-150);
    AddWalkZones(MARH("nandor/fortaleza"));
    SetIVision(0);
    InitChats(3,"El ladr�n te mira con curiosidad.\n");
    AddItem(ARMA("espada"),REFRESH_REMOVE,SF(wieldme));
    AddItem(ARMA("daga2"),REFRESH_REMOVE,SF(wieldme));
    SetGoChance(30);
    set_heart_beat(1);
}

void robar()
{
    object player, *players, * cosas;
    if (Fighting()) return;
    players = filter(all_inventory(environment()),
           (:!query_wiz_level($1) && CanSeeObject($1) && query_once_interactive($1):));
    if (!sizeof(players)) return;
    player = players[random(sizeof(players))];
    cosas = all_inventory(player);
    cosas -=player->QueryArmours();
    cosas-=player->QueryWeapons();
    cosas = filter(cosas,(:    $1->QueryWeight() < 5000 && !$1->id("dinero")
                            && !living($1) && !$1->Query(P_CANT_STEAL):));
    if (!sizeof(cosas)) return;
    // elegimos qu� vamos a robar
    if (cosas[random(sizeof(cosas))]->move(TO) == ME_OK)
    {
        tell_room(environment(),"El ladr�n hace un movimiento brusco.\n");
    }
}


public void heart_beat()
{
    ::heart_beat();
    if (!QueryCombatDelay() && random(100) >= 98) robar();
}

/*
private int LamparaApagada(object ob)
// si es una l�mpara, est� apagada y no est� gastada, devuelve APAGADA. Si est� vac�a,
// devuelve GASTADA. Si no es una l�mpara, devuelve 0.
{
    if (blueprint(object_name(ob)) == "/obj/torch" && !ob->QueryBurning())
    {
        return (ob->QueryFuel() ? APAGADA : GASTADA);
    }
    return 0;
}


private void TirarLamparasVacias()
{
    filter(all_inventory(), (:if (LamparaApagada($1) == GASTADA)
                              {
                                  tell_room(environment(), "Un ladr�n tira una l�mpara "
                                                           "vac�a.\n");
                                  $1->move(environment());
                              }:));
}

private void ComprobarVisibilidad()
// si es denoche, lleva l�mpara y no ve un pijo, la enciende
{
    object lampara;
    if (   !CanSeeObject(environment())
        && sizeof(filter(all_inventory(), (:LamparaApagada($1) == APAGADA:))))
    {
        command_me("encender lampara");
    }
}

public void reset()
{
    ::reset();
    TirarLamparasVacias();
    ComprobarVisibilidad();
}

public void init()
{
    // tira las l�mparas vac�as, y si lleva alguna en el inventario llena, la enciende
    TirarLamparasVacias();
    ComprobarVisibilidad();
}
*/