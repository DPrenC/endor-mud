/* Creado por [I] Izet@Simauria.
   Sirvientes del castillo Kha-annu.
   [Woo] Modificado
*/


#include "./path.h"
inherit KBASE;

create() {
      ::create();
  SetAggressive(0);
   SetLevel(1);
  SetAlign(200);
  SetAC(1);
  SetHands(( {( {"mano izquierda",0,3}), ({"mano derecha",0,4} )} ));

}

init() {
int x;
   ::init();
   x = random(10);
      if (x < 6) {
              TO->SetGender(2);
              TO->SetName("el sirviente");
              TO->SetIds( ({"sirviente"}) );
              TO->SetAds( ({"un","el"}) );
              TO->SetShort("un sirviente");
              TO->SetLong(
"Este es uno de los muchos sirvientes del castillo. Viste con ropas lujosas, aunque\n"
"va muy desaliñado.\n"
              );
      }
      if (x >= 6) {
              TO->SetGender(1);
              TO->SetName("la sirvienta");
              TO->SetIds( ({"sirvienta"}) );
              TO->SetAds( ({"una","la"}) );
              TO->SetShort("una sirvienta");
              TO->SetLong(
"Esta es una de las sirvientas del castillo. Viste ropas totalmente blancas, y esta\n"
"muy bien aseada.\n"
              );
      }
}

public varargs void Die(mixed silent) {
   tell_room(environment(TO),
 "Con un crujido de huesos, "+TO->QueryName()+" cae al suelo sin vida, manchando\n"
"todo de roja sangre.\n");
   TP->SetAttribute("asesino",(TP->QueryAttribute("asesino"))+1);
   ::Die(silent);
}
