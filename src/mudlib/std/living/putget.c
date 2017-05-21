/**
 * SIMAURIA '/std/living/putget.c'
 */

#include "/secure/wizlevels.h"
#include <properties.h>
#include <moving.h>
#include <search.h>
#include <config.h>
#include <npc.h>
#include <magia.h>
#include <messages.h>

#undef ENV
#define ENV   environment

/*--------------------------------------------------------------------------*/

public varargs mixed Search(mixed what, int mode);
                                       // std/living/description
public varargs mixed SearchM(mixed what, int mode, closure pred);
                                       // std/living/description
public string QueryName();             // std/living/description
public string QueryObjective();        // std/living/description

//--------------------------------------------------------------------------
/* Asin funciona GetArticle:
   le metes el string que tengas (pe. de poner "coger grillo", le metes
   "grillo") y te devuelve un array de strings de 2 componentes:
   femenino) string[0]="la"/"las" y string[1]="una"/"unas" dependiendo de si
             el objeto es singular o plural
   masculino) string[0]="el"/"los" y string[1]="un"/"unos"...
*/

public int GetGender(mixed thing) {
  if (thing[strlen(thing)-1]=='s') {
    if (thing[strlen(thing)-2]=='a') return(5);
    else return(4);
  }
  else {
    if (thing[strlen(thing)-1]=='a') return(2);
    else return(1);
  }
}

// [w] Anyadida esta funcion, ya que el QueryArticle() solo
//     funcionaba a partir del nombre y en casos como:
//       > Una hacha de combate
//     Al acabar en 'e' lo hacia masculino.
public string QueryGenderNumber(object thing)
{
 string s;

 if (!thing) return "";

 if(thing->Query(P_GENDER)==GENDER_FEMALE) s="a";
 else s="o";
  
 if(thing->Query(P_NUMBER)==NUMBER_PLURAL) s+="s";

 return s;
}

public mixed QueryArticle(mixed thing) {
  if (!thing) return ""; // [anyadido]
  if (thing[strlen(thing)-1]=='s') {
    if (thing[strlen(thing)-2]=='a') return("as");
    else return("os");
  }
  else {
    if (thing[strlen(thing)-1]=='a') return("a");
    else return("o");
  }
}

public mixed *GetArticle(mixed thing) {
  mixed *d;

  d=({"",""});
  if (!thing) return(d);
  if (living(to_object(to_string(thing)))) return(d);
  if (strlen(to_string(thing))<1) return(d);
  if (thing[strlen(to_string(thing))-1]=='s') {
    if (thing[strlen(thing)-2]=='a') {
      d[0]="las";
      d[1]="unas";
      return(d);
    }
    else {
      d[0]="los";
      d[1]="unos";
      return(d);
    }
  }
  else {
    if (thing[strlen(thing)-1]=='a') {
      d[0]="la";
      d[1]="una";
      return(d);
    }
    else {
      d[0]="el";
      d[1]="un";
    }
  }

  return(d);
}

public mapping sortObjsByEnv(object * what, object me, object * envs) {
  mapping bags;
  object bag, obj;
  int    i;

  // Sort from where the objects were dropped.
  bags = ([]);
  for (i = sizeof(what); i-- > 0; ) {
    obj = what[i];
    bag = ENV(what[i]);

    if( !bags[bag] ) bags[bag] = ({ obj });
    else bags[bag] += ({ obj });
  }
  if (bags[me]) envs = ({ me }) + (m_indices(bags) - ({ me }));
  else envs = m_indices(bags);
  return bags;
}

//--------------------------------------------------------------------------
public varargs string makeFromMsg(object me, mapping bags, object * envs, object * what) {
  string msg, part, sh;
  object bag;
  int    i;


  // Construct and output primary drop message
  msg = "";
  for (i = 0; i < sizeof(envs); i++) {
    bag = envs[i];
    if (living(bag)) {
      sh = bag->QueryName() || bag->Short();
//      if (!sh || sh == "") sh = "alguien";
    }
    else {
      if (bag) {
        sh = bag->Short();
//        if (!sh || sh == "") sh = "en algun lugar";//somewhere
      }
      else sh = 0;
    }
    part="";
    //part = (bag != me && sh) ? (" (de "+sh+")") : "";

    if (pointerp(what)) part += " "+fold_objlist(bags[bag] & what, 1);
    else part += " "+fold_objlist(bags[bag], 1);

    if (0 == i) msg += part;
    else if (i < sizeof(envs)-1) msg = msg+","+part;
    else msg = msg+", y"+part;
  }
  return msg;
}

