/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 08-10-98                |
 |               Ultima Modificacion.. 13-05-99                |
 |                                                             |
 *=============================================================*/

#include "path.h"
inherit SHOP;

create()
{
    ::create();
    SetIntShort("la tienda de magia vudú");
    SetIntLong("Acabas de entrar en la tienda de Evah la curandera, un lugar solitario y "
        "alejado de la civilización. Se trata de una casa bastante vieja y llena de polvo y "
        "telarañas por todas partes, incluso en los sitios más recónditos y protegidos. "
        "Cientos de pequeños recipientes de barro están apostados en unas rústicas estanterías "
        "que cubren las paredes, al parecer son diversos tipos de pócimas que Evah prepara con "
        "hierbas y hongos del bosque.\n");
    SetIndoors(1); // 1: A cubierto  0: A descubierto
    SetIntBright(30);
    SetIntNoise("El silencio que hay casi te permite escuchar los animales del bosque.\n");
    SetIntSmell("Hay un extraño olor en el ambiente como a incienso.\n");
    RemoveDustbin();
    CanSell(0);
    CanAppraise(0);
    CanIdentify(0);
    AddArticle("/guilds/kisalas/pergamino/pergamino_calmar",REFRESH_REMOVE,1);
    AddArticle("/guilds/kisalas/pergamino/pergamino_luz_cegadora",REFRESH_REMOVE,1);
    AddArticle("/guilds/kisalas/pergamino/pergamino_sombra",REFRESH_REMOVE,1);
    AddArticle("/guilds/kisalas/pergamino/pergamino_vision_nocturna",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_agrandar",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_apocalipsis",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_coraza",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_elemental",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_elemental_mayor",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_enjambre",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_esfera",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_esferao",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_espada_sagrada",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_familiar", REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_frio_intenso",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_hierbas",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_hogaza",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_lanza_acida",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_maza_infernal",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_meteorito",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_oscuridad",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_piel_piedra",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_reducir",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_teletransporte",REFRESH_REMOVE,1);
    AddArticle("/guilds/conjuradores/pergamino/pergamino_victima",REFRESH_REMOVE,1);
    AddArticle("/guilds/hechiceros/pergamino/pergamino_campo",REFRESH_REMOVE,1);
    AddArticle("/guilds/hechiceros/pergamino/pergamino_golpe",REFRESH_REMOVE,1);
    AddExit("fuera",BOSCURO("frente_vudu"));
    AddItem(PNJ("bosque_oscuro/duntha"),REFRESH_DESTRUCT); // El siervo de Evah
    SetShopkeeper(PNJ("bosque_oscuro/evah"));
    SetLocate("bosque oscuro de Goldhai");
}

init()
{
    ::init();
   add_action("do_sell","vender");
}

do_sell(string str)
{
    say("Evah le dice algo a "+CAP(TNAME)+".\n",TP);
    write("Evah te dice: Lo siento "+CAP(TNAME)+", pero yo no compro cosas, solo vendo.\n");
    return 1;
}
