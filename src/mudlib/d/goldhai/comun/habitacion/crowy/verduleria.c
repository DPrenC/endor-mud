/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 27-11-97                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit PUESTO;

create()
{
 ::create();
 SetIntShort("un puesto de verduras");
 SetIntLong(
"Cuatro palos con un trozo de piel encima protegen los productos del mal\n\
tiempo. Las verduras se dividen en cestas y tú puedes coger lo que quieras\n\
siempre y cuando pagues al propietario del puesto. Puedes pedir la 'lista'\n\
y así poder saber que verduras están a la venta, si deseas alguna solo tienes\n\
que comprarlas.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntBright(40);
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Las verduras no tienen ningun olor en especial.\n");
 AddDetail(({"productos","verdura","verduras","cestas","canastas","cesta"}),
"Todas las verduras tienen una pinta muy buena.\n");
 AddDetail("tendero",
"Es un tendero normal y corriente dispuesto a atenderte.\n");
 AddExit("sur",CROWY("zona_comercial2"));
 AddTendero("el tendero");
 // Precio puesto a 1 para que lo tome del valor del producto*2.
 AddProducto("una col",1,COMIDA("col"));
 AddProducto("unas espinacas",1,COMIDA("espinacas"));
 AddProducto("un cardo",1,COMIDA("cardo"));
 AddProducto("una patata",1,COMIDA("patata"));
 AddProducto("una zanahoria",1,COMIDA("zanahoria"));
 AddProducto("una lechuga",1,COMIDA("lechuga"));
 SetLocate("Crowy");
}
