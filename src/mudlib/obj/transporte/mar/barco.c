/* SIMAURIA '/obj/transporte/mar/barco.c'
   ======================================
   [w] Woo@simauria

   29-12-97 [w] Traduccido y adaptado para Simauria.
   24-08-98 [w] Solucionado un pequenyo bug que habia en la linea 538.
   24-08-98 [w] Modificada la funcion FromHarbour() para que jamas
                el puerto de destino sea igual al de salida, cosa que
                ocurria antes en el codigo original.
   26-08-98 [w] Anyadida la funcion QueryShipPermission(), con la cual
                se podra prohibir la subida de un pasajero al barco.
   26-08-98 [w] Anyadido todo el sistema monetario. A partir de ahora los
                barcos 'pueden' costar dinero mediante las funciones
                SetShipCost(int) y QueryShipCost(). Anyadidas tambien las
                funciones SetMsgCost(string) y QueryMsgCost() que contienen
                el mensaje en caso de que no dispongas de dinero para pagar.
   29-03-99 [w] Castellanizado.
*/

#include <config.h>
#include <moving.h>
#include <search.h>
#include <stdrooms.h>
#include <properties.h>
#include <sounds.h>

#define PORT_FILE 0
#define PORT_NAME 1
#define PORT_ENTRIES 2
#define SCENE_TEXT 0
#define SCENE_DELAY 1
#define SCENE_ENTRIES 2

#define WAIT_TIME (60/4)/2 // Espera 15 segundos (/2 a causa del heart_beat)

inherit NMB;

private static object Pship; // Almacena el objeto del barco.
private static string *Pdecks,
// La primera habitacion es la habitacion a la cual el jugador llegara
// una vez ha entrado en el barco, puedes dejar la habitacion a cualquiera
// de las que esten a su lado y los mensajes se veran en todas las
// habitaciones del barco.
                      *Prooms;
// El barco debe conocer todas las habitaciones pertenecientes a este
// para saber cuando el barco puede ser 'limpiado' entre otras razones.

private static mixed Penter_msgs,Pleave_msgs,
// Mensaje del jugador al subir y abandonar el barco
                     Pship_enter_msgs,Pship_leave_msgs,
// Mensaje del barco al entrar y salir del puerto
                     Pmove_msgs;
// Mensajes aleatorios del barco en movimiento
// Pmove_msgs: ({({<msg1>,<msg2>}),({<probabilidad1>,<probabilidad2>})})

private static mapping Pmove_scenes,
// Escenas que se escriben en un determinado orden. Cuando se hayan
// terminado querra decir que el viaje ha terminado.
// Pmove_scenes:
//   (["desdepuerto":(["haciapuerto":([<nr>:<escena>;<retardo>])])])
                       Pports;
// Los puertos donde hace escala el barco (por orden)
// Pports:
//   ([<nr>:<fichero>;<nombre>])

private static int Pto_port,
// Almacena el indice del puerto a donde se dirige o acaba de llegar
                   Pfrom_port,
// Almacena el indice del puerto del cual proviene
                   Phbcount;
// Variable que cuenta los heart_beats hasta que el barco abandona el puerto

private int coste;
// Almacena el coste del viaje en caso de hacer uso de SetShipCost(int)
private string MsgCoste;
// Contiene el mensaje en caso de no disponer de suficiente dinero para pagar.
private string pLeaveSound;
// el sonido
public object RegisterMe()
{
  if (PO!=TO
      &&blueprint(PO)==object_name())
    Pship = PO;
  return Pship;
}

public object QueryShip()
{
  return Pship;
}

protected object valid_port(string port)
{
  object res;
  string error;
  seteuid(getuid());
  if (file_size(port+".c")<0)
    {
      MASTER->runtime_error("¡Ese puerto no existe!\n",
                            object_name(),port,-1);
      return 0;
    }
  if (error = catch(res = load_object(port)))
    {
      MASTER->runtime_error("Error puerto: "+error,
                            port,object_name(),-1);
      return 0;
    }
  if (member(res->QueryShips()||({}),blueprint())==-1)
    {
      MASTER->runtime_error("Este puerto no admite barcos.\n",
                            port,object_name(),-1);
      return 0;
    }
  seteuid(0);
  return res;
}

public mapping SetPorts(mapping p) { return Pports = p; }
public mapping QueryPorts() { return Pports||([]); }
public mapping AddPort(string portname,string portfile)
// Los puertos se introducen en el mismo orden del 'create'.
{
  int i;
  portfile = resolve_file(portfile);
  if (!valid_port(portfile))
    return Pports||([]);
  if (!Pports)
    Pports = m_allocate(0,PORT_ENTRIES);
  i = sizeof(Pports);
  Pports[i,PORT_FILE] = portfile;
  Pports[i,PORT_NAME] = portname;
  return Pports;
}

