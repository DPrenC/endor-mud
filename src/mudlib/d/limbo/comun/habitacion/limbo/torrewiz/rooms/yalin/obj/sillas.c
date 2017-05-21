#include "path.h"
#include <properties.h>
inherit THING;

int pers=0;
string *sent=({});

festado()
{
    string estado;
    if (pers==0) estado="Están vacías.\n";
    else
    {
        if (pers==1) estado="Una de ellas está ocupada por ";
        else estado=(pers+" de ellas están ocupadas por ");
        estado+=implode_list(sent)+".\n";
        }
    SetLong("Cuatro sillas colocadas alrededor de la mesa, fabricadas en la misma madera y con lamisma talla que ésta. "
    "Sus patas son 4 dragones, y su asiento está tapizado en terciopelo rojo, a juego con la caoba de que están hechas.\n"+estado);
    return;
}
                    
int fsentarse()
{
    if (pers<4)
    {
        int sentado=TP->QueryAttribute("sentado");
        if (!sentado)
        {
            pers++;
            sent+=({TNAME});
            TP->SetResting(1);
            TP->SetAttribute("sentado",time());
            write("Te sientas en una silla con gran satisfacción.\n");
            tell_room(environment(),TNAME+" se sienta en una silla con un suspiro de placer.\n",({TP}));
            festado();
        }
        else write("Ya estás sentad"+TP->QueryGenderEndString()+".\n");
    }
    else
    {
        write("No hay más sillas donde sentarse.\n");
        tell_room(environment(),TNAME+" va a sentarse en una silla, pero se encuentra con que no "
        "hay ninguna libre.\n",({TP}));
    }
    return 1;
}

int flevantarse()
{
    int sentado=TP->QueryAttribute("sentado");
    if (sentado)
    {
        pers--;
        if (pers<0) pers=0;
        sent-=({TNAME});
        TP->SetResting(0);
        TP->RemoveAttribute("sentado");
        festado();
        write("Te levantas pesadamente de la silla.\n");
        tell_room(environment(),TNAME+" se levanta pesadamente de la silla.\n",({TP}));
    return 1;
    }
    return 0;
}

create()
{
    ::create();
    SetShort("cuatro sillas");
    festado();
    AddId(({"silla","sillas"}));
    Set(P_GENDER, GENERO_FEMENINO);
    Set(P_NUMBER, NUMERO_PLURAL);
    SetNoGet("Las sillas son para sentarse, no para ir cargado con ellas de aquí para allá.\n");
}

init()
{
    ::init();
    add_action("flevantarse","levantarse");
    add_action("fsentarse","sentarse");
}
    