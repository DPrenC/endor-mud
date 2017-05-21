/*
DESCRIPCION  : Entrada al Templo de Asthar.
FICHERO      : /d/limbo/comun/habitacion/limbo/asthar/templo01.c
MODIFICACION : 08-02-98 [Angor@Simauria] Creacion
               12-08-98 [Angor@Simauria] Rehecha en gran medida
               24-03-99 [a] wrapeada....
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <moving.h>

inherit ROOM;

int salirTemplo() {
  if (!TP) return 0;

  if (TP->QueryGhost()==1) {
  write("En el momento en el que intentas abandonar el templo, una fuerza invisible te "
  "atrapa firmemente. Un escalofrio espectral te recorre. Una voz grave y severa "
  "resuena en tu interior: 'Antes de que tu espiritu pueda abandonar este lugar y "
  "vagar por el mundo, debes encarnarte en un cuerpo material. No esta permitido "
  "dejar que seres en tu estado incorporeo entren al mundo'.\n");
 say("El espiritu de "+TP->QueryName()+" trata de salir del templo, pero es retenido por una\nextranya fuerza.\n",TP);
 return 1;
 }
  return TP->move(TEMPLO("plaza06"),M_GO,"norte");
}


public create(){
  ::create();
  SetIntShort("la entrada del templo de Asthar");
  SetIntLong(
W("Te encuentras en la entrada del templo de Asthar. Es un amplio edificio de base "
"cuadrada, con varias hileras de altas columnas de mármol que soportan el peso de "
"la bóveda semiesférica que lo corona. El muro oeste está recubierto de murales "
"pintados, y en el del este se abren unos altos ventanales al exterior cuya luz se "
"refleja en un suelo negro pulido como un espejo. Al sur del templo se halla el "
"altar, donde Asthar resucita a los desventurados seres que han muerto en este mundo.\n"));

AddDetail(({"columna","columnas"}),
W("Varias hileras de columnas recorren el interior del templo. Su funcion es la de "
"soportar el peso de la inmensa boveda semiesferica que corona el templo. Las "
"columnas son delgadas y estan fabricadas a partir de bloques de un marmol megro. "
"Estan casi totalmente cubiertas por una serie de complicados dibujos y signos "
"que te son completamente desconocidos.\n"));

AddDetail(({"dibujos","signos"}),
W("Las columnas del templo estan casi totalmente cubiertas con ellos. No tienes ni "
"idea de que son o que representan.\n"));

AddDetail(({"boveda","esfera"}),
W("Ocupando la mayor parte del techo del templo se halla una inmensa boveda de "
"forma semiesferica. Tal vez sea un efecto optico pero te parece que flotando "
"alla arriba en la boveda hay una gran esfera de luz...\n"));

AddDetail(({"murales"}),
"Son frescos pintados en la pared oeste del templo. Acercate mas para verlos.\n");

AddDetail(({"altar","altar"}),
W("El altar es una especie de mesa situada sobre una plataforma elevada que se "
"encuentra al sur del templo. Es en el donde Asthar realiza el rito sagrado que "
"permite encarnarse a los espiritus o cambiar la forma de un cuerpo.\n"));

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
W("La isla Limbo es el lugar magico de Simauria donde habitan los dioses. Gracias "
"a ellos, es en este lugar donde las almas de los seres se encarnan para poder "
"asi vivir en este mundo.\n"));

SetIntNoise("Oyes el ruido del las olas chocando contra los acantilados.\n");
SetIntSmell("Hmm.. el aire es fresco y limpio.\n");
SetLocate("isla Limbo");
SetIndoors(1);
SetIntBright(50);

AddExit("norte", SF(salirTemplo));
AddExit("oeste",TEMPLO("templo00"));
AddExit("sur",TEMPLO("templo04"));
AddExit("este",TEMPLO("templo02"));
}