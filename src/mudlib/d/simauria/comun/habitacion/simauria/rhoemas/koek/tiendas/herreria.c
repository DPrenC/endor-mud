/***************************************************************************************
 ARCHIVO:	herreria.c
 AUTOR:		[z] Zomax
 FECHA:		15-12-2001
 COMENTARIOS:	Herrería, planta baja.
 ***************************************************************************************/

#include <money.h>
#include <wizlevels.h>
#include "path.h"

inherit "/room/herreria";
#include RHOEPRESO

int abierto,h1,h2,i;
mixed ficheros;

void fcosas(string tienda)
{
	ficheros=get_dir(RHOEVAR("koek/comercio/"+tienda+"/*.c"));
 	for (i=sizeof(ficheros);i--;)
 	{
 		AddArticle(RHOEVAR("koek/comercio/"+tienda+"/"+ficheros[i]),REFRESH_REMOVE,5);
 	}
}

int fhorario(int h1 , int h2)
{
 	if ((CHRONOS->QueryHour()>=h1) && (CHRONOS->QueryHour()<h2))
 	{
 		abierto=1;
 	}
 	else
 	{
 		abierto=0;
 	}
 	return 1;
}

create () {
 ::create();

  SetLocate("Koek");
  SetIntShort("la herrería");
  SetIntSmell("Huele a cosas quemadas.\n");
  SetIntNoise("No oyes nada especial, salvo lo normal en una herrería a estas horas.\n");
  SetIntLong(W("Estás en la herrería del pueblo. Es una pequeña casa llena de "
  	"trastos extraños en las paredes y con un gran yunque y un horno donde "
  	"el herrero trabaja el metal hasta convertirlo en maravillosas piezas. "
  	"El ambiente es un poco cargante, debido al calor del horno.\n"));
  AddDetail(({"pieza","piezas","arma","armas","escudo","escudos"}),W("Aparte de las que hay a la venta, "
  	"hay numerosas armas y escudos colgadas en las paredes que dan un toque "
  	"decorativo a la herrería.\n"));
  AddDetail(({"yunque","martillo"}),W("Un gran yunque de hierro, con un martillo "
  	"a su lado, se alza en una de las esquinas de la herrería, muy cerca del "
  	"horno donde templan el metal.\n"));
  AddDetail(({"horno"}),W("Hay un gran horno justo en la pared central de la habitación. "
  	"Aquí suelen dejar el metal para que se funda y puedan trabajarlo.\n"));
  AddDetail(({"suelo"}),W("Hay ceniza y restos de metal por el suelo, pero no está "
  	"tan sucio como otros.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes están llenas de armas y escudos "
  	"colgados, sin duda piezas que han sido modeladas aquí.\n"));
  AddDetail(({"techo"}),"Un techo la mar de normal, quizás algo quemado por el humo.\n");
  AddDetail(({"cartel","horario"}),W("Hay un pequeño cartel colgado en el "
  	"que pone el horario de apertura normal y unas aclaraciones. Deberías leerlo.\n"));
  AddReadMsg(({"horario","cartel"}),("\n"
  "       *-------------------------------------------------------*\n"
  "       |                                                       |\n"
  "       |            [36mTabla de Horarios de la Herrería[0m           |\n"
  "       |                                                       |\n"
  "       |    Nos complace atenderle todos los días desde las    |\n"
  "       |    [52m10[0m horas hasta las [52m24[0m horas, siempre hora local.   |\n"
  "       |    No obstante el servicio de reparación permanecerá  |\n"
  "       |    a su disposición ininterrumpidamente cargando una  |\n"
  "       |    cantidad adicional a su cuenta por las molestias.  |\n"
  "       |                                                       |\n"
  "       |                                             [50mKolen[0m     |\n"
  "       *-------------------------------------------------------*\n"));
  AddExit("este",RHOEHAB("koek/calles/cendaf_01"));
  SetLastDest(RHOEHAB("koek/calles/cendaf_01"));
  SetNotifyExits("este");
  SetShopkeeper(RHOEPNJ("koek/tiendas/kolen"));
  SetSmithy(1);
  h1=10;
  h2=24;
  fcosas("herreria");
  carcel=(RHOEHAB("koek/calles/cendaf_01"));
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("arreglar","do_fix");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
  AddRoomCmd("almacen","falmacen");
}

init(){
  ::init();
  fhorario(h1,h2);
  if (abierto)
  {
  	SetRepairFactor(150);
    	SetResizeFactor(33);
  }
  else
  {
  	SetRepairFactor(500);
    	SetResizeFactor(100);
  }
}

varargs int GetRepairPrice(object ob,int force)
{
	if (ob->QueryShort()=="la espada de Zendak muy oxidada")
	{
		mixed price;
		price=750000;
		return price;
	}
	else return ::GetRepairPrice(ob,force);
}

int do_fix(string str)
{
	object cosa,kolen;
	if (str) {cosa=present(str,TP);}
	if (cosa)
	{
		if(cosa->QueryShort()!="la espada de Zendak muy oxidada")
		return ::do_fix(str);
	}
	kolen=present("Kolen",TO);
	if (kolen && cosa)
	{
		if (living(kolen))
		{
			if (cosa->QueryEquipped()==TP)
			{
				write("Primero deberías desempuñarla.\n");
				return 1;
			}
			else
			{
				object espada;
				mixed pay_result;
				int price,force;
				price=GetRepairPrice(cosa,force);
    				pay_result=PayValue2(TP,price,QueryValuta());
    				if (!pointerp(pay_result))
    				{
        				write(W("Este es un duro trabajo. Te costará "+MONEY_DEMON->QueryMoneyString(
					MONEY_DEMON->CreateMoney(price,QueryValuta()))+" reparar "+cosa->Short()+".\n"));
					return 1;
    				}
    				else
    				{
				write(W("Le das la espada de Zendak vieja y oxidada a "
				"Kolen. De repente un brillo extraño aparece en su mirada, "
				"como si hubiera estado toda la vida esperando arreglar una "
				"pieza como esta. Está tan entusiasmado por haber podido "
				"contemplar tan magnífica espada que se le saltan las lágrimas. "
				"Tras un duro trabajo te deja la espada como nueva... parece "
				"un milagro.\n"));
				say(W("El herrero se queda maravillado ante la espada que "
				"le trae "+CATP+" y la arregla con esmero.\n"),TP);
				write(W("Pagas "+pay_result[0]+(pay_result[1]?" y te devuelve "+pay_result[1]:"")+".\n"));
    				say(W(CATP+" paga "+pay_result[0]+(pay_result[1]?" y le devuelven "+pay_result[1]:"")+".\n"),TP);
				cosa->remove();
				espada=clone_object(RHOEWEA("koek/varios/espada_zendak_arreglada"));
				espada->move(TP,M_NOCHECK);
				return 1;
				}
			}
		}
	}
}

int falmacen(string str)
{
	if(!IS_LEARNER(TP))
	{
		write("El almacen está cerrado, no puedes pasar.\n");
		return 1;
	}

}
