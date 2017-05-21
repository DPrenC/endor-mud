/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 22-01-98                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>#define ASESINOS DOM_STD "asesinos"
#include DOM_SYS "crowiano.h"

inherit PNJ_CROWY("crowiano_civil_base");

create() {
    ::create();
    SetStandard("sherfa","medio-elfo",([GC_LUCHADOR:23]),GENERO_MASCULINO);
    SetIds(({"sherfa","Sherfa","salteador","sherfa el salteador"}));
    SetShort("Sherfa el salteador");
    SetLong(" Sherfa es un semielfo de aspecto peligroso. Va vestido con ropas de "
        "cuero,  viejas botas altas y una ligera cota de mallas.\n  Suele utilizar "
        " un par de armas en el combate: un cuchillo en una mano y en la otra una espada"
        " corta cuya empuñadura y forma la identifican como un arma élfica.  Ambas "
        "armas parecen muy bien cuidadas.\n");
    SetAlign(-200);

    AddItem(ARMA("espada_elfica"),REFRESH_REMOVE,SF(wieldme));
    AddItem(ARMA("cuchillo"),REFRESH_REMOVE,SF(wieldme));
    AddItem("/obj/money",REFRESH_REMOVE,
        (["Money":(["cobre":random(9),"plata":random(9),"oro":7])]));
    AddItem(PROT("cota_mallas"),REFRESH_REMOVE,SF(wearme));

    InitChats(3,({"Sherfa el salteador te mira.\n",
        "Sherfa grita: ¡Tabernero.. traeme otra jarra de vino!\n",
        "Sherfa dice: Jajaja.. aún recuerdo cuando mi ancestro le robó el anillo al "
        "tonto de Frobbon.\n",
        "Sherfa eructa sonoramente.\n"}));
    InitAChats(6,({"Ahora sabrás quien es Sherfa!!\n",
        "¿Cómo te atreves a tocarme?\n"}));

    AddQuestion(({"frobbon","Frobbon","anillo","anillo de frobbon","anillo de Frobbon"}),
        "Sherfa te dice: Solo recuerdo que Turgo, un antepasado mio, le robó a Frobbon "
        "su anillo hace ya algunos años pero que lo perdió en una partida de dados.\n  "
        "Lo último que supe del anillo es que lo tenia un estafador llamado Lonny.\n",1);

    AddQuestion(({"Lonny","lonny","estafador"}),
        "A Lonny lo tienen retenido los guardias en la torre de la entrada de Crowy.\n");
}