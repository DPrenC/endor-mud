/*
DESCRIPCION  : Huerta en los campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/huerta.c
MODIFICACION : 20-03-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;


public string mirar_huerta(){

object cal;
string str;

cal=clone_object("/obj/calendario/calendario_estandar");
switch(cal->QueryMesNombre()) {
  case "enero"      : str="La nieve cubre los campos de cultivo de los orcos y la superficie del río esta "
                          "helada. En estas condiciones aun no se cultiva nada en esta zona de huerta.\n";break;
  case "febrero"    : str="Los campos siguen cubiertos por la nieve del invierno. Cuando al subir la "
                          "temperatura llegue el deshielo, los orcos plantaran esta zona de huerta.\n";break;
  case "marzo"      : str="Ha comenzado el deshielo y poco a poco la nieve que durante meses ha cubierto "
                          "los campos va deshaciendose. Dentro de poco se plantara esta huerta.\n";break;
  case "abril"      : str="Las ultimas lluvias han nutrido bien el suelo. Ya se ha plantado la primera "
                          "cosecha en la huerta. Las plantas son jovenes pero crecen rapidamente.\n";break;
  case "mayo"       : str="Las plantas de las hortalizas ya estan bastante crecidas, aunque algunos de sus "
                          "frutos aun no estan maduros. Puedes distinguir un variado numero de ellas.\n";break;
  case "junio"      : str="Los frutos de las hortalizas estan ya maduros y no tardaran en recogerlos. En "
                          "estos momentos el huerto es una explosion de color.\n";break;
  case "julio"      : str="Apenas se ha recogido la primera cosecha del huerto ya se ha plantado la segunda "
                          "del anyo. Observas como se ha removido la tierra para airearla.\n";break;
  case "agosto"     : str="Observas como con el calor de esta epoca del anyo las plantas de la segunda "
                          "cosecha estan bastante crecidas. En los campos vecinos se cosecha el trigo.\n";break;
  case "septiembre" : str="Los frutos y las hortalizas de la segunda cosecha del huerto estan ya maduros, "
                          "por los que no tardaran en recogerlos.\n";break;
  case "octubre"    : str="Parece que se acaba de plantar la tercera cosecha del anyo. Se trata de verduras "
                          "capaces de crecer rapidamente con temperaturas moderadas.\n";break;
  case "noviembre"  : str="Las verduras de la ultima cosecha ya estan suficientemente maduras. Pronto se "
                          "cosecharan y se arara la tierra antes de descansar hasta el proximo anyo.\n";break;
  case "diciembre"  : str="Han llegado las primeras heladas y pronto lo haran las primeras nieves. El "
                          "terreno del huerto descansa hasta las cosechas del anyo siguiente.\n";break;
  default: str="";
 }
return str;
}


protected void updateDescr()
{
 SetIntLong(
"A tu alrededor se extienden los campos de cultivo de los orcos en este valle.\n" //
"Te hallas en la orilla del río Kusaii. Esta zona, asi como el resto de las "
"riberas de este río son empleadas como una productiva de huerta por los orcos.\n" //
+mirar_huerta());
}


mirar_cmd(string str) {
   updateDescr();
   return 0;
}


create() {
  ::create();
  SetIntShort("la huerta de los campos de cultivo");
  updateDescr();

  AddDetail(({"campos de cultivo","campo","campos","huerta","huerto"}),QueryIntLong());

  AddDetail(({"río","afluente","Kusaii","kusaii","Kuneii","kuneii"}),
  "El río Kusaii nace en las montanyas de Sharg, al sur del valle de Zarkam. Desde "
  "alli baja encajonado entre desfiladeros hasta el centro del valle donde se une "
  "con su afluente el Kuneii que viene del oeste, para despues dirigirse hacia el "
  "este hacia la costa. Este río no es navegable, pues al atravesar las montanyas "
  "Negras al este de aqui, las cataratas de Nurr lo impiden.\n");

  AddDetail("huerta",SF(mirar_huerta));
  AddRoomCmd("mirar",SF(mirar_cmd));

  SetIntNoise("Oyes al ruido del viento a tu alrededor.\n");
  SetIntSmell("Notas un olor a tierra humeda removida.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
}
