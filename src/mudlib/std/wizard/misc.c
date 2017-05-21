/**
 * SIMAURIA '/std/wizard/misc.c'
 */

#include "/secure/wizlevels.h"
#include "/secure/config.h"
#include <config.h>
#include <magia.h>
#include <moving.h>
#include <search.h>
#include <properties.h>
#include <stdrooms.h>
#include <sounds.h>
//-----------------------------------------------------------------------------

string exp_fname (string fname); // std/wizard/filesys
public int QueryInwiz(); // std/wizard/description
public string QueryCurrentDir(); // std/wizard/filesys
public varargs int move(mixed dest, int method, mixed extra);
                                 // std/living/moving

//-----------------------------------------------------------------------------

private mapping aTargets;   // Lista de objetivos

public mapping QueryTargets()        { return copy(aTargets); }
public mapping SetTargets(mapping m) { return aTargets = m; }

/*-------------------------------------------------------------------------
** Add all commands we're implementing.
*/

static void add_misc_commands() {
  add_action("ftarget", "objetivo");
}

/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
public object * find_target(string arg, int is_trans, int is_locate)
/* Find the target for a goto/in-command (is_trans is FALSE) or
 * a trans command (is_trans is TRUE).
 * is_locate has to be set if the target is just to be located (for adding
 * to the aTargets mapping).
 * Result is the ({ object, it's environment }) or 0.
 * If the object can't be found, a notify_fail() has been set.
 *
 * Syntaxes:
 *             <target>
 *   liv[ing]  <name>
 *   pl[ayer]  <name>
 *   obj[ect]  <object spec>|<object filename>
 *   room      <object spec>|<object filename>
 *   target    <name>
 */
{
  string spec, *tmp, name, temp;
  object obj, env;
  int try, flag, i;
  mixed rc;

#define TRY_LIVING   (1<<0)
#define TRY_PLAYER   (1<<1)
#define TRY_OBJ_SPEC (1<<2)
#define TRY_OBJ_NAME (1<<3)
#define TRY_ROOM     (1<<4)
#define TRY_TARGET   (1<<5)
#define TRY_ALL      (0xFF)

  try = TRY_ALL;

  if (is_trans) try = try & ~(TRY_ROOM);

  tmp = explode(arg, " ") - ({ "", 0 });
  if (!sizeof(tmp)) {
    if (is_trans)
      notify_fail("¿A quién quieres transportar?\n", NOTIFY_NOT_VALID);
    else
      notify_fail("¿"+capitalize(query_verb())+" donde?\n", NOTIFY_NOT_VALID);
    return 0;
  }

  flag = 0;
  if (sizeof(tmp) > 1) {
    flag = 1;
    switch(lower_case(tmp[0])) {
      case "monstruo": case "mon": case "pnj": case "npc":
        try = try & TRY_LIVING;
        break;
      case "jugador": case "jug":
        try = try & TRY_PLAYER;
        break;
      case "objeto": case "obj":
        try = try & (TRY_OBJ_SPEC|TRY_OBJ_NAME);
        break;
      case "habitacion": case "hab":
        if (is_trans) try = try & (TRY_ROOM);
        else flag = 0;
        break;
      case "objetivo":
        try = try & TRY_TARGET;
        break;
      default:
        flag = 0;
        break;
    }
  }
  spec = implode(tmp[(flag ? 1 : 0)..], " ");

  obj = env = 0;

  // Try to find the object by living name.
  if (try & TRY_LIVING) {
    obj = find_object(lower_case(spec));
  }
  // Try to find the object by player name.
  if (!obj && (try & TRY_PLAYER)) {
    obj = find_object(lower_case(spec));
  }
  // Try to find the object by object specification.
  if (!obj && (try & TRY_OBJ_SPEC)) {
    obj = is_trans ? search_env_inv(spec) : search_env(spec);
  }
  // Try to find the object by target specification.
  if (!obj && (try & TRY_TARGET) && sizeof(aTargets)) {
    name = aTargets[lower_case(spec)];
    if (stringp(name))
    {
      obj = find_object(name);
      if (!obj) {
        rc = catch((obj = load_object(name)));
        if (rc) notify_fail("No se puede cargar "+arg+": "+rc);
      }
      if (!is_trans && obj && !living(obj)) env = obj;
    }
  }
  // Try to find the object by filename.
  if (!obj && (try & (TRY_OBJ_NAME|TRY_ROOM))) {
    name = exp_fname(spec);

    if (-1 == member("~+&/", name[0])) name = QueryCurrentDir()+"/"+name;

    name = resolve_file(name);
    obj = find_object(name);
    if (!obj && ".c" == name[<2..]) {
      name = name[0..<3];
      obj = find_object(name);
    }

    sscanf(name,"%s %s",name,temp);
    if (!obj && -1 == member(name, '#') && file_size(name+".c") >= 0) {
      rc = catch((obj = load_object(name)));
      if (rc) notify_fail("No se puede cargar "+arg+": "+rc);
  }

    if (!is_trans && obj)
      if (!living(obj) || TRY_ROOM == (try & (TRY_OBJ_NAME|TRY_ROOM)))
        env = obj;
  }

  // Evaluate the finding. If env is valid here, it is the room to go into.
  if (!obj) {
    if (!is_locate)
      notify_fail("No se puede encontrar "+arg+" ("+name+").\n", NOTIFY_NOT_VALID);
    else
      notify_fail("No se puede localizar "+arg+".\n", NOTIFY_NOT_VALID);
    return 0;
  }
  if (!env) env = environment(obj);

  return ({ obj, env });

#undef TRY_LIVING
#undef TRY_PLAYER
#undef TRY_OBJ_SPEC
#undef TRY_OBJ_NAME
#undef TRY_ROOM
#undef TRY_ALL
}

