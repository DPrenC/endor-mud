/*
DESCRIPCION  : objeto "gafas de sol".
FICHERO      : /obj/sunglasses.c
ORIGEN       : Basado en sunglasses.c de NightFall
               11-Oct-92 [Mateese]
               12-Feb-95 [Mateese] Adapted for /obj/equipment instead of /std/armour.
ESTA VERSION : 13-03-97  [angor]   Traduccion
               01-02-99  [woo] Cambiado el SIZE a GENERIC.
               21-12-99  [woo] Le he metido para que suba mas el UVision y asi
                         momentaneamente los demonios puedan ver.

Gafas ahumadas (como las gafas de sol, pero este es un juego de fantasia
medieval). Solo se pueden llevar unas a la vez. Se deben llevar puestas para
que hagan efecto.
Usa las propiedades interiores "DeltaUVision", "DeltaIVision" para ajustar
la absorcion. 'SetDelta()' ajusta ambos valores a la vez.
La absorcion por defecto es 'one half sunbright'.
La propiedad interior 'Worn' tambien pone/quita las gafas de sol.
Las gafas se deben nombrar como 'glasses' y 'sunglasses'.
No cambiar el latter.

*/

#include <properties.h>
#include <config.h>
#include <attributes.h>
#include <wizlevels.h>
#include <search.h>

inherit "/obj/equipment";

static int deltaiv, deltauv;

/*--------------------------------------------------------------------------*/

create () {
  ::create();
  SetShort("unas gafas ahumadas");
  SetLong("Unas gafas ahumadas.\n");
  SetWeight(100);
  SetValue(1);
  SetIds( ({ "gafas", "gafas ahumadas" }) );
  deltaiv = deltauv = MAX_SUNBRIGHT;
  Set(P_SIZE, P_SIZE_GENERIC);
}

/*--------------------------------------------------------------------------
** Actually (un)wear the glasses.
*/

public varargs void NotifyEquip(object liv, object armour, int flags) {
  if (armour != TO) return;
    
  if (!living(liv)) return;
  liv->ModifyAttr(A_IVISION, deltaiv);
  liv->ModifyAttr(A_UVISION, deltauv);
  
  ::NotifyEquip(liv, armour, flags);
}

public varargs void NotifyUnequip(object liv, object armour, int flags) {
  if (armour != TO) return;
    
  if (!living(liv)) return;
  liv->ModifyAttr(A_IVISION, -deltaiv);
  liv->ModifyAttr(A_UVISION, -deltauv);
  
  ::NotifyUnequip(liv, armour, flags);
}

/*--------------------------------------------------------------------------
** Set/Query the absorbtion values.
** Using the functions allows setting even when wearing the glasses.
*/

int QueryDeltaUVision () { return deltauv; }
int SetDeltaUVision (int v) {
  int delta;
  object owner;
  if (v < 0) return deltauv;
  if (owner = QueryEquipped()) {
    delta = v - deltauv;
    owner->ModifyAttr(A_UVISION, delta);
    owner->AddBonus (A_IVISION, delta);
  }
  return deltauv = v;
}

int QueryDeltaIVision () { return deltaiv; }
int SetDeltaIVision (int v) {
  int delta;
  object owner;
  if (v < 0) return deltaiv;
  if (owner = QueryEquipped()) {
    delta = v - deltaiv;
    owner->ModifyAttr(A_IVISION, delta);
    owner->AddBonus(A_IVISION, delta);
  }
  return deltaiv = v;
}

varargs void SetDelta (int duv, int div) {
  if (!div) div = duv;
  SetDeltaUVision (duv);
  SetDeltaIVision (div);
}

/****************************************************************************/
