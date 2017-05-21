/**
 * SIMAURIA '/std/living/perception.c'
 */

#include "/secure/wizlevels.h"
#include <properties.h>
#include <perception.h>
#include <colours.h>
#include <messages.h>

/*--------------------------------------------------------------------------*/

public int QueryStatusSleeping();	    // std/living/body
public mixed Query(string name); // std/base
public int QueryLState(); // std/living/description

public varargs void catch_msg(mixed msg, object obj); //Forward
private void _execute_funcs(mapping frame, mixed msg, object obj); // forward

/*--------------------------------------------------------------------------*/

private int aIVision, aUVision;
private int aSeeInvis, aSeeHidden;

private mapping pMsgFuncs = ([]);

/*--------------------------------------------------------------------------*/


public int QueryIVision()       { return aIVision; }
public int SetIVision(int i)    { return aIVision = i; }

public int QueryUVision()       { return aUVision; }
public int SetUVision(int i)    { return aUVision = i; }

public int QuerySeeInvis()      { return aSeeInvis; }
public int SetSeeInvis(int i)   { return aSeeInvis = i>0 ? 1 : 0; }

public int SetSeeHidden(int i) { return aSeeHidden = i>0? (i>100?100:i) : 0; }
public int QuerySeeHidden() {
  if (TO->QueryInt()>aSeeHidden) return TO->QueryInt();
  else return aSeeHidden;
}

/*--------------------------------------------------------------------------*/
// Functions to test if we can see in the actual environment.
// CanSeeObject(ob) returns non-zero if we can see 'ob', else 0.
// CanSee() returns non-zero if we can see; else 0.
// CantSee() returns <0 if its too dark, >0 if its too bright and 0 if its o.k.

// CanSee devuelve 1 si veo en el environment env (o en mi environment si no le paso nada) y 0 si no veo
public varargs int CanSee(object env)
{
  if (QueryStatusSleeping() || Query(P_BLIND)) return 0;

  if (env || (env = environment()))
  {
    int l, ivision, uvision, state;
    state = QueryLState();
    if (state == LSTATE_GHOST) return 1;
    ivision = QueryIVision();
    uvision = QueryUVision();
    if (state == LSTATE_FROG)
    {
      l = uvision - ivision;
      ivision -= l/4;
      uvision += l/4;
    }
    l = to_int(env->QueryIntLight());
    return l >= ivision && l <= uvision;
  }
  return 0;
}

public varargs int CantSee(object env)
{
  if (QueryStatusSleeping() || Query(P_BLIND)) return -1; // Devuelvo too dark

  if (env || (env = environment()))
  {
    int l, ivision, uvision, state;

    state = QueryLState();
    if (state == LSTATE_GHOST) return 0;
    ivision = QueryIVision();
    uvision = QueryUVision();
    if (state == LSTATE_FROG)
    {
      l = uvision - ivision;
      ivision -= l/4;
      uvision += l/4;
    }
    l = to_int(env->QueryIntLight());
    if (l < ivision) return l-ivision;
    if (l > uvision) return l-uvision;
  }
  return 0;
}

/*
NOTA: Esta función supone q nos das un 'ob' que esta 'present' a mi y quieres
chekear si lo puedo ver.

¿Poner mixed ob y probar con un ob = present(ob)?

CanSeeObject devuelve 0 si NO ves a ob y distinto de cero si si que le ves.
Concretamente (definido en perception.h):
- Devuelve CAN_SEE_OBJECT_NO si no veo a ob (definido como 0)
- Devuelve CAN_SEE_OBJECT_VIS si ob es visible y le veo
- Devuelve CAN_SEE_OBJECT_INVIS si ob es invisible pero le veo
- Devuelve CAN_SEE_OBJECT_INWIZ si ob es inwizible pero le veo
*/
public int CanSeeObject(object ob)
{
    if ( objectp(ob) && CanSee() )
    {
        if ( ob->Query(P_INWIZ) )
        { // ob esta inwizible
            if ( IS_LEARNER(TO) && !Query(P_NOWIZ)) return CAN_SEE_OBJECT_INWIZ;
            return CAN_SEE_OBJECT_NO;
        }

        if ( ob->Query(P_INVIS) )
        { // ob esta invisible
            if (   ob == TO
                || (   Query(P_SEE_INVIS)
                    && (   Query(P_SEE_HIDDEN) >= ob->Query(P_HIDDEN)
                        || member(ob->QuerySeenBy()||({}),TO)!=-1
                       )
                   )
               )
            {
                return CAN_SEE_OBJECT_INVIS;
            }
            return CAN_SEE_OBJECT_NO;
        }
        else
        { // ob esta visible
            if (   Query(P_SEE_HIDDEN) >= ob->Query(P_HIDDEN)
                || member(ob->QuerySeenBy()||({}),TO)!=-1
               )
            {
                return CAN_SEE_OBJECT_NORMAL;
            }
            return CAN_SEE_OBJECT_NO;
        }
    }
    return CAN_SEE_OBJECT_NO;
}

