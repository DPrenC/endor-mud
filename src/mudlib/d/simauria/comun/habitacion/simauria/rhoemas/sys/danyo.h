/***************************************************************************************
 ARCHIVO:	preso.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Funciones que chequean si hay guardias cuando hieres a alguien.
 MODIFICACION:  24-04-2003 Repaso de código.
 13/01/2005: [kastwey@simauria]: Arreglo las llamadas al DoDamage
 a ver si dejan de petar los pnj al matarlos.
 ***************************************************************************************/

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras)
{
	if (environment(TO))
	{
		if ((living(present("carcelero",environment(TO)))) || (living(present("patrullero",environment(TO)))) || (living(present("guardia",environment(TO)))))
		{
			TP->StopAttack();
			TO->StopAttack();
			if (environment(TO)->fcarcel()) return ::DoDamage (damage, type, gentle, &xtras);
			else
			{
				int i;
				object *guardias;
				
				guardias=(deep_inventory(environment(TO)));
				if(sizeof(guardias))
				{
					for (i=0;i<sizeof(guardias);i++)
					{
						if (guardias[i]->QueryShort()=="un patrullero" || guardias[i]->QueryShort()=="un guardia" || guardias[i]->QueryShort()=="el carcelero")
						{
							guardias[i]->Kill(TP);
						}
					}
				}
				TP->Kill(TO);
				TO->Kill(TP);
			}
		}
		if(TO->QueryRealName()=="adwel" && living(present("geagan",environment(TO))))
		{
			present("geagan",environment(TO))->Kill(TP);
			return ::DoDamage (damage, type, gentle, &xtras);
		}
		if(TO->QueryRealName()=="geagan" && living(present("adwel",environment(TO))))
		{
			present("adwel",environment(TO))->Kill(TP);
			return ::DoDamage (damage, type, gentle, &xtras);
		}
	}
	return ::DoDamage (damage, type, gentle, &xtras);
}
