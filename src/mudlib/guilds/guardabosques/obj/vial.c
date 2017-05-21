inherit "/obj/vial";

void create() {
    ::create();
    SetLong("Es un vial de regeneración. Lleva el emblema del gremio de los Guardabosques.\n");
    SetFoodHeal(150);
}
