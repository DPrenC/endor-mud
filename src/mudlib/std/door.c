/**
 * /std/door
 * objeto para almacenar el estado de las puertas de comunicación entre dos habitaciones
*/

#include <door.h>
#include <materials.h>
#include <properties.h>
#include <rooms.h>
#include <sounds.h>
#include <scheduler.h>

inherit "/std/base";

/* variables de control */

private nosave int pDoorState, pDoorDefaultState; // 1 abierta, 0 cerrada
private nosave int pDoorLockState, pDoorDefaultLockState;
// 1 para cerradura abierta, 0 para cerrada
private nosave int pDoorDefaultInReset = 1;
// controla si reseteará el estado por defecto ´de la puerta en cada reset de la habitación
private int pMaterial; // material de la puerta
private nosave int *pDoorCloseTime; // Horas en las que la puerta estará cerrada
private nosave int pDoorStateChangedByUser;
// si el estado ha sido cambiado luego de la creación de la puerta
private nosave mixed *pDoorNoleaveMsg; // mensaje que se muestra cuando el player se da contra ella
private nosave mixed *pDoorOpenMsg; // mensaje para cuando se abre la puerta
private nosave mixed *pDoorCloseMsg; // mensaje para cuando se cierra la puerta
private nosave mixed *pDoorCantOpenMsg; // cuando intenta abrirla pero está bloqueada
private nosave mixed *pDoorUnlockMsg, *pDoorLockMsg;
// mensajes de bloqueo y desbloqueo de cerraduras
private nosave mixed *pDoorCantUnlockMsg, *pDoorCantLockMsg;
// cuando intenta bloquear o desbloquear la puerta con un objeto no válido
private nosave mixed pDoorKnockMsg; // cuando se llama a la puerta
private nosave mapping pIds = ([]); // ids de la puerta
private nosave mapping pShort = ([]), pLong = ([]); // descripción corta y larga
private nosave int pGender; // género de la puerta
private nosave mapping pDoorKey = ([]); // seguridad de la puerta
private nosave int pDoorTransparency; // 1 para transparente, 0 para opaca.
private nosave mixed *pDoorTransparencyMsg; // si la puerta es transparente, el mensaje que se verá al otro lado
private nosave closure pDoorChangeStateFunction; // Función especial para abrir o cerrar la puerta
private nosave closure pDoorChangeLockFunction; // función especial para bloquear o desbloquear la puerta
private nosave string pDoorRoom1, pDoorRoom2; // habitaciones a las que da esta puerta
private nosave mapping pDoorRoom1Closures, pDoorRoom2Closures; // propiedades closures de cada habitación
private nosave string pDoorOpenSound; // 0 sin sonido, string con el sonido al abrir.
private nosave string pDoorCloseSound; // 0 sin sonido, string con el sonido al cerrar.
private nosave string pDoorUnlockSound; // 0 sin sonido, string con el sonido para desbloquear
private nosave string pDoorLockSound; // 0 sin sonido, string con el sonido para bloquear
private nosave string pDoorHitSound; // 0 sin sonido, string con el sonido al golpear la puerta cerrada
private nosave string pDoorKnockSound; // lo que suena cuando llaman a la puerta

/* Funciones varias */

public string SetDoorRoom1(string ob)
{
    if (ob && pDoorRoom2 && ob == pDoorRoom2)
    {
        return raise_error("No se puede ajustar DoorRoom1 con el mismo objeto que DoorRoom2.\n"), 0;
    }
    pDoorRoom1 = ob;
    return ob;
}

public string QueryDoorRoom1() { return pDoorRoom1; }

public varargs object QueryDoorRoom1Ob(int force_load)
{
    if (!pDoorRoom1) return 0;
    if (!force_load) return find_object(pDoorRoom1);
    return load_object(pDoorRoom1);
}

public string SetDoorRoom2(string ob)
{
    if (ob && pDoorRoom1 && ob == pDoorRoom1)
    {
        return raise_error("No se puede ajustar DoorRoom2 con el mismo objeto que DoorRoom1.\n"), 0;
    }
    pDoorRoom2 = ob;
    return ob;
}

