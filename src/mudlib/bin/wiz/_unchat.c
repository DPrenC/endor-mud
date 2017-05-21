/******************************************************/
/* fichero: _unchat.c                                 */
/* utilidad:  Poner bozales a jugadores que molesten  */
/*            por alguno de los canales a su disposi- */
/*            cion.                                */
/* Izet@Simauria.                                  */
/******************************************************/


#include <moving.h>
public int main(string str)
{
    int i, val;
    object jugata, bozal;
    object *usuarios;

    if (query_wiz_level(TP) < 20)
    {
        return notify_fail ("No eres lo suficiente poderoso para poner el Bozal Mágico. "
                            "Consulta con un Archwizard.\n\n");
    }
    if (!str)
    {
        return notify_fail("¿A quien quieres poner el bozal mágico?\n");
    }

    if (!jugata = find_object(lower_case(str)))
    {
        return notify_fail("Ese jugador no está conectado.\n");
    }
    if (!query_once_interactive(jugata))
    {
        return notify_fail("No puedes ponerle el bozal a " + CAP(str) + ".\n");
    }
    if (present("bozal_magico",jugata))
    {
        return notify_fail(CAP(jugata->QueryRealName()) + " ya tiene puesto "
                           "un bozal mágico.\n");
    }
    seteuid(getuid());
    bozal=clone_object("/secure/obj/bozal");
    val = bozal->move(jugata);
    if (val != ME_OK)
    {
        bozal->remove();
        return notify_fail("Imposible mover el vozal a " +
                           CAP(jugata->QueryRealName()) + ".\n");
    }

    write("Has puesto el bozal a "+CAP(jugata->QueryRealName()) + ".\n");
    tell_object(jugata,"\nTe han puesto el Bozal Mágico.\n"
                       "No esta permitido molestar a las personas que juegan "
                       "en Endor.\n");

    /* comentado porque no hay permisos
    write_file("/log/BOZAL",ctime(time())+" ---> "+ CAP(getuid(TP)) + " puso el bozal "
             "a "+ CAP(getuid(jugata))+".\n");
    */
    return 1;
}

