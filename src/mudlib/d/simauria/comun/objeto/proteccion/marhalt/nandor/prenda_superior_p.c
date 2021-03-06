/****************************************************************************
Fichero: prenda_superior.c
Autor: Rakwor.
Fecha: 11/08/2007
Descripci�n: Una camisa o una blusa seg�n el sexo del pnj, de talla peque�a.
****************************************************************************/

#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>

inherit ARMOUR;
create(){
    ::create();
    string *colores=({"gris", "violeta", "marr�n", "a rayas", "a cuadros", "verde", "azul",
        "granate", "con flores", "de tela", "remendada", "de piel", "deste�ida",
        "blanca", "amarilla", "roja", "parda"});
    string color=colores[random(sizeof(colores))];

	SetStandard(AT_TUNICA, 1, P_SIZE_SMALL, M_TELA);
	SetQuality(100);
	Set(P_NUMBER, NUMBER_SINGULAR);
	Set(P_GENDER, GENDER_FEMALE);
	SetWeight(500);
	SetValue(QueryValue()*2);
	if (!TP || TP->QueryGender()==GENDER_MALE){
        SetShort("una camisa "+color);
        SetLong("Una elegante camisa "+color+" de la regi�n de Marhalt.\n");
        AddId(({"camisa", "elegante camisa","camisa elegante", "prenda", "ropa"}));
    }else{
        SetShort("una blusa "+color);
        SetLong("Una bonita blusa "+color+" de la regi�n de Marhalt.\n");
        AddId(({"blusa", "bonita blusa", "blusa bonita", "prenda", "ropa"}));
    }

}
