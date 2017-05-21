/*
** Guildmaster del Gremio de Guerreros
** Autor: [n] Nemesis@Simauria, Ago'99
** Update: [n] 18-May-01 intercepto el Die() pa que el que lo mate (Jezz)
**             se lleve un bonito premio... >:)
*/

#include "wguild.h"
#include <wizlevels.h>
#include <moving.h>
#include <skills.h>
#include <config.h>
#include <living.h>
#include <rooms.h>
#include <messages.h>

inherit NPC;

public void create() {
  ::create();
 SetStandard("General Drix","humano",([GC_GUERRERO: 100]),1);
  SetShort("General Drix, el guildmaster");
  SetLong(
    "Drix es muy grande, los músculos se marcan en cada centímetro de su cuerpo.\n"
    "No estas seguro de si su expresión es una mueca malvada o un intento de\n"
    "mostrar una sonrisa amigable. Bueno, al menos no te ha atacado, así que\n"
    "seguramente es una sonrisa.\n");
  SetIds(({"guildmaster","master","general","Drix","hombre","drix"}));
  SetAds(({"enorme","general","malvado","amigable"}));
  SetGender(GENDER_MALE);
  SetMaxHP(2345);
  SetHP(2345);
  SetAlign(-100);
//[Nyh] Se la quito, que peta de vez e ncuando
//  AddItem("/players/nemesis/experimental/arma",REFRESH_REMOVE,SF(wieldme));
}


Defend(int dam, int dtype, object weapon) {
object who;
int i;
if (TP==TO)
 for (i = 0; (who=previous_object(i))==TO;i++);
else who=TP;
if (!who) return;
else {
 write("...\n"
 "Drix te coge del cuello y te levanta en el aire.\n"
 "Con voz profunda dice: '¿De verdad quieres hacer eso?'\n"
 "Te das cuenta de que realmente no deseas hacerlo y él te deja en el suelo.\n");
 tell_room(environment(TP), ({ MSG_SEE,
 "...\nDrix coge a "+who->QueryName()+" por el cuello y le levanta en el aire.\n"
 "Con voz profunda le dice: '¿De verdad quieres hacer eso?'\n"+who->QueryName()+
 " se pone azul y Drix le suelta.\n"}), ({ TP }));
  who->StopHunting(TO);
  return;
 }

}


public varargs void Die(mixed silent) {
  object killer;

  killer = PO;
  tell_object(killer,
"Un aura dorada rodea de pronto a Drix, cuyos ojos se vuelven rojos de\n"
"repente mientras comienza a echar espuma por la boca. Dando un grito\n"
"sobrehumano levanta su hacha y la clava en tu pobre cuerpo, partiéndolo\n"
"en dos pedazos palpitantes.\n"
"Lo último que ves es el enorme pie de Drix aplastando tu cráneo...\n");
 say("Un aura dorada rodea de pronto a Drix, cuyos ojos se vuelven rojos de\n"
"repente mientras comienza a echar espuma por la boca. Dando un grito\n"
"sobrehumano levanta su hacha y la clava en el pobre cuerpo de "+killer->QueryShort()+",\n"
"partiéndole en dos pedazos palpitantes.\n"
"Finalmente, Drix aplasta el cráneo de "+killer->QueryShort()+" con su pie, desparramando\n"
"sus sesos por el suelo...\n"
 );
killer->Die();
}