//----------------------------------------------------------------------------
public varargs int CanHear(object env)
{
  if (QueryStatusSleeping() || Query(P_DEAF)) return 0;

  if (env || (env = environment()))
  { // SI no tengo env no oigo, las ondas no se mueven por el vacio ;p
    // Mirar si la habitacion esta silenciada o algo
    return 1;
  }
  return 0;
}

/*
NOTA: Esta función supone q nos das un 'ob' que esta 'present' a mi y quieres
chekear si lo puedo ver.

¿Poner mixed ob y probar con un ob = present(ob)?

CanHearObject devuelve 0 si NO oyes a ob y distinto de cero si si que le oyes.
Concretamente (definido en perception.h):
- Devuelve CAN_HEAR_OBJECT_NO si no veo a ob (definido como 0)
- Devuelve CAN_HEAR_OBJECT_NORMAL si ob es oible y le oigo
- Devuelve CAN_HEAR_OBJECT_INWIZ si ob es inwizible pero le oigo
*/
public int CanHearObject(object ob)
{
  if (objectp(ob) && CanHear())
  {
    if ( ob->Query(P_INWIZ) )
    { // ob esta inwizible
        if ( IS_LEARNER(TO) && !Query(P_NOWIZ)) return CAN_HEAR_OBJECT_INWIZ;
        return CAN_HEAR_OBJECT_NO;
    }
    return CAN_HEAR_OBJECT_NORMAL;
  }
  return CAN_HEAR_OBJECT_NO;
}

//--------------------------------------------------------------------------
private string _get_short(object ob)
{
    if (objectp(ob))
    {
        switch (CanSeeObject(ob))
        {
            case CAN_SEE_OBJECT_INWIZ : // Esta inwizible, pero le veo
                return TC_ITALIC + "<(" + ( ob->QueryName()||ob->QueryShort() )
                                 + ")>" + TC_ITALIC_OFF;
            case CAN_SEE_OBJECT_INVIS : // esta invisible, pero le veo
                return TC_ITALIC + "(" + ( ob->QueryName()||ob->QueryShort() )
                                 + ")" + TC_ITALIC_OFF;
            case CAN_SEE_OBJECT_NORMAL : // esta visible, y le veo
                return ob->QueryName() || ob->QueryShort();
        }
    }
    return "alguien";
}

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Funciones para descargar el catch_msg y para permitir ser sobrecargadas
// para aumentar la funcionalidad.

