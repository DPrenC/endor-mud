/**
 * simauria /bin/wiz/_kick.c
*/

#include "/secure/userinfo.h"
public int main(string str)
{
    string jugador, realname;
    int minutos, todos, mywizlevel;
    object pl;
    if (!str)
    {
        return notify_fail("Sintáxis: kick <jugador>.\n"
                           "kick <jugador> <minutos>.\nkick todos <jugador>.\n"
                           "kick todos <jugador> <minutos>\n"
                           "Por defecto, al expulsar a un jugador, se le expulsa "
                           "durante 10 minutos.\nSi se usa todos <jugador>, se expulsará al jugador "
                           "<jugador>, y se restringirá el acceso a todos sus jugadores asociados.\n",
                           NOTIFY_NOT_VALID);
    }
    if (sscanf(str, "todos %s %d", jugador, minutos) == 2)
    {
        todos = 1;
    }
    else if (sscanf(str, "todos %s", jugador) == 1)
    {
        todos = 1;
        minutos = 10;
    }
    else if (sscanf(str, "%s %d", jugador, minutos) != 2)
    {
        jugador = str;
        minutos = 10;
    }
    pl = find_object(jugador = LOWER(jugador));
    if (!pl)
    {
        return notify_fail("No se encontró a " + CAP(jugador) + ".\n");
    }
    if (pl == TP)
    {
        return notify_fail("¿Y has probado con abandonar?\n");
    }
    if (query_wiz_level(pl) >= (mywizlevel = query_wiz_level(TP)))
    {
        log_file("KICK", ctime() + ". " + TNREAL + " intentó expulsar a " + NREAL(pl) + ".\n\n");
        return notify_fail("¡No puedes expulsar a " + CAP(jugador) + "!\n");
    }
    if (minutos <= 0)
    {
        return notify_fail("Los minutos de expulsión deben ser un número positivo, comprendido entre 1 y 1440.\n");
    }
    if (minutos > 1440)
    {
        return notify_fail("No puedes expulsar a alguien por más de 24 horas. Para períodos superiores, usa nicks banear.\n");
    }
    realname = NREAL(pl);
    write("Expulsando a " + CAP(jugador) + " durante " + minutos + " minutos.\n");
    tell_object(pl, "Por orden de los Valar, Has sido espulsad" + pl->QueryGenderEndString() + " de Arda "
                "durante " + minutos + " minutos.\n");
    command("salvar", pl);
    pl->remove();
    if (pl) destruct(pl);
    if (pl)
    {
        return notify_fail("No puedes expulsar a " + CAP(jugador) + ".\n");
    }
    if (!CHARMASTER->BanName(realname, "kick", time() + (minutos * 60)))
    {
        return notify_fail("Imposible restringir el acceso a " + CAP(jugador) + ".\n");
    }
    if (todos)
    {
        mixed *ch;
        string unnombre, *baneados = ({});
        write("Restringiendo el acceso a todos sus jugadores asociados:\n");
        ch = MASTER->find_associated_characters(realname);
        if (!ch || sizeof(ch) <= 1)
        {
            write(CAP(realname) + " no tiene personajes asociados.\n");
            return 1;
        }
        foreach(mixed *pj:ch)
        {
            if ((unnombre = pj[AR_NAME]) == realname) continue;
            if (query_wiz_level(unnombre) >= mywizlevel)
            {
                write(CAP(unnombre) + " tiene un nivel igual o superior a ti, por lo que no puedes "
                      "restringirle el acceso.\n");
            }
            else if (!CHARMASTER->BanName(unnombre, "kick", time() + (minutos * 60)))
            {
                write("Imposible banear a " + CAP(unnombre) + ".\n");
            }
            else baneados += ({unnombre});
        }
        if (sizeof(baneados))
        {
            write("Se ha restringido el acceso también a " + implode_list(baneados) + ".\n");
        }
        else
        {
            write("No se ha restringido el acceso a ningún otro jugador.\n");
        }
    }
    return 1;
}






