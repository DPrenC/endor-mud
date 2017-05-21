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
  SetShort("un folleto del Depart. de Mensajeria");
  SetLong("Este es un folleto del Departamento de Mensajeria de la Hermandad de Banqueros.\n"
"           Seguramente deberias leerlo.\n");
  Set(P_NOSELL);
  SetWeight(5);
}


init() {
  ::init();
    add_action("read_it", "leer");
}

read_it(str) {
   if (!id(str)) return 0;
   write("Departamento de Mensajeria de la Hermandad de Banqueros\n\
\n\
  Bienvenido a la Hermandad de Banqueros, antes que nada queremos agradecerle\n\
que confie en nosotros.\n\
\n\
  Con una experiencia de varias decadas, llevando los mas increibles mensajes\n\
a los lugares mas insolitos de nuestro mundo. Podemos decir con orgullo que\n\
el Departamento de Mesajeria de la Hermandad de Banqueros todavia no ha\n\
perdido un solo mensaje.\n\
\n\
  Para operar con su dinero en nuestras oficinas, simplemente hable con el\n\
encargado que le atienda en ese momento.\n\
  En nuestras oficinas usted podra mandar un 'correo a alguien',\n\
o podra 'leer correo' en las propias instalaciones.\n\
  Trabajando para nosotros se puede obtener un anillo proporcionado por\n\
la Hermandad de Banqueros que le permitira mandar y recibir el correo sin\n\
tener que desplazarse a nuestras oficinas. Se encuentre donde se encuentre\n\
uno de nuestros hombres le encontrara y recogera o le entregara sus mensajes.\n\
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


