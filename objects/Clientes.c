typedef struct cliente {
	int id;
	char nome[20];
	char email[20];
	char senha[20];
} Cliente;

void imprimeClientes() {
	NoLista *atual = listaClientes->primeiro;
	while (atual != NULL) {
		Cliente *c = atual->dados;
	   	printf(
	   		"%d - %s, %s, %s\n",
	   		c->id,
	   		c->nome,
	   		c->email,
	   		c->senha
	  	);
	  	atual = atual->proximo;
	  	free(c);
	}
	printf("\n");
}

Cliente *buscaPorEmailESenha(char *email, char *senha) {
	NoLista *atual = listaClientes->primeiro;
  	while (atual != NULL) {
  		Cliente *c = atual->dados;
	    if ((strcmp(c->email, email) == 0) && (strcmp(c->senha, senha) == 0)) {
	      return c;
	    }
    	atual = atual->proximo;
  	}
  	return NULL;
}

void insereCliente(Cliente * c) {
	lista_insere_fim(listaClientes, c->id, c);
}

void cadastroCliente() {
	char tmp;
	char nome[20], email[20], senha[20];

	scanf("%c", &tmp);
	
	printf("Insira o nome\n");
	scanf("%[^\n]", nome);
	scanf("%c", &tmp);

	printf("Insira o email\n");
	scanf("%[^\n]", email);
	scanf("%c", &tmp);

	printf("Insira a senha\n");
	scanf("%[^\n]", senha);

	int id;

	NoLista * no = lista_ultimo_no(listaClientes);

	if (no != NULL) {
		id = no->valor +1;
	}
	else {
		id = 1;
	}

	Cliente *c = malloc(sizeof(Cliente));
	c->id = id;
	strcpy(c->nome, nome);
	strcpy(c->email, email);
	strcpy(c->senha, senha);
	
	insereCliente(c);

	FILE *file = fopen(FILE_CLIENTES, "a");
	if (file == NULL) {
		perror(FILE_CLIENTES);
	}
	fprintf(file, "%d;%s;%s;%s\n", c->id, c->nome, c->email, c->senha);
	fclose(file);
}

void login() {
	char email[20], senha[20];

	printf("Insira o email\n");
	scanf("%[^\n]", email);

	printf("Insira a senha\n");
	scanf("%[^\n]", senha);

	Cliente *c = buscaPorEmailESenha(email, senha);

	if (c != NULL) {
		// print usuario logado
	} else {
		// credenciais inválidas
	}
}