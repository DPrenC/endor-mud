/* ******************************************************
   *                                                    *
   *  Archivo:      dedogar.c                           *
   *  Autor:        [a] Articman                        *
   *  Descripci�n:  Objeto para dar y completar quest.  *
   *                Se consigue matando a la g�rgola.   *
   *  Modificaci�n: 31/01/02 [a] Creaci�n               *
   *                03/03/03 [z] A�ado no robar y func. *
   *                         para darsela solo al que   *
   *                         toca.                      *
   ******************************************************  */


inherit THING;
#include <properties.h>
#include "path.h"

create() {
::create();
SetShort("un dedo de g�rgola");
SetLong(W("Es un largo dedo de g�rgola viva. Mide unos "
"20 cm de largo. Es de color oscuro y restos de sangre "
"roja. Acaba en una afilada y negra u�a.\n"));
SetIds(({"dedo gargola","dedo g�rgola","dedo de gargola"
,"dedo de g�rgola","dedo","d_gargola"}));
Set(P_GENDER,GENERO_MASCULINO);
Set(P_NUMBER,NUMERO_SINGULAR);
SetWeight(100);
Set(P_CANT_STEAL,1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
}

init(){
  ::init();

  add_action("fdar","dar");

}

public int fdar(string str)
{
	object bardo;
	string cosa,quien;

	if (!str  || sscanf(str,"%s a %s",cosa,quien) != 2) return 0;
	if (environment(TP) && id(cosa))
	{
		bardo=present(quien,environment(TP));
		if (bardo && (living(bardo)) && (bardo->id("bardo"))) return 0;
		else
		{
			write("No puedes dar el dedo.\n");
			return 1;
		}
	}
}
