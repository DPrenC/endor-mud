/* El tendero de la tienda de curiosidades de Khurton
   9/10/98 [o] Okkita@Simauria
*/
#include "./path.h"

inherit NPC;

create ()
{
   ::create();
   SetName("Irdil");
   SetShort("un perspicaz y joven kender");
   SetIds(({"kender","Manosligeras","perspicaz","joven"}));
/*
   SetAdds("un");
*/
   SetLong(
"Un joven kender que te mira de arriba a abajo una y otra vez. "
"Esta vestido con las ropas kender tipicas, y su largo pelo esta recogido "
"en un gracioso copete. LLeva una gran cantidad de bolsas colgando de la "
"cintura, de donde saca extranyos objetos, que mira y vuelve a guardar. "
"Su traviesa mirada te analiza continuamente, como si buscara en ti algo "
"que merezca la pena 'guardar'.\n");
   SetRace("kender");
   SetGender(1);
   SetLevel(5);
   InitChats(2, ({
"El perspicaz y joven kender saca algo pequenyo y brillante de una de sus "
"numerosas bolsas. Lo mira, le da vueltas, lo muerde y finalmente, lo pone "
"de nuevo en la bolsa.\n",
"El perspicaz y joven kender dice: Hola!, te interesaria comprar algo? Tengo cosas muy interesantes!\n",
"El perspicaz y joven kender dice: Hmm..., curioso...\n",
"El perspicaz y joven kender se coloca el copete.\n",
"El perspicaz y joven kender recoloca todas sus bolsas.\n"}) );
   InitAChats(10, ({
"El perspicaz y agil kender esquiva tu ataque con una graciosa finta. "
"Oops, al hacer la finta se le caen algunos de los objetos de sus bolsas.\n"
"El perspicaz y agil kender dice: hmm, te importa esperar un momento a que recoga mis cosas?.\n",
"El perspicaz y agil kender dice: Que emocionante, una pelea!. "
"Veras, es que yo siempre quise participar en una buena pelea..., "
"claro que no pensé que pudiera doler tanto...\n",
"El perspicaz y joven kender grita: Hey, que aqui hay pelea!",
"El perspicaz y joven kender grita: Pelea!, diversion asegurada!\n",
"El perspicaz y joven kender para tu ataque, coge tu arma, la mira,\n"
"y te la da diciendo: Bah, no me gusta, toma!, es tuya.\n",
"El perspicaz y joven kender te intenta pegar un moco!.\n" }) );
}
/*-------------------------------------------------------------*/