protected void _msg_see(mixed msg, object obj) {
// ({ MSG_SEE, SEE_CAN, SEE_CANT })

    if (!environment()) return;

    switch (CanSeeObject(obj))
    {
        case CAN_SEE_OBJECT_INWIZ : // obj esta inwizible, pero le veo
            if (stringp(msg[SEE_CAN]))
                catch_msg(TC_ITALIC "<(" + msg[SEE_CAN] + ")>" TC_NORMAL, obj);
            else catch_msg(msg[SEE_CAN], obj);
            break;
        case CAN_SEE_OBJECT_INVIS : // obj esta invisible, pero le veo
            if (stringp(msg[SEE_CAN]))
                catch_msg(TC_ITALIC "(" + msg[SEE_CAN] + ")" TC_NORMAL, obj);
            else catch_msg(msg[SEE_CAN]);
            break;
        case CAN_SEE_OBJECT_NORMAL : // obj esta visible, y le veo
            catch_msg(msg[SEE_CAN], obj);
            break;
        case CAN_SEE_OBJECT_NO : // no veo a obj
        default:
     // Los multiples chekeos es por que los wizs inwiz no hacen ruido
            if (   SEE_CANT < sizeof(msg) // Hay mensaje de oir
                && ( !obj || !obj->Query(P_INWIZ) || IS_LEARNER(TO) )
               )
            {
                catch_msg(msg[SEE_CANT], obj);
            }
    }
}

protected void _msg_hear(mixed msg, object obj) {
// ({ MSG_HEAR, HEAR_CAN, HEAR_CANT })

    if (!environment()) return;

    switch (CanHearObject(obj))
    {
        case CAN_HEAR_OBJECT_INWIZ : // obj esta inwizible, pero le oigo
            if (stringp(msg[HEAR_CAN]))
                catch_msg(TC_ITALIC "<(" + msg[HEAR_CAN] + ")>" TC_NORMAL, obj);
            else catch_msg(msg[HEAR_CAN], obj);
            break;
        case CAN_HEAR_OBJECT_NORMAL : // Puedo oir a obj
            catch_msg(msg[HEAR_CAN], obj);
            break;
        case CAN_HEAR_OBJECT_NO : // No oigo a obj
        default:
            if ( HEAR_CANT < sizeof(msg) ) {
                catch_msg(msg[HEAR_CANT], obj);
            }
    }
}

protected void _msg_feel(mixed msg, object obj) {
// ({ MSG_FEEL, FEEL_CAN, ¿FEEL_CANT? })
    catch_msg(msg[FEEL_CAN], obj);
}

protected void _msg_tell(mixed msg, object obj) {
// ({ MSG_TELL, TELL_CAN, ¿TELL_CANT? })
    catch_msg(msg[TELL_CAN], obj);
}

