/**
 * SIMAURIA '/std/wizard/saveload.c'
 */

inherit "/std/player/saveload";

#include <stdrooms.h>
#include <moving.h>
#include <colours.h>
#include <wizlevels.h>
#include <input_to.h>
#include <sounds.h>

/**
 * Sobreescribo el move_player_to_start
 */
protected void _move_player_to_start(int newflag) {
    int i;
    object *u;

    if (!sizeof(QueryHome()) || catch(i = TO->move(QueryHome(), M_SILENT)) || i != 1) {
        TO->move(CENTER, M_SILENT);
    }

    if (environment(TP)) catch_tell("Te materializas en "+(environment(TP)->QueryLocate()||environment(TP)->QueryIntShort()));
    else catch_tell("Por algún error no has podido ser movido a ningún sitio.\n");
    if (TO->QueryInwiz()) catch_tell(" (estás en forma incorpórea)");
    catch_tell(".\n");

    if (TO->QueryInwiz() && !IS_WIZARD(TP))  command("vis");

    if (TO->QueryInwiz()) {
        for (i=sizeof(u=users()); i--; ) {
            if (TO!=u[i] && IS_LEARNER(u[i])) {
                play_sound(u[i], SOUND_EVENTOS("conexion"));
                tell_object(u[i], (u[i]->QueryChLine() ? "" : "\n") + TC_MUD_WHO + "[mud: " + TC_NORMAL
                                + TC_MUD_MSG + capitalize(getuid(TO)) + " se manifiesta una vez  más en  la Tierra Media.\n"
                                "Cuidad vuestras acciones, Oh Hijos de Ilúvatar, pues uno de los \n"
                                " Señores del Antiguo Occidente, camina entre vosotros" + TC_NORMAL
                                + TC_MUD_WHO + "]" + TC_NORMAL + "\n");
            }
        }
    }
    else
    {
        CHANNELMASTER->SendEmote("infomud", capitalize(getuid(TO))+" ha retornado  del Antiguo Occidente a la Tierra Media.\n"
        "Cuidad vuestras acciones, Oh Hijos de Ilúvatar, pues uno de los Señores de Arda \n" "camina entre vosotros", SOUND_EVENTOS("conexion"));
    }
}

start_player(str)
{
    if (!::start_player(str)) return 0;

    call_out("_pending_nicks", 2);
    return 1;
}

public void _pending_nicks() { return CHARMASTER->CheckPendingNames(); }
