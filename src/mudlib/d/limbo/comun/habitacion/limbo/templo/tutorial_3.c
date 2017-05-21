/*
DESCRIPCION  : salida del tutorial
AUTOR	     : [2008-03-22] Angor
*/

#include "./path.h"
#include <moving.h>
inherit ROOM;

int ir_templo(){
  write("Comienzas a ascender por la escalera de madera hasta la trampilla. Una vez alli, "
        "empujas la pesada plancha de madera y sales. Al caer de nuevo, la trampilla hace "
        "un ruido metálico como si se hubiese atrancado al otro lado.\n");
  say(   TP->QueryName()+" sube por la escalera, abre la trampilla y sale de aquí.\n");
  tell_room( TEMPLO("pasillo"), "Se levanta la trampilla y "+TP->QueryName()+" sale por ella.\n");
  TP->move(TEMPLO("pasillo"),M_SILENT);
  return 1;
}


create() {
  ::create();
  SetIntShort("la escalera al templo");
  SetIntLong(
"A partir de aquí comienza un pasillo que conduce a varias habitaciones "
"del sótano del templo. Es un lugar polvoriento y poco transitado. Una "
"escalera de madera cubierta de telarañas conduce a una trampilla en "
"el techo.\n");

 SetIntNoise("No se oye gran cosa.\n");
 SetIntSmell("Hay polvo por todas partes.\n");
 SetLocate("isla Limbo");
 SetIndoors(1);
 SetIntBright(50);
 AddExit("norte",TEMPLO("tutorial_2"));
 AddExit("arriba",SF(ir_templo));
 ForbidAllMagic();
 set_next_reset(120);
}
