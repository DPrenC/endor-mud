/***************************************************************************************
 ARCHIVO:	folletoc.c
 AUTOR:		[v] Varios
 FECHA:		03-12-2001
 COMENTARIOS:	Folleto para Correos de Koek
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
  SetShort("un folleto de correos");
  SetLong(W("Es un folleto que explica el funcionamiento de la oficina de correos de "
  	"Koek. Deberias leerlo.\n"));
  Set(P_NOSELL);
  SetWeight(5);
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
   		"|        [36mCorreos de Koek, integrado en La Hermandad de Mensajeros,[0m       |\n"
   		"|             [36mle agradece que confie en nuestros servicios.[0m              |\n"
   		"|                                                                        |\n"
   		"|  Con una experiencia de varias decadas, llevando los mas increibles    |\n"
   		"|  mensajes a los lugares mas insolitos de nuestro mundo. Podemos decir  |\n"
   		"|  con orgullo que jamás hemos extraviado un solo mensaje. Si tiene      |\n"
   		"|  alguna duda acerca del servicio, pregunte a nuestros empleados.       |\n"
      		"|                                                                        |\n"
      		"|  En nuestras oficinas usted podrá mandar un [52mcorreo a alguien[0m, o podrá  |\n"
		"|  [52mleer correo[0m en las propias instalaciones.                             |\n"
      		"|                                                                        |\n"
      		"*------------------------------------------------------------------------*\n");
   		return 1;
   	}
}
