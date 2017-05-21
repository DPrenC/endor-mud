/**
 * SIMAURIA '/std/living/view.c'
 */

#include <properties.h>
#include <moving.h>
#include <search.h>
#include <config.h>
#include <npc.h>
#include <magia.h>
#include <wizlevels.h>
#include <messages.h>

//-----------------------------------------------------------------------------

public varargs mixed Query(string name);          // std/base
public varargs int CanSee(object env);            // std/living/description
public varargs int CantSee(object env);           // std/living/description
public varargs mixed Search(mixed what, int mode);
                                                  // std/living/description
public varargs mixed SearchM(mixed what, int mode, closure pred);
                                                  // std/living/description
public string QueryName();                        // std/living/description
public string QueryObjective();                   // std/living/description
public string QueryPossessive();                  // std/living/description
public string *_weapons (string poss);
public string *_armours ();
public mapping sortObjsByEnv (object * what, object me, object * envs);
                                                  // std/living/putget

//-----------------------------------------------------------------------------

public int aBrief, aObvious = 1;

//-----------------------------------------------------------------------------

public int QueryBrief()    { return aBrief; }
public int SetBrief(int b) { return aBrief = b; }

public int QueryObvious()    { return aObvious; }
public int SetObvious(int o) { return aObvious = o; }

public int CheckLight () {
  int ct;

  if (Query(P_BLIND)) {
    notify_fail("Estás ciego.\n", NOTIFY_NOT_VALID);
    return (1<<32);
  }
  if (ct = CantSee())
  {
    if (ct < 0)
      notify_fail("Está demasiado oscuro.\n", NOTIFY_NOT_VALID);
    else
      notify_fail("Hay demasiada luz.\n", NOTIFY_NOT_VALID);
  }
  return ct;
}

public varargs mapping describeEnvs (mixed envs, int str_by_obj)
{
  object *dinv, *inv, *denvs, denv, env;
  mixed tmp;
  mapping rc;
  int i, j, alive;
  string msg, sh;

  if (!pointerp(envs))
    envs = ({ envs });

  inv = ({ TO })+all_inventory(TO);
  dinv = ({ TO })+deep_inventory(TO);

  denvs = ({});
  for (denv = environment(TO); denv; denv = environment(denv))
    denvs += ({ denv });

  rc = m_allocate(0,2);
  for (i = 0; i < sizeof(envs); i++)
  {
    if (-1 != member(dinv, env = envs[i]))
    {
      msg = "que lleva consigo ";
      while (env != TO) {
        if ("" != (sh = (string) env->Short()||""))
          msg += "en "+sh+" ";
        env = environment(env);
      }
    }
    else {
      msg = "";
      while (env && -1 == (j = member(denvs, env)))
      {
        if ("" != (sh = (string) env->Short()||"")) {
          if (living(env)) {
            msg += "llevado por "+(env->QueryName())+" ";
            alive = 1;
          }
          else
            msg += "en "+sh+" ";
        }
        env = environment(env);
      }
      if (j)
        msg += "fuera ";
      else if (!alive && !str_by_obj)
        msg += "aquí ";
    }

    j = (-1 != member(dinv, env = envs[i]));
    msg = msg[0..<2];
    if (!str_by_obj)
    {
      tmp = rc[msg,0];
      if (!tmp)
        rc += ([ msg : ({ env }); j ]);
      else if (-1 == member(tmp, env))
        rc[msg,0] = tmp+({ env });
    }
    else
    {
      rc[env,0] = msg;
      rc[env,1] = j;
    }
  }
  return rc;
}

