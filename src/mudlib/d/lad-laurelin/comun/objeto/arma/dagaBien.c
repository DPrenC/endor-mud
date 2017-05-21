//Descripcion	: Daga de titanio q no se puede vender para seres buenos
//Nombre completo : dagaBien.c
//Creacion		: Junio 2001 [Alura]

inherit WEAPON;
// inherit NPC;
#include "path.h"
#include <moving.h>
#include <colours.h>
#include <combat.h>
#include <properties.h>
#include <materials.h>

create()
{
  ::create();
 SetStandard(WT_CUCHILLO, 3, P_SIZE_SMALL, M_TITANIO);
  SetShort("una daga");
  SetLong("Es una bonita daga de metal. El mango es de mármol rosado y la cuchilla no es muy larga.\n");
  SetIds(({"daga"}));
  Set(P_GENDER, GENDER_FEMALE);
  Set(P_NOSELL,1);
}

int emp_ali(){
	if (TP->QueryAlign()<0){
		tell_object(TP, "La espada arde tanto en tus manos que la tiras al suelo enseguida.\n");
		move(environment(TP),M_SILENT);
		return 1;
	} else {
		return ::wield(TO);
	}
}

int desemp() {
	int fl;
	fl=::unwield(TO);  //llamo a la funcion pa que haga to el trabajo
	if (TP->QueryAlign()<0) {
		tell_object(TP, "Después de usarla con "+TC_RED"maldad"TC_NORMAL+", provocas que la espada se "+TC_RED"audestruya"TC_NORMAL+".\n");
		//destruct(TO);
		return TO->remove();
	}
}

init(){
	add_action("emp_ali","empuñar");
	add_action("emp_ali","empunyar");
	add_action("desemp","desempuñar");
	add_action("desemp","desempunyar");
	::init();
}