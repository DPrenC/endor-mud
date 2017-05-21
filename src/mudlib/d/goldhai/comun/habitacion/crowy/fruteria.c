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
 SetIntShort("un puesto de frutas");
 SetIntLong(
"Estás justo en frente de un carro lleno de toda clase de jugosas frutas. La\n\
gente llega con sus cestas y compran mientras tu contemplas un pajaro azul\n\
que reposa en lo alto de un arbol. Si algún dia te decides a 'comprar' algo\n\
primero deberias pedir la 'lista' y saber que hay a la venta.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntBright(40);
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail(({"frutas","fruta"}),
"Todas las frutas parece recien cogidas y muy apetitosas.\n");
 AddDetail(({"carro","carreta"}),
"Se trata de un viejo carro pero que sirve muy bien para exponer las frutas.\n");
 AddDetail(({"arbol"}),
"Ves un arbol no demasiado alto con pajaros en sus copas, aunque te llama la\n\
atención uno en especial de color azul.\n");
 AddDetail(({"pajaro","pajaro azul"}),
"Tiene un plumaje precioso de color azul y un pico de color blanco. Sin duda\n\
no es de estas tierras, seguramente habrá venido con algun extranjero al que\n\
se le escapó.\n");
 AddDetail("tendera",
"La tendera es una mujer de mediana edad que te mira.\n");
 AddTendero("la tendera");
 // Precio a 1 para que lo tome directamente del valor del producto*2.
 AddProducto("una manzana",1,COMIDA("manzana"));
 AddProducto("una pera",1,COMIDA("pera"));
 AddProducto("una naranja",1,COMIDA("naranja"));
 AddProducto("un limon",1,COMIDA("limon"));
 AddProducto("un platano",1,COMIDA("platano"));
 AddProducto("un racimo de uvas",1,COMIDA("uvas"));
 AddExit("oeste",CROWY("zona_comercial3"));

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(2)+1);

 SetLocate("Crowy");
}

void init()
{
 ::init();
}