public varargs mixed LookFor (mixed what, int impl)
{
  mapping bags, envs;
  mixed tmp, found, tmp2, rc;
  string msg, msg2;
  int i, j, k;

  if (stringp(what))
    what = ({ what });

  if (objectp(what))
    what = ({ what });
  else if (pointerp(what)) {
    tmp = filter(what, SF(objectp));
    what = SearchM( filter(what, SF(stringp))
                  , SEARCH_INV_ENV|SM_MULTI|SM_COUNT|WizSearch()
                  );
    if (sizeof(tmp))
      what[FOUND_SINGLE] = envs+(what[FOUND_SINGLE] || ({}));
  }
  else
    what = ({});

  msg = "";

  what[FOUND_SPECS] = 1<<30;
  found = sort_findings(what, 1);
  what = found[FOUND_SINGLE];
  if (found[-FOUND_SINGLE])
    msg = "No hay tantas cosas como piensas.\n";

  // Construye el mensaje para los objetos que no han sido localizados.
  if (j = sizeof(tmp = found[FOUND_IDS]))
    msg = msg+implode_list(tmp, "No encuentras ", ".\n", "ni");
  else if (!sizeof(what))
  {
    if (Query(P_BLIND)) msg += "Estar ciego no te ayuda demasiado.\n";
    else if ((i = CantSee()) < 0) msg += "Está demasiado oscuro para ver nada.\n";
    else if (i > 0) msg += "Hay demasiada luz para ver algo.\n";
    else msg += "No encuentras nada de eso.\n";
  }

  rc = ({ msg });

  bags = sortObjsByEnv(what, TO, &tmp);
  envs = describeEnvs(tmp);

  for (k = 0; k < 2; k++)
  {
    tmp = sort_array(m_indices(envs), SF(<));
    for (i = 0; i < sizeof(tmp); i++)
    {
      if (!envs[tmp[i],1] == !!k)
        continue;
      tmp2 = envs[tmp[i],0];
      found = ({});
      for (j = 0; j < sizeof(tmp2); j++)
        found += bags[tmp2[j]];
      if (sizeof(found))
      {
        msg2 = capitalize(tmp[i])+": "+fold_objlist(found, 1)+".";
        rc += ({ msg2[0..1]+sprintf("%2s%-73=s", "", msg2[2..])[2..]+"\n" });
      }
    }
  }
  if (impl)
    rc = implode(rc, "");
  return rc;
}

public varargs string LookRoom (int flags, object room)
{
  int i;
  object *exclude;
  string ret = "";

  if (!room) room = environment();
  if (!room) return "Estás en medio de ningún sitio.\n";

  if (i = CantSee())
    return (i < 0 ? "Está demasiado oscuro." : "Hay demasiada luz.")
           +" No ves nada.\n";

// [i] Aquí habia una, añadido tb un Query(P_HIDDEN).
  if (!(SENSE_SILENT & flags) && !Query(P_INVIS) && !Query(P_HIDDEN) )
    tell_room(environment(), ({MSG_SEE, QueryName()+" mira a su alrededor.\n" }), ({TO}));

  if (TO) exclude = room->ListDoors(0);

  if( !exclude ) exclude = ({ TO });
  else exclude += ({ TO });

  i = QueryBrief();

  if ((flags & SENSE_MOVE) && i) ret += CAP(room->IntShort())+". ";

  if ((flags & SENSE_EXAMINATE)) ret += room->GetExaIntDesc(exclude, TO);
  else ret += room->GetIntDesc((flags & SENSE_MOVE) && i, exclude, TO);

  return ret;
}

public varargs void LookAfterMove (int method, mixed extra)
{
//  dtell("nyh",sprintf("%O->LookAfterMove(%O, %O)\n",TO, method, extra));
  if (interactive()) {
    if (IS_LEARNER(TO))
      TO->catch_msg((objectp(environment()) ? to_string(environment()) : "???")+"\n");
    TO->catch_msg(LookRoom(SENSE_SILENT|SENSE_MOVE));
  }
}

public varargs string SenseRoom (string type, object room, int flags)
{
  string desc;

  switch(type) {
    case "mirar":
      return LookRoom(0, room);
    case "examinar":
// [i] Le meto mano a estos chequeos, y añado Query(P_HIDDEN)
      if (!Query(P_INVIS) && !Query(P_HIDDEN) )
        tell_room(environment(TO), ({ MSG_SEE, QueryName()+" examina su alrededor.\n" }), ({ TO }));
      return LookRoom(SENSE_SILENT|SENSE_EXAMINATE, room);
    case "oler":
      if (!Query(P_INVIS) && !Query(P_HIDDEN) )
        tell_room(environment(TO), ({ MSG_SEE, QueryName()+" husmea el ambiente.\n" }), ({ TO }));
      desc = (room || environment(TO))->IntSmell();
      return desc || "No huele a nada especial.\n";
      break;
    case "escuchar":
      if (!Query(P_INVIS) && !Query(P_HIDDEN) )
        tell_room(environment(TO), ({ MSG_SEE, QueryName()+" escucha atentamente.\n" }), ({ TO }));
//[i] jo, me he puesto las botas.
      desc = (room || environment(TO))->IntNoise();
      return desc || "No escuchas ningún sonido fuera de lo común.\n";
      break;
    default:
      return "No notas nada.\n";
  }
  return desc || "No puedes "+type+" nada.\n";
}

