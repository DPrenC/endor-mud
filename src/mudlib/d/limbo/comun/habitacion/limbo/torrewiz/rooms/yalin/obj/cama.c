#include "path.h"
#include <properties.h>
#include <sounds.h>
inherit THING;

#define DORMIDO    TP->QueryAttribute("dormido")
int pers=0;
string *dor=({});

festado()
{
    string estado;
    if (pers==0) estado="";
    else
    {
        if (pers==1) estado=" está durmiendo en ella.\n";
        else estado=(" están durmiendo en ella.\n");
    }
        SetLong("Es una soberbia cama rícamente vestida con seda élfica, y cubierta con un edredón "
            "de plumas.\nParece muy confortable, debe dormirse muy bien en ella, y probablemente, "
            "otras cosas también.\n"+
    implode_list(dor)+estado);
    return;
}
                    
int fdespertar()
{
    if (DORMIDO && TP->QueryStatusResting())
    {
        write("No estás durmiendo.\n");
        return 1;
    }
    return 0;
}
    
int ftumbarse()
{
    if (pers<3)
    {
        if (!DORMIDO)
        {
            pers++;
            dor+=({TNAME});
            TP->SetStatusResting();
            TP->SetAttribute("dormido",time());
            write("Te tumbas en la cama, y notas como te relajas.\n");
            tell_room(environment(),TNAME+" se tumba en la cama con un suspiro de placer.\n",({TP}));
            festado();
            return 1;
        }
        else write("Ya estás tumbad"+TP->QueryGenderEndString()+".\n");
        return 1;
    }
    write("Tendrás que buscar otro sitio para dormir, en la cama no caben más.\n");
    tell_room(environment(),TNAME+" trata  de tumbarse en la cama, pero sus ocupantes no "
            "quieren más invitados.\n",({TP}));
    return 1;
}

int fdormir()
{
    if (!DORMIDO)
    {
        if (pers==3) return notify_fail("Aquí no puedes dormir, la cama está ocupada.\n",
            NOTIFY_NOT_VALID);
        if (ftumbarse()) return 0;
    }
    if (TP->QueryStatusSleeping())
    {
        write("te despiertas.\n");
        tell_room(environment(),TNAME+" se despierta.\n",({TP}));
        TP->SetStatusResting();
        play_sound(environment(),SND_SUCESOS("despertar"));
        return 1;
    }
    return 0;
}

int flevantarse()
{
    if (DORMIDO)
    {
        pers--;
        dor-=({TNAME});
        if (TP->QueryStatusSleeping()) TP->command_me("dormir");
        TP->SetStatusNormal();
        TP->RemoveAttribute("dormido");
        festado();
        write("Te levantas de la cama con un bostezo de fastidio.\n");
        tell_room(environment(),TNAME+" se levanta de la cama bostezando con desgana.\n",({TP}));
    }
    else write("No estás tumbad"+TP->QueryGenderEndString()+".\n");
    return 1;
}

create()
{
    ::create();
    SetShort("la cama");
    festado();
    AddId(({"cama","lecho"}));
    AddSubDetail(({"edredon","edredón"}), "Es una especie de..., saco de seda, relleno con plumas "
        "de ruiseñor, hecho por las propias hadas. Muy ligero y caliente en invierno.\n");
    Set(P_NOGET,"Es muy grande y de madera sólida, no puedes con ella.\n");
}

init()
{
    ::init();
    add_action("fdespertar","despertar");
    add_action("flevantarse","levantarse");
    add_action("fdormir","dormir");
    add_action("ftumbarse","tumbarse");
}
    