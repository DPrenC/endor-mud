/*
[n] nemesis@Simauria
DESCRIPCION    : medallon magico que sube vida y mas cosas y kita otras
FICHERO        : /d/lad-laurelin/comun/objeto/magico/medalc.
CREACION       : Abril 99 (Alura).
*/

#define reghp (TP->QueryRegHP())
#define to (TO)

#include <properties.h>
#include <combat.h>
#include <health.h>

inherit ARMOUR;

public int colocar_medal(string str)
{
    object estatua,medallon;
    string donde, que;

    if (   !str || sscanf(str, "%s en la %s", que, donde) != 2
        && sscanf(str, "%s a %s", que, donde) != 2
        && sscanf(str, "%s en %s", que, donde) != 2)
        {
            return notify_fail("¿" + CAP(query_verb()) + " qué dónde?\n");
        }
    estatua=present("estatuilla",TP);
    medallon = TO;
    if (   !estatua ||!medallon || present(que, TP) != medallon
        || present(donde, TP) != estatua)
    {
        return notify_fail("¿" + CAP(query_verb()) + " qué dónde?\n");
    }
    if (estatua->Query("llevamedal"))
    {
        return notify_fail("La estatuilla ya lleva puesto un medallón.\n",
                           NOTIFY_NOT_VALID);
    }
    write("Colocas el medallón en el cuello de la estatua, el cual vuelve a "
          "formar parte de ella.\n");
    say(CAP(TNAME) + " coloca un medallón en una estatuilla.\n", TP);
    estatua->Set("llevamedal",1);
    return remove();
}


init()
{
    ::init();
    add_action("colocar_medal","colocar");
    add_action("colocar_medal","colgar");
    add_action("colocar_medal", "poner");
}

create()
{
    ::create();
    SetAds(({"de Dehim"}));
     SetIds(({"medallon","medalla","medallón"}));
    SetShort("el Medallón de Dehim");
    SetLong("El medallón es de reluciente plata. Tiene un aura luminosa alrededor, lo "
            "cual te hace pensar que no es una medalla simplemente decorativa ... "
            "En él, puedes ver grabada la figura del dios Dehim.\n");

    SetAC(2); //cuanto protege
    SetWeight(50);              //peso en gramos
    SetMaterial(M_PLATINO);
    SetValue(1000000);
    SetArmourType(AT_AMULET);
    SetSize(P_SIZE_GENERIC);
    SetResetQuality(100);         //calidad estado en el que esta 0-100
    Set(P_NOBUY, 1);
    SetMagic(1);

}

public varargs void NotifyEquip(object liv, object armour, int flags) {
  if (armour != TO) return;
    
   liv->AddConBonus(3);
   liv->AddStrBonus(-5);
   
   ::NotifyEquip(liv, armour, flags);
}

public varargs void NotifyUnequip(object liv, object armour, int flags) {
  if (armour != TO) return;
    
   liv->AddConBonus(-3);
   liv->AddStrBonus(5);
   
   ::NotifyUnequip(liv, armour, flags);
}

