/*
DESCRIPCION  : Tutorial
AUTOR	     : [2008-03-22] Angor
*/

#include "./path.h"
#include <lock.h>

inherit ROOM;

#include "./tutorial.h"

int coger_cmd(string s) {
    int i;
    if ((i = member(({"espada de cofre","escudo de cofre","monedas de cofre"}),s)) >= 0) {
    	object ob = present("cofre", environment(TP));
    	if (ob){
    		if (ob->QueryLockState()==LOCK_OPEN){
	    		do_step(TUT_STEP_USE_OBJS, TP);
    		}else{
                	write("El cofre está cerrado. Debes abrirlo primero.\n");
                }
    	}
    }
  return 0;
}

int mov_cmd() {
	object ob = present("lista_tutorial",TP);
	if (ob) {
		if (ob->QueryStepDone(TUT_STEP_LOOK) &&
		    ob->QueryStepDone(TUT_STEP_INVENTORY) && 
		    ob->QueryStepDone(TUT_STEP_USE_OBJS)) {
		    do_step(TUT_STEP_MOV, TP);
		    return 0;
		}else{
                    write(TUT_STEP_NOT_DONE);
		    return 1;
		}
	}
  return 0;
}

create() {
  ::create();
  SetIntShort("el sotano del templo");
  SetIntLong(
"Esta pequeña habitación vacia parece un sótano. Las paredes están construidas "
"con grandes bloques de piedra sobre los que crecen líquenes debido a la "
"humedad. El suelo esta lleno de polvo y huele a cerrado. Un grueso portón "
"de madera conduce al norte.\n");
 SetIntNoise("El goteo del agua produce eco.\n");
 SetIntSmell("Esta habitacion lleva demasiado tiempo cerrada.\n");
 SetLocate("isla Limbo");
 SetIndoors(1);
 SetIntBright(50);
 AddExit("norte",TEMPLO("tutorial_1"));
 AddItem(PNJ("asthar_2"),REFRESH_HOME);
 ForbidAllMagic();
 
 AddItem("/d/limbo/comun/quest/tutorial/cofre",REFRESH_DESTRUCT,1);

 AddRoomCmd("tutorial",SF(tutorial_cmd));
 
 AddRoomCmd("m",SF(mirar_cmd));
 AddRoomCmd("mirar",SF(mirar_cmd));
 
 AddRoomCmd("i",SF(inv_cmd));
 AddRoomCmd("inventorio",SF(inv_cmd));
 AddRoomCmd("peso",SF(inv_cmd));
 
 AddRoomCmd("coger",SF(coger_cmd));
 
 AddRoomCmd("n",SF(mov_cmd));
 AddRoomCmd("norte",SF(mov_cmd));
 set_next_reset(120);
}
