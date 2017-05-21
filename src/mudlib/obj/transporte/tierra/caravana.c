/* SIMAURIA '/obj/transporte/tierra/caravana.c'
   ============================================
   [w] Woo@simauria
   [m] Maler@simauria
   20-11-98 [w] Creacion de este archivo basandome en los barcos que estaban
                ya creados.. la habitacion donde esta la caravana la he
                llamado desierto, como la podia haber llamado 'un_lugar',
                total, nunca influye, el jugador nunca la ve.. y solo sirve
                para llevar a la caravana a un sitio mientras los pobres
                jugadores parece que estan viajando :)
   29-03-99 [w] Castellanizado.
   15-10-00 [t] Arreglado un fallo... El PayValue2 NO siempre devuelve un mapping....
   algun dia[m] Cambio a saco, meto el moviminento en el heart_beat.
*/

#include <config.h>
#include <moving.h>
#include <search.h>
#include <stdrooms.h>
#include <properties.h>


#define PARADA_FICHERO 0
#define PARADA_NOMBRE 1
#define PARADA_ENTRADAS 2
#define ESCENA_TEXTO 0
#define ESCENA_ESPERA 1
#define ESCENA_ENTRADAS 2

#define TIEMPO_ESPERA (60/4)/2 // Espera 15 segundos (/2 a causa del heart_beat)

inherit NMB;

private static object Pcaravana; // Almacena el objeto del barco.
private static string *Pdecks,
// La primera habitacion es la habitacion a la cual el jugador llegara
// una vez ha entrado en la caravana, puedes dejar la habitacion a cualquiera
// de las que esten a su lado y los mensajes se veran en todas las
// habitaciones de la caravana.
                      *Prooms;
// La caravana debe conocer todas las habitaciones pertenecientes a esta
// para saber cuando la caravana puede ser 'limpiada' entre otras razones.

private static mixed Penter_msgs,Pleave_msgs,
// Mensaje del jugador al subir y abandonar la caravana
                     Pcaravana_msgs_enter,Pcaravana_msgs_leave,
// Mensaje de la caravana al entrar y salir de la parada
                     Pmove_msgs;
// Mensajes aleatorios de la caravana en movimiento
// Pmove_msgs: ({({<msg1>,<msg2>}),({<probabilidad1>,<probabilidad2>})})

private static mapping Pmove_scenes,
// Escenas que se escriben en un determinado orden. Cuando se hayan
// terminado querra decir que el viaje ha terminado.
// Pmove_scenes:
//   (["desdeparada":(["haciaparada":([<nr>:<escena>;<retardo>])])])
                       Pparadas;
// Las paradas donde hace escala la caravana (por orden)
// Pparadas:
//   ([<nr>:<fichero>;<nombre>])

private static int Pto_parada,
// Almacena el indice de la parada a donde se dirige o acaba de llegar
                   Pfrom_parada,
// Almacena el indice de la parada del cual proviene
		   Pmoving,
		   contador,
		   scene,
// Chequeo para el hb, si se esta moviendo uno, si no se esta moviendo, 0

                   Phbcount;
// Variable que cuenta los heart_beats hasta que la caravana abandona la parada

private int coste;
// Almacena el coste del viaje en caso de hacer uso de SetCaravanaCost(int)
private string MsgCoste;
// Contiene el mensaje en caso de no disponer de suficiente dinero para pagar.

public object RegisterMe()
{
  if (PO!=TO
      &&blueprint(PO)==object_name())
    Pcaravana = PO;
  return Pcaravana;
}

public object QueryCaravana()
{
  return Pcaravana;
}

protected object valid_parada(string parada)
{
  object res;
  string error;
  seteuid(getuid());
  if (file_size(parada+".c")<0)
    {
      MASTER->runtime_error("¡Esa parada no existe!\n",
                            object_name(),parada,-1);
      return 0;
    }
  if (error = catch(res = load_object(parada)))
    {
      MASTER->runtime_error("Error parada: "+error,
                            parada,object_name(),-1);
      return 0;
    }
  if (member(res->QueryCaravanas()||({}),blueprint())==-1)
    {
      MASTER->runtime_error("Esta parada no admite caravanas.\n",
                            parada,object_name(),-1);
      return 0;
    }
  seteuid(0);
  return res;
}

