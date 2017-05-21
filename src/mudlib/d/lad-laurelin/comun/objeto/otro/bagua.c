/*
DESCRIPCION  : una botella de agua bendita q hace mucha pupa a muertos vivientes
FICHERO      : d/lad-laurelin/comun/objeto/tiin/lago/bagua_b.c
CREACION : 15-2-99 [Alura]

aun no esta acabado [angor]
Ya ta acabao pero revisalo si quieres [Alura]
--------------------------------------------------------------------------------
*/

inherit DRINK;

#include <properties.h>  //por el GENDER_MALE


int arrojar_agua(string str){
int dvol;
object ob;
string nombicho;
string comando;

if (present("agua bendita",TP))
{

  dvol=QueryFull();

  if (dvol<=0) {
	write("El frasco esta vacio.\n");
  	empty_vessel();
	return 0;
  }
  if (strlen(str)>=19){
     nombicho=str[19..strlen(str)];
     comando=str[0..17];
  } else {
     nombicho="";
     comando="";
  }

   if (!str) {write("Desperdicias el agua esa manera, tu veras.\n");}
  else
   {
   if (upper_case(comando)=="AGUA BENDITA SOBRE") {
     ob=present(nombicho,environment(TP));
     if (ob)
       {
          if ( (ob->QueryRace() == "no-muerto") || (ob->QueryRace() == "esqueleto") )
	     {
	     ob->AddHP(-(ob->QueryHP()/2));
	     say(TP->QueryName()+" arroja agua bendita al no-muerto y algunas partes de su cuerpo se deshacen.\n");
		 write("El "+nombicho+" se derrite parcialmente ante tus ojos.\n");
	     }
	  else {
	  		say(TP->QueryName()+" moja al "+nombicho+" y lo pone perdidito de agua.\n");
	  		write("Mojas al "+nombicho+" de arriba a abajo.\n");
           }
	   }
         else
         {
            write("No ves ningun "+nombicho+" al que mojar.\n");
         }
     }
  }
//en cualquier caso pierdes agua
dvol=dvol-100;
return SetFull(dvol);
 }else return 0;
}

init()
{
 ::init();
 add_action("arrojar_agua","arrojar");
 //add_action("arrojar_agua","echar");
}


create() {
   ::create();
    Set_Drink_Name("agua bendita");
    SetLong("Es un frasco de agua bendita.\n");
    SetFoodMsg1("Es refrescante.");
    SetFoodMsg2("se bebe un frasco de agua.");
    SetFoodAlc(0);
    SetFoodHeal(5);
    Set_Vessel_Name("frasco");
    Set_Vessel_Value(10);
    Set_Vessel_Weight(500);
    Set_Vessel_Volume(200);
    Set_Vessel_Gender(GENDER_MALE);
    SetValue(5000*100);  //5 monedas de mithril
    AddId(({"agua bendita","frasco"}));
}
