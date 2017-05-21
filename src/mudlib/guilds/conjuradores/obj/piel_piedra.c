/* SIMAURIA '/guilds/conjuradores/obj/piel_piedra.c'
   =================================================
   [w] Woo@simauria
   [h] Nyh@simauria

   25-11-99 [w] Usado por el conjuro 'piel de piedra'.
   20-12-04 [h] Arreglo un bug
*/

#include <properties.h>
#include <moving.h>
inherit "/std/thing";

create()
{
 ::create();
 SetIds(({"conjuro_piel_piedra"}));
 SetShort(0);
 SetLong(0);
 SetWeight(0);
 Set(P_NODROP,1);
 Set(P_NOGET,1);
 Set(P_NOGIVE,1);
 call_out("remove",10);
}

void Endurecer(object jug, int tiempo)
{
 while(remove_call_out("remove")!=-1);
 while(remove_call_out("Restablecer")!=-1);
 TO->move(jug, M_NOCHECK);
 jug->ModifyAttr("AC",8);
 call_out("Restablecer", tiempo, jug);
}

int Restablecer(object jug)
{
 while(remove_call_out("Restablecer")!=-1);
 if (jug)
 {
  jug->ModifyAttr("AC",-8);
  tell_object(jug,"Notas como tu piel vuelve al estado normal.\n");
 }
 remove();
 return 1;
}
