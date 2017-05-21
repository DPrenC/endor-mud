/*
DESCRIPCION  : Gremio de exploradores
FICHERO      : /guilds/exploradores/exploradores.c
--------------------------------------------------------------------------------
*/


#include <gremios.h>
#include <wizlevels.h>
#include <guild.h>
#include <config.h>
inherit "std/guild";

public void create_ob() {
 ::create_ob();
  SetIntShort("La sede del grupo de exploradores");
  SetIntLong("Una estancia de paso para ajustarte el gremio con el que tienes que jugar en Endor-Mud.\n");

 SetIndoors(1);
 SetIntBright(20);

 SetGuildclass(GC_AVENTUREROS); //clase del gremio
 SetGuildname("Equipo de exploradores");  //nombre del gremio
 SetGuildDomain("pais-bree");
 SetCreators( ({"Orome"}) );                 //creador

 }

public void init(){

    ::init();
    if(!IS_LEARNER(TP)){
        cmd_join();
        "/room/ajustes"->ajustes();
    }
}