public mapping SetParadas(mapping p) { return Pparadas = p; }
public mapping QueryParadas() { return Pparadas||([]); }
public mapping AddParada(string paradaname,string paradafile)
// Las paradas se introducen en el mismo orden del 'create'.
{
  int i;
  paradafile = resolve_file(paradafile);
  if (!valid_parada(paradafile))
    return Pparadas||([]);
  if (!Pparadas)
    Pparadas = m_allocate(0,PARADA_ENTRADAS);
  i = sizeof(Pparadas);
  Pparadas[i,PARADA_FICHERO] = paradafile;
  Pparadas[i,PARADA_NOMBRE] = paradaname;
  return Pparadas;
}

public string QueryFromParada()
// Devuelve el nombre del fichero del que proviene la caravana
{
  return QueryParadas()[Pfrom_parada,PARADA_FICHERO];
}

public string QueryToParada()
// Devuelve el nombre del fichero de la parada a la que se dirige o acaba de llegar
{
  return QueryParadas()[Pto_parada,PARADA_FICHERO];
}
public string Parada()
// Devuelve el nombre de la parada a la que se dirige o acaba de llegar la caravana
{
  return QueryParadas()[Pto_parada,PARADA_NOMBRE];
}
public string FromParada()
// Devuelve el nombre de la parada de la cual proviene la caravana
{
// [w] Anyadida esta comprobacion
  if(Pfrom_parada==Pto_parada)
   if(Pfrom_parada==0) Pfrom_parada=sizeof(Pparadas)-1;
   else Pfrom_parada=Pfrom_parada-1;
  return QueryParadas()[Pfrom_parada,PARADA_NOMBRE];
}

public mixed SetCaravanaEnterMsgs(mixed msg)
// ({<msg_caravana>,<msg_harbour>})
// o closure: Que devuelve string, en caso contrario no habrian mensajes extra
// @@Parada@@ en el string sera reemplazado por el nombre de la parada
{
  if (msg)
    if (stringp(msg))
      msg = ({msg,capitalize(TO->QueryShort())+" llega a la parada.\n"});
    else if (   pointerp(msg)
             && sizeof(msg)<2)
      msg+=({"El jefe de la caravana grita: Hemos llegado a @@Parada@@!\n",
             capitalize(TO->QueryShort())+" llega a la parada.\n"})
           [sizeof(msg)..];
  return Pcaravana_msgs_enter = msg;
}

public mixed QueryCaravanaEnterMsgs()
{
  return Pcaravana_msgs_enter||
    ({"El jefe de la caravana grita: ¡Hemos llegado a @@Parada@@!\n",
      capitalize(TO->QueryShort())+" llega a la parada.\n"});
}

public mixed SetCaravanaLeaveMsgs(mixed msg)
// ({<msg_caravana>,<msg_harbour>})
// o closure: Si devuelve un array, sino no habra ningun mensaje extra
{
  if (msg)
    if (stringp(msg))
      msg = ({msg,capitalize(TO->QueryShort())+" se aleja de la parada.\n"});
    else if (   pointerp(msg)
             && sizeof(msg)<2)
      msg+=({"El jefe de la caravana grita: ¡Acabamos de dejar @@FromParada@@ y nos dirigimos\n"
             "hacia @@Parada@@!\n",
             capitalize(TO->QueryShort())+" se aleja de la parada.\n"})
           [sizeof(msg)..];
  return Pcaravana_msgs_leave = msg;
}

public mixed QueryCaravanaLeaveMsgs()
{
  return Pcaravana_msgs_leave||
    ({"El jefe de la caravana grita: ¡Acabamos de dejar @@FromParada@@ y nos dirigimos\n"
      "hacia @@Parada@@!\n",
      capitalize(TO->QueryShort())+" se aleja de la parada.\n"});

}

