/*
DESCRIPCION  : pata pequenya (miembro desmembrado)
FICHERO      : /obj/miembro/pata_pequenya.c
MODIFICACION : 11-09-98 [Angor@Simauria] Creacion.
               Mar'99 [Nemesis@Simauria] Castellanizado.
--------------------------------------------------------------------------------
*/

inherit "/obj/miembro";

create() {
  ::create();
  //caracteristicas generales
  SetShort("una pata separada de su cuerpo"); //sera actualizada por miembro.c
  SetLong(
  "Es una pequeña pata desmembrada y ensangrentada. No es probable que su anterior\n"
  "propietario la reclame...\n");

  SetIds( ({"pata","pata pequenya"}) );
  AddAdjective( ({"separada","una","sangrienta","cortada"}) );
  SetSmell("La pata huele a sangre.\n");
  SetNoise("¿Qué ruido quieres que haga un trozo de carne muerta?\n");
  AddId("miembro");
  SetWeight(400);

  //caracteristicas propias del miembro desmembrado
  SetTipo("pata");
  SetRace("un ser desconocido");  //si es un miembro desmembrado, el body.c hace que se
                                  //herede luego la del PNJ padre
  SetEfecto("curativo");
  SetComible(1);
  SetCocinable(1);
  SetVendible(0);
  SetPudrible(1);
  SetDuracion(30);               //dura 30 mn
  SetRitmoPutrefaccion(20);      //baja un punto aproximadamente cada minuto
  SetGenero(2);
  SetPoder(4);
  SetValor(0);
  SetVomitar(10);                //10% de probabilidad de vomitar al comertela

  SetComestiblePor(({"elfo","elfo_oscuro","humano","medio_elfo","gigante",
  "troll","orco","demonio","kainoak","draconiano","logath","duende","gnomo",
  "enano","kender"}));

  /*"elfo","elfo_oscuro","humano","medio_elfo","gigante","troll","orco","demonio",
  "kainoak","draconiano","logath","duende","gnomo","enano","kender"*/

  SetComerMSG(
  "Empiezas a pegarle mordiscos a la pequenya pata.\n","");
}
