/* vi: set tabstop=4 */
/** @file c213.c
	@brief el despacho de Altriv, el director del centro
	@author SimBuilder
	@version 1.00
	@date 2009-03-07

Estás en el despacho de Altriv, el director del centro de adiestramiento de reclutas enanos. Es con mucho la habitación más interesante de todas las que se pueden ver en el centro. En la pared norte se abre un gran ventanal desde el que se puede ver toda la Arena y justo en el centro de la habitación hay una enorme mesa de madera de caoba en la que Altriv realiza sus trabajos administrativos. En las paredes puedes ver también varias armas colgadas y una enseña del dominio de Kha-annu, algo diferente de las que hay en las otras estancias.
*/

#include "./path.h"

inherit HAB_CENTRO_ANNUFAM("base_centro.c");

int cmd_coger(string str);

create() {
	::create();
	SetLocate("Annufam");
	SetIntShort("el despacho de Altriv, el director del centro");
	SetIntLong("Estás en el despacho de Altriv, el director del centro de adiestramiento de reclutas enanos. Es con mucho la habitación más interesante de todas las que se pueden ver en el centro. En la pared norte se abre un gran ventanal desde el que se puede ver toda la Arena y justo en el centro de la habitación hay una enorme mesa de madera de caoba en la que Altriv realiza sus trabajos administrativos. En las paredes puedes ver también varias armas colgadas y una enseña del dominio de Kha-annu, algo diferente de las que hay en las otras estancias.\n");
	AddDetail(({"ensenya", "enseña"}), "No te llama la atención su forma sino los materiales con los que está fabricada. Todas las enseñas que has visto hasta ahora han sido pinturas, tapices o grabados, pero esta es una reproducción del escudo en oro, diamantes y mithril... quien sabe si no será el escudo original de Kha-annu.\n");
	AddDetail(({"pared", "paredes"}), "A pesar del valor de las armas y la enseña del dominio de Kha-annu que ves colgada en la pared, lo que más te llama la atención es un pergamino que hay colgado en la pared del este.\n");
	AddDetail("techo", "Se trata de un techo abovedado en el que puedes ver talladas varias cabezas de león.\n");
	AddDetail("suelo", "Sabes que está fabricado con las mismas baldosas verdes y marrones que el suelo del resto del edificio porque las ves asomar a los lados de una gran alfombra que lo cubre casi en su totalidad.\n");
	AddDetail("alfombra", "Es una gran y mullida alfombra de lana decorada con los tradicionales leones del escudo de Kha-annu.\n");
	AddDetail(({"arma", "armas"}), "Se trata de armas de varios tipos y tamaños pero entre las que predominan las hachas y alguna que otra espada orca, recuerdo sin duda de alguna batalla.\n");
	AddDetail(({"muebles", "mobiliario"}), "Solo hay un armario y una gran mesa.\n");
	AddDetail("armario", "Se trata de un armario no excesivamente grande pero sí muy resistente. Está fabricado con madera de los árboles de las montañas de Kha-annu y tiene una cerradura que no podrías abrir por mucho que lo intentaras.\n");
	AddDetail("mesa", "Es una mesa cuadrada situada en el centro del despacho. Está fabricada con la madera del mismo árbol que el armario y sobre ella puedes ver algunos documentos.\n");
	AddDetail(({"documento", "documentos"}), "Sin duda se trata de documentos de gran importancia para los enanos así que será mejor que no los toques.\n");
	SetIntNoise("El rumor del entrenamiento te llega a través de la ventana de un modo extrañamente distante y lejano.\n");
	SetIntSmell("Aspiras el aroma del despacho y descubres que no tiene nada que ver con el del resto del edificio. Se siente  un ligero aroma a madera muy agradable.\n");
	AddExit("sur", "c214");
	AddItem(OTRO_ANNUFAM("pergamino_despacho"), REFRESH_REMOVE);
	AddRoomCmd("coger", "cmd_coger");
}

int cmd_coger(string str)
{
	string cosa;

	if (!str) return 0;
	cosa = trim(LOWER(str));
	if ("pergamino" == cosa)
	{
		write ("¿Estás de broma? Seguro que si lo haces no sales vivo de aquí.\n");
		return 1;
	}
	if ("armas de pared" == cosa)
	{
		write ("No creo que sea buena idea coger unas armas tan valiosas, lo más probable es que sufras represalias.\n");
		return 1;
	}
	if ("documentos" == cosa)
	{
		write ("Sin duda se trata de documentos muy valiosos para los enanos así que mejor déjalos ahí.\n");
		return 1;
	}

	return 0;
}