//--------------------------------------------------------------------------
public varargs mixed * DropTake(string verb, mixed what, int mode) {
  string sh, ne_msg, msg, prop;
  mapping bags, found;
  object *nodrop, obj;
  mixed rc, *envs, tmp, twhat;
  int i,j;

  twhat=what;
  if (stringp(what)) what = ({ what });
  if (objectp(what)) what = ({0, ({ what }), 0, 0, 1 });
  else if (pointerp(what)) {
    if (verb == "tirar" || verb == "dejar")
      // Drop only objects carried.
      tmp = lambda(({SYM(obj)}), ({SF(!=), -1
                                   , ({SF(member), quote(deep_inventory(TO))
                                               , SYM(obj)}) })
                  );
    else
      // Take only objects not directly carried.
      tmp = lambda(({SYM(obj)}), ({SF(==), -1
                                   , ({SF(member)
                                       , quote( ({ TO })+all_inventory(TO))
                                       , SYM(obj)}) })
                  );
    envs = filter(what, SF(objectp));
    what = SearchM( filter(what, SF(stringp))
                  , ((verb == "tirar" || verb == "dejar") ? SEARCH_INV : SEARCH_ENV_INV)
                    |SM_MULTI|SM_COUNT|WizSearch()
                    |(((mode & PUTGET_REALLY) || (verb != "tirar" && verb != "dejar")) ? 0 : SM_REALLY)
                  , tmp
                  );

    if (sizeof(envs)) what[FOUND_SINGLE] = envs+(what[FOUND_SINGLE] || ({}));
  }
  else what = ({});

  // Sort out 'what' into 'found', with the No<verb> objects collected under
  // index FOUND_NOTHANDLE, and put that back into 'what' and 'nodrop'.
  prop = ((verb == "tirar" || verb == "dejar")? P_NODROP : P_NOGET);
  found = sort_findings(what, sort_f_prop(prop));
  what = found[FOUND_SINGLE]||({});
  nodrop = found[FOUND_NOTHANDLE]||({});

  if (found[-FOUND_SINGLE])
    ne_msg = "No puedes "+verb+" tanto como pretendías.\n";

  // If items could not be located, construct the appropriate message in 'msg'.
  // If just some items could not be located, output it immediately.
  if (j = sizeof(tmp = found[FOUND_IDS])) {
    msg =  (ne_msg||"")
          +implode_list(tmp, "No encuentras ", " para "+verb+".\n", "ni");
    ne_msg = 0;
    if (sizeof(what) && !(mode & PUTGET_SILENT))
      TO->catch_msg(msg);
  }
  else if (!sizeof(what) && !sizeof(nodrop))
    msg = "No puedes "+verb+" nada.\n";

  // Check the 'nodrop' and output their messages, clobbering 'envs'.
  // Also, output the 'not enough things' messages if still in 'ne_msg'.
  if (!(mode & PUTGET_SILENT) && sizeof(nodrop)) {
    envs = ({}); 
    for (i = 0; i < sizeof(nodrop); i++ ) {
      obj = nodrop[i];
      sh = (!(mode & PUTGET_SILENT) && obj->Short());
      tmp = obj->Query(prop);
      if (sh && stringp(tmp))
        TO->catch_msg(tmp);
      else envs += ({ obj });
    }
    if (sizeof(envs)) {
      if (capitalize(fold_objlist(envs, 1))!=TP->QueryPresay()+TP->QueryName()+" "+TP->QueryTitle())
      {
        tmp= "No puedes "+verb+" "+capitalize(fold_objlist(envs, 1)+".");
        tmp = tmp[0..1]+sprintf("%2s%-80=s", "", tmp[2..])[2..]+"\n";
        //2-73
      }
      else tmp="";
    }
    if (sizeof(envs) || ne_msg)
      TO->catch_msg((ne_msg||"")+(tmp||""));
  }

  // Prepare this already
  if (mode & PUTGET_FULL) {
    rc = allocate( ({PUTGET_COUNT, 0}) );
    rc[PUTGET_NODROP] = nodrop;
  }
  else rc = ({ });

  // Premature end if there is nothing left to handle.
  if (!sizeof(what)) {
    if (msg) {
      notify_fail(msg, NOTIFY_ILL_ARG);
      return 0;
    }
    return rc;
  }

  // Sort the objects to handle by their environments.
  bags = sortObjsByEnv(what, (verb == "tirar" || verb == "dejar")? TO : ENV(TO), &envs);
  what = ({});
  for (i = 0; i < sizeof(envs); i++)
    what += bags[envs[i]];

  // Now do the actual movement.
  for (i = 0; i < sizeof(what); i++ ) {
    obj = what[i];

    //[t] Los objetos invisibles ni se cogen ni se dejan.
    if (!(obj->Query(P_INVIS) && //!IS_LEARNER(TP) &&
      TP->Query(MP_DETECTINVIS)<obj->Query(P_INVIS)))
    {
    sh = (!(mode & PUTGET_SILENT) && obj->Short());
    switch (obj->move( (verb == "tirar" || verb == "dejar") ? ENV(TO) : TO
                     , (verb == "tirar" || verb == "dejar") ? M_DROP : M_GET)) {
      case ME_OK:
        if (mode & PUTGET_FULL) rc[PUTGET_OK] += ({ obj });
        else rc += ({ obj });
        break;
      case ME_NO_DROP:
      case ME_NO_LEAVE:
        if (mode & PUTGET_FULL) rc[PUTGET_NOLEAVE] += ({ obj });
        if (sh) TO->catch_msg("No puedes "+verb+" "+sh+".\n");
        break;
      case ME_NO_ENTER:
        if (mode & PUTGET_FULL) rc[PUTGET_TOOHEAVY] += ({ obj });
        if (sh) TO->catch_msg("No puedes "+verb+" "+sh+".\n");
        break;
      case ME_TOO_MANY:
        if (mode & PUTGET_FULL) rc[PUTGET_TOOMANY] += ({ obj });
        if (sh) TO->catch_msg(capitalize(sh)+" es demasiado grande.\n");
        break;
      case ME_TOO_BIG:
        if (mode & PUTGET_FULL) rc[PUTGET_TOOBIG] += ({ obj });
        if (sh) TO->catch_msg(capitalize(sh)+" es demasiado grande.\n");
        break;
      case ME_TOO_HEAVY:
        if (mode & PUTGET_FULL) rc[PUTGET_TOOHEAVY] += ({ obj });
        if (sh)
          if ((verb == "tirar" || verb == "dejar"))
            TO->catch_msg("No hay suficiente espacio para "+sh+".\n");
          else
            TO->catch_msg("Eso es demasiado pesado para ti.\n");
        break;
      case ME_NO_GET:
    	if (mode & PUTGET_FULL) rc[PUTGET_NOLEAVE] += ({ obj });
        if (sh) TO->catch_msg("No puedes "+verb+" "+sh+".\n");
        break;
      case ME_NO_GIVE:
      case ME_NO_MOVE:
        if (sh) TO->catch_msg("No puedes mover "+sh+".\n");
        // FALL THROUGH
      default:
        if (mode & PUTGET_FULL) rc[PUTGET_NOMOVE] += ({ obj });
        break;
    }
  }
  }

  // Makeup and output the handle message
  if (!(mode & PUTGET_SILENT)) {
    what = ((mode & PUTGET_FULL) ? rc[PUTGET_OK] : rc) - ({ 0 });
    if (!sizeof(what))
       TO->catch_msg("No "+((verb=="tirar" || verb=="dejar")?"dejas":"coges")+" nada.\n");
    else {
      msg = makeFromMsg((verb == "tirar" || verb == "dejar")? TO : ENV(TO), bags, envs, what);
      tmp = ((verb=="tirar" || verb == "dejar")?(verb=="dejar"?"Dejas":"Tiras"):"Coges")+msg+".";
      tmp = tmp[0..1]+sprintf("%2s%-80=s", "", tmp[2..])[2..];
      TO->catch_msg(tmp+"\n");
      tmp = capitalize(QueryName())+" "+((verb=="tirar"||verb=="dejar")?(verb=="tirar"?"tira":"deja"):"coge")+msg+".";
      tmp = tmp[0..1]+sprintf("%2s%-80=s", "", tmp[2..])[2..];
      tell_room(ENV(TO), ({ MSG_SEE, tmp+"\n" }), ({ TO })+what);
    }
  }

  return rc;
}

