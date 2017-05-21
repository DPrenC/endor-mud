/**
 * SIMAURIA /std/living/equipment.c
 *
 * [Nyh] Archivo con todo lo relacionado con que un living se ponga o quite
 *       equipo.
 */

#include <properties.h>
#include <equipment.h>
#include <messages.h>

//---------------------------------------------------------------------------

protected int AddWeapon(object ob);
protected int RemoveWeapon(object ob, int flags);
protected int AddArmour(object ob);
protected int RemoveArmour(object ob, int flags);
protected void Ungrip(object ob);
protected int Grip(object ob);

//---------------------------------------------------------------------------

public varargs mixed Equip(object what, int flags)
// Empuña what
{
  mixed rc, obj, mode;
  string sh;

  //dtell("nyh",sprintf("%O->Equip(%O, %O)\n", TO, what, flags));
  if (!what) return EQ_ERROR;

  if (what->QueryEquipped()) return EQ_ALREADY;

  sh = what->QueryShort();

  rc = TO->CompareSize(what);
  if (rc < 0) return EQ_LARGE;
  if (rc > 0) return EQ_SMALL;

  if (rc = what->Query(P_NOEQUIP)) return stringp(rc) ? rc : EQ_FORBID;

#if __VERSION__ >= "3.3"
  obj = ({ what }) | all_inventory(TO); // ¿poner TODO el inventario?
#else
  obj = ({ what }) + (all_inventory(TO) - ({ what }));
#endif

  rc = map_objects(obj-({ 0 }), "ChkEquip", TO, what, flags) - ({ EQ_OK });
  if (sizeof(rc)) return stringp(rc[0]) ? rc[0] : EQ_FORBID;

  if (what->QueryNumberHands() && !Grip(what)) return EQ_NOHANDS;

  if (flags & EWF_WEAPON) {
    switch (what->QueryUsage())
    {
      case EQM_NONE : rc = 1; break;
      case EQM_WEAR : rc = AddArmour(what); break;
      case EQM_WIELD: rc = AddWeapon(what); break;
      case EQM_BOTH : rc = AddArmour(what)
                        && AddWeapon(what); break;
    }
  }

  if (!rc)
  {
    Ungrip(what);
    return EQ_FORBID;
  }
  else
  {
    if (!(flags & EWF_SILENT) && environment(TO))
    {  // Es necesario el chekeo de env porque los pnj que empuñan cosas desde el create no tienen env y petan
      tell_room(environment(TO), ({ MSG_SEE, capitalize(TO->QueryName())+" se equipa con "+sh+".\n"}), ({ TO }));
    }
    what->SetEquipped(TO);
  }

  if (obj) filter_objects(obj-({ 0 }), "NotifyEquip", TO, what, flags);

  return EQ_OK;
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
public varargs mixed Unequip(object what, int flags)
// Desequipa what si lo lleva equipado.
{
  mixed obj, rc;

  if (!what) return EQ_ERROR;

  obj = what->QueryEquipped();

  if (!obj || TO != obj) return EQ_ALREADY;

  if (rc = what->Query(P_NOUNEQUIP)) return stringp(rc) ? rc : EQ_FORBID;

#if __VERSION__ >= "3.3"
  obj = ({ what }) | all_inventory(TO); // ¿poner TODO el inventario?
#else
  obj = ({ what }) + (all_inventory(TO) - ({ what }));
#endif

  rc = map_objects(obj-({ 0 }), "ChkUnequip", TO, what, flags) - ({ EQ_OK });
  if (sizeof(rc)) return stringp(rc[0]) ? rc[0] : EQ_FORBID;

  if (what && what->QueryEquipped() && what->QueryNumberHands()) Ungrip(what);

  switch (what->QueryUsage())
  {
    case EQM_NONE : break;
    case EQM_WEAR : RemoveArmour(what, flags); break;
    case EQM_WIELD: RemoveWeapon(what, flags); break;
    case EQM_BOTH : RemoveArmour(what, flags)
                 && RemoveWeapon(what, flags); break;
  }

  what->SetEquipped(0);
  if (!(flags & EWF_SILENT) && environment(TO))
    tell_room(environment(TO), ({ MSG_SEE, capitalize(TO->QueryName())+" desequipa "+what->QueryShort()+".\n" }), ({ TO }));

  if (obj) filter_objects(obj-({ 0 }), "NotifyUnequip", TO, what, flags);

  return EQ_OK;
}

//---------------------------------------------------------------------------
// Funciones viejas dejadas por compatibilidad
//---------------------------------------------------------------------------

// Estas funciones son llamadas desde el AddItem para empuñar ob, ya son
// obsoletas, pero lo dejo hasta q las cambiemos todas.
public int wieldme(object ob)	  { return !Equip(ob, ob->QueryWeaponType()?EWF_WEAPON:0); }
public int wearme(object ob)	  { return !Equip(ob,  ob->QueryArmourType()?EWF_WEAPON:0); }

//---------------------------------------------------------------------------
// Fin Funciones viejas dejadas por compatibilidad
//---------------------------------------------------------------------------