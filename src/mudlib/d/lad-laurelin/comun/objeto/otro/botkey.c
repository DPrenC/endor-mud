/*************************************************************************/
// DESCRIPCION: bote con llave dentro
// FICHERO:
// CREACION: Alura
/*************************************************************************/
#include <properties.h>
#include <moving.h>
inherit "/std/room/items"; // reset() is here
inherit CONTAINER;

/*-------------------------------------------------------------------------
** funcion romper_bote que clona la llave cuando el bote se rompa
-------------------------------------------------------------------------*/
int _romper(string str){
object ob;
if (str=="bote") {
	write("Entre los restos del bote ves una llave.\n");
	say(TP->QueryName()+" rompe un pequenyo bote en trocitos.\n");
	AddItem("/d/lad-laurelin/comun/objeto/otro/llaveq");
	TO->remove();
	return 1;
	}
write("No puedes romper eso.\n");
return 0;
}

init(){
	::init();
	add_action("_romper","romper");
}

create () {
  ::create();
  SetShort("un pequenyo bote");
  SetLong("Un bote en el que ves una llave, pero no puedes meter la mano dentro.\n");
  SetPreIntShort("dentro de");
  SetIntShort("un bote");
  SetIntLong("Estas en el interior de una bolsa.\n");
  SetPreContent("Contiene:\n");
  SetValue(12);
  SetWeight(700);
  AddId("bote");
  SetMaxIntWeight(1000);
}

int IsObjBag() { return 0; }