//--------------------------------------------------------------------------
public varargs mixed * Drop (mixed what, int mode) {
  return DropTake("tirar", what, mode);
}

//--------------------------------------------------------------------------
public varargs mixed * Take (mixed what, int mode) {
  return DropTake("coger", what, mode);
}

//--------------------------------------------------------------------------
private mixed * takeBefore ( closure action
                           , string verb, mixed what, mixed to, int mode)
{
  mixed *rc, *taken;

  if (sizeof(what)) {
    rc = Take(what, mode);
    if (rc && sizeof(taken = (mode & PUTGET_FULL) ? rc[0] : rc))
      call_out(action, 1, verb, taken, to, mode);
  }
  return rc;
}

//--------------------------------------------------------------------------
public varargs mixed * GivePut (string verb, mixed what, mixed to, int mode)
{
  string to_sh, sh, msg, ne_msg;
  mapping bags, found;
  object *nodrop, *notcarried, obj;
  mixed rc, *envs, tmp;
  int i, j, res;
  mixed twhat;
  int final_give = 0;

  tmp = (verb == "dar" ? "nadie" : "nada");
  if (stringp(to)) {
    tmp = to;
    to = Search(to, SEARCH_INV_ENV|SEARCH_OBJECT|WizSearch());
  }
  else if (!objectp(to))
    to = 0;

  if (!to) {
    notify_fail("No ves a "+tmp+" para "+verb+"le cosas.\n", NOTIFY_ILL_ARG);
    return 0;
  }

  if (to == ENV(TO) && (verb == "tirar" || verb == "dejar"))
    return DropTake(verb, what, mode);

  if (verb == "dar") {
    if (!living(to)) {
      notify_fail("¡"+capitalize(tmp)+"  no es un ser viviente.\n", NOTIFY_ILL_ARG);
      return 0;
    }
    if (to == TO) {
      notify_fail("¿Es tu cumpleaños?\n", NOTIFY_ILL_ARG);
      return 0;
    }
  }

  if (verb == "dar")
    to_sh = (string)(to->QueryName() || to->Short() || "alguien");
  else
    to_sh = (string)(to->Short() || to->QueryName() || "algo");

  if (stringp(what)) {
    what = ({ what });
  }

  if (objectp(what))
    what = ({0, ({ what }), 0, 0, 1 });
  else if (pointerp(what)) {
    envs = filter(what, SF(objectp));
  if (verb!="dar" && verb!="poner")
    what = SearchM( filter(what, SF(stringp))
                    , SEARCH_INV_ENV|SM_MULTI|SM_COUNT|WizSearch()
                      |((mode & PUTGET_REALLY) ? 0 : SM_REALLY)
                    , lambda(({SYM(obj)}), ({SF(!=), to, SYM(obj)}))
                    );
  else
    what = SearchM( filter(what, SF(stringp))
                    , SEARCH_INV|SM_MULTI|SM_COUNT|WizSearch()
                      |((mode & PUTGET_REALLY) ? 0 : SM_REALLY)
                    , lambda(({SYM(obj)}), ({SF(!=), to, SYM(obj)}))
                    );
    if (sizeof(envs))
      what[FOUND_SINGLE] = envs+(what[FOUND_SINGLE] || ({}));
  }
  else
    what = ({});

  // Sort out 'what' into 'found', with the No<verb> objects collected under
  // index FOUND_NOTHANDLE, and put that back into 'what' and 'nodrop'.
  found = sort_findings(what, sort_f_prop(P_NOGIVE));
  what = found[FOUND_SINGLE]||({});
  nodrop = found[FOUND_NOTHANDLE]||({});
  if (found[-FOUND_SINGLE])
    ne_msg="No puedes "+verb+" tantas cosas.\n";

  // Objects lying around need an extra action to be taken.
  notcarried = what - deep_inventory(TO);
//  notcarried = deep_inventory(TO);
//  what = what - notcarried;

  // If items could not be located, construct the appropriate message in 'msg'.
  // If just some items could not be located, output it immediately.
  if (j = sizeof(tmp = found[FOUND_IDS])) {
    msg =  (ne_msg||"")
          +implode_list(tmp, "No encuentras ", " para "+verb+".\n", "ni");
    ne_msg = 0;
    if (sizeof(what) && !(mode & PUTGET_SILENT))
      TO->catch_msg(msg);
  }
  else if (!sizeof(what) && !sizeof(nodrop))
    msg = "No puedes "+verb+" nada.\n";

  // Check the 'nodrop' and output their messages, clobbering 'envs'.
  // Also, output the 'not enough things' messages if still in 'ne_msg'.
  if (!(mode & PUTGET_SILENT) && sizeof(nodrop)) {
    envs = ({});
    for (i = 0; i < sizeof(nodrop); i++ ) {
      obj = nodrop[i];
      sh = (!(mode & PUTGET_SILENT) && obj->Short());
      tmp = obj->Query(P_NOGIVE);
      if (sh && stringp(tmp))
        TO->catch_msg(tmp);
      else if (sh)
        envs += ({ obj });
    }
    if (sizeof(envs)) {
      if (capitalize(fold_objlist(envs, 1))!=TP->QueryPresay()+TP->QueryName()+" "+TP->QueryTitle())
      {
      tmp = "No puedes "+verb+" "+fold_objlist(envs, 1)+".";
      tmp = tmp[0..1]+sprintf("%2s%-80=s", "", tmp[2..])[2..]+"\n";
      }
    }
    if (sizeof(envs) || ne_msg)
      TO->catch_msg((ne_msg||"")+(tmp||""));
  }

  // Prepare this already
  if (mode & PUTGET_FULL) {
    rc = allocate( ({PUTGET_COUNT, 0}) );
    rc[PUTGET_NODROP] = nodrop;
  }
  else {
    rc = ({ });
  }

  // Premature end if there is nothing left to handle.
  if (!sizeof(what)) {
    if (msg)
      notify_fail(msg, NOTIFY_ILL_ARG);

/*    tmp = takeBefore(SF(GivePut), verb, notcarried, to, mode);
    if (!msg && (mode & PUTGET_FULL))
    {
      if (tmp)
        tmp[PUTGET_NODROP] += nodrop;
      else
        tmp = ({ ({}), nodrop, ({}), ({}), ({}) });
    }*/
    return tmp;
  }

  // Sort the objects to handle by their environments.
  bags = sortObjsByEnv(what, TO, &envs);
  what = ({});
  for (i = 0; i < sizeof(envs); i++)
    what += bags[envs[i]];

  // Now do the actual giving
  for (i = 0; i < sizeof(what); i++ ) {
    obj = what[i];

    //[t] Los players no pueden dar o dejar cosas invisibles
    if (!(obj->Query(P_INVIS) && //!IS_LEARNER(TP) &&
    	TP->Query(MP_DETECTINVIS)<obj->Query(P_INVIS)))
    {
    sh = (!(mode & PUTGET_SILENT) && obj->Short());
    res = obj->move(to, verb == "dar" ? M_GIVE : M_PUT);
    if (!(obj->Query(P_INVIS) && !IS_LEARNER(to) &&
    	to->Query(MP_DETECTINVIS)<obj->Query(P_INVIS)))
    switch (res) {
      case ME_OK:
        if (mode & PUTGET_FULL) rc[PUTGET_OK] += ({ obj });
        else rc += ({ obj });
        break;
      case ME_NO_DROP:
      case ME_NO_LEAVE:
        if (mode & PUTGET_FULL) rc[PUTGET_NOLEAVE] += ({ obj });
        if (sh) TO->catch_msg("No puedes coger " + sh +".\n");
        break;
      case ME_NO_ENTER:
        if (mode & PUTGET_FULL) rc[PUTGET_TOOHEAVY] += ({ obj });
        if (sh) {
          if (verb == "dar") {
            TO->catch_msg("No puedes darle "+sh+" a "+to_sh+".\n");
            tell_object(to, capitalize(TO->QueryName())+" no ha podido darte "
                            +sh+".\n");
          }
          else
            TO->catch_msg("No puedes poner "+sh+" en "+to_sh+".\n");
        }
        break;
      case ME_TOO_MANY:
        if (mode & PUTGET_FULL) rc[PUTGET_TOOMANY] += ({ obj });
        if (sh) {
          if (verb == "dar") {
            TO->catch_msg(capitalize(sh)+" es demasiado grande"
                        " para "+to_sh+".\n");
            tell_object(to, capitalize(TP->QueryName())+" intenta darte " + sh
                        + ", pero es demasiado grande para tí.\n");
          }
          else
            TO->catch_msg(capitalize(to_sh)
                              +" tiene las manos llenas.\n");
        }
        break;
      case ME_TOO_BIG:
        if (mode & PUTGET_FULL) rc[PUTGET_TOOBIG] += ({ obj });
        if (sh) {
          if (verb == "dar") {
            TO->catch_msg(capitalize(sh)+" es demasiado grande"
                        " para "+to_sh+".\n");
            tell_object(to, capitalize(TP->QueryName())+" intenta darte " + sh
                        + ", pero es demasiado grande para tí.\n");
          }
          else
            TO->catch_msg(capitalize(to_sh)
                              +" no tiene más espacio.\n");
        }
        break;
      case ME_TOO_HEAVY:
        if (mode & PUTGET_FULL) rc[PUTGET_TOOHEAVY] += ({ obj });
        if (sh) {
          if (verb == "dar") {
            TO->catch_msg(capitalize(sh)+" es demasiado pesad"+
                        QueryGenderNumber(obj)+" para "+to_sh+".\n");
            tell_object(to, capitalize(TP->QueryName())+" intenta darte " + sh
                        + ", pero es demasiado pesad"+ QueryGenderNumber(obj)+" para tí.\n");
          }
          else
            TO->catch_msg(capitalize(to_sh)
                              +" no soporta más peso.\n");
        }
        break;
      case ME_NO_GIVE:
        if (mode & PUTGET_FULL) rc[PUTGET_TOOHEAVY] += ({ obj });
        if (sh) {
          if (verb == "dar") {
            TO->catch_msg("No puedes darle "+sh+ " a "+to_sh+".\n");
            tell_object(to, capitalize(TO->QueryName())+" no puede darte "
            	        +sh+".\n");
          }
          else
            TO->catch_msg(capitalize(to_sh)
                              +" tiene las manos llenas.\n");
        }
        break;
      case ME_NO_GET:
      case ME_NO_MOVE:
        if (sh) TO->catch_msg("No puedes mover "+sh+".\n");
        // FALL THROUGH
      default:
        if (mode & PUTGET_FULL) rc[PUTGET_NOMOVE] += ({ obj });
        break;
    }
    else if( res == ME_OK ) rc[PUTGET_SILENT] += ({ obj });
  }
  }
  //[t] No hay nada para dejar/dar?
  //[g] Arreglado para que no diga que "No encuentras cosa para dar." cuando
  //    lo que pasa es que el otro no puede llevar tanto peso (tambien decia
  //	lo del peso)
  //[t] corrijo un fallo feo, estaba usado PUTGET_FULL como indexador de rc en vez de como flag de modo
  if ((mode & PUTGET_FULL) && sizeof(rc[PUTGET_OK]||({}))==0) {
    msg =  (ne_msg||"")
        +implode_list(what, "No encuentras ", " para "+verb+".\n", "ni");
    ne_msg = 0;
    if (sizeof(what) && !(mode & PUTGET_SILENT))
      notify_fail(msg);
    return 0;
  }

  // Make up and output the handle message
  if (!(mode & PUTGET_SILENT)) {
    if (mode & PUTGET_FULL) {
      what = rc[PUTGET_OK] - ({ 0 });
      if (!sizeof(what) && !sizeof(rc[PUTGET_SILENT]))
        TO->catch_msg("No "+(verb=="dar"?"das":"tiras")+" nada.\n");
      else if (sizeof(rc[PUTGET_SILENT])) {
        msg = makeFromMsg(TO, bags, envs, rc[PUTGET_SILENT]);
        if (verb == "dar")
          sh = " a "+to_sh+".";
        else if (verb == "tirar" || verb == "dejar")
          sh = " sobre "+to_sh+".";
        else
          sh = " en "+to_sh+".";
        tmp = (verb=="dar"?"Le das":"Pones")+msg+sh;
        tmp = tmp[0..1]+sprintf("%2s%-80=s", "", tmp[2..])[2..];
        TO->catch_msg(tmp+"\n");
      }
      else {
        final_give = 1;
      }
    }
    else {
      what = rc - ({ 0 });
      final_give = 1;
    }

    if (final_give) {
      msg = makeFromMsg(TO, bags, envs, what);
      if (verb == "dar")
        sh = " a "+to_sh+".";
      else if (verb == "tirar" || verb == "dejar")
        sh = " sobre "+to_sh+".";
      else
        sh = " en "+to_sh+".";
      tmp = (verb=="dar"?"Le das":"Pones")+msg+sh;
      tmp = tmp[0..1]+sprintf("%2s%-80=s", "", tmp[2..])[2..];
      TO->catch_msg(tmp+"\n");
      tmp = capitalize(QueryName())+" "+(verb=="dar"?"le da":"pone")
              +msg+sh;
        tmp = tmp[0..1]+sprintf("%2s%-80=s", "", tmp[2..])[2..];
        tell_room(ENV(TO), ({ MSG_SEE, tmp+"\n" }), ({ TO, to })+what);
        if (verb == "dar") {
          tmp = capitalize(QueryName())+" te da"+msg+".";
          tmp = tmp[0..1]+sprintf("%2s%-80=s", "", tmp[2..])[2..];
          tell_object(to, ({ MSG_SEE, tmp+"\n", tmp+"\n" }));
        }
    }
  }

  // Now take up objects from around and give them away, too.

/*  tmp = takeBefore(SF(GivePut), verb, notcarried, to, mode);
  if (sizeof(tmp))
    if (mode & PUTGET_FULL)
      for (i = sizeof(rc); i-- > 0; )
        rc[i] += tmp[i];
    else
      rc += tmp;
*/
  return rc;
}