public string *SetRooms(string *f) { return Prooms = f; }
public string *QueryRooms() { return (Prooms||({}))+({}); }
public string *AddRoom(string file)
// Para la 'limpieza' y el manejo de heart_beats la caravana necesita saber
// que habitaciones forman parte de el.
{
  file = resolve_file(file);
  return Prooms = (Prooms||({}))-({file})+({file});
}

public object *QueryPassengers()
// Devuelve los pasajeros de la caravana.
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
// Devuelve los posibles pasajeros que esperan en la parada.
{
  string *paradas;
  int i;
  object *res,parada;
  i = sizeof(paradas = m_values(QueryParadas()));
  res = ({});
  while(i--)
    if (parada = find_object(paradas[i]))
      res+=filter(deep_inventory(parada),SF(query_once_interactive));
  return res;
}

protected int calc_next_parada()
{
  object *cust;
  string *paradas_to_support;
  mapping paradas;
  int res,i,max_parada;
  paradas = QueryParadas();
  max_parada = max(m_indices(paradas));
  if (   !sizeof(QueryPassengers())
      && sizeof(cust = QueryCustomers())
     )
    {
      paradas_to_support = map(map(cust,SF(environment)),
                                   SF(object_name));
      for(i=0;i<max_parada+1;i++)
        if (member(paradas_to_support,paradas[i])!=-1&&i!=Pto_parada)
          return i;
      return Pto_parada;
    }
  res = Pto_parada+1;
  if (res>max_parada)
    res = 0;
  return res;
}

protected int can_sleep()
{
  if (   !environment()
      || object_name(environment())==DESERT
      || sizeof(QueryPassengers())
      || sizeof(QueryCustomers())
     )
    return 0;
  return 1;
}

protected int can_clean_up()
{
  if (!clonep())
    return Pcaravana!=0;
  return !can_sleep();
}

public string *SetDecks(string *f) { return Pdecks = f; }
public string *QueryDecks() { return (Pdecks||({}))+({}); }
public string *AddDeck(string file)
// Añade las habitaciones donde deberian salir los mensajes referentes a
// movimientos, llegadas, etc.. y donde el jugador puede abandonar la caravana.
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
        decks[i]->Set(P_HARBOUR,shore<0?Parada():0);
      tell_room(decks[i],msg);
    }
  seteuid(0);
}

public void AnnounceEnter()
// Dice en la parada y en las habitaciones de la caravana que la caravana ha llegado.
{
  mixed msg;
  msg = QueryCaravanaEnterMsgs();
  if (closurep(msg))
    if (!pointerp(msg = funcall(msg,QueryToParada())))
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
  msg = QueryCaravanaLeaveMsgs();
  if (closurep(msg))
    if (!pointerp(msg = funcall(msg,QueryToParada())))
      return DeckDisplay("",1);
  DeckDisplay(process_string(msg[0]),1);
  tell_room(environment(),process_string(msg[1]));
}

public mapping SetMoveScenes(mapping sc) { return Pmove_scenes = sc; }
public mapping QueryMoveScenes() { return Pmove_scenes||([]); }
public mapping AddMoveScene(string from,string to,mixed scene,int delay)
// from: Fichero de la posicion que la caravana acaba de abandonar
// to: Fichero al sitio donde la caravana se dirige
// scene: string: String que se escribira en todas las habitaciones de la caravana
//        closure: Sera llamada, si devuelve string se escribira sino se ignora
// delay: Tiempo antes de llamar a la siguiente escena
// La caravana llegara a la siguiente parada cuando todas las escenas hayan pasado
{
  int i;
  if (!Pmove_scenes)
    Pmove_scenes = ([]);
  if (!member(Pmove_scenes,from))
    Pmove_scenes[from] = ([]);
  if (!member(Pmove_scenes[from],to))
    Pmove_scenes[from][to] = m_allocate(0,ESCENA_ENTRADAS);
  i = sizeof(Pmove_scenes[from][to]);
  Pmove_scenes[from][to][i,ESCENA_TEXTO] = scene;
  Pmove_scenes[from][to][i,ESCENA_ESPERA] = delay;
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
         funcall(msgs,QueryFromParada(),QueryToParada(),QueryDecks())))
      return;
  DeckDisplay(msgs);
  call_out(SF(PrintMoveMsg),2+random(10));
}