public string QueryDoorRoom2() { return pDoorRoom2; }

public varargs object QueryDoorRoom2Ob(int force_load)
{
    if (!pDoorRoom2) return 0;
    if (!force_load) return find_object(pDoorRoom2);
    return load_object(pDoorRoom2);
}

public mapping SetDoorRoom1Closures(mapping p) { return pDoorRoom1Closures = p; }
public mapping QueryDoorRoom1Closures() { return pDoorRoom1Closures; }

public mapping SetDoorRoom2Closures(mapping p) { return pDoorRoom2Closures = p; }
public mapping QueryDoorRoom2Closures() { return pDoorRoom2Closures; }



private void _valid_room(mixed room)
{
    string ruta;
    if (!room || (!stringp(room) && !objectp(room)))
    {
        return raise_error("No se ha pasado ninguna habitación a validar.\n");
    }

    if (stringp(room)) ruta = room;
    else ruta = object_name(room);
    if (!pDoorRoom2 && !pDoorRoom1) return;
        if (ruta != pDoorRoom1 && ruta != pDoorRoom2)
    {
        raise_error("La habitación especificada no se encuentra en ninguno de los lados de "
                    " esta puerta.\n");
    }
}


public mapping QueryDoorClosures(object ob)
{
    _valid_room(ob);
    return ob == find_object(pDoorRoom1) ? pDoorRoom1Closures : pDoorRoom2Closures;
}

public object QueryDoorRoom()
// intenta determinar la habitación desde la que se ha llamado a esta función
{
    object ob;
    if (member(inherit_list(ob = PO), ROOM + ".c") < 0)
    {
        if (!TP || !ob = environment(TP))
        {
            return raise_error("No se encontró la habitación de orígen de la llamada a la función"
                               "de ajuste para esta puerta.\n"), 0;
        }
    }
    _valid_room(object_name(ob));
    return ob;
}


public varargs object QueryDoorOtherSide(mixed arg1, mixed arg2)
// devuelve la habitación del otro lado de la puerta, de la
// habitación <ob> pasada como parámetro
{
    object ob = (objectp(arg1) && arg1) || (objectp(arg2) && arg2);
    int force_load = (intp(arg1) && arg1) ||(intp(arg2) && arg2);
    string other;

    if (!pDoorRoom1 || !pDoorRoom2)
    // si alguna de las dos no está aún definida, no se puede calcular
    {
        return raise_error("NO puedo calcular la habitación del otro lado de la puerta, si "
                           "pDoorRoom1 y pDoorRoom2 no están definidas.\n"), 0;
    }
    if (!ob) ob = QueryDoorRoom();
    else _valid_room(ob);
    other = object_name(ob) == pDoorRoom1 ? pDoorRoom2 : pDoorRoom1;
    if (!force_load) return find_object(other);
    return load_object(other);
}


/* funciones de manejo de propiedades */

