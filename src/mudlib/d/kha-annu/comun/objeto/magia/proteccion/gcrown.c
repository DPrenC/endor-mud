/***************************************************************************/
/* Por Izet@Simauria, en espera a que Nemesis me la banee de Simauria :)   */
/* Fichero:      /d/Kha-annu/comun/objeto/proteccion/cromswrd.c            */
/* Descripcion:  Esta es la corona del Rey Belthain (nivel 80), rey de los */
/*               Enanos. Es una corona magica, que aumenta constitucion.   */
/*               Tiene AC = 17, ya que es un objeto magico. Y se vende por */
/*               7.000 de cobre en las tiendas.                            */
/* Creacion:     14 de Noviembre de 1998.                                  */
/* Modificacion: [I] 14 de Noviembre de 1998.                              */
/*               [Woo] Modificada                                          */
/***************************************************************************/

#include <combat.h>
inherit ARMOUR;

create() {
   ::create();
   SetStandard(AT_TIARA,5);
   SetIds( ({"corona","corona de oro","corona dorada"}) );
   SetAds( ({"una","la"}) );
   SetShort("la Corona Dorada");
   SetLong("\
Esta es la Corona Dorada. Esta corona identifica al Rey de la capital del "
"reino enano de Kha-annu. Esta adornada con numerosas joyas, y aunque parece "
"no ofrecer ninguna proteccion, debe asegurar bien la cabeza en numerosas "
"ocasiones. Parece que tiene algo escrito.\n"
   );
   SetValue(7000);
   SetWeight(1000);
   SetMagic(1);
}

void init() {
   ::init();
   add_action("Leer","leer");
}

int Leer(string str) {
   if (str == "corona" || str == "la corona" || str == "una corona" ||
       str == "corona dorada" || str == "la corona dorada" ||
       str == "una corona dorada"
      ) {
      write("\
En la parte interior de la corona pone: "
"              'Forjada durante la Segunda Edad de Simauria por "
"                 Alcelefin, el herrero-mago de Lad-Laurelin.'\n"
      );
      if (TP->QueryInvis() == 0) {
         say(
TP->QueryName()+" saca una corona dorada y lee una inscripción.\n"
         );
         return 1;
      } else return 1;
   } else return 0;
}

public varargs void NotifyEquip(object liv, object armour, int flags) {
  if (armour != TO) return;
    
   liv->AddConBonus(2);
   
   ::NotifyEquip(liv, armour, flags);
}

public varargs void NotifyUnequip(object liv, object armour, int flags) {
  if (armour != TO) return;
    
   liv->AddConBonus(-2);
   
   ::NotifyUnequip(liv, armour, flags);
}
