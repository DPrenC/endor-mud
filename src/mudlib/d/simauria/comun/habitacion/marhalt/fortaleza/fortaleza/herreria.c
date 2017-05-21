
#include <attributes.h>
#include <properties.h>
#include <combat.h>
#include "./path.h"
#include <door.h>
#include <scheduler.h>
inherit "room/herreria";

object art1,art2;

create()
{
    ::create();

   SetLocate("Cored");
   SetIntShort("la herrería de la fortaleza");
    SetIntLong("Estás en la herrería de la fortaleza. Ves montones de armas esparcidas "
    "por todas partes. El desorden puebla el local.\n");
    SetIntBright(30);
    SetIntNoise("¡El estruendo del yunque te va a destrozar los oidos!\n");
    SetIntSmell("Hueles a humo.\n");
    AddDetail("yunque","Debe pesar por lo menos una tonelada.\n");
    AddExit("oeste",ROOMFF("patio15"));
    SetLastDest("./patio15");
    SetNotifyExits("oeste");
    AddDoor("oeste", "la puerta de la herrería", "Es una vieja puerta medio rota.\n",
    ({"puerta", "puerta vieja", "puerta de la herrería", "puerta del este"}),
    ([P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
/* Funciones propias de las tiendas */

    CanIdentify(1);
    CanAppraise(1);
    CanShow(1);
    CanList(1);
    CanBuy(1);
    CanSell(0,"No compro nada");
    RemoveDustbin(1);
    RemoveExit("almacen");
    SetShopkeeper(PNJFF("herrero"));


    art1=clone_object("/std/weapon");
    art1->SetStandard(WT_ESPADA, 5, P_SIZE_MEDIUM, M_ACERO);
    art1->SetShort("una espada corta");
    art1->SetLong("Es una simple espada corta de acero, ni en su empuñadura ni en "
    "su hoja se le puede apreciar ningún adorno.\n");
    art1->AddId("espada corta");

    art2=clone_object("/std/weapon");
    art2->SetStandard(WT_ALABARDA, 7, P_SIZE_MEDIUM, M_HIERRO);
    art2->SetShort("una guadaña");
    art2->SetLong("Es una guadaña de metal algo tosca.\n");
    art2->SetNumberHands(2);
    AddArticle(ARMA("arma_rnd"),d3());
    AddArticle(art1, REFRESH_REMOVE, 1);
    AddArticle(art2, REFRESH_REMOVE, 1);
    AddArticle(ARMA("claymore"), REFRESH_REMOVE,1);
    AddArticle(ARMA("daga"), REFRESH_REMOVE,1);

    AddArticle("/d/simauria/comun/objeto/proteccion/amd_cutre",random(6));


}