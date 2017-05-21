/* SIMAURIA '/obj/transporte/barco.c'
   ==================================
   [w] Woo@simauria

   29-12-97 [w] Traduccion de este archivo. Este sera el objeto que
                habra que heredarse para crear un barco.
   08-02-00 [w] Le he metido el seteuid porque no se porque cojones
                ahora daba un cannot load effective user, ese...
*/

inherit "/obj/transporte/mar/barco";
inherit "/std/thing";

public varargs int clean_up(int refcount)
{
  if (!can_clean_up()) return 1;
  return (thing::clean_up(refcount));
}

public create()
{
  blueprint()->RegisterMe();
  ::create();
  seteuid(getuid());
  SetShort("un barco");
  SetLong("Se trata de un simple barco que cruza el oceano.\n");
  SetIds(({"barco","bote"}));
  SetNoGet("No tienes fuerza suficiente para coger eso.\n");
  "/obj/lib/register"->Register(TO,"BARCO");
  if (!clonep()) return 1;
  set_heart_beat(1); // [w] Una vez se crea primero espera en el muelle
  return 0;
}

public init()
{
  (::init());
// [w] Llama a las correspondientes funciones que se encuentran en
//     /obj/transporte/mar/barco.c

  add_action("cmd_enter","subir");
  add_action("cmd_enter","abordar");
  add_action("cmd_enter","embarcar");
}
