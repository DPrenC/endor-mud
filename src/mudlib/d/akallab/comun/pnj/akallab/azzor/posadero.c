/*
DESCRIPCION : posadero del Lobo de mar
FICHERO     : /d/akallab/comun/pnj/akallab/azzor/posadero.c
MODIFICACION:
09-12-05 [Riberales] Creacion
09-12-05 [Angor] Descripcion cambiada + Mas WalkZones
*/

#include "path.h"
#include <properties.h>
#include <guild.h>

inherit NPC;

string charla();

public create()
{
    ::create();

    seteuid(getuid());

    SetStandard("Lomak","orco",([GC_NINGUNO:40]),GENDER_MALE);
    SetShort("Lomak el posadero");
    SetLong(
    "Lomak es el viejo orco que regenta la posada 'Lobo de Mar'. Es delgado y camina "
    "con cierta dificultad. Acostumbrado a toda una vida en el mar, sus ojos estan "
    "hundidos y ausentes y su piel, arrugada, ajada y pegada a los huesos.\n");

    SetIds(({"posadero","Lomak","lomak","orco"}));

    SetGoChance(30);
    AddWalkZones(({AZ_POSADA("lobomar/entrada"),
                   AZ_POSADA("lobomar/sala_descanso"),
                   AZ_POSADA("lobomar/comedor"),
                   AZ_POSADA("lobomar/taberna")}));

    InitChats(3,SF(charla));

    AddItem("/std/thing",REFRESH_REMOVE,([
            P_SHORT: "un trapo",
            P_LONG: "Es un vulgar trapo que sirve para quitar el polvo.\n",
            P_IDS: ({"trapo","trapo_posadero"})]));

}

string charla()
{
    string msg;
    switch(random(3))
    {
        object viejo, env;
        case 0:
            msg = "Lomak te mira y dice: Lo siento forastero, no "
                "disponemos de ninguna habitación libre para alquilar. ";
            if ((env = environment())->QueryEntrada())
            {
                msg+="Pero al norte de aquí se encuentra la taberna de nuestra posada, "
                    "donde podrás beber y comer muy bien.\n";
                break;
            }
            if (env->QueryTaberna())
            {
                msg+="Por cierto, espero que nuestra taberna te resulte agradable. Cualquier "
                    "cosa no dudes en pedírsela a nuestra tabernera.\n";
                break;
            }
            msg+="Pero al norte de la entrada se encuentra la taberna de nuestra posada, donde "
                "podrás beber y comer muy bien.\n";
        break;
        case 1:
            if ((viejo = present("marvag",environment())) && !living(viejo))
            {
                msg="El posadero exclama: ¿Qué le ha pasado a Marvag?\n";
                break;
            }
            if (viejo)
            {
                msg="El posadero mira con mala cara a Marvag.\n";
                break;
            }
            msg="El posadero se frota las manos.\n";
        break;
        case 2:
            if ((env = environment())->QueryDescanso())
            {
                if (env->QueryEstadoChimenea())
                // la chimenea de la sala está encendida
                {
                    msg="El posadero aviva el fuego de la chimenea.\n";
                    break;
                }
                if (present("trapo_posadero"))
                {
                    msg="El posadero le pasa el trapo a uno de los candelabros.\n";
                    break;
                }
                msg="El posadero murmura: ¿Dónde demonios habré dejado el trapo?\n";
                break;
            }
            msg="Lomak te sonríe.\n";
        break;
    }
    return msg;
}

