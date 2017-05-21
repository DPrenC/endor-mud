#include "path.h"
#include <properties.h>
inherit THING;

int pers=0;
string sent="";

festado()
{
    string estado;
    if (!pers) estado="Está desocupada";
    else estado=("Está ocupada por ");
        estado+=sent+".\n";
    SetLong("Es una silla de la misma madera y talla que el altar, colocada frente a éste.\nEl asiento está acolchado y "
        "cubierto con terciopelo blanco a juego con el mantel del altar.\n"+estado);
    return;
}
                    
int fsentarse()
{
    int sentado=TP->QueryAttribute("sentado");
    if (sentado) write("Ya estás sentad"+TP->QueryGenderEndString()+".\n");
    else
    {
        if (!pers)
        {
            pers=1;
            sent=TNAME;
            TP->SetResting(1);
            TP->SetAttribute("sentado",time());
            write("Te sientas en la silla con gran satisfacción.\n");
            tell_room(environment(),TNAME+" se sienta en la silla con un suspiro de placer.\n",({TP}));
            festado();
        }
    else
    {
        write("La silla está ocupada.\n");
        tell_room(environment(),TNAME+" va a sentarse en la silla, pero se encuentra con que no "
        "está libre.\n",({TP}));
    }
    }
    return 1;
}

int flevantarse()
{
    int sentado=TP->QueryAttribute("sentado");
    if (sentado)
    {
        pers=0;
        sent="";
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
    SetShort("una silla");
    festado();
    AddId(({"silla"}));
Set(P_GENDER, GENERO_FEMENINO);
Set(P_NUMBER, NUMERO_SINGULAR);
SetNoGet("No puedes ir por ahí con una silla a cuestas.\n");
}

init()
{
    ::init();
    add_action("flevantarse","levantarse");
    add_action("fsentarse","sentarse");
}
    