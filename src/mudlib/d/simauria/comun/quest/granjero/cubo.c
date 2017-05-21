/*   cubo.c
     Creado por : Nemesis
     Fecha : 3-Dic-97
     Modificacion : 28-Sep-98 Modificada la descripcion para que sea un cubo
                              lleno de leche (Quest del granjero)
                    03-03-2003 [z] Hago que no se pueda tirar ni dar ni robar.
                    		   Weno lo de dar salvo al pnj del quest.
                  12/01/2005: kastwey[simauria]:
                  	retoco el cubo y uso la función move para aprovechar el notify_enter del granjero.
*/

#include <properties.h>
#include <moving.h>
inherit THING;

string pOwner;
public string SetOwner(string own) { return pOwner = own; }
public string QueryOwner() { return pOwner; }


create() {
::create();
SetShort("un cubo de leche");
SetLong("Es un cubo lleno de leche recien ordeñada.\n");
AddId("cubo");
AddId("cubo de leche");
AddId("qbo_leche");
SetWeight(1750);
SetValue(10);
Set(P_NOSELL,1); // No quiero objetos de quest pululando por ahi.
Set(P_CANT_STEAL,1);
}
public varargs int move(mixed dest, int method, mixed extra)
{
	if (dest->QueryGranjeroNandor() || method != M_GIVE)
	// es el granjero
	{
		return ::move(dest, method, extra);
	}
	else
	{
		return write("Solo le podrás dar este cubo a su dueño.\n"),ME_NO_GIVE;
	}
}
