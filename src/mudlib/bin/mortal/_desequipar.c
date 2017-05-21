/**
 *  SIMAURIA /bin/mortal/_desequipar.c
 *
 * [Nyh] Comando para desequipar objetos que hereden del /std/equipment.c
 *
 */

#include "equipdata.ic"

public int main(string arg)
{
  mixed   rc;
  mapping cdata;
  string  msg;

  if (!arg) {
    return notify_fail("¿"+capitalize(query_verb())+" qué?\n", NOTIFY_NOT_OBJ);
  }

  // Parse the commandline and match the given objects.
  if (!(cdata = getCData("desequipar", arg))) {
    return notify_fail("No tienes nada puesto para quitarte .\n");
  }

  // If this object was meant, try to wear it.
  foreach(object ob: cdata["what"])
  {
    if (member(inherit_list(ob), "/std/equipment.c") >= 0)
      rc = TP->Unequip(ob, ((ob->QueryWeaponType()||ob->QueryArmourType()) ? EWF_WEAPON : 0));
    else
      rc = EQ_FORBID;

    if (stringp(rc)) cdata["msg"] += rc;
    else
      switch (rc) {
      case EQ_OK:      cdata["handled"]    += ({ ob });  break;
      case EQ_ALREADY: cdata["already"]    += ({ ob });  break;
      case EQ_FORBID:  cdata["nothandled"] += ({ ob });  break;
      case EQ_NOHANDS:
      case EQ_ERROR:
      default:
        raise_error(sprintf("%O: Objeto ilegal o erróneo: rc %O\n", ob, rc));
      }

    msg =  cdata["msg"]
          +implode_list(cdata["already"], "No llevas puesto ", ".\n", "ni")
          +implode_list(cdata["nothandled"], "No te puedes quitar ", ".\n", "ni")
          +implode_list(cdata["handled"], "Te quitas ", ".\n")
    ;

  }

  write(msg);
  return 1;
}