public varargs int SetDoorState(int i, int byuser)
{
    if (pDoorLockState == DOOR_LOCKED) return 0;
    if (byuser) pDoorStateChangedByUser = 1;
    return pDoorState = i;
}
public varargs int QueryDoorState(int recalculate)
// obtiene el estado de la puerta. si recalculate está a 0, solo devuelve la variable pDoorState.
// Si está a 1 y la puerta tiene horario de cierre, se comprobará si alguno de los dos lados de la puerta es scheduler, y si están
// cerrados, en cuyo caso, la puerta aparecerá como cerrada
{
    object unlado, otrolado, sch;
    int sch_st, sch_st_nocheck;
    if (!recalculate || (!pDoorCloseTime || !sizeof(pDoorCloseTime)))
    {
        return pDoorState;
    }

    unlado = QueryDoorRoom1Ob();
    otrolado = QueryDoorRoom2Ob();
    if (unlado && member(inherit_list(unlado), SCHEDULER_ROOM ".c") >= 0) sch = unlado;
    else if (otrolado && member(inherit_list(otrolado), SCHEDULER_ROOM ".c") >= 0) sch = otrolado;
    if (!sch)
    // se obtiene del horario del a propia puerta{
    {
        if (member(pDoorCloseTime, QueryDoorRoom()->QueryDayState()) < 0)
        {
            if (pDoorLockState == DOOR_LOCKED) pDoorLockState = DOOR_UNLOCKED;
            if (!pDoorStateChangedByUser) pDoorState = DOOR_OPENED;
            else return pDoorState;
        }
        else
        // la puerta debería estar cerrada
        {
            pDoorState = DOOR_CLOSED;
            pDoorLockState = DOOR_LOCKED;
            pDoorStateChangedByUser = 0;
            return pDoorState;
        }
    }
    if (sch)
    // el lado scheduler está cargado, a´si que se saca de aquí
    {
        sch_st_nocheck = sch->QueryRoomState(1);
        sch_st = sch->QueryRoomState();
        if (sch_st_nocheck != sch_st && sch_st == DOOR_OPENED)
        // esto quiere decir que se acaba de abrir, así que desbloqueamos la puerta y la abrimos
        {
            pDoorLockState = DOOR_UNLOCKED;
            pDoorState = DOOR_OPENED;
            return pDoorState;
        }
        if (sch_st == S_CLOSED)
        // la tienda está cerrada
        {
            pDoorLockState = DOOR_LOCKED;
            pDoorState = DOOR_CLOSED;
            return pDoorState;
        }
        if (sch_st == S_OPENED && pDoorLockState == DOOR_LOCKED)
        {
            pDoorLockState = DOOR_UNLOCKED;
        }
    }
    return pDoorState;
}




public int SetDoorLockState(int i)
{
    // si está abierta, no se puede bloquear
    if (pDoorState == DOOR_OPENED && i == DOOR_LOCKED) return pDoorLockState;
    return pDoorLockState = i;
}
public int QueryDoorLockState() { return pDoorLockState; }

public int SetDoorDefaultState(int i) { return pDoorDefaultState = i; }
public int QueryDoorDefaultState() { return pDoorDefaultState; }

public int SetMaterial(int m) { return pMaterial = m; }
public int QueryMaterial() { return pMaterial; }
public int QueryDorStateChangedByUser() { return pDoorStateChangedByUser; }
public int *SetDoorCloseTime(mixed time)
{
    if (!pointerp(time) && !stringp(time) && time) return pDoorCloseTime;
    if (intp(time)) time = ({time});
    return pDoorCloseTime = time;
}
public int *QueryDoorCloseTime() { return copy(pDoorCloseTime); }

public int SetDoorDefaultLockState(int i) { return pDoorDefaultLockState = i; }
public int QueryDoorDefaultLockState() { return pDoorDefaultLockState; }

public int SetDoorDefaultInReset(int i) { return pDoorDefaultInReset = i; }
public int QueryDoorDefaultInReset() { return pDoorDefaultInReset; }

private mixed *_SetDoorMsg(mixed *var, mixed *msg)
{
    int n, i;
    if (!pointerp(msg) || !sizeof(msg)) return 0;
    if ((n = sizeof(msg)) > 3) msg = msg[..2];
    else if (n < 3) msg += (({({0, 0})}) * (3 - n));
    for (i=sizeof(msg);i--;)
    {
        if (!closurep(msg[i]) && !pointerp(msg[i]) && !stringp(msg[i])) return 0;
        if (!pointerp(msg[i])) msg[i] = ({msg[i]});
    }
    var = copy(msg);
    return var;
}
private mixed *_QueryDoorMsg(mixed *var)
{
    // si está descargada, la cargamos, pues muchos mensajes importantes para la puerta
    // pueden estar codificados en pDoorRoom1
    return copy(var);
}

public mixed *SetDoorNoleaveMsg(mixed *s) { return _SetDoorMsg(&pDoorNoleaveMsg, &s); }
public mixed *QueryDoorNoleaveMsg() { return _QueryDoorMsg(&pDoorNoleaveMsg); }

