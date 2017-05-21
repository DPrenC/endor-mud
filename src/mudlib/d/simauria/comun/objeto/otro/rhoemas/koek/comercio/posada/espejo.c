/***************************************************************************************
 ARCHIVO:	espejo.c
 AUTOR:		[z] Zomax
 FECHA:		29-11-2001
 COMENTARIOS:	Un espejo
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit WEAPON;

create () {
 ::create();

 SetShort("un espejo");
 SetLong(W("Es un bonito espejo de mano típico de la región de Koek. Tiene un "
 "pequeño marco de madera a su alrededor para protegerlo de los golpes con "
 "unos bonitos detalles pintados.\n"));
 AddSubDetail(({"marco"}),W("El espejo tiene un marco de madera para poder cogerlo "
 	"y como protección.\n"));
 SetIds(({"espejo"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetDieMsg("#jug# ha muerto con la cara llena de cristales clavados debido a una gran estupidez.");
 SetWeight(500);
 SetValue(1500);
 SetNumberHands(1);
 SetWC(0);
 SetWeaponType();
 SetMaterial(M_CRISTAL);
}

init(){
  ::init();
  add_action("fdar","dar");
}

int fdar(string str)
{
	string cosadada,pnjrecibe;
	object borracha,cristal;
        if (!str || (sscanf(str,"%s a %s", cosadada, pnjrecibe) != 2))
        {
        	write("¿Dar <qué> a <quién>?\n");
        	return 1;
        }
	else if (cosadada=="espejo")
	{
		borracha=present(pnjrecibe,environment(TP));
		if (borracha)
		{
			if (borracha->QueryName()=="Syrnam")
			{
				if (living(borracha))
				{
					{
						write(W("Le das el espejo a Syrnam, que "
						"lo coje con mucha curiosidad. Se empieza "
						"a mirar y BOOOOMM... unos cuantos cristales "
						"se te clavan en la cara al estallar el "
						"espejo. No debe haber soportado reflejar algo "
						"tan espantoso.\n"));
						say(W(CATP+" tiene ha estúpida idea de dejarle "
						"el espejo a Syrnam. Éste estalla en mil pedazos "
						"y le saltan algunos cristales a la cara.\n"),TP);
						if (TP->QueryHP()<=25)
						{
							cristal=clone_object(RHOEVAR("koek/varios/cristales"));
							cristal->move(TP,M_SILENT);
						}
						else
						{
							TP->AddHP(-25);
						}
						write(W("El espejo desaparece en miles de cristalitos "
						"en tu cara.\n"));
						TO->remove();
						return 1;
					}
				}
				else
				{
					write("¿Para qué quieres darle un espejo a una muerta?\n");
					return 1;
				}
			}
		}
	}
}
