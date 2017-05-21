/* Death-Mark
**
** The main purpose of the mark is to be autoloading to prevent cheating.
** Thus we don't make it a fullfledged 'thing'.
** But since we have it, it can also do some nicies.
**
**   26-Aug-92 [m] Adapted for native.
**
**  [m] Mateese
**  [I] Izet@Simauria, Traduccion y Debug. 12 de Enero, 1997
*/

#include <config.h>
#include <properties.h>
#include <moving.h>

static object lugar;  /* En esta hab. retornaremos de la Muerte */

init() {
  ini_muerte();
}

varargs int move (mixed dest, mixed method, mixed extra) {
  if (stringp(dest)) dest = find_object(dest);
  if (!dest) return 0;
    /* If a living is dead, it's dead. */
/*  if (method != 1 && living(environment(TO))) return 0; */
  move_object(TO, dest);
  return 1;
}

int id (string str) { return str == "marca_muerte"; }

/* Empieza la muerte.
**
** Just print out some comments and move the player into the deathroom.
** The player is the one carrying us, and it must be a ghost already.
*/

ini_muerte () {
  object mi_host, ob;
  mi_host = environment(TO);
  if (!mi_host || !living(mi_host) || lugar) return;
  if (!mi_host->QueryGhost()) { destruct(TO); return; }
  lugar = environment(mi_host);
  say ("Ves una forma oscura envuelta en el misterio ...\n"
      "... o quiza sean imaginaciones tuyas.\n"
      );
  write (
"Ves a un hombre oscuro vestido con ropas oscuras detras de tu cuerpo.\n"
"Empunya una guadanya de hoja sanguinolenta que va moviendo de arriba hacia\n"
"abajo lentamente. De repente para... y su mirada se encuentra con la tuya...\n"
"Las cuencas de sus ojos estan vacias, pero..., pero un brillo de color rojizo\n"
"las invade.\n\n"
        );

  write("La Muerte te dice: VEN A MI, MORTAL!\n\n"
    "Se acerca hacia ti y de repente te encuentras en otro lugar.\n\n");
  if (   ME_OK != mi_host->move("/room/hab_muerte", M_SILENT)
      && ME_OK != mi_host->move("/room/hab_muerte", M_NOCHECK)
     )
  {
    CHANNELMASTER->SendStr("error",
      sprintf("[error] marca_muerte: No se puede mover al jugador %s fuera del entorno %O."
             , capitalize(geteuid(mi_host)), environment(mi_host)
             )
    );
    mi_host->SetGhost(0);
    destruct(TO);
  }
}

object preg_lugar() { return lugar; }

/* Autoload contra cheaters */

mixed Query(string prop) { return prop == P_AUTOOBJECT; }
mixed Set(string prop, mixed val) { return val; }
