/****************************************************************************
Fichero: prenda_inferior.c
Autor: Ratwor.
Fecha: 11/08/2007
Descripción: Una falda o un pantalón según el sexo del portador.
****************************************************************************/

#include "./path.h"
#include <combat.h>
#include <properties.h>
inherit ARMOUR;

create()
{
	::create();
	string *colores=({"gris", "violeta", "marrón", "a rayas", "a cuadros", "verde", "azul",
        "granate", "con flores", "de tela", "de piel", "de lana"});
    string color=colores[random(sizeof(colores))];
	SetStandard(AT_TROUSERS,d2(),P_SIZE_LARGE,M_TELA);
	SetResetQuality(100);

    if (!TP || TP->QueryGender()==GENDER_MALE){
        SetShort("un pantalón "+color);
	    SetLong("Es un pantalón "+color+", algo corriente, pero resistente.\n");
        Set(P_NUMBER, NUMBER_PLURAL);
	    Set(P_GENDER, GENDER_MALE);
	    SetWeight(900);
	    SetValue(QueryValue()*3);
	    AddId(({"pantalon", "pantalón", "pantalones", "prenda", "ropa"}));
	}else{
        SetShort("una falda "+color);
	    SetLong("Es una simple falda "+color+" típica de la zona de Marhalt.\n");
	    Set(P_GENDER, GENDER_FEMALE);
	    Set(P_NUMBER, NUMBER_SINGULAR);
	    SetWeight(900);
	    AddId(({"prenda", "ropa", "falda"}));
	}
}