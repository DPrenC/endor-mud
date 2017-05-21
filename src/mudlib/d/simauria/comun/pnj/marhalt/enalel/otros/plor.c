/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	PNJ de Enalel
 *****************************************************************************/

#include "path.h"
#include <properties.h>

inherit ENALPNJ"base";

create(){
  ::create();
 
  SetStandard("Plor","humano",10+random(3),GENERO_MASCULINO);
  SetShort("Plor el cartero");
  SetLong(W("Es un humano de aspecto inquieto y enfermizo que no hace m�s que "
  "revisar el correo y lamentarse.\n"));
  SetIds(({"humano","cartero","Plor","plor"}));
  SetAlign(30);
  InitChats(9,({
	"Plor coge una carta de una bolsa y la coloca en su buz�n.\n",
	"Plor dice: 'Hace a�os que deber�a estar trabajando en la sede de Pomar pero esos d�spotas me env�dian'\n",
	"Plor dice: 'Yo, que trabajo hasta en fiestas, y me pagan as�...'\n",
	"Plor se lamenta en silencio.\n",
	"Plor mascuya palabras incomprensibles mientras clasifica el correo.\n",
	"Plor te mira y te dice: '�Desea algo?'"}));
}
