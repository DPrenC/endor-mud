/* Kha-annu.SIMAURIA '/d/kha-annu/comun/quests/malabar.c'
/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
\   [o] Okkita                                                       /
/                                                                    \
\   Bolas de malabares, para el quest de hacer reir al Rey...        /
/                                                                    \
\   29/05/97  [o]  Creacion del esqueleto basico del objeto.         /
/   02/06/97  [o]  Parches y anyadido juego con multiples bolas.     \
\                                                                    /
/                  Con una pequenya ayuda de Thragor@Nightfall.      \
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
*/

#include "./path.h"

inherit "/std/unit";     // [o] Para hacerlo elegantemente. :)
inherit THING;             // [o] Solo por si acaso.

/* Declaracion variables globales                    [o] Okkita
**********************************************************************/
int njbolas;               // [o] Numero de bolas en juego
int nbolas;                // [o] Numero de bolas a evaluar

/* Create, propiedades y definiciones                [o] Okkita
**********************************************************************/
create () {
   ::create();
   SetShort("bola de malabares");
   SetPluralShort("bolas de malabares");
   SetIds(({"bola"}));
   SetPluralIds(({"bolas"}));
   SetAds(({"una","malabar","malabares","unas","de"}));
   SetLong(
"Una bola para hacer juegos malabares. Es pequenya, ligera y suave al\n"
"tacto. Con mas como esta podrias hacer fantasticos trucos.\n");
   SetPluralLong(
"Un juego de bolas de malabares. Son pequenyas, ligeras y suaves al\n"
"tacto. Con ellas podrias hacer fantasticos trucos y figuras.\n");
   SetValuePerUnit(5);
   SetWeightPerUnit(125);
   SetAmount(1);
}
/* Init, llamadas a funciones                          [o] Okkita
*********************************************************************/

void init() {
   ::init();
   add_action("fjugar","jugar");
   add_action("fpracticar","practicar");
   add_action("fparar","parar");
}

/* Funciones                                           [o] Okkita
*********************************************************************/
int QueryBola() {   // [o] Para usar mas adelante.
   return 1;
   }


fjugar(str) {       // [o] Controla el comienzo del juego.

nbolas=TO->QueryAmount();
   if (njbolas!=0)
   {
      if (njbolas==1)
      {
      notify_fail("Ya juegas con una bola.\n");
      return 0;
      }
      if (njbolas!=1)
      {
      notify_fail("Ya estas jugando con "+njbolas+".\n");
      return 0;
      }
   }
   if ((!str) || (str=="con") || (str=="bola") || (str=="bolas")
              || (nbolas <= 0)) {

                    // [o] Suprime los casos especiales: Id, etc.
      notify_fail("Jugar con que o a que?\n");
      return 0;
      }
   if ((str=="con bola") || (str=="con una bola") || (str=="con 1 bola")) {
      write("Empiezas a jugar con una bola... (que aburrido, no?).\n"
            "Para dejar de jugar, escribe 'parar'\n");
      njbolas=1;
      TP->AddExtraLook("Esta jugando a los malabares con una bola.\n");

      /* [o] MIRAR ESTO, NO SE SI ES AddSpecialLong!!!!!!!!!!!
             ME FALTA MIRAR EL DISEASE.C PA VER COMO ES.... */

      call_out("fseguir_jugando",5);
      return 1;
      }
   if (str=="con bolas")  // [o] Jugar con TODAS las bolas que tenga.
   {
      nbolas==TO->QueryAmount();
      if (nbolas==1)
      {
      write("Empiezas a jugar con una bola... (que aburrido, no?).\n"
            "Para dejar de jugar, escribe 'parar'\n");
      njbolas=1;
      TP->AddExtraLook("Esta jugando a los malabares con una bola.\n");
      call_out("fseguir_jugando",5);
      return 1;
      }
      else
      write(
"Empiezas a hacer malabares con "+nbolas+" bolas.\n");
      njbolas=nbolas;
      TP->AddExtraLook("Esta jugando a los malabares con "+njbolas+" bolas.\n");
      call_out("fseguir_jugando",5);
      return 1;
   }
   if (sscanf(str,"con %d bolas",nbolas)==1)
      if ( (TO->QueryAmount()) < nbolas)
      {
      notify_fail(
"Solo tienes "+TO->QueryAmount()+" bolas.\n");
      return 0;
      }
      else
      write(
"Empiezas a hacer malabares con "+nbolas+" bolas.\n");
      njbolas=nbolas;
      TP->AddExtraLook("Esta jugando a los malabares con "+njbolas+" bolas.\n");
      call_out("fseguir_jugando",5);
      return 1;
    }

fseguir_jugando() {  // [o] Continuar jugando..., hasta fparar.
   if (njbolas==1)   // [o] 1 sola bola.
      {
      write(
"Lanzas una bola hacia arriba, y la recoges antes de que caiga al suelo.\n");
      call_out("fseguir_jugando",10);
      }
   if (njbolas==2)   // [o] 2 bolas.
      {
      write("Estas malabareando dos bolas en una sola mano.\n");
      call_out("fseguir_jugando",9);
      }
   if (njbolas==3)   // [o] 3 bolas.
      {
      write("Malabareas una bonita cascada con las tres bolas.\n");
      call_out("fseguir_jugando",8);
      }
   if (njbolas==4)   // [o] 4 bolas.
      {
      write(
"Haces malabares con cuatro bolas a la vez. Estas echo un experto ya!\n");
      call_out("fseguir_jugando",7);
      }
   if (njbolas==5)   // [o] 5 bolas.
      {
      write(
"Malabareas una cascada de cinco bolas. Impresionante!\n");
      call_out("fseguir_jugando",6);
      }
   if ((njbolas>5)&&(njbolas<=nbolas))
                     // [o] Resto de los casos, siempre y cuando tenga
                     //     bolas suficientes.
      {
      write(
"Increible, estas malabareando "+nbolas+" bolas!!!\n");
      call_out("fseguir_jugando",5);
      }
   else              // [o] Caso extranyo.
      {
      notify_fail(
"Argo shungo pasa en er espashio-tiempo. Comunicashelo a un wisha.\n");
      return 0;
      }
}
fparar(str) {          // [o] Dejar de jugar.
   if (njbolas < 1)    // [o] NO estaba jugando.
   {
   notify_fail("No estas jugando a los malabares.\n");
   return 0;
   }
   if (njbolas >= 1)   // [o] SI estaba jugando -> deja de jugar.
   {
   remove_call_out("fseguir_jugando");
   njbolas=0;
   write(
"Dejas de jugar a los malabares.\n");
   return 1;
   }
   else                // [o] Caso extranyo.
   {
   notify_fail(
"Argo shungo pasa en er espashio-tiempo. Comunicashelo a un wisha.\n");
   return 0;
   }
}
