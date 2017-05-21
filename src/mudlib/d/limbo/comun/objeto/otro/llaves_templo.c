/*
DESCRIPCION  : Llaves del templo para el quest de "las llaves del templo de Asthar"
FICHERO      : /d/limbo/comun/obj/otro/llaves_templo.c
MODIFICACION : 21-09-98 [Angor@Siamuria] Creacion.
*/

inherit THING;
#include <properties.h>

create(arg){
 ::create(arg);
 AddId("llaves_templo");
 AddId("llaves");
 AddAdjective(({"unas","del templo"}));
 SetShort("las llaves del templo");
 SetLong(
 "Son tres llaves de tamanyo mediano hechas de plata. Cada una tiene incrustada\n"
 "en su cabeza una gema de gran valor y las tres se hallan engarzadas en una\n"
 "argolla de oro. Son las llaves del templo de Asthar.\n");
 SetWeight(25);
 SetValue(4);
 Set(P_NOSELL,1);
}
