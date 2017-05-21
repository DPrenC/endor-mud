#include "path.h"
inherit ATB_C("std_cueva");


create(){
  object ob;
  ::create();
  SetIntLong(W("Al parecer estas en una cueva que no parece del todo "
  	"natural, como si en un principio ya existiese pero alguien la hubiese "
  	"'ayudado' a agrandarse y a alisar los suelos.\n"));
  AddDetail("suelo", "Es frio, liso y humedo.\n");
  AddDetail("paredes", "Son de roca viva. De vez en cuando ves las marcas de "
	"alguna herramienta.\n");
  AddDetail("pared", "Es de roca viva. De vez en cuando ves las marcas de "
	"alguna herramienta.\n");
  SetIntShort("la cueva de Atbalnin");
  AddExit("sudeste", ATB_C("cueva02"));
  AddExit("oeste", ATB_C("cueva00"));
}