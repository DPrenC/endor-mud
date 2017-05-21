/**
 * simauria /std/scheduler_room
**/

#pragma no_clone
#include <moving.h>
#include <rooms.h>
#include <door.h>
#include <colours.h>
#include <nightday.h>
#include <scheduler.h>
#include <stdrooms.h>
// #define DEBUG_SCHEDULER
#ifdef DEBUG_SCHEDULER
#define DEBUGGER "kastwey"
#define DEB_NAME (explode(object_name(), "/")[<1])
#define DEB_ONAME(x)   (explode(object_name(x), "/")[<1])
#endif

inherit ROOM;

// Propiedades y variables de control

private int processing;
private int pRoomState, *pCloseTime, pNoSchedulerObject;
private string pRoomClosedMsg, pMainRoom, pSchedulerID, *pAssociatedRooms;
private string *pNotifyExits, pThrowOutMsg, pLastDest, pInformCloseMsg, *pNotifyOpenMsg, *pNotifyCloseMsg;
private int _informed;

// ----------------------------------------------------------------------------

// Forward

public varargs int CheckState(int newstate, int silent, object from, int from_silent); // forward
public varargs mapping QueryOutExits(int include_closures); // forward
public int QueryIsMainRoom();

// ----------------------------------------------------------------------------

// Manejo de propiedades

public int SetRoomState(int i) { return pRoomState = i; }
public varargs int QueryRoomState(int nocalculate) { return nocalculate ? pRoomState : CheckState(QueryDayState(), 1); }

public int *SetCloseTime(mixed time)
{
    if (!pointerp(time) && !intp(time)) return pCloseTime;
    if (intp(time)) time = ({time});
    return pCloseTime = time;
}
public int *QueryCloseTime() { return copy(pCloseTime); }

public int SetNoSchedulerObject(int i) { return pNoSchedulerObject = i; }
public int QueryNoSchedulerObject()
{
    if (!pNoSchedulerObject && !QueryIsMainRoom())
    {
        if (!pMainRoom) return 0;
        return pSchedulerID = resolve_file(pMainRoom)->QueryNoSchedulerObject();
    }
    return pNoSchedulerObject;
}

public string SetRoomClosedMsg(string msg) { return pRoomClosedMsg = msg; }
public string QueryRoomClosedMsg() { return pRoomClosedMsg; }

public string SetMainRoom(string r) { return pMainRoom = r; }
public string QueryMainRoom() { return pMainRoom; }

public string SetSchedulerID(string id)
{
    if (id) pNoSchedulerObject = 0;
    else pNoSchedulerObject = 1;
    return pSchedulerID = id;
}
public string QuerySchedulerID()
{
    if (!pSchedulerID)
    {
        if (QueryIsMainRoom()) return 0;
        if (!pMainRoom) return 0;
        return pSchedulerID = resolve_file(pMainRoom)->QuerySchedulerID();
    }
    return pSchedulerID;
}

public string *SetAssociatedRooms(mixed rooms)
{
#ifdef DEBUG_SCHEDULER
    dtell(DEBUGGER, sprintf("Ejecuto SetAssociatedIds(%O).\n", rooms));
#endif
    if (!stringp(rooms) && !pointerp(rooms) && rooms) return pAssociatedRooms;
    if (stringp(rooms)) return pAssociatedRooms = ({rooms});
    return pAssociatedRooms = rooms;
}
public string *QueryAssociatedRooms() { return copy(pAssociatedRooms); }

public string *SetNotifyExits(mixed exits)
{
    if (!stringp(exits) && !pointerp(exits) && exits) return pNotifyExits;
    if (stringp(exits)) return pNotifyExits = ({exits});
    return pNotifyExits = exits;
}
public string *QueryNotifyExits() { return copy(pNotifyExits); }


public string SetThrowOutMsg(string msg) { return pThrowOutMsg = msg; }
public string QueryThrowOutMsg() { return pThrowOutMsg; }

public string SetLastDest(string dest) { return pLastDest = dest; }
public varargs string QueryLastDest(int calculate)
// devuelve pLastDest, o si pLastDest vale 0 y calculate está a 1, intenta calcularlo
{
    mapping salidas;
    if (pLastDest) return pLastDest;
    salidas = QueryOutExits();
    if (!salidas) return 0;
    return m_values(salidas, EXIT_DEST)[random(sizeof(salidas))];
}

