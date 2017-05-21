/*=============================================================*
 |          << GOLDHAI.Bosque Wald [w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 27-08-98            |
 |             Ultima Modificacion........ 11-05-99            |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <moving.h>
inherit GBOSQUE;

int pasar_arbustos(string str)
{
    if(!str) return notify_fail("¿Qué es lo que quieres atravesar?\n"),0;
 if (str!="arbustos" && str!="vegetacion" && str!="ramas"
  && str!="los arbustos" && str!="entre arbustos" && str!="arbusto"
  && str!="hueco" && str!="paso" && str!="agujero")
  return notify_fail("Eso no lo puedes atravesar.\n"),0;
 TP->move(BWALD("puente"),M_SPECIAL,
 ({
   "desaparece entre los arbustos",
   "llega del este pasando entre los arbustos",
   "Te metes como puedes entre los arbustos y consigues llegar al otro lado"}));
 return 1;
}

create()
{
    ::create();
    SetIntShort("la orilla oeste del río Cashigan");
    SetIntLong("El ruido del agua golpeando las rocas de la orilla te indican que el río "
        "Cashigan está en la parte oeste aunque no lo puedes ver por la gran cantidad de "
        "arbustos que hay, entre los que destaca un pequeño hueco que parece conducir a algún "
        "lado. Los árboles del bosque te impiden ir hacia el este por lo que sólo puedes "
        "continuar al Norte y al Sur.\n");
    SetIntNoise("Aunque no lo ves puedes escuchar el agua del río Cashigan en el oeste.\n");
    AddDetail(({"hueco","paso","agujero","arbusto","arbustos"}),"Te fijas un poco más en el "
        "hueco que existe entre los arbustos. Parece ser que hay un pequeño paso que te "
        "permitirá atravesar los arbustos.\n");
    AddDetail(({"río","arroyo","agua","río cashigan","cashigan"}),"Los enormes arbustos te "
        "impiden ver el río.\n");
    AddRoomCmd("atravesar",SF(pasar_arbustos));
    AddRoomCmd("pasar",SF(pasar_arbustos));
    AddExit("norte",BWALD("borde_rio4"));
    AddExit("sur",BWALD("borde_rio6"));
    AddPnj();
    SetLocate("bosque Wald");
}