public string QueryFromPort()
// Devuelve el nombre del fichero del que proviene el barco
{
  return QueryPorts()[Pfrom_port,PORT_FILE];
}

public string QueryToPort()
// Devuelve el nombre del fichero del puerto al que se dirige o acaba de llegar
{
  return QueryPorts()[Pto_port,PORT_FILE];
}
public string Harbour()
// Devuelve el nombre del puerto al que se dirige o acaba de llegar el barco
{
  return QueryPorts()[Pto_port,PORT_NAME];
}
public string FromHarbour()
// Devuelve el nombre del puerto del cual proviene el barco
{
// [w] Anyadida esta comprobacion
  if(Pfrom_port==Pto_port)
   if(Pfrom_port==0) Pfrom_port=sizeof(Pports)-1;
   else Pfrom_port=Pfrom_port-1;
  return QueryPorts()[Pfrom_port,PORT_NAME];
}

public mixed SetShipEnterMsgs(mixed msg)
// ({<msg_ship>,<msg_harbour>})
// o closure: Que devuelve string, en caso contrario no habrian mensajes extra
// @@Harbour@@ en el string sera reemplazado por el nombre del puerto
{
  if (msg)
    if (stringp(msg))
      msg = ({msg,capitalize(TO->QueryShort())+" atraca en el muelle.\n"});
    else if (   pointerp(msg)
             && sizeof(msg)<2)
      msg+=({"El Capitan grita: ¡Hemos llegado a @@Harbour@@!\n",
             capitalize(TO->QueryShort())+" atraca en el muelle.\n"})
           [sizeof(msg)..];
  return Pship_enter_msgs = msg;
}

public mixed QueryShipEnterMsgs()
{
  return Pship_enter_msgs||
    ({"El Capitan grita: ¡Hemos llegado a @@Harbour@@!\n",
      capitalize(TO->QueryShort())+" atraca en el muelle.\n"});
}

public mixed SetShipLeaveMsgs(mixed msg)
// ({<msg_ship>,<msg_harbour>})
// o closure: Si devuelve un array, sino no habra ningun mensaje extra
{
  if (msg)
    if (stringp(msg))
      msg = ({msg,capitalize(TO->QueryShort())+" abandona el muelle.\n"});
    else if (   pointerp(msg)
             && sizeof(msg)<2)
      msg+=({"El Capitan grita: ¡Acabamos de dejar @@FromHarbour@@ y nos dirigimos\n"
             "rumbo a @@Harbour@@!\n",
             capitalize(TO->QueryShort())+" abandona el muelle.\n"})
           [sizeof(msg)..];
  return Pship_leave_msgs = msg;
}

public mixed QueryShipLeaveMsgs()
{
  return Pship_leave_msgs||
    ({"El Capitan grita: ¡Acabamos de dejar @@FromHarbour@@ y nos dirigimos\n"
      "rumbo a @@Harbour@@!\n",
      capitalize(TO->QueryShort())+" abandona el muelle.\n"});

}

public string *SetRooms(string *f) { return Prooms = f; }
public string *QueryRooms() { return (Prooms||({}))+({}); }
public string *AddRoom(string file)
// Para la 'limpieza' y el manejo de heart_beats el barco necesita saber
// que habitaciones forman parte de el.
{
  file = resolve_file(file);
  return Prooms = (Prooms||({}))-({file})+({file});
}

public object *QueryPassengers()
// Devuelve los pasajeros del barco.
{
  string *rooms;
  int i;
  object *res,room;
  i = sizeof(rooms = QueryRooms());
  res = ({});
  while(i--)
    if (room = find_object(rooms[i]))
      res+=filter(deep_inventory(room),SF(query_once_interactive));
  return res;
}

public object *QueryCustomers()
// Devuelve los posibles pasajeros que esperan en el puerto.
{
  string *ports;
  int i;
  object *res,port;
  i = sizeof(ports = m_values(QueryPorts()));
  res = ({});
  while(i--)
    if (port = find_object(ports[i]))
      res+=filter(deep_inventory(port),SF(query_once_interactive));
  return res;
}

protected int calc_next_port()
{
  object *cust;
  string *ports_to_support;
  mapping ports;
  int res,i,max_port;
  ports = QueryPorts();
  max_port = max(m_indices(ports));
  if (   !sizeof(QueryPassengers())
      && sizeof(cust = QueryCustomers())
     )
    {
      ports_to_support = map(map(cust,SF(environment)),
                                   SF(object_name));
      for(i=0;i<max_port+1;i++)
        if (member(ports_to_support,ports[i])!=-1&&i!=Pto_port)
          return i;
      return Pto_port;
    }
  res = Pto_port+1;
  if (res>max_port)
    res = 0;
  return res;
}

