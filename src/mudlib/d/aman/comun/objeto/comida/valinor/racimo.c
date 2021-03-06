/*****************************************************************************************
 ARCHIVO:       racimo.c
 AUTOR:         Ztico
 FECHA:         04-06-2006
 DESCRIPCI�N:   Un racimo para la parra
 COMENTARIOS:   
*****************************************************************************************/

#include "./path.h"
#include <properties.h>

inherit FOOD;

create()
{
    if(::create()) return 1;
    	
    seteuid(getuid());
    SetShort("un suculento racimo de uvas");
    SetLong("Es un racimo de carnosas y enormes uvas blancas.\n");
    Set(P_GENDER, GENERO_MASCULINO);
    Set(P_NUMBER, NUMERO_SINGULAR);
    AddId(({"racimo_uvas", "racimo", "r�cimo", "uva", "r�cimo de uva"}));
    AddSubDetail(({"uva", "uvas"}), "Pues eso, son uvas.\n");
        SetFoodMsgs("Te comes un r�cimo de uvas.\n");
    SetFoodStuff(11);
    SetFoodHeal(6);

}
