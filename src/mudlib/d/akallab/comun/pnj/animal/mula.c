/*
DESCRIPCION  : una mula de carga
FICHERO      : /d/akallab/comun/pnj/animal/mula.c
MODIFICACION : 31-01-00 [Angor@Simauria]Creacion
---------------------------------------------------------------------------
*/

#include <living.h>
#include <properties.h>
#include <rooms.h>

inherit NPC;


int QueryPuedeLlevarCarga(){return 1;} //se le pueden poner alforjas

create()
{
  ::create();
 SetStandard("mula","mula",10,GENDER_FEMALE);
  SetIds(({"mula", "animal"}));
  SetShort("una mula");
  SetLong("Es una mula. Este tipo de animales se emplea para transportar "
            "cargas, normalmente en las alforjas que suelen llevar puestas.\n");
  SetWeight(300000);
  SetValue(5000);
  Set(P_HANDS, ({
    ({"la pata trasera derecha", 0, 4}),
    ({"la pata trasera izquierda", 0, 4}),
    ({"un mordisco", 0, 7})}));
}


init() {
  (::init());
  add_action("montar_cmd", "montar");
  add_action("montar_cmd", "coger");
}


int montar_cmd(string str) {
  int hp;
  if(!str || !id(str)) return 0;
  write("La mula se revuelve y te pega una coz. Te ha dolido bastante.\n");
  hp=TP->QueryHP();
  hp=(hp-10>0?hp-10:0);
  TP->SetHP(hp);
  return 1;
}
