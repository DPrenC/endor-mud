/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 25-11-97                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>
#include <door.h>
#include <nightday.h>
#include <scheduler.h>
#include <sounds.h>


inherit SHOP;

create()
{
   ::create();
    SetIntShort("una vieja sastrería");
    SetIntLong("Esta es una vieja sastrería con toda la buena fama que se merece. "
    "Quizá es el momento adecuado para cambiar tus ropajes por algo más estilizado. "
    "La calidad y el lujo es la principal prioridad de esta tienda, que además trabaja "
    "en distintas tallas.\n");
    SetIndoors(1);
    SetIntBright(40);
    SetIntSmell("Huele a las telas nuevas de las prendas que se exponen.\n");
 AddDetail(({"telas","tela","pared"}),
    "Las paredes están decoradas de telas de todos los colores que tu te puedas "
    "imaginar. Hay desde tejidos gruesos para la época de frio como tejidos muy "
    "finos para cuando llega el calor.\n");
    AddDetail(({"ropa","ropajes","vestimenta"}),
    "No sabes que comprarte de la gran variedad que hay.\n");

    AddExit("sur",CROWY("zona_comercial3"));

    SetLocate("crowy");
    AddDoor("sur", "la puerta de la calle",
    "Es la puerta de salida que da a una de las calles de Crowy.\n",
    ({"puerta", "puerta de salida", "puerta de la calle", "puerta del sur"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    SetLastDest("./zona_comercial3");
    SetNotifyExits("sur");
    if(d2()==1)
        AddArticle(PROT("camisa_seda"), REFRESH_REMOVE, d2());
    if(d2()==1)
        AddArticle(PROT("corpinyo"), REFRESH_REMOVE);
    if(d2()==1)
        AddArticle(PROT("escarpines"), REFRESH_REMOVE);
    if(d2()==1)
        AddArticle(PROT("falda"), REFRESH_REMOVE, d2());
    if(d2()==1)
        AddArticle(PROT("guantes_seda"), REFRESH_REMOVE);
    if(d2()==1)
        AddArticle(PROT("jubon"), REFRESH_REMOVE);
    if(d2()==1)
        AddArticle(PROT("pantalon"), REFRESH_REMOVE, d2());
    if(d2()==1)
        AddArticle(PROT("sandalias"), REFRESH_REMOVE);
    if(d2()==1)
        AddArticle(PROT("sombreros"), REFRESH_REMOVE, d2());
    if(d2()==1)
        AddArticle(PROT("zapatos_charol"), REFRESH_REMOVE);
    SetShopkeeper(PNJ("crowy/damila"));
    RemoveExit("almacen");
}
