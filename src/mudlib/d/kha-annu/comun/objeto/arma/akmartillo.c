/* Kha-annu.SIMAURIA '/d/Kha-annu/comun/armas/akmartillo.c'
/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
\  [o] Okkita                                                        /
/                                                                    \
\   Un martillo de guerra enano. Pertenece a la secta de los         /
/   Ahkorianos, enemigos acerrimos de los elfos.                     \
\   +3 WC para enanos                                                /
/   10 -> minimo fuerza para blandirlo. Excepto enanos.              \
\   Explota si lo intenta blandir un elfo, elfo-oscuro o medio-elfo. /
/                                                                    \
\   26/05/97 [o] Fecha creacion. Faltan cosas por hacer......        /
/                Ver funcion CheckWield.                             \
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
*/

#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>


inherit WEAPON;

string raza;                  // [o] Para mas adelante.
#define FUERZA_MINIMA 10      // [o] Fuerza necesaria para poder blandirlo.

create() {
  ::create();
  SetShort("un martillo labrado");
  SetLong(
"Un martillo de guerra enano. La cabeza esta fabricada en mithril y el\n"
"mastil esta recorrido por runas, que parecen conformar un mensaje.\n");
  SetStandard(WT_MAZA, 2, P_SIZE_MEDIUM, M_TITANIO);
  SetIds( ({"martillo","arma"}) );
  SetAds(({"labrado","mithril","enano"}));
  SetWC(10);
  SetDamType(DT_BLUDGEON);
  SetWeight(12000);
  SetValue(3000);
  SetResetQuality(100);
  SetReadMsg(
"En honor de Ahkora, Gran Jefe de Sacerdotes, Destructor de Elfos.\n");
}

remove_me(object ob) {
  if (!ob) return 0;
  if (!TP) return 0;
  TP->Defend(5+random(20),DT_ZAP,TO);
  remove();
  if (ob) destruct(ob);
  return 1;
}

CheckWield(object wielder) {
/* [o] Es un arma hecha para enanos..... */

    if (!TP) {return 0;}
    raza = TP->QueryRace();
    	 if(raza == "enano") {
               write(
"En el mismo momento en que la blandes, sientes que el Gran Ahkora esta\n"
"contigo.\n");
	TO->SetWC(13);
        return 1;
            }
         else

/* [o] Los elfos mejor que ni lo toquen..... */

         if((raza == "elfo") || (raza == "elfo-oscuro") ||
            ( raza == "medio-elfo") ) {
              call_out("remove_me",1,TO);
              write(
"En cuanto lo sostienes empieza a vibrar y emitir un leve zumbido...\n"
"BOOOM! El martillo explota ruidosamente.\n");


/* Aqui falta algo que me evite que salga el mensaje "You wield martillo",
mirarselo bien. Vamo a ve..... */

            }
         else
         if ((TP->QueryStr() < FUERZA_MINIMA))
         {
         write("Aumpf!, pesa demasiado para que puedas blandirla.\n");
         return 0;                  // [o] Fallo.
         }
         else
         TO->SetWC(10);
         return 1;
}