protected int can_sleep()
{
  if (   !environment()
      || object_name(environment())==OCEAN
      || sizeof(QueryPassengers())
      || sizeof(QueryCustomers())
     )
    return 0;
  return 1;
}

protected int can_clean_up()
{
  if (!clonep())
    return Pship!=0;
  return !can_sleep();
}

public string *SetDecks(string *f) { return Pdecks = f; }
public string *QueryDecks() { return (Pdecks||({}))+({}); }
public string *AddDeck(string file)
// Anyade las habitaciones donde deberian salir los mensajes referentes a
// movimientos, llegadas, etc.. y donde el jugador puede abandonar el barco.
// La primera habitacion definida es donde el jugador entrara al barco.
{
  file = resolve_file(file);
  AddRoom(file);
  return Pdecks = (Pdecks||({}))-({file})+({file});
}

public varargs void DeckDisplay(string msg,int shore)
// Escribe un mensaje en todas las habitaciones del barco.
// <shore> se usa para anunciar la entrada y salida del barco.
// Si <shore> es 1 todas las habitaciones tienen la propiedad P_HARBOUR
// establecida a 0 sino si <shore> es -1 la propiedad P_HARBOUR sera
// el nombre del barco donde se encuentra.
{
  int i;
  string *decks;
  decks = QueryDecks();
  i = sizeof(decks);
  seteuid(getuid());
  while(i--)
    {
      if (shore)
        decks[i]->Set(P_HARBOUR,shore<0?Harbour():0);
      tell_room(decks[i],msg);
    }
  seteuid(0);
}

public void AnnounceEnter()
// Dice en el puerto y en las habitaciones del barco que el barco ha llegado.
{
  mixed msg;
  msg = QueryShipEnterMsgs();
  if (closurep(msg))
    if (!pointerp(msg = funcall(msg,QueryToPort())))
      return DeckDisplay("",-1);
  DeckDisplay(process_string(msg[0]),-1);
  DeckDisplay("Puedes abandonar "+(TO->Query(P_NAME)||
                                strip_article(TO->QueryShort()))+" ahora.\n");
  tell_room(environment(),process_string(msg[1]));
}

public void AnnounceLeave()
// Dice en el puerto y en las habitaciones del barco que el barco se va.
{
  mixed msg;
  msg = QueryShipLeaveMsgs();
  if (pLeaveSound)
  {
      play_sound(({ environment()}) + filter(map(QueryDecks() || ({}), (:find_object($1):)), (:$1:)), pLeaveSound);
  }

  if (closurep(msg))
    
      if (!pointerp(msg = funcall(msg,QueryToPort())))
      return DeckDisplay("",1);
  DeckDisplay(process_string(msg[0]),1);
  tell_room(environment(),process_string(msg[1]));
}

public mapping SetMoveScenes(mapping sc) { return Pmove_scenes = sc; }
public mapping QueryMoveScenes() { return Pmove_scenes||([]); }
public mapping AddMoveScene(string from,string to,mixed scene,int delay)
// from: Fichero de la posicion que el barco acaba de abandonar
// to: Fichero al sitio donde el barco se dirige
// scene: string: String que se escribira en todas las habitaciones del barco
//        closure: Sera llamada, si devuelve string se escribira sino se ignora
// delay: Tiempo antes de llamar a la siguiente escena
// El barco llegara al siguiente puerto cuando todas las escenas hayan pasado
{
  int i;
  if (!Pmove_scenes)
    Pmove_scenes = ([]);
  if (!member(Pmove_scenes,from))
    Pmove_scenes[from] = ([]);
  if (!member(Pmove_scenes[from],to))
    Pmove_scenes[from][to] = m_allocate(0,SCENE_ENTRIES);
  i = sizeof(Pmove_scenes[from][to]);
  Pmove_scenes[from][to][i,SCENE_TEXT] = scene;
  Pmove_scenes[from][to][i,SCENE_DELAY] = delay;
  return Pmove_scenes;
}

public mixed SetMoveMsgs(mixed mm) { return Pmove_msgs = mm; }
public mixed QueryMoveMsgs() { return Pmove_msgs||({({}),({})}); }
public mixed AddMoveMsg(mixed msg,int probability)
{
  if (!Pmove_msgs)
    {
      Pmove_msgs = allocate(2);
      Pmove_msgs[0] = ({});
      Pmove_msgs[1] = ({});
    }
  Pmove_msgs[0]+=({msg});
  Pmove_msgs[1]+=({probability});
  return Pmove_msgs;
}

