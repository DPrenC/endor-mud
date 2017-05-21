// Comando comandos

public int main(string str) {
  if (!TP) return 0;
  printf("Local commands:\n%-78#s\n", implode(query_actions(TP), "\n"));
	return 1;
}