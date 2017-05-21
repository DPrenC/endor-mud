/***************************************************************************************
 ARCHIVO:	froeker.c
 AUTOR:		[z] Zomax
 FECHA:		25-10-2001
 COMENTARIOS:	Froeker, pescador y regente de la cofradía.
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Froeker","humano",10,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Froeker");
  SetIds(({"humano","froeker","Froeker","pescador"}));
  SetShort("Froeker");
  SetLong(W("Froeker es un humano. Tiene la cara y las manos curtidas por el "
  	"sol y el roce de las redes que usa para pescar. El pelo y la gran barba "
  	"que le cae de la cara son blancos como la nieve, y destacan sus ojos, "
  	"algo tristes. En la mejilla tiene una pequeña cicatriz y un millar más "
  	"en las manos, de manejar los anzuelos. Se le ve muy fuerte a pesar de su "
  	"edad.\n"));
  AddSubDetail(({"mano","manos"}),W("Se nota que es pescador. Sus manos están "
  	"encallecidas y muy estropeadas.\n"));
  AddSubDetail(({"pelo","barba"}),"Tiene el pelo blanco como la nieve en invierno.\n");
  AddSubDetail(({"ojo","ojos","mirada"}),"Um... mirada triste... que pena.\n");
  AddSubDetail(({"mejilla","cicatriz"}),W("Tiene una gran cicatriz en la mejilla, parece "
  	"que de una pelea o algo parecido.\n"));
  AddQuestion(({"pesca"}),W("Froeker te dice: La pesca es un oficio muy relajante, pero que requiere "
  	"de mucha paciencia y destreza con los aparejos. No todo el mundo tiene esas "
  	"cualidades, por eso hay gente nacida para pescar y otros no. A veces se "
  	"pescan cosas de lo más inusual; armas, algas, botas...\n"),1);
  AddQuestion(({"hijo","vaemar","Vaemar"}),W("Froeker te dice: Vaemar es mi único hijo. Hace un año "
  	"o más se adentró por error en el bosque de Cylin y no he vuelto a saber de "
  	"él ni de su esposa. Desde entonces crío a mi nieto junto con mi mujer Kaewin.\n"),1);
  AddQuestion(({"mujer","esposa","kaewin","Kaewin"}),W("Froeker te dice: Kaewin es mi esposa, se "
  	"encarga de vender el pescado que consigo en la pescadería de la calle "
  	"de los comerciantes, aquí en koek. La verdad es que no sé qué haría sin "
  	"ella, pero últimamente está un poco triste, desde que nuestro hijo Vaemar "
  	"desapareció.\n"),1);
  AddQuestion(({"concurso","concurso de pesca"}),W("Froeker te dice: Hay un concurso permanentemente "
  	"en la cofradía de pescadores. Sólo tienes que pescar un pez mayor que el que "
  	"la cofradía de pescadores tiene registrado como más pesado para recibir el "
  	"premio.\n"),1);
  AddQuestion(({"nieto","zaesh","Zaesh"}),W("Froeker te dice: Zaesh es nuestro nieto, el hijo de "
  	"Vaemar y Sia. Nos ocupamos de criarle desde que desaparecieron. Le "
  	"estoy enseñando todo lo que sé de la pesca, como hice con Vaemar. Sólo "
  	"espero que pueda encontrar a sus padres...\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Froeker te dice: Koek es un sitio bastante tranquilo, aunque ultimamente se está masificando algo.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"A Froeker se le escapa una mirada entre temor y rencor.\n "
	"Froeker te dice: Cylin, maldito bosque... Si no fuera tan viejo yo mismo "
	"entraría para descrubrir lo que a pasado con mi hijo... "
	"ya lo intenté una vez, pero apenas llegué a la entrada cuando "
	"recibí esto como bienvenida, y ni siquiera se de dónde vino.\n"
	"Froeker se señala la cicatriz de la mejilla.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W(
	"Froeker te dice: El templo... algo debe esconder... sino, ¿por qué protegen el bosque "
	"de esa manera?.\n"),1);
  AddQuestion(({"sia","Sia","nuera"}),W("Froeker te dice: Sia es la esposa de mi hijo... "
  	"desapareció con el en el bosque de Cylin hace un año.\n"),1);
  AddQuestion(({"cicatriz","mejilla"}),W("Froeker te dice: Esto me lo hice al intentar entrar "
  	"en el bosque de Cylin cuando desapareció mi hijo... unos monjes me "
  	"sacaron a tiempo, pero no me libré de la marca. No se ni como me la "
  	"hice, fue muy rápido.\n"),1);
}
