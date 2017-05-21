/***************************************************************************************
 ARCHIVO:	pasillo.c
 AUTOR:		[z] Zomax
 FECHA:		27-12-2001
 COMENTARIOS:	Pasillo Standard con lo básico para cada habitación del pasillo.
 MODIFCICACION: 24-04-2003 Repaso de código, elimino cosas que sobran.
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

public string fpasillo()
{
	string pasillo;
	pasillo=W(TO->QueryIntLong());
	return pasillo;
}

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetIntShort("un pasillo");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntNoise("Hay un silencio absoluto.\n");
  AddDetail(({"pasillo"}),SF(fpasillo));
  AddDetail(({"destello","destellos","reflejo","reflejos"}),W("A falta "
  		 "de más decoración son lo único que hace que este lugar no parezca "
  		 "una mazmorra.\n"));
  switch(random(20))
  {
  	case 0:  SetIntLong(W("Estás en uno de los pasillos de Seri-Solderteg. Puedes "
  		 "ver cómo este lugar está muy bien iluminado, con las paredes reglejando "
  		 "cada haz de luz que se cruza en su camino. No ves ninguna decoración, "
  		 "pero no por ello la arquitectura de este lugar deja de serlo.\n"));
  		 break;
  	case 1:  SetIntLong(W("Te encuentras en uno de los pasillos del templo, al norte "
  		 "de Koek. Es un templo muy poco decorado, pero de gran firmeza, que ha "
  		 "conseguido mantenerse casi intacto con el paso de los años.\n"));
  		 break;
  	case 2:  SetIntLong(W("Te encuentras en uno de los pasillos de Seri-Solderteg. "
  		 "Puedes ver en la roca pulida del suelo cómo la luz del lugar se convierte "
  		 "en millones de reflejos que cáda vez te marean más.\n"));
  		 break;
  	case 3:  SetIntLong(W("Te adentras en un pasillo del templo. Puedes ver cómo el "
  		 "suelo y las paredes, a pesar de carecer de elementos decorativos, están "
  		 "pulidas con gran detalle, lo cual te hace pensar que la falta de "
  		 "decoración es más una creencia que una falta de medios.\n"));
  		 break;
  	case 4:  SetIntLong(W("Estás en uno de los pasillos de este templo, aunque no sabes "
  		 "exactamente cuál; todos te parecen iguales. Puedes ver cómo en casi todos "
  		 "los tramos de pasillo del templo hay casi lo mismo. Techos altos, bóvedas "
  		 "pequeñas y una gran cantidad de arcos de todas clases.\n"));
  		 break;
  	case 5:  SetIntLong(W("Te encuentras en el pasillo central. Es un pasillo no muy "
  		 "largo y algo estrecho. Las paredes de aquí son de un tono grisáceo de roca "
  		 "muy brillante y pulida. Piensas en seguir por el pasillo explorando el templo, "
  		 "pero la verdad es que ni siquiera sabes dónde estás ahora.\n"));
  		 break;
  	case 6:  SetIntLong(W("Sigues en uno de los pasillos. Puedes ver una y otra vez las "
  		 "paredes hechas de una exquisita roca pulida y los suelos reflectantes, pero "
  		 "ningún tipo de decoración. Te empiezas a extrañar, dada la fama de adinerados "
  		 "que tienen en el templo. Debe ser parte de su entrenamiento; supones que algo "
  		 "de austeridad debe fortalecer la voluntad.\n"));
  		 break;
  	case 7:  SetIntLong(W("Sigues recorriendo el templo por sus pasillos. Las paredes "
  		 "y el suelo siguen siendo como en los demás pasillos, una mezcla de roca "
  		 "pulida de lo más simple, pero muy brillante. Empiezas a saber distinguir "
  		 "incluso la calidad de la roca por sus pequeños matices. Te sabes todos los "
  		 "tipos de roca de memoria.\n"));
  		 break;
  	case 8:  SetIntLong(W("Te encuentras en uno de los pasillos del templo de "
  		 "Seri-Solderteg. Puedes ver que el pasillo está diseñado para ser "
  		 "puramente funcional, sin ningún tipo de decoración ni nada que lo "
  		 "algre un poco. Parece que aquí la concentración es lo primordial.\n"));
  		 break;
  	case 9:  SetIntLong(W("Estás en un pasillo tan aburrido como grande. Los techos "
  		 "son altos y arqueados, con bóvedas en los huecos que le dan algo de "
  		 "originalidad, pero que se pierde entre las inmensas y monótonas paredes.\n"));
  		 break;
  	case 10: SetIntLong(W("Sigues por el pasillo. Todo sigue igual, las paredes grises, "
  		 "los techos arqueados. La verdad es que parece que quién construyó este "
  		 "templo no era muy amante de la decoración, o igual es que no tenían mucho "
  		 "donde elegir.\n"));
  		 break;
  	case 11: SetIntLong(W("Estás en un triste pasillo del templo de Seri-Solderteg "
  		 "únicamente alegrado por los reflejos que generan sus paredes al contanto "
  		 "con la luz. Si sigues por el pasillo puede que no veas gran cosa, pero "
  		 "quizás te lleves una sorpresa.\n"));
  		 break;
  	case 12: SetIntLong(W("Caminas por un pasillo tan aburrido como poco decorado. "
  		 "Después de mucho observar has llegado a la conclusión de que aquí no "
  		 "les importa lo más mínimo la decoración, y que con tener cuatro paredes "
  		 "les basta y les sobra. No quieres ni pensar cómo serán sus habitaciones.\n"));
  		 break;
  	case 13: SetIntLong(W("Paseas por uno de los pasillos del templo mientras observas "
  		 "con detalle la falta de gusto que tienen por estos lares. Casi puedes afirmar "
  		 "que has visto cuevas más decoradas que este templo. Aquí pasan dos cosas; o "
  		 "no les gusta decorar o guardan las reliquias en algún sitio.\n"));
  		 break;
  	case 14: SetIntLong(W("Caminas por uno de los pasillos de Seri-Solderteg, entre "
  		 "grandes muros de piedra pulida y altos techos abovedados. La verdad es "
  		 "que empiezas a cansarte de tanta monotonía.\n"));
  		 break;
  	case 15: SetIntLong(W("Te encuentras aprisionado entre los muros de uno de los "
  		 "pasillos de Seri-Solderteg. Puedes ver como la roca tan común en Rhoemas "
  		 "ha sido tratada de una forma muy especial hasta conseguir que despida un "
  		 "brillo cegador.\n"));
  		 break;
  	case 16: SetIntLong(W("Estás en el templo de Seri-Solderteg, caminando por uno de "
  		 "sus anchos pasillos de piedra grisácea y suelos brillantes azulados. Está "
  		 "todo muy limpio, se nota que los aprendices trabajan duro, pero le falta "
  		 "algo de calor hogareño. Es un sitio muy frío y triste.\n"));
  		 break;
  	case 17: SetIntLong(W("Estás en uno de los pasillos del templo de Koek, recorriendo "
  		 "los enormes adentros de Seri-Solderteg. Es un lugar muy austero en lo que "
  		 "a decoración se refiere. Hechas de menos aunque fuera una mísera alfombra.\n"));
  		 break;
  	case 18: SetIntLong(W("Te adentras en uno de los pasillos del templo que al contrario "
  		 "que las habitaciones o los altares que encuentras a tu paso no tiene ningún "
  		 "tipo de decoración o adorno. Parece que cuanto más caminas por el templo "
  		 "menos decorado está.\n"));
  		 break;
  	default: SetIntLong(W("Te adentras en un pasillo del templo. Puedes ver cómo el "
  		 "suelo y las paredes, a pesar de carecer de elementos decorativos, están "
  		 "pulidas con gran detalle, lo cual te hace pensar que la falta de "
  		 "decoración es más una creencia que una falta de medios.\n"));
  		  break;
  }
  switch(random(6))
  {
  	case 0:  AddDetail(({"pared","paredes"}),W("Las paredes de todo el templo "
  		 "están hechas de un tipo de roca grisácea muy poco decorativa y "
  		 "algo triste, pero han sido pulidas al máximo ofreciendo destellos "
  		 "y reflejos que suplen la falta de decoración dándoles bastante "
  		 "atractivo.\n"));
  		 break;
  	case 1:  AddDetail(({"pared","paredes"}),W("En este pasillo las paredes son "
  		 "es como en el resto del templo. Están hechas de una típica roca "
  		 "gris de Rhoemas, algo basta y rugosa, pero que ha sido cuidadosamente "
  		 "pulida en láminas rectas que han sabido sacar partido de su gran "
  		 "habilidad para reflejar las cosas.\n"));
		 break;
	case 2:  AddDetail(({"pared","paredes"}),W("Las paredes están hechas de "
		 "piedra gris propia de la zona. Están absolutamente pulidas y "
		 "reflejan cada haz de luz que las toca. Son un verdadero trabajo "
		 "de artesanía.\n"));
		 break;
	case 3:  AddDetail(({"pared","paredes"}),W("Las paredes de aquí son de "
		 "piedra gris, como en el resto de pasillos del templo, sin embargo "
		 "están pulidas, lo cual aumenta su belleza.\n"));
		 break;
	case 4:  AddDetail(({"pared","paredes"}),W("Las paredes son grises, algo "
		 "frías, pero muy suaves. Se nota que pulieron las rocas a conciencia.\n"));
		 break;
	default: AddDetail(({"pared","paredes"}),W("Son unas paredes tan simples como "
		 "bien construidas. Están hechas de piedra gris de muy buena calidad y "
		 "muy bien trabajada.\n"));break;
  }
  switch(random(5))
  {
	case 0:  AddDetail(({"suelo"}),W("El suelo está hecho de roca. Es una roca "
		 "muy parecida a la de las paredes, pero en un tono azulado muy extraño. "
		 "Quizá haya sido tintado de alguna forma. Está brillante y pulido.\n"));
		 break;
	case 1:  AddDetail(({"suelo"}),W("El suelo es de una roca lisa y brillante de "
		 "tonos azulados que brilla según le de la luz.\n"));
		 break;
	case 2:  AddDetail(({"suelo"}),W("El suelo está hecho de piedra azul, bastante "
		 "brillante, muy extraña en esta zona.\n"));
		 break;
	case 3:  AddDetail(({"suelo"}),W("El suelo es de un color azulado que brilla con "
		 "la luz y da algo de colorido a este lugar.\n"));
		 break;
	case 4:  AddDetail(({"suelo"}),W("El suelo está muy brillante y pulido. Está hecho "
		 "de una roca muy extraña azulada que parece hipnótica.\n"));
		 break;
	default: AddDetail(({"suelo"}),W("El suelo está hecho de roca azul, parece que pulida, "
		 "que refleja la luz al máximo.\n"));
		 break;
  }
  switch(random(6))
  {
  	case 0:  AddDetail(({"techo","arco","arcos","bóveda","bóvedas","boveda","bovedas"}),W("Sobre "
  		 "tu cabeza, muy arriba puedes ver el techo, lleno de arcos y pequeñas bóvedas.\n"));
  		 break;
	case 1:  AddDetail(({"techo","arco","arcos","bóveda","bóvedas","bóvedas","bovedas"}),W("El "
		 "techo de esta parte forma unos pequeños arcos y bóvedas que le dan profundidad y "
		 "amplitud.\n"));
		 break;
	case 2:  AddDetail(({"techo","arco","arcos","bóveda","bóvedas","bóvedas","bovedas"}),W("El "
		 "techo forma unos pequeños arcos y bóvedas por los que se pierde tu mirada.\n"));
		 break;
	case 3:  AddDetail(({"techo","arco","arcos","bóveda","bóvedas","bóvedas","bovedas"}),W("Puedes "
		 "ver cantidad de arcos y bóvedas que hacen del techo todo un espectáculo.\n"));
		 break;
	case 4:  AddDetail(({"techo","arco","arcos","bóveda","bóvedas","bóvedas","bovedas"}),W("Intentas "
		 "contar todos los arcos que hay en el techo, pero desistes. Es como contar las estrellas "
		 "en un cielo raso.\n"));
		 break;
	default: AddDetail(({"techo","arco","arcos","bóveda","bóvedas","bóvedas","bovedas"}),W("¡Vaya! "
		 "¡Parece que los arcos están de moda por aquí!\n"));
		 break;
  }
}
