/**
 *  /obj/tool/silence-o-matic.c
 *
 * [Nyh] Esto es estupido y te lo puedes saltar de mil maneras diferentes.
 *       El bozal es lo q te puedes saltar, esto en el fondo solo te lo clona.
 *
 */

#define VERSION 1
#define FIX     6

#include <living.h>
#include <properties.h>
#include <moving.h>
#include <wizlevels.h>
#include <magia.h>

inherit THING;

private static object jugador;

create () {
    ::create();
    SetShort("el silence-o-matic v"+VERSION+"."+FIX+" de "+capitalize(getuid(TP)));
    AddId(({"báculo", "baculo","silence","silence-o-matic"}));
    AddAdjective(({"del silencio","un","el"}));
    SetLong("Este es el silence-o-matic v"+VERSION+"."+FIX+" de "+capitalize(getuid(TP))+".\n"
            "Retiene un inmenso poder que sirve para hacer callar a personas indeseables.\n"
            "Para usarlo escribe 'bozal <jugador>'.\n");
    SetWeight(1);
    Set(P_NODROP,1);
    Set(P_NOGIVE,1);
    Set(P_NOSELL,1);
    Set(P_MAGIC,1);
    Set(P_AUTOOBJECT,1);
    SetSmell("Huele a ozono.\n");
}

init () {
   ::init();
   add_action("cmd_bozal", "bozal");
}

cmd_bozal (string str) {
    object bozal;

    if ( !IS_WIZARD(TP) ) {
        write("Es harto ilegal que tengas esto, asi que a ver como lo explicas.\n");
        raise_error("["+ctime()+"] "+capitalize(TP->QueryRealName())+" intentó usar "+QueryShort());
    }
    else {
        if (!str)
            return notify_fail("A quien quieres poner el bozal?\n");
        str = lower_case(str);
        if (!jugador = find_object(str))
            return notify_fail("Esa persona no se encuentra en Simauria.\n");
        if (!query_once_interactive(jugador))
            return notify_fail("Ese objeto no necesita el bozal.\n");
        if (!interactive(jugador))
            return notify_fail("Las estatuas no necesitan el bozal.\n");
        write("Has puesto el bozal en "+capitalize(getuid(jugador))+".\n");
        "/obj/chmaster"->SendMsg("infomud",
            "Le acabo de poner el bozal a "+capitalize(getuid(jugador))+".\n");
        tell_object(find_object(str),"\nTe han puesto el bozal.\n"
        "No esta permitido molestar a las personas que juegan en Simauria.\n");
        bozal = clone_object("/secure/bozal");
        bozal->move(find_object(str));
        log_file("BOZAL","["+ctime(time())+"] "+capitalize(getuid(TP))+
               " puso el bozal a "+capitalize(getuid(jugador))+".\n");
    }
    return 1;
}
