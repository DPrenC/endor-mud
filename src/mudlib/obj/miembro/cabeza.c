/*
DESCRIPCION  : cabeza comestible
FICHERO      : /obj/miembro/cabeza.c
MODIFICACION : 20-07-98 [Angor@Simauria] Creacion.
               Mar'99 [Nemesis@Simauria] Castellanizado.
--------------------------------------------------------------------------------
Ejemplo de utilizacion de miembros desmembrados basados en miembro.c
--------------------------------------------------------------------------------
*/

inherit "/obj/miembro";

create() {
  ::create();
  //caracteristicas generales
  SetShort("una cabeza separada de su cuerpo"); //sera actualizada por miembro.c
  SetLong(
  "La cabeza aún está caliente, y la sangre chorrea por su cuello degollado\n"
  "llenándolo todo de sangre.\n");
  SetIds( ({"cabeza"}) );
  AddAdjective( ({"separada","una","sangrienta","cortada"}) );
  SetSmell("La cabeza despide ese olor tan peculiar que tiene la sangre.\n");
  SetNoise("Mientras juegas con la cabeza puedes escuchar algun 'crack' estimulante.\n");
  AddId("miembro");
  SetWeight(1000);

  //caracteristicas propias del miembro desmembrado
  SetTipo("cabeza");
  SetRace("un ser desconocido");  //si es un miembro desmembrado, el body.c hace que se
                                  //herede luego la del PNJ padre
  SetEfecto("saciante");
  SetComible(1);
  SetCocinable(1);
  SetVendible(0);
  SetPudrible(1);
  SetDuracion(10);               //dura 10 mn
  SetRitmoPutrefaccion(20);      //baja un punto aproximadamente cada minuto
  SetGenero(2);
  SetPoder(20);
  SetValor(0);
  SetVomitar(50); //50% de probabilidad de vomitar al comertela

  SetComestiblePor(({"orco","troll","kainoak","draconiano","demonio"}));

  /*"elfo","elfo_oscuro","humano","medio_elfo","gigante","troll","orco","demonio",
  "kainoak","draconiano","logath","duende","gnomo","enano","kender"*/
  //SetDesmembrableEn({CABEZA,PIERNA,PIERNA,BRAZO,BRAZO,TRONCO});

  SetComerMSG(
  "Empiezas a pegarle mordiscos a la cabeza produciendo un sonido desgarrador.\n",
  "");
}
