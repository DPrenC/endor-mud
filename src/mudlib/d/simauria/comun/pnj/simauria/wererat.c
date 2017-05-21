/*   wererat.c
     Creado por : Nemesis
     Fecha : 26-Dic-97
	 Descripcion: Hombre-rata transformado para las cloacas de Simauria.
	 Modificado por Nyh
*/

#include <living.h>
#include <combat.h>
#include <gremios.h>

inherit NPC;

create() {
  ::create();
 SetStandard("un hombre-rata","licantropo", ([ GC_LUCHADOR: 15 ]), GENDER_MALE);
  SetShort("un hombre-rata");
  SetLong(
"Es una horrible criatura. Mide 2 metros de alto y su cuerpo esta cubierto. "
"de un espeso pelaje negro. Camina erguido sobre sus patas traseras y tiene "
"una larga cola que se mueve como un latigo. Esta es la forma mas peligrosa "
"del hombre-rata, ya que posee todo el maligno poder del animal y la inteli "
"gencia y habilidad manual del humano.\n");
  AddId(({"hombre rata","licántropo","licantropo","hombrerata","rata","hombre","monstruo"}));
  SetAds(({"horrible","apestoso"}));
  SetWeight(750000);
  SetLevel(10); // Es uno de los bichos mas peligrosos de las cloacas.
  SetCon(QueryCon()-1);
  SetDex(QueryDex()+4);
  SetInt(QueryInt()-3);
  SetHP(QueryMaxHP());
  SetAlign(-9000); // Son malvados por naturaleza
  SetAggressive(1);
  SetHands(({({"garra izquierda",0,4}),({"garra derecha",0,4}),({"cola",0,5})})); // Es poderosa, a pesar de todo

  InitAChats(10,({
	"Los ojos del monstruo brillan siniestramente.\n"
  }));
}