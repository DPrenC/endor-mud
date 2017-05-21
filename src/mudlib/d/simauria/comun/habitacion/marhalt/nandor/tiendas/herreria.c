
#include <attributes.h>
#include <properties.h>
#include <combat.h>
#include "./path.h"
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit "room/herreria";

object art1,art2;

create()
{
    ::create();

   SetLocate("Aldea de Nandor");
    SetIntShort("La herrería de Altur");
    SetIntLong(
    "Nada más entrar en la herrería del pueblo, lo que más te llama la atención "
    "es el sofocante calor que hace aquí. El estruendo de la forja es el sonido "
    "característico, y casi imposibilita el habla. La salida está al norte.\n");

    SetIntBright(30);
    SetIntNoise("¡El estruendo del yunque te va a destrozar los oidos!\n");
    SetIntSmell("Hueles a humo.\n");
    AddDetail("yunque","Debe pesar por lo menos una tonelada.\n");
    AddExit("norte","../calle1");
    AddDoor("norte", "la puerta de la calle",
    "Es la puerta que da a la calle.\n",
    ({"puerta de la calle", "puerta del norte", "puerta"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));

/* Funciones propias de las tiendas */

    CanIdentify(1);
    CanAppraise(1);
    CanShow(1);
    CanList(1);
    CanBuy(1);
    CanSell(0,"No compro nada");
    RemoveDustbin(1);
    SetShopkeeper(QUEST+"/tamara/altur");

// Funciones propias de la herrería
// Ahora los players van a saber lo que es tener armas de chicha y nabo :)
    SetWeaponDecay(3);
    SetArmourDecay(3);

/* Articulos a la venta */

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

/* comentada porque por ahora falla... Descomentar cuando alguien implemente los caballos :)
    AddArticle("/std/thing",REFRESH_REMOVE,8,
    ([P_SHORT: "una herradura",
    P_LONG:  "Una simple herradura de caballo.\n",
    P_IDS: ({"herradura de caballo","herradura"}),
    P_WEIGHT:1000 ,
    P_VALUE:50,
    ]));
*/
    SetNotifyExits("norte");
    SetLastDest("../calle1");

}