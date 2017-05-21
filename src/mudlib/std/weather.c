/* std/weather
**
** The basic code for nightday- and weather-servers.
**
**  15-Jun-93 [Mateese] Written from the old /obj/nightday
**  14-Jan-94 [Mateese] Made notification of users more flexible.
**  08-Sep-94 [Mateese] InitStates() added.
**  15-Sep-94 [Mateese] Fixed wrap-around bug in SetState().
**  02-Oct-99 [Theuzifan] Añado funciones para saber el dia, mes, etc...
**		Además ahora la fecha del MUD se calcula a partir de
**		time(), teniendo en cuenta la relación temporal entre
**		Simauria y la Realidad :)
*/

#include <config.h>
#include <properties.h>
#include <weather.h>
#include <nightday.h>
#include <rooms.h>
#include <scheduler.h>

#undef ENV
#define ENV  environment

/*-------------------------------------------------------------------------*/

public  int state;        // Actual state
private object *clients;  // objects to notify, a sorted array
private object *clientstodo, *clientsdone; // temp for notifies

public mixed *statedata;

private mixed *c_data;  // For faster access and temporary changes

/*-------------------------------------------------------------------------*/

public int QueryStateLength ();
public varargs int SetState (int new, int no_callout);
public int QueryState ();

/*-------------------------------------------------------------------------*/

public void InitStates()
{
  int i;

  statedata = (mixed *)NIGHTDAY->QueryStates();
  // Make a value copy in case the inheritor changes it.
  if (pointerp(statedata)) {
    statedata = (mixed *)NIGHTDAY->QueryStates() + ({});
    for (i=sizeof(statedata); i--; )
      if (pointerp(statedata[i]))
        statedata[i] = statedata[i]+({});
  }
}


int *correct_state()
{
  int mytime, i, secs, sdia;

  mytime=time();
  secs=0;
  sdia=(CHRONOS->QueryHour()*60*60+CHRONOS->QueryMinute()*60)/4;

  for (i=0; i<sizeof(statedata); i++)
  {
    if (sdia>secs) secs+=statedata[i][0];
    else break;
  }

  return ({i-1,secs-sdia});
}


public void StartServer() {
  int daytime, len, *st;
  if (!statedata)
    SetState(0);
  else {
    st=correct_state();
    SetState(st[0]);
    remove_call_out("NextState");
    call_out("NextState", st[1]);
  }
}

public void create() {
  if (object_name(TO) == "/std/weather") return;
  clients = ({});
  c_data = allocate (WD_USER);
  InitStates();
  StartServer();
}

/*-------------------------------------------------------------------------*/
// True properties

public mixed *QueryStates () { return statedata; }
public mixed *SetStates (mixed *v) {
  return statedata = v;
}

public mixed * QueryStateEntry (int ix) {
  return statedata[ix];
}
public mixed * SetStateEntry (int ix, mixed v) {
  return statedata[ix] = v;
}

public int CountStates () { return statedata && sizeof(statedata); }
public int TimeLeft()     { return find_call_out ("NextState"); }

/*-------------------------------------------------------------------------*/
// Actually queried functions, including temporary caches.

public varargs mixed QueryStateData (int flag) {
  mixed *s_data;
  s_data = QueryStateEntry(QueryState());
  if (flag) return s_data;
  if (sizeof(c_data) < sizeof(s_data))
    return c_data+s_data[sizeof(c_data)..];
  return c_data;
}
public mixed SetStateData (mixed v) {
  mixed *s_data;
  if (sizeof(v) < sizeof(c_data))
    v += c_data[sizeof(v)..];
  c_data = v;
  s_data = QueryStateEntry(QueryState());
  if (sizeof(c_data) < sizeof(s_data))
    c_data += s_data[sizeof(c_data)..];
  else if (sizeof(c_data) > sizeof(s_data))
    c_data = c_data[0..sizeof(s_data)-1];
  return c_data;
}

public string QueryStateDesc ()        { return c_data[WD_DESC]; }
public string SetStateDesc (string m)  { return c_data[WD_DESC] = m; }

public string QueryChangeDesc ()       { return c_data[WD_CDESC]; }
public string SetChangeDesc (string m) { return c_data[WD_CDESC] = m; }

public int QuerySunLight ()    { return c_data[WD_SUNLIGHT]; }
public int SetSunLight (int i) { return c_data[WD_SUNLIGHT] = i; }

public int QueryStateLength ()    { return c_data[WD_LENGTH]; }
public int SetStateLength (int i) { return c_data[WD_LENGTH] = i; }

/*-------------------------------------------------------------------------
** Handling of the clients-array.
*/

public object *QueryClients()        { return clients; }
public object *SetClients(object *c) {
  clientstodo = 0;
  clientsdone = 0;
  return clients = c;
}

public void AddClient (object client) {
  clients = (clients || ({}))+({client});
}

public void RemoveClient (object client) {
  clients = (clients || ({}))-({client});
}

public void CleanupClients () {
  if (!clients) return;
  clients = clients - ({ 0 });
}

/*-------------------------------------------------------------------------
** Notify all clients about the current state.
*/

