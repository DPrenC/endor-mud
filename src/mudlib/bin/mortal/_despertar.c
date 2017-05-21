// Comando despertar

public int main(string str) {
  if (!TP) return 0;

  if (TP->QueryStatusResting()) return command("descansar", TP);
  if (TP->QueryStatusSleeping()) return command("dormir", TP);
write("No estás durmiendo, sentado ni descansando.\n");
  return 1;

}