/* SIMAURIA '/bin/_beep.c'
*/

#include <sounds.h>

public varargs beep(string str)
{
    object ob;
    string msg, who;

    if (!str) return notify_fail("Beepear a quien?\n");

    if (strstr(str, " ", 0) != -1) sscanf(str, "%s %s", who, msg);
    else who = str;

    ob = find_object(who)||find_object(lower_case(who));

    if (!ob || (ob->QueryInwiz() && !query_wiz_level(TP)))
    {
        return notify_fail("No ves a ningún jugador conectado llamado "+capitalize(who)+".\n");
    }
    if (ob->CheckIgnored(TNREAL))
    {
        return notify_fail(CAP(who) + " te está ignorando.\n", NOTIFY_NOT_VALID);
    }
    play_sound(ob, SND_SUCESOS("beep"));
    if (!msg)
    {
        tell_object(ob, ""+capitalize(TP->QueryRealName())+" quiere hablar contigo.\n");
        write("Beepeas a "+capitalize(ob->QueryRealName())+".\n");
    }
    else
    {
        tell_object(ob, ""+capitalize(TP->QueryRealName())+" te beepea: "+msg+".\n");
        write("Beepeas a "+capitalize(ob->QueryRealName())+" diciendole: "+msg+".\n");
    }
    return 1;
}
