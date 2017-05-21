/*
DESCRIPCION  : troll a la entrada del edificio de suministros
FICHERO      : /d/limbo/comun/pnj/troll.c
MODIFICACION : 20-09-98 [Angor@Siamuria] Creacion.
               10-10-99 [Woo] Toqueteado...
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <messages.h>

inherit NPC;

#define AO      (TP->QueryGenderEndString())
#define NOMBRE  (capitalize(TP->QueryName()))

create() {
  ::create();
 SetStandard("Harald","humano",20,GENDER_MALE);
  SetShort("Harald el minero");
  SetLong(
"Harald es un viejo y humano de aspecto frágil. Tiene la piel ajada por el sol y pegada a los huesos. Te mira sin prestar demasiada atencion a traves de unos parpados casi cerrados al tiempo que fuma lentamente tabaco en una pipa de hueso. Por su vestimenta, sabes que es uno de los siervos de los dioses en la isla Limbo. Quizás pueda ayudarle.\n");

  SetIds(({"humano","siervo","Harald","harald"}));
  SetAds(({"un","siervo","viejo","humano"}));
  SetAlign(0);
  SetAC(3);
  SetNoGet("Harald dice: ¿Que pretendes hacer? ¿Cargar con un pobre viejo como yo? Seguro que tienes mejores cosas que hacer...\n");
  SetAggressive(0);

  AddQuestion(({"angor","Angor"}),
  "¿Angor? Angor es un... impresentable... No me importa que me oiga si anda por aquí cerca, que a mis años ya da todo igual... Mira que le dije veces que a mi el trabajo que me interesaba era en el puerto, donde podria pescar de vez en cuando... Y el me envio aquí a la mina.\n");

  AddQuestion(({"mina"}),
  "Lleva tiempo abandonada pero aun se puede encontrar algo de valor. Lleva cuidado si bajas pues probablemente estará llena de bichos.\n");

  AddQuestion(({"lampara"}),
"Hij"+AO+", la mina es muy oscura y es fácil perderse. Ahí abajo una lámpara es tu mejor amiga. Si no tienes una yo las vendo.\n");

Set(P_CANT_FIGHT,1);
Set(P_CANT_STEAL,1);

  InitChats(2,({
  "Harald da una calada a la pipa y saborea el humo lentamente...\n",
  "Harald se seca el sudor de la frente\n",
  "Harald murmura algun insulto contra el dios Angor.\n",
  "El tabaco de la pipa tiene un fuerte aroma que inunda el lugar.\n",
  "Harald te dice: lleva cuidado en la mina, los tuneles no están en buen estado.\n",
  "Harald te mira y comenta: yo de tu compraría una lámpara si tienes la intención de aventurarte en la mina.\n",
  "Harald masculla algo sobre Angor...\n"}) );

}


