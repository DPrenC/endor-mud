/**
 * SIMAURIA '/std/wizard.c'
 */


#include "/secure/wizlevels.h"

#define MDTQS "/obj/lib/mdtqs"

//------------------------------------------------------------------------------

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
inherit "/std/living/putget";
inherit "/std/living/stats";
inherit "/std/living/view";

inherit "/std/player/config";       // Configuracion del player
inherit "/std/player/restrictions";
inherit "/std/player/skills";
inherit "/std/player/soul";
inherit "/std/player/spells";
inherit "/std/player/utils";        // Comandos de utilidades.

inherit "/std/wizard/body";
inherit "/std/wizard/comm";
inherit "/std/wizard/description";
inherit "/std/wizard/filesys";
inherit "/std/wizard/misc";
inherit "/std/wizard/perception";
inherit "/std/wizard/saveload";     // Graba y recupera el player
inherit "/std/wizard/wiz_utils";

//-----------------------------------------------------------------------------

public int remove() {
  return "saveload"::remove();
}

public int QueryNetdead() {
    return TO && query_once_interactive(TO) && !interactive();
}

//----------------------------------------------------------------------------

protected _add_commands() {
    ::_add_commands();

    add_filesys_commands();
    add_wiz_utils_cmds();
}

//----------------------------------------------------------------------------

public string *QueryDomains() {
  string *dm;
  int i;

  dm = MDTQS->GetWizardInfo(TO->QueryRealName());
  if (!dm) return 0;

  for (i=sizeof(dm); i--; ) dm[i] = dm[i][1..];
  return dm;
}

//----------------------------------------------------------------------------

create() {
  string str1;

  "*"::create();

  /* dont mess with the blueprint */
  if (!clonep()) return;

  str1 = explode(PO ? object_name(PO) : "<none>", "#")[0];

  if (str1 != LOGIN) {
    TO->catch_tell("Clonado por '"+str1+"'\n");
    write("You are struck by a mental bolt from the interior of the game.\n");
    log_file("ILLEGAL", ctime(time()) + ":\n");
    log_file("ILLEGAL", TI->QueryRealName() + " Clone of /std/wizard\n");
    destruct(TO);
    return 0;
  }

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

    if (!interactive()) { // Desconectado
        destruct_player(1); // El 1 es para forzar que salga aunq algo lo impida
    }
}

//-----------------------------------------------------------------------------