public string SetInformCloseMsg(string msg) { return pInformCloseMsg = msg; }
public string QueryInformCloseMsg() { return pInformCloseMsg; }

public string *SetNotifyOpenMsg(mixed s)
{
    if (!s) return pNotifyOpenMsg = s;
    if (!pointerp(s) && !stringp(s)) return copy(pNotifyOpenMsg);
    if (pointerp(s))
    {
        pNotifyOpenMsg = s[..1];
    }
    else
    {
        pNotifyOpenMsg = ({s});
    }
    return copy(pNotifyOpenMsg);
}
public string *QueryNotifyOpenMsg() { return copy(pNotifyOpenMsg); }

public string *SetNotifyCloseMsg(mixed s)
{
    if (!s) return pNotifyCloseMsg = s;
    if (!pointerp(s) && !stringp(s)) return copy(pNotifyCloseMsg);
    if (pointerp(s))
    {
        pNotifyCloseMsg = s[..1];
    }
    else
    {
        pNotifyCloseMsg = ({s});
    }
    return copy(pNotifyCloseMsg);
}
public string *QueryNotifyCloseMsg() { return copy(pNotifyCloseMsg); }


public  int QueryCloseInformed() { return _informed; }

// ----------------------------------------------------------------------------


// Funciones varias

public int QueryIsMainRoom()
{
    if ((pAssociatedRooms && sizeof(pAssociatedRooms)) || (!pAssociatedRooms && !pMainRoom)) return 1;
    return 0;
}

public int IsCloseTime(int state)
{
    int *ct;
    if (!QueryIsMainRoom() && !pMainRoom) return 0;
    ct = QueryIsMainRoom() ? pCloseTime : resolve_file(pMainRoom)->QueryCloseTime();
    if (!ct) return 0;
    return member(ct, state) >= 0;
}

    public varargs mapping QueryOutExits(int include_closures)
// devuelve las salidas que dan al exterior, o de no haberlas, devolverá las que tengan
// un EXIT_DEST que no sea closure... Si no existe ninguna, devolverá 0 si include_closures está a 0,
// o las que tenga la room, si include_closures está a 1
{
    mapping salidas = filter(QueryExits() || ([]), (:!closurep($2[EXIT_DEST]) && !$2[EXIT_DEST]->QueryIndoors():));
    mapping salida;
    if (sizeof(salidas)) return salidas;
    // no hay salidas al exterior, así que pillamos las que no tengan closures
    salidas = filter(QueryExits() ||([]), (:!closurep($1[EXIT_DEST]):));
    if (sizeof(salidas)) return salidas;
    if (!include_closures) return 0;
    // ni exteriores ni sin closures en el destino... pues ala, QueryExits, a pelo
    return QueryExits();
}


public object QuerySchedulerObject()
{
    object schob, *obs;
    if (!QuerySchedulerID() || (!QueryIsMainRoom() && !pMainRoom)) return 0;
    obs = filter(all_inventory(), (:$1->id(pSchedulerID) && living($1):));
    if (sizeof(obs)) return obs[0];
    if (pMainRoom)
    {
        obs = filter(all_inventory(load_object(resolve_file(pMainRoom))), (:$1->id(pSchedulerID) && living($1):));
        if (sizeof(obs)) return obs[0];
    }
    return 0;
}


// ----------------------------------------------------------------------------

public void inform_close()
{
    string desc;
    int left;
    object ob;

    if (_informed) return;
    if ((left = QueryServer()->TimeLeft()) - TIME_TO_INFORM > 0)
    {
#ifdef DEBUG_SCHEDULER
        dtell(DEBUGGER, "Falta más de " + TIME_TO_INFORM + " segundos. Se recalcula el call_out.\n");
#endif
        while(remove_call_out("inform_close") != -1);
        call_out("inform_close", left - TIME_TO_INFORM);
        return;
    }
    if (!pNoSchedulerObject && !(ob = QuerySchedulerObject()))
    {
#ifdef DEBUG_SCHEDULER
        dtell(DEBUGGER, DEB_NAME + ". Salgo de inform_close, porque no hay objeto scheduler y no está definido como inexistente.\n");
#endif
        return;
    }

    if (pInformCloseMsg) tell_room(TO, pInformCloseMsg);
    else if (ob)
    {
        tell_room(TO, CAP(ob->QueryName() || ob->QueryShort()) + " " +
            (QueryIsMainRoom() ? "dice" : "grita") + ": ¡Venga, vamos saliendo que ya mismo "
            "cierro!\n");
    }
    else if (pNoSchedulerObject)
    {
        tell_room(TO, "Será mejor que vayas saliendo, " + (QueryIntShort(1) || "la habitación") +
                  " está a punto de cerrar.\n");
    }
    _informed = 1;
}



