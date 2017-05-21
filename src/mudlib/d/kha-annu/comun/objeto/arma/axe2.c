/*****************************************************************/
/*                Realizado por Fran@Simauria                  */
/*  Modificado por Izet@Simauria porke estaba muy furro.         */
/*  Anyadidos las estructuras IF para ke aumente el WC           */
/*  si se es enano.                                              */
/*****************************************************************/

#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>



inherit WEAPON;

create() {
  ::create();
  SetStandard(WT_HACHA, 2, P_SIZE_MEDIUM, M_ACERO);
  SetAds(({"un","gran","metal"}));
  SetIds(({"hacha","arma"}));
  AddId("hacha");
  SetShort("un gran hacha de guerra");
  SetLong(
"Es un gran hacha de guerra de las que usan los enanos. Notas la gran\n"
"calidad propia de las herrerias enanas.\n"
"Tiene un mango como de un metro, hecho de madera y con tiras de cuero\n"
"negro, parece durisimo.Las hojas son muy grandes y afiladas.\n"
"Es una magnifica arma para la lucha.\n"
"Reconoces unas escrituras en idioma comun en una de las hojas del hacha.\n"
);

  if (TP->QueryRace("enano")) SetWC(14);
  else { SetWc(11); }

  /* Correcion de Gorthem */

  SetWeight(9000);
  SetValue(10);
  SetDamType(DT_SLASH);
  SetResetQuality(100);
  Set(P_NOGET, 0);
  Set(P_NODROP, 0);
  Set(P_NOSELL, 0);
  Set(P_NOBUY, 0);
}
init() {
   ::init();
     add_action("Leer","leer");
}

Leer(string str) {
    if ( (str != "hoja") && (str != "hojas") && (str != "hacha") &&
         (str != "escritura") && (str != "escrituras") ) {
         /* return 0 por si hay otra funcion de leer en la habitacion */
         /* o en algun otro objeto que lleve el jugador */
         return 0;
     }
     else {
        write("Lees las escrituras de la hoja del hacha de combate:\n"
"\tIlustrisimas Herrerias de la ciudad de Kha-annu\n"
"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
"\tAleacion de Oro, Platino, Mithril y un metal\n"
"\t    extranyo otorgado por los cielos.\n");
        return 1;
     }
}