//--------------------------------------------------------------------------
public varargs mixed * Give (mixed what, mixed to, int mode) {
  return GivePut("dar", what, to, mode);
}

//--------------------------------------------------------------------------
public varargs mixed * Put (mixed what, mixed to, int mode) {
  return GivePut("poner", what, to, mode);
}

//--------------------------------------------------------------------------

public varargs int fdrop (string arg)
{
  string tmp, to;
  mixed rc, i, j;
  string verb = query_verb();

  notify_fail("");
  if (!arg)
    return notify_fail("¿"+CAP(verb)+" qué?\n", NOTIFY_NOT_OBJ);
  if (   2 == sscanf(arg, "%s en %s", tmp, to)
      || 2 == sscanf(arg, "%s sobre %s", tmp, to)
     )
    rc = GivePut(verb, tmp, to, PUTGET_FULL);
  else
    rc = DropTake(verb, arg, PUTGET_FULL);
  if (pointerp(rc))
  for (i = j = 0; i < sizeof(rc); i++)
    j += pointerp(rc[i])?sizeof(rc[i]):0;
  return j;
}

//--------------------------------------------------------------------------
public varargs int ftake (string arg)
{
  mixed rc, i, j;

  notify_fail("");
  if (!arg)
    return notify_fail("¿Coger qué?\n", NOTIFY_NOT_OBJ);
  rc = Take(arg, PUTGET_FULL);
  if (pointerp(rc))
  for (i = j = 0; i < sizeof(rc); i++)
    j += pointerp(rc[i])?sizeof(rc[i]):0;
  return j;
}

