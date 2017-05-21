/*
DESCRIPCION  : ala (miembro desmembrado)
FICHERO      : /obj/miembro/ala.c
MODIFICACION : 29-07-98 [Angor@Simauria] Creacion.
               Mar'99 [Nemesis@Simauria] Castellanizado.
--------------------------------------------------------------------------------
*/

inherit "/obj/miembro";

create() {
  ::create();
  //caracteristicas generales
  SetShort("un ala separada de su cuerpo"); //sera actualizada por miembro.c
  SetLong(
  "Es un ala desmembrada y ensangrentada. Algunas de sus plumas faltan y otras\n"
  "están rotas.\n");
  SetIds( ({"ala"}) );
  AddAdjective( ({"separada","una","sangrienta","cortada"}) );
  SetSmell("El ala huele a sangre.\n");
  SetNoise("¿Qué ruido quieres que haga un trozo de carne muerta con plumas?\n");
  AddId("miembro");
  SetWeight(500);

  //caracteristicas propias del miembro desmembrado
  SetTipo("ala");
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
  SetPoder(10);
  SetValor(0);
  SetVomitar(25);                //25% de probabilidad de vomitar al comertela

  SetComestiblePor(({"elfo","elfo_oscuro","humano","medio_elfo","gigante","troll",
  "orco","demonio","kainoak","draconiano","logath","enano","kender"}));

  /*"elfo","elfo_oscuro","humano","medio_elfo","gigante","troll","orco","demonio",
  "kainoak","draconiano","logath","duende","gnomo","enano","kender"*/
  //SetDesmembrableEn({CABEZA,PIERNA,PIERNA,BRAZO,BRAZO,TRONCO});

  SetComerMSG(
  "Empiezas a pegarle mordiscos al ala. Escupes algunos trozos de plumas que has\n"
  "mordido junto con la carne.\n",
  "");
}
