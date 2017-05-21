// qcorpse.c
// Cadáver del ghoul, del que habrá que cortar la cabeza.
// Por supuesto, esto tiene bastante tela, porque no sé si
// conseguiré que funcione como yo quiero.
// La idea es: una vez muerto el ghoul, su cadáver es esto.
// Y luego le cortas la cabeza. No tiene más. El truco está
// en que probablemente ahora sí que pueda llamar a SetOwner
// con un owner correcto. Si esto no funcionare, entraré en
// Berserk y destruiré algo.

#include <properties.h>

inherit THING;

create() {
::create();
SetShort("El cadáver de un ghoul");
SetLong(
"Es el cadáver medio descompuesto de un ghoul.\n");
SetWeight(70000);
SetValue(25);

}

init(){
// Añadir el add_action por aquí má o meno...
  ::init();
}