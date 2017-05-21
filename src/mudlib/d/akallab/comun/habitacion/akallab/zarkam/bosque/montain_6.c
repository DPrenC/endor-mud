/*
DESCRIPCION  : Cordillera de Kova
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/montain_6.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Rehecha
               27-10-99 [Angor@Simauria] quest
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <moving.h>


inherit ROOM;


int ir_arriba(){
  object ob1,ob2;

  if (!TP) return 0;

  ob1=present("amu_quest_00",environment(TP));
  ob2=present("amu_quest_00",TP);

  if ((!ob1) && (!ob2))
     {
     write("Intentas escalar la roca apoyandote en los escurridizos "
             "salientes pero no eres capaz... Si realmente quieres subir "
             "ahi deberias ayudarte con alguna otra cosa.\n");
     return 1;
     }

  if (ob1) ob1->remove();
  else     ob2->remove();

  write("Colocas la escalera junto a la pared rocosa de la grieta. "
          "Subes por ella y desde alli, manteniendo el equilibrio saltas "
          "hasta un saliente que hay mas arriba. A duras penas consigues "
          "agarrarte y subir a el... Debido a tu salto, la vieja escalera "
          "cae al suelo y termina de romperse.\n");

  ob1=clone_object(QUEST+"amuleto/escalera_rota");
  ob1->move(environment(TP));
  say(TP->QueryName()+" se sube a la escalera y desde alli "
     "salta a un saliente de la roca. La vieja escalera se tambalea, cae "
     "al suelo y termina de romperse.\n",TP);
  tell_room(Z_BOSQUE("montain_d"),TP->QueryName()+" aparece "
     "escalando por el borde del acantilado, jadeando tras realizar una "
     "dificil ascensión por la pared de roca.\n");
  TP->move(Z_BOSQUE("montain_d"),M_SPECIAL);
  return 1;
}


create() {
  ::create();
  SetIntShort("la cordillera de Kova");
  SetIntLong(
  "Un viento gelido que te transpasa aulla entre las montanyas. Tu unica "
    "companyia son las rocas y los acantilados que formas las montanyas, "
    "ya que ni la vegetacion ha logrado crecer. Avanzas con cuidado ante el "
    "temor de que un paso mal dado te lleve rodando hasta el fondo del valle "
    "dado lo resbaladizo de las rocas sobre las que caminas. Desde aqui y a "
    "traves de una grieta en la pared de roca podrias subir algo mas arriba "
    "en la montanya.\n");

  AddDetail(({"grieta","pared"}),
  "Apoyandote en los salientes de una grieta en la pared rocosa se puede "
    "subir aun mas arriba en la montanya, pero necesitarias algo con que "
    "ayudarte.\n");

  AddDetail(({"roca","rocas"}),
  "Las rocas de esta montanya son altamente lisas lo que las hace "
    "bastante resvaladizas\n");

  SetIntNoise("Reina el silencio.\n");
  SetIntSmell("El aire es algo frio en estas alturas.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("nordeste",Z_BOSQUE("montain_9"));
  AddExit("oeste",Z_BOSQUE("montain_5"));
  //AddExit("arriba",Z_BOSQUE("montain_d"));
  AddExit("arriba",SF(ir_arriba));
  AddExit("sur",Z_BOSQUE("montain_8"));

  AddItem(QUEST+"amuleto/oso_herido", REFRESH_DESTRUCT);
}

