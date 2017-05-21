#include <properties.h>
#include <money.h>
#include <properties.h>

inherit THING;
inherit MONEY_LIB;


#define JOIN_PRICE 10
#define CALC_FEE(x) (x*2/100)||1



create() {
  ::create();
  SetIds(({"folleto", "triptico"}));
  SetShort("un folleto de la Hermandad de Banqueros");
  SetLong("Este es un folleto de la Hermandad de Banqueros. Seguramente deberias\n\leerlo.\n");
  Set(P_NOSELL);
  SetWeight(5);
}


init() {
  ::init();
    add_action("read_it", "leer");
}

read_it(str) {
   if (!id(str)) return 0;
   write("Bienvenido a la Hermandad de Banqueros\n\
\n\
  Bienvenido a la Hermandad de Banqueros, antes que nada queremos agradecerle\n\
que confie en nosotros.\n\
\n\
  Con el coste de un poco de su dinero ("+
  		   call_other(MONEY_DEMON,
			      (TP||PO)->QueryBrief()?
			      "QueryValueShort":"QueryValueString",
			      JOIN_PRICE,QueryValuta()||({"copper"})) +")\n\
le aseguramos que su dinero estara a salvo de malechores, rufianes y ladrones\n\
que roban a honrados ciudadanos. Ademas, teniendo aqui su dinero, obtendra\n\
un trato preferencial en las diferentes ofertas que la Hermandad de Banqueros\n\
haga a sus clientes.\n\
\n\
  Para operar con su dinero en nuestras oficinas, simplemente hable con el\n\
encargado que le atienda en ese momento.\n\
  En nuestras oficinas usted podra 'abrir' una cuenta, 'ingresar' dinero,\n\
'sacar' dinero, consultar el 'balance' de su cuenta o 'cerrar' la cuenta.\n\
Si esta interesado en cambiar a otra moneda, al sacar el dinero de su cuenta\n\
debera indicar la moneda en la que desea recibir el dinero. Con 'lista de\n\
mejores clientes', podra ver los clientes mas ilustres del banco.\n\
\n\
                       Tabla de Equivalencias de Monedas\n\
               Moneda Base -> U.M.S (Unidad Monetaria de Simauria)\n\
-------------------------------------------------------------------------------\n\
                      1 Moneda de Cobre  -> 1 U.M.S.\n\
\n\
\n\
\n");
   return 1;
}


