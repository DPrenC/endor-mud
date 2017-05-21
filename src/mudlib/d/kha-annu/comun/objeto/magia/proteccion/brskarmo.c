/***************************************************************************/
/* Fichero:     brskarmo.c   [I] Izet@Simauria                             */
/* Descripcion: Armadura Berserk. El personaje que se ponga esta armadu-   */
/*              dura, entrara en un estado frenetico, en el que los golpes */
/*              le haran menos danyo, y la fuerza con la que golpee aumen- */
/*              tara en +3.                                                */
/* Creacion:    15 de Noviembre de 1998.                                   */
/* Modific.:    15 de Noviembre de 1998.                                   */
/*              [Woo] Modificada                                           */
/***************************************************************************/

#define NAME (TP->QueryName())
#include <combat.h>
#include <properties.h>
inherit ARMOUR;

create() {
   ::create();
   SetStandard(AT_MAIL,10,P_SIZE_GENERIC);
   SetIds ( ({"armadura","placas","armadura berserk","armadura de placas"}) );
   SetAds ( ({"una","la"}) );
   SetShort("la Armadura Berserk");
   SetLong("\
Es una armadura de placas de guerra. De los hombros sobresalen dos grandes "
"cuchillas metalicas en forma de media luna. Los pectorales estan hechos de "
"oro macizo, y la parte abdominal es de puro mithril. La armadura desprende "
"un brillo azul al reflectar con la luz.\n"
   );
   SetValue(20000);
   SetWeight(25000);
   SetMagic(1);
}

public varargs void NotifyEquip(object liv, object armour, int flags) {
  if (armour !=TO) return;

  write("Sientes una furia descontrolada al vestir la Armadura Berserk.\n");
  if (liv->QueryInvis() != 0) {
    say("Ves como los ojos de "+liv->QueryName()+" se inyectan en sangre.\n");
  }
  liv->AddStrBonus(2);
  liv->AddProteccion(DT_BLUDGEON,10);
  liv->AddProteccion(DT_PIERCE,10);
  liv->AddProteccion(DT_SLASH,10);
  liv->AddDexBonus(-5);
  call_out("Berserk",2,TP);

  ::NotifyEquip(liv, armour, flags);
}

public varargs void NotifyUnequip(object liv, object armour, int flags) {
  if (armour != TO) return;

  write("La furia disminuye en tu interior al quitarte la armadura.\n");
  if (liv->QueryInvis() != 0) {
     say(liv->QueryName()+" suspira con alivio al quitarse su armadura.\n");
  }
  liv->AddStrBonus(-2);
  liv->AddProteccion(DT_BLUDGEON,-10);
  liv->AddProteccion(DT_PIERCE,-10);
  liv->AddProteccion(DT_SLASH,-10);
  liv->AddDexBonus(5);
  remove_call_out("Berserk");

  ::NotifyUnequip(liv, armour, flags);
}

void Berserk(object ob) {
int x;
   x = random(8);
   switch(x) {
     case 0..2: write("Sientes como la furia se apodera de ti.\n");
                say(ob->QueryName()+" dice: APARTATE DE MI!\n");
                call_out("Berserk",60,ob);
                break;
     case 3..5: write("La furia aumenta en tu interior.\n");
                say(ob->QueryName()+" dice: QUIERO MATAR!\n");
                call_out("Berserk",2,ob);
                break;
     case 6..8: write("Sientes unas ganas irreprimibles de acabar con\n"
                      "lo que te rodea.\n");
                say(ob->QueryName()+" dice: QUIERO TU SANGREEE!\n");
                call_out("Berserk",2,ob);
                break;
   }
}
