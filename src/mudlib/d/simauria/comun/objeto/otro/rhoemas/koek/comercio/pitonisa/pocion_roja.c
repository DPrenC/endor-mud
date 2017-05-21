/***************************************************************************************
 ARCHIVO:	pocion_roja.c
 AUTOR:		[z] Zomax
 FECHA:		07-01-2002
 COMENTARIOS:	Una poci�n roja
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit THING;

create () {
 ::create();

  SetShort("una poci�n roja");
  SetLong(W("Es un peque�o frasco con un l�quido rojo muy intenso. Parece alg�n "
  	"tipo de poci�n m�gica o elixir de amor.\n"));
  SetIds(({"pocion","poci�n","pocion roja","poci�n roja","elixir"}));
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(10);
  SetValue(250);
}

init(){
  ::init();
  add_action("fbeber","beber");
}

int fbeber(string str)
{
	if (str && TO->id(str))
	{
		int i;
		object *pjs;
		write("Te bebes la poci�n roja sin dejar ni una gota.\n");
		say(W(CATP+" se bebe una poci�n roja sin dejar ni una gota.\n"),TP);
		pjs=all_inventory(environment(TP));
		TP->SetFollowers();
		for (i=0;i<sizeof(pjs);i++)
		{
			if (living(pjs[i]))
			{
				if (pjs[i]==TP)
				{
					write(W("Cada dia te gustas m�s. Pero mira que est�s buen"+AO+".\n"));
				}
				else if (pjs[i]->QueryGender()!=TP->QueryGender())
				{
					tell_object(pjs[i],W("Sientes una salvaje atracci�n "
						"por "+CATP+".\n"));
					tell_object(TP,W("Notas como "+capitalize(pjs[i]->QueryRealName())+" te mira con ojos lujuriosos.\n"));
				}
				else
				{
					tell_object(pjs[i],W("Empiezas a notar una cierta "
						"atracci�n por "+CATP+".\n"));
					tell_object(TP,W("Est�s empezando a asustarte, "+capitalize(pjs[i]->QueryRealName())+" te mira con ojos un tanto 'especiales'.\n"));
				}
				if (pjs[i]->QueryIsPlayer() && (pjs[i]->QueryGender()!=TP->QueryGender()))
				{
					TP->AddFollower(pjs[i], FOLLOW_NORMAL);
					tell_object(pjs[i],W("Sientes la irremediable tentaci�n de perseguir a "+CATP+".\n"));
				}
			}
		}
		if (TP->QueryFollowers())
		{
			tell_object(TP,W("Te sientes acosad"+AO+".\n"));
		}
		TO->remove();
		return 1;
	}
    return 0;
}