protected void PrintMoveMsg()
// Si esta definida visualiza un mensaje de movimiento aleatorio
{
  int maxp,actmsg;
  int i;
  mixed msgs;

  while(remove_call_out(SF(PrintMoveMsg)) != -1);
  if (!Pmove_msgs) return;
  maxp = sum(Pmove_msgs[1]);
  actmsg = random(maxp+1);
  for (i=0;i<sizeof(Pmove_msgs[1]);i++)
    if (actmsg<sum(Pmove_msgs[1][0..i]))
      break;
  if (i>=sizeof(Pmove_msgs[1])) i = sizeof(Pmove_msgs[1])-1;
  msgs = Pmove_msgs[0][i];
  if (closurep(msgs))
    if (!stringp(msgs =
         funcall(msgs,QueryFromPort(),QueryToPort(),QueryDecks())))
      return;
  DeckDisplay(msgs);
  call_out(SF(PrintMoveMsg),2+random(10));
}

public void StartJourney()
{
  set_heart_beat(0);
  // El heart_beat solo se necesita cuando se espera en el puerto
  AnnounceLeave();
  seteuid(getuid());
  TO->move(OCEAN,M_SILENT);
  seteuid(0);
  // Fichero temporal donde esperar
  call_out(SF(PrintMoveMsg),2+random(10));
}

public void EndJourney()
{
  seteuid(getuid());
  TO->move(QueryToPort(),M_SILENT);
  seteuid(0);
  AnnounceEnter();
  set_heart_beat(1);
  // Espera en el puerto
  while(remove_call_out(SF(PrintMoveMsg)) != -1);
}

protected void PrintScene(int scene)
// Si no hay mas escenas finaliza el movimiento sino visualiza la siguiente
// escena y comienza el call_out para la otra
{
  mixed text;
  string from,to;
  int delay;
  while(remove_call_out(SF(PrintScene)) != -1);
  if (!Pmove_scenes
      ||!sizeof(QueryPassengers())
      ||!member(Pmove_scenes,from = QueryFromPort())
      ||!member(Pmove_scenes[from],to = QueryToPort())
      ||!member(Pmove_scenes[from][to],scene))
    return EndJourney();

  text = Pmove_scenes[from][to][scene,SCENE_TEXT];
  delay = Pmove_scenes[from][to][scene,SCENE_DELAY];
  if (closurep(text))
    text = funcall(text,from,to,QueryDecks());
  if (stringp(text))
    DeckDisplay(text);
  call_out(SF(PrintScene),delay,scene+1);
}

public void NextPort()
// Llamada por heart_beat cuando se encuentra en el puerto
{
  string where;
  string *ports;
  int pos;
  if (!sizeof(ports = m_values(QueryPorts()))) return;
  if (  !environment()
      ||(pos = member(ports,where = object_name(environment())))==-1)
    {
      pos = 0;
      if (!Pto_port = calc_next_port())
        Pfrom_port = max(m_indices(QueryPorts()));
      return EndJourney();
    }
  Pfrom_port = pos;
  if ((pos = calc_next_port())==Pto_port)
  // Si el destino siguiente es el mismo donde estamos permanece parado
    return;
  Pto_port = pos;
  StartJourney();
  call_out(SF(PrintScene),5,0);
}

public void heart_beat()
{
  if (can_sleep())
    {
      set_heart_beat(0);
      return;
    }
  if (   !environment()
      && !Phbcount)
    Phbcount = WAIT_TIME-random(5);
  // No deja que todos los barcos lleguen a la vez al mismo puerto
  Phbcount++;
  if (Phbcount > WAIT_TIME)
    {
      Phbcount = 0;
      NextPort();
    }
}

public void CallShip()
{
  object ob;
  if (clonep()&&object_name(PO)==blueprint())
    {
      if (   !environment()
          || object_name(environment())!=OCEAN
         )
        set_heart_beat(1);
      return;
    }
  if (!ob = QueryShip())
    {
      seteuid(getuid());
      ob = clone_object(object_name());
      seteuid(0);
    }
  ob->CallShip();
}

public mixed SetEnterMsgs(mixed msg)
// ({<port>,<ship>,<player>}) (string o closure)
// o closure: Si devuelve un array como el anterior sino no hay mensajes extra
{
  return Penter_msgs = msg;
}

public mixed QueryEnterMsgs()
{
  return copy(Penter_msgs||
    ({"sube "+TO->QueryShort(),
      "sube al barco",
      "subes "+TO->QueryShort()}));
}

