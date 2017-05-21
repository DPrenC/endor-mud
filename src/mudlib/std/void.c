/* SIMAURIA '/std/void.c'
   ======================
   [n] Nemesis@simauria
   [a] Angor@simauria
   [t] Theuzifan@simauria
   [w] Woo@simauria

   Lugar donde los jugadores se mueven si su environment se destruye.

   17-11-97 [n] Traducción de ello.
   15-02-98 [a] Actualización a la nueva habitación de Asthar.
   14-12-99 [t] Modifica un poco para que no pete demasiado y puedas volver
                al sitio donde se supone que estaba bien.
   04-02-99 [t] Castellanizado.
   06-04-99 [w] Actualizado al nuevo sistema de magia.
   22-04-99 [t] Corrijo alguna que otra cosa en el volver
*/

inherit ROOM;
#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include <stdrooms.h>
#include <wizlevels.h>
#include <magia.h>

static private mapping oenv;

#define LOGFILE "VOID"


public int center(string arg);
public string windows(string window);
public int do_scream(string arg);
object ob;

int fun_volver()
{
  if (catch(load_object(oenv[TI, 0])))
    return notify_fail("Ha ocurrido un error y no puedes volver al lugar de donde viniste.\n");
  else
    TP->move(oenv[TI, 0], M_TELEPORT);

  return 1;
}

void create() {
  ::create();
  oenv=([]);
  SetIndoors(1);
  SetIntBright(20);
  SetIntShort("un lugar ignoto");
  SetIntLong(
"Flotas en medio de la nada, más allá de todo tiempo y espacio. Una cálida y "
"aterciopelada oscuridad te rodea y no puedes distinguir nada salvo un portal plateado "
"que irradia una suave luz y un agujero en el mismo tejido de la realidad, más allá del "
"cual no percibes nada.\n"
"Si has aparecido aquí significa que se ha producido un error en el lugar donde te "
"encontrabas. Si quieres intentar volver a donde estabas escribe 'retornar'.\n"
"Si no puedes, escribe 'portal' y accederás a una estancia desde la que podrás, por la "
"gracia de los Valar, desplazarte a casi cualquier lugar de la Tierra Media.\n");
AddDetail(({"portal", "portal plateado", "puerta", "plateado"}),
"Es un portal con forma de arco que refulge con débil luz plateada.\n");
AddDetail(({"agujero"}),
"Una simple mancha que flota y fluctúa en la oscuridad reinante.\n");

  AddExit("portal", "/d/aman//comun/habitacion/valinor/valmar/ciudad/trans_endor");
  AddExit("regresar", SF(fun_volver));

  SetTPort(TPORT_OUT);
  AddDetail(({"ventana","ventanas","vacio", "vacío"}),
"\nA través de las ventanas sólo ves el vacio. Nunca pensaste que el vacio\n\
tuviera el aspecto de una especie de niebla fosforescente. Flotando en\n\
la niebla, a lo lejos, puedes ver una hermosa isla... la Isla Limbo\n");
  AddDetail(({"isla","Limbo","isla Limbo"}),
"\nTiene un aspecto mucho más acogedor que el lugar en el que te encuentras.\n");
  AddDetail(({"niebla"}),
"\nTiene un aspecto bastante siniestro. Parece estar viva, y de vez en cuando\n"
"ves aparecer extrañas sombras, vagamente definidas, flotando sobre ella.\n");
  AddDetail(({"sombras"}),
 "\nNo tienen una estructura clara. Incluso algunas parecen cambiar de forma. Algunas\n"
 "parecen vagamente humanas, otras tienen el aspecto de enormes cabezas oscuras\n"
 "y hay muchas que son sólo remolinos de niebla con boca y ojos. Algunas se\n"
 "acercan a las ventanas y te miran amenazantes. Tienes suerte de que ellos\n"
 "esten ahí fuera y tu aquí dentro... por el momento.\n");

  AddRoomCmd(({"gritar", "chillar"}), SF(do_scream));
}

public int QueryIntLight() {
  if (TP)
    return (int)TP->QueryIVision();
  return ::QueryIntLight();
}

/* Esto se queda comentao de momento...

 public int center(string arg) {
  if(IS_LEARNER(TP)) {
    TP->move(CENTER, M_GO, "into the center");
    return 1;
  }
  notify_fail("Sorry, that is not for mortals.\n");
}

*/

public void reset() {
  int j;
  object obj, tmp;

  for(j = 0, obj = first_inventory(); obj;) {
    tmp = obj;
    obj = next_inventory(obj);
    if(!query_once_interactive(tmp)) {
      tmp->remove();
      if (tmp)
        destruct(tmp);
      tell_room(TO, "La habitación se descompone y se recompone sola.\n");
      j++;
    }
  }
  if(j) {
    tell_room(TO, "Algo ha sido destruido.\n");
    if(obj = find_object(RESTROOM))
      tell_room(obj
               , "Explosiones silenciosas de luz iluminan la estancia.\n");
  }
}

public int do_scream(string arg) {
  write("En el vacío nadie puede oir tus gritos.\n");
  return 1;
}


public int remove(int arg)
{
  object * ob;
  int i;

  ob = all_inventory(TO);
  for (i = sizeof(ob); i-- ; )
  {
      if (interactive(ob[i]))
      {
	if (catch(ob[i]->move(oenv[ob[i], 0], M_SILENT)))
	  ob[i]->move(ob[i]->QueryHome(), M_SILENT);

        if (environment(ob[i])==TO)
          ob[i]->move(ASTHAR, M_SILENT);

        m_delete(oenv, ob[i]);
        tell_object(ob[i], "Todo a tu alrededor se disuelve.\n\
Por suerte, has sido transferido a otro lugar.\n");
      }
  }
  return ::remove(arg);
}

public void notify_enter(object oldenv, int method, mixed extra) {
  string msg;
  if (query_once_interactive(PO) && !query_wiz_level(PO))
  {
    msg = sprintf("%s %s de %O, método %O\n", ctime(), getuid(PO), oldenv, method);
    if (TI != PO)
      msg += sprintf("  interactivo: %s, verb '%s'\n"
                    , TI?getuid(TI) : "<nada>"
                    , query_verb() || "<nada>");
    log_file(LOGFILE, msg);
  }
  oenv+=([TP:object_name(oldenv)]);
  ::notify_enter(oldenv, method, extra);
}
