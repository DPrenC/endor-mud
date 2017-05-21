/****************************************************************************
Fichero: prenda_inferior.c
Autor: Ratwor.
Fecha: 11/08/2007
Descripci�n: Una falda o un pantal�n seg�n el sexo del portador.
****************************************************************************/

#include "./path.h"
#include <combat.h>
#include <properties.h>
inherit ARMOUR;

create()
{
	::create();
	string *colores=({"gris", "violeta", "marr�n", "a rayas", "a cuadros", "verde", "azul",
        "granate", "con flores", "de tela", "de piel", "de lana"});
    string color=colores[random(sizeof(colores))];
	SetStandard(AT_TROUSERS,d2(),P_SIZE_LARGE,M_TELA);
	SetResetQuality(100);

    if (!TP || TP->QueryGender()==GENDER_MALE){
        SetShort("un pantal�n "+color);
	    SetLong("Es un pantal�n "+color+", algo corriente, pero resistente.\n");
        Set(P_NUMBER, NUMBER_PLURAL);
	    Set(P_GENDER, GENDER_MALE);
	    SetWeight(900);
	    SetValue(QueryValue()*3);
	    AddId(({"pantalon", "pantal�n", "pantalones", "prenda", "ropa"}));
	}else{
        SetShort("una falda "+color);
	    SetLong("Es una simple falda "+color+" t�pica de la zona de Marhalt.\n");
	    Set(P_GENDER, GENDER_FEMALE);
	    Set(P_NUMBER, NUMBER_SINGULAR);
	    SetWeight(900);
	    AddId(({"prenda", "ropa", "falda"}));
	}
}