public void move_player_to_last_dest(object player)
{
    string dest = pLastDest || QueryLastDest(1);
    mapping salidas;

    if (!dest)
    {
        tell_object(player, TC_RED + "¡ATENCIÓN! " + TC_NORMAL + TC_BLUE +
                    "Cuando saliste del juego lo hiciste en " +
                    (QueryIntShort(1) || "una habitación")  + " cuyas puertas se encuentran "
                    "cerradas en este momento. Aunque se te ha intentado mover fuera "
                    "de dicha habitación, ha sido imposible. "
                    "Contacta con un wizard.\n" + TC_NORMAL);
        load_object(CHANNELMASTER)->SendEmote("error",
                    NREAL(player) + " no pudo moverse fuera de " +
                    (QueryIntShort(1) || "una habitación") + " (" + object_name(TO) + "), al "
                    "no estar definido LastDest y no encontrarse salidas adecuadas para el movimiento");
        player->move(INICIO, M_GO);
        return;
    }
    dest = resolve_file(dest);
    tell_object(player, "En tu última expedición en Arda, abandonaste el mundo en " +
                (QueryIntShort(1) || "una habitación") + ", que en este momento no es"
                " accesible para jugadores.\n"
                "Los Señores de Arda te trasladan a la sala de los portales.\n"
                "Desde aquí podrás acceder a casi cualquier lugar de Arda.\n");
    player->move(dest, M_GO);
}

public int allow_enter(int method, mixed extra)
{
    object quien = PO;
    int delatienda;
    string *assoc;

    if (!quien) return ME_NO_ENTER;
    if (   !living(quien)
        || (!query_once_interactive(quien) && !quien->QueryIsPet() && (method != M_GO || (method == M_GO && !extra)))
        || QueryRoomState() == S_UNKNOWN || QueryRoomState() == S_OPENED)
    {
        return ::allow_enter(method, extra);
    }
    if (query_once_interactive(quien) && !environment(quien))
    // está entrando al mud y, desgraciadamente, aparece en esta room que está cerrada
    {
        call_out("move_player_to_last_dest", 1, quien);
        return ::allow_enter(method, extra);
    }

    if (pRoomState == S_CLOSING)
    // esto en teoría no debe pasar nunca. Un jugador debe de ser echado de la tienda diréctamente.
    // Pero por si acaso, se hace esta comprobación para evitar que no pueda moverse
    // por las habitaciones de la tienda
    {
        assoc = QueryIsMainRoom() ? QueryAssociatedRooms() : resolve_file(pMainRoom)->QueryAssociatedRooms();
        if (assoc) assoc = map(assoc, (:resolve_file($1):));
        delatienda = assoc && sizeof(assoc) && member(assoc, object_name(environment(quien))) >= 0;
        if (delatienda) return ::allow_enter(method, extra);
        tell_object(quien, CAP(QueryIntShort(1) || "El establecimiento") + " está cerrando, ya no se "
                    "puede entrar.\n");
    }
    else if (pRoomState == S_CLOSED)
    {
        tell_object(quien,
                    (pRoomClosedMsg || (CAP(QueryIntShort(1) || "") || "El establecimiento") +
                     " tiene las puertas cerradas en este momento.\n"));
    }
    return ME_CLOSED;
}

