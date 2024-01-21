#include "funcionario.h"

void cadastrar(Funcionario *funcionario){
    FILE *cadastro;

    cadastro = fopen("..\\db\\funcionario.txt", "a");

    if(cadastro == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    printf("Cadastre o nome do funcionario: ");
    scanf("%s", funcionario->usuario);

    do{
        printf("Digite a senha (entre 8 e 10 caracteres): ");
        scanf("%s", funcionario->senha);
        if (strlen(funcionario->senha) < 8)
        {
            printf("Senha Curta!\nMinimo de 8 caracteres!\n");
        } else if (strlen(funcionario->senha) > 10)
        {
            printf("Senha Longa!\nMaximo de 10 caracteres!\n");
        }
    }while(strlen(funcionario->senha) < 8 || strlen(funcionario->senha) > 10);

    fprintf(cadastro, "%s\n%s\n", funcionario->usuario, funcionario->senha);

    fclose(cadastro);
}