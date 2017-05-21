/*
DESCRIPCION  : vomito
FICHERO      : /obj/miembro/vomito.c
MODIFICACION : 22-07-98 [Angor@Simauria] Creacion.
               Mar'99 [Nemesis@Simauria] Castellanizado.
--------------------------------------------------------------------------------
*/

inherit "/obj/miembro";

create() {
  ::create();
  SetShort("un v�mito asqueroso y repugnante");
   SetLong(
"Es un v�mito. Su textura es espesa y ves unos tropezones amarillos y otras\n"
"cosas a�n mas extranyas flotando en su superficie. Podr�a llegar a ser\n"
"comestible, aunque no es recomendable.\n");

SetIds( ({"vomito","pota"}) );
AddAdjective( ({"asqueroso","repugnante","sanguinolento","amarillo"}) );
SetSmell("Ags! Notas un olor �cido y espeso que viene del v�mito.\n");
SetNoise("El v�mito no produce ningun ruido, aunque en su momento hubo de producirlo.\n");
AddId("vomito");
SetWeight(250);

  //caracteristicas propias del miembro
  SetTipo("vomito");
  SetRace("un ser desconocido");
  SetEfecto("ninguno");
  SetComible(0);
  SetCocinable(0);
  SetVendible(0);
  SetPudrible(1);
  SetDuracion(2);                //dura un par de minutos
  SetRitmoPutrefaccion(20);
  SetGenero(1);
  SetPoder(0);
  SetValor(0);
}