public mixed SetLeaveMsgs(mixed msg)
// ({<ship>,<port>,<player>}) (string o closure)
// o closure: Si devuelve un array como el anterior sino no hay mensajes extra
{
  return Pleave_msgs = msg;
}

public mixed QueryLeaveMsgs()
{
   return copy(Pleave_msgs||
      ({"abandona el barco",
        "abandona "+TO->QueryShort(),
        "abandonas "+TO->QueryShort()}));
}

public int cmd_leave(string str)
{
  if (   str
      && member(({"barco","bote"}),lower_case(str))==-1
      && locate(environment(),str,SM_OBJECT|SM_IGNLIGHT)!=TO
     )
    return notify_fail("No puedes abandonar "+str+".\n",NOTIFY_NOT_OBJ),0;
  if (object_name(environment(TO))==OCEAN)
    return notify_fail("Lo siento, estamos en alta mar.\n",
                       NOTIFY_NOT_VALID),0;
  if (!TP)
    return 0;
  TP->move(environment(),M_SPECIAL,funcall(QueryLeaveMsgs()));
  return 1;
}

public string QueryShipPermission()
// [w] Inicialmente se permite la subida al barco a cualquier jugador.
{
 return "";
}

public int SetShipCost(int cost)
// [w] Por defecto el viaje es gratuito
{
 return coste = cost || 0;
}

public int QueryShipCost()
{
 return coste || 0;
}

public string SetMsgCost(string str)
{
 return MsgCoste = str || "Lo siento, no tienes suficiente dinero para pagar.\n";
}

public string QueryMsgCost()
{
 return MsgCoste || "Lo siento, no tienes suficiente dinero para pagar.\n";
}

public string SetLeaveSound(string s) { return pLeaveSound = s; }
public string QueryLeaveSound() { return pLeaveSound; }
public void InitDecks()
{
  string *decks;
  int i;
  i = sizeof(decks = QueryDecks());
  seteuid(getuid());
  while(i--)
    {
      decks[i]->SetCleanUp(0);
      decks[i]->AddExit("bajar",SF(cmd_leave));
    }
  seteuid(0);
}

public int cmd_enter(string str)
{
  int precio,dinero_jugador;
  mixed dinero;

  if (!TP)
    return 0;
  if (!str)
   return notify_fail("A que barco quieres subir?.\n"),0;
  if (   str
      && member(({"barco","bote"}),lower_case(str))==-1
      && search(TP,str,SM_OBJECT|SM_IGNLIGHT|SEARCH_ENV)!=TO
     )
    return notify_fail("No puedes subir en "+str+".\n",NOTIFY_NOT_OBJ),0;
  if (!sizeof(QueryDecks()))
    return notify_fail(
      capitalize(TO->QueryShort())+" no ha sido construido para llevar pasajeros.\n",
      NOTIFY_NOT_VALID),0;
  InitDecks();
// [w] Comprueba si puede subir y controla el coste del viaje.
  if (QueryShipPermission()!="")
   return notify_fail(QueryShipPermission()+"\n"),0;
  if (QueryShipCost()!=0)
  {
   precio=QueryShipCost();
   dinero_jugador="/lib/money"->QuerySomeonesValue(TP);
   if(dinero_jugador < precio)
   {
    return notify_fail(QueryMsgCost()),0;
   }
   dinero="/lib/money"->PayValue2(TP,precio);
   if (intp(dinero))
     write("Pagas " + dinero + "\n");
   else
     write("Pagas "+dinero[0]+
         (dinero[1] ? " y recibes "+dinero[1] : "")+".\n");
  }
// ------------
  TP->move(QueryDecks()[0],M_SPECIAL,funcall(QueryEnterMsgs()));
  return 1;
}

public int remove()
{
  mixed obs;
  int i;
  if (!clonep()&&Pship)
    {
      write("¡Atención no debes destruir este blueprint!\n"
            "Para salvar los pasajeros destruye este barco.\n");
      return 0;
    }
  i = sizeof(obs = QueryPassengers());
  // SALVA LOS PASAJEROS
  while(i--)
    obs[i]->move(VOID,M_SPECIAL,
      ({"se salvó de un barco que fué destruido",
        "llega de un barco que se estaba hundiendo",
        "escapó de un barco que se estaba hundiendo"}));
  // El barco se hunde
  i = sizeof(obs = QueryRooms());
  while(i--)
     if (find_object(obs[i]))
       obs[i]->remove();
  destruct(TO);
  return 1;
}
create()
{
    SetLeaveSound(SND_SUCESOS("boat_horn"));
}