//--------------------------------------------------------------------------
public varargs int fgive (string arg) {
  string tmp, to;
  mixed rc, i, j;

  if (!arg || 2 != sscanf(arg, "%s a %s", tmp, to)) {
    return notify_fail("¿Qué quieres dar, y a quién?\n", NOTIFY_NOT_OBJ);
  }
  arg = tmp;
  notify_fail("");

  if (!arg)
    return notify_fail("¿Dar qué a "+to+"?", NOTIFY_NOT_OBJ);
  rc = Give(arg, to, PUTGET_FULL);
  if (pointerp(rc))
  for (i = j = 0; i < sizeof(rc); i++)
    j += pointerp(rc[i])?sizeof(rc[i]):0;
  return j;
}

//--------------------------------------------------------------------------
public varargs int fput (string arg) {
  string tmp, to;
  mixed rc, i, j;

  if (!arg
   || (   2 != sscanf(arg, "%s en %s", tmp, to)
       && 2 != sscanf(arg, "%s sobre %s", tmp, to)
      )
     )
  {
    return notify_fail("¿Poner qué dónde?\n", NOTIFY_NOT_OBJ);
  }
  arg = tmp;

  notify_fail("");
  if (!arg)
    return notify_fail("¿Poner qué en "+to+"?", NOTIFY_NOT_OBJ);
  rc = Put(arg, to, PUTGET_FULL);
  if (pointerp(rc))
  for (i = j = 0; i < sizeof(rc); i++)
    j += pointerp(rc[i])?sizeof(rc[i]):0;
  return j;
}

//--------------------------------------------------------------------------
public void add_putget_cmds () {
  add_action("fdrop",   "tirar");
  add_action("fdrop",   "dejar");
  add_action("ftake",   "coger");
  add_action("fput" ,   "poner");
  add_action("fgive",   "dar");
}

/****************************************************************************/
