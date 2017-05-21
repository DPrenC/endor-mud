/*
En d/kha-annu/comun/habitacion/kha-annu/ciudad/tiendas/tienda1.c est� como cambiar la descripci�n a petici�n del player.
*/

#include "path.h"
#include "/sys/moving.h"
#include "/sys/size.h"

inherit "/obj/mochila";

create() {
	::create();
	AddId("mochila levitadora");
	SetShort("una mochila levitadora");
	SetLong("Es una mochila levitadora realizada a partir de ciertos tejidos m�gicos que incorporan unos materiales m�s ligeros que el aire. Todo aquello que se introduzca en la mochila, ya de por si muy voluminosa, pesar� solamente la mitad de lo que deber�a en condiciones normales.\n");
	SetIntShort("una mochila levitadora");
	SetIntLong("Dentro de una mochila levitadora.\n");
	SetWeight(1000);										// La mochila en s� pesa 1 kilo
	SetMaxIntWeight(20000);									// Puede llevar 20 kilos
	SetSize(P_SIZE_LARGE);
	SetMagic(1);
}

// allow_enter -> notify_enter
public int allow_enter(int method, mixed extra)
{
	int ret;

	PO->SetWeight(PO->QueryWeight()/2);
	ret = ::allow_enter(method, extra);
	if (ME_OK != ret)
		PO->SetWeight(PO->QueryWeight()*2);
	return ret;
}

// prevent_leave -> notify_leave
public void notify_leave(mixed to, int method, mixed extra)
{
	::notify_leave(to, method, extra);
	PO->SetWeight(PO->QueryWeight()*2);
}