public varargs void CloseRoom(int silent)
// si silent está a 1 no se notifica al exterior
{
    object ob;
    string *notificar;

#ifdef DEBUG_SCHEDULER
    dtell(DEBUGGER, "Ejecuto CloseRoom(silent = " + silent + ") en " + DEB_NAME + ".\n");
#endif
    if (!pNoSchedulerObject && !(ob = QuerySchedulerObject())) return;
    // podemos cerrar
    // Buscamos las habitaciones a las que tenemos que notificar que vamos a cerrar
    if (!silent)
    {
        notificar  = pNotifyExits || m_indices(QueryOutExits() || ([]));
        if (notificar && sizeof(notificar))
        {
            object noti, puerta;
            int i;
            string dir, short, sonido, desc;
            mapping ex;

            desc = QueryIntShort(1) || "la habitación";
            if (ob) short = CAP(ob->QueryName() ||ob->QueryShort() || "alguien");
            for (i=sizeof(notificar);i--;)
            {
                ex = QueryExit(notificar[i]);
                if (!closurep(ex[notificar[i], EXIT_DEST]) && noti = find_object(ex[notificar[i], EXIT_DEST]))
                // no es una closure, y el objeto al que da la salida está cargado
                {
                    if ((puerta = ex[notificar[i], EXIT_DOOR]))
                    // tiene puerta...
                    // esto es una pijada, pero mola cantidad XD
                    {
                        if (puerta->QueryDoorState() == DOOR_CLOSED /* && QueryIsMainRoom() && !i*/)
                        {
                            if (ob)
                            {
                                tell_room(noti, short + " abre " + puerta->QueryShort() +
                                          (puerta->QueryDoorTransparency() ? " desde el otro lado" : "") +
                                          ".\n");
                            }
                            else tell_room(noti, "Se abre " + puerta->QueryShort() + ".\n");
                            puerta->SetDoorState(DOOR_OPENED);
                            if ((sonido = puerta->QueryDoorOpenSound())) play_sound(noti, sonido);
                        }
                        if (ob)
                        {
                            if (!i && present(ob, TO))
                            {
                                tell_room(noti, (pNotifyCloseMsg ? regreplace(pNotifyCloseMsg[0], "@name@", short, 0) :
                                          short + " sale de " + desc + ", cierra " +
                                          puerta->QueryShort() + " y se marcha.\n"));
                            }
                            else
                            {
                                tell_room(noti, (pNotifyCloseMsg && sizeof(pNotifyCloseMsg) == 2 ?
                                                 regreplace(pNotifyCloseMsg[1], "@name@", short, 0) :
                                                 (puerta->QueryDoorTransparency() ? short +
                                                  " cierra " + puerta->QueryShort() + " desde el otro lado" :
                                                  "Se cierra " + puerta->QueryShort(object_name(noti))) + ".\n"));
                            }
                        }
                        else
                        {
                            tell_room(noti, "Se cierra " + puerta->QueryShort(object_name(noti)) + ".\n");
                        }
                        puerta->SetDoorState(DOOR_CLOSED);
                        if ((sonido = puerta->QueryDoorCloseSound())) play_sound(noti, sonido);
                        puerta->SetKey(object_name(TO));
                        puerta->SetDoorLockState(DOOR_LOCKED);
                    }
                    else
                    {
                        if (pNoSchedulerObject)
                        // no hay empleado
                        {
                            tell_room(noti, "Se cierra " + CAP(QueryIntShort(1) || "algo") + ".\n");
                        }
                        else
                        {
                            if (i || !present(ob, TO))
                            {
                                tell_room(noti,
                                          (pNotifyCloseMsg && sizeof(pNotifyCloseMsg) == 2 ?
                                           regreplace(pNotifyCloseMsg[1], "@name@", short, 0) :
                                           short +
                                           " cierra " + QueryIntShort(1) + ".\n"));
                            }
                            else
                            {
                                tell_room(noti,
                                          (pNotifyCloseMsg ? regreplace(pNotifyCloseMsg[0], "@name@", short, 0) :
                                          CAP(short) + " cierra " + QueryIntShort(1) + " y se marcha.\n"));
                            }
                        }
                    }
                }
            }
        }
    }
    // cerramos las puertas
    foreach(string salida, mixed dest, object door:ListExitsDoor())
    {
        door->SetDoorState(DOOR_CLOSED);
        door->SetDoorLockState(DOOR_LOCKED);
    }
#ifdef DEBUG_SCHEDULER
    dtell(DEBUGGER, "Finalizo CloseRoom en " + DEB_NAME + ", y cierro.\n");
#endif
    pRoomState = S_CLOSED;
}

