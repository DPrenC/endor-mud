/* vi: set tabstop=4 */
/** @file c215.c
	@brief la habitaci�n de Altriv, el director del centro
	@author SimBuilder
	@version 1.00
	@date 2009-03-07

Esta es la habitaci�n del director del centro de adiestramiento para guerreros enanos de Annufam. Desde luego Altriv no vive como el resto de los soldados. Su habitaci�n est� adornada con buen gusto y de toda ella destaca una enorme cama que hay justo debajo de la ventana. Los muebles son todos de caoba y el suelo est� cubierto por una mullida alfombra que otorga a la estancia una apariencia muy confortable.
*/

#include "./path.h"

inherit HAB_CENTRO_ANNUFAM("base_centro.c");

create() {
	::create();
	SetLocate("Annufam");
	SetIntShort("la habitaci�n de Altriv, el director del centro");
	SetIntLong("Esta es la habitaci�n del director del centro de adiestramiento para guerreros enanos de Annufam. Desde luego Altriv no vive como el resto de los soldados. Su habitaci�n est� adornada con buen gusto y de toda ella destaca una enorme cama que hay justo debajo de la ventana. Los muebles son todos de caoba y el suelo est� cubierto por una mullida alfombra que otorga a la estancia una apariencia muy confortable.\n");
	AddDetail("cama", "Se trata de una cama mucho m�s grande que las dem�s que has visto en Annufam. Esta no tiene un colch�n de paja sino un c�modo colch�n de plumas sobre el que est�s seguro que se debe dormir de maravilla.\n");
	AddDetail(({"pared", "paredes"}), "Las paredes de la habitaci�n de Altriv est�n pr�cticamente desnudas. En ellas solo puedes ver un hermoso tapiz y una ventana que se abre a la ciudad\n");
	AddDetail("suelo", "Sabes que est� fabricado con las mismas baldosas verdes y marrones que el suelo del resto del edificio porque las ves asomar a los lados de una gran alfombra que lo cubre casi en su totalidad.\n");
	AddDetail("techo", "Se trata de un techo abovedado en el que puedes ver talladas varias cabezas de le�n.\n");
	AddDetail("alfombra", "Est� tejida en lana pero en ella no ves las t�picas cabezas de le�n que desde que has entrado en la ciudad te vienen persiguiendo. El dibujo de la alfombra es una c�lida mezcla de colores sin una forma concreta, pero que en su conjunto te producen una sensaci�n de bienestar.\n");
	AddDetail("tapiz", "Es un tapiz muy parecido a la alfombra. Igual que ella est� tejido en lana y decorado con la misma combinaci�n de colores.\n");
	AddDetail(({"muebles", "mobiliario"}), "La cama y un armario de doble hoja es el �nico mobiliario de la habitaci�n.\n");
	AddDetail("armario", "Es un armario de doble hoja fabricado con la madera de los �rboles de las monta�as de Kha-annu. Su aspecto es tan resistente que est�s seguro de que no lo podr�as abrir por mucho que lo intentaras.\n");
	AddDetail("ventana", "Desde esta altura puedes contemplar toda la extensi�n de la ciudad de Annufam, desde la entrada a la misma y el foso hasta las mismas puertas del Centro de Adiestramiento para Guerreros Enanos.\n");
	SetIntNoise("Los rumores de la calle que llegan a trav�s de la ventana son los �nicos sonidos que escuchas.\n");
	SetIntSmell("Un suave aroma a madera envuelve la habitaci�n caus�ndote un verdadero bienestar.\n");
	AddExit("norte", "c214");
	AddItem(PNJ_CENTRO_ANNUFAM("altriv"), REFRESH_DESTRUCT);
}