public void StartJourney()
{
  AnnounceLeave();
  seteuid(getuid());
  TO->move(DESERT,M_SILENT);
  seteuid(0);
  // Fichero temporal donde esperar
  Pmoving=1;
  }

public void EndJourney()
{
  seteuid(getuid());
  TO->move(QueryToParada(),M_SILENT);
  Pmoving=0;
  seteuid(0);
  AnnounceEnter();
  set_heart_beat(1);
  // Espera en la parada
  while(remove_call_out(SF(PrintMoveMsg)) != -1);
}


public void NextParada()
// Llamada por heart_beat cuando se encuentra en la parada
{
  string where;
  string *paradas;
  int pos;
  if (!sizeof(paradas = m_values(QueryParadas()))) return;
  if (  !environment()
      ||(pos = member(paradas,where = object_name(environment())))==-1)
    {
      pos = 0;
      if (!Pto_parada = calc_next_parada())
        Pfrom_parada = max(m_indices(QueryParadas()));
      return EndJourney();
    }
  Pfrom_parada = pos;
  if ((pos = calc_next_parada())==Pto_parada)
  // Si el destino siguiente es el mismo donde estamos permanece parada
    return;
  Pto_parada = pos;
  StartJourney();
  Pmoving=1;
}

public void heart_beat()
{
   int delay;
   mixed text;
   string from,to;
 switch(Pmoving){
  case 0:
  if (can_sleep())
    {
      return;
    }
  if (   !environment()
      && !Phbcount)
    Phbcount = TIEMPO_ESPERA-random(5);
  // No deja que todas las caravanas lleguen a la vez al mismo puerto
  Phbcount++;
  if (Phbcount > TIEMPO_ESPERA)
    {
      Phbcount = 0;
      NextParada();
    }
    break;
  case 1:

  if (!Pmove_scenes
      ||!sizeof(QueryPassengers())
      ||!member(Pmove_scenes,from = QueryFromParada())
      ||!member(Pmove_scenes[from],to = QueryToParada())
      ||!member(Pmove_scenes[from][to],scene))
    {scene=0;return EndJourney();}
  text = Pmove_scenes[from][to][scene,ESCENA_TEXTO];
  delay = Pmove_scenes[from][to][scene,ESCENA_ESPERA];
   contador++;
  if (contador>delay/2)
  {
  if (closurep(text))
    text = funcall(text,from,to,QueryDecks());
  if (stringp(text))
    DeckDisplay(text);
    scene++;
    contador=0;
  }

  }
}

public void CallCaravana()
{
  object ob;
  if (clonep()&&object_name(PO)==blueprint())
    {
      if (   !environment()
          || object_name(environment())!=DESERT
         )
        set_heart_beat(1);
      return;
    }
  if (!ob = QueryCaravana())
    {
      seteuid(getuid());
      ob = clone_object(object_name());
      seteuid(0);
    }
  ob->CallCaravana();
}

public mixed SetEnterMsgs(mixed msg)
// ({<parada>,<caravana>,<player>}) (string o closure)
// o closure: Si devuelve un array como el anterior sino no hay mensajes extra
{
  return Penter_msgs = msg;
}

public mixed QueryEnterMsgs()
{
  return copy(Penter_msgs||
    ({"se une "+TO->QueryShort(),
      "se une a la caravana",
      "te unes "+TO->QueryShort()}));
}

public mixed SetLeaveMsgs(mixed msg)
// ({<caravana>,<parada>,<player>}) (string o closure)
// o closure: Si devuelve un array como el anterior sino no hay mensajes extra
{
  return Pleave_msgs = msg;
}

public mixed QueryLeaveMsgs()
{
   return copy(Pleave_msgs||
      ({"abandona la caravana",
        "abandona "+TO->QueryShort(),
        "abandonas "+TO->QueryShort()}));
}