public varargs void OpenRoom(int silent)
// Si silent está a 1, no se notifica
{
#ifdef DEBUG_SCHEDULER
    dtell(DEBUGGER, "Ejecuto OpenRoom en " + DEB_NAME + ".\n");
#endif
    string *notificar;
    object ob;

    if (!pNoSchedulerObject && !(ob = QuerySchedulerObject())) return;
    if (!silent)
    {
        notificar = pNotifyExits || m_indices(QueryOutExits() || ([]));
        if (notificar && sizeof(notificar))
        {
            object noti, puerta;
            int i;
            mapping ex;


            for (i=sizeof(notificar);i--;)
            {
                ex = QueryExit(notificar[i]);
                if (!closurep(ex[notificar[i], EXIT_DEST]) && (noti = find_object(ex[notificar[i], EXIT_DEST])))
                {
                    if ((puerta = ex[notificar[i], EXIT_DOOR]))
                    // tiene puerta
                    {
                        string sonido = puerta->QueryDoorOpenSound();
                        puerta->SetDoorLockState(DOOR_UNLOCKED);
                        puerta->SetDoorState(DOOR_OPENED);
                        if (sonido) play_sound(noti, sonido);
                    }
                    if (pNoSchedulerObject)
                    {
                        tell_room(noti, "Se abre " + (QueryIntShort(1) || "el establecimiento") + ".\n");
                    }
                    else
                    {
                        string short = (ob->QueryName() || ob->QueryShort() || "alguien");
                        if (!i && present(ob, TO))
                        {
                            tell_room(noti,
                                (pNotifyOpenMsg ? regreplace(pNotifyOpenMsg[0], "@name@", short, 0) :
                                CAP(short) + " llega y abre " + (QueryIntShort(1) || "el establecimiento") +
                                ".\n"));
                        }
                        else
                        {
                            tell_room(noti,
                                (pNotifyOpenMsg && sizeof(pNotifyOpenMsg) == 2 ? regreplace(pNotifyOpenMsg[1], "@name@", short, 0) :
                                CAP(short) + " abre " + (QueryIntShort(1) || "el establecimiento") + ".\n"));
                        }
                    }
                }
            }
        }
    }
    // abrimos las puertas que haya
    foreach(string salida, mixed dest, object door:ListExitsDoor())
    {
        if (pNotifyExits && member(pNotifyExits, salida) >= 0)
        {
            door->SetDoorLockState(DOOR_UNLOCKED);
            door->SetDoorState(DOOR_OPENED);
        }
    }
    _informed = 0; // no se ha informado del cierre
    pRoomState = S_OPENED;
}


