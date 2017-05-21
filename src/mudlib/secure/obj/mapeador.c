/* /secure/mapeador.c

  [Nyh] Creo esto para mapear el mud. La única limitación que tiene son las
        salidas que en vez de un destino tienen una closure, el programa
        no pasa por ahi.

  [Nyh] Puta mierda, me da 'Too deep recursion', ale, tendre q hacerlo con
        bucles!
        Ahora el codigo es mas cutre q nada, pero funciona y como no es algo
        que se vaya a usar a menudo, me la pela.

  Explicacion de como rula:

  La función a llamar es:
    public varargs int mapea(mixed origin, string savefile)

  Como veis es varargs, si alguno de los valores no se introduce, se toma el
  de por defecto, que en el caso de origin es environment(TP) y
  en el caso de savefile es DEFAULT_SAVEFILE.

  NOTA: No me seais cafres, si alguien quiere que mapee desde donde esta, pero
  quiere especificar un savefile, la llamada seria:
    mapea(0,"/dondequiero/guardar/esto")

  Lo que guarda es un mapping que tiene por keys nombres de habitaciones, y
  por data mappings que tienen por keys direcciones y por data a donde lleva
  cada dirección.
  Si una habitacion no tiene salidas almacena ([])
  Si una habitacion ha dado algun error almacena 0
  Si una salida tiene una funcion como destino, la salida almacena 0
  Podria hacer una salida formateada y bonita, pero paso por que con el
  UltraEdit se tarda menos en hacer eso y no tengo q programar nada...

  Ale, ale, es para tontos, asi q dudas a /dev/null

*/
#include <rtlimits.h>
#include <wizlevels.h>

#define DEFAULT_SAVEFILE    "/log/mapeador"

mapping data = ([]);

private varargs int _generate_map(mixed origin, string savefile) {
    string str;
    object ob;
    mapping dest;
    mixed *rooms;
    int rc;

//Primero compruebo los datos de entrada.
//Si no hay savefile, utilizo DEFAULT_SAVEFILE
    if (!savefile) savefile = DEFAULT_SAVEFILE;

//Si algo falla con origin uso environment(TP) y si no aborto.
    if (stringp(origin)) origin = load_object(origin);
    if (   !objectp(origin)
        && (   !TP
            || !objectp(origin = environment(TP))
           )
       )
    {
        raise_error("Imposible determinar una habitación de origen.\n");
        return 0;
    }

// Empieza el programa... si no es llamado con privilegios de proceso
// ilimitado, casi seguro q petara.
    ob   = origin;
    str  = object_name(ob);
    dest = ob->QueryExitsDest() || ([]);
    data = ([str: dest]);
    rooms = m_values(dest);

    while(sizeof(rooms))
    {
        if (stringp(rooms[0]))
        {
            if (catch(ob = load_object(rooms[0])))
            {
                data += ([rooms[0]: 0]);
                rooms = rooms[1..];
                continue;
            }
            str = object_name(ob);
        }
        else if (objectp(rooms[0]))
        {
            ob = rooms[0];
            str = object_name(ob);
        }

        if (member(data, str))
        { //ya tengo esta habitacion
            rooms = rooms[1..];
            continue;
        }

        if ( !ob  || !str )
        { //Error... y esta puesto aposta despues del member
            data += ([rooms[0]: 0]);
            rooms = rooms[1..];
            continue;
        }

        dest = ob->QueryExitsDest() || ([]);

        data += ([str: dest]);
        rooms += map(m_values(dest), (: (stringp($1) && $1[<2..]==".c")?$1[..<3]:$1 :)) - ({ str });
    }
// Ahora tengo data petado de habitaciones... grabo.

    rc = save_object(savefile);
    data = ([]);

    return rc;
}

public varargs int mapea(mixed origin, string savefile) {
    seteuid(getuid());

    if (!TP || !IS_CON(TP))
      return notify_fail("No tienes suficientes privilegios.\n");
    return limited(SF(_generate_map), ({0,0,0,0,0,0}), origin, savefile);
}