public varargs mixed Sense (mixed what, string type, int flags)
{
  object env, obj;
  mapping envs, shorts;
  mixed tmp, found, tmp2, rc, *det, msg, msg2, msg3;
  string verb;
  int i, j, k;

  if (!type)
    type = "mirar";

  if(!(env = environment()))
    msg = "Estás en el más allá, o en el más acá... ¡yo que sé, en algún lao!\n";
  else
    msg = "";

  if (stringp(what))
    what = ({ what });

  if (objectp(what))
    what = ({ what });
  else if (pointerp(what)) {
    tmp = filter(what, SF(objectp));

    what = SearchM( tmp2 = filter(what, SF(stringp))
                  , SEARCH_INV_ENV|SM_MULTI|SM_COUNT|WizSearch()
                  );
    if (sizeof(tmp))
      what[FOUND_SINGLE] = envs+(what[FOUND_SINGLE] || ({}));
  }
  else
    what = ({});

#ifdef READCODE
  if (type != "leer")
    found = sort_findings(what);
  else
    found = sort_findings(what, sort_f_nprop(P_READ_MSG));
#else
  found = sort_findings(what);
#endif

  what = found[FOUND_SINGLE];
  if (found[-FOUND_SINGLE])
    msg += "No hay tantas cosas como piensas.\n";

  det = ({});
  k = 0; // hidden flag
  if (env && sizeof(what) && -1 != member(what, env)) {
    det = env->QueryIndoors() ? ({ "suelo", "tierra" }) : ({ "tierra" });
    det = det & tmp2;
    k = sizeof(det); // Hidden flag
  }
  tmp2 -= ({ "suelo", "tierra" });
  if (env && sizeof(tmp2)) {
    det += (tmp2-det);
    k = sizeof(det); // Hidden flag
  }
  tmp = det+((found[FOUND_IDS]||({}))-det);
  if (env && (j = sizeof(tmp)))
  {
    det = allocate(j);
    for (i = 0; i < j; i++)
    {
      switch(type) {
      case "mirar":
        msg2 = (string)env->GetDetail(tmp[i]);
        if (pointerp(msg2))
          msg2 = msg2[0];
        break;
      case "examinar":
        msg2 = (string)env->GetDetail(tmp[i]);
        if (pointerp(msg2))
          msg2 = msg2[1];
        break;
      case "escuchar":
        msg2 = (string)env->GetNoise(tmp[i]);
        break;
      case "oler":
        msg2 = (string)env->GetSmell(tmp[i]);
        break;
      case "leer":
        msg2 = (string)env->GetReadMsg(tmp[i]);
        break;
      }
      if (msg2) {
        det[i] = ({ msg2, tmp[i] });
        tmp[i] = 0;
      }
    }
    while (k--)
      if (!det[k])
        tmp[k] = 0;
      else if (pointerp(what))
        what -= ({ env });
    det -= ({ 0 });
    tmp -= ({ 0 });
  }

  if (   !sizeof(what) && !sizeof(det)
#ifdef READCODE
      && (type != "leer" || !sizeof(found[FOUND_NOTHANDLE]))
#endif
     )
  {
    if (Query(P_BLIND)) msg += "Estar ciego no te ayuda mucho.\n";
    else if ((i = CantSee()) < 0) msg += "Está demasiado oscuro para ver algo.\n";
    else if (i > 0) msg += "Hay demasiada luz para ver algo.\n";
    else msg += "No ves nada de eso.\n";
  }
  else if (j = sizeof(tmp))
    msg = msg+implode_list(tmp, "No ves ", ".\n", "ni");

#ifdef READCODE
  if (type == "leer" && (j = sizeof(tmp = found[FOUND_NOTHANDLE])))
  {
    tmp = "No hay nada que leer en "+fold_objlist(tmp, 1)+".";
    msg += tmp[0..1]+sprintf("%2s%-73=s", "", tmp[2..])[2..]+"\n";
  }
#endif

  rc = ({ msg });
  sortObjsByEnv(what, TO, &tmp);
  envs = describeEnvs(tmp, 1);

  found = ([]);
  shorts = ([]);
  j = (sizeof(what)+sizeof(det) > 1);

  for (i = 0; i < sizeof(what); i++)
  {
    //[t] Los players no pueden hacer nada con algo invisible.
    //[i] Basicamente con nada que no puedan ver.
    if (TP->Query(P_SEE_INVIS) >=what[i]->Query(P_INVIS)  ||
    	TP->Query(P_SEE_HIDDEN)>=what[i]->Query(P_HIDDEN) ||
    	IS_LEARNER(TP))
    {
    if (what[i] != TO)
    {
      tmp = (what[i]->QueryIds()||({"algo"}))[<1];
      msg = 0;
      if ("" == (msg2 = what[i]->Short(tmp)))
        msg2 = 0;
      else
        msg = msg2;
    }
    else
    {
      msg2 = "a tí mism"+(TP->QueryGenderEndString());
      msg = "a sí mism"+(TP->QueryGenderEndString());
      tmp = "a tí mism"+(TP->QueryGenderEndString());
    }

    if ("" != (msg3 = envs[environment(what[i]),0]))
    {
      if (msg)
        msg += " ("+msg3+")";
      msg3 = ", "+msg3;
    }

    if (msg) {
      if (!shorts[msg])
        shorts[msg] = ({ what[i] });
      else
        shorts[msg] += ({ what[i] });
    }

    msg = "";
    if (j && msg2)
      msg += "  ("+msg2+msg3+")\n";

    if (
#ifdef READCODE
        type != "leer" &&
#endif
        -1 != member(deep_inventory(what[i]), TO)
       )
      tmp2 = SenseRoom(type, what[i]);
    else if (msg2)
      switch(type) {
      case "leer":
        tmp2 = what[i]->Read(tmp) || "No hay nada que leer.\n";
        break;
      case "mirar":
        tmp2 = what[i]->Long(tmp)+
         (IS_LEARNER(TP)&&(what[i]->Content(type, 1))||"")||"";
        break;
      case "examinar":
        tmp2 = what[i]->ExaLong(tmp)+
         (IS_LEARNER(TP)&&(what[i]->Content(type, 1))||"")||"";
        break;
      case "escuchar":
        tmp2 = what[i]->Noise(tmp) || "No escuchas nada.\n";
        break;
      case "oler":
        tmp2 = what[i]->Smell(tmp) || "No hueles nada.\n";
        break;
      }

    msg += tmp2;

    if (!m_contains(&k, found, msg)) {
      rc += ({ ({ 1, msg2, msg3, tmp2 }) });
      found[msg] = sizeof(rc)-1;
    }
    else
      rc[k][0]++;
    }
  }
  //[t] Si no has visto nada (todo es invisible), devuelve el error.
 // if (sizeof(rc)==1) return "No ves nada de ese estilo.\n";

  for (i = 1; i < sizeof(rc); i++)
  {
    msg = "";
    if (j && rc[i][1])
    {
      msg += "  ("+rc[i][1];
      if (rc[i][0] > 1)
        msg += "["+rc[i][0]+"]";
      msg += rc[i][2]+")\n";
    }
    rc[i] = msg+rc[i][3];
  }

  msg3 = ({});
  for (i = 0; i < sizeof(det); i++)
  {
    rc += ({ (j ? "  ("+det[i][1]+", aquí)\n" : "")+det[i][0] });
    msg3 += ({ det[i][1] });
  }

  if (flags & SENSE_IMPL)
  {
    if (sizeof(rc) > 2)
      rc = rc[0]+implode(rc[1..], "\n");
    else
      rc = implode(rc, "");
  }

// [w] Algunas modificaciones a partir de aqui, 3-2-98
// [i] Tb le meto mano a esto.
  if (!(flags & SENSE_SILENT) && !Query(P_INVIS) && !Query(P_HIDDEN)
      && (sizeof(msg3) || sizeof(what))
     )
  {
    switch(type) {
    case "leer":
      msg += "lee";
      break;
    case "mirar":
      msg += "mira";
      break;
    case "examinar":
      msg += "examina";
      break;
    case "escuchar":
      msg += "escucha";
      break;
    case "oler":
      msg += "huele";
      break;
    }

    tmp2 = m_indices(shorts);

   if(sizeof(what)==1 && interactive(what[0])
      && environment(what[0])==environment(TO))
   {
    if (what[0]==TO) // Si se mira a si mismo.
    {
     tell_room(environment(TO), ({ MSG_SEE, capitalize(QueryName())+" se "+
       msg+" a si mism"+(TO->QueryGenderEndString())+
       ".\n"}),({TO}));
    } else
    {
     tell_room(environment(TO), ({ MSG_SEE, capitalize(QueryName())+" "+
       msg+" a "+capitalize(what[0]->QueryName())+
       ".\n"}), ({what[0],TO}));
     tell_object(what[0],
       capitalize(QueryName())+" te "+msg+".\n");
    }
    return rc;
   }

    msg = QueryName()+" "+msg+" ";

// [w] Fin de la parte modificada.

    if (sizeof(what))
      tmp = filter(what, SF(living)) - ({ TO }) + ({ TO });
    else
      tmp = ({ TO });

    for (i = sizeof(tmp); i--; )
    {
      msg2 = msg3+({});
      for (j = sizeof(tmp2); j--; ) {
        found = shorts[tmp2[j]];
        if (   tmp[i] != TO && -1 != member(found, tmp[i]))
          found -= ({ tmp[i] });
        if (sizeof(found)) {
          if (sizeof(found) > 1)
            msg2 += ({ tmp2[j]+"["+sizeof(found)+"]" });
          else
            msg2 += ({ tmp2[j] });
        }
      }
      if (tmp[i] != TO)
        msg2 += ({ "a ti" });
      if (sizeof(msg2))
      {
        if (sizeof(msg2) > 1)
          msg2 = implode(msg2[0..<2], ", ")+" y "+msg2[<1];
        else
          msg2 = msg2[<1];
        msg2 = msg+msg2+".";
        msg2 = msg2[0..1]+sprintf("%2s%-73=s", "", msg2[2..])[2..]+"\n";
        if (tmp[i] != TO)
          tell_object(tmp[i], ({ MSG_SEE, msg2 }));
        else
           tell_room(environment(TO), ({ MSG_SEE, msg2 }), tmp);
      }
    }
  }

  return rc;
}

