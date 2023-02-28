
typedef struct nolista {
  int valor;
  struct nolista *proximo;
  void *dados;
} NoLista;

typedef struct lista {
  NoLista *primeiro;
  int tamanho;
} Lista;

Lista *cria_lista() {
  Lista *lista = (Lista*) malloc(sizeof(Lista));
  lista->primeiro = NULL;
  lista->tamanho = 0;
  return lista;
}

void insere_inicio(Lista *lista, int valor, void *dados) {
  NoLista *novo = (NoLista*) malloc(sizeof(NoLista));
  novo->valor = valor;
  novo->proximo = lista->primeiro;
  novo->dados = dados;
  lista->primeiro = novo;
  lista->tamanho++;
}

void lista_insere_fim(Lista *lista, int valor, void *dados) {
  NoLista *novo = (NoLista*) malloc(sizeof(NoLista));
  novo->valor = valor;
  novo->proximo = NULL;
  novo->dados = dados;
  if (lista->primeiro == NULL) {
    lista->primeiro = novo;
  } else {
    NoLista *atual = lista->primeiro;
    while (atual->proximo != NULL) {
      atual = atual->proximo;
    }
    atual->proximo = novo;
  }
  lista->tamanho++;
}

NoLista *lista_ultimo_no(Lista *lista) {
	if (lista->primeiro != NULL) {
		NoLista *atual = lista->primeiro;
	  	while (atual->proximo != NULL) {
	    	atual = atual->proximo;
	  	}
	  	return atual;
	}

	return NULL;
}

void remove_inicio(Lista *lista) {
  if (lista->primeiro != NULL) {
    NoLista *temp = lista->primeiro;
    lista->primeiro = lista->primeiro->proximo;
    free(temp);
    lista->tamanho--;
  }
}

void remove_fim(Lista *lista) {
  if (lista->primeiro != NULL) {
    if (lista->primeiro->proximo == NULL) {
      free(lista->primeiro);
      lista->primeiro = NULL;
    } else {
      NoLista *anterior = lista->primeiro;
      NoLista *atual = lista->primeiro->proximo;
      while (atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
      }
      anterior->proximo = NULL;
      free(atual);
    }
    lista->tamanho--;
  }
}

void exibe_lista(Lista *lista) {
  NoLista *atual = lista->primeiro;
  printf("Lista: ");
  while (atual != NULL) {
    printf("%d ", atual->valor);
    atual = atual->proximo;
  }
  printf("\n");
}

void libera_lista(Lista *lista) {
  NoLista *atual = lista->primeiro;
  while (atual != NULL) {
    NoLista *temp = atual;
    atual = atual->proximo;
    free(temp);
  }
  free(lista);
}