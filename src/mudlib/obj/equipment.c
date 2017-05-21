/*---------------------------------------------------------------------------
** /obj/equipment
**
** A standard equipment thing.
** All necessary entanglement between /std/thing and /std/equipment is
** already done.
**---------------------------------------------------------------------------
*/


#include <config.h>
#include <properties.h>
#include <moving.h>
#include <equipment.h>

inherit THING;
inherit "/std/equipment";

//---------------------------------------------------------------------------

public void init () {
  thing::init();
}

public varargs int move (mixed dest, int method, mixed extra) {
  int rc;
  rc = thing::move(dest, method, extra);
  if (rc == ME_OK)
    notify_move(dest, method, extra);
  return rc;
}

public int remove() {
  notify_move(0, M_DESTRUCT);
  return thing::remove();
}

public /* int */ QueryValue(int sc)         {
  return sc ? ::QueryValue() : modifyValue(::QueryValue());
}

public string Long(string what) { return modifyLong(::Long(what)); }
public string InvShort (string what) {
  return modifyInvShort(::InvShort(what));
}

/***************************************************************************/
