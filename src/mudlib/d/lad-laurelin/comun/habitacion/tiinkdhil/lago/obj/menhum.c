/*
DESCRIPCION    : alimento base
FICHERO        : DIRECCION/NOMBRE
CREACION       : 12-1-98 [koel].
U.MODIFICACION :
*/


#include "path.h"

inherit FOOD;

int curar;

//SOLO PARA COMIDA QUE QUIERAS QUE SE PUEDA COCINAR Y CAMBIE

init(){
	::init();
	
	add_action("hacer_cocinar","cocinar");
}
//HASTA AQUI.

create() {
	::create();
	
	curar=50;
		
	SetShort("Menhum");
	SetLong("No habias visto nunca este tipo de hierba.\n");
	AddId("hierba","menhum","la","el");       //identificativo, esto es como se llama
	SetFoodKind("food"); //comida o bebida, food, drink
	SetFoodMsgs(({"Te notas agradablemente mejor.\n"}));
	SetFoodHeal(curar);
	SetWeight(250);            //peso en gramos
	SetValue(400);             // valor en monedas de cobre
}


 