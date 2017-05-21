/*
DESCRIPCION  : Tutorial
AUTOR	     : [2008-03-22] Angor
*/

#include "./path.h"
inherit ROOM;

#include "./tutorial.h"

int preguntar_cmd(string s) {
    int i;
    //write("str="+s+".\n");
    if ((i = member(({"a asthar sobre dioses","a asthar sobre Dioses"}),s)) >= 0) {do_step(TUT_STEP_COMM, TP);}
  return 0;
}

int decir_cmd() {
    do_step(TUT_STEP_COMM, TP);
  return 0;
}

int help_cmd() {
    do_step(TUT_STEP_HELP, TP);
  return 0;
}

int mov_cmd() {
	object ob = present("lista_tutorial",TP);
	if (ob) {
		if (ob->QueryStepDone(TUT_STEP_COMBAT) &&
		    ob->QueryStepDone(TUT_STEP_SKILL) && 
		    ob->QueryStepDone(TUT_STEP_COMM) &&
   		    ob->QueryStepDone(TUT_STEP_HELP) ) {
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
  SetIntShort("el pasillo del sotano del templo");
  SetIntLong(
"Este pasillo conduce a varias habitaciones del sótano del templo. Hay grietas "
"entre los grandes bloques de piedra que forman las paredes donde probablemente "
"se habiten ratas. El suelo es polvoriento y hay telarañas en los rincones.\n");
 SetIntNoise("Se oyen chillidos de ratas al otro lado de la pared.\n");
 SetIntSmell("Hay polvo por todas partes.\n");
 SetLocate("isla Limbo");
 SetIndoors(1);
 SetIntBright(50);
 AddExit("sur",TEMPLO("tutorial_3"));
 AddExit("este",TEMPLO("tutorial_1"));

 ForbidAllMagic();
 
 AddItem(PNJ("rata_tutorial"),REFRESH_DESTRUCT,1);

 AddRoomCmd("tutorial",SF(tutorial_cmd));
 
 AddRoomCmd("habilidades",SF(skill_cmd));
 AddRoomCmd("s",SF(mov_cmd));
 AddRoomCmd("sur",SF(mov_cmd));

 AddRoomCmd("dormir",SF(dormir_cmd));
 AddRoomCmd("preguntar",SF(preguntar_cmd));
 AddRoomCmd("decir",SF(decir_cmd));
 AddRoomCmd("ayuda",SF(help_cmd));

 AddItem(PNJ("asthar_2"),REFRESH_HOME);
 set_next_reset(120);
}
