/***************************************************************************************
 ARCHIVO:	folletob.c
 AUTOR:		[v] Varios
 FECHA:		03-12-2001
 COMENTARIOS:	Folleto para el Banco de Koek
 		Adaptacion para Rhoemas por [z] Zomax
 ***************************************************************************************/

#include <money.h>
#include "path.h"
#include <properties.h>

inherit THING;
inherit MONEY_LIB;

#define JOIN_PRICE 10
#define CALC_FEE(x) (x*2/100)||1


create() {
  ::create();
  SetIds(({"folleto"}));
  SetShort("un folleto del banco");
  SetLong(W("Es un folleto que el banco pone a disposición de los clientes para su "
  	"mejor información. Parece que este banco depende de la Hermandad de Banqueros. "
  	"Seguramente deberías leerlo.\n"));
  Set(P_NOSELL);
  SetWeight(5);
  SetValue(0);
}

init() {
  ::init();
    add_action("fleer", "leer");
}

fleer(str)
{
	if (TO==present(str))
   	{
   		write(
   		"*------------------------------------------------------------------------*\n"
   		"|                                                                        |\n"
   		"|        [36mEl Banco de Koek, integrado en La Hermandad de Banqueros,[0m       |\n"
   		"|             [36mle agradece que confíe en nuestros servicios.[0m              |\n"
   		"|                                                                        |\n"
   		"|   Por la módica cantidad de "+call_other(MONEY_DEMON,(TP||PO)->QueryBrief()?
        	 "QueryValueShort":"QueryValueString",JOIN_PRICE,QueryValuta()||({"cobre"}))+" le aseguramos que su    |\n"
      		"|   dinero estará a salvo de malechores, rufianes y ladrones que roban   |\n"
      		"|   a honrados ciudadanos. Además, obtendra un trato preferencial en     |\n"
      		"|   las diferentes ofertas que la Hermandad de Banqueros haga a sus      |\n"
      		"|   clientes. Si tiene alguna duda, pregúntele a nuestros empleados.     |\n"
      		"|                                                                        |\n"
      		"|   En nuestras oficinas usted podrá [52mabrir[0m una cuenta, [52mingresar[0m y [52msacar[0m  |\n"
      		"|   dinero, consultar el [52mbalance[0m  o [52mcerrar[0m la cuenta. Para cambiar de    |\n"
      		"|   una moneda a otra deberá indicar la moneda en la que desea recibir   |\n"
      		"|   el dinero al sacarlo de la cuenta. Con [52mlista de mejores clientes[0m,    |\n"
      		"|   podrá ver los clientes mas ilustres del banco.                       |\n"
      		"|                                                                        |\n"
      		"|     [37mTabla de Equivalencias (U.M.S = Unidad Monetaria de Simauria)[0m      |\n"
      		"|                                                                        |\n"
      		"|                1 Moneda de Cobre   =      1 U.M.S.                     |\n"
      		"|                1 Moneda de Plata   =     10 U.M.S.                     |\n"
      		"|                1 Moneda de Oro     =    100 U.M.S.                     |\n"
      		"|                1 Moneda de Platino =   1000 U.M.S.                     |\n"
      		"|                1 Moneda de Mithril =   5000 U.M.S.                     |\n"
      		"|                                                                        |\n"
      		"*------------------------------------------------------------------------*\n");
   		return 1;
   	}
}