public varargs int ThrowOutPeople(int silent, object from, int from_silent)
// echa a los clientes de la room
{
#ifdef DEBUG_SCHEDULER
    dtell(DEBUGGER, "Ejecuto ThrowOUtPeople(silent " + silent + ", from " + object_name(from) + ", from_silent " + from_silent + ") en " + DEB_NAME + ".\n");
#endif
    object *people, ob, puerta;
    mixed items;
    string msg, dest, desc;
    int i, ismain, npeople, npeople2;
    string *assoc, *allrooms;
    mapping salidas;

    if (!(ismain = QueryIsMainRoom()) && !from) return -1;

    if (!pNoSchedulerObject && !(ob = QuerySchedulerObject())) return -1;
    // paramos todos los ataques que puedan estar produciéndose, y de paso
    // pillamos los players que hay aquí dentro
#ifdef DEBUG_SCHEDULER
    dtell(DEBUGGER, "Saco a la gente de " + DEB_NAME + ", y paro ataques.\n");
#endif
    people = filter(all_inventory(),
                    (:if (living($1) && $1->Fighting()) $1->StopAttack();
    return (living($1) && $1 != $3 && (!$2 || !sizeof($2) || member($2, $1) < 0));:), ((items = QueryItems()) ? map(QueryItems(), (:$1[RITEM_OBJECT]:)) : 0), QuerySchedulerObject());
#ifdef DEBUG_SCHEDULER
    dtell(DEBUGGER, sprintf("Gente: %s.\n", implode(map(people, (:$1->QueryName():)), ", ")));
#endif
    // si no hay gente dentro, cerramos, sin más
    // si esta función se llamó como silent , se cierra en silencio
    if (people && (npeople = sizeof(people)))
    {
        if (pThrowOutMsg) msg = pThrowOutMsg;
        else if (ob)
        {
            if (!ismain && ob == resolve_file(pMainRoom)->QuerySchedulerObject())
            {
                msg = CAP(ob->QueryName() || ob->QueryShort() || "alguien") + " llega gritando: ¡Venga, "
                      "vamos fuera, que es hora de cerrar!\n"
                      "Rápidamente, te diriges a la salida y abandonas " + (QueryIntShort(1) || "la habitación") + ".\n";
            }
            else
            {
                msg = CAP(ob->QueryName() || ob->QueryShort() || "Alguien") + " dice: ¡Venga, Fuera "
                      "de aquí, que es hora de cerrar!\n"
                      "Rápidamente, te diriges a la salida y abandonas " + (QueryIntShort(1) || "la habitación") + ".\n";
            }
        }
        if (!msg) msg = "Viendo que ya van a cerrar, decides marcharte de aquí.\n";
        tell_room(TO, msg);
        dest = resolve_file(pLastDest || from->QueryLastDest(1) || QueryLastDest(1));
#ifdef DEBUG_SCHEDULER
        dtell(DEBUGGER, "Dest: " + dest+ ".\n");
#endif
        desc = TO->QueryIntShort(1);
        if (!desc) desc = "la habitación";
        allrooms = (ismain ? ({object_name()}) + (pAssociatedRooms  || ({})):
            ({pMainRoom}) + (resolve_file(pMainRoom)->QueryAssociatedRooms() || ({})));
        allrooms = map(allrooms, (:resolve_file($1):));
#ifdef DEBUG_SCHEDULER
        dtell(DEBUGGER, "Assoc para ver las puertas es: " + sprintf("%O", assoc) + ".\n");
#endif

        salidas = filter(dest->ListExitsDoor(), (:object hab;
                         if ((hab = find_object($2[EXIT_DEST])) && IS_SCHEDULER(hab))
                         // es una hab cargada y es scheduler. comprobamos si pertenece a
                         // las habitaciones de this_object
                         {
#ifdef DEBUG_SCHEDULER
                             dtell(DEBUGGER, "Es hab cargada y scheduler: " + DEB_ONAME(hab) + ".\n");
#endif
                             if (   hab == TO
                                 || member($3, object_name(hab)) >= 0)
                             {
                                 return 1;
                             }
                         }
                         return 0;:), allrooms);
        if (salidas && sizeof(salidas)) puerta = m_values(salidas, EXIT_DOOR)[0];
#ifdef DEBUG_SCHEDULER
        dtell(DEBUGGER, sprintf("Puerta es %O.\n", puerta));
#endif
        for (i = npeople; i--;)
        // los vamos echando fuera
        {
            if (i == (npeople - 1) && puerta && puerta->QueryDoorState(1) == DOOR_CLOSED)
            // es el primero, y hay puerta, así que, si está cerrada, la abre
            {
                string sonido = puerta->QueryDoorOpenSound(), sh_puerta;
                object ladodest, otrolado;
                ladodest = find_object(dest);
                otrolado = puerta->QueryDoorOtherSide(ladodest, 1);

                if (puerta->QueryDoorLockState() == DOOR_LOCKED) puerta->SetDoorLockState(DOOR_UNLOCKED);
                tell_object(people[i], "Abres " + (puerta->QueryShort(otrolado) || "una puerta")+ ".\n");
                if (sonido)
                {
                    play_sound(({ladodest, otrolado}), sonido);
                }
                if (puerta->QueryDoorTransparency())
                {
                    tell_room(ladodest, "Ves como " + NNAME(people[i]) + " abre " +
                              (puerta->QueryShort(ladodest) || "una puerta") + ".\n");
                }
                else
                {
                    tell_room(ladodest, "Se abre " + (puerta->QueryShort(ladodest) || "una puerta") +
                              ".\n");
                }
                puerta->SetDoorState(DOOR_OPENED);
            }
            if (people[i]->move(dest, M_SPECIAL, ({"sale de " + desc, "Sale de " + desc, "Sales a " + dest->QueryIntShort(1)})) == ME_OK) npeople++;
        }
        npeople = npeople2 - npeople;
    }
    if (ismain && (assoc = copy(pAssociatedRooms)) && (assoc= map(assoc, (:resolve_file($1):))) && sizeof(assoc= filter(assoc, (:find_object($1):))))
    // comprobamos, en todas las habitaciones asociadas, si queda gente
    {
#ifdef DEBUG_SCHEDULER
        dtell(DEBUGGER, "Busco asociadas en " + DEB_NAME + ". Luego de filtrar, pAssociatedRooms queda: " + implode(pAssociatedRooms, ", ") + ".\n");
#endif
        if (from)
        {
            assoc-= ({object_name(from)});
#ifdef DEBUG_SCHEDULER
            dtell(DEBUGGER, "Como hay from, quito from a assoc, y se queda en: " + implode(assoc, ", ") + ".\n");
#endif
        }


        // si from está aquí, lo quitamos para notificarlo luego con el valor en silent de from_silent
        npeople2 = sum(call_other(assoc, "ThrowOutPeople", 0, TO));
        if (from) npeople2 += from->ThrowOutPeople(from_silent, TO);
        if (npeople2 > 0)
        // queda gente
        {
#ifdef DEBUG_SCHEDULER
            dtell(DEBUGGER, "Queda gente en alguna asociada: " + npeople2 + ".\n");
#endif
            call_out("ThrowOutPeople", 3, silent, from, from_silent);
        }
        else
        {
#ifdef DEBUG_SCHEDULER
            dtell(DEBUGGER, "NO queda gente, cierro " + DEB_NAME + ".\n");
#endif
            CloseRoom(silent);
        }
    }
    else
    {
        if (npeople <= 0) CloseRoom(silent);
        else pRoomState = S_CLOSING;
    }
#ifdef DEBUG_SCHEDULER
    dtell(DEBUGGER, "Al finalizar ThrowOutPeople en " + DEB_NAME + ", pRoomState es " + pRoomState + ".\n");
#endif
    return npeople;
}


