/****************************************************************************
Fichero: base_room
Autor: Tagoras
Fecha: 27/02/2009
Descripci�n: Base de las rooms de los reclutas y soldados de la primera planta del centro.
****************************************************************************/

#include "path.h"

inherit HAB_SEGUNDA_ANNUFAM("base_planta");

create()
{
    ::create();
	AddDetail("armario", "Se trata de un rudimentario mueble de una sola puerta construido con la misma madera que el resto del mobiliario. Est� cerrado y no parece que puedas abrirlo.\n");
	AddDetail("cama", "Es una cama muy estrecha y bastante peque�a. Su estructura es de madera y el colch�n parece de paja.\n");
	AddDetail(({"mesa", "mesita"}), "Es una mesita peque�a de madera sobre la que su propietario ha dejado unas monedas.\n");
	AddDetail(({"mobiliario", "muebles"}), "Es un mobiliario muy rudimentario pero que cumple bien su labor. Ves una cama, una mesita y un armario cerrado.\n");
	AddDetail(({"moneda", "monedas"}), "�Vas a molestarte por dos cobres? D�jaselos a su due�o que con eso no tienes para nada.\n");
	AddDetail(({"pared", "paredes"}), "Son unas paredes de piedra en la que puedes ver alguna peque�a pintura y alguna antorcha colgada.\n");
	AddDetail(({"cuadro", "cuadros", "pintura", "pinturas"}), "En la pared ves algunas pinturas que representan enanos en diferentes actitudes. Imaginas que son retratos que los familiares regalaron a los reclutas antes de venir a Annufam.\n");
	AddDetail("silla", "Es una simple silla construida con la misma madera que el resto de muebles de la habitaci�n.\n");
}

void AddNWindow()
{
    AddDetail("ventana", "Desde la ventana de la habitaci�n puedes ver mucho mejor la Arena del centro de adiestramiento. Te fijas y ves a algunos enanos en actitud de combate.\n");
}

void AddSWindow()
{
    AddDetail("ventana", "Desde esta altura puedes ver parte de la ciudad de Annufam pero no tienes perspectiva suficiente como para alcanzar a ver las murallas y m�s all�.\n");
}
