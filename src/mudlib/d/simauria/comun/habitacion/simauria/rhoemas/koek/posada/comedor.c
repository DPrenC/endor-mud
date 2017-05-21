/***************************************************************************************
/* Modificado por Khelben 12-11-2004
   Cambiamos la forma de añadir los objetos. Si no hay ninguno entonces añadirmos
   Si hay alguno, no ponemos ninguno.
   Aparecen cientos de objetos tal y como esta ahora
 ARCHIVO:	comedor.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	El comedor
 ***************************************************************************************/

#include "path.h"

inherit PUB;
#include RHOEPRESO

create () {
 ::create();

  SetIndoors(1);
  SetIntBright(40);
  SetLocate("Koek");
  SetIntShort("el comedor");
  SetIntSmell("Huele a comida.\n");
  SetIntNoise("No oyes nada extraño.\n");
  SetIntLong(W("Estás en el comedor de la posada, donde se sirven las comidas y puedes "
  	"beber a tu gusto. Aquí suele haber peregrinos comiendo todo el día. Parece todo "
  	"muy limpio a pesar de la clientela que tienen.\n"));

  AddDetail(({"suelo"}),"El suelo, hecho de tablones de madera que cruje a tu paso.\n");
  AddDetail(({"mesa","mesas","silla","sillas"}),W("Las mesas y sillas son de madera. Quizás "
  	"si te das prisa puedas coger sitio para pedir algo.\n"));
  AddDetail(({"pared","paredes"}),"Son de madera, están limpias y eso te basta.\n");
  AddDetail(({"techo"}),W("El techo es un simple conjunto de tablones de "
 	"madera.\n"));

  carcel=(RHOEHAB("koek/posada/entrada"));
  AddExit("sur",RHOEHAB("koek/posada/entrada"));
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");

  AddItem(RHOEPNJ("koek/varios/patrullero"),1,3+random(2));
  AddItem(RHOEPNJ("koek/posada/peregrino_comedor"),1,3+random(6));
    SetKeeper(RHOEPNJ("koek/posada/posadera_koek"));

    AddFood("sopa de pescado","un tazón de",6,7,0,0);
    AddFood("trucha asada","un plato de",7,9,0,0);
  AddFood("pollo asado","un plato de",8,10,0,0);
  AddFood("cerdo asado","un plato de",9,15,0,0);
  AddDrink("ron","una jarra de",10,10,5,0);
  AddDrink("cerveza","una jarra de",3,4,8,0);
  AddDrink("vino","un vaso de",10,10,5,0);
  AddDrink("whisky","un vaso de",15,15,7,0);
  AddDrink("aguardiente","un vaso de",20,20,10,0);
}

int QueryEntrarPatrullero()
{
	return 1;
}
