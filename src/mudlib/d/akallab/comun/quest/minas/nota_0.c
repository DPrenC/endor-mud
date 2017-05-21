/*
DESCRIPCION  : nota del quest de las minas de Zarkam
FICHERO      : /d/akallab/comun/quest/minas/nota_0.c
MODIFICACION : 04-11-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include AK_MACRO
inherit THING;

create() {
  ::create();
  SetShort("una pequenya nota");
  SetLong(
  "\nLo encontre, Dalbar! lo encontre! Te dije que debia ser cierto lo que "
    "dijo aquel viejo loco sobre el gran tesoro escondido en esta mina. La "
	"historia no hacia mas que dar vueltas en mi cabeza hasta que, hace unos "
	"dias, decidi ir a buscarlo. Llevo ya unos dias que, tras el trabajo me "
	"he escabullido y he ido a explorar mas alla de los limites permitidos "
	"de las galerias. He seguido las indicaciones del viejo y he encontrado "
	"las primeras marcas alla donde el dijo: la caverna de la piedra, el "
	"arroyo y la gran grieta... Esta noche me aventurare mas alla. Si te "
	"interesa ven, estoy dispuesto a darte parte de lo que encuentre si me "
	"ayudas.\nFirmado: Sargek\n\n");
  SetIds(({"nota","pequenya"}));
  SetWeight(50);
  SetValue(0);
}
