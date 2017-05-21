/*
DESCRIPCION    : Fantasma del peregrino que te dice el Quest (no es para ataque)
FICHERO        : /d/lad-laurelin/pnj/lago/fantPereg.c
CREACION       : Junio del 2000 [Alura]
U.MODIFICACION :
*/

#include <rooms.h> // solo para que pueda perseguir

#include "path.h"
#include <properties.h>
inherit "std/undead";

int car;

void attack(){
        object *en;
        int i;
        en=TO->QueryEnemies();
        for (i=1;i<=sizeof(en);i++)
                tell_object(en[i],"No puedes atacar a este ser incorpóreo.\n");
        tell_object(environment(TO),"El fantasma del elfo es atacado, pero éste ni se inmuta.\n");
}


create() {
  ::create();
 SetStandard("un fantasma","no-muerto",1,GENDER_MALE);
  SetShort("El fantasma de un elfo");
  SetLong("Es la translúcida imagen de un elfo.\n");
  SetIds(({"fantasma de un elfo","fantasma"}));
  SetAds(({"el","un","demacrado"}));
  SetAlign(700);
  SetSize(P_SIZE_MEDIUM);
  SetHands(({({"mano izquierda",0,1}),({"mano derecha",0,1})}));
  SetAggressive(0);
  Set(P_CANT_FIGHT,1);

  InitChats(2,({"La aparición te dice: Por favor, ayudanos... mortal...\n",
                "El fantasma te dice: Dehim llora por este lugar, abandónalo o purifícalo.\n"}));

    AddQuestion(({"Dehim","dehim"}),
  "El espíritu del elfo te mira estupefacto y te dice: Cómo no sabes quien es\n"
  "el dios druídico de la curación?? la salvación de los enfermos!, el alivio de\n"
  "los guerreros! Este templo estaba dedicado a él, hasta que llegó la\n"
  "Oscuridad... - El elfo suspira y se tapa la cara.\n");

   AddQuestion(({"oscuridad","Oscuridad"}),
  " El fantasma te mira y te dice:\n"
  " Ah, quieres saber lo que pasó?? pues escucha:\n"
  "  Hace ya mucho tiempo, un elfo peregrino, seguidor de Dehim, dios élfico\n"
"de la curación, tuvo una revelacion de un emplazamiento. Largo tiempo estuvo\n"
"viajando por el reino hasta que encontró este lugar.\n"
"Quisiendo demostrar su servidumbre y devoción,\n"
"el peregrino decidio construir un templo dedicado a su deidad. Largos fueron\n"
"los años de construcción. Con ayuda del pueblo enano próximo a este lugar\n"
"consiguió que el templo fuese una magnífica obra de arte y de culto,\n"
"morada por adeptos élficos y peregrinos de todas las razas.\n"
"\n"
"    Vivia feliz hasta que una visita inesperada cambió su vida. Un señor\n"
"de la noche apareció y reclamó el valle para sí. A partir de ese dia sus\n"
"huestes de no-muertos fueron minando muy lentamente el valle y el terreno\n"
"consagrado por el peregrino.\n"
"\n"
"    Durante un periodo, el peregrino y los pocos adeptos que pudo reunir con\n"
"el paso del tiempo, hicieron frente a este problema. Muy a su pesar, el elfo\n"
"sabia que algun dia tendria que enfrentarse directamente con el causante de\n"
"todo aquel mal, y asi fue. Un terrible dia, en una cruel batalla, el elfo se\n"
"enfrentó solo contra el vampiro Radhul y.. perdió. Al ver a su líder muerto,\n"
"muchos adeptos se desmoralizaron y huyeron, y los que quedaron, fueron masacrados.\n"
"    Mas tarde, Radhul profanó el templo y se llevó un símbolo de nuestro dios.\n"
"    Por favor, tráelo de nuevo a su lugar, acaba con el odioso vampiro y las almas\n"
"de este templo podremos descansar en paz...\n");
}

int nomagia(string str){
  int i;
  if (strstr(str, "fantasma",1)!=-1 ||
  strstr(str, "un fantasma",1)!=-1 || strstr(str, "fantasma de un elfo",1)!=-1 || strstr(str, "el fantasma",1)!=-1){
                tell_object(TP,"No puedes atacar a este ser incorpóreo. No le afecta tu magia.\n");
                return 1;
  } else { return 0;}
}

init(){
        ::init();
        add_action("nomagia","magia");
}
