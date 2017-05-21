/*
   [Ch] Chaos@simauria
   [n] Nemesis@simauria
   **********************************************************************
    12-10-98 [Ch] Chaos creacion generica de animales.

    21-10-98 [Ch] Modificacion, que intercepta la funcion SetRace()
   		   para luego modificar las descripciones segun la
                   raza del animal.

    03-11-98 [Ch] Modificacion: introduccion de las funciones ave()
   		   mamifero(),reptil() e insecto()para que segun que
   		   raza sea actualice las descripciones y que no haga
   		   poner el inherit del ave.c mamifero.c reptil.c

    04-11-98 [Ch] Modificacion: eliminacion de las funciones
                  Actualizar(), Tamanyo() para crear las descripciones
   		   y se sigan usando las funciones estandars
    26-01.99 [Ch] Modificacion: se anyade el tamanyo Huge para todos
    		  los tipos de animales,
    10-03-99 [Ch] Modificacion: Reduccion del numero de ataques en las
    		  diferentes razas standars de animales debido a que no
    		  se cenyian a la realidad (y debatido por algunas nenazas)
    23-09-02 [n] Corrige la función SetRace() pa que devuelva string y no
                 int, que es lo que debía ser. No sé cómo funcionó desde
		 el principio, porque el parse no debería dejar que se
		 cambiara el tipo de una función sobrecargada.
    **********************************************************************
 */

//macros
#include <properties.h>
#define ART (QueryGender()==GENDER_FEMALE?"una ":"un ")

#include <miembro.h>
inherit NPC;

// Para que segun el tamanyo del animal se calcule el nivel, el peso y
// el valor del combate de las manos.
// Se usara mas adelante para que segun el tamanyo de la descripcion.
int SetSize(int tamanyo){
	::SetSize(tamanyo);
	switch(tamanyo){
		case 1 :	SetLevel(1+random(3));
			        SetWeight(!QueryWeight()?3000:QueryWeight());
				return 1;
				break;
		case 2 :	SetLevel(4+random(6));
			        SetWeight(!QueryWeight()?30000:QueryWeight());
				return 1;
				break;
		case 3 :	SetLevel(10+random(9));
			        SetWeight(!QueryWeight()?300000:QueryWeight());
				return 1;
				break;
		case 4:		SetLevel(23+random(13));
				SetWeight(!QueryWeight()?3000000:QueryWeight());
				return 1;
				break;
	        default:	SetLevel(1+random(3));
			        SetWeight(!QueryWeight()?3000:QueryWeight());
				return 1;
				break;
	}
return 1;
}

// Para la raza de mamiferos dentro de los animales
int Mamifero(){
	string nombre;
	string corta;
	string larga;
	
	nombre=QueryName();
	corta=ART+nombre;
	larga="Es "+corta+" normal y corriente. Tiene el cuerpo recubierto de pelo. Su  "
	      "tacto es muy suave. Utiliza sus cuatro patas para desplazarse, bien sea por el "
	      "suelo o por los arboles.\n";

	SetHands(({
		 	({"boca",1,4+QueryLevel()/2})
		}));
	SetShort(corta);
	SetLong(larga);

	InitChats(20,({capitalize(QueryName())+" se pasea entre los arboles.\n",
	               capitalize(QueryName())+" te pasa cerca.\n",
                       capitalize(QueryName())+" te mira indiferente.\n"}));
return 1;
}

// Para la raza de reptiles dentro de los animales
int Reptil(){
	string nombre;
	string corta;
	string larga;

	nombre=QueryName();
	corta=ART+nombre;
	larga="Es "+corta+" normal y corriente. Tiene el cuerpo recubierto de una piel  "
	      "fina y no tiene nada de pelo. Cuando realiza un desplazamiento, se arrastra  "
	      "sobre su vientre. Lo que te impresiona es la enorme boca que tiene.\n";

	SetHands(({
		 	({"boca",1,4+QueryLevel()/2}),
		}));
	SetShort(corta);
	SetLong(larga);


	InitChats(20,({capitalize(QueryName())+" se arrastra por entre los arboles.\n",
	               capitalize(QueryName())+" se arrasta cerca de ti.\n",
                       capitalize(QueryName())+" te mira indiferente.\n"}));
return 1;
}

// Para la raza de insectos dentro de los animales
int Insecto(){

	string nombre;
	string corta;
	string larga;

	nombre=QueryName();
	corta=ART+nombre;
	larga="Es "+corta+" normal y corriente. Tiene el cuerpo recubierto de pequenyas "
	      "placas a modo de armadura. Tiene ocho patas.\n";

	SetHands(({
		 	({"aguijon",1,4+QueryLevel()/2})
		}));
	SetShort(corta);
	SetLong(larga);

	InitChats(20,({capitalize(QueryName())+" se arrastra por entre los arboles.\n",
	               capitalize(QueryName())+" se arrasta cerca de ti.\n",
                       capitalize(QueryName())+" te mira indiferente.\n"}));
return 1;
}

// Para la raza de aves dentro de los animales
int Ave(){

	string nombre;
	string larga;

	nombre=QueryName();
	larga="Es "+nombre+" normal y corriente. Tiene unas plumas muy vistosas y bonitas "
	      "que le ayudan a la hora de volar. En el suelo es algo torpe por que sus patas  "
	      "no estan preparadas para correr.\n";

	SetHands(({
		 	({"pico",1,4+QueryLevel()/2})
		}));
	SetShort(nombre);
	SetLong(larga);
	InitChats(20,({capitalize(QueryName())+" pasa de rama en rama.\n",
	               capitalize(QueryName())+" picotea una fruta.\n",
                       capitalize(QueryName())+" te mira indiferente.\n"}));
	SetDesmembrableEn(({CABEZA,ALA,ALA}));
	AddId("pajaro");
	return 1;
}

// Por si no es ninguna de las razas genericas, ave, mamifero, reptil
int Defecto(){

	string nombre;
	string corta;
	string larga;

	nombre=QueryRace();
	corta=ART+nombre;
	larga="Es "+corta+" normal y corriente\n";

	SetHands(({
		 	({"boca",1,4+QueryLevel()/2})
		}));
	SetShort(corta);
	SetLong(larga);

return 1;

}

//Intercepcion de la raza para actualizar las descripciones del animal
string SetRace(string raza){
    	string nombre;
    	nombre=QueryName();
	switch (raza){
		case "ave"     :	Ave();
					break;
		case "reptil"  :	Reptil();
					break;
		case "mamifero":	Mamifero();
					break;
		case "insecto" :	Insecto();
					break;
		default	       :        Defecto();
					break;
	}
	AddId(nombre);
        return ::SetRace(raza);
}

create (){
   ::create();
        SetName("animal");
	SetSize(1);
	SetRace("animal");
	SetIds(({"animal"}));
	SetSP(0);
	SetMaxSP(0);
}

