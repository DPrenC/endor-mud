// qcorpse.c
// Cad�ver del ghoul, del que habr� que cortar la cabeza.
// Por supuesto, esto tiene bastante tela, porque no s� si
// conseguir� que funcione como yo quiero.
// La idea es: una vez muerto el ghoul, su cad�ver es esto.
// Y luego le cortas la cabeza. No tiene m�s. El truco est�
// en que probablemente ahora s� que pueda llamar a SetOwner
// con un owner correcto. Si esto no funcionare, entrar� en
// Berserk y destruir� algo.

#include <properties.h>

inherit THING;

create() {
::create();
SetShort("El cad�ver de un ghoul");
SetLong(
"Es el cad�ver medio descompuesto de un ghoul.\n");
SetWeight(70000);
SetValue(25);

}

init(){
// A�adir el add_action por aqu� m� o meno...
  ::init();
}