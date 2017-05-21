/* ENDOR-MUD'/std/room/exits.c'*/

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "/secure/wizlevels.h"
#include <door.h>
#include <messages.h>
#include <search.h>
#include <sounds.h>

/* --- Definiciones de Uso Propio --- */

#define NUMBER(x) ({"dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve", "diez"})[x-2]



/* --- Pre-Definiciones --- */

public varargs object *AddItem(mixed file, int refr,
                   mixed xarg1, mixed xarg2, mixed xarg3); // /std/room/items.c
public varargs int DoExplore( mixed arg ); // /std/room/description
public void RemoveExit(mixed *dir); // forward


/* --- Variables Globales --- */


/* Pexits contiene todos los datos de una salida. La clave es la dirección
   cardinal. Los valores sucesivos de cada fila son: ruta de destino (o una closure),
   el objeto puerta (o 0 si no tiene), flag de salida obvia u oculta, y
   tamaño de la salida
*/
private static mapping Pexits, Pcmds;
private static string Pdefmsg;
private static mapping Pnowaymsgs;

/* salidas */

/* --- Funciones de Uso Interno --- */

// Func: _exits_data() -> Devuelve un mapping con los datos especificados en
// la entrada. El mapping tiene formato de Pexits.
//
private void _exits_data( string dir, string dest, object door, int hidden,
                          int size, mapping rc )
{
   rc[dir, EXIT_DEST] = dest;
   rc[dir, EXIT_DOOR] = door;
   rc[dir, EXIT_HIDDEN] = hidden;
   rc[dir, EXIT_SIZE] = size;
 }

// Func: _exits_dest() -> Devuelve un mapping con sólo índice y destino
// correspondientes a los datos de entrada.
//
private void _exits_dest( string dir, string dest, object door, int hidden,
                          int size, mapping rc )
{
    rc[dir, EXIT_DEST] = dest;
}

/* --- Funciones de Uso Público --- */

// Func: QueryExits() -> Devuelve TODAS las salidas con TODA su información.
//
public mapping QueryExits() { return copy(Pexits); }

// Func: SetExits() -> Cambia el valor interno de Pexits por el de e y
// devuelve el resultado. e debe contener todos los datos de las salidas:
// dirección, destino, puerta (o 0), oculta y tamaño.
//
public mapping SetExits( mapping e)
{
    if (e && widthof(e) != EXIT_COUNT)
    {
        raise_error("El número de columnas del mapping de salidas no es válido. Se "
                    "esperaban " + EXIT_COUNT + ".\n");
        return 0;
    }
    return Pexits = e;
}



// Func: QueryExitsDest() -> Devuelve TODAS las salidas, pero sólamente el
// destino junto con la dirección.
//
public mapping QueryExitsDest()
{
    mapping rc;
    if( !Pexits ) return ([]);

    rc = m_allocate( sizeof( Pexits ), 1 );
    walk_mapping( Pexits, SF(_exits_dest), &rc );
    return rc || ([]);
}

// Func: SetExitsDest() -> Cambia el valor interno de Pexits por el de d
// y devuelve el resultado. d sólo puede contener un mapping de direcciones
// con sus destinos.
//
public mapping SetExitsDest( mapping d )
{
    if (!d || !sizeof(d)) return Pexits = 0;
    Pexits = m_allocate( sizeof( d ), 1 );
    walk_mapping( d, SF(_exits_dest), &Pexits );
    return Pexits;
}

// Func: QueryPlainExits() -> Sólo devuelve aquellas salidas libres de datos
// extra, es decir, aquellas sin puerta, no ocultas, sin función de llamada y
// con tamaño genérico. Sólo devuelve la dirección y destino de éstas.
//
public mapping QueryPlainExits()
{
    if (!Pexits ||!sizeof(Pexits)) return 0;
    return filter(Pexits,
                  (:   !closurep($2[EXIT_DEST]) && !$2[EXIT_DOOR] && !$2[EXIT_HIDDEN]
                  && $2[EXIT_SIZE] == P_SIZE_GENERIC:));
}


// Func: QueryExit() -> Devuelve TODA la información referente a la salida
// especificada en dir.
//
public mapping QueryExit( string dir )
{
    if(!Pexits ) return 0;
    return ([dir: Pexits[dir, EXIT_DEST]; Pexits[dir, EXIT_DOOR];
                  Pexits[dir, EXIT_HIDDEN]; Pexits[dir, EXIT_SIZE]]);
}

// Func: QueryExitSize() -> Devuelve el tamaño de la salida exit.
//
public int QueryExitSize( string exit )
{
    // Si no existe la salida, no hay tamaño definido. Y si no hay info extra
    // sobre la salida, tampoco.

    if (!Pexits || !member(Pexits, exit)) return 0;
    return Pexits[exit, EXIT_SIZE];
}

// Func: SetExitSize() -> Cambia el tamaño de la salida exit por el contenido
// en size y devuelve el resultado.
//
public int SetExitSize( string exit, int size )
{
    // Si no hay salidas, no existe la salida y no se puede cambiar el tamaño.
    // Y si la salida no existe, tampoco.

    if( !Pexits || !member(Pexits, exit ) ) return 0;
    // Ajustamos el tamaño introducido dentro de los límites.
    if( size < P_SIZE_MIN ) size = P_SIZE_MIN;
    if( size > P_SIZE_MAX ) size = P_SIZE_MAX;

    // Cambiamos el tamaño de la salida en el mapping de salidas.
    Pexits[exit, EXIT_SIZE] = size;
    return size;
}

// Func: AddExit() -> Añade una salida en la dirección dir, con destino dest
// y tamaño size (esto último se puede omitir, tomándose por defecto el
// tamaño genérico)
//
public varargs void AddExit( mixed dir, mixed dest, int size )
{
    if( stringp( dest ) ) dest = resolve_file( dest );
    if( !stringp( dest ) && !closurep( dest ) )
    {
        return raise_error("Tipo ilegal en argumento 2 de AddExit(). Sólo se admite "
                           "string o closure.\n" );
    }
    if( !pointerp( dir ) ) dir = ({ dir });

    foreach(mixed exit:dir)
    {
        if (mappingp(Pexits) && Pexits[exit, EXIT_DOOR])
        {
            return raise_error( "No se puede reemplazar la salida " + exit +
                ". Existe una puerta vinculada a esta salida.\n");
        }
        RemoveExit(exit);
        if( !stringp(exit))
        {
            return raise_error("Tipo ilegal en argumento 1 de AddExit(). "
                "Sólo se admite string o array de strings.\n");
        }
        if(!Pexits) Pexits = ([]);
        Pexits += ([exit:dest; 0; 0; size]);
    }
}

