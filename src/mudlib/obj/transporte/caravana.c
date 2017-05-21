/* SIMAURIA '/obj/transporte/caravana.c'
   =====================================
   [w] Woo@simauria

   20-11-98 [w] Creacion de este archivo.. modificado a partir de los
                barcos.
   29-03-99 [w] Castellanizado.
*/

inherit "/obj/transporte/tierra/caravana";
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
  SetShort("una caravana");
  SetLong("Es una caravana de nomadas que cruzan el desierto con sus camellos.\n");
  SetIds(({"caravana"}));
  SetNoGet("¿Realmente intentas coger una caravana?\n");
  "/obj/lib/register"->Register(TO,"CARAVANA");
  if (!clonep()) return 1;
  set_heart_beat(1); // [w] Una vez se crea primero espera en la parada
  return 0;
}

public init()
{
  (::init());
// [w] Llama a las correspondientes funciones que se encuentran en
//     /obj/transporte/tierra/caravana.c

  add_action("cmd_enter","unirse");
  add_action("cmd_enter","subir");
}
