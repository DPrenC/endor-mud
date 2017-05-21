/*=============================================================*
 |            << GOLDHAI.Puerto [w] Woo@simauria >>            |
 *=============================================================*
 |               Creacion.............. 06-01-98               |
 |               Ultima Modificacion... 13-05-10               |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit SHOP;

create()
{
    ::create();
    SetIntShort("la lonja del puerto");
    SetIntLong("Estás dentro de la lonja de este importante puerto.\n Un lugar donde "
    "los pescadores acuden a vender todo aquello que han arrebatado al mar con sus "
    "redes.\n Si te interesa algo de pescado, el joven Dower te puede atender.\n");  

    SetIntBright(25);
    SetIntNoise("No escuchas nada en particular.\n");
    SetIntSmell("Argghhhhhh.. hay un olor repugnante a pescado.\n");

    RemoveDustbin();
    CanSell(0);
    CanAppraise(0);
    CanIdentify(0);
    SetShopkeeper(PNJ("puerto/dower"));

    AddArticle(COMIDA("calamar"),REFRESH_REMOVE,5);
    AddArticle(COMIDA("junka"),REFRESH_REMOVE,5);
    AddArticle(COMIDA("atun"),REFRESH_REMOVE,3);

    AddExit("norte",PUERTO("puerto5"));
    AddExit("oeste",PUERTO("puerto3"));
    AddDoor("norte", "una puerta",
    "Es una puerta para salir de la lonja.\n",
    ({"puerta de la lonja", "puerta del norte", "puerta"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME: S_CLOSED_AT_NIGHT]));
    AddDoor("oeste", "la puerta de salida",
    "Es la puerta principal de la lonja del puerto.\n",
    ({"puerta de salida", "puerta del oeste", "puerta", "puerta principal"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME: S_CLOSED_AT_NIGHT]));

    RemoveExit("almacen");

    SetLocate("puerto de Goldhai");
    SetNotifyOpenMsg(({"El pescadero llega silvando, abre la puerta de la lonja y entra.\n",
    "El pescadero abre desde dentro la puerta, se asoma para ojear el exterior y se "
    "vuelve a meter en la lonja.\n"}));
    SetNotifyCloseMsg(({"El pescadero cierra con llave la puerta de la lonja y se va "
      "silvando.\n",
    "El pescadero cierra la puerta desde el interior.\n"}));
    SetNotifyExits(({"oeste","norte"}));
    SetLastDest("./puerto3");
    
    
}
