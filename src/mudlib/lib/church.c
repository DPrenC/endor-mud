/* Este fichero sera heredado por todas las iglesias de Simauria.
  * NO es necesario que permita el rezo para resucitar o ser resucitado
  * no tienes que usar las funciones, puedes hacerlo si quieres
  * o si lo necesitas.
  * Las habitaciones deben de tener en todos los casos el SetChurch() y
 * un ForbidEnter()
 *
 * [c] creado el 13may1995
 *
 * [c] Cadra@Nightfall
 */

#include <moving.h>
#include <config.h>
#include <properties.h>
#include <search.h>
#include <messages.h>

private static string deity;
private mixed appearmsg;
private static int align, church, sunglasses, torch;
private static mapping forbid;

public int SetChurch(int i) { return church=i; }
public int SetTorch(int i) { return torch = i; }
public int SetGlasses(int i) { return sunglasses = i; }
public int SetAlign(int alignment) { return align = alignment; }
public mixed SetPrayMsg(mixed message) { return appearmsg=message; }
public string SetDeity(string str) { return deity = str; }

public int QueryChurch() { return church; }
public int QueryTorch() { return torch; }
public int QueryGlasses() { return sunglasses; }
public int QueryAlign() { return align; }
public string QueryDeity() { return deity; }

public varargs void ForbidEnter(mixed whom, string reason) {
  int i;
  if (!reason) reason = "No te esta permitido entrar en ese lugar.\n";
  if (!forbid) forbid = m_allocate(0,1);
  i = sizeof(whom-({0}));
  while (i--) forbid[lower_case(whom[i])] = reason;
}

public int allow_enter(int method, mixed extra) {
  object po;
  string race,guild,*idx,*id;
  po=PO;
  race = lower_case(po->QueryRace() || "");
  guild = lower_case(po->QueryGuild() || "");
  idx = m_indices(forbid||([]));
  if (sizeof(id = regexp(idx,"^"+race+"|^"+guild+
    "|^race:"+race+"|^guild:"+guild)))
    return  notify_fail(
      forbid[id[0]],NOTIFY_NOT_VALID)&&ME_NO_MOVE;
  return ME_OK;
}

public int resurrect_me() {
  mixed msg;
  if (!TP) return 0;

  if (closurep(appearmsg)) msg = funcall(appearmsg);
    else msg = appearmsg;
   if (stringp(msg)) msg = ({msg,"se reencarna en forma solida.\n"});
  if (TP->QueryGhost()) {
    if (!pointerp(msg)) {
      write("Has sido succionado por una fuerza misteriosa.\n");
       tell_room(environment(TP), ({ MSG_SEE, capitalize(TP->QueryName())+" se reencarna en forma solida.\n"}), ({ TP }));
      }
     else {
       write("Te "+msg[0]);
       tell_room(environment(TP), ({ MSG_SEE, capitalize(TP->QueryName())+msg[1]}), ({ TP }));
       }
    TP->SetGhost(0);
    return 1;
    }
  write("Te arrodilas y suplicas resucitar a los dioses locales.\n");
  tell_room(environment(TP), ({ MSG_SEE, capitalize(TP->QueryName())+
    " se arrodila y suplica resucitar a los dioses locales.\n"}), ({ TP }));
  return 1;
}

public int do_get(string str) {
  object obj;
  if (!TP || (!str)) return 0;
  if (!sunglasses) return  notify_fail(
    "No ves ningunas gafas ahumadas aqui.\n") && 0;
    write("Coges unas gafas ahumadas.\n");
    obj=clone_object("/obj/sunglasses");
    obj->Set(P_NOBUY,1);
    if (obj->move(TP,M_GET)!=ME_OK) {
      write("Son demasiado pesadas para ti, y las dejas caer.\n");
      tell_room(environment(TP), ({ MSG_SEE, capitalize(TP->QueryName())+
        " intenta coger unas gafas ahumadas, pero de repente las deja caer.\n"}), ({ TP }));
      }
    return 1;
  if (str=="antorcha") {
    if (!torch) return  notify_fail(
      "No ves ninguna antorcha por aqui.\n") && 0;
     if (!search(TP,"antorcha",SEARCH_INV_ENV|SM_OBJECT|SM_IGNLIGHT)) {
       write("Coges una antorcha.\n");
      obj=clone_object("/obj/torch");
      obj->Set(P_NOBUY,1);
      if (obj->move(TP,M_GET)!=ME_OK) {
        write("La antorcha es demasiado pesada para ti, y la dejas caer.\n");
        tell_room(environment(TP), ({ MSG_SEE, capitalize(TP->QueryName())+
          " intenta coger una antorcha, pero la deja caer.\n"}), ({ TP }));
        }
      return 1;
      }
    }
  return 0;
}
