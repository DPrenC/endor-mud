/***************************************************************************************
 ARCHIVO:	rakon.c
 AUTOR:		[z] Zomax
 FECHA:		01-12-2001
 COMENTARIOS:	Rakon, preso n�4 del calabozo n�3.
 MODIFICACI�N:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 		24-04-2003 Repaso c�digo para que quede m�s ordenado y claro.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

public string fmaestro(string str)
{
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (quest && member(quest,"libro"))
	{
		if (quest["libro",0]==1) quest+=(["libro":2]);
		if (quest["libro",0]==2)
		{
			return W("Rakon te dice: El maestro... si, si, a veces me "
			"escribe cartas. Me las envia a mi porque sabe que soy el "
			"�nico de los cuatro que sabe leer m�s o menos.\n");
		}
		else
		{
			return W("Rakon te dice: Espero que no sepa d�nde "
			"estamos... se decepcionar�a mucho si supiera donde hemos "
			"ido a parar...\n");
		}
	}
	else return W("Rakon te dice: Espero que no sepa d�nde estamos... se "
		"decepcionar�a mucho si supiera donde hemos ido a parar...\n");
}

public string fcartas(string str)
{
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (quest && member(quest,"libro"))
	{
		if (quest["libro",0]==2) quest+=(["libro":3]);
		if (quest["libro",0]==3)
		{
			if (environment(TO) && environment(TO)->QueryJabon())
			{
				return W("Rakon te dice: Si, a�n tengo las cartas... "
				"pero son algo... digamos que personal, no se si podr�a "
				"confiar en ti...\n");
			}
			else
			{
				return W("Rakon te dice: Si, a�n tengo las cartas... "
				"muchas gracias por recoger el jab�n, veo que eres una "
				"persona valiente, parece que se puede confiar en ti. Te "
				"dir� donde puedes encontrar las cartas... est�n en la "
				"casa abandonada de la calle Kadhu, la de la izquierda "
				"concretamente.\n");
			}
		}
		else return "Rakon te dice: �Las has encontrado ya?.\n";
	}
	else return "Rakon se encoge de hombros.\n";
}

create(){
  ::create();
  SetStandard("Rakon","humano",10,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(50);
  SetAggressive(0);
  SetName("Rakon");
  SetIds(({"humano","rakon","Rakon","preso"}));
  SetShort("Rakon el preso");
  SetLong(W("Rakon es un humano, un preso con el que compartes celda que no parece "
  	"tener muy buenas intenciones...\n"));
  AddQuestion(({"jab�n","jabon","pastilla","pastilla de jabon","pastilla de jab�n"}),W(
  	"Rakon se desmaya al empezar a preguntarle... poco a poco recupera el "
  	"conocimiento... pero no quiere decir nada... est� en estado de shock.\n"));
  AddQuestion(({"fuga","salir","carcel","fugarse","calabozo","salida"}),W("Rakon "
  	"te dice: Solo alguien valiente como el que m�s puede escapar de la c�rcel...\n"),1);
  AddQuestion(({"maestro"}),SF(fmaestro),1);
  AddQuestion(({"carta","cartas"}),SF(fcartas),1);
}

init(){
  ::init();
  if (environment(TO)->QueryJabon())
  {
  	SetLong(W("Este es Rakon, uno de los presos de aqu�. Est� muy "
  	"nervioso, de pie en una esquina y con la espalda completamente "
  	"pegada a la pared. No hace mas que mirar hacia todos lados y "
  	"hacia la pastilla de jab�n que hay en el centro de la celda.\n"));
  }
  else
  {
  	SetLong(W("Este es Rakon, uno de los presos de este calabozo. Est� "
  	"muy relajado, tumbado en el suelo sin preocuparse de los dem�s. "
  	"No se molesta ni en mirarte.\n"));
  }
}
