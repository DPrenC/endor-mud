/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 22-01-98                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>
#include DOM_SYS "crowiano.h"

inherit PNJ_CROWY("crowiano_civil_base");

create(){
    ::create();
    SetStandard("zorkj","ogro",([GC_LUCHADOR:25]),GENERO_MASCULINO);
    SetIds(({"contrabandista","zorkj","Zorkj", "mercenario"}));
    SetShort("Zorkj el mercenario");
    SetLong("Zork es un ogro, un enorme humanoide de unos tres metros de altura  de "
        "piel grisácea y pelo grasiento. Sus facciones brutales  reflejan cierta "
        "estupidez, aunque una mirada a la gran maza de pinchos colgada del burdo "
        "cinturón que porta, le basta a  cualquiera para pensar  que no sería prudente "
        "mencionárselo. \n  Como muchos otros guerreros de fortuna, espera en la "
        "Daga Sangrienta a que llegue alguien que contrate sus servicios.\n");

    SetEdad(MEDIANA);
    SetAlign(-150);

    AddItem(ARMA("maza_hierro"),REFRESH_REMOVE,SF(wieldme));
    AddItem("/obj/money",REFRESH_REMOVE,
        (["Money":(["plata":random(3),"oro":random(2)])]));
    AddItem(PROT("coraza_hierro"),REFRESH_REMOVE,SF(wearme));

    InitChats(3,({"Zorkj saca una moneda y la muerde.\n",
        "Zorkj dice: Vaya, ya no me queda dinero de la venta de mi padre.\n",
        "Zorkj dice: Le tengo echado el ojo a un cargamento de vino.\n"}));
    InitAChats(7,({"Zorkj te dice: Si estuviera aquí mi madre te ibas a enterar.\n",
        "Zorkj grita: Morirás!!!\n"}));
}