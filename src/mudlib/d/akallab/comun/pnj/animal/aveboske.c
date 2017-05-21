/*
  ***************************************************************
   Fichero para la generacion de pajaros tipicos de un bosque
  ***************************************************************
   22-10-98 [Chaos]		Creacion

   04-11-98 [Chaos] Modificacion: cambio del path por que ahora
    		  no hace falta la funcion Actualizar y han
   		  sido eliminados los ficheros ave.c mamifero.c
  		  reptil.c
  **************************************************************
*/
#define ART (QueryArtIndString()+" ")

#include <properties.h>
#include <living.h>
#include <miembro.h>

inherit "/d/akallab/comun/pnj/animal/animal";
// inherit NPC;
     int numero1;
     int numero2;

create(){
     ::create();
     SetSize(1);
     SetWeight(500);
     numero1=random(10);
     switch (numero1){
			case 0	:	SetName(ART+"gorrion");
					AddId("gorrion");
					break;
			case 1	:	SetName(ART+"jilguero");
					AddId("jilgero");
					break;
			case 2	: 	SetName(ART+"ruisenyor");
					AddId("ruisenyor");
					break;
			case 3	: 	SetName(ART+"pajaro carpintero");
					AddId("carpintero");
					AddId("pajaro");
					break;
			case 4	: 	SetName(ART+"petirrojo");
					AddId("petirrojo");
					break;
			case 5	: 	SetName(ART+"tordo");
					AddId("tordo");
					break;
			case 6  :	SetName(ART+"martin pescador");
					AddId("pescador");
					AddId("martin");
					break;
			case 7  :	SetName(ART+"colibri");
					AddId("colibri");
					break;
			case 8  :	SetName(ART+"canario");
					AddId("canario");
					break;
			case 9  :	SetName(ART+"periquito");
					AddId("periquito");
					break;
			default : 	SetName(ART+"pajarillo");
					AddId("pajarillo");
					break;
   }
   numero2=random(2);
   SetRace("ave");
   switch(numero2){
		case 0 :  SetShort(QueryName());
			  SetLong("Es "+QueryName()+" de vistosos y alegres colores que se posa en el suelo a picotear "+
			  	   "algo de comida\n");
			  return ;
			  break;
		case 1:   SetShort(QueryName());
			  SetLong("Es "+QueryName()+" de pequenyas dimensiones que revolotea de un lado hacia otro. Se "+
 			          "posa en una rama y se pone a cantar.\n");
			  return ;
			  break;
		default : SetShort(QueryName());
			  SetLong("Es un pajarillo de vistosos y alegres colores que se posa en el suelo a picotear "+
			  	   "algo de comida\n");
			  return ;
			  break;
   }
 SetGender(GENDER_MALE);
 SetDesmembrableEn(({ALA,ALA,CABEZA}));
 if (numero1==3) SetNoise("Tactactactactactactactactactac.\n");
         else    SetNoise("Tuititititituituitituituitititui.\n");
}