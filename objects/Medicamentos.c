typedef struct medicamento {
	int id;
	char nome[100];
	float preco;
} Medicamento;

void imprimeMedicamentos(node *no, int nivel) {
	if (no != NULL) {
	  	imprimeMedicamentos(no->esquerda, nivel + 1); 

		Medicamento *m = no->dados;
	  	printf(
	  		"%d - %s: R$ %.2f \n",
	  		m->id,
	  		m->nome,
	  		m->preco
	 	);
	 	free(m);

	  	imprimeMedicamentos(no->direita, nivel + 1);
	}
}