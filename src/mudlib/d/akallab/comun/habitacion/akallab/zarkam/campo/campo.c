/*
DESCRIPCION  : Campos de cultivo.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/campos/campo.c
MODIFICACION : 19-03-98 [Angor@Simauria] Creacion
               07-10-98 [Angor@Simauria] Descripcion aleatoria+f(fecha)
               21-04-03 [Theuzifan] Te voy a dar yo a ti clone_object...
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

public string mirar_trigo(){

object cal;
string str;

cal=load_object("/obj/calendario/calendario_estandar");
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
  int i;
  string str;
  i=random(3);
  switch(i) {
    case 0 : str="A tu alrededor se extienden los campos de cultivo de los orcos en este valle.\n";break;
    case 1 : str="Los orcos emplean estas fertiles tierras como campos de cultivo para Zarkam.\n";break;
    case 2 : str="Te hallas en el fondo del valle de Zarkam, en medio de los campos de cultivo.\n";break;
    //default: str="";
    }
  str+=mirar_trigo();
  i=random(3);
  switch(i) {
    case 0 : str+="Observas esclavos trabajando en los campos.\n";break;
    case 1 : str+="Huele a tierra humeda.\n";break;
    case 2 : str+="Sientes que se te observa desde la lejana ciudad fortificada de de Zarkam.\n";break;
    }
  SetIntLong(str);
}


mirar_cmd(string str) {
   updateDescr();
   return 0;
}


create() {
  ::create();
  SetPreIntShort("enmedio de");
  SetIntShort("los campos de cultivo");
  updateDescr();

  AddDetail(({"ciudad","ciudad fortificada","Zarkam","zarkam"}),
     "En medio del valle y sobre una loma se alza la ciudad fortificada de Zarkam. Es "
     "una poblacion de mediano tamanyo que se halla totalmente rodeado por una alta "
     "muralla de piedra. Desde el exterior, lo unico que se puedes ver de la ciudad es "
     "una alta torre que se alza sobre la muralla y en la que siempre hay vigias por "
     "si aparecen enemigos. Seguro que vigilan tus movimientos desde que entraste en "
     "este valle... No hay duda que esta gente esta acostumbrada a la guerra.\n");

  AddDetail(({"campos de cultivo","campo","campos"}),QueryIntLong());
  AddDetail("trigo",SF(mirar_trigo));
  AddRoomCmd("mirar",SF(mirar_cmd));
  AddRoomCmd("m",SF(mirar_cmd));

  SetIntNoise("Oyes al ruido del viento a tu alrededor.\n");
  SetIntSmell("Notas un olor a tierra humeda removida.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
}
