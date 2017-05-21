/*
	Kheron el enano soplagaitas, para el quest de la copa
	cheto 7-11-01
*/
	
#include "path.h"
#include <properties.h>
inherit NPC;
create()
{
  ::create();

  SetStandard("Kheron", "enano", 10, GENDER_MALE);
  SetShort("Kheron el Soplador de Vidrio");
  SetLong(W("Kheron es un enano de mediana edad con una larga barba roja "
	"es famoso en todo Lad-laurelin por su reconocida habilidad para "
	"soplar vidrio, es realmente bueno en su trabajo. "
	"\n"));
  	
  SetIds(({"kheron", "enano", "Kheron"}));

  InitChats(1,({
  "Kheron saca un trozo de Vidrio de la fragua y empieza a Soplar.\n",
  "Kheron pone a remojar un jarrón recien soplado para enfriar el Vidrio.\n",
  "Kheron rompe un jarrón de Vidrio recien soplado porque no le gusta.\n",
  "Kheron se aparta el sudor de la frente y se bebe un vaso de agua.\n",	
    ""}));
AddQuestion(({"llama","llama imperecedera"}),
"Necesito la llama imperecedera para encender mi fragua, sin ella no\n"
"puedo practicar el arte de soplar el vidrio.\n");
AddQuestion("arena",
"Para soplar la copa, necesito vidrio del santuario de la diosa\n"
"humana del mar, vete a gorat y pregunta allí.\n");

}
//funcion que comprueba varias cosas,
//primero hay que darle la llama, para que encienda la fragua
//si la fragua está encendida, pero el pibe no lleva
//la llama la apaga y la pide
//si esta encendida y tienes la arena, te da la copa y
//borra los objetos del player, si no, no los borra.


notify_enter(mixed oldenv, int method, mixed extra) {
object p;
object q;
object r;

::notify_enter(oldenv,method,extra);

p=PO;
if (p->QueryIds())
  if (p->id("llamaq"))
  {
   write ("El enano usa la llama para encender la fragua y te la debuelve.\n");
   environment(TO)->SetFragua(1); //enciande la fragua.
   p->move(TI);
   return 42;
  }
 if (p->id("arenaq"))
 {
 if (environment(TO)->QueryFragua()==1){
	if (r=present("llamaq",TI)){
	    write("El enano con la fuerza de su soplido te apaga la llama.\n");
	if (r) r->remove();
	write("El enano se dispone a soplar el vidrio y te da una bonita copa de cristal.\n");
	q=clone_object("/d/simauria/comun/objeto/otro/vidrio");
	q->move(TI);
	 }
	else
	{
	(environment(TO)->SetFragua(0));
	write("tienes que traerme la llama para encender la fragua");
	p->move(TI);
	}
    }//fragua encendida
    else
	{
	write("El enano te dice:\n"
	"Traeme la llama imperecedera para poder encender mi fragua, sin ella\n"
	"no te puedo soplar el vidrio.\n");
	p->move(TI);
	}//else
}//funcion
}
