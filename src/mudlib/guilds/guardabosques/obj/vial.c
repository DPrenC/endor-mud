inherit "/obj/vial";

void create() {
    ::create();
    SetLong("Es un vial de regeneraci�n. Lleva el emblema del gremio de los Guardabosques.\n");
    SetFoodHeal(150);
}
