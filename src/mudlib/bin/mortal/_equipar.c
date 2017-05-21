/**
 *  SIMAURIA /bin/mortal/_equipar.c
 *
 * [Nyh] Comando para equipar objetos que hereden del /std/equipment.c
 *
 */

#include "equipdata.ic"

public int main(string arg)
{
  mixed   rc;
  mapping cdata;
  string  msg, sufijo, sufijo2;

  if (!sizeof(arg)) {
    return notify_fail("¿"+capitalize(query_verb())+" qué?\n", NOTIFY_NOT_OBJ);
  }

  // Parse the commandline and match the given objects.
  if (!(cdata = getCData("equipar", arg))) {
    return notify_fail("No tienes nada que ponerte.\n");
  }
  // If this object was meant, try to wear it.
  foreach(object ob: cdata["what"])
  {
    if (member(inherit_list(ob), "/std/equipment.c") >= 0)
      rc = TP->Equip(ob, ((ob->QueryWeaponType()||ob->QueryArmourType()) ? EWF_WEAPON : 0));
    else
      rc = EQ_FORBID;
    if (stringp(rc)) cdata["msg"] += rc;
    else
      switch (rc) {
      case EQ_OK:      cdata["handled"]    += ({ ob }); break;
      case EQ_ALREADY: cdata["already"]    += ({ ob }); break;
      case EQ_FORBID:  cdata["nothandled"] += ({ ob }); break;
      case EQ_NOHANDS: cdata["fewhands"]   += ({ ob }); break;
      case EQ_SMALL:   cdata["small"]      += ({ ob }); break;
      case EQ_LARGE:   cdata["large"]      += ({ ob }); break;
      case EQ_ERROR:
      default:
        raise_error(sprintf("%O: Objeto ilegal o erróneo: rc %O\n", ob, rc));
      }

    sufijo = "";
    sufijo = (ob->Query(P_GENDER)==GENDER_FEMALE?(ob->Query(P_NUMBER)==NUMBER_SINGULAR?"a":"as"):
                                  (ob->Query(P_NUMBER)==NUMBER_SINGULAR?"o":"os"));

    sufijo2 = (ob->Query(P_NUMBER)==NUMBER_SINGULAR?"":"s");

    msg =  cdata["msg"]
          +implode_list(cdata["already"], "Ya llevas equipad"+sufijo + " ", ".\n")
          +implode_list(cdata["nothandled"], "No puedes equipar ", ".\n")
          +implode_list( cdata["fewhands"]
                     , "No dispones de manos libres para empuñar ", ".\n")
          +capitalize(implode_list(cdata["small"]
                     , "", " " + (sizeof(cdata["small"]) > 1 ? "son" : "es")
                     +"demasiado pequeñ"+(sizeof(cdata["small"]) > 1 ? getPlData("small",cdata)+"s" : sufijo)
                     +" para que l"
                     +(sizeof(cdata["small"]) > 1 ? getPlData("small",cdata)+"s" : sufijo)
                     +" equipes.\n"))
          +capitalize(implode_list(cdata["large"]
                     , "", " " + (sizeof(cdata["large"]) > 1 ? "son" : "es")
                     +" demasiado grande para ti"+(sizeof(cdata["large"]) > 1 ? "s" : sufijo2)
                     +" para que  l"
                     +(sizeof(cdata["large"]) > 1 ? getPlData("large",cdata)+"s" : sufijo)
                     +" equipes.\n"))
          +implode_list(cdata["handled"], "Equipas ", ".\n")
    ;

  }

  write(msg);
  return 1;
}
