/* vi: set tabstop=4 */
/** @file c113.c
	@brief una sala de descanso
	@author SimBuilder
	@version 1.00
	@date 2009-02-27

Esta es una sala que no tiene nada que ver con las otras que se pueden ver en el edificio. Aqu� todo parece estar hecho para el descanso y el placer. No se ve ni una sola arma y sin embargo en las paredes se observan pinturas y ense�as muy agradables. El mobiliario tambi�n est� muy bien cuidado, con unos magn�ficos sillones que deben ser puro placer para un cuerpo dolorido.
*/

#include "./path.h"

inherit HAB_CENTRO_ANNUFAM("base_centro");

create() {
	::create();
	SetIntShort("una sala de descanso");
	SetIntLong("Esta es una sala que no tiene nada que ver con las otras que se pueden ver en el edificio. Aqu� todo parece estar hecho para el descanso y el placer. No se ve ni una sola arma y sin embargo en las paredes se observan pinturas y ense�as muy agradables. El mobiliario tambi�n est� muy bien cuidado, con unos magn�ficos sillones que deben ser puro placer para un cuerpo dolorido.\n");
	AddDetail(({"sillon", "sill�n", "sillones"}), "Hay varios sillones de diferentes tama�os y materiales distribuidos por toda la sala. La verdad es que tienen una pinta fenomenal.\n");
	AddDetail(({"mobiliario", "mueble", "muebles"}), "El mobiliario de la sala parece magn�fico. Hay unos bonitos armarios de caoba roja, un par de mesas, alguna que otra silla, pero lo que m�s gustar�a a cualquiera son los sillones ya que tienen una pinta estupenda.\n");
	AddDetail(({"armario", "armarios"}), "Los armarios de la sala permanecen cerrados y se ve que la llave est� muy bien guardada, as� que olv�date de abrirlos.\n");
	AddDetail(({"mesa", "mesas"}), "Se trata de un par de mesas de madera de caoba muy grandes y alrededor de las cuales hay varias sillas muy c�modas.\n");
	AddDetail(({"silla", "sillas"}), "Son unas sillas de madera de caoba con los acabados en piel.\n");
	AddDetail(({"pintura", "pinturas"}), "Son unas pinturas en las que se puede ver a enanos en diferentes posiciones. La mayor�a de ellas est�n ambientadas en el campo pero tambi�n hay algunas en la que no hay cielo y que deduces est�n ambientadas en las minas\n");
	AddDetail(({"ense�a", "ensenya"}), "Hay colgadas algunas reproducciones de la ense�a oficial del dominio de Kha-annu.\n");
	AddDetail(({"pared", "paredes"}), "Las paredes de esta sala son muy diferentes a las del resto. Aqu� no ves piedra m�s que en algunos puntos muy concretos y, �c�mo no?, formando la cabeza de un le�n. El resto est� forrado todo de madera de caoba y por aqu� y all� tambi�n puedes observar alguna pintura.\n");
	AddDetail("techo", "El techo de esta sala tambi�n es diferente al del resto del edificio. Sigue siendo abovedado pero est� mucho m�s acabado ya que todos los arcos que lo sustentan est�n decorados con cabezas de le�n.\n");
	AddDetail("ventana", "Desde la ventana de la habitaci�n puedes ver mucho mejor La Arena del centro de adiestramiento. Te fijas y ves a algunos enanos en actitud de combate.\n");
	AddExit("sur", "c114");
	AddItem(PNJ_CENTRO_ANNUFAM("anglhanail"), REFRESH_DESTRUCT);
}
