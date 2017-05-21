#include "./path.h"

inherit ROOM;

void AddMsgs(int freq, string *msgs);

void create()
{
   ::create();
  SetIntShort("");
   SetIntLong("");
   SetIndoors(1);

AddDetail(
   ({"suelo","cloaca"}),
   W("Al mirar al suelo y a tu alrededor ves solo oscuridad "
      "y suciedad.\n")
   );

AddDetail(
  ({"paredes","pared","techo"}),
   W("Por las paredes y goteando del techo distingues un líquido "
      "semiespeso y maloliente, y te preguntas como te has metido "
     "en semejante lugar")
   );

AddDetail(
   ({"l^Mquido","liquido"}),
   W("Gotea casi por toda la cloaca.\n")
   );

AddDetail(
  ({"suciedad"}),
   W("Te rodea por todas partes.\n")
   );

AddMsgs(33,
   ({
   W("Crees oir algo a tu espalda, pero al girarte ves sólo "
      "oscuridad y ese molesto líquido goteando a tu alrededor.\n"),
   W("A lo lejos, parece como si una sombra se moviera, pero al "
      "fijarte mejor ves que sólo es una rata.\n"),
   W("El incesante ruido de ese molesto líquido goteante "
      "martillea en tus oídos.\n"),
   W("Ack! Parece como si algo te hubiese tocado en el brazo!\n")
   })
   );

   SetIntBright(10);
}
/***************************************************************/
/* Funcion AddMsgs(int freq, string *msgs)                     */
/*    'freq' es la frecuencia con la que saldran los mensajes  */
/*    dados por el vector de string 'msgs'. La frecuencia de   */
/*    los mensajes es medida de forma porcentual, lo cual      */
/*    quiere decir que si pones un 100, cada segundo imprimirá */
/*    un mensaje por pantalla.                                 */
/***************************************************************/
void AddMsgs(int freq, string *msgs)
{
int perc;
int r;

r=random(sizeof(msgs));

/* La frecuencia nunca podrá ser mayor q 100 o menor q 5 */
if(freq > 100) freq=100;
if(freq < 5) freq=5;

perc=1000/freq;

tell_room(TO,msgs[r]);

if(find_call_out("AddMsgs") != -1) remove_call_out("Msgs");
call_out("AddMsgs", perc, freq, msgs);
}
