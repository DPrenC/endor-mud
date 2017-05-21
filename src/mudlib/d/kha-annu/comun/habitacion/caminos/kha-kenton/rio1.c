#include "./path.h"
#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el río Gaut-Kilok");
    SetIntLong("El río transcurre tranquilo, sin embargo su caudal es bastante profundo y "
        "necesitas nadar para cruzarlo. Mientras lo intentas, la corriente te lleva "
        "ligeramente hacia el sudeste.\n");
    SetIndoors(0);
    SetIntBright(MAX_SUNBRIGHT);
    AddDetail(({"agua"}),"El agua es transparente y casi puedes ver el fondo.\n");
    AddExit("este","rio2");
    AddExit("oeste","río");
    SetLocate("río Gaut-Kilok");
}

init()
{
    ::init();
    detalles();
    add_action("cruzar_rio","nadar");
    add_action("nadar_este","este");
    add_action("nadar_este","e");
    add_action("nadar_oeste","oeste");
    add_action("nadar_oeste","o");
}

int cruzar_rio(string str)
{
    write("Lo haces lo mejor que puedes!! No te desesperes ya queda menos.\n");
    return 1;
}

int nadar_este(string str)
{
    /* Aki va un callout de esos */
    int dex;
    dex = random(TP->QueryDex());
    if ((dex == 0) || (dex > 4))
    {
        write("Empiezas a nadar hacia la otra orilla del río, no parece tan difícil.\n");
        /* Aki hay que mover al jugador hacia la otra habitacion */
        return 1;
    }
    else
    {
        write("Intentas nadar hacia la otra orilla, pero no te sientes como pez en el agua y "
            "piensas que no ha sido una buena idea cruzar el río por esta zona...\n");
        TP->SetHP(TP->QueryHP() - random(10));
        if (random(100) < 25)
        {
            write("... pero haces tremendos esfuerzos por salir del río y lo consigues. uff!\n");
            /* Aki se devuelve al jugador a la orilla, ke suerte tuvo el joputa */
            return 1;
        }
        return 1;
    }
}
