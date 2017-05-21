/* Marca Muerte.
**
** The main purpose of the mark is to be autoloading to prevent cheating.
** Thus we don't make it a fullfledged 'thing'.
** But since we have it, it can also do some nicies.
**
**   26-Aug-92 [m] Adapted for native.
**
**  [m] Mateese
*/

#include <config.h>
#include <properties.h>
#include <moving.h>

static object place;  /* Here we'll return from death */

init() {
  start_death();
}

varargs int move (mixed dest, mixed method, mixed extra) {
  if (stringp(dest)) dest = find_object(dest);
  if (!dest) return 0;
    /* If a living is dead, it's dead. */
/*  if (method != 1 && living(environment(TO))) return 0; */
  move_object(TO, dest);
  return 1;
}

int id (string str) { return str == "death_mark"; }

/* Start death.
**
** Just print out some comments and move the player into the deathroom.
** The player is the one carrying us, and it must be a ghost already.
*/

start_death () {
  object my_host, ob;
  my_host = environment(TO);
  if (!my_host || !living(my_host) || place) return;
  if (!my_host->QueryGhost()) { destruct(TO); return; }
  place = environment(my_host);
  say ("Crees percibir una silueta que se yergue sobre el cadáver.\n"
  "La silueta se deshace en el aire...\n\n"
      );
  write (
"Quedas suspendid"+my_host->QueryGenderEndString()+" en un nimbo más allá de todo tiempo y espacio....\n"
        );

  write("Las estrellas giran lentamente y cada instante parece eterno como una Edad...\n\n");
  if (   ME_OK != my_host->move("/room/death_room", M_SILENT)
      && ME_OK != my_host->move("/room/death_room", M_NOCHECK)
     )
  {
    CHANNELMASTER->SendStr("error",
      sprintf("[error] death_mark: No se pudo mover al jugador %s desde el entorno %O."
             , capitalize(geteuid(my_host)), environment(my_host)
             )
    );
    my_host->SetGhost(0);
    destruct(TO);
  }
}

object query_place() { return place; }

/* Autoload against cheaters */

mixed Query(string prop) { return prop == P_AUTOOBJECT; }
mixed Set(string prop, mixed val) { return val; }