public varargs int fbuscar(string arg) // [g] 12/06/97 (look for)
{
 string to;
 if (!arg) {
   TO->catch_tell("¿Buscar qué?\n");
   return 1;
 }
 if (sscanf(arg,"a %s",to)==1) arg=to;
 TO->catch_tell(LookFor(arg,1));
 return 1;
}

public varargs int flook (string arg)
{
  string to;

  if (   !arg
      || -1 != member(({"","habitacion","habitación","aqui","aquí","alrededor"}), norm_id(arg))
     ) {
    TO->catch_tell(LookRoom());
    return 1;
  }

  if (   1 == sscanf(arg, "a %s", to)
      || (to = arg)
     )
  {
    TO->catch_tell(Sense(to, "mirar", 1));
    return 1;
  }

  return notify_fail("¿Mirar qué?\n", NOTIFY_NOT_CMD);
}

public varargs int flooka (string arg)
{
  string to;

  if (   (strlen(query_verb()) > strlen("mirar"))
      || (query_verb() != "mirar"[0..strlen(query_verb())-1])
     )
    return 0;
  return flook(arg);
}

public varargs int fexamine (string arg)
{
  if (   !arg
      || -1 != member(({"","habitacion", "habitación"}), norm_id(arg))
     ) {
// [i] No había algo como este más arriba?  (???)
    if (!Query(P_INVIS) && !Query(P_HIDDEN) )
      tell_room(environment(TO), ({ MSG_SEE, QueryName()+" examina su alrededor.\n" }), ({ TO }));
    TO->catch_tell(LookRoom(SENSE_SILENT|SENSE_EXAMINATE));
    return 1;
  }
  TO->catch_tell(Sense(arg, "examinar", SENSE_IMPL));
  return 1;
}

