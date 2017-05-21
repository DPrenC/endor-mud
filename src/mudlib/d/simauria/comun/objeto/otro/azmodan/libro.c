/***********************************************************/
//	"libro"
//	Libro de instrucciones del muñeco vudú
//	se desvanece al leerlo
//	14-12-01 : Creación -> Kodex
//	14-12-01 : Modificación -> Kodex
//
//

inherit THING;

#include <properties.h>
#include <colours.h>
#include "./path.h"


int leer_cmd(string str)
{
	if (!str) return notify_fail("Leer qué??"),0;
if (str == "libro" || str == "libro de las maldiciones")
	{
	tell_object(TP,W("Comienzas a leer el libro: El arte de las maldiciones "
	"viene de los antiguos shamanes, un secreto perdido que aquí se relata:\n"+TC_RED+"Maldición "
	"con un muñeco vudú"+TC_NORMAL+", es necesario llevar puesto un colgante de huesos místico "
	"para realizar la maldición, una vez se tiene puesto se puede proceder "
	"a \"maldecir\" al objetivo. Cuando el objetivo está maldito el muñeco tomará "
	"su forma y clavando agujas en el muñeco se causará daño al objetivo "
	"de la maldición.....\n"));
	tell_room(environment(TP),W("El "+TC_YELLOW+"libro de las maldiciones"TC_NORMAL" se convierte en polvo y se desvanece...\n"));
	TO->remove();
	return 1;
	}
else
	return notify_fail("Qué has dicho que quieres leer???"),0;
}

create()
{
::create();

SetShort("el libro de las maldiciones");
SetLong(W("Es un libro de gran tamaño, las pastas son de cuero, aunque"
" tienes una sensación extraña al fijarte en ellas, sus páginas están "
"escritas con sangre y tiene un gran símbolo dorado en la portada.\n"));
SetIds(({"libro","libro de las maldiciones"}));
SetWeight(3000);
Set(P_GENDER,GENERO_MASCULINO);
Set(P_NUMBER,NUMERO_SINGULAR);
Set(P_NOGET,1);
}

init()
{
::init();
add_action("leer_cmd","leer");
}