public mixed *SetDoorOpenMsg(mixed *s) { return _SetDoorMsg(&pDoorOpenMsg, &s); }
public mixed *QueryDoorOpenMsg() { return _QueryDoorMsg(&pDoorOpenMsg); }

public mixed *SetDoorCloseMsg(mixed *s) { return _SetDoorMsg(&pDoorCloseMsg, &s); }
public mixed *QueryDoorCloseMsg() { return _QueryDoorMsg(&pDoorCloseMsg); }

public mixed *SetDoorCantOpenMsg(mixed *s) { return _SetDoorMsg(&pDoorCantOpenMsg, &s); }
public mixed *QueryDoorCantOpenMsg() { return _QueryDoorMsg(&pDoorCantOpenMsg); }

public mixed *SetDoorUnlockMsg(mixed *s) { return _SetDoorMsg(&pDoorUnlockMsg, &s); }
public mixed *QueryDoorUnlockMsg() { return _QueryDoorMsg(&pDoorUnlockMsg); }

public mixed *SetDoorLockMsg(mixed *s) { return _SetDoorMsg(&pDoorLockMsg, &s); }
public mixed *QueryDoorLockMsg() { return _QueryDoorMsg(&pDoorLockMsg); }

public mixed *SetDoorCantUnlockMsg(mixed *s) { return _SetDoorMsg(&pDoorCantUnlockMsg, &s); }
public mixed *QueryDoorCantUnlockMsg() { return _QueryDoorMsg(&pDoorCantUnlockMsg); }

public mixed SetDoorKnockMsg(mixed s) { return _SetDoorMsg(&pDoorKnockMsg, &s); }
public mixed QueryDoorKnockMsg() { return _QueryDoorMsg(&pDoorKnockMsg); }

public mixed *SetDoorCantLockMsg(mixed *s) { return _SetDoorMsg(&pDoorCantLockMsg, &s); }
public mixed *QueryDoorCantLockMsg() { return _QueryDoorMsg(&pDoorCantLockMsg); }

public mixed *SetDoorTransparencyMsg(mixed *msg)
{
    if (!msg || !sizeof(msg)) return 0;
    if (!sizeof(msg)) return 0;
    else if (sizeof(msg) > 2) msg = msg[..<2];
    return pDoorTransparencyMsg = copy(msg);
}
public mixed *QueryDoorTransparencyMsg() { return (!pDoorTransparencyMsg ? 0 : copy(pDoorTransparencyMsg)); }


public int SetDoorTransparency(int i) { return pDoorTransparency = i; }
public int QueryDoorTransparency() { return pDoorTransparency; }


public closure SetDoorChangeStateFunction(closure func) { return pDoorChangeStateFunction = func; }
public closure QueryDoorChangeStateFunction()
{
    return pDoorChangeStateFunction;
}

public closure SetDoorChangeLockFunction(closure func) { return pDoorChangeLockFunction = func; }
public closure QueryDoorChangeLockFunction()
{
    return pDoorChangeLockFunction;
}

public int SetGender(int n) { return pGender = n; }
public int QueryGender() { return pGender; }
public string QueryGenderEndString() { return pGender == GENDER_FEMALE ? "a" : "o"; }

public string *SetIds(mixed arg1, mixed arg2)
{
    string room;
    mixed ids;
    string *aux;

    room = arg1 && arg2 ? arg1 : 0;
    ids = arg1 && arg2 ? arg2 : arg1;

    if (!ids) return 0;
    if (room) _valid_room(room);
    else room = object_name(QueryDoorRoom());
    return m_add(pIds, room, (stringp(ids) ? ({ids}) : (pointerp(ids) ? ids : 0)))[room];
}

public varargs string *QueryIds(string room)
{
    string *aux;
    if (room) _valid_room(room);
    else room = object_name(QueryDoorRoom());
    aux  = pIds[room];
    return aux;
}