// Func: RemoveExit() -> Borra la(s) salida(s) dir.
//
public void RemoveExit( mixed *dir)
{
    if (!Pexits ||!sizeof(Pexits)) return;
    if (!pointerp(dir)) dir = ({dir});
    foreach(string exit:dir)
    {
        m_delete(Pexits, exit);
    }
}

// Func: HideExit() -> Oculta o desvela la(s) salida(s) dirs, dependiendo del
// valor new.
// Devuelve 1 en caso de éxito, 0 en caso de error.
//
public int HideExit( mixed *dirs, int new )
{
    int ok = 1;
    if( !Pexits ) return 0;
    if( !pointerp( dirs ) ) dirs = ({dirs});
    // comprobamos por cada salida si no existe o si tiene puerta, en cuyo caso,
    // no hacemos nada.
    filter(dirs, (:member(Pexits, $1) && !Pexits[$1, EXIT_DOOR] ?
                   Pexits[$1, EXIT_HIDDEN] = $2 : $3 = 0:), new, &ok);
    return ok;
}

// Func: map_brief_exit() -> Devuelve la forma abreviada de la salida exit
// si ésta es una de las conocidas. Si no, devuelve exit.
//
public string map_brief_exit(mixed exit)
{
    string salida, res;
    int cerrada;
    if (pointerp(exit))
    {
        salida = exit[0];
        cerrada = 1;
    }
    else salida = exit;

    switch( salida)
    {
        case "norte":
        case "sur":
        case "oeste" :
        case "este" :
             res = salida[0..0];
             break;
        case "arriba": res = "ar"; break;
        case "abajo": res = "ab"; break;
        case "suroeste": res = "so"; break;
        case "noroeste": res = "no"; break;
        case "sureste": res = "se"; break;
        case "noreste": res = "ne"; break;
        default: res = salida; break;
    }
    return res + (cerrada ? "(/)" : "");
}

// Func: map_normal_exit() -> Devuelve la salida normal de una salida simplificada
public string map_normal_exit(string exit)
{
    if (!exit) return 0;
    switch(exit)
    {
        case "s" : return "sur"; break;
        case "n": return "norte"; break;
        case "e": return "este"; break;
        case "o": return "oeste"; break;
        case "se": return "sureste"; break;
        case "so": return "suroeste"; break;
        case "ne": return "noreste"; break;
        case "no": return "noroeste"; break;
        case "ar": return "arriba"; break;
        case "ab": return "abajo"; break;
    }
    return exit;
}

// Func: ReverseExit --> Da la vuelta a una salida, sólo por su nombre: arriba abajo, abajo arriba, ETC.
public string ReverseExit(string exit)
{
    if (!exit) return 0;
    if (strlen(exit) <=2) exit = map_normal_exit(exit);
    switch(exit)
    {
        case "norte": return "sur"; break;
        case "sur": return "norte"; break;
        case "este": return "oeste"; break;
        case "oeste": return "este"; break;
        case "sureste": return "noroeste"; break;
        case "suroeste": return "noreste"; break;
        case "noroeste": return "sureste"; break;
        case "nordeste": return "suroeste"; break;
        case "arriba": return "abajo"; break;
        case "abajo": return "ab"; break;
        case "dentro": return "fuera"; break;
        case "fuera": return "dentro"; break;
    }
    return 0;
}



// Func: BackExit --> Devuelve la salida de vuelta a la introducida (si se conoce.
public string BackExit(string exit)
{
    object dest;
    mapping d_exits;
    mixed exit_to;
    string msg, reverse;

    exit = map_normal_exit(exit); // la normalizamos
    if (!exit_to = m_values(QueryExit(exit), EXIT_DEST)[0])
    // no puedo encontrar la habitación a la que da esta salida
    {
        return 0;
    }
    if (closurep(exit_to))
    // es una closure, así que es imposible saber a donde te mandará esta salida
    // por consiguiente, y apostando por la buena fe del que la haya programado, consideraremos
    // aquello de que si vamos a una salida hacia el norte, se volverá hacia el sur
    {
        return ReverseExit(exit);
    }
    if (msg = catch(dest = load_object(exit_to)))
    // error al cargar la habitación destino
    {
        raise_error("Error en BackExit. " + msg + ".\n");
    }

    // tenemos la habitación destino cargada. Vamos a ver qué salida corresponde a esta:
    d_exits = filter(dest->QueryExits(), (:$2[EXIT_DEST] == object_name():));
    if (!sizeof(d_exits))
    // no la hemos encontrado. veamos si existe una salida con el nombre reverso a <exit>
    {
        if (dest->QueryExits()[(reverse = ReverseExit(exit))]) return reverse;
        else return 0;
    }
    return m_indices(d_exits)[0];
}

// Func: MakeExitString() -> Devuelve la cadena con las salidas dependiendo
// de los parámetros de entrada.
//
public varargs string MakeExitString( int brief, string *dirs, int hidden )
{
    int s;
    string str;


    dirs = sort_array(dirs, (:member(({"norte", "noreste", "este", "sureste", "sur",
                                       "suroeste", "oeste", "noroeste", "arriba", "abajo",
                                       "entrar", "salir" }), (pointerp($2) ? $2[0] : $2)) >= 0:));

    if( brief )
    {
        dirs = map( dirs, SF(map_brief_exit ));
        return implode( dirs, "," );
    }

    dirs = map(dirs, (:(pointerp($1) ? $1[0] + " (cerrada por " + $1[1] + ")" : $1):));
    switch( s = sizeof( dirs))
    {
        case 0: return (!hidden ? "No existe ninguna salida obvia.\n" :
                                  "No hay salidas ocultas.\n");
        case 1:
            return (!hidden ? "Hay una salida obvia: " : "OCULTA: ") + dirs[0] + ".\n";
        case 2..10:
             str = (!hidden ? "Hay " + NUMBER(s) + " salidas obvias: " :
                              "OCULTAS [" + NUMBER(s) + "]: ");
             break;
        default:
             str = (!hidden ? "Hay muchas salidas obvias: " : "OCULTAS: ");
    }
    return str+ implode_list(dirs) + ".\n";
}

// Func: ExitList() -> Devuelve un vector de 2 vectores con las salidas
// visibles y ocultas respectivamente. Si una salida tiene puerta y esta está cerrada,
// el dir de la salida será un vector en el que el primer valor es la dirección, y el segundo
// el short de esa puerta
//
public mixed *ExitList()
{
    string *dirs, *hidden = ({});
    int i;

    if (!Pexits) return 0;
    dirs = map(m_indices(Pexits),
               (:Pexits[$1, EXIT_DOOR] && Pexits[$1, EXIT_DOOR]->QueryDoorState(1) == DOOR_CLOSED ?
                ({$1, Pexits[$1, EXIT_DOOR]->QueryShort(object_name())}) : $1:));
    dirs = filter(dirs, (:if (Pexits[(pointerp($1) ? $1[0] : $1), EXIT_HIDDEN])
                          {
                              $2 += ({$1});
                              return 0;
                          }
                          return 1;:), &hidden);
    return ({dirs, hidden});
}