public varargs int CheckState(int newstate, int silent, object from, int from_silent)
// comprueba si se tiene que cambiar el estado de apertura o cierre de esta room
// si silent está a 1, es que se llamó a esta función desde QueryRoomState y no desde reset, NotifyDayStateChange o notificación de otras rooms.
// si esta no es MainRoom, solo se devuelve el estado, sin cambiarlo, y notificando a MainRoom
// si processing está a 1, solo devolvemos el estado, y así evitamos recursividad
{
#ifdef DEBUG_SCHEDULER
    dtell(DEBUGGER, sprintf("Ejecuto CheckState(estado %d, silent %d, from %O, from_silent %d) en %s.\n", newstate, silent, from, from_silent, DEB_NAME));
#endif
    object ob;
    int fuerahorario, ismain, nextstate, *ctime;
    if (processing || !(ismain = QueryIsMainRoom()) && !pMainRoom)
    {
#ifdef DEBUG_SCHEDULER
        dtell(DEBUGGER, DEB_NAME + " Salgo porque " + (processing ? "Ya se está ejecutando una petición" : "no es MainRoom pero no tiene MainRom Asociada.\n"));
#endif
        return pRoomState;
    }
    processing = 1;
    nextstate  = newstate + 1 > ND_PRENIGHT ? 0 : newstate + 1;
    ctime = ismain ? pCloseTime : resolve_file(pMainRoom)->QueryCloseTime();
#ifdef DEBUG_SCHEDULER
    dtell(DEBUGGER, "NextState: " + nextstate + ".\n");
#endif
    if (ctime && member(ctime, newstate) < 0 && member(ctime, nextstate) >= 0)
    // lanzamos el call_out para informar de cuando quede un minuto para cerrar
    {
#ifdef DEBUG_SCHEDULER
        dtell(DEBUGGER,DEB_NAME + ". Hago call_out para informar del inminente cierre: " + (QueryServer()->TimeLeft() - TIME_TO_INFORM) + ".\n");
#endif
        while(remove_call_out("inform_close") != -1);
        _informed = 0;
        call_out("inform_close", QueryServer()->TimeLeft() - TIME_TO_INFORM);
    }

    if (!ismain && pMainRoom)
    // notificamos a MainRoom y que ella se encargue
    {
        object mr = load_object(resolve_file(pMainRoom));
#ifdef DEBUG_SCHEDULER
        dtell(DEBUGGER, "Voy a notificar (" + DEB_NAME + "), a " + pMainRoom + " de que el estado es " + newstate + ".\n");
#endif
        if (!mr)
        {
#ifdef DEBUG_SCHEDULER
            dtell(DEBUGGER, "No se pudo cargar " + pMainRoom + ".\n");
#endif
            processing = 0;
            return pRoomState;
        }
        mr->CheckState(newstate, 0, TO, silent);
        if (pRoomState == S_UNKNOWN) pRoomState = S_OPENED;
        processing = 0;
        return pRoomState;
    }
#ifdef DEBUG_SCHEDULER
    dtell(DEBUGGER, "Busco call_outs en " + DEB_NAME + ".\n");
#endif
    if (find_call_out("ThrowOutPeople") != -1
        || find_call_out("OpenRoom") != -1
        || find_call_out("CloseRoom") != -1)
    {
        processing = 0;
        return pRoomState;
    }
    fuerahorario = pCloseTime && sizeof(pCloseTime) && member(pCloseTime, newstate) >= 0;
#ifdef DEBUG_SCHEDULER
    dtell(DEBUGGER, (fuerahorario ? "Está " : "No está") + " fuera de horario.\n");
#endif
    if (pRoomState == S_OPENED && fuerahorario)
    // es hora de cerrar
    {
#ifdef DEBUG_SCHEDULER
        dtell(DEBUGGER, "¡Voy a cerrar!\n");
#endif
        ThrowOutPeople(silent, from, from_silent);
#ifdef DEBUG_SCHEDULER
        dtell(DEBUGGER, "Ya he ejecutado ThrowOutPeople en " + DEB_NAME + " y ahora devuelvo el estado de esta room, que se ha quedado en " + pRoomState + ".\n");
#endif
        processing = 0;
        return pRoomState;
    }
    else if ((pRoomState == S_CLOSED || pRoomState == S_UNKNOWN) && !fuerahorario)
    // es hora de abrir
    {
#ifdef DEBUG_SCHEDULER
        dtell(DEBUGGER, "Voy a abrir " + DEB_NAME + ".\n");
#endif
        if (ismain && pAssociatedRooms)
        {
#ifdef DEBUG_SCHEDULER
            dtell(DEBUGGER, "pAssociatedRooms para abrir es: " + sprintf("%O", pAssociatedRooms) + ".\n");
#endif
            foreach(string room:pAssociatedRooms)
            {
                object hab;
                if (hab = load_object(resolve_file(room)))
                {
#ifdef DEBUG_SCHEDULER
                    dtell(DEBUGGER, "Voy a abrir " + DEB_ONAME(hab) + ".\n");
#endif
                    if (hab == from) hab->OpenRoom(from_silent);
                    else hab->OpenRoom(silent);
                }
#ifdef DEBUG_SCHEDULER
                else
                {
                    dtell(DEBUGGER, "No se encontró " + room + ".\n");
                }
#endif
            }
        }
        OpenRoom(silent);
        processing = 0;
        return pRoomState;
    }
    if (fuerahorario && pRoomState == S_UNKNOWN)
    {
#ifdef DEBUG_SCHEDULER
        dtell(DEBUGGER, DEB_NAME + " es desconocida, así que se cierra.\n");
#endif
        pRoomState = S_CLOSED;
        if (pAssociatedRooms)
        {
            foreach(string room:pAssociatedRooms)
            {
                object hab;
                if (hab = load_object(resolve_file(room)))
                {
                    if (hab == from) hab->CloseRoom(from_silent);
                    else hab->CloseRoom(silent);
                }
            }
        }
        processing = 0;
        return pRoomState;
    }
    if (from && from->QueryRoomState(1) != pRoomState)
    // no debería ocurrir esto, segúramente la otra se ha recargado o algo
    {
        from->SetRoomState(pRoomState);
    }

    processing = 0;
    return pRoomState;
}

public void reset()
{
#ifdef DEBUG_SCHEDULER
    dtell(DEBUGGER, "Soy reset!\n");
#endif
    ::reset();
    CheckState(QueryDayState(), 0);
}

public void NotifyDayStateChange(mixed data, int newstate)
{
#ifdef DEBUG_SCHEDULER
    dtell(DEBUGGER, "Soy NotifyDayStateChange.\n");
#endif
    ::NotifyDayStateChange(data, newstate);
    CheckState(newstate, 0);
}

// ----------------------------------------------------------------------------

create()
{
    ::create();
    pNoSchedulerObject = 1;
}
