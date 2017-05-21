/*   licencia de pescar
     Creado por : Cheto
     Fecha : 16-Nov-98
     Modificación: 03-03-2003 [z] Pongo no robar no tirar no vender no comprar.
*/

#include <properties.h>
inherit THING;

create() {
::create();
SetShort("Impreso JK23-H");
SetLong("Impreso JK23-H, Certificado Oficial de Reparador de Faros de Simauria.\n");
AddId(({"impresoq","JK23-H","impreso"}));
SetWeight(0);
SetValue(50);
Set(P_CANT_STEAL,1);
  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
}
