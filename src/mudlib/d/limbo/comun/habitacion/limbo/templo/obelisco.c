/*
DESCRIPCION  : Monolito en el medio de la plaza del templo
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/obelisco.c
MODIFICACION : 22-09-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el monolito en plaza del templo");
  SetIntLong(
"Estas en el centro de la plaza del templo de Asthar. Junto a ti se alza un "
"monolito de basalto negro. Esta inmensa mole de piedra se halla colocada en "
"vertical sobre la plaza presidiendo este lugar. Constituye una senyal de la "
"presencia de los dioses en este mundo. Al sur de la plaza se encuentra el "
"templo y al oeste el edificio donde viven los siervos de los dioses.\n");

AddDetail(({"monolito"}),
 "Es un inmenso bloque de basalto negro colocado verticalmente en el centro de "
 "la plaza del templo de Asthar. Sus caras son tan planas y lisas como espejos, y "
 "sus aristas son perfectamente rectas. Sus medidas son 1 metro de ancho, 4 de "
 "largo y 9 de alto, los cuadrados de los tres primeros numeros primos. Su "
 "perfecta y fria belleza es sobrecogedora. Los dioses suelen indicar con objetos "
 "como este lugares singulares en este mundo.\n");

AddDetail(({"templo","templo de Asthar"}),
 "El templo de Asthar es el edificio que se encuentra al sur de esta plaza. Es un "
 "gran edificio de base rectangular hecho de marmol de color claro sobre el sobre "
 "el que sobresale una inmensa boveda de forma hemisferica. En el templo, Asthar "
 "realiza la operacion que permite a un ser cambiar su forma fisica, manteniendo "
 "intacto su espiritu.\n");

AddDetail(({"edificio","siervos"}),
 "El edificio de los siervos de los dioses se halla al oeste de la plaza. Si eres "
 "un recien llegado encontraras que en el hay servicios muy interesantes para ti.\n");

AddDetail(({"plaza"}),
 "La plaza es una gran extension cuadrada de adoquines blancos en cuyo centro se "
 "halla un gran monolito de basalto negro.\n");

 AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar magico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 SetIntNoise("Oyes el ruido del las olas chocando contra los acantilados.\n");
 SetIntSmell("Hmm.. el aire es fresco y limpio.\n");
 SetLocate("isla Limbo");
 SetIndoors(0);

 AddExit("sur",TEMPLO("plaza06"));
 AddExit("oeste",TEMPLO("plaza03"));
 AddExit("norte",TEMPLO("plaza01"));
 AddExit("este",TEMPLO("plaza04"));
}