protected void _msg_combat(mixed msg, object obj) {
// ({ MSG_COMBAT,  COMBAT_TYPE,
//    COMBAT_ATK,  COMBAT_DEF,
//    COMBAT_VERB, COMBAT_WITH, COMBAT_DAM
//    COMBAT_WHAT, COMBAT_HOW })

/* NOTA: capitalizar.
verb =  verb = "ataca"      /   "lanza"    / "conjura"
with =  verb = "una espada" / "una piedra" / "'rayo'"
prep =            " a "    / " contra "   / " contra "
what =         "falla"          / "roza"
how  =         "miserablemente" / "ligeramente"
*/
    string atk = _get_short(msg[COMBAT_ATK]),
           def = _get_short(msg[COMBAT_DEF]);

    if (CanSee() && (atk != "alguien" || def != "alguien") )
    { // Veo lo q ocurre
        switch (msg[COMBAT_TYPE]) {
            case  COMBAT_TYPE_MELEE:
            case -COMBAT_TYPE_MELEE:
// COMBAT_ATK COMBAT_VERB a COMBAT_DEF [con COMBAT_WITH] < y te|, pero lo> COMBAT_WHAT [COMBAT_HOW]
                if (TO->QueryCombateBreve()) {
                  catch_msg(TC_COMBAT_OTRO
                      + capitalize( atk + " " + msg[COMBAT_VERB] + " a " + def
                      + (msg[COMBAT_TYPE] > 0 ? " y le " : ", pero lo ")
                      + msg[COMBAT_WHAT] + TC_NORMAL), obj);
                }
                else {
                  catch_msg(TC_COMBAT_OTRO
                      + capitalize( atk + " " + msg[COMBAT_VERB] + " a " + def
                      + (sizeof(msg[COMBAT_WITH])?" con "+msg[COMBAT_WITH]:"")
                      + (msg[COMBAT_TYPE] > 0 ? " y le " : ", pero lo ")
                      + msg[COMBAT_WHAT] + msg[COMBAT_HOW] + TC_NORMAL), obj);
                }
                break;
            case  COMBAT_TYPE_THROW:
            case -COMBAT_TYPE_THROW:
// COMBAT_ATK COMBAT_VERB COMBAT_WITH a/contra COMBAT_DEF < y te|, pero lo> COMBAT_WHAT [COMBAT_HOW]
                if (TO->QueryCombateBreve()) {
                  catch_msg(TC_COMBAT_OTRO
                      + capitalize( atk + " " + msg[COMBAT_VERB] + " "
                      + msg[COMBAT_WITH] + " contra " + def
                      + (msg[COMBAT_TYPE] > 0 ? " y le " : ", pero lo ")
                      + msg[COMBAT_WHAT] + TC_NORMAL), obj);
                }
                else {
                  catch_msg(TC_COMBAT_OTRO
                      + capitalize( atk + " " + msg[COMBAT_VERB] + " "
                      + msg[COMBAT_WITH] + " contra " + def
                      + (msg[COMBAT_TYPE] > 0 ? " y le " : ", pero lo ")
                      + msg[COMBAT_WHAT] + msg[COMBAT_HOW] + TC_NORMAL), obj);
                }
                break;
            case  COMBAT_TYPE_SPELL:
            case -COMBAT_TYPE_SPELL:
// COMBAT_ATK COMBAT_VERB 'COMBAT_WITH' contra COMBAT_DEF < y te|, pero lo> COMBAT_WHAT [COMBAT_HOW]
                if (TO->QueryCombateBreve()) {
                  catch_msg(TC_COMBAT_OTRO
                      + capitalize( atk + " " + msg[COMBAT_VERB]
                      + " '" + msg[COMBAT_WITH] + "' contra " + def
                      + (msg[COMBAT_TYPE] > 0 ? " y le " : ", pero lo ")
                      + msg[COMBAT_WHAT] + TC_NORMAL), obj);
                }
                else {
                  catch_msg(TC_COMBAT_OTRO
                      + capitalize( atk + " " + msg[COMBAT_VERB]
                      + " '" + msg[COMBAT_WITH] + "' contra " + def
                      + (msg[COMBAT_TYPE] > 0 ? " y le " : ", pero lo ")
                      + msg[COMBAT_WHAT] + msg[COMBAT_HOW] + TC_NORMAL), obj);
                }
                break;
        }
    }
    else if (   CanHear()
             && (   CanHearObject(msg[COMBAT_ATK])
                 || CanHearObject(msg[COMBAT_DEF])
                )
            )
    { // No veo lo que ocurre, pero oigo algo
        catch_msg(TC_KEY_COMBAT_OTRO + capitalize(
            "Escuchas el ruido de un combate justo a tu lado."
            TC_NORMAL), obj);
    }
}

/*--------------------------------------------------------------------------
** The function which are the 'eyes' of a living. Whenever the living gets
** a message string invoked by an action which depends on the current light
** level, then this function should be used.
*/
// Esto se llama siempre que un mensaje le llega a un living
// La voy a rehacer enterita.
// Totalmente prohibido hacer returns entre medias por que dejarian el
// SetByCMsg activado.

