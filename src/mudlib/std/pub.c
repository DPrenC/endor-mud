/* SIMAURIA '/std/pub.c'
   =====================
   [w] Woo

   29-12-96 [w] Revisado para el nuevo mud. Ningun cambio.
                El verdadero pub se encuentra en '/room/pub.c'
*/

inherit "/room/pub";

public void create()
{
  ::create();
  "/obj/lib/register"->Register(TO,"STDPUB");
}
