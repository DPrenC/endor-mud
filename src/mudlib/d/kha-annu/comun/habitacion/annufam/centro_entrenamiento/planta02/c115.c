/* vi: set tabstop=4 */
/** @file c115.c
	@brief un comedor
	@author SimBuilder
	@version 1.00
	@date 2009-02-27

Este es el comedor del centro de adiestramiento de guerreros enanos de Annufam. Ante ti tienes varias mesas rodeadas de bancos que cuando estén servidas deben tener una pinta estupenda. Con la fama de buenos comedores que tienen los enanos no te cabe ninguna duda de ello.
*/

#include "./path.h"

inherit HAB_CENTRO_ANNUFAM("base_centro");

create() {
	::create();
	SetIntShort("un comedor");
	SetIntLong("Este es el comedor del centro de adiestramiento de guerreros enanos de Annufam. Ante ti tienes varias mesas rodeadas de bancos que cuando estén servidas deben tener una pinta estupenda. Con la fama de buenos comedores que tienen los enanos no te cabe ninguna duda de ello.\n");
	AddDetail(({"mesa", "mesas"}), "Se trata de mesas de madera recia y de color oscuro de las que no se pide nada más que permanecer estables mientras los guerreros devoran el rancho.\n");
	AddDetail(({"pared", "paredes"}), "Son muy parecidas a las que has venido viendo hasta ahora: pintadas en verde y marrón, con alguna antorcha, con algún farol y con una gran ventana. Curiosamente aquí no hay enseña del dominio de Kha-annu... ¿será por tratarse del comedor?\n");
	AddDetail(({"silla", "sillas"}), "Son bancos corridos de madera en los que los guerreros enanos se sientan para comer.\n");
	SetIntNoise("Escuchas el sonido lejano de platos entrechocando.\n");
	SetIntSmell("Sientes un aroma a comida que te hace la boca agua. Parece que los soldados tienen para comer guisado de jabalí y mucha cerveza.\n");
	AddExit("norte", "c114");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
}
