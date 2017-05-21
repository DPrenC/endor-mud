// c_kutiri.c

/*
 Carromato-vivienda de los Hermanos Kutiri.
 (c) [n] nemesis@simauria
 Creaci�n:  06-Oct-2002 00:32:26 CEST [n]
 Notas: Ser�a "bonito" colocar un peque�o notify_enter de tal manera
        que al incauto player le ocurriera "algo" al entrar en el
	carromato. Al fin y al cabo, son kenders y adem�s uno de ellos
	es "artista de las bromas", con lo que como m�nimo deber�a
	haber un cubo de agua sucia esperando al incauto player sobre
	la puerta. O una c�scara de pl�tano, o un cepo para osos...
	No s�, las posibilidades son infinitas...
 Modificado:

*/

#include <moving.h>
// Para el caso hipot�tico de que los mensajitos lleven colores y/o efectos
#include <colours.h>

#include "./path.h"

inherit SIM_ROOM;

// Peque�a "broma"

private void cubo_agua() {
 write(W("Un cubo de agua sucia te cae encima, empap�ndote por completo. "
      "Los cinco kenders comienzan a re�rse, se�al�ndote. Es evidente que "
      "se r�en de ti. Claro que tu aspecto no es para menos...\n"));
 // Aqu� le metemos un bonito objeto invisible que contenga un extralook
 // acorde con el rollo.
 // Finalmente, el jugador se lleva un bonito olor :)
 PO->SetSmell("A tu nariz llega un nauseabundo olor a suciedad. Es asqueroso.\n");
}

// Un poco salvaje, pero "gracioso" :)
private void cepo() {
 int hp;
 hp = PO->QueryHP();
 write(W("Nada m�s entrar en el carromato, oyes un chasquido y sientes "
         "un dolor lacerante en la pierna. Tu aullido de dolor se mezcla "
	 "con las risotadas de los cinco kenders, que se revuelcan por el "
	 "suelo de la risa. Al mirar hacia abajo, descubres que tu pierna "
	 "est� atrapada en una enorme ratonera. Te sueltas como puedes, "
	 "pero el dolor a�n te durar� un rato... �Jod�os kenders!\n"));
 if (hp>25) PO->SetHP(hp - 25);
 else       PO->SetHP(1);
}
// Suavesito en apariencia, pero algo inventar�...
private void aceite() {
 int hp;
 hp = PO->QueryHP();
 write(W("Nada m�s entrar en el carromato, notas que pierdes el apoyo y "
         "te caes al suelo de culo. En ese momento los cinco kenders, que "
	 "te estaban observando con atenci�n, comienzan a re�rse. Sin duda "
	 "tu pat�tica entrada les ha hecho mucha gracia. Como puedes, te "
	 "levantas e intentas recuperar tu dignidad. No ser� trabajo f�cil.\n"));
 // Tal vez aqu� convenga poner un Extralook... no s�, veremos...
 if (hp>5) PO->SetHP(hp - 5);
 else      PO->SetHP(1);
}

private void nada() {
 write(W("Los cinco kenders comienzan a re�r. Te quedas en el umbral un "
         "momento, dudando si entrar o no, cosa que finalmente haces.\nNo "
         "pasa nada.\n"));
 // �Por qu� no un Extralook? Con un bonito cartel que diga: "P�game una patada"

}

void notify_enter(mixed from,
                  int method,
		  mixed extra) {
 int broma;
 object who;
// if (method == M_TELEPORT) return;
 who = PO;
 write(W("Entras en el carromato y ves ante ti a cinco kenders "
         "sonrientes. Das un paso para entrar y...\n"));
 // A partir de aqu� tenemos la peque�a "broma" que te van a gastar
 // los degeneraos �stos (bueno, m�s bien s�lo uno, pero todos se
 // reir�n...)
 broma = random(4);
 write(broma+"\n");
 switch (broma) {
  case 0: cubo_agua();
          break;
  case 1: cepo();
          break;
  case 2: aceite();
          break;
  case 3: nada();
          break;
  default: break;
 }
}


