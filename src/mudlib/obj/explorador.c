/* SIMAURIA '/obj/explorador.c'
 * ============================
 * [w] Woo@simauria
 * [n] Nemesis@Simauria
 *
 * 25-02-99 [w] Corregido algún que otro bug y de paso hace que se guarden
 *              logs de cuando un jugador consigue un punto de exploracion.
 * Mar'99   [n] Traducida la cabecera, por si alguien no sabe inglés :) .
 * 22-03-99 [w] Añadida la función TotalEP() que se usa en el player.c y
 *              que devuelve la cantidad total de puntos de exploración que
 *              se pueden conseguir
 *
 * Objeto de control de los puntos de exploracion.
 * Fuertemente inspirado por el sistema de exploracion de TubMUD.
 * (Por supuesto, este fichero era originalmente de Nightfall, hasta que Woo
 *  y Nemesis pusieron sus zarpas sobre el y lo dejaron hecho unos zorros :) )
 *
 * Quiza sea integrado en el QUESTMASTER algun dia.
 *
 * P: Bien, que magia necesito poner en mi habitacion para activar el flag de
 *    exploracion?
 * R: Basicamente, la habitacion necesita hacer la llamada:
 *    TP->SetExplored()
 *
 *    Para facilitar la simple exploracion de habitaciones y detalles
 *    (i.e.: que entrar en una habitacion u observar un detalle cuente como
 *    \'acto de exploracion\'), Mateese@NF añadio la propiedad P_EXPLORABLE
 *    a la /std/room.
 *    En el create de la habitacion simplemente introduce:
 *	SetExplorable(1)	para hacer la habitacion explorable
 *	SetExplorable("zorch")	para hacer el detalle explorable
 *				(mirar zorch)
 *
 *    Estas dos funciones os ahorraran la molestia (y a Simauria el uso de
 *    la memoria :-) ) de programar funciones especiales en habitaciones que
 *    por lo demas no tienen nada de particular.
 *    Otra posibilidad es invocar SetExplored() en una funcion que sea
 *    invocada para manejar un comando.
 *
 *    Ejemplo:
 *	tirar_palanca() {
 *	    TP->SetExplored();
 *	    write("cuando tiras de la palanca, oyes un CLICK!\n");
 *	    [..]
 *	    return 1;
 *	}
 *
 *   Otro ejemplo (ahora obsoleto gracias a SetExplorable("nombre-detalle")):
 *	create() {
 *	    [..]
 *	    AddDetail("cuadro",
 *		      lambda(0,
 *			     ({ CL_PROGN ,
 *				({ SF(call_other),
 *				    ({ SF(this_player )}),
 *				    "SetExplored"
 *				}),
 *				"Un cuadro de Nemesis vestido de explorador.\n"
 *			     })
 *			    );
 *	    [..]
 *	}
 * Aunque el segundo ejemplo parece complicado, realmente es bastante
 * simple. Ni siquiera necesitas comprenderlo, simplemente copialo tal cual
 * en el codigo de tu habitacion.
 *
 */

#include "/secure/config.h"
#include <xp.h>
/* the purpose of the next three macros is to avoid the hash-tick notation,
 * which would confuse emacs c-mode indent engine _sigh_
 */
#define LSF(x) symbol_function(x, TO)	/* lfun */
#define ESF(x) symbol_function(x)	/* efun */
#define L(x) lambda(0, x)

static nomask make_log(s) {
  CHANNELMASTER->SendStr("error", "", "[error] "+object_name()+": "+s);
}
#define LOG(cond, str) if (cond) make_log(str);

private static mapping rooms;

/* --- */

public mapping QueryRooms() { return copy(rooms); }

private static check_file(x) {
  if ("" == x) return;
  if (!x || !stringp(x) || file_size(x+".c") < 0)
    make_log("Warning: No File for ``"+x+"''\n");
}

private static check_files() {	/* do the specified files exist? */
  map_indices(rooms, SF(check_file));
}

/* create() and SetExplored() are the two only functions that are
 * required for the explorer mechanism to work. the other functions
 * are for the NFQDs comfort and curiosity
 */
create() {
  int *indizes;
  int i;

  /* the list of rooms and rewards is contained in a separate file */

#include "/obj/explorador.ic"

  /* sanity checking */
  /* are all indizes unique ? */
  indizes = sort_array(m_values(rooms), SF(>));
  for (i = 0; i < sizeof(indizes)-1 ; i++)
    if (indizes[i] == indizes[i+1])
      make_log("Error: Indice de habitacion "+indizes[i]+" definido dos veces\n");

  /* have numbers been allocated sequentially ? */
  if (indizes[i] >= sizeof(indizes)) {
    make_log("Error: los indices de las habitaciones no son secuenciales, "
        + indizes[i] + " deberian ser " + sizeof(indizes) + "\n");
    /* try to find out which one is missing */
    for (i = 0; i < sizeof(indizes)-1 ; i++)
      if (indizes[i] != i) write(indizes[i] + " deberian ser " + i + "\n");
  }

  call_out(SF(check_files), 0);
}

/* keep it simple :-) */
nomask string SetExplored(string e) {
  string n;
  mixed x;
  int b;
  object prev;
  int i;

  while (prev = previous_object(i++))
  {
    n = object_name(efun::blueprint(prev));
    b = rooms[n];
    if (!b) continue;
    x = rooms[n, 1];
    if (!test_bit(e, b))
    // la primera vez que entra, pues el bit no está ajustado a 1
    {
      if (intp(x)) PO->exp(x);
      else funcall(x);
      // logeamos el descubrimiento
      log_file("EXPLORADOR", "["+ctime()+"] "+capitalize(TP->QueryName())
               +" ha explorado "+b+" obteniendo una recompensa de "+x+" XP\n");
    }
    else
    // ya estuvo antes. la vuelve a explorar
    {
      log_file("EXPLORADOR", "["+ctime()+"] "+capitalize(TP->QueryName())
               +" volvió a explorar "+b+"\n");
    }
    return set_bit(e, b);
    break;
  }
  return 0; // [Nyh] Para evitar el warning
}

/* --- */

clean_up() { destruct(TO); } /* we are stateless , thus can easily save mem */

/* --- */

/* some functions for comfort, statistics and curious people */
CountBits(s) {
  int i, j;
  for (i = 0; i < strlen(s||"") * 6; i++)
    j += test_bit(s||"", i);
  return j;
}

TotalEP() {
  return sizeof(rooms);
}
