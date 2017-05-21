/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	PNJ de Enalel
 *****************************************************************************/

#include "path.h"
#include <properties.h>

inherit ENALPNJ"base";

create(){
  ::create();

  SetStandard("Librath","medioelfo",15+random(3),GENERO_MASCULINO);
  SetShort("Librath");
  SetLong(W("Es un anciano con rasgos �lficos perteneciente a la noble familia "
  "Silves. Su noble rostro parece surcado por arrugas de preocupaci�n.\n"));
  SetIds(({"humano","pueblerino","hombre","librath","Librath","anciano","viejo","noble","medio elfo","medioelfo"}));
  SetAlign(1000);
  InitChats(6,({
    "Librath mira en todas direcciones de forma nerviosa.\n",
    "Librath dice: '�D�nde estar� este chico?'\n",
    "Librath se rasca la cabeza pensativo.\n",
    "Librath dice: 'Ya deber�a haber vuelto con el objeto'\n",
    "Librath dice: 'Espero que la misi�n no sea demasiado dificil para el muchacho'\n",
    "Librath dice: 'Espero que vuelva pronto'\n",
    "Librath dice: 'Cualquiera sabe donde estar� este peque�o Biltem'\n"}));
}
