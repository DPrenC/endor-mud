/*
DESCRIPCION : almenas de la muralla
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/muralla/almena.c
MODIFICACION: 27-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <nightday.h>  //por las ctes del dia
inherit ROOM;

int amedida;    //no crea la habitacion con randoms? 0=no, 1=si
int luz;        //hay luz en esta zona? 0=no, 1=si
int bandera;    //hay banderas? 0=no, 1=si
int guardias;   //guardias
int patrulla;   //guardias de patrulla


string antorchas(){
  string str;
  str="Las antorchas estan colocadas en unos soportes de metal anclados en la pared.\n";
  if ((QueryDayState()>=ND_SUNRISE) || (QueryDayState()<ND_FALL))
       str+="Al ser de dia, ahora estan apagadas.\n";
  else str+="Al ser de noche, ahora estan encendidas.\n";
  return str;
}


create() {
 string str;

 ::create();
 if (amedida==0) {luz=random(2); bandera=random(3); patrulla=random(3); guardias+=(random(5)==0?1:0);}

 SetIntShort("las almenas de la muralla");

 str="Te encuentras sobre la muralla del castillo junto a las almenas. Desde aqui se "
     "puede ver gran parte de la ciudad y del valle de Zarkam. Observas que a cada "
     "cierta distancia hay un torre en la muralla, generalmente con un vigia sobre "
     "ella. A lo largo de la muralla ves a grupos de soldados patrullando.\n";

 if (bandera==1) {
    str+="Junto a las almenas hay varios altos postes en los que flamean banderas negras.\n";
    AddDetail(({"poste","postes","bandera","banderas"}),
         "Junto a las almenas de la torre hay varios postes altos y delgados cuya función "
         "es la de ser los mastiles de otras tantas alargadas banderas negras, los "
         "simbolos que identifican al imperio orco.\n");
    }

 if (luz==1) {
    str+="Hay varias antorchas colocadas en los soportes. Se encienden por la noche para "
         "iluminar esta parte de la muralla.\n";
    AddDetail(({"antorchas"}),SF(antorchas));

    SetIntBright(30);
    }
 else str+="Las antorchas de esta parte de las almenas faltan de sus soportes.\n";

 SetIntLong(str);

 AddDetail(({"soporte","soportes"}),
    "Los soportes sirven para colocar en ellos las antorchas que iluminan las almenas "
    "de la muralla. Son una especie de aros de metal anclados a la pared en los que "
    "se mete una antorcha.\n");

 AddDetail(({"torre","torres"}),
     "A cada cierta distancia, hay una torre en la muralla. Por ellas se puede subir y "
     "bajar de la muralla. Las torres son mas altas que la muralla y sobre ellas suele "
     "haber vigias controlando tanto la ciudad como el valle.\n");

  AddDetail(({"muralla"}),
     "Es un inmenso muro de piedra que protege el castillo rodeandolo por completo. "
     "Dirias que como minimo tiene unos cinco metros de altura en las partes mas bajas "
     "y esta protegida con gruesas almenas. Sobre ella hay una pasarela por la que "
     "cada cierto tiempo pasan soldados fuertemente armados.\n");

  SetIntNoise("El frio viento sopla con fuerza.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("castillo de Zarkam");
  SetIndoors(0);

  if (guardias!=0) AddItem(PNJ("z_castillo/guardia"), REFRESH_DESTRUCT, guardias);
  if (patrulla==1) AddItem(PNJ("z_castillo/patrullero"), REFRESH_DESTRUCT, 1);
}
