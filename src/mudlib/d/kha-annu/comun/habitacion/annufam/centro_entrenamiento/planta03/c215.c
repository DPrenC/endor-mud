/* vi: set tabstop=4 */
/** @file c215.c
	@brief la habitación de Altriv, el director del centro
	@author SimBuilder
	@version 1.00
	@date 2009-03-07

Esta es la habitación del director del centro de adiestramiento para guerreros enanos de Annufam. Desde luego Altriv no vive como el resto de los soldados. Su habitación está adornada con buen gusto y de toda ella destaca una enorme cama que hay justo debajo de la ventana. Los muebles son todos de caoba y el suelo está cubierto por una mullida alfombra que otorga a la estancia una apariencia muy confortable.
*/

#include "./path.h"

inherit HAB_CENTRO_ANNUFAM("base_centro.c");

create() {
	::create();
	SetLocate("Annufam");
	SetIntShort("la habitación de Altriv, el director del centro");
	SetIntLong("Esta es la habitación del director del centro de adiestramiento para guerreros enanos de Annufam. Desde luego Altriv no vive como el resto de los soldados. Su habitación está adornada con buen gusto y de toda ella destaca una enorme cama que hay justo debajo de la ventana. Los muebles son todos de caoba y el suelo está cubierto por una mullida alfombra que otorga a la estancia una apariencia muy confortable.\n");
	AddDetail("cama", "Se trata de una cama mucho más grande que las demás que has visto en Annufam. Esta no tiene un colchón de paja sino un cómodo colchón de plumas sobre el que estás seguro que se debe dormir de maravilla.\n");
	AddDetail(({"pared", "paredes"}), "Las paredes de la habitación de Altriv están prácticamente desnudas. En ellas solo puedes ver un hermoso tapiz y una ventana que se abre a la ciudad\n");
	AddDetail("suelo", "Sabes que está fabricado con las mismas baldosas verdes y marrones que el suelo del resto del edificio porque las ves asomar a los lados de una gran alfombra que lo cubre casi en su totalidad.\n");
	AddDetail("techo", "Se trata de un techo abovedado en el que puedes ver talladas varias cabezas de león.\n");
	AddDetail("alfombra", "Está tejida en lana pero en ella no ves las típicas cabezas de león que desde que has entrado en la ciudad te vienen persiguiendo. El dibujo de la alfombra es una cálida mezcla de colores sin una forma concreta, pero que en su conjunto te producen una sensación de bienestar.\n");
	AddDetail("tapiz", "Es un tapiz muy parecido a la alfombra. Igual que ella está tejido en lana y decorado con la misma combinación de colores.\n");
	AddDetail(({"muebles", "mobiliario"}), "La cama y un armario de doble hoja es el único mobiliario de la habitación.\n");
	AddDetail("armario", "Es un armario de doble hoja fabricado con la madera de los árboles de las montañas de Kha-annu. Su aspecto es tan resistente que estás seguro de que no lo podrías abrir por mucho que lo intentaras.\n");
	AddDetail("ventana", "Desde esta altura puedes contemplar toda la extensión de la ciudad de Annufam, desde la entrada a la misma y el foso hasta las mismas puertas del Centro de Adiestramiento para Guerreros Enanos.\n");
	SetIntNoise("Los rumores de la calle que llegan a través de la ventana son los únicos sonidos que escuchas.\n");
	SetIntSmell("Un suave aroma a madera envuelve la habitación causándote un verdadero bienestar.\n");
	AddExit("norte", "c214");
	AddItem(PNJ_CENTRO_ANNUFAM("altriv"), REFRESH_DESTRUCT);
}
