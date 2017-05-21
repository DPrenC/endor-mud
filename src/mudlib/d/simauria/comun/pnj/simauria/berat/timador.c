/*
DESCRIPCION : timador
FICHERO     : /d/simauria/comun/pnj/simauria/berat/timador.c
MODIFICACION: 4-11-99 [Icaro];10-6-00[Maler]elimino retonnos;enmascaro magia y
lanzar
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <money.h>
#include <combat.h>
#include <properties.h>
#include <rooms.h>
#include <messages.h>
#define NOMBRE  (capitalize(TP->QueryName()))

inherit NPC;

object arma;

create() {
  ::create();
SetName("hombre");
AddAdjective("misterioso");
AddId("figura");
AddId("hombre misterioso");
AddId("hombre");
SetShort("hombre misterioso");
SetLong("No puedes distinguir ninguno de sus rasgos, en tal oscuridad.\n");
SetRace("humano");
SetWeight(70000);
SetLevel(5);
SetAggressive(0); //0 no, 1 si.
SetGender(1);// 1 masculino, 2 femenino
SetAlign(-10);
SetMaxHP(80);
SetHP(80);
AddQuestion("espada",W("El hombre te dice: Si quieres una de mis maravillosas "
"espadas, pon comprar espada, y por un precio razonable, la tendrás.\n"));
InitChats(1,({
//--------------------------------------------------------------------------------
  "El hombre misterioso te dice: ¿quieres una espada mágica?\n",
  "El hombre misterioso te dice: compra una de estas fabulosas espadas mágicas.\n",
  "El hombre misterioso te dice: acércate "+NOMBRE+", no te apetece una fabulosa espada?\n",

  }) );
}
init() {
  ::init();
  add_action("matar_cmd","matar");
  add_action("matar_cmd","magia");
  add_action("matar_cmd","lanzar");
}


int matar_cmd(){
  object who;
  int hp;

  who=TP;
  who->StopHunting(TO);

  write(W(
   "El hombre misterioso te detiene con su mano derecha y te pregunta: ¿que intentas hacer, acaso deseas tu muerte?, con un veloz movimiento de su mano izquierda, te noquea advirtiéndote, la próxima vez me enfadaré.\n"));

   tell_room(environment(TP), ({ MSG_SEE,
   NOMBRE+" ataca al hombre misterioso que le detiene con su mano derecha y le pregunta: ¿que intentas hacer, acaso deseas tu muerte?, con un veloz movimiento de su mano izquierda, noquea a "+NOMBRE+" advirtiéndole, que la próxima vez se enfadará\n"}), ({ TP }));

   hp=TP->QueryHP();
   if (hp>15) TP->SetHP(hp-10);
  return 1;
}

