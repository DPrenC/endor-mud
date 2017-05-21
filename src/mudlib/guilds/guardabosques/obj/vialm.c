inherit "/obj/vialm";

void create() {
    ::create();
    SetLong("Es un vial de regeneración de magia. Lleva el emblema del gremio de\n"+
    	"los Guardabosques.\n");
    SetFoodHeal(150);
}
