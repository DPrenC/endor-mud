/*
DESCRIPCION  : Cordillera de Kova
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/montain_d.c
MODIFICACION : 10-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <moving.h>

inherit ROOM;

int ir_abajo(){
  int i,dam;

  if (random(10)>2) //te caes
     {
     write("Te deslizas con cuidado por las abruptas y resbaladizas rocas "
             "de la grieta cuando, de repente, la piedra sobre la que acabas "
             "de apoyar tu pie se desprende.... "
             "Caes por la grieta golpeandote contra los salientes....\n");
     say(TP->QueryName()+" comienza el peligroso descenso por las "
             "rocas de la pared de la grieta. De repente, una roca se desprende "
             "bajo sus pies y cae golpeandose contra los salientes...\n",TP);
     tell_room(Z_BOSQUE("montain_6"),TP->QueryName()+" cae por la "
             "grieta golpeandose contra los salientes.\n");

     i=random(TP->QueryMaxHP()*20/100)+10;
     dam=(i>TP->QueryHP()?TP->QueryHP():i);
     TP->Defend(dam);
     }
  else  //consigues bajar
     {
     write("Te deslizas con cuidado por las abruptas y resbaladizas rocas "
             "de la grieta. Tu corazon se acelera cada vez que apoyas un pie "
             "en estas traicioneras rocas, muchas de las cuales estan a punto "
             "de desprenderse. "
             "Tras un lento y fatigoso descenso, llegas al fondo de la grieta.\n");
     say(TP->QueryName()+" comienza el peligroso descenso por las "
             "rocas de la pared de la grieta. Tras un lento y fatigoso descenso, "
             "llega al fondo de la grieta.\n",TP);
     tell_room(Z_BOSQUE("montain_6"),TP->QueryName()+" llega al "
             "fondo de la grieta tras un lento y fatigoso descenso.\n");
     }
  TP->move(Z_BOSQUE("montain_6"),M_SILENT);
  return 1;
}


create() {
  ::create();
  SetIntShort("la cordillera de Kova");
  SetIntLong(
     "Te encuentras en uno de los lugares mas altos de la cordillera de Kova. El "
     "hasta aqui ha estado lleno de dificultades y por lo que ves no crees que se "
     "pueda subir mucho mas, a no ser claro que tengas alas... Observas que todavia "
     "quedan montanyas aun mas altas en esta cordillera. Desde aqui y a traves de una "
     "grieta en la pared de roca puedes intentar bajar por la montanya.\n");

  AddDetail(({"grieta","pared"}),
    "Apoyandote en los salientes de una grieta en la pared rocosa se puede bajar por "
    "la montanya.\n");

  AddDetail(({"cordillera","Kova"}),
     "La cordillera de Kova, en la que te encuentras, es una de las mas inhospitas "
     "de la region.\n");

  AddDetail(({"cuspides","montanyas"}),
     "Aunque te encuentras en una zona extremadamente elevada, todavia puedes ver "
     "montanyas mucho mas altas.\n");

  SetIntNoise("Reina el silencio.\n");
  SetIntSmell("El aire es extremadamente frio en estas alturas.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("norte",Z_BOSQUE("montain_f"));
  //AddExit("abajo",Z_BOSQUE("montain_6"));
  AddExit("abajo",SF(ir_abajo));
}