public varargs int IsMyPlayer (object player, object env) {
  int depth;
  mixed env_server;

  if (!player)
    return 0;

  // Search the nearest enclosing 'Outdoors' environment and
  // count the depth.
  env = player;
  depth = 0;
  env_server = 0;
  while (env) {
    depth++;
    env_server = env->QueryServer();
    if (env_server)
      break;
    env = ENV(env);
  }

  if (stringp(env_server))
     env_server = load_object(env_server);

  if (!env || env_server != TO)
    return 0;

  return depth;
}


public int NotifyClient (object client, mixed *data, int newstate) {
  if (data && client->QueryServer () == object_name(TO))
  {
    client->NotifyDayStateChange(data, newstate);
  }
  return !!data;
}

private void _notify_clients (mixed *data, int newstate) {
  int amount;
  if ((amount = sizeof(clientstodo)) > 100)
    amount = 100;
  if (amount > 0) {
    map (clientstodo[0..amount-1], SF(NotifyClient), data, newstate);
    clientstodo = clientstodo[amount..];
  }
  if (sizeof(clientstodo))
    call_out ("_notify_clients", 0, data, newstate);
  else {
    clients = clientsdone;
    clientsdone = 0;
  }
}

private object _check_scheduler_room(string dest, object door)
// comprueba si con los parámetros especificados, la room a la
// que apunta esa salida, es una room scheduler que necesita ser notificada del cambio de
// estado
{
    object room;
    int *close, priorstate, openbefore, opennow, nocargada;

    if (door && (close = door->QueryDoorCloseTime()) && sizeof(close))
    {
        priorstate = state - 1;
        if (priorstate < ND_NIGHT) priorstate = ND_PRENIGHT;
        openbefore = member(close, priorstate) < 0;
        opennow = member(close, state) < 0;
        if (openbefore == opennow) return 0;
        // si la room no tiene ni que abrirse ni que cerrarse, ni siquiera le notificamos el cambio de estado
        room = find_object(dest);
        if (!room)
        {
            nocargada = 1;
            room = load_object(dest);
        }
        if (member(inherit_list(room), SCHEDULER_ROOM ".c") >= 0)
        {
            if (nocargada)
            {
                if (openbefore && !opennow) room->SetRoomState(S_OPENED);
                else room->SetRoomState(S_CLOSED);
            }
            return room;
        }
    }
    return 0;
}


public object *QuerySchedulerRooms(object room)
// obtiene las habitaciones scheduler que conecten con <room>
// si <room> es scheduler, no se hace nada
{
    mapping salidas;
    object *rooms = ({});
    object res;

    if (member(inherit_list(room), SCHEDULER_ROOM ".c") >= 0) return 0;
    foreach(string salida, mixed dest, object door : room->ListExitsDoor())
    {
        res = _check_scheduler_room(dest, door);
        if (res) rooms += ({res});
    }


    return rooms;
}
    
public varargs void NotifyClients (mixed *data, int newstate) 
// notifico a los clientes de <clients>, y a las rooms de los usuarios conectados,
// así como las rooms circundantes a estas que sean schedulers, y a las
// rooms que estas tengan puestas en ServerNotifications.
{
  object *rooms; // Mapping para asegurarme que NO hay elementos repetidos
  object room;
  
  string *others = ({});

  if (!data) {
    data = QueryStateData();
    newstate = QueryState();
  }

  rooms = m_indices(mkmapping( map( users(), SF(environment) ) )) - ({0}); // habitaciones de los pj

  foreach(room: rooms)
  {
    object *schedulers = QuerySchedulerRooms(room);
    if (sizeof(schedulers)) rooms += schedulers;
  }

  foreach(room: rooms) 
    if (sizeof(room->QueryServerNotifications())) 
      others += room->QueryServerNotifications();

  others = m_indices(mkmapping(others)); // para limpiar elementos repetidos
  
  rooms += map(others, SF(load_object));
  rooms = m_indices(mkmapping(rooms));
  map(rooms, SF(NotifyClient), data, newstate);

  if (!sizeof(clients)) return;
  if (sizeof(clients) <= 100)
    map (clients, SF(_notify_clients), data, newstate);
  else if (clientsdone) // Notify in progress: delay!
    call_out ("NotifyClients", sizeof(clients) / 10, data, newstate);
  else {
    clientstodo = clients + ({});
    clientsdone = ({});
    _notify_clients(data, newstate);
  }
}

/*-------------------------------------------------------------------------
** Change the state from to <new>.
** This does merely set the state variable, reloads the c_data cache
** and then notifies all clients.
** If <no_callout> is not set, it also restarts the call_out() to NextState().
*/

public int QueryState () { return state; }
public varargs int SetState (int new, int no_callout) {
  if (!statedata) state = new;
  else            state = new % (CountStates() || 1);
  c_data = QueryStateEntry(state);
  if (!no_callout) {
    remove_call_out ("NextState");
    call_out ("NextState", c_data[WD_LENGTH]);
  }
  NotifyClients(c_data, state);
  return state;
}

public void NextState () {
  SetState (QueryState()+1);
}

/***************************************************************************/
