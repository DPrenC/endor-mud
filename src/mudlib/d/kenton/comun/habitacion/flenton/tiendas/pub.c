/***************************************************************************************
 ARCHIVO:	pub.c
 AUTOR:		[k] Korsario
 FECHA:		02-04-1998
 COMENTARIOS:	Pub Local
 ***************************************************************************************/

#include "path.h"

inherit PUB;

create(){
  ::create();

  SetIndoors(1);
  SetIntBright(80);
  SetLocate("taberna");
  SetIntNoise("Escuchas un ligero murmullo de cantos, voces y risas que da "
  	"calor al ambiente.\n");
  SetIntSmell("Huele a comida.\n");
  SetIntShort("la taberna de Pikarus");
  SetIntLong("Te encuentras en la taberna de Pikarus. Aquí se reune la "
  	"gente del poblado a reir y cantar, y a discutir hasta el agotamiento "
  	"los temas mas diversos. Las noches son muy animadas aquí, sobre todo "
  	"cuando llegan extranjeros con muchas hazañas que contar, y con novedades "
  	"sobre el mundo exterior. Hay un menú que puedes leer sobre la barra.\n");

  AddDrink("cerveza negra","una jarra de",5,10,5,7,"Te bebes la jarra de "
  	"cerveza negra y notas un ligero calor bajando por tu garganta.\n");
  AddDrink("bebida de rocio","una jarra de",5,8,5,10,"El posadero te trae "
  	"una jarra de un liquido de color dorado. Te la bebes y notas su "
  	"delicado sabor a miel, y un ligero calorcillo por tu garganta.\n");
  AddDrink("cerveza de frambuesa","una jarra de",6,15,5,10,"Te tomas la "
  	"jarra de Cerveza de Frambuesa y notas como su delicioso sabor baja "
  	"por tu garganta, produciendo un agradable calorcillo.\n");
  AddDrink("licor de mora","una jarrita de",6,16,2,9,"Te tomas el licor "
  	"de Mora, notas su sabor dulce y el calorcillo que te produce al bajar "
  	"por tu garganta. Hmmmm... que bueno esta!\n");
  AddDrink("aliento de dragon","una copita",16,25,5,25,"Arggh! Notas como "
  	"si el mismisimo fuego del infierno bajara por tu garganta. Por un "
  	"momento se te nubla la vision.\n");
  AddFood("pan kender","una rebanada de",7,8,10,"El posadero te trae un "
  	"pan dulce y con muy buena pinta. Aunque la cantidad no parecia mucha, "
  	"te ha llenado bastante.\n");
  AddFood("asado de jabalí","un plato de",5,10,14,"Te comes el asado de "
  	"jabalí. Estaba para chuparse los dedos!\n");
  AddFood("sopa de tortuga","un plato de",4,6,9,"El camarero te trae un "
  	"plato humeante de sopa de tortuga. Cuando te lo terminas te sientes "
  	"reconfortado.\n");
  AddFood("especial de la casa","un plato de",15,6,40,"Te comes el plato "
  	"especial de la casa, esta para chuparte los dedos!\n");

  AddExit("norte",FLENHAB+"calles/plaza_00");
  AddItem(FLENPNJ+"poblado/pikarus",REFRESH_REMOVE,1);

}
