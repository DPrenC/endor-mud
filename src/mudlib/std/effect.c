/* SIMAURIA '/std/effect.c'
   =======================================
   [h] Nyh@Simauria

   05-04-08 [h] Creación del archivo base de la actual chapuza de los efectos.
                Sirve para poder hacer algo temporal al jugador. Básicamente tu
                lo heredas y sobrecargas las funciones de InitEffect, ExecEffect
                y EndEffect (o solo las que necesites). Tb viene bien ponerle
                nombre o algo asi, mira el codigo y/o ejemplos hechos para
                enterarte mejor.
                Cuando quieras afectar a un living con el efecto creado
                heredando esto solo tienes que clonar tu objeto y llamar a
                <efecto>->Affect(<objeto living>, asaltos)
                y ya se encarga esto de lo demas.

                Ahora también se le pueden poner chats. JAMAS enviar chats desde
                las funciones Init/Exec/End porque podria dar lugar a
                incongruencias, sobretodo con el End.

                Tener MUY en cuenta que las funciones InitEffect y EndEffect no
                solo se ejecutan al iniciar y terminar el efecto, sino tambien
                al entrar el jugador en el mud y abandonarlo.
*/

#include <properties.h>
#include <moving.h>
#include <effects.h>

inherit THING;

//------------------------------------------------------------------------------

private int pTimeLeft; // Tiempo que queda hasta el final del efecto, en asaltos
private object pAffected; // El living afectado, que deberia ser SIEMPRE ENV(TO)

// Chats a soltar al living cuando se inicia, ejecuta o termina la affección.
// Pueden ser de cualquier tipo valido para catch_msg, o closure que lo devuelva
// Si es closure como primer argumento ira pAffected y como segundo pTimeLeft
private mixed pInitChat;
private mixed pExecChat;
private mixed pEndChat;

// Chats a soltar al environment(living), menos al propio living, cuando se
// inicia, ejecuta o termina la affección.
// Pueden ser de cualquier tipo valido para catch_msg, o closure que lo devuelva
// Si es closure como primer argumento ira pAffected y como segundo pTimeLeft
private mixed pEnvInitChat;
private mixed pEnvExecChat;
private mixed pEnvEndChat;

//------------------------------------------------------------------------------
// Query / Set
//------------------------------------------------------------------------------

public int QueryTimeLeft() { return pTimeLeft; }

public object QueryAffected() { return pAffected; }

public mixed QueryInitChat   () { return pInitChat   ; }
public mixed QueryExecChat   () { return pExecChat   ; }
public mixed QueryEndChat    () { return pEndChat    ; }
public mixed QueryEnvInitChat() { return pEnvInitChat; }
public mixed QueryEnvExecChat() { return pEnvExecChat; }
public mixed QueryEnvEndChat () { return pEnvEndChat ; }

public mixed SetInitChat   (mixed m) { return pInitChat    = m; }
public mixed SetExecChat   (mixed m) { return pExecChat    = m; }
public mixed SetEndChat    (mixed m) { return pEndChat     = m; }
public mixed SetEnvInitChat(mixed m) { return pEnvInitChat = m; }
public mixed SetEnvExecChat(mixed m) { return pEnvExecChat = m; }
public mixed SetEnvEndChat (mixed m) { return pEnvEndChat  = m; }

//------------------------------------------------------------------------------
// Funciones a sobrecargar para hacer cosas.
// Cuando se llaman estas funciones QueryTimeLeft y QueryAffected estan
// disponibles para saber el tiempo que queda (en asaltos) y quien es el afectado
//------------------------------------------------------------------------------

// Devuelve 0 si no se le ha podido afectar y distinto de cero en caso de exito
public int InitEffect() {
  if (find_object("kastwey") && find_object("kastwey")->Query("DebugEffects"))
    dtell("kastwey",sprintf("[Effects] %O->InitEffect()\tpAffected = [%O]%O\tpTimeLeft = %O\n"
         , TO, pAffected->QueryGuildLevel(), pAffected->QueryName(), pTimeLeft));
  return 1;
}

// Función autoejecutada en cada heart_beat
public int ExecEffect() {
  if (find_object("kastwey") && find_object("kastwey")->Query("DebugEffects"))
    dtell("kastwey",sprintf("[Effects] %O->ExecEffect()\tpAffected = [%O]%O\tpTimeLeft = %O\n"
         , TO, pAffected->QueryGuildLevel(), pAffected->QueryName(), pTimeLeft));
  return 1;
}

