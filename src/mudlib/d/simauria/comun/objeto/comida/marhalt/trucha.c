/***************************************************************************************
 ARCHIVO:	trucha.c
 AUTOR:		Ratwor
 FECHA:		21-03-2010
 COMENTARIOS:	La trucha que se pesca en el río del bosque de Marhalt.
              Algo copiada de la trucha de los comercios de Koek.
 ***************************************************************************************/

#include "./path.h"
#include <properties.h>

inherit FOOD;


int fcocinar(string str)
{
	if (str=="trucha")
	{
		write("Cocinas la trucha con lo que tienes a mano...\n");
		SetFoodMsgs("Te comes la trucha... está sabrosa...\n");
		SetFoodStuff(15);
 		SetFoodHeal(15);
 		SetShort("una trucha cocinada");
 		SetLong("Una sabrosa trucha bien cocinada.\n");
 		SetSmell("Huele de maravilla.\n");
		return 1;
	}
}

create () {
    ::create();
    int peso=(500+(d20(20)*d10())); // así da los pesos reales de una trucha de verdad
    SetFoodKind("food");
    SetFoodMsgs("Te comes la trucha cruda, con espinas y todo.\n");
    SetFoodStuff(5);
    SetFoodHeal(5);
     SetShort("una trucha");
     SetLong("Es una trucha cruda. Un pescado plateado con rayas oscuras que suele medir "
    "algo más de 30 centímetros de largo y unos 12 de diámetro.\n");
    AddId(({"pez", "pescado", "trucha"}));
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    Set(P_SIZE,P_SIZE_MEDIUM);
    SetWeight(peso);
    SetValue(QueryWeight()/10);
    SetSmell("Huele a lo típico que huele el pescado crudo.\n");
}

init(){
    ::init();

    add_action("fcocinar","cocinar");
}