/*
msg = ({ MSG_TYPE, argumentos q dependen del tipo })

*/
// obj es el objeto causante
public varargs void catch_msg(mixed msg, object obj)
{
//    log_file("/MESSAGES",sprintf("[%O] %O llamo a %O->catch_msg(%O, %O)\n",ctime(time()),previous_object(),TO, msg, obj ));

    if (!sizeof(msg)) return; // No se, pero a veces llegan mensajes vacios.

    if (stringp(msg)) {
        TO->catch_tell(msg + " \n");
    }

    if (!obj) obj = PO; // Parche para evitar que los tell_object tengan un obj = 0.

    TO->SetByCMsg(1); // Quiero quitar esto, ya vere como

    // Llamo a las funciones 'registradas'
    if (pMsgFuncs["all"]) _execute_funcs(pMsgFuncs["all"], msg, obj);
    if (pMsgFuncs[msg[0]]) _execute_funcs(pMsgFuncs[msg[0]], msg, obj);

    switch (msg[0])
    {
        case MSG_SEE   : // ({ MSG_SEE, SEE_CAN, SEE_CANT })
            _msg_see(msg, obj);
            break;
        case MSG_HEAR  : // ({ MSG_HEAR, HEAR_CAN, HEAR_CANT })
            _msg_hear(msg, obj);
            break;
        case MSG_FEEL  : // ({ MSG_FEEL, FEEL_CAN, ¿FEEL_CANT? })
            _msg_feel(msg, obj);
            break;
        case MSG_TELL  : // ({ MSG_TELL, TELL_CAN, ¿TELL_CANT? })
            _msg_tell(msg, obj);
            break;
        case MSG_COMBAT: // ({ MSG_COMBAT,  COMBAT_TYPE,
                         //    COMBAT_ATK,  COMBAT_DEF,
                         //    COMBAT_VERB, COMBAT_WITH, COMBAT_DAM
                         //    COMBAT_WHAT, COMBAT_HOW })
            _msg_combat(msg, obj);
            break;
    }

    TO->SetByCMsg(0); // Quiero quitar esto, ya vere como

}

//------------------------------------------------------------------------------
// Si te parecen feas estas funciones, ya somos dos, pero es mucho mas rapido
// el copiar descaradamente

// Registra una función que será llamada cuando llegue un catch_msg del tipo
// indicado.
// Nota: si sizeof(type) vale cero se registra para todos
// fun es la funcion a llamar
// ob es e lobjeto donde esta la funcion, si no existe es TO
public varargs void RegisterMsgFun(string type, mixed fun, object ob) {
  mixed entry;
  string key;
  mapping m;
  int i;

  //dtell("nyh",sprintf("%O->RegisterMsgFun(%O, %O)\n", TO, type, fun));

  if (!sizeof(type)) type = "all";

  if (!ob) ob = TO;

  if (closurep(fun))
  {
    key = sprintf("%O", fun);
    key[0..1] = "/";
    entry = ({ fun });
  }
  else if (stringp(fun))
  {
    if (-1 == (i = strstr(fun, "->")))
    {
      key = to_string(ob)+"->"+fun;
      entry = ({ ob, fun });
    }
    else
    {
      key = resolve_file(fun[0..i-1], ob);
      entry = ({ key, fun[i+2..] });
      key += fun[i..];
    }
  }
  else if (pointerp(fun))
  {
    entry = fun;
    key = to_string(fun[0])+"->"+fun[1];
  }

  if (!(m = pMsgFuncs[type])) m = ([]);

  m[key] = entry;

  pMsgFuncs[type] = m;

  //dtell("nyh",sprintf("%O->pMsgFuncs[%O] = %O\n", TO, type, m));
}

private void _execute_funcs(mapping frame, mixed msg, object obj)
// Execute any registered functions in the given <frame>.
{
  string *ind;
  mixed *entry;
  int i;

  //dtell("nyh",sprintf("%O->_execute_funcs(%O, %O, %O)\n", TO, frame, msg, obj));

  if (!sizeof(frame)) return;



  ind = m_indices(frame);
  //dtell("nyh",sprintf("ind = %O\n", ind));

  for (i = sizeof(ind); i--; )
  {
    entry = frame[ind[i]];
    //dtell("nyh",sprintf("-entry[0] = %O\n",entry[0]));
    if (closurep(entry[0]))
    {
      //dtell("nyh",sprintf("+entry[1] = %O\n",entry[1]));
      funcall(entry[0], msg, obj);
    }
    else if (entry[0]) {
      //dtell("nyh",sprintf("*entry[1] = %O\n",entry[1]));
      call_other(entry[0], entry[1], msg, obj);
    }
    else { // algo raro pasa, asiq borro esta funcion
      // Si realmente los mappings se pasan por referencia
      // esto a lo bruto deberia funcionar
      m_delete(frame, ind[i]);
    }
  }
}

//------------------------------------------------------------------------------
