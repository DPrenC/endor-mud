/* SIMAURIA '/guilds/conjuradores/obj/oscuridad.c'
   ===============================================
   [w] Woo@simauria

    26-10-99 [w] Objeto creado para el conjuro de oscuridad.
*/

inherit "/std/thing";

create() {
  if (!clonep(TO)) return;
  ::create();
  SetShort(0);
  SetLong(0);
  SetBright(-50);
  SetWeight(0);
  SetNoGet(1);
  call_out("remove",300);
}

