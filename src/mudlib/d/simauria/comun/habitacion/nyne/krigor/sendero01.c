/* **********************************************************************
   *  DESCRIPCION  	:sendero que une el bosque con Krigor es la primera
   			habitacion del camino hacia Krigor, desde aqui
   			se ve todo el valle.
   *  FICHERO	: 	sendero01.c
   *  CREACION	:	Chaos [ChS]
      MODIFICACION:	06-03-03 [ChS]  -A�ado las descripciones como tocan y deja de ser
      			genericas,
*/
#include "path.h"
inherit SIM_ROOM;

create()
{
	::create();
	SetIntShort("el sendero hacia Krigor");

	SetIntLong(W("Te encuentras en el principio de un sendero, que sale del bosque "
		"y atraviesa el valle hasta llegar a una peque�a aldea. Ves alguna "
		"que otra casa diseminada por todo el valle. El peque�o valle esta "
		"entre  unas enormes monta�as. El sendero parece que esta rodeado "
		"por una valla. Y a la izquierda ves un letrero.\n"));

// Algun que otro detalle para amenizar un poko esto, ya se iran a�adiendo mas

	AddDetail(({"valla"}),
		W("Es madera, posiblemente sacada del bosque del que acabas de salir."
		"Rodea el camino dejando algun que otro rodal sin valla, que es usado"
		" por la gente para ir a las casa o entrar en el prado.\n"));
	AddDetail(({"prado","prados","pradera"}),
		W("Es una extensi�n de terreno que rodea a la aldea, de un verde oscuro"
		" que contrasta con el azul del riachuelo que lo cruza por el Este "
		"y se extiende hasta las monta�as. En el valle ves alguna vaca pastando\n"));
	AddDetail(({"aldea","pueblo"}),
		W("Es una peque�a aglomeraci�n de casitas blancas donde vive la gente "
		" de esta aldea\n"));
	AddDetail(({"casa","casas","casitas","casita"}),
		W("Es una construcion algo sencilla de paredes blancas y tejado de "
		"pizarra, para cuando nieva no se hunda el techo, es de dos pisos.\n"));
	AddDetail(({"monta�a","monta�as","montanya","montanyas"}),
		W("Son unas enormes monta�as que rodean este maravilloso valle. Parecen"
		" ser bastante escarpadas y abruptas, con lo que la unica via de "
		"entrada es por el bosque.\n"));
	AddDetail(({"r�o","riachuelo","arroyo"}),
		W("Es un delgado hilo de agua azul que parte el prado en dos. No distingues"
		" de donde nace, pero parece que surja de las monta�as\n"));
	AddDetail(({"letrero","cartel"}),
		"			*****************\n"
		"			** BIENVENIDOS **\n"
		"			**     A       **\n"
		"			**   KRIGOR    **\n"
		"			*****************\n");

// Ahora se le daran detalles de olor y oido

	SetNoise(W(	"Oyes el rumor del viento sobre las copas"
			" de los �rboles.\n"));
	SetSmell(	"Huele a humedad.\n");

// Donde localizamos esta zona

	SetLocate("Krigor");

// se encuentra al aire libre, es un prado

	SetIndoors(0);

// Salidas de la habitaci�n

	AddExit("norte",KRIGOR("sendero02"));
	AddExit("sur",BOSQUE_NYN("bosque004"));
}