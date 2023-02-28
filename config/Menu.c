void menuAdmin() {

	int exit = false;
	int opcao;

	while(!exit) {

		printf("\n");
		printf("1 - Listar medicamentos\n");
		printf("2 - Listar clientes\n");
		printf("10 - Sair\n");

		scanf("%d", &opcao);

		if (opcao == 1) {
			imprimeMedicamentos(arvoreMedicamentos, 0);
		}
		else if (opcao == 2) {
			imprimeClientes();
		}
		else if (opcao == 10) {
			exit = true;
		}
	}
}

void menuClienteLogado() {

	int exit = false;
	int opcao;

	while(!exit) {

		printf("\n");
		printf("1 - Iniciar compra\n");
		printf("2 - Ver carrinho de compras\n");
		printf("10 - Sair\n");

		scanf("%d", &opcao);

		if (opcao == 1) {
			imprimeMedicamentos(arvoreMedicamentos, 0);
		}
		else if (opcao == 2) {
			cadastroCliente();
		}
		else if (opcao == 10) {
			exit = true;
		}
	}
}

void menuClienteNaoLogado() {

	int exit = false;
	int opcao;

	while(!exit) {

		printf("\n");
		printf("1 - Cadastro\n");
		printf("2 - Login\n");
		printf("10 - Sair\n");

		scanf("%d", &opcao);

		if (opcao == 1) {
			cadastroCliente();
		}
		else if (opcao == 2) {
			login();
		}
		else if (opcao == 10) {
			exit = true;
		}
	}
}