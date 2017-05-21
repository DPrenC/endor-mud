/* vi: set tabstop=4 */
/** @file c213.c
	@brief el despacho de Altriv, el director del centro
	@author SimBuilder
	@version 1.00
	@date 2009-03-07

Est�s en el despacho de Altriv, el director del centro de adiestramiento de reclutas enanos. Es con mucho la habitaci�n m�s interesante de todas las que se pueden ver en el centro. En la pared norte se abre un gran ventanal desde el que se puede ver toda la Arena y justo en el centro de la habitaci�n hay una enorme mesa de madera de caoba en la que Altriv realiza sus trabajos administrativos. En las paredes puedes ver tambi�n varias armas colgadas y una ense�a del dominio de Kha-annu, algo diferente de las que hay en las otras estancias.
*/

#include "./path.h"

inherit HAB_CENTRO_ANNUFAM("base_centro.c");

int cmd_coger(string str);

create() {
	::create();
	SetLocate("Annufam");
	SetIntShort("el despacho de Altriv, el director del centro");
	SetIntLong("Est�s en el despacho de Altriv, el director del centro de adiestramiento de reclutas enanos. Es con mucho la habitaci�n m�s interesante de todas las que se pueden ver en el centro. En la pared norte se abre un gran ventanal desde el que se puede ver toda la Arena y justo en el centro de la habitaci�n hay una enorme mesa de madera de caoba en la que Altriv realiza sus trabajos administrativos. En las paredes puedes ver tambi�n varias armas colgadas y una ense�a del dominio de Kha-annu, algo diferente de las que hay en las otras estancias.\n");
	AddDetail(({"ensenya", "ense�a"}), "No te llama la atenci�n su forma sino los materiales con los que est� fabricada. Todas las ense�as que has visto hasta ahora han sido pinturas, tapices o grabados, pero esta es una reproducci�n del escudo en oro, diamantes y mithril... quien sabe si no ser� el escudo original de Kha-annu.\n");
	AddDetail(({"pared", "paredes"}), "A pesar del valor de las armas y la ense�a del dominio de Kha-annu que ves colgada en la pared, lo que m�s te llama la atenci�n es un pergamino que hay colgado en la pared del este.\n");
	AddDetail("techo", "Se trata de un techo abovedado en el que puedes ver talladas varias cabezas de le�n.\n");
	AddDetail("suelo", "Sabes que est� fabricado con las mismas baldosas verdes y marrones que el suelo del resto del edificio porque las ves asomar a los lados de una gran alfombra que lo cubre casi en su totalidad.\n");
	AddDetail("alfombra", "Es una gran y mullida alfombra de lana decorada con los tradicionales leones del escudo de Kha-annu.\n");
	AddDetail(({"arma", "armas"}), "Se trata de armas de varios tipos y tama�os pero entre las que predominan las hachas y alguna que otra espada orca, recuerdo sin duda de alguna batalla.\n");
	AddDetail(({"muebles", "mobiliario"}), "Solo hay un armario y una gran mesa.\n");
	AddDetail("armario", "Se trata de un armario no excesivamente grande pero s� muy resistente. Est� fabricado con madera de los �rboles de las monta�as de Kha-annu y tiene una cerradura que no podr�as abrir por mucho que lo intentaras.\n");
	AddDetail("mesa", "Es una mesa cuadrada situada en el centro del despacho. Est� fabricada con la madera del mismo �rbol que el armario y sobre ella puedes ver algunos documentos.\n");
	AddDetail(({"documento", "documentos"}), "Sin duda se trata de documentos de gran importancia para los enanos as� que ser� mejor que no los toques.\n");
	SetIntNoise("El rumor del entrenamiento te llega a trav�s de la ventana de un modo extra�amente distante y lejano.\n");
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
		write ("�Est�s de broma? Seguro que si lo haces no sales vivo de aqu�.\n");
		return 1;
	}
	if ("armas de pared" == cosa)
	{
		write ("No creo que sea buena idea coger unas armas tan valiosas, lo m�s probable es que sufras represalias.\n");
		return 1;
	}
	if ("documentos" == cosa)
	{
		write ("Sin duda se trata de documentos muy valiosos para los enanos as� que mejor d�jalos ah�.\n");
		return 1;
	}

	return 0;
}
