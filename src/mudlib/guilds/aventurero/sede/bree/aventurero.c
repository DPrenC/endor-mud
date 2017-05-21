/*
DESCRIPCION  : Gremio de trotamundos, escursionistas  o aventureros
FICHERO      : /guilds/aventurero/sede/bree/aventurero.c
--------------------------------------------------------------------------------
*/
#include <gremios.h>
#include <wizlevels.h>
#include <guild.h>
#include <config.h>
inherit "std/guild";

public void create_ob() {
 ::create_ob();
  SetIntShort("Un humilde agujero hobbit");
  SetIntLong("Te encuentras en el interior de un pequeño y humilde agujero hobbit.\n"
  "La estancia, excavada en el flanco de la colina, oficia de cuarto de estar, cocina y "
  "distribuidor. Una ventana da al oeste, sobre el discreto jardín, y en el muro sur, "
  "una puerta da acceso a la habitación del propietario. A un lado, el hogar de piedra "
  "sirve para dar calor y cocinar.\n"
  "Frente al fuego y orientada hacia la ventana hay una butaca de respaldo alto.\n"
  "Varios ajados mapas cuelgan de las paredes, junto a diversos objetos y armas. Una "
  "pequeña mesa está colocada bajo la ventana y un gran arcón reposa en un rincón.\n"
  "Suelo y paredes están revestidos de losetas de piedra gris, lo que da a la vivienda "
  " un aspecto espartano y humilde, aunque no descuidado.\n");
  AddDetail("hogar",
  "Un sencillo hogar de piedra sobre el que cuelga una olla de hierro.\n");
  AddDetail("olla",
  "Una vieja pero limpia olla de hierro que cuelga sobre el hogar.\n");
  AddDetail("butaca",
  "Una butaca repujada de piel con respaldo alto y aspecto confortable.\n");
  AddDetail("mapas",
  "Varios mapas cuelgan de las paredes, recorridos por líneas con diminutas notas "
  "garrapateadas al carboncillo.\n");
  AddDetail("armas",
  "Algunas espadas cortas, dagas, un hacha y una vara tallada para caminar cuelgan de "
  "los muros.\n");
  AddDetail("objetos",
  "Diversos objetos que el hobbit ha ido acumulando durante sus vagabundeos. Puede verse "
  "desde un retorcido colmillo con grabados o una cantimplora forrada de piel hasta "
  "una cota de cuero entrelazado o un arco recurvado hecho de cuerno negro.\n");
  AddDetail("mesa",
  "Una mesa algo destartalada con una silla están colocadas bajo la ventana para poder "
  "observar el jardín y el panorama que la altura sobre la colina de Bree proporciona.\n");
  AddDetail(({"paredes", "muros", "suelo"}),
  "Pequeñas losetas revisten suelo y paredes, aislándolos de la roca de la colina.\n");

  AddExit("oeste", "/d/pais-bree/comun/habitacion/bree/jardin1");

 SetIndoors(1);
 SetIntBright(30);
 AddDoor("oeste", "la puerta",
 "Es una puerta redonda, típicammente hobbit. Tiene una mirilla para observar el "
 "exterior y dos gruesos pestillos además de un pasador en la parte inferior. Junto a la "
 "cerradura hay una bruñida manilla de bronce que permite abrirla.\n",
 ({"puerta redonda", "redonda", "calle"}));


 SetGuildclass(GC_AVENTUREROS); //clase del gremio
  SetGuildname("Gremio de trotamundos");  //nombre del gremio
 SetGuildDomain("pais-bree");
 SetCreators( ({"Orome"}) );                 //creador

 }

public void init(){

    ::init();
            if (TP->QueryIsPlayer() && present(TP, environment()) && !IS_LEARNER(TP) && TP->QueryGuild()=="ninguno"){
                 call_out("unirse",1);
                 }
            }

public void unirse(){
    cmd_join();
        //"/room/ajustes"->ajustes();
    }
