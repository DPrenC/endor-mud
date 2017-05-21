/* SIMAURIA.Kha-annu '/d/Kha-annu/ejemplos/habitacion.c'
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
 \\                  << KHA-ANNU [w] Woo@simauria >>              \\
  \\                 << KHA-ANNU [i] Izet@simauria >>              \\
   \\               << KHA-ANNU [o] Okkita@Simauria >>              \\
    \\                FICHERO DE EJEMPLO: HABITACION                 \\
     \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
     ///////////////////////////////////////////////////////////////////
    //  Creacion............. 07-05-97                               //
   //   Ultima Modificacion.. 23-05-97                              //
  //    23/05/97 [o] Anyadidos todos los comentarios, no me        //
 //                  hago responsable de las faltas d'ortografia  //
///////////////////////////////////////////////////////////////////
*/

#include "./path.h"  // [o] Esto se pone siempre, contiene casi todas
                     //     las funciones que "suelen" hacer falta.
                     //     Para un listado completo de lo que incluye,
                     //     ver '/d/Kha-annu/docs/Harbol.txt'

inherit ROOM;        // [o] Aqui se pone el TIPO de habitacion:
                     //     ROOM, SHOP, etc...

int abierto;                 // [o] Esto es para la funcion de mas abajo...
                             //     Como si no estuviera, vamos....
// CREATE:
// ======================================================================
create() {           // [o] Donde se definen todas las caracteristicas
                     //     de la habitacion, es decir, se "crea" :)

 ::create();
        // [o] Esto se pone SIEMPRE.

 SetIntShort("Aqui va la descripcion corta de la habitacion");
                     // [o] La descripcion corta es la que se ve cuando
                     //     esta activado el modo "breve".
                     //     Basicamente es una descripcion resumida de la
                     //     habitacion. Una "primera impresion".
                     //\n = retorno de carro
 SetIntLong(
"Aqui va la descripcion detallada de la habitacion.\n"
"[o] Es importante que cada nombre que se incluya en la\n"
"descripcion de la habitacion tenga su correspondiente\n"
"AddDetail(). La descripcion 'larga' NO tiene porque ser\n"
"muy larga y detallada, basta con que quede claro el contenido\n"
"de la misma, si se queren detallar algunas cosas, hacerlo con\n"
"AddDetail(), (detallar != remarcar :) )\n");
                    // [o] La descripcion larga es la que se ve al hacer
                    //     un "mirar" en la habitacion o al entrar en ella.

 SetIndoors(0);     // [o] Especifica si la habitacion es exterior o
                    //     interior..., no es nada realista un bareto
                    //     en el que, por ejemplo, llueva. :)
                    //     SetIndoors(0) --> exterior
                    //     SetIndoors(1) --> interior

 SetIntBright(40);   // [o] Define la luminosidad de la habitacion; la
                    //     luz ambiental. Consultar los docs para ver
                    //     los valores apropiados a cada lugar.

 SetIntNoise("Aqui se pone lo que se puede oir en la habitacion.\n");
 SetIntSmell("Aqui se pone lo que se puede oler en la habitacion.\n");
                    // [o] Estas han de ser bastante cortas, se
                    //     refieren a percepciones generales, de
                    //     la habitacion en si misma, raramente de
                    //     algun objeto en ella.

 AddDetail(({"arbol","roble"}),
 "Es un gran roble.\nEsta partido en dos por un rayo.\n");
                    // [o] Descripcion de los detalles de la habitacion
                    //     Estructura:
                    //     AddDetail(({"",""}), " ");
                    //                   |       |
                    //     vector de nombres   descripcion

 AddExit("Izet",("/players/izet/workroom"));
 AddExit("Okkita",("/players/okkita/workroom"));
                    // [o] Define las posibles salidas de la habitacion.

 HideExit("Okkita",1);
                    // [o] Oculta la salida entre comillas.

 AddRoomCmd("llamar","llama_puerta");
                    // [o] Esta una de las formas de llamar a funciones
                    //     especiales en una habitacion; por ejemplo,
                    //     anyadir comandos.

AddReadMsg(({"cartel","pancarta"}),
"Lees el cartel:\n" // [o] Esto define un cartel, nota o cualquier
" HOOOOOOOOLA\n");  //     objeto que pueda leerse.

 SetLocate("Kha-annu");
                    // [o] Los locates definen zonas, grupos de habitaciones,
                    //     son importantes por ejemplo, a la hora de limitar
                    //     los movimientos de un npc.
}

// INIT:
// ========================================================================

void init() {       // [o] En init van todas las funciones que han de ini-
                    //     cializarse cuando se carga la habitacion, es
                    //     decir, cuando alguien entra en ella.

   ::init();        // [o] Poner esto SIEMPRE.

    add_action("llama_puerta","llamar");
                    // [o] Por ejemplo :).
}

int llama_puerta(string str) /* [i] Esto es un ejemplillo de funcion */
{
abierto=0;

  if ((str !="puerta") && (str !="puertas") && (str !="a puerta") &&
      (str != "a puertas") && (str != "a la puerta") &&
      (str != "a las puertas") && (str !="en puerta") && (str !="en puertas")
      && (str !="en la puerta") && (str !="en las puertas")) {
    write("Llamar en donde?\n");
    return 1;
  }
  else {
    if (abierto == 1) {
      write("Las puertas estan abiertas, no hace falta llamar de nuevo.\n");
      return 0;
    }
    if (abierto == 0) {
      write("Llamas a las puertas.\n");
      write("Toc, Toc, Toc!\n");
      say(TP->QueryShort()+" llama a las puertas.\n");
      say("Toc, Toc, Toc!\n");
      call_out("abre_puerta", 5); // [i] Aki llamaria a otra funcion
      return 1;                   //     que abriria las puertas...
    }                             //     Pero como esto solo es un
  }                               //     ejemplo.... :)
}

/* Estas son las funciones basicas para crear una habitacion...

Algunas son opcionales, y hay muchas mas, ya mas complejas, (ver docs)
que aqui no se tratan.
Lo mas importante: Nunca olvidar los ; despues de las funciones,
nunca olvidar ::create(); y el ::init();, no dejar ningun sustantivo de
las descripciones sin su correspondiente AddDetail (incluidos los de las
descripciones de los AddDetail :)), imaginar mucho y, sobre todo, diver-
tirse codeando, que para eso es todo el tinglao este.

Este documento ha sido redactado por [o] Okkita@Simauria,
tomando como base un archivo de [w] Woo@Simauria
y una funcion de ejemplo de [i] Izet@Simauria.
*/