// Func: Exits() -> Devuelve la cadena completa o breve de salidas,
// dependiendo de brief.
//
public varargs string Exits( int brief, object pl )
{
    string str = "";
    mixed *exits;

    if( !pl ) pl = TP;

    exits = ExitList();

    if((   (   IS_LEARNER( pl ) && !pl->Query( P_NOWIZ ) )
            || LSTATE_GHOST == pl->Query( P_LSTATE))
        && exits && sizeof( exits[1]))
    {
        str = (brief ? "[]" : "") + MakeExitString( brief, exits[1], 1 );
    }
    return MakeExitString( brief, exits ? exits[0] : ({ }), 0 ) + str;
}

/* puertas */

/* --- funciones de uso público --- */

// func: ListExitsDoor() -> Devuelve un mapping con las salidas con puerta.
//
public mapping ListExitsDoor()
{
    return (Pexits ? filter(Pexits, (:$2[EXIT_DOOR]:)) : ([]));
}


// func: QueryOpenExits() -> Muestra todas las salidas abiertas
public mapping QueryOpenExits()
{
    return (Pexits ? filter(Pexits, (:!$2[EXIT_DOOR] || $2[EXIT_DOOR]->QueryDoorState() == DOOR_OPENED:)) : ([]));
}

// func: AddDoor() -> Añade una puerta a la salida especificada:
//
public varargs int AddDoor(string salida, mixed short, mixed long, mixed ids,
                           mixed arg1, mixed arg2, mixed arg3)
{
    object puerta, dest;
    mapping d_salidas, props;
    int nuevapuerta, gender;
    string key, msg, ruta_dest, obname;

#ifdef DEBUG_DOOR
    dtell("orome", "Añadiendo puerta: " + (stringp(short) ?short : (closurep(short) ? funcall(short) : "sin descripción corta") + ". Salida: " + salida + ". Habitación: " + object_name(TO) + ".\n");
#endif

    if (!salida) return raise_error("El parámetro salida es obligatorio.\n"), 0;
    if (short && (!stringp(short) && !closurep(short)))
    {
        return raise_error("La descripción corta debe ser una string o una closure.\n"), 0;
    }
    if (long && (!stringp(long) && !closurep(long)))
    {
        return raise_error("La descripción larga debe ser o una string o una closure.\n"), 0;
    }
    if (ids && (!pointerp(ids) && !stringp(ids)))
    {
        return raise_error("Las identificaciones de la puerta deben ser o una string, o "
                           "un array de strings.\n"), 0;
    }

    // ajustamos los argumentos extra:
    gender = intp(arg1) && arg1 || intp(arg2) && arg2 || intp(arg3) && arg3;
    key = stringp(arg1) && arg1 || stringp(arg2) && arg2 || stringp(arg3) && arg3;
    props = mappingp(arg1) && arg1 || mappingp(arg2) && arg2 || mappingp(arg3) && arg3;

    if (mappingp(props) && widthof(props) != 1)
    {
        return raise_error("El mapping de propiedades debe tener el formato propiedad:valor, "
                           "sin columnas adicionales.\n"), 1;
    }
    if (!props) props = ([]);
    if (!Pexits || !member(Pexits, salida))
    {
        return raise_error("No existe la salida " + salida + " a la que añadir la puerta.\n"), 0;
    }
    if (!stringp(Pexits[salida, EXIT_DEST]))
    {
        return raise_error("No se puede añadir una puerta a una salida asociada a una "
                           "función closure.\n"), 0;
    }

    if (Pexits[salida, EXIT_DOOR])
    {
        return raise_error("Ya hay una puerta en la salida " + salida + ".\n"), 0;
    }
    obname = object_name();
    dest = find_object(ruta_dest = Pexits[salida, EXIT_DEST]);
    if (dest)
    // la habitación destino está cargada, así que pillamos la puerta
    {
        // buscamos la salida correspondiente de la habitación destino a la actual.
        d_salidas = dest->QueryExits();
        d_salidas = filter(d_salidas, (:$2[EXIT_DEST] == $3:), obname);
        if (!sizeof(d_salidas))
        // no se encontró la salida de vuelta
        {
            return raise_error("No se encontró la salida de la habitación destino a la actual.\n"), 0;
        }
        if (sizeof(d_salidas) > 1)
        {
            return raise_error("Hay más de una salida en la habitación destino, que "
                               "apunta a la habitación actual.\n"), 0;
        }
        if (!puerta = m_values(d_salidas, EXIT_DOOR)[0])
        // No hay puerta en el otro lado
        {
            return raise_error("Aunque " + object_name(dest) + " está cargada, no se encontró "
                               "la puerta asociada a la salida de vuelta a esta habitación.\n"), 0;
        }
    }
    else
    // no está cargada, así que creamos la nueva puerta aquí
    {
#ifdef DEBUG_DOOR
        dtell("orome", "La puerta en " + obname + " es nueva!\n");
#endif
        nuevapuerta = 1;
        puerta = clone_object(DOOR_PATH);
    }
    if (nuevapuerta)
    {
        puerta->SetDoorRoom1(obname);
        puerta->SetDoorRoom2(ruta_dest);
    }
    if (stringp(short))
    {
        if (short[<1..<1] == "\n") short = short[..<2];
        if (short[<1..<1] == ".") short = short[..<2];
    }
    if (stringp(long))
    {
        if (long[<2..<1] != ".\n") long += ".\n";
    }

    // si hay parámetros adicionales como el short, el long y las ids, se colocan.
    // si no los hay y la puerta es nueva, se ponen por defecto. Si la puerta no es nueva,
    // en los casos en los que pueda haber una propiedad por lado, se ajustará la propiedad de
    // cada lado de la puerta.
    if (short)
    {
        puerta->SetShort(obname, short);
        if (!nuevapuerta && !puerta->QueryShort(ruta_dest, 1)) puerta->SetShort(ruta_dest, short);
    }
    else if (!nuevapuerta && puerta->QueryShort(ruta_dest, 1)) puerta->SetShort(obname, puerta->QueryShort(ruta_dest, 1));
    else
    {
        puerta->SetShort(obname, "una puerta");
        puerta->SetShort(ruta_dest, "una puerta");
    }

    if (long)
    {
        puerta->SetLong(obname, long);
        if (!nuevapuerta && !puerta->QueryLong(ruta_dest, 1)) puerta->SetLong(ruta_dest, long);
    }
    else if (!nuevapuerta && puerta->QueryLong(ruta_dest, 1)) puerta->SetLong(obname, puerta->QueryLong(ruta_dest, 1));
    else
    {
        puerta->SetLong(obname, "Es una puerta normal y corriente.\n");;
        puerta->SetLong(ruta_dest, "Es una puerta normal y corriente.\n");
    }

    if (ids)
    {
        puerta->SetIds(obname, ids);
        if (!nuevapuerta && !puerta->QueryIds(ruta_dest)) puerta->SetIds(ruta_dest, ids);
    }
    else if (!nuevapuerta && puerta->QueryIds(ruta_dest))
    {
        puerta->SetIds(obname, puerta->QueryIds(ruta_dest));
    }
    else
    {
        puerta->SetIds(obname, ({"puerta"}));
        puerta->SetIds(ruta_dest, ({"puerta"}));
    }


    if (gender) puerta->SetGender(gender);
    else if (nuevapuerta) puerta->SetGender(GENDER_FEMALE);


    if (key)
    {
        puerta->SetDoorKey(obname, key);
        if (!nuevapuerta && !puerta->QueryDoorKey(ruta_dest)) puerta->SetDoorKey(ruta_dest, key);
    }
    else if (!nuevapuerta && puerta->QueryDoorKey(ruta_dest)) puerta->SetDoorKey(obname, puerta->QueryDoorKey(ruta_dest));

    // ajustamos las propiedades extra:
    if (sizeof(props))
    {
        mapping props_closure;
        props_closure = filter(props, (:   closurep($2)
                                        || (   pointerp($2)
                                            && sizeof(filter($2, (:   closurep($1)
                                                                   || (   pointerp($1)
                                                                       && sizeof(filter($1, SF(closurep)))
                                                                      )
                                                                 :))))
                                      :));
        if (sizeof(props_closure))
        {
            if (nuevapuerta) puerta->SetDoorRoom1Closures(props_closure);
            else puerta->SetDoorRoom2Closures(props_closure);
        }
        if (nuevapuerta) puerta->SetProperties(props);
        if (member(props, P_DOOR_STATE)) puerta->SetDoorDefaultState(props[P_DOOR_STATE]);
        if (member(props, P_DOOR_LOCK_STATE))
        {
            puerta->SetDoorDefaultLockState(props[P_DOOR_LOCK_STATE]);
        }
    }
    Pexits[salida, EXIT_DOOR] = puerta;
    return 1;
}

private object *_FindObjectDoor(string id)
{
    mapping s_puertas = ListExitsDoor();
    object *puertas = sizeof(s_puertas) ? m_values(s_puertas, EXIT_DOOR) : ({});
    object *result;

    if (!sizeof(puertas)) return 0;
    result = filter(puertas, (:member($1->QueryIds() || ({}), $2) >= 0:), id);
    return result;
}

// func: FindDoor() -> dada una id, devuelve la puerta asociada.
// Si hay más de una puerta con la id especificada, devolverá -1. También se admiten
// salidas para identificar a una puerta, o una combinación de id y salida.
// si disable_exits está a 1, el uso de la salida como id no será tenida en cuenta.
//
public varargs mixed FindDoor(string id, int disable_exits)
{
    object *result;
    int num_puertas;
    string *palabras;
    if (!Pexits) return 0;
    if (   !disable_exits && member(m_indices(Pexits), id = map_normal_exit(id)) >= 0
        && Pexits[id, EXIT_DOOR])
    // hay una puerta en la salida <id>, así que es la que usamos
    {
        return Pexits[id, EXIT_DOOR];
    }
    result = _FindObjectDoor(id);
    if (!(num_puertas = sizeof(result)) && sizeof(palabras = explode(id, " ")))
    // comprobamos si está intentando buscar la puerta de cierta salida
    {
        string salida = palabras[<1];
        id = implode(palabras[..<2], " ");
        if (member(m_indices(Pexits), salida) < 0) return 0;
        result = _FindObjectDoor(id);
        if (!sizeof(result)) return 0;
        result = filter(result, (:$1 == Pexits[$2, EXIT_DOOR]:), salida);
        if (!sizeof(result)) return 0;
        return result[0];
    }

    if (num_puertas > 1) return -1;
    return result[0];
}


// func: FindExitDoor -> Dado un objeto puerta, devuelve la salida a la que está asociada
//
public string FindExitDoor(object door)
{
    int pos;
    if (!objectp(door)) return 0;
    pos = member(m_values(Pexits || ([]), EXIT_DOOR), door);
    return (pos == - 1 ? 0 : m_indices(Pexits)[pos]);
}

public varargs mixed _SendDoorMessages(mixed *mensajes, string salida, object puerta, int notify, mixed extra)
// Envía los mensajes contenidos en la variable que se le pasa como parámetro, al player,
// a la room y al destino.
{
    object other_room;
    mixed *msg;
    closure func;
    int val;

    if (sizeof(mensajes) != 3) return 0;
    // dependiendo de cada tipo de mensaje, vamos mirando qué tell_room o tell_object usar
    if (msg = mensajes[DOOR_MSG_ROOM])
    {
        if (sizeof(msg) == 1)
        // es un mensaje que no distingue entre ver y oir, solo se manda
        {
            tell_room(TO, regreplace((string)funcall(msg[0], puerta, salida, TO, extra),
                                     "@nombre@", CAP(TNAME), 0),({TP}));
        }
        else if (sizeof(msg) == 2 && msg[DOOR_MSG_SEE] && msg[DOOR_MSG_HEAR])
        // están ambos mensajes, así que hay alternativas si se ve o si solo se oye:
        {
            tell_room(TO, ({MSG_SEE,
                            regreplace((string)funcall(msg[DOOR_MSG_SEE], puerta, salida, TO, extra),
                                       "@nombre@", CAP(TNAME), 0),
                            ({MSG_HEAR,
                              regreplace((string)funcall(msg[DOOR_MSG_HEAR], puerta, salida, TO, extra),
                                          "@nombre@", CAP(TNAME), 0)})}),
                          ({TP}));
        }
        else
        // solo hay uno de los dos mensajes
        {
            val = msg[DOOR_MSG_SEE] ? DOOR_MSG_SEE : DOOR_MSG_HEAR;
            tell_room(TO, ({(val == DOOR_MSG_SEE ? MSG_SEE : MSG_HEAR),
                            regreplace((string)funcall(msg[val], puerta, salida, TO, extra),
                                       "@nombre@", CAP(TNAME), 0)}), ({TP}));
        }
    }

    if ((msg = mensajes[DOOR_MSG_DEST]) && (other_room = puerta->QueryDoorOtherSide(TO)))
    {
        if (sizeof(msg) == 1)
        // es un mensaje que no distingue entre ver y oir, solo se manda
        {
            tell_room(other_room, regreplace((string)funcall(msg[0], puerta, salida, TO, other_room, extra),
                                             "@nombre@", CAP(TNAME), 0));
        }
        else if (sizeof(msg) == 2 && msg[DOOR_MSG_SEE] && msg[DOOR_MSG_HEAR])
        // están ambos mensajes, así que hay alternativas si se ve o si solo se oye:
        {
            tell_room(other_room, ({MSG_SEE,
                                    regreplace((string)funcall(msg[DOOR_MSG_SEE], puerta, salida,
                                                               TO, other_room, extra),
                                                "@nombre@", CAP(TNAME), 0),
                                    ({MSG_HEAR,
                                      regreplace((string)funcall(msg[DOOR_MSG_HEAR], puerta, salida,
                                                                 TO, other_room, extra),
                                                  "@nombre@", CAP(TNAME), 0)})}));
        }
        else
        // solo hay uno de los dos mensajes
        {
            val = msg[DOOR_MSG_SEE] ? DOOR_MSG_SEE : DOOR_MSG_HEAR;
            tell_room(other_room, ({(val == DOOR_MSG_SEE ? MSG_SEE : MSG_HEAR),
                                    regreplace((string)funcall(msg[val], puerta, salida, TO, other_room,
                                                               extra),
                                                "@nombre@", CAP(TNAME), 0)}));
        }
    }

    // guardamos la closure para la función del player
    if (!msg = mensajes[DOOR_MSG_PLAYER]) return 1;
    if (sizeof(msg) == 1)
    // un sólo mensaje, así que no importa si se ve o se oye.
    // Aquí uso lambdas porque puede admitir las variables locales.
    // Las lambdas son un infierno. Básicamente lo que hago es un tell_object en el que
    // se manda al player el mensaje de la variable, ejecutándose la closure contenida en él
    // (si es una closure), o diréctamente la cadena que tenga guardada.
    {
        func = lambda(0, ({SF(tell_object), TP,
                           ({SF(regreplace), ({SF(to_string), ({SF(funcall), msg[0], puerta, salida, TO, extra})}),
                             "@nombre@", CAP(TNAME), 0})}));
    }
    else if (sizeof(msg) == 2 && msg[DOOR_MSG_SEE] && msg[DOOR_MSG_HEAR])
    // están los dos tipos de mensaje
    {
        /*
        func = lambda(0, ({SF(tell_object), TP,
                           quote(({MSG_SEE, regreplace((string)funcall(msg[DOOR_MSG_SEE],
                                                                       puerta, salida, TO, extra),
                                                       "@nombre@", CAP(TNAME), 0),
                                   ({MSG_HEAR, regreplace((string)funcall(msg[DOOR_MSG_HEAR],
                                                                          puerta, salida, TO, extra),
                                                          "@nombre@", CAP(TNAME), 0)})}))}));
        */
        func = lambda(0, ({SF(tell_object), TP, ({#'({, MSG_SEE, ({SF(regreplace), ({SF(to_string), ({SF(funcall), msg[DOOR_MSG_SEE], puerta, salida, TO, extra})}), "@nombre@", CAP(TNAME), 0}), ({#'({, MSG_HEAR, ({SF(regreplace), ({SF(to_string), ({SF(funcall), msg[DOOR_MSG_HEAR], puerta, salida, TO, extra})}), "@nombre@", CAP(TNAME), 0})})})}));
    }
    else
    // uno de los dos mensajes está a cero
    {
        val = (msg[DOOR_MSG_SEE] ? DOOR_MSG_SEE : DOOR_MSG_HEAR);
        func = lambda(0, ({SF(tell_object), TP, quote(({({SF(?), ({SF(==), val, DOOR_MSG_SEE}),
                                                          MSG_SEE, MSG_HEAR}),
                           ({SF(regreplace), ({SF(to_string), ({SF(funcall), msg[val], puerta,
                                                                salida, TO, extra})}), "@nombre@",
                             CAP(TNAME), 0})}))}));
    }
    if (notify == 1) return notify_fail(func);
    funcall(func);
    return 1;
}




public int fopen_close_door(string str)
{
    string accion = query_verb(), sonido;
    string salida, pshort, pgender;
    mixed puerta;
    object other_room;
    string *msg;


    if (!str) return notify_fail("¿" + CAP(accion) + " qué?\n");
    if (!puerta = FindDoor(str))
    {
        return notify_fail("No ves " + str + " que " + accion + ".\n");
    }
    if (puerta == -1)
    {
        return notify_fail("¿Qué " + str + " quieres " + accion + " exactamente?\n");
    }

    pshort = puerta->QueryShort(object_name());
    pgender = puerta->QueryGenderEndString();

    if (puerta->QueryDoorState() == (accion == "abrir" ? DOOR_OPENED : DOOR_CLOSED))
    // la puerta ya está como se supone que se intenta colocar
    {
        return notify_fail(CAP(pshort) + " ya está " +
                           (accion == "abrir" ? "abiert" : "cerrad") + pgender + ".\n");
    }
    salida = FindExitDoor(puerta);
    if (puerta->QueryDoorLockState() == DOOR_LOCKED && puerta->QueryDoorState() == DOOR_CLOSED)
    {
        if (!puerta->QueryDoorCantOpenMsg())
        {
            msg = ({({"Intentas abrir " + pshort + ", pero parece que está "
                      "cerrad" + pgender + " con llave.\n"}),
                        ({"@nombre@ intenta abrir " + pshort + ", pero parece que "
                        "está cerrad" + pgender + " con llave.\n",
                          "Escuchas un extraño ruido.\n"})});
            if (other_room = puerta->QueryDoorOtherSide(TO))
            {
                msg += ({({(puerta->QueryDoorTransparency() ?
                            "Ves como @nombre@ intenta abrir " + puerta->QueryShort(other_room) +
                            ", pero no lo consigue.\n" :
                            "Escuchas como alguien intenta abrir " + puerta->QueryShort(other_room) +
                            " sin mucho éxito.\n"),
                           "Escuchas un extraño ruido.\n"})});
            }
            else msg += ({0});
        }
        return _SendDoorMessages(puerta->QueryDoorCantOpenMsg() || msg,
                                 salida, puerta, 1);
    }

    if (puerta->QueryDoorChangeStateFunction())
    {
        if (!funcall(puerta->QueryDoorChangeStateFunction(), puerta, salida, accion, str)) return 0;
    }
    puerta->SetDoorState(accion == "abrir" ? DOOR_OPENED : DOOR_CLOSED, 1);
    if ((sonido = (accion == "abrir" ? puerta->QueryDoorOpenSound() : puerta->QueryDoorCloseSound())))
    {
        object lado;
        if (lado = puerta->QueryDoorRoom1Ob()) play_sound(lado, sonido);
        if (lado = puerta->QueryDoorRoom2Ob()) play_sound(lado, sonido);
    }
    if (   (accion == "abrir" && !puerta->QueryDoorOpenMsg())
        || (accion == "cerrar" && !puerta->QueryDoorCloseMsg()))
    {
        msg = ({({(accion == "abrir" ? "Abres" : "Cierras") + " " + pshort + ".\n"}),
                ({"@nombre@ " + (accion == "abrir" ? "abre" : "cierra") + " " + pshort + ".\n",
                  "Escuchas como se " + (accion == "abrir" ? "abre" : "cierra") + " una puerta.\n"})});
        if (other_room = puerta->QueryDoorOtherSide(TO))
        {
            msg += ({({(puerta->QueryDoorTransparency() ?
                        "Ves como @nombre@ " + (accion == "abrir" ? "abre" : "cierra") + " " +
                        puerta->QueryShort(other_room) + " desde el otro lado.\n" :
                        "Se " + (accion == "abrir" ? "abre" : "cierra") + " " +
                        puerta->QueryShort(other_room) + ".\n"),
                       "Escuchas " + (accion == "abrir" ? "abrirse" : "cerrarse") +
                       " una puerta.\n"})});
        }
        else msg += ({0});
    }
    return _SendDoorMessages(   (accion == "abrir" ? puerta->QueryDoorOpenMsg() : puerta->QueryDoorCloseMsg())
                             || msg, salida, puerta);
}

public int flock_unlock_door(string str)
{
    string accion = query_verb(), sonido;
    string pref = (accion == "desbloquear" ? "des" : "");
    string que, conque, salida, rshort, pshort;
    mixed puerta, res;
    string *msg;
    object other_room;


    if (!str)
    {
        return notify_fail("¿Qué es lo que quieres " + pref + "bloquear, y con qué?\n");
    }

    if (sscanf(str, "%s con %s", que, conque) != 2)
    {
        return notify_fail("¿" + CAP(pref + "bloquear qué, con qué?\n"));
    }

    puerta = FindDoor(que);
    if (!puerta)
    {
        return notify_fail("No encuentras " + str + " para " + pref + "bloquear.\n");
    }

    if (puerta == -1)
    {
        return notify_fail("¿Qué " + str + " quieres " + pref + "bloquear "
                           "exactamente?\n");
    }

    pshort = puerta->QueryShort(object_name());
    if (   !puerta->QueryDoorKey())
    {
        if (accion == "desbloquear")
        {
            return notify_fail(CAP(pshort) + " ya está desbloqueada.\n");
        }
        return notify_fail(CAP(pshort) + " no se puede bloquear.\n");
    }
    if (puerta->QueryDoorLockState() == (accion == "bloquear" ? DOOR_LOCKED : DOOR_UNLOCKED))
    // la puerta ya está abierta o cerrada. vamos, que la acción no tiene sentido
    {
        return notify_fail(CAP(pshort) + " ya está " + pref + "bloqueada.\n");
    }

    // si la puerta está abierta, no podemos bloquearla
    if (accion == "bloquear" && puerta->QueryDoorState() == DOOR_OPENED)
    {
        return notify_fail("Debes cerrar " + pshort + " antes de bloquearl" +
                           puerta->QueryGenderEndString() + ".\n");
    }
    // comprobamos si la llave es la correcta
    res = search(TP, conque, SEARCH_INV|SM_OBJECT);
    if (!res)
    {
        return notify_fail("No encuentras " + conque + " con lo que " + pref +
                           "bloquear " + pshort + ".\n");
    }
    if (pointerp(res)) res = res[0];
    rshort = res->QueryShort() || "algo";
    salida = FindExitDoor(puerta);
    if (member(res->QueryIds() || ({}), puerta->QueryDoorKey(object_name())) < 0)
    // no la puede bloquear / desbloquear
    {
        if (   (accion == "bloquear" && !puerta->QueryCantLockMsg())
            ||(accion == "desbloquear" && !puerta->QueryCantUnlockMsg()))
        {
            msg = ({({"Introduces " + rshort + " en la cerradura de " + pshort + ", pero no consigues " +
                      pref + "bloquearla.\n"}),
                    ({"@nombre@ introduce " + rshort + " en la cerradura de " + pshort + ", pero "
                      "parece que no consigue " + pref + "bloquearla.\n",
                      "Escuchas un extraño ruido.\n"})});
            if (other_room = puerta->QueryDoorOtherSide(TO))
            // la otra habitación está cargada
            {
                msg += ({({(puerta->QueryDoorTransparency() ?
                            "Ves como @nombre@ introduce algo en la cerradura de " +
                            puerta->QueryShort(other_room) + " desde el otro lado, pero parece que no ha "
                            "conseguido lo que quería.\n" :
                            "Escuchas un extraño ruido tras " + puerta->QueryShort(other_room) + ".\n"),
                           "Escuchas un extraño ruido.\n"})});
            }
            else msg += ({0});
        }
        return _SendDoorMessages((accion == "bloquear" ? puerta->QueryDoorCantUnlockMsg() :
                                  puerta->QueryDoorCantLockMsg()) || msg,
                                  salida, puerta, 1, (object)res);
    }
    // comprobamos si hay función preventiba para cambiar el estado de bloqueo
    if (puerta->QueryDoorChangeLockFunction())
    {
        if (!funcall(puerta->QueryDoorChangeLockFunction(), puerta, salida, accion, str, (object)res))
        {
            return 0;
        }
    }

    // realizamos la acción
    puerta->SetDoorLockState(accion == "bloquear" ? DOOR_LOCKED : DOOR_UNLOCKED);
    //sonido
    if (sonido = (accion == "bloquear" ? puerta->QueryDoorLockSound() : puerta->QueryDoorUnlockSound()))
    {
        object lado;
        if (lado = puerta->QueryDoorRoom1Ob()) play_sound(lado, sonido);
        if (lado = puerta->QueryDoorRoom2Ob()) play_sound(lado, sonido);
    }
    if (   (accion == "bloquear" && !puerta->QueryDoorLockMsg())
        || (accion == "desbloquear" && !puerta->QueryDoorUnlockMsg()))
    {
        msg = ({({"Introduces " + rshort + " en la cerradura de " + pshort + " y la " +
                  pref + "bloqueas.\n"}),
                ({"@nombre@ introduce " + rshort + " en la cerradura de " + pshort + " y la " +
                  pref + "bloquea.\n",
                  "Escuchas un extraño ruido.\n"})});
        if (other_room = puerta->QueryDoorOtherSide(TO))
        // la otra habitación está cargada
        {
            msg += ({({(puerta->QueryDoorTransparency() ?
                        "Ves como @nombre@ introduce " + rshort + " en la cerradura de " +
                        puerta->QueryShort(other_room) + ", y la " + pref + "bloquea.\n" :
                        "Escuchas un ¡Click! en la cerradura de " + puerta->QueryShort(other_room) +
                        ".\n"),
                       "Escuchas un suave ¡click!\n"})});
        }
        else msg += ({0});
    }
    return _SendDoorMessages((accion == "bloquear" ? puerta->QueryDoorLockMsg() :
                              puerta->QueryDoorUnlockMsg()) ||msg,
                             salida, puerta, 0, (object)res);
}

/* llamar a la puerta */

public int fknock(string str)
{
    mixed puerta, msg;
    string sonido, short, sgender;
    object other_room;

    if (!str) return notify_fail("llamar dónde?\n", NOTIFY_NOT_VALID);

    if (!(puerta = FindDoor(str)))
    {
        return notify_fail("NO ves " + str + " donde llamar.\n", NOTIFY_NOT_VALID);
    }
    if (puerta == -1)
    {
        return notify_fail("¿A qué " + str + " quieres llamar exactamente?\n", NOTIFY_NOT_VALID);
    }
    short = puerta->QueryShort() || str;
    sgender = puerta->QueryGender() == GENDER_FEMALE ? "a": "o";
    other_room = puerta->QueryDoorOtherSide(TO);


    if (puerta->QueryDoorState() == DOOR_OPENED)
    {
        return notify_fail("¿Para qué llamar a " + short + " si está abiert" + sgender + "?",
                           NOTIFY_NOT_VALID);
    }

    if (!(msg = puerta->QueryDoorKnockMsg()))
    {
        msg = ({({"Llamas a " + short + ".\n"}),
            ({TNAME + " llama a " + short + ".\n", "Escuchas como alguien llama a una puerta.\n"})});
        if (other_room)
        {
            string oshort = puerta->QueryShort(other_room);
            msg += ({({(puerta->QueryDoorTransparency() ? "Escuchas como " + TNAME + " llama a " +
                   oshort + " desde el otro lado.\n" :
                   "Escuchas llamar a " + oshort + ".\n"),
                       "Escuchas como alguien llama a una puerta.\n"})});
        }
        else msg += ({({0})});
    }
    _SendDoorMessages(msg, FindExitDoor(puerta), puerta);
    if ((sonido = puerta->QueryDoorKnockSound()))
    {
        play_sound(TO, sonido);
        if (other_room = puerta->QueryDoorOtherSide(TO)) play_sound(other_room, sonido);
    }
    return 1;
}

//------------------------------------------------------------------------------
/* mensajes */

/* --- Funciones de Uso Público --- */

// Func: QueryNowayMsgs() -> Devuelve un mapping con los mensajes de "no hay
// salida".
//
public mapping QueryNowayMsgs()
{
    return copy(Pnowaymsgs);
}


// Func: SetNowayMsgs() -> Cambia y devuelve el mapping de los mensajes de
// "no hay salida".
//
public mapping SetNowayMsgs( mapping m)
{
    return Pnowaymsgs = m;
}


// Func: AddNowayMsg() -> Añade mensajes de "no hay salida" a la lista.
//
public void AddNowayMsg( mixed arg, string msg )
{
    if( msg[<1] == '\n' ) msg = msg[0..<2];
    if (member("!.?", msg[<1] < 0) ) msg += ".";
    msg += "\n";
    if( !Pnowaymsgs ) Pnowaymsgs = ([]);
    if( stringp(arg)) m_add(Pnowaymsgs, arg, msg);
    else filter(arg, (:m_add(Pnowaymsgs, $1, $2):), msg);
}


// Func: RemoveNowayMsg() -> Borra el/los mensaje/s de "no hay salida"
// especificados.
//
public void RemoveNowayMsg( mixed arg )
{
    if(!Pnowaymsgs || !sizeof(Pnowaymsgs)) return;
    if( stringp( arg ) ) m_delete( Pnowaymsgs, arg );
    else filter(arg, (:m_delete( Pnowaymsgs , $1):));
}

// Func: QueryNowayMsg() -> Devuelve el mensaje de "no hay salida" actual.
//
public varargs string QueryNowayMsg( string verb, string arg )
{
   string msg;

    if(verb && Pnowaymsgs && sizeof(Pnowaymsgs) && m_contains( &msg, Pnowaymsgs, verb ) )
    {
        return msg;
    }
    return Pdefmsg;
}

// Func: SetNowayMsg() -> Cambia el mensaje de "no hay salida" y devuelve
// el resultado.
//
public string SetNowayMsg( string s )
{
    return Pdefmsg = s;
}

/* \/\/\/\/\/\/\/\/\/\/\/\/ COMANDOS \/\/\/\/\/\/\/\/\/\/\/\/ */

/* --- Funciones de Uso Público --- */

// Func: QueryCommands() -> Devuelve un mapping con los comandos existentes.
//
public mapping QueryCommands()
{   return Pcmds;   }

// Func: SetCommands() -> Cambia y devuelve el mapping de comandos existentes.
//
public mapping SetCommands( mixed c )
{
   if( !c || mappingp( c ) )
      Pcmds = c;
   else
      Pcmds = mkmapping( c[0], c[1] );
   return Pcmds;
}

// Func: AddRoomCmd() -> Añade a la lista de comandos el comando cmd, que
// llamará a la función func cada vez que se ejecute.
//
public void AddRoomCmd( mixed cmd, mixed func )
{
   int s;

   if( stringp( cmd ) )
   {
      if( Pcmds )
      {
         if( func ) Pcmds[cmd] = func;
         else
            if( !sizeof( Pcmds = m_delete( Pcmds, cmd ) ) )
               Pcmds = 0;
      }
      else
         if( func ) Pcmds = ([ cmd: func ]);
   }
   else
      if( s = sizeof( cmd ) )
      {
         if( Pcmds )
         {
            if( func ) while( s-- ) Pcmds[cmd[s]] = func;
            else
            {
               while( s-- ) Pcmds = m_delete( Pcmds, cmd[s] );
               if( !sizeof( Pcmds ) ) Pcmds = 0;
            }
         }
         else
            if( func )
            {
               Pcmds = ([ ]);
               while( s-- ) Pcmds[cmd[s]] = func;
            }
      }
}

// Func: RemoveRoomCmd() -> Borra el comando cmd de la lista de comandos.
//
public void RemoveRoomCmd( mixed cmd )
{
   int s;

   if( !Pcmds )
      return;
   if( stringp( cmd ) )
      Pcmds = m_delete( Pcmds, cmd );
   else
      if( s = sizeof( cmd ) )
         while( s-- ) Pcmds = m_delete( Pcmds, cmd[s] );
   if( !sizeof( Pcmds ) )
      Pcmds = 0;
}

// Func: UseExit() -> Chequea si puedes o no pasar por la salida y si puedes
// o no entrar en la habitación destino. Si eres capaz, allí te mueve. Si
// no, bonito mensaje de rechazo te odio.
//
public int UseExit( string verb, string arg, int method )
{
    mixed dest, obj;
    object puerta;
    int size;


    // Si no existe esa salida...
    //
    if( !Pexits || !( dest = Pexits[verb] ) )
    {
        return notify_fail( QueryNowayMsg( verb, arg ) || "No hay salida hacia allí.\n" );
    }

    // Si el destino es una llamada a una función, se ha de ejecutar...
    //
    if( closurep( dest ) )
    {
        return (int) funcall( dest, arg );
    }

    obj = ( TP || PO );

    if( arg || environment( obj ) != TO )
    {
        return 0;
    }

    // ¿Y si está demasiado cansado incluso como para moverse?
    //
    if ( (TP->Query(P_LSTATE) != LSTATE_GHOST) && !IS_WIZARD(TP) )
    {
        if( TP->QueryTP() <= 0 )
        {
            return notify_fail( "Estás muy cansado para seguir.\n" );
        }
        TP->SetTP( TP->QueryTP() - 1 );
    }

    // si hay puerta, comprobamos si está abierta o cerrada, y en consecuencia, si puede o no pasar
    if ((puerta = Pexits[verb, EXIT_DOOR]) && puerta->QueryDoorState() == DOOR_CLOSED)
    {
        string pshort = puerta->QueryShort(), sonido;
        object other_room;

        string *msg = ({({"Te estampas violentamente contra " + pshort +
                          " cerrad" + puerta->QueryGenderEndString() +
                          ".\n",
                        "Te estampas violentamente contra " + pshort + ".\n"}),
                      ({"@nombre@ se estampa ridículamente contra " + pshort + ".\n",
                    "Se escucha un fuerte golpe.\n"})});

        if (sonido = puerta->QueryDoorHitSound()) play_sound(TO, sonido);

        if (other_room = puerta->QueryDoorOtherSide(TO))
        // la habitación del otro lado está cargada
        {
            if (sonido) play_sound(other_room, sonido);
            msg += ({({(puerta->QueryDoorTransparency() ?
                        "Un fuerte golpe sacude " + puerta->QueryShort(other_room) +
                        ". @nombre@ no se ha dado cuenta que estaba cerrad" +
                        (puerta->QueryGender() == GENDER_FEMALE ? "a" : "o") +
                        ".\n" :
                        "Un fuerte golpe sacude " + puerta->QueryShort(other_room) +
                        ".\n"),
                       "Se escucha un fuerte golpe.\n"})});
        }
        else msg += ({0});

        return _SendDoorMessages(puerta->QueryDoorNoleaveMsg() ||msg,
                                 verb, puerta, 1);
    }

    // Veamos si tiene el tamaño necesario para pasar.
    //
    size = Pexits[verb, EXIT_SIZE];
    if( size != P_SIZE_GENERIC &&
        TP->QuerySize() != P_SIZE_GENERIC )
    {
        if( size < TP->QuerySize() )
        {
            write( "Te estrujas para poder pasar por la salida " + verb + "...\n" );
            if( !TP->QueryInvis() )
            {
                say( capitalize( TP->QueryRealName() ) + " se estruja para poder pasar por la salida " + verb + "...\n" );
            }
        }
        if( size < TP->QuerySize() - 1 )
        {
            if( !TP->QueryInvis() )
            {
                say( "... pero la salida es demasiado pequeña para " +
                     ( TP->QueryGender() == GENERO_FEMENINO ? "ella" : "el" ) + ".\n" );
            }
            return notify_fail( "... pero la salida es demasiado pequeña para tí.\n" );
        }
    }

    // Diferentes respuestas a nuestro intento de movimiento.
    //
    switch( obj->move( dest, method, verb ) )
    {
        case ME_OK:
        case ME_CLOSED:
        case ME_NO_MOVE:
        case ME_DESTRUCTED_SELF:
             break;
        case ME_NO_LEAVE:
             tell_object( obj, "Algo te impide irte de aquí.\n" );
             break;
        case ME_NO_DROP:
        case ME_NO_GET:
        case ME_NO_GIVE:
        case ME_NO_ENTER:
             tell_object( obj, "Algo te impide moverte allí.\n" );
             break;
        case ME_TOO_HEAVY:
        case ME_TOO_MANY:
        case ME_TOO_BIG:
             tell_object( obj, "No hay suficiente espacio para tí.\n" );
             break;
        case ME_CAUGHT_ERR:
             tell_object( obj, "Un problema te impide moverte.\n" );
             break;
        default:
             tell_object( obj, "Un gran problema impide que te muevas.\n" );
    }
    return 1;
}

// Func: exitfunc() -> Realiza la llamada a UseExit() con los parámetros
// correspondientes.
//
public int exitfunc(string arg) { return UseExit( query_verb(), arg, M_GO ); }

// Func: closurecmd() -> Realiza la llamada a la función especificada en la
// declaración de la salida.
//
public int closurecmd( string arg )
{   return funcall( Pcmds[ query_verb() ], arg );   }

// Func: init() -> Ya se sabe. Además, añade los comandos de salida comunes
// y otros.
//
public void init()
{
    string *cmd, *def;
    mixed *func;
    int s, t;

    DoExplore( 1 );
    if( Pexits )
    {
        def = ({ "norte", "noroeste", "oeste", "suroeste", "sur", "sureste",
                 "este", "noreste", "arriba", "abajo","entrar", "salir" });
        cmd = m_indices(mkmapping(m_indices( Pexits || ([]) ) + def));
        for(s=sizeof(cmd); s--;) add_action("exitfunc", cmd[s]);
    }


    if( Pcmds )
    {
        for( s = sizeof( cmd = m_indices( Pcmds ) ), func = m_values( Pcmds ); s--;)
        {
            if( stringp( func[s] ) ) add_action( func[s], cmd[s] );
            else add_action( "closurecmd", cmd[s] );
        }
    }
}

/* \/\/\/\/\/\/\/\/\/\/\/\/ FIN [exits.c] \/\/\/\/\/\/\/\/\/\/\/\/ */