// Funcion autoejecutada al terminar el efecto (para deshacer lo que hayas hecho
// en caso de que sea necesario)
public int EndEffect() {
  if (find_object("kastwey") && find_object("kastwey")->Query("DebugEffects"))
    dtell("kastwey",sprintf("[Effects] %O->EndEffect()\tpAffected = [%O]%O\tpTimeLeft = %O\n"
         , TO, pAffected->QueryGuildLevel(), pAffected->QueryName(), pTimeLeft));
  return 1;
}

//------------------------------------------------------------------------------
// Funciones llamadas internamente:
//------------------------------------------------------------------------------

// Devuelve el número de copias de este efecto que tiene pAffected
private int _query_effect_copies()
{
    object bp, to;
    if (!pAffected || !living(pAffected)) return -1;
    bp = efun::blueprint();
    to = TO;
    return sizeof(filter(all_inventory(pAffected), lambda(({SYM(ob)}), ({SF(&&), ({SF(==), bp, ({SF(efun::blueprint), SYM(ob)})}), ({SF(!=), to, SYM(ob)})}))));
}

private void _say_chat(mixed to_who, mixed to_env) {
  string str;

  if (sizeof(str = funcall(to_who, QueryAffected(), QueryTimeLeft())))
    tell_object(pAffected, str);

  if (   environment(QueryAffected())
      && sizeof(str = funcall(to_env, QueryAffected(), QueryTimeLeft())))
    tell_room(environment(QueryAffected()), str, ({ QueryAffected() }));
}

// Llamada internamente al empezar el efecto
// _init_efect devuelve 1 si todo se ha iniciado bien
private varargs int _init_effect(int flags) {
  if (move(pAffected, M_NOCHECK) != ME_OK)
  { // Fallo al mover, me destruyo. ¿hacer log?
    destruct(TO); // Sin remove, para que no haga _end_effect
    return 0;
  }
  if (InitEffect())
  {
    QueryAffected()->AddInformObj(TO); // Quiero q se me informe si muere
    set_heart_beat(1);
    if (!flags) _say_chat(QueryInitChat(), QueryEnvInitChat());
    return 1;
  }
  destruct(TO); // Ha fallado el init, me destruyo
  return 0;
}

// Llamada internamente al terminar el efecto
private varargs void _end_effect(int flags) {
  int rc;
  if (!flags) pTimeLeft = 0;
  if (!EndEffect()) {
    raise_error(sprintf("Error al finalizar el efecto %O en %O", TO, pAffected));
  }
  if (!flags && _query_effect_copies() <= 0) _say_chat(QueryEndChat(), QueryEnvEndChat());
  destruct(TO); // Sin remove, para que no vuelva ha hacer _end_effect
}

// Llamada internamente cada heart_beat que dura el efecto
private void _exec_effect() {
  if (!pTimeLeft) {
    _end_effect();
    return;
  }

  if (pTimeLeft > 0) pTimeLeft--;

  if (ExecEffect())
  {
    _say_chat(QueryExecChat(), QueryEnvExecChat());
    return;
  }

  _end_effect();
}

//------------------------------------------------------------------------------
// Funcion a llamar para iniciar todo esto:
//------------------------------------------------------------------------------

// Si, nomask, que nos conocemos y seguro q alguien intenta molestar.
// Devuelve 0 en caso de fallo y distinto de cero en caso contrario
// Si se le pasa un tiempo negativo se considera que el efecto no termina por
// si solo nunca.
public nomask int Affect(object liv, int asaltos) {
  if (!objectp(liv)) return 0;
  else pAffected = liv;
  if (!asaltos) return 0;
  else pTimeLeft = asaltos;
  if (!_init_effect()) return 0;
  return 1;
}

//------------------------------------------------------------------------------

public mixed SetAutoObject(mixed args) {
  restore_object(args);
  pAffected = TP; // Al cargar el inventario TP es el dueño
  _init_effect(1); // Que rearranque
  return pTimeLeft;
}

public mixed QueryAutoObject() {
  return save_object();
}

//------------------------------------------------------------------------------

public int remove() {
  if (QueryAffected()) _end_effect(1);
  if (TO) destruct(TO);
  return TO && 1;
}

//------------------------------------------------------------------------------
// Función llamada cuando PO muere, quitar los efectos y autodestruirme
inform_death() {
  remove();
}

//------------------------------------------------------------------------------

heart_beat() {
  _exec_effect();
}

create_clone()
{
  ::create_clone();
  AddId(EFFECTS_ID);
  SetShort(0);
  SetLong(0);
  SetWeight(0);
  Set(P_NODROP, 1);
  Set(P_NOGET,  1);
  Set(P_NOGIVE, 1);
}

//------------------------------------------------------------------------------
