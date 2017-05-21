inherit "/obj/vialv";

void create() {
    ::create();
    SetLong("Es un vial de curación. Lleva el emblema del gremio de los Guardabosques.\n");
    SetFoodHeal(150);
}
