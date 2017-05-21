/***************************************************************************************
 ARCHIVO:	folker_08.c
 AUTOR:		[z] Zomax
 FECHA:		08-11-2001
 COMENTARIOS:	Calle Folker de Koek
 MODIFICACION:  07-04-03 Quito un par de variables que no tengo ni idea de por qué dejé.
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("roome");

create () {
    ::create();

     SetLocate("Koek");
     SetIntShort("la calle Folker");
     carcel=(RHOEHAB("koek/calles/folker_09"));

     AddExit("norte",RHOEHAB("koek/varios/banco"));
     AddExit("este",RHOEHAB("koek/calles/folker_09"));
     AddExit("oeste",RHOEHAB("koek/calles/folker_07"));
    AddItem(RHOEPNJ("koek/ciudadanos/ciudadano3"), REFRESH_DESTRUCT);
    map[neu,des]= "La calle de Folker se extiende ante ti. Es una calle "
  		"bastante normal, quizás algo estrecha para ser una vía "
  		"principal. Al norte de aquí ves el Banco de Koek, siempre "
  		"custodiado. Al este puedes ver que la calle sigue y una "
  		"entrada a la posada. Al oeste también sigue la calle, en "
  		"este caso hacia la plaza de Zendak. ";
}