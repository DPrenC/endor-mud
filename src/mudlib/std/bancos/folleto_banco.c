/*
DESCRIPCION  : Folleto explicativo del banco
FICHERO      : /d/limbo/comun/objeto/otro/folleto_banco.c
MODIFICACION : ??-??-?? [Mirill???]      Creacion
               02-10-98 [Angor@Simauria] Varias modificaciones
	 04-02-99 [Theuzifan] Castellanizado
--------------------------------------------------------------------------------
*/

#include <properties.h>
#include <money.h>
#include <properties.h>

#define MONEY_VAL(x)  MONEY_DEMON->QueryCoinValue(x)

inherit "/std/thing";
inherit MONEY_LIB;


#define JOIN_PRICE 5
#define CALC_FEE(x) (x*2/100)||1



string leer_folleto(){
    return "La Hermandad de Banqueros le agradece que confíe en nuestros servicios.\n\n"
           "Por la módica cantidad de ("+
           call_other(MONEY_DEMON,
           (TP||PO)->QueryBrief()?
           "QueryValueShort":"QueryValueString",
           JOIN_PRICE,QueryValuta()||({"cobre"})) +") "
           "le aseguramos que su dinero estará a salvo de malechores, rufianes "
           "y ladrones que roban a honrados ciudadanos. Además, obtendrá un "
           "trato preferencial en las diferentes ofertas que la Hermandad de Banqueros "
           "haga a sus clientes. Si tiene alguna duda, pregúntele a nuestros "
           "empleados.\n\n"
           "En nuestras oficinas usted podrá 'abrir' una cuenta, 'ingresar' y "
           "'sacar' dinero, consultar el 'balance'  o 'cerrar' la cuenta. "
           "Para cambiar de una moneda a otra deberá indicar la moneda en la "
           "que desea recibir el dinero al sacarlo de la cuenta. Con 'lista de "
           "mejores clientes', podrá ver los clientes mas ilustres del banco.\n\n"
           "Tabla de Equivalencias de Monedas  (U.M.S = Unidad Monetaria de "
           "Simauria)\n"
           "  1 Moneda de Cobre   =   " + MONEY_VAL("cobre") + " U.M.S.\n"
           "  1 Moneda de Plata   =   " + MONEY_VAL("plata") + " U.M.S.\n"
           "  1 Moneda de Oro     =   " + MONEY_VAL("oro") + " U.M.S.\n"
           "  1 Moneda de Platino =   " + MONEY_VAL("platino") + " U.M.S.\n"
           "  1 Moneda de Mithril =   " + MONEY_VAL("mithril") + " U.M.S.\n";
}


create() {
  ::create();
  SetIds(({"folleto","triptico", "tríptico"}));
  SetShort("un folleto de la Hermandad de Banqueros");
  SetLong(
     "Este es un folleto de la Hermandad de Banqueros que explica el funcionamiento de\n"
     "los bancos. Seguramente deberías leerlo.\n");
  Set(P_NOSELL);
  SetWeight(5);
  SetValue(0);
  SetReadMsg(SF(leer_folleto));
}

