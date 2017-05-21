	   //////////////////////////////////////////
	  //   Creado originalmente por Tsume     //
	 //   Modificado ligeramente por Alura   //
	//////////////////////////////////////////

#include "path.h"
#include <moving.h>


inherit LAD_ROOM;

object arma;
int armaclonada;

int funEx1(string str){
	if ( ((str=="victimas") || (str=="víctimas")) && (armaclonada==0) ) {
		arma=clone_object(ALUOBJ("arma/espadon-plata"));
		arma->move(TO,M_SILENT);
		tell_object(TP," Al examinar cuidadosamente entre los restos, descubres un "+
		"arma que tal vez puedas aprovechar.\n");
		armaclonada=1;
		return 1;
	} else return 0;
	if (str=="") return 0;
	if (armaclonada==1) return 0;
}

create()
{
  ::create();
  armaclonada=0;
  SetIntShort("el laboratorio de DheSarf");
  SetIntLong(
    "Esta es la habitacion donde DheSarf, que decidio que su existencia era "
          "demasiado corta, experimenta con los vivos. Esparcidos por el suelo puedes "
          "ver restos horriblemente mutilados de innumerables generaciones de victimas "
          "de DheSarf.\n"
    );
  SetIndoors(1);
  SetIntBright(0);
  SetIntSmell(
          "El aire esta particularmente viciado en esta sala, como si no entrase una "
            "rafaga de aire fresco desde hace siglos\n"
    );
  SetIntNoise(
    "Oyes los lamentos de las almas de las victimas de DheSarf que aun no han sido "
          "arrastradas al río de las almas condenadas.\n"
    );
  AddDetail(({"restos","cadaveres"}),
    "Son las victimas de la hechiceria de DheSarf, cientos de cuerpos desmembrados, "
          "decapitados, o sencillamente destrozados.\n"
    );

  AddExit("norte",ALUTIIN("cementerio/cripta/mausoleo1"));
}

init(){
	::init();
	add_action("funEx1","examinar");
}
