/***
Fichero: caballo.c
Autor: kastwey@simauria
Descripci�n: caballo para el establo de Siempreunidos.
SAcado de los establos de zarkam.
***/

#include "path.h"
#include <properties.h>

inherit NPC;

create()
{
  ::create();
   SetName("caballo");
    SetIds(({"caballo", "animal"}));
    SetAds(({"marron", "un"}));
    SetShort("un caballo");
    SetLong("Es un precioso caballo de color marron y largas crines. No sabes de quien sera.\n");
    SetWeight(415000);
    SetValue(23000);
    SetLevel(15);
    SetGender(GENDER_MALE);
    Set(P_HANDS, ({
        ({"la pata trasera derecha", 0, 4}),
        ({"la pata trasera izquierda", 0, 4}),
        ({"un mordisco", 0, 7})}));

    InitChats(10, ({
        "Hiiiiiii......brrr......hiiiiii.....\n",
        "El caballo come un poco de pienso.\n",
        "Brrrr.....brrrrr...hiiiiiiii.\n",
        "El caballo no parece prestarte especial atencion.\n",
        "Hiiii...hiiiiii....brrrr...\n"
    }));


}


init()
{
    (::init());
    add_action("montar", "montar");
    add_action("montar", "coger");
}


montar(string str)
{
    int hp;
    if(!str || !id(str)) return 0;
    write("El caballo se revuelve y te pega una coz. Te ha dolido bastante.\n");
    hp=TP->QueryHP();
    hp=(hp-10>0?hp-10:0);
    TP->SetHP(hp);
    return 1;
}
