/*=============================================================*
 |           << GOLDHAI.Barcos [w] Woo@simauria >>             |
 *=============================================================*
 |              Creacion............. 24-02-99                 |
 |              Ultima Modificacion.. 24-02-99                 |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit SHIP;

string *MensajesEntradaBarco(string puerto)
{

 if (puerto==BNORTE("embarcadero"))
  return ({
   "\nHas llegado de nuevo a las inmediaciones del bosque Norte de Goldhai. El bote\n"
   "se aproxima lentamente al embarcadero y se para junto al peque�o muelle.\n",
   "Un peque�o bote viejo y ruinoso se detiene en el embarcadero.\n"});

 if (puerto==LAGO("embarcadero"))
  return ({
   "\nLlegas a un peque�o embarcadero situado en la parte sur de la isla que se\n"
   "encuentra en el centro del lago Zinn. Todo parece solitario y abandonado.\n",
   "Un bote se aproxima y se detiene en el embarcadero.\n"});

 return ({
   "El bote llega a a @@Harbour@@!\n",
   "El bote atraca en el embarcadero.\n"});
}

string *MensajesSalidaBarco(string puerto)
{
 puerto=FromHarbour();
 if (puerto=="bosque norte")
  return ({
   "\nInexplicablemente el bote se comienza a alejar del embarcadero por si\n"
   "solo y sin ninguna raz�n aparente. Todo esto te resulta muy extra�o.\n",
   "El bote fantasma se aleja lentamente del embarcadero.\n"});

 if (puerto=="isla del lago Zinn")
  return ({
  "\nUn peque�o golpe de agua hace que el bote comience a separarse poco a poco\n"
  "del embarcadero alejandose de la isla.\n",
  "El bote se aleja del embarcadero.\n"});

 return ({
   "El bote comienza a alejarse del embarcadero.\n ",
   "El bote fantasma se aleja del embarcadero.\n"});
}

create()
{
 ::create();
 SetIds(({"bote","bote fantasma"}));
 SetShort("el bote fantasma");
 SetLong(
"Es un peque�o bote bastante viejo y sucio.\n");

 SetIds(({"bote", "bote fantasma"}));

 SetLeaveSound(0);
 SetEnterMsgs(({"sube al bote.",
                "sube al bote de forma precavida.",
                "Te montas en el bote fantasma"}));
 SetLeaveMsgs(({"baja del bote.",
                "abandona el bote con sumo cuidado.",
                "Abandonas el bote fantasma"}));

 SetShipEnterMsgs(SF(MensajesEntradaBarco));
 SetShipLeaveMsgs(SF(MensajesSalidaBarco));

 AddPort("bosque norte",BNORTE("embarcadero"));
 AddPort("isla del lago Zinn",LAGO("embarcadero"));

 AddMoveScene(BNORTE("embarcadero"),LAGO("embarcadero"),
   "El bote continua su viaje a trav�s del lago.\n",4);
 AddMoveScene(LAGO("embarcadero"),BNORTE("embarcadero"),
   "A�n no sabes como pero el bote surca el lago sin tripulaci�n.\n",4);
 AddDeck(BOTE_FANTASMA("int_bote"));

 SetMsgCost("No tienes suficiente dinero para viajar.\n");
}

QueryShipCost()
{
 return 0; // Es Gratis
}
