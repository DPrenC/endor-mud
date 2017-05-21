/* El tendero de la tienda de provisiones de Khurton
   9/10/98 [o] Okkita@Simauria
*/
#include "./path.h"

inherit NPC;

create ()
{
   ::create();
   SetName("Kistlin");
   SetShort("un kender atareado y barrigon");
   SetIds(({"kender","Buenabarriga","barrigon","atareado"}));
/*
   SetAds("un");
*/
   SetLong(
"Un activo kender (cual no lo es!) te mira con ojos llenos de curiosidad. "
"Ademas de las ropas kender tipicas lleva puesto un delantal de cuero y "
"recorre la tienda de un lado a otro, mirando y colocando cosas.\n");
   SetRace("kender");
   SetGender(1);
   SetLevel(5);
   InitChats(2, ({
"El kender atareado y barrigon dice: Hola!, te interesa ver algo?.\n",
"El kender atareado y barrigon revisa su mercancia.\n",
"El kender atareado y barrigon murmulla: ...donde estaba aquella...\n",
"El kender atareado y barrigon se rasca la barriga.\n",
"El kender atareado y barrigon busca algo en los estantes.\n",
"El kender atareado y barrigon pregunta: donde habre puesto ese lapiz?.\n",
                 }) );
   InitAChats(8, ({
"El kender atareado y barrigon intenta huir de ti.\n",
"El kender atareado y barrigon te grita: antipatico!\n",
"El kender atareado y barrigon grita: a mi la guardia!\n",
"El kender atareado y barrigon intenta escabullirse de ti.\n",
                 }) );
}
/*-------------------------------------------------------------*/