public varargs int fexaminea (string arg)
{
  if (   (strlen(query_verb()) > strlen("examinar"))
      || (query_verb() != "examinar"[0..strlen(query_verb())-1])
     )
    return 0;
  return fexamine(arg);
}

public varargs int flisten (string arg)
{
  string to;

  if (   !arg
      || -1 != member(({"","habitacion","habitación","ambiente"}), norm_id(arg))
     ) {
    TO->catch_tell(SenseRoom("escuchar"));
    return 1;
  }
  if (   1 == sscanf(arg, "%s", to)
      || (to = arg)
     )
  {
    TO->catch_tell(Sense(to, "escuchar", SENSE_IMPL));
    return 1;
  }

  return notify_fail("¿Escuchar qué?\n", NOTIFY_NOT_CMD);
}

public varargs int fsmell (string arg)
{
  string to;

  if (   !arg
      || -1 != member(({"","habitación","habitacion","ambiente"}), norm_id(arg))
     ) {
    TO->catch_tell(SenseRoom("oler"));
    return 1;
  }
  if (   1 == sscanf(arg, "%s", to)
      || (to = arg)
     )
  {
    TO->catch_tell(Sense(to, "oler", SENSE_IMPL));
    return 1;
  }

  return notify_fail("¿Oler qué?\n", NOTIFY_NOT_CMD);
}

