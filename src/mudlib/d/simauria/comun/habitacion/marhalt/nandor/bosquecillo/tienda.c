 /*============================================================*
  |                      << NYNE.KRIGOR >>                      |
  *=============================================================*
  |               Creacion: Chaos       05-10-01                |
  |               Nombre archivo: tienda.c                      |
  |               tienda del pueblo de Krigor,                  |
  |               adaptada de la tienda de Nandor               |
  |                      de Nemesis.                            |
  *=============================================================*/

#include "path.h"
inherit SHOP;

object art1, art2, art3, art4;


int matar_(string str);

create()
{
	 ::create();
	 SetIntShort("una tienda");
	 SetIntLong("TIENDA.\n");
	 SetIndoors(1);
	 SetIntBright(45);
	 SetIntSmell(W("Huele un poco raro, pero puedes distinguir claramente un fuerte olor a "+
	 "resinas o algo asi.\n"));
	 CanBuy(0);
	 SetDustbin(0);
	AddExit("norte","plaza");


	AddArticle("/d/simauria/comun/objeto/otro/cuerda", REFRESH_REMOVE,3);
	AddArticle("/obj/torch", REFRESH_REMOVE,6);
	AddArticle(art1, REFRESH_REMOVE, 2);
	AddArticle(art2, REFRESH_REMOVE,1);
	AddArticle(art3, REFRESH_REMOVE, 2);
	AddArticle(art4, REFRESH_REMOVE, 2);
	AddArticle(PROT("amuleto"), REFRESH_REMOVE, 4);
	AddArticle(ARMA("vara"));
	AddArticle(ARMA("arma_rnd"),REFRESH_REMOVE,2);
	AddArticle(PROT("anillo"));
	AddArticle(PROT("guantes"), REFRESH_REMOVE, 2);
	AddArticle("/obj/vialv", REFRESH_REMOVE, 4);
	AddArticle("/obj/vialm", REFRESH_REMOVE, 4);
	AddArticle("/obj/vial", REFRESH_REMOVE, 2);
}