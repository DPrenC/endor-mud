/***************************************************************************************
 ARCHIVO:	shop.c
 AUTOR:		[z] Zomax
 FECHA:		31-10-2001
 COMENTARIOS:	Tienda Standard de Koek... cierra y se queda sin tendero cuando toca...
 		o al menos es lo que se pretende. Gracias a Artic por recordarme que
 		cuando clono a un pnj en el init se vuelve a llamar al init... que me
 		traía de cabeza.
 MODIFICACION:  24-04-2003 Repaso el codigo un poquito quitando cosas que sobran.
 ***************************************************************************************/

#include <wizlevels.h>
#include "path.h"

inherit SHOP;
#include RHOEPRESO

int abierto,tendero,bucle,h1,h2,i;
string pnj;
mixed ficheros;

void fcosas(string tienda)
{
	ficheros=get_dir(RHOEVAR("koek/comercio/"+tienda+"/*.c"));
 	for (i=sizeof(ficheros);i--;)
 		AddArticle(RHOEVAR("koek/comercio/"+tienda+"/"+ficheros[i]),REFRESH_REMOVE,5);
}

int fhorario(int h1 , int h2)
{
 	if ((CHRONOS->QueryHour()>=h1) && (CHRONOS->QueryHour()<h2))
 		abierto=1;
 	else
 		abierto=0;
 	return 1;
}

void fponer_tendero()
{
	bucle=1;
	SetShopkeeper(RHOEPNJ(pnj));
	tendero=1;
}

void fquitar_tendero()
{
	bucle=0;
	RemoveShopkeeper();
	tendero=0;
}

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(40);
  SetDynamic(100);
  SetMinCash(50000);
  RemoveDustbin();
  RemoveShopkeeper();
  abierto=0;
  bucle=0;
  tendero=0;
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
  AddRoomCmd("almacen","falmacen");
  HideExit("almacen",1);
}

init() {
  if (!bucle)
  {
 	::init();
 	fhorario(h1,h2);
 	if (abierto && tendero==0)
 		fponer_tendero();
 	if (!abierto)
 		fquitar_tendero();
  }
  else
  {
 	::init();
 	bucle=0;
  }
}

public int QueryEntrarPatrullero() { return 1;}

public int falmacen(string str)
{
	if(!IS_LEARNER(TP))
	{
		write("El almacen está cerrado, no puedes pasar.\n");
		return 1;
	}

}