public varargs string *AddId(mixed arg1, mixed arg2)
// añade la id en el lado de la puerta de la habitación especificada.
// Si no se especifica room, se intenta calcular automáticamente
{
    string room;
    mixed id;

    room = arg1 && arg2 ? arg1 : 0;
    id = arg1 && arg2 ? arg2: arg1;

    if (!id || (!stringp(id) && !pointerp(id))) return 0;
    if (!room) _valid_room(room);
    else room = object_name(QueryDoorRoom());
    return pIds[room] += m_indices(mkmapping((pIds[room] || ({})) + (pointerp(id) ? id : ({id}))));
}

public string *RemoveId(mixed arg1, mixed arg2)
{
    string room;
    mixed id;

    room = arg1 && arg2 ? arg1: 0;
    id = arg1 && arg2 ? arg2 : arg1;
    if (!id) return 0;
    if (room) _valid_room(room);
    else room = object_name(QueryDoorRoom());

    return pIds[room] -= pointerp(id) ? id : ({id});
}

public mixed SetShort(mixed arg1, mixed arg2)
// ajusta el Short de la puerta en el lado de la ruta especificada, en uno
// de los dos argumentos. Si no se pasa ruta, se intenta calcular automáticamente
{
    string room;
    mixed s;

    room = arg1 && arg2 ? arg1 : 0;
    s = arg1 && arg2 ? arg2 : arg1;
    if (!s) return 0;
    if (room) _valid_room(room);
    else room = object_name(QueryDoorRoom());

    return m_add(pShort, room, s)[room];
}
public varargs mixed QueryShort(mixed arg1, mixed arg2)
// si NotExec está a 1, se devuelve lo que contenga la variable pShort. De lo contrario,
// se devolverá el valor resultante de ejecutar la closure de la variable (si la hubiese),
// o se devolverá el valor de la misma en caso de ser una string.
// Todo esto, en el lado de la puerta definido por la ruta  pasada
// en uno de los dos argumentos. Si no se pasa la ruta, se intentará calcular.
{
    string room;
    int NotExec;

    room = stringp(arg1) && arg1 || stringp(arg2) && arg2;
    NotExec = intp(arg1) && arg1 || intp(arg2) && arg2;

    if (room) _valid_room(room);
    else room = object_name(QueryDoorRoom());
    return NotExec ? pShort[room] : (string)funcall(pShort[room]);
}

public mixed SetLong(mixed arg1, mixed arg2)
// Ajusta el Long del lado de la puerta pasado en el primer parámetro.
// De no pasarse más que un parámetro, se considerará arg1 como el long de la puerta, y se
// considerará como lado, al orígen de la llamada a esta función
{
    string room;
    mixed s;

    room = arg1 && arg2 ? arg1 : 0;
    s = arg1 && arg2 ? arg2: arg1;

    if (!s) return 0;
    if (room) _valid_room(room);
    else room = object_name(QueryDoorRoom());

    return m_add(pLong, room, s)[room];
}

public varargs mixed QueryLong(mixed arg1, mixed arg2)
// si NotExec está a 1, se devuelve lo que contenga la variable pLong. De lo contrario,
// se devolverá el valor resultante de ejecutar la closure de la variable (si la hubiese),
// o se devolverá el valor de la misma en caso de ser una string. En caso de no
// pasarse la variable NotExec, se incluirá en el resultado el mensaje de si
// la puerta está abierta o cerrada.
// Todo esto, en el lado de la puerta especificado por la ruta de la habitación pasada como uno
// de los dos argumentos. Si no se pasa ruta, se intentará calcular.
{
    string room;
    int NotExec;

    room = stringp(arg1) && arg1 || stringp(arg2) && arg2;
    NotExec = intp(arg1) && arg1 || intp(arg2) && arg2;

    if (room) _valid_room(room);
    else room = object_name(QueryDoorRoom());

    return NotExec ? pLong[room] : (string)funcall(pLong[room]) + "Está " +
                             (pDoorState == DOOR_OPENED ? "abiert" : "cerrad") +
                             QueryGenderEndString() + ".\n";
}


public string SetDoorKey(mixed arg1, mixed arg2)
// Ajusta la clave string para la cerradura de la puerta.
// Si esta propiedad está definida, se asume que la puerta tiene cerradura.
// Para abrirla, debe introducirse un objeto, que tenga como alguna ID la clave introducida aquí.
// Esta clave se ajustará al lado de la puerta especificado por laruta de la  habitación pasada como
// uno de los dos argumentos. Si no se pasa ruta, se intentará calcular.
{
    string room;
    string k;

    room = arg1 && arg2 ? arg1 : 0;
    k = arg1 && arg2 ? arg2 : arg1;

    if (!k) return 0;
    if (room) _valid_room(room);
    else room = object_name(QueryDoorRoom());

    return m_add(pDoorKey, room, k)[room];
}

// sonido al abrir la puerta
public string SetDoorOpenSound(string sound) { return pDoorOpenSound = sound; }
public string QueryDoorOpenSound() { return pDoorOpenSound; }
// Sonido al cerrar la puerta
public string SetDoorCloseSound(string sound) { return pDoorCloseSound = sound; }
public string QueryDoorCloseSound() { return pDoorCloseSound; }

// sonido al bloquear la puerta
public string SetDoorLockSound(string sound) { return pDoorLockSound = sound; }
public string QueryDoorLockSound() { return pDoorLockSound; }

// sonido al desbloquear la puerta
public string SetDoorUnlockSound(string sound) { return pDoorUnlockSound = sound; }
public string QueryDoorUnlockSound() { return pDoorUnlockSound; }

// Sonido al estemparte contra la puerta
public string SetDoorHitSound(string sound) { return pDoorHitSound = sound; }
public string QueryDoorHitSound(string sound) { return pDoorHitSound; }

public string SetDoorKnockSound(string s) { return pDoorKnockSound = s; }
public string QueryDoorKnockSound() { return pDoorKnockSound; }



public varargs string QueryDoorKey(string room)
{
    if (room) _valid_room(room);
    else room = object_name(QueryDoorRoom());
    return pDoorKey[room];
}

/* borrados y clean_up */

public int CantRemove()
{
    if (   (pDoorRoom1 && find_object(pDoorRoom1)
        && member(m_values(pDoorRoom1->ListExitsDoor(), EXIT_DOOR), TO) >= 0)
        || (pDoorRoom2 && find_object(pDoorRoom2)
        && member(m_values(pDoorRoom2->ListExitsDoor(), EXIT_DOOR), TO) >= 0))
    // si la puerta tiene alguna habitación asignada, y esta está cargada, además de
    // tener a esta puerta en alguna de sus salidas, no podemos borrarla.
    {
        return 1;
    }
    return 0;
}

public int clean_up(int ref)
{
    log_file("DOOR_REMOVED", ctime() + ": " + object_name(PO || TP) + " llama a clean_up en " + object_name(TO) + ".\n");
    if (CantRemove())
    {
        log_file("DOOR_REMOVED", sprintf("%-76=s", "No se borra pues pDoorRoom1 (" + pDoorRoom1 + ") " + (pDoorRoom1 && find_object(pDoorRoom1) ? "está" : "no está") + " cargada, y pDoorRoom2 (" + pDoorRoom2 + "), " + (pDoorRoom2 && find_object(pDoorRoom2) ? "está" : "no está") + " cargada.\n"));
        return 1;
    }
    return ::clean_up(ref);
}

create()
{
    ::create();
    pDoorOpenSound = SOUND_PUERTAS("abrir_puerta");
    pDoorCloseSound = SOUND_PUERTAS("cerrar_puerta");
    pDoorLockSound = SOUND_PUERTAS("cerradura");
    pDoorUnlockSound = SOUND_PUERTAS("cerradura");
    pDoorHitSound = SOUND_PUERTAS("golpe_madera");
    pDoorKnockSound = SOUND_PUERTAS("llamar_puerta_madera");
    pMaterial = M_MADERA;
}

public int remove()
{
    //log_file("DOOR_REMOVED", sprintf("%-76=s", ctime() + ". " + object_name(PO ||TP) + " llama a remove en " + object_name(TO) + ". Me borro.\n"));
    return ::remove();
}

