#include "./path.h"
#include <combat.h>
#include <properties.h>
#define RAZA TP->QueryRace()
inherit "/std/armour";

string title;

void create() {
  ::create();
  SetStandard(AT_HELMET,1,P_SIZE_GENERIC);
  SetShort("una mascara negra");
  SetLong(
"Es una simple mascara de color negro. Está hecha de piel oscura\n"
"Es muy ligera y cubre toda la cara.\n");
   SetIds( ({"mascara","mask","mascara negra"}) );
   SetAds( ({"la","una"}) );
   SetWeight(100);
   SetValue(600);
  Set(P_NOGIVE, "Mejor no darle tu mascara a nadie.\n");
  Set(P_NODROP, "Nunca dejarías un objeto de tu Gremio por ahí.\n");
  Set(P_NOSELL, "Vender tu mascara? Jamas!\n");
}

void init() {
  ::init();
   add_action("Quitando","quit");
   add_action("Quitando","exit");
   add_action("Quitando","reiniciar");
   add_action("Vestir","ponerse");
   add_action("Vestir","vestir");
   add_action("Vestir","usar");
   add_action("Desvestir","quitarse");
   add_action("Desvestir","desvestir");
}

int Vestir(string str) {
object ob;
   if (!str) return 0;
   if (!ob = present(str,TP) ) return 0;
   if (ob!=TO) return 0;
   if (TP->QueryGender() == GENDER_FEMALE) {
      TP->SetName("Una "+RAZA+" enmascarada");
      TP->SetShort("una "+RAZA+" enmascarada");
   } else {
      TP->SetName("Un "+RAZA+" enmascarado");
      TP->SetShort("un "+RAZA+" enmascarado");
   }
   TP->AddId(RAZA);
return 0;
}

int Desvestir(string str) {
object ob;
   if (!str) return 0;
   if (!ob = present(str,TP) ) return 0;
   if (ob!=TO) return 0;
   TP->SetShort(capitalize(getuid(TP)));
   TP->SetName(capitalize(getuid(TP)));
   TP->RemoveId(RAZA);
return 0;
}

Quitando() {
   if (TO->QueryWear() == TP) {
      TO->Unequip();
      TP->SetShort(capitalize(getuid(TP)));
      TP->SetName(capitalize(getuid(TP)));
   }
   TP->RemoveId(RAZA);
return 0;
}