public int cmd_leave(string str)
{
  if (   str
      && member(({"caravana"}),lower_case(str))==-1
      && locate(environment(),str,SM_OBJECT|SM_IGNLIGHT)!=TO
     )
    return notify_fail("No puedes abandonar "+str+".\n",NOTIFY_NOT_OBJ),0;
  if (object_name(environment(TO))==DESERT)
    return notify_fail("Lo siento, estamos a mitad de viaje.\n",
                       NOTIFY_NOT_VALID),0;
  if (!TP)
    return 0;
  TP->move(environment(),M_SPECIAL,funcall(QueryLeaveMsgs()));
  return 1;
}

public string QueryCaravanaPermission()
// [w] Inicialmente se permite la subida a la caravana a cualquier jugador.
{
 return "";
}

public int SetCaravanaCost(int cost)
// [w] Por defecto el viaje es gratuito
{
 return coste = cost || 0;
}

public int QueryCaravanaCost()
{
 return coste || 0;
}

public string SetMsgCost(string str)
{
 return MsgCoste = str || "Lo siento, no tienes suficiente dinero para unirte a nosotros.\n";
}

public string QueryMsgCost()
{
 return MsgCoste || "Lo siento, no tienes suficiente dinero para unirte a nosotros.\n";
}

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
  mixed mix;

  if (!TP)
    return 0;
  if (!str)
   return notify_fail("¿A qué caravana quieres unirte?.\n"),0;
  if (   str
      && member(({"caravana"}),lower_case(str))==-1
      && search(TP,str,SM_OBJECT|SM_IGNLIGHT|SEARCH_ENV)!=TO
     )
    return notify_fail("No puedes unirte a "+str+".\n",NOTIFY_NOT_OBJ),0;
  if (!sizeof(QueryDecks()))
    return notify_fail(
      capitalize(TO->QueryShort())+" no permite llevar pasajeros.\n",
      NOTIFY_NOT_VALID),0;
  InitDecks();
// [w] Comprueba si puede subir y controla el coste del viaje.
  if (QueryCaravanaPermission()!="")
   return notify_fail(QueryCaravanaPermission()+"\n");
  if (QueryCaravanaCost()!=0)
  {
   precio=QueryCaravanaCost();
   dinero_jugador="/lib/money"->QuerySomeonesValue(TP);
   if(dinero_jugador < precio)
   {
    return notify_fail(QueryMsgCost()),0;
   }
   mix="/lib/money"->PayValue2(TP,precio);
   if (intp(mix))
   	write("Pagas "+mix+".\n");
   else
	   write("Pagas "+mix[0]+(mix[1] ? " y recibes "+mix[1] : "")+".\n");
  }
// ------------
  // [kastwey] pongo el HomeTmp para que si desconectan
  // al conectar aparezcan en el sitio que estaban antes de subir.
  // [Nyh] retoco ligeramente.
  mix = environment(TP);
  TP->move(QueryDecks()[0], M_SPECIAL, funcall(QueryEnterMsgs()));
  if (mix) TP->SetHomeTmp(object_name(mix));

  return 1;
}

public int remove()
{
  mixed obs;
  int i;
  if (!clonep()&&Pcaravana)
    {
      write("¡Atención no debes destruir este blueprint!\n"
            "Para salvar los pasajeros destruye esta caravana.\n");
      return 0;
    }
  i = sizeof(obs = QueryPassengers());
  // SALVA LOS PASAJEROS
  while(i--)
    obs[i]->move(VOID,M_SPECIAL,
      ({"se salvó de una caravana que fué aniquilada",
        "llega de una caravana que fué aniquilada",
        "escapó de una caravana que estaba siendo aniquilada"}));
  // La caravana se va a hacer puñetas
  i = sizeof(obs = QueryRooms());
  while(i--)
     if (find_object(obs[i]))
       obs[i]->remove();
  destruct(TO);
  return 1;
}

public int QueryPmoving()
{
	return Pmoving;
}
