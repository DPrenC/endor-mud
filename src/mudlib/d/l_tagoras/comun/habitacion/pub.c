/* vi: set tabstop=4 */
/** @file pub.c
	@brief la tasca de Nandor
	@author SimBuilder
	@version 1.00
	@date 2008-08-23

Esta es la tasca de Nandor, un lugar medianamente pequeño, pero acogedor y familiar. Siempre hay buenos amigos conversando, tomándose unas copas o, simplemente, pasando el rato.
	Al dueño del local le gusta servir bebidas un tanto distintas. Al lado de unos cuadros se encuentra colgado el menú.
*/

#include "./path.h"

inherit PUB;

create() {
	::create();
	object rak;
	SetLocate("Area Test");
	SetIntShort("la tasca de Nandor");
	SetIntLong("Esta es la tasca de Nandor, un lugar medianamente pequeño, pero acogedor y familiar. Siempre hay buenos amigos conversando, tomándose unas copas o, simplemente, pasando el rato.\n"
	"Al dueño del local le gusta servir bebidas un tanto distintas. Al lado de unos cuadros se encuentra colgado el menú.\n");
	SetIntBright(30);
	SetIntNoise("Escuchas el gentío de la tasca.\n");
	SetIntSmell("Se mezclan los olores de los distintos licores y comidas que aquí se sirven.\n");
	AddDrink("vino tinto", "un vaso de", 4, 8, 5, 0);
	AddDrink("vino blanco", "un vaso de", 4, 8, 5, 0);
	AddDrink("cerveza rosa", "una jarra de", 5, 5, 10, 0, "Te bebes una jarra de cerveza rosa. ¡Esta cerveza sabe a fresas!.\n");
	AddDrink("cerveza especial", "una jarra de", 9, 10, 13, 0, "Te bebes la cerveza especial que entra como un rayo, parece que le hayan puesto ginebra.\n");
	AddDrink("zumo de mora", "un vaso de", 5, 0, 9, 0);
	AddDrink("sidra con tequila", "un chupito de", 7, 15, 5, 0);
	AddDrink("zumod de frutas silvestres", "un vaso de", 8, 0, 11, 0);
	AddDrink("zumo de naranja con ron", "un vaso de", 5, 6, 7, 0);
	AddFood("jamón", "unos taquitos de", 8, 11, 0);
	AddFood("queso", "unos taquitos de", 7, 10, 0);
	AddFood("olivas partidas", "unas", 3, 5, 0, "Te metes un puñado de olivas de golpe en la boca y escupes los huesos a diestro y siniestro.\n");
	AddFood("anchoas", "unas", 5, 7, 0);
	AddSpecial("litru", "un cuenco de", 12, 7, 11, 7, 0, "Te tomas el cuenco del mejunje este raro... puedes apreciar que lleva chufas trituradas, zumo de limón y algo de ron.\n");

	//if ( !(rak=find_object( "d/simauria/comun/habitacion/marhalt/nandor/rak-nal-turi") ) )
		AddItem (PNJ("rak-nal-turi"), REFRESH_REMOVE, 1);
		//catch(AddItem (PNJ("rak-nal-turi"), REFRESH_REMOVE, 1));
	//else
		//if ( find_object("tagoras") ) dtell ("tagoras",sprintf("Rak-nal-turi -> %O\n", environment(rak)));
}
