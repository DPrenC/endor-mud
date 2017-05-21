    /*   cabeza.c
     Creado por : Nemesis
     Fecha : 6-Nov-98
     Descripcion : La cabeza del ghoul de Nandor. Ha de ser entregada a Gulkas.
     Modificación:
     	03-03-2003: [z] Pongo que no se pueda robar y la función de dar solo a
                        Gulkas por lo del quest y porque usa el dar del mud.
                        Tampoco tirar ni comprar.
	08-04-2003  [n] EXPERIMENTAL: Añade una función para que lo anterior
	                dé algo así como igual...
18/07/2004: [kastwey@simauria:
Añado la función SetGhoulKiller y QueryGhoulKiller.
Si no, la comprobación de Gulkas no tendría mucho sentido.
*/

#include "path.h"
#include <moving.h>
#include <properties.h>

inherit THING;

string pOwner;
string pKiller;

public string SetOwner(string name) { return pOwner = name; }

public string QueryOwner() { return pOwner; }
public int SetGhoulKiller(string name);
public string QueryGhoulKiller();

create() {
  ::create();
  SetShort("una cabeza de ghoul");
  SetLong("Es una cabeza que una vez perteneció a un ghoul.\n");
  RemoveId("thing");
  AddId(({"k_beza","cabeza","cabeza de ghoul"}));
  SetWeight(1750);
  Set(P_NOSELL, 1); // No quiero objetos de quest pululando por ahi.
  SetOwner("");
  SetNoDrop(1);
  Set(P_NOSELL,1);

}

public int SetGhoulKiller(string name)
{
	pKiller = name;
	return 1;
}

public string QueryGhoulKiller()
{
	return pKiller;
}

public varargs int move(mixed dest, int method, mixed extra)
{
  if (method == M_GIVE && !dest->QueryIsGulkas()) return ME_NO_LEAVE;
	return ::move(dest, method, extra);
}
