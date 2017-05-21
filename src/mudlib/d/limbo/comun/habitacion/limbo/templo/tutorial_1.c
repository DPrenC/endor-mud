/*
DESCRIPCION  : Tutorial
AUTOR	     : [2008-03-22] Angor
*/

#include "./path.h"
inherit ROOM;

#include "./tutorial.h"

int comer_cmd(string s) {
    int i;
    if (s){
    	object ob = present(s,TP);
    	if (ob){
			//write("debug:obj existe\n");
	    	if ((i = member(({"manzana","cerveza"}),s)) >= 0) {
				do_step(TUT_STEP_HEALTH, TP);
				//write("debug: actualiza tutorial");
			}
		}
    }
	//no procesar el comando, lo hace el objeto en si
    return 0;
}

int mov_cmd() {
	object ob = present("lista_tutorial",TP);
	if (ob) {
		if (ob->QueryStepDone(TUT_STEP_HEALTH)) {
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
   
  SetIntShort("el almacen del templo");
  SetIntLong(
"Esta habitación parece algún tipo de almacen ya que hay grandes cajones "
"de madera por todas partes. No parece que la gente venga a menudo pues "
"el suelo esta lleno de polvo y huele a cerrado.\n");
 SetIntNoise("El goteo del agua produce eco.\n");
 SetIntSmell("Esta habitacion lleva demasiado tiempo cerrada.\n");
 SetLocate("isla Limbo");
 SetIndoors(1);
 SetIntBright(50);
 AddExit("sur",TEMPLO("tutorial_0"));
 AddExit("oeste",TEMPLO("tutorial_2"));
  
 AddItem(PNJ("asthar_2"),REFRESH_HOME);
 ForbidAllMagic();
 
 AddRoomCmd("tutorial",SF(tutorial_cmd));
 
 AddRoomCmd("m",SF(mirar_cmd));
 AddRoomCmd("mirar",SF(mirar_cmd));
 
 AddRoomCmd("i",SF(inv_cmd));
 AddRoomCmd("inventorio",SF(inv_cmd));
 AddRoomCmd("peso",SF(inv_cmd));

 //AddRoomCmd("comer",SF(comer_cmd));
 //AddRoomCmd("beber",SF(comer_cmd));
 AddItem("/d/limbo/comun/quest/tutorial/manzana_tutorial",REFRESH_DESTRUCT,2);
 AddItem("/d/limbo/comun/quest/tutorial/cerveza_tutorial",REFRESH_DESTRUCT,1);
 
 AddRoomCmd("o",SF(mov_cmd));
 AddRoomCmd("oeste",SF(mov_cmd));
 
 set_next_reset(120);
}

init()
{
  ::init();
  add_action("comer_cmd","comer");
  add_action("comer_cmd","beber");
  //add_action("comer_cmd","dummy");
}