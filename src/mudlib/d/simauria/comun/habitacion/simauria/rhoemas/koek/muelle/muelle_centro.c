/***************************************************************************************

 ARCHIVO:	muelle_centro.c

 AUTOR:		[z] Zomax

 FECHA:		18-11-2001

 COMENTARIOS:	Centro del muelle

 ***************************************************************************************/



#include "path.h"



inherit RHOESTD("muelle");



create () {

    ::create();



    SetLocate("Koek");

    SetIntShort("el centro del muelle");

    AddRoomCmd("pescar","fpescar");

    carcel=(RHOEHAB("koek/calles/folker_04"));

  

    AddExit("norte",RHOEHAB("koek/calles/folker_04"));

    AddExit("sur",RHOEHAB("koek/muelle/muelle_sur"));

    AddExit("este",RHOEHAB("koek/muelle/muelle_este"));

    AddExit("oeste",RHOEHAB("koek/muelle/muelle_oeste"));

    AddItem(RHOEPNJ("koek/varios/gato"), REFRESH_DESTRUCT,d2());
    AddItem(RHOEPNJ("koek/ciudadanos/jovencito"), REFRESH_DESTRUCT);
    map[neu,des]= "Te encuentras en el centro de los muelles de Koek. Al norte se "

  		"encuentra la calle Folker, y al sur, este y oeste los extremos "

  		"del muelle, que dan al lago. Es un muelle muy rústico, hecho de "

  		"de madera. Parece en buen estado. ";

  

}



int fpescar(string str)

{

	notify_fail("Este no parece un buen sitio para pescar.\n");

	return 0;

}
