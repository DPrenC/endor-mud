/***********************************************************/
//	"libro"
//	Libro de instrucciones del mu�eco vud�
//	se desvanece al leerlo
//	14-12-01 : Creaci�n -> Kodex
//	14-12-01 : Modificaci�n -> Kodex
//
//

inherit THING;

#include <properties.h>
#include <colours.h>
#include "./path.h"


int leer_cmd(string str)
{
	if (!str) return notify_fail("Leer qu�??"),0;
if (str == "libro" || str == "libro de las maldiciones")
	{
	tell_object(TP,W("Comienzas a leer el libro: El arte de las maldiciones "
	"viene de los antiguos shamanes, un secreto perdido que aqu� se relata:\n"+TC_RED+"Maldici�n "
	"con un mu�eco vud�"+TC_NORMAL+", es necesario llevar puesto un colgante de huesos m�stico "
	"para realizar la maldici�n, una vez se tiene puesto se puede proceder "
	"a \"maldecir\" al objetivo. Cuando el objetivo est� maldito el mu�eco tomar� "
	"su forma y clavando agujas en el mu�eco se causar� da�o al objetivo "
	"de la maldici�n.....\n"));
	tell_room(environment(TP),W("El "+TC_YELLOW+"libro de las maldiciones"TC_NORMAL" se convierte en polvo y se desvanece...\n"));
	TO->remove();
	return 1;
	}
else
	return notify_fail("Qu� has dicho que quieres leer???"),0;
}

create()
{
::create();

SetShort("el libro de las maldiciones");
SetLong(W("Es un libro de gran tama�o, las pastas son de cuero, aunque"
" tienes una sensaci�n extra�a al fijarte en ellas, sus p�ginas est�n "
"escritas con sangre y tiene un gran s�mbolo dorado en la portada.\n"));
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