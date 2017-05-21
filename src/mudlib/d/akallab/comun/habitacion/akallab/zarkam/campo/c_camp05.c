/*
DESCRIPCION  : Puente en el camino a los Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/c_camp05.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
               05-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

public string mirar_trigo(){

object cal;
string str;

cal=clone_object("/obj/calendario/calendario_estandar");
switch(cal->QueryMesNombre()) {
  case "enero"      : str="La nieve cubre los campos de trigo. Las plantas, bien protegidas en el interior "
                          "de la tierra, esperan pacientemente la llegada del calor para comenzar a brotar.\n";break;
  case "febrero"    : str="Los campos siguen cubiertos por la nieve del invierno. Las plantas esperan bajo "
                          "a salvo del frio y de las fuertes heladas de esta estacion.\n";break;
  case "marzo"      : str="Ha comenzado el deshielo y poco a poco la nieve que durante meses ha cubierto "
                          "los campos de trigo va deshaciendose. Dentro de poco las plantas brotaran.\n";break;
  case "abril"      : str="Las ultimas lluvias han nutrido bien el suelo y el trigo finalmente ha brotado "
                          "en los campos. Las plantas son jovenes pero crecen rapidamente.\n";break;
  case "mayo"       : str="El trigo aun esta verde, pero ya esta bastante crecido y cubre la superficie de "
                          "de los campos de cultivo como una inmensa manta verde.\n";break;
  case "junio"      : str="El trigo ya esta bastante crecido y comienza a dorarse. Observas como ahora los "
                          "campos pierden el vivo color verde que han tenido durante la primavera\n";break;
  case "julio"      : str="Por su color dorado te das cuenta de que el trigo esta ya maduro y no tardaran "
                          "recogerlo. Parece que esta sera una cosecha razonablemente buena para Zarkam.\n";break;
  case "agosto"     : str="Observas como ya ha empezado la cosecha del trigo mas temprano. Parte de los "
                          "campos estan ya segados. Esta es una epoca de trabajo duro aqui en el campo.\n";break;
  case "septiembre" : str="Los campos estan vacios, descansando de la ultima cosecha. Solo quedan, aqui y "
                          "alla algunos montones de rastrojos.\n";break;
  case "octubre"    : str="Observas que se han arado los campos para airear asi la tierra. De esta forma "
                          "la tierra recobrara fuerza antes de la siembra de la proxima cosecha.\n";break;
  case "noviembre"  : str="Por los aparejos que ves en el campo dirias que hace poco que se ha realizado la "
                          "siembra. Hay suficiente terreno plantado para que se produzca una buena cosecha.\n";break;
  case "diciembre"  : str="Los campos estan arados y sembrados, pero el trigo aun no ha nacido a la espera "
                          "de que pase lo mas frio del invierno. Pronto llegaran las primeras nieves.\n";break;
  default: str="";
 }
return str;
}


protected void updateDescr()
{
 SetIntLong(
    "A tu alrededor se extienden los campos de cultivo de los orcos en este valle. " +
    mirar_trigo()+
    "Te encuentras en sobre un viejo puente de madera que permite cruzar el río en "
    "el camino que cruza estos campos. Al norte de los campos observas la cabanya "
    "destinada a los esclavos que trabajan en ellos.\n");
}


mirar_cmd(string str) {
    updateDescr();
    return 0;
}


create() {
  object obj;
  ::create();
  SetIntShort("un puente en el camino a los campos de cultivo");
  updateDescr();

  AddDetail(({"cabanya","gran cabanya","establo"}),
     "Los orcos suelen utilizar esclavos para cultivar sus tierras, por lo que supones "
     "que la construccion que ves al norte de los campos debe ser el lugar donde los "
     "orcos mantienen a estos esclavos cuando no estan trabajando.\n");

  AddDetail(({"puente","viejo puente"}),
     "Es un bajo puente de madera que cruza sobre el río Kusaii. Esta construido con "
     "gruesos troncos de madera traidos del bosque del nordeste del valle. Por su "
     "aspecto desvencijado, dirias que este ancho y macizo puente ha sido muy "
     "transitado a lo largo de los anyos.\n");

  AddDetail(({"río","afluente","Kusaii","kusaii","Kuneii","kuneii"}),
    "El río Kusaii nace en las montanyas de Sharg, al sur del valle de Zarkam. Desde "
    "alli baja encajonado entre desfiladeros hasta el centro del valle donde se une "
    "con su afluente el Kuneii que viene del oeste, para despues dirigirse hacia el "
    "este hacia la costa. Este río no es navegable, pues al atravesar las montanyas "
    "Negras, que quedan al este de aqui, las cataratas de Nurr lo impiden.\n");

 AddDetail(({"tierras de cultivo","cultivos","campos de cultivo"}),
    "Los orcos emplean sus prisioneros de guerra para que trabajen sus tierras. Esto "
    "no significa que los orcos sean malos agricultores, simplemente ocurre que "
    "debido a su mentalidad guerrera necesitan el mayor numero de hombres para sus "
    "batallas. No es de extranyar que alli te encuentres prisioneros de distintas "
    "razas, posiblemente enemigos entre si, pero con una similitud... el enemigo "
    "comun que los mantiene como esclavos.\n");

  AddDetail("trigo",SF(mirar_trigo));
  AddRoomCmd("mirar",SF(mirar_cmd));
  AddRoomCmd("m",SF(mirar_cmd));

  SetIntNoise("Oyes al ruido del viento a tu alrededor.\n");
  SetIntSmell("Notas un olor a tierra humeda removida.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("sudeste",Z_CAMPOS("c_camp04"));
  AddExit("este",Z_CAMPOS("campo_07"));
  AddExit("nordeste",Z_CAMPOS("huerta_06"));
  AddExit("noroeste",Z_CAMPOS("c_camp06"));
  AddExit("suroeste",Z_CAMPOS("huerta_05"));
  AddExit("sur",Z_CAMPOS("campo_10"));

  obj=clone_object(PNJ("guardia_esclavos"));
  obj->SetAgressive(0);
  obj->SetGoChance(50);
  obj->move(TO);
}
