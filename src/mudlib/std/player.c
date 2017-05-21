/**
 * SIMAURIA '/std/player.c'
 */


#include <classes.h>
#include <properties.h>
#include <npc.h> //[t] nuevo include para el PUTGET_REALLY

#include "/secure/wizlevels.h"
#include UDP_HEADER

#ifndef MAX_IDLE_TIME
#define MAX_IDLE_TIME   1800
#endif

//Nyh
#define LOG_COMBAT_STATISTICS

/* Comandos heredados */
inherit "/std/base";

inherit "/std/living/attributes"; //[h] Antes era en player, ya no.
inherit "/std/living/cmds";
inherit "/std/living/combat";
inherit "/std/living/commands";
inherit "/std/living/equipment";
inherit "/std/living/groups";
inherit "/std/living/heart";
inherit "/std/living/moving";
inherit "/std/living/perception";
inherit "/std/living/putget";
inherit "/std/living/stats";
inherit "/std/living/view";

inherit "/std/player/comm";
inherit "/std/player/config";       // Configuracion del player
inherit "/std/player/description";
inherit "/std/player/body";
inherit "/std/player/restrictions";
inherit "/std/player/saveload";     // Graba y recupera el player
inherit "/std/player/skills";
inherit "/std/player/soul";
inherit "/std/player/spells";
inherit "/std/player/utils";        // Comandos de utilidades.

//-----------------------------------------------------------------------------

public int remove() { return "saveload"::remove(); }

public int QueryNetdead() {
    return TO && query_once_interactive(TO) && !interactive();
}

//-----------------------------------------------------------------------------

create() {
  "*"::create();

  /* dont mess with the blueprint */
  if (!clonep()) return;

  if (load_name(PO) != LOGIN) {
    TO->catch_tell("Cargado por '"+load_name(PO)+"'\n");
    write("You are struck by a mental bolt from the interior of the game.\n");
    log_file("ILLEGAL", ctime(time()) + ":\n");
    log_file("ILLEGAL", TI->QueryRealName() + " Clone of /std/player\n");
    destruct(TO);
    return;
  }

  AddClassId(C_PLAYER);
  SetLevel(-1);
  SetName("<logon>");
  SetAlign(0);
  SetTTY("none");
  SetChannels(CHANNELMASTER->QueryPlayerDefaultChannels());
  SetDrink(100);
  SetFood(100);
  SetAlcohol(0);
  SetWhimpy(15);
  SetGhost(1);
  SetEchoMode(1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
}

reset() {
  "*"::reset();
  /* HBSTAT */
  clean_hbstat();
}

init()
{
    "*"::init();
}

heart_beat() {
    ResetCmdDataStack();
    "*"::heart_beat();

    if (interactive()) { // Conectado
        if (   !IS_LEARNER(TO)
             && interactive(TO)
             && query_idle(TO)>MAX_IDLE_TIME)
        {
            log_file("idle.log", sprintf("%O: %O sale por estar idle %O segundos.\n",
                     ctime(), capitalize(TO->QueryRealName()),query_idle(TO)));
            TO->catch_msg("Demasiado tiempo pasivo, tendrás que volver a conectar.\n\n");

            save();
            call_out("remove", 1);
        }
    }
    else { // Desconectado
        destruct_player();
    }
}

//-----------------------------------------------------------------------------
