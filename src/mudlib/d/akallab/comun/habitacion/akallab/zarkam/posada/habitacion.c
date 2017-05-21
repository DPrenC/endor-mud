/*
DESCRIPCION : habitacion tipo de la posada
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/posada/habitacion.c
MODIFICACION: 12-10-98 [Angor@Simauria] Creacion
              11-03-00 [Angor@Simauria] muebles estandard, wrap
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

public string nom_posada;  //nombre de la posada
public int    tipo;        //[0] da al exterior, [1] da a un patio interior
public int    huesped;     //[0] no hay, [1] si hay
public string vista;       //lo que se ve al mirar por la ventana

string mirar_ventana(){
  if (tipo==0) return (!vista?"A traves de la ventana ves la calle.\n":vista);
  else return "A traves de la ventana ves el patio interior de la posada.\n";
}

create() {
  int i;
  string str, tmp;

  ::create();

  SetIntShort("una habitacion de la posada");

  if (!nom_posada) {
     nom_posada="";
     str="una posada cualquiera";
     }
  else str="la posada "+nom_posada;

  tmp="Te encuentras en una de las habitaciones de "+str+". ";
  if (!tipo) tipo=0;
  switch (tipo){
     case 0:tmp+="Es una habitacion de mediano tamanyo con una ventana que da al exterior del "
                 "edificio. En medio de la habitacion se encuentra una rustica cama de madera.";break;
     case 1:tmp+="Es una habitacion de mediano tamanyo con una ventana que da a un patio interior "
                 "del edificio. En medio de la habitacion se encuentra una rustica cama de madera.";break;
     }

  if (!huesped) huesped=0;
  if (huesped==1) AddItem(PNJ("/std/huesped"),REFRESH_DESTRUCT);
  if (random(2)) AddItem(MUEBLE("armario_ropa"),REFRESH_DESTRUCT,1);
  if (random(2)) AddItem(MUEBLE("cofre_ropa"),REFRESH_DESTRUCT,1);

  SetIntLong(tmp+"\n");

  AddDetail(({"ventana"}),SF(mirar_ventana));

  //AddDetails de Zarkam

  AddDetail(({"patibulo"}),
   "Es una plataforma elevada de madera con varias horcas. Es alli donde se ejecuta "
    "publicamente a los delincuentes o prisioneros de guerra como castigo publico y "
    "como advertencia al resto de la poblacion.\n");

  AddDetail(({"horcas"}),
   "Varias horcas hechas con una gruesa soga cuelgan de la viga superior del "
    "en ellas los orcos ajustician publicamente a quien el governador decide.\n");

  AddDetail(({"plaza","plaza central"}),
   "Es una gran explanada que se encuentra en el centro de la ciudad de Zarkam. A su "
    "alrededor se alzan altos edificios y al oeste el castillo de la ciudad. Es el "
    "lugar en que se reune la gente cuando se producen ejecuciones publicas o cuando "
    "el governador realiza algun importante anuncio.\n");

  AddDetail(({"castillo"}),
    "La ciudad de Zarkam se ha construido en torno al gran castillo que observas al "
    "al noroeste de aqui. En el vive el governador orco que el emperador ha elegido "
    "para dirigir esta provincia. El castillo es una inmensa mole de piedra mas alta "
    "que cualquiera de los edificios que lo rodean. Sobre el se alza una alta torre "
    "desde la que se vigila el valle constantemente.\n");

  SetIntNoise("Se oye a alguien roncar.\n");
  SetIntSmell("Hmm.. quiza alguien deberia abrir una ventana para ventilar la habitacion.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(1);
  SetIntBright(50);
}
