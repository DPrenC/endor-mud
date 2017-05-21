/* [Woo] Modificado */

inherit NPC;
#include "./path.h"
#include <guild.h>


create()
{
   ::create();

   SetStandard("Lord Uggly","orco",([ GC_LUCHADOR: 15]),GENDER_MALE);
   SetIds(({"lord","lordUggly","Uggly"}));
   SetShort("Lord Uggly el poderoso");
   SetLong("Lord Uggly es un orco enorme con unos músculos muy poderosos debido a\n"
    "las muchas batallas en las que ha participado, de todas esas batallas guarda\n"
    "recuerdos, como pueden ser un montón de cicatrices por todo su cuerpo, las\n"
    "cuales las muestra con orgullo por ser marcas de victorias. Está sentado en\n"
    "un trono de piedra labrado toscamente por manos orcas. Suele mirar a todo el\n"
    "mundo con cara de pocos amigos y soltar amenazas por doquier. Pero por lo demás\n"
    "es un gran tipo.\n");
   SetAlign(-100);
   InitChats(7, ({"Lord Uggly te mira con cara de pocos amigos.\n",
   "Lord Uggly dice: ¿Qué diablos haces aqui?\n",
   "Lord Uggly exclama: ¡¡Malditos enanos!!\n",
   "Lord Uggly dice: ¡Ayudame a salir de aqui!.\n"}));

  }