public varargs int fread (string arg)
{
  if (!arg || arg == "") {
    return notify_fail("¿Leer qué?\n", NOTIFY_NOT_CMD);
  }
  TO->catch_tell(Sense(arg, "leer", SENSE_IMPL));
  return 1;
}

private static string
_make_inv (object cont, int mode, int depth, int width) {
  string list, sh;
  mixed  *inv;
  object *sep;
  int i, j, indent;

  indent = 2*depth+2;

  if (INV_LONG & mode)
    inv = ({ all_inventory(cont) });
  else
    inv = unique_array(all_inventory(cont), "InvShort", "");

  list = "";
  for (i = 0; i < sizeof(inv); i++) {

    sep = ({});
    if (INV_LONG & mode) {
      sep = inv[i];
      inv[i] = ({ });
    }
    else if (!(INV_FLAT & mode)) {
      sep = allocate(sizeof(inv[i]));
      for (j = sizeof(inv[i]); j--; )
        if (first_inventory(inv[i][j])) {
          sep[j] = inv[i][j];
          inv[i][j] = 0;
        }
    }

    inv[i] -= ({ 0 });
    sep    -= ({ 0 });

    if (sizeof(inv[i])) {
      sh = inv[i][0]->InvShort();

      if (sizeof(inv[i]) > 1)
        sh = sprintf("%*s- %s [%d]\n", indent-2, "", sh, sizeof(inv[i]));
      else
        sh = sprintf("%*s- %s\n", indent-2, "", sh);

        list += sh[0..indent-1]+sprintf("%*s%-*=s", indent, "", width-indent
                                     , sh[indent..])[indent..];
    }

    for (j = 0; j < sizeof(sep); j++) {
      if ("" == (sh = sep[j]->InvShort()))
        continue;
      sh = sprintf("%*s- %s\n", indent-2, "", sh);
      list += sh[0..indent-1]+sprintf("%*s%-*=s", indent, "", width-indent
                                     , sh[indent..])[indent..];
    }
  }
  if (list[<1] != '\n')
    list += "\n";
  return list;
}

public varargs string Inventory (int mode) {
  return _make_inv(TO, mode, 0, (mode & INV_NARROW) ? 38 : 78);
}

public int finventory (string arg) {
  string *list;
  int mode, low, high;

  mode = INV_NARROW;
  list = ({});
  if (arg) {
    list = explode(lower_case(arg), " ");
    if (member(list, "flat") != -1)
      mode |= INV_FLAT;
    if (member(list, "largo") != -1)
      mode |= INV_LONG;
    if (member(list, "lista") != -1)
      mode ^= INV_NARROW;
  }

  if (CheckLight())
    return 0;

  if (   !first_inventory(TO)
      || !sizeof(map_objects(all_inventory(TO), "InvShort")-({ 0, "" }))
     )
    TO->catch_tell("No tienes nada.\n");
  if (member(list, "equipo") != -1 || member(list, "equipapiento") != -1)
  {
    string str, *strs;
    mixed objs;

    str = "";
    strs = _armours();
    if (sizeof(strs))
      str = implode_list(strs, "Te equipas con ", ".\n");
    strs = _weapons("tu");
    if (sizeof(strs))
      str += "Empuñas "+implode(strs, ".\nEmpuñas ")+".\n";
    if (!strlen(str) )
      str = "No puedes ni empuñar ni equipar nada.\n";
    TO->catch_tell(str);
    return 1;
  }
  if (!(mode & INV_NARROW))
    TO->catch_tell(Inventory(mode));
  else {
    list = explode(Inventory(mode), "\n") - ({ "" });
    if (sizeof(list) & 1)
      list += ({ "" });
    high = (sizeof(list)+1)/2;
    for (low = 0; low < high; low++)
      printf("%-40s%-s\n", list[low], list[high+low]);
  }
  return 1;
}

public void add_view_cmds ()
{
  add_action("fexaminea", "exa", 1);
  add_action("finventory", "i");
  add_action("finventory", "inventario");
  add_action("finventory", "inv");
  add_action("flooka", "m",1);
  add_action("fread", "leer");
  //add_action("fbuscar","buscar");
  add_action("flisten", "escuchar");
  add_action("fsmell", "oler");
}
