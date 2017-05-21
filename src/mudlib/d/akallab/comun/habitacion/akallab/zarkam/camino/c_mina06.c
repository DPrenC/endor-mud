/*
DESCRIPCION : Lavadero de la mina.
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/camino/c_mina06.c
MODIFICACION: 13-03-98 [Angor@Simauria] Creacion
              06-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <properties.h>

inherit ROOM;

#define NOMBRE (capitalize(TP->QueryName()))
#define AO     (TP->QueryGender()==GENDER_FEMALE?"a":"o")

create() {
  object ob;

  ::create();
  SetIntShort("el lavadero de la mina");
  SetIntLong(
     "Te encuentras en una pequenya explanada frente a la boca de la mina. Aqui se ha "
     "construido un lavadero con el que separar las rocas con mineral del resto. El "
     "agua del río llega hasta aqui desde una pequenya cascada al sur gracias a unos "
     "canalones de madera. Debido al lavado del mineral el agua del río Kuneii baja "
     "turbia a partir de aqui. Al norte de aqui se han formado unos inmensos montones "
     "de piedras con las rocas desechadas tras el lavado.\n");

  AddDetail(({"canalones","cascada","arroyo","canalon"}),
     "Al sur de aqui se observa una pequenya cascada en el arroyo que es aqui el río "
     "Kuneii. Los orcos han construido unos canalones con planchas de madera que a "
     "modo de acueducto conducen parte de las aguas hasta el lavadero.\n");

  AddDetail(({"lavadero","lavadero de mineral"}),
     "El lavadero en si en una especie de gran plancha inclinada de madera con una "
     "serie de escalones. El material rocoso se deposita en el escalon superior donde "
     "cae el chorro de agua del canalon. El agua lava las rocas permitiendo asi al "
     "operario apreciar cual tiene veta de mineral y arrastrandolas, las separa entre "
     "los distintos escalones segun el peso de las pepitas.\n");

 AddDetail(({"montones","montones de piedras","rocas"}),
     "Una vez lavado el material, las rocas que no tienen veta y por tanto son "
     "inutiles se amontonan a un lado. Por el tamanyo inmenso que tienen actualmente "
     "los montones supones que deben haber explotado esta mina durante unos cuantos "
     "anyos.\n");

  AddDetail(({"arroyo","río","río Kuneii","Kuneii","kuneii"}),
     "El río Kuneii serpentea a traves del valle de Zarkam. Sus aguas son frias y algo "
     "turbias. En esta zona, es mas bien un arroyo que corre entre penyas que un río "
     "propiamente dicho.\n");

  AddDetail(({"montanya","montanyas","Shojuna","shojuna"}),
     "Al oeste del valle se hallan las montanyas de Shujuna. Estas altas montanyas "
     "aislan al valle de Zarkam de los territorios costeros del oeste de la peninsula "
     "de Aguliuk ya que no existe un paso en condiciones para poder cruzarlas. Los "
     "orcos han excavado algunas minas en ellas.\n");

  SetIntNoise("El viento sopla fuerte y se oye la cascada del Kuneii.\n");
  SetIntSmell("El aire es humedo y frio. Huele a fango.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("sudeste",Z_CAMINO("c_mina05"));
  //AddExit("oeste",Z_MINA("entrada"));
  //AddRoomCmd("coger","coger_cmd");
  //AddRoomCmd("usar","usar_cmd");


  ob=clone_object("/obj/monolito");
  ob->SetRaza("demonio");
  ob->move(TO);
  AddItem(OTRO("en_obras"),REFRESH_ALWAYS,3);
}

/*
public int coger_cmd(string que)
{
 if (!que) return notify_fail("Que es lo que quieres coger?\n",NOTIFY_NOT_VALID)&&0;
 if ((que=="roca")||(que=="piedra"))
 {
  object obj;
  obj=clone_object(ARMA("piedra"));
  obj->move(TP);
  write("Coges una piedra del monton.\n");
  say(NOMBRE+" coge una piedra del monton.\n",TP);
  return 1;
 }
 return 0;
}

public int usar_cmd(string str)
{
 int pos;
 string que1,que2;
 if (!str) return notify_fail("Que es lo que quieres usar?\n",NOTIFY_NOT_VALID)&&0;

 if ((sscanf("lavadero",str,pos)!=-1)&&(sscanf(" con ",str,pos)==-1))
    return notify_fail("Usar que con lavadero?\n",NOTIFY_NOT_VALID)&&0;

 if (sscanf("%s con %s",str,que1,que2)>=2){
    if ((que1!="lavadero")&&(que2!="lavadero")) return 0;
    if ((que1!="roca")&&(que2!="roca")&&(que1!="piedra")&&(que2!="piedra"))
       return notify_fail("Eso no puede usarse con el lavadero.\n",NOTIFY_NOT_VALID)&&0;
    if (que1=="lavadero") {que1=que2;que2="lavadero";}
    if (!present(que1,TP)) {write("No tienes una "+que1+".\n");return 1;}

    write("Lavas la "+que1+" en el lavadero.\n");

    //identificar piedra, obtener mineral, etc...
    return 1;
    }
 return 0;
}*/