create() {
 ::create();

 SetLocate("Bosque de Lengor");
 SetIntShort("el carromato de los hermanos Kutiri");
 SetIntLong(
 W("Te encuentras en un carromato espacioso, pero donde hay poco espacio "
   "libre debido a que est� lleno de trastos. Puedes ver un par de literas "
   "y un viejo camastro en un rinc�n, as� como varios artefactos que sin duda "
   "deben pertenecer al espect�culo de los hermanos Kutiri. Una puerta azul "
   "da acceso al exterior.\n"));
 SetIndoors(1);
 SetIntBright(45);

 AddDetail("carromato",TO->QueryIntLong());
 AddDetail(({"trastos","cachivaches"}),
 W("Hay de todo un poco: viejos cacharros de cocina, pedazos de vidrio, "
   "botellas, chatarra de todas clases,... Eso s�, todos tienen algo en "
   "com�n: son absolutamente in�tiles.\n"));
 AddDetail(({"cacharros de cocina"}),
 "A juzgar por su estado, no crees que los hermanos Kutiri los usen para cocinar.\n");
 AddDetail(({"pedazos de vidrio"}),
 W("Del techo cuelgan varias cuerdas con trozos de vidrio atravesados "
   "en ellas. No es que sean precisamente bonitos, pero le dan un toque "
   "de color al carromato.\n"));
 AddDetail(({"botellas"}),
 W("Hay botellas de todas las formas y colores, todas vac�as. Tal "
   "vez sea cierto lo de que todos los artistas beben demasiado...\n"));
 AddDetail(({"trozos de metal"}),
 W("Hay chatarra de todas las procedencias: puntas de flecha oxidadas, "
   "latas viejas, llaves, tornillos,...\n"));
 AddDetail(({"puntas de flecha","latas","latas viejas","llaves","tornillos"}),
 "�Tienes alg�n inter�s profesional en la chatarra o es simple curiosidad?\n");
 AddDetail(({"artefactos","artefactos de circo"}),
 W("Puedes ver unas pelucas, pinturas, lo que parecen unas flores de "
   "papel y otros extra�os artefactos que parecen algo as� como instrumentos "
   "musicales.\n"));
 AddDetail(({"pelucas","pinturas","flores de papel","instrumentos musicales"}),
 W("Parece que el espect�culo de los hermanos Kutiri es una mezcla bastante "
   "heterog�nea de todas las artes.\n"));
 AddDetail(({"extra�os artefactos"}),
 W("Si de extra�os artefactos se trata, puedes ver algunos muy raros "
   "junto a un banco de trabajo en la pared del fondo.\n"));
 AddDetail(({"banco de trabajo","banco"}),
 W("Es un r�stico mueble de madera sobre el que se desparraman sin orden "
   "ni concierto toda clase de herramientas. Junto a �l puedes ver lo que "
   "parecen m�quinas o algo as�.\n"));
 AddDetail(({"m�quinas","maquinas","herramientas"}),
 W("Tienen un aspecto horrible. No quieres ni imaginar para lo que "
   "pueden servir. Aunque, bien pensado, probablemente no sirven para "
   "nada.\n"));
 AddDetail(({"literas"}),
 W("Son literas de dos pisos, una est� pintada de verde y la otra de "
   "amarillo.\n"));
 AddDetail(({"litera"}),
 "Hay dos literas: una verde y otra amarilla.\n");
 AddDetail(({"litera amarilla"}),
 W("Sobre el cabezal de la litera superior puedes ver pintada una gran "
   "'B' y sobre el de la inferior una 'P'.\n"));
 AddDetail(({"'B'","B","gran B","gran 'B'","b","'b'","gran b", "gran 'b'"}),
 W("Una letra 'B' de complicada filigrana ha sido tallada y pintada "
   "de dorado ocupando casi todo el cabezal. �sa debe ser la cama de "
   "Binky.\n"));
 AddDetail(({"cama de Binky","cama de binky"}),
 W("Parece la m�s c�moda de todas. Est� bastante limpia y est� hecha "
   "con gran cuidado.\n"));
 AddDetail(({"'P'","P"}),
 "�sa debe ser la cama de Pinky.\n");
 AddDetail(({"cama de Pinky","cama de pinky"}),
 W("Se parece a la cama que tiene sobre ella, si bien parece que su due�o "
   "la ha intentado 'mejorar' con algunos 'toques personales'.\n"));
 AddDetail(({"toques personales de la cama de Pinky",
             "toques personales de la cama de pinky",
             "toques personales de cama de Pinky",
             "toques personales de cama de pinky",
             "palancas","palancas adosadas a la cama de Pinky,",
             "palancas adosadas a la cama de pinky"}),
 W("Hay un par de palancas adosadas a un lateral de la cama. No puedes "
   "imaginar para qu� sirven.\n"));
 AddDetail(({"litera verde"}),
 W("Sobre el cabezal de la litera superior puedes ver pintada una 'T' "
   "y sobre el de la inferior una 'D'.\n"));
 AddDetail(({"'T'","T"}),
 "�sa debe ser la cama de Tinky.\n");
 AddDetail(({"cama de Tinky","cama de tinky"}),
 W("La cubre una colcha de color verde brillante, aunque las s�banas "
   "que tiene debajo no parecen haber sido alisadas con demasiado ardor. "
   "Sobre ella descansa un extra�o instrumento musical.\n"));
 AddDetail(({"instrumento sobre cama de Pinky",
             "instrumento sobre cama de pinky",
             "instrumento musical sobre cama de Pinky",
             "instrumento musical sobre cama de Pinky"
             "instrumento musical"}),
 W("Parece un extra�o h�brido entre corneta, guitarra y bandone�n. Su "
   "sonido debe ser 'peculiar', por decirlo de manera no hiriente...\n"));
 AddDetail(({"'D'","D"}),
 "�sa debe ser la cama de Dinky.\n");
 AddDetail(({"cama de Dinky","cama de dinky"}),
 W("Aunque parece haber sido pintada recientemente, da una sensaci�n "
   "de suciedad indescriptible. Est� deshecha y puedes ver algunas manchas "
   "de lo que parece aceite en las s�banas. A su vez, la funda de la "
   "almohada tiene un curioso tono gris�ceo-amarillento, aunque jurar�as "
   "que originalmente era blanca\n"));
 AddDetail(({"camastro","cama de Clyde","cama de clyde"}),
 W("Es de un color que en tiempos debi� ser marr�n, pero que ahora es "
   "m�s bien naranja sucio. En el cabezal puedes ver pintada una gran 'C'.\n"));
 AddDetail(({"'C'","C","gran C","gran 'C'"}),
 "Es lo �nico que parece reciente en el desvencijado camastro.\n");
// ... y 29 (!!) AddDetails. Pa que aprendan otros...
 AddDetail(({"puerta","puerta azul"}),
 W("Jurar�as que es la misma por la que entraste (tampoco hay otra, vaya). "
   "Y si entraste por ella, lo normal es que tambi�n puedas usarla para salir.\n"));

// AddItem("binky",REFRESH_REMOVE, 1);
// AddItem("dinky",REFRESH_REMOVE, 1);
// AddItem("pinky",REFRESH_REMOVE, 1);
// AddItem("tinky",REFRESH_REMOVE, 1);
// AddItem("clyde",REFRESH_REMOVE, 1);

// AddExit("salir", "fuera");

}