/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
public varargs int ftarget (string arg)
/* Sintaxis:
 *   objetivo <nombre> <objetivo>
 *   objetivo <nombre> eliminar
 *   objetivo <nombre>
 *   objetivo lista
 */
{
    string * args;
    string   tname;
    object * target;
    int      i;

    if (!arg) return notify_fail(" Uso: objetivo <nombre> <objetivo>\n"
                                 "      objetivo <nombre> eliminar\n"
                                 "      objetivo <nombre>\n"
                                 "      objetivo lista\n");

    args = explode(arg, " ") - ({ 0, "" });
    if (sizeof(args) < 1) return 0;

    if (sizeof(args) == 1 && lower_case(args[0]) == "lista") {
        if (!sizeof(aTargets)) write("No se ha especificado ningún objetivo.\n");
        else {
            tname = "";
            args = sort_array(m_indices(aTargets), SF(>));
            for (i = sizeof(args); i-- ; )
                tname += sprintf("%-15.15'.'s %s\n", args[i], aTargets[args[i]]);
            write(tname);
        }
        return 1;
    }

    if (sizeof(args) < 2) {
        if (!sizeof(aTargets))
            write("No se ha especificado ningún objetivo.\n");
        else {
            tname = aTargets[args[0]];
            if (!tname) write(sprintf("'%s' no es un objetivo.\n", args[0]));
            else write(sprintf("%-15.15'.'s %s\n", args[0], tname));
        }
        return 1;
    }

    tname = args[0];

    if (sizeof(args) == 2 && args[1] == "eliminar") {
        if (!sizeof(aTargets) || !aTargets[tname])
            write(sprintf("El objetivo '%s' no esta aquí para ser eliminado.\n", tname));
        else {
            aTargets = m_delete(aTargets, tname);
            write(sprintf("El objetivo '%s' ha sido eliminado.\n", tname));
        }
        return 1;
    }

    target = find_target(implode(args[1..], " "), 1, 1);
    if (!target) return 0;
    if (!sizeof(aTargets)) aTargets = ([ tname : to_string(target[0]) ]);
    else m_add(aTargets, tname, to_string(target[0]));

    write(sprintf("Ha sido establecido el objetivo '%s' por '%s'.\n", tname, to_string(target[0])));
    return 1;
}

/*************************************************************************/
