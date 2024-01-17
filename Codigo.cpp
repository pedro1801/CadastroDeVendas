#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#define TAM 100
using namespace std;
//Gera as Estruturas de dados para armazenar os clientes produtos e as vendas
struct Cliente
{
    char nome[50];
    int codigo;
    float cartao;
    int compras;
};
struct Produtos
{
    char nome[50];
    int codigo;
    float preco;
    int qtd;
};
struct Vendas
{
    int codigo;
    float preco;
    int qtd;
    char nome[50];
};
//Funções de busca de clientes e produtos
int BuscaCliente(struct Cliente *Cliente, int tamanho, int op, int codigo, char cliente[50]);
int BuscaProdutos(struct Produtos *Produtos, int tamanho, int op, int codigo, char NomeProduto[50]);
int main()
{
    //Declaração de variaveis
    char nome[50];
    int op, pos, pos2, pos3, codigo, op2, qtd, posProduto, posCliente, codigoVendas;
    float valorTotalVendas;
    valorTotalVendas = 0;
    op = -1;
    pos = 0;
    pos2 = 0;
    pos3 = 0;
    codigoVendas = 0;

    struct Vendas *novoVenda = (struct Vendas *)malloc(TAM * sizeof(struct Vendas));
    struct Cliente *novoCliente = (struct Cliente *)malloc(TAM * sizeof(struct Cliente));
    struct Produtos *novoProduto = (struct Produtos *)malloc(TAM * sizeof(struct Produtos));
    //Faz o Programa rodar infinitamente até que o usuario digite 0
    while (op != 0)
    {
        //Mostar as opções na tela
        cout << "Cadastro Cliente:1\nCadastro Produto:2\nVendas:3\nEstoque:4\nBusaca de Cliente:5\nRelatorio:6\nSair:0" << endl;
        cout << "Escolha a sua opcao:";
        cin >> op;//Recebe o operador
        switch (op)
        {
        // Se o op for = 0 encerra o programa
        case 0:
            op = 0;
            free(novoCliente);
            free(novoProduto);
            free(novoVenda);
            break;
        //Parte para o cadastro do cliente
        case 1:
            system("cls");
            cout << "Nome Cliente:";
            cin.ignore(); // Descarta o caractere de nova linha pendente
            cin.getline(novoCliente[pos].nome, 50);//Recebe o nome digitado pelo usuario
            cout << "Codigo Cliente:";
            cin >> novoCliente[pos].codigo;//Recebe o codigo digitado pelo usuario
            //Verifica se o codigo fornecido já existe
            if (pos > 0)
            {
                //Serve para passar por todas as posições da estrutura
                for (int i = 0; i < pos; i++)
                {
                    //verfica se o existe algum codigo igual
                    if (novoCliente[pos].codigo == novoCliente[i].codigo)
                    {
                        cout << "Codigo Existente" << endl;
                        cout << "Insira outro Codgio:";
                        cin >> novoCliente[pos].codigo;//se existir codigo igual ele pede para inserir outro
                    }
                }
            }
            novoCliente[pos].compras = 0;//Coloca a quantidade de compras do cliente em 0
            novoCliente[pos].cartao = 0;//Coloca o valor do cartao do cliente em 0
            pos++;//adiciona + 1 na posições
            system("cls");
            break;

        case 2:
            //Cadastro dos Produtos
            system("cls");
            cout << "Nome Produto:";
            cin.ignore(); // Descarta o caractere de nova linha pendente
            cin.getline(novoProduto[pos2].nome, 50);//Recebe o nome do produto informado pelo usuario
            cout << "Codigo Produto:";
            cin >> novoProduto[pos2].codigo;//recebe o codigo
            //Verifica se o codigo fornecido já existe
            if (pos2 > 0)
            {
                //Serve para passar por todas as posições da estrutura
                for (int i = 0; i < pos2; i++)
                {
                    //verfica se o existe algum codigo igual
                    if (novoCliente[pos2].codigo == novoCliente[i].codigo)
                    {
                        cout << "Codigo Existente" << endl;
                        cout << "Insira outro Codgio:";
                        cin >> novoProduto[pos2].codigo;//se existir codigo igual ele pede para inserir outro
                    }
                }
            }
            cout << "Valor Produto:";
            cin >> novoProduto[pos2].preco;//Recebe o valor do produto informado pelo usuario
            cout << "Quantidade:";
            cin >> novoProduto[pos2].qtd;//Recebe a quantidade do produto informado pelo usuario
            pos2++;//adiciona + 1 na posições
            system("cls");
            break;

        case 3:
            //Venda de Produtos
            system("cls");
            //Declaração de variaveis
            int op3, vendas, qtdPro;
            float valorVenda;
            qtdPro = 0;//inicializa como 0
            vendas = 0;//inicializa como 0
            valorVenda = 0;//inicializa como 0
            //Se for diferente de 0 ele ira continuar vendendo produtos
            while (vendas != 1)
            {
                system("cls");
                cout << "Finalizar Vendas:1\nVender Produto:2" << endl;
                cout << "Escolha Sua Opcao:";
                cin >> vendas;//recebe o operador que o usuario escolher
                if (vendas == 1)
                    break;
                cout << "Codigo do Produto a ser vendido:";//Pergunta o codigo do produto que o usuario quer vender
                cin >> codigo;
                op2 = 1;
                posProduto = BuscaProdutos(novoProduto, pos2, op2, codigo, nome);//busca a posição do produto a ser vendido
                //verifica se o produto tem estoque
                if (novoProduto[posProduto].qtd == 0)
                {
                    system("cls");
                    cout << "Produto Sem Estoque" << endl;
                    system("pause");
                }
                //se tiver estoque
                else
                {
                    qtdPro++;//adiciona + 1 a quantidade de produtos
                    valorVenda = valorVenda + novoProduto[posProduto].preco;//adiciona o valor do produto ao valor da venda
                    novoProduto[posProduto].qtd = novoProduto[posProduto].qtd - 1;//reduz a quantidade do estoque
                }
            }
            //se o valor da venda for == 0 ele finaliza
            if (valorVenda == 0)
            {
                break;
            }
            //Caso o Tenha um valor ira para finalização da venda
            else
            {
                system("cls");
                cout << "Avista/Cartao Debito:1\nCartao Loja:2" << endl;
                cout << "Escolha Sua Opcao:";//Recebe a opção do usuario
                cin >> op3;

                //Se for = a 1 ira passar a venda a vista
                if (op3 == 1)
                {
                    system("cls");
                    cout << "Valor da Venda:" << valorVenda << endl;
                    //ira cirar uma nova estrutura e salvar cada venda
                    novoVenda[pos3].codigo = codigoVendas++;
                    novoVenda[pos3].preco = valorVenda;
                    novoVenda[pos3].qtd = qtdPro;
                    strcpy(novoVenda[pos3].nome, "Venda Avista");
                    valorTotalVendas = valorTotalVendas + valorVenda;
                    pos3++;
                }
                //venda por cliente
                else
                {
                    system("cls");
                    cout << "Codigo Cliente:";
                    cin >> codigo;//pergunta o codigo do cliente para efetuar a venda
                    op2 = 1;
                    posCliente = BuscaCliente(novoCliente, pos, op2, codigo, nome);//busca a posição do cliente na estrutura
                    novoCliente[posCliente].cartao = novoCliente[posCliente].cartao + valorVenda;//adiciona o valor ao cartao do cliente
                    novoCliente[posCliente].compras = novoCliente[posCliente].compras + 1;//adiciona +1 as compras do cliente
                    //adiciona os valores na estrutura de vendas
                    novoVenda[pos3].codigo = codigoVendas++;
                    novoVenda[pos3].preco = valorVenda;
                    novoVenda[pos3].qtd = qtdPro;
                    strcpy(novoVenda[pos3].nome, novoCliente[posCliente].nome);
                    pos3++;
                    valorTotalVendas = valorTotalVendas + valorVenda;
                    cout << "Valor De:" << valorVenda << "Foi Atribuido Ao Cartao Do Cliente:" << novoCliente[posCliente].nome << endl;
                }
            }
            system("pause");
            system("cls");
            break;

        case 4:
            //Estoque
            system("cls");
            cout << "Conferir Estoque:1\nAlterar Estoque:2" << endl;
            cout << "Escolha a opcao:";
            cin >> op2;//Recebe a opção do usuario
            //Retorna o estoque do produto
            if (op2 == 1)
            {
                system("cls");
                op2 = 0;
                cout << "Busca por codigo:1\nBusca por nome:2\n";
                cout << "Escolha a opcao:";
                cin >> op2;//Recebe a opção do usuario
                //Busca por codigo
                if (op2 == 1)
                {
                    system("cls");
                    cout << "Informe o Codigo:";
                    cin >> codigo;
                    strcpy(nome, "NULL");
                }
                //Busca por nome do produto
                else
                {
                    system("cls");
                    cout << "Informe o Nome do Produto:";
                    cin.ignore();
                    cin.getline(nome,50);
                    codigo = 0;
                }
                posProduto = BuscaProdutos(novoProduto, pos2, op2, codigo, nome);//retorna a posição do produto
                cout << "Nome:" << novoProduto[posProduto].nome << endl;
                cout << "Codigo:" << novoProduto[posProduto].codigo << endl;
                cout << "Preoco Produto:" << novoProduto[posProduto].preco << endl;
                cout << "Quantidade no Estoque:" << novoProduto[posProduto].qtd << endl;
            }
            //Altera o estoque do produto
            else
            {
                system("cls");
                op2 = 0;
                cout << "Busca por codigo:1\nBusca por nome:2\n";
                cout << "Escolha a opcao:";
                cin >> op2;//Recebe a opção do usuario
                //Busca por codigo
                if (op2 == 1)
                {
                    system("cls");
                    int qtd2;
                    cout << "Informe o Codigo:";
                    cin >> codigo;
                    strcpy(nome, "NULL");
                    posProduto = BuscaProdutos(novoProduto, pos2, op2, codigo, nome);
                    cout << "Informe a quantidade:";
                    cin >> qtd2;//recebe a nova quantidade do produto
                    //se a quantidade for diferente de zero ira somar a quantidade do estoque mas a informada
                    if (novoProduto[posProduto].qtd != 0)
                    {
                        qtd2 = novoProduto[posProduto].qtd + qtd2;
                        novoProduto[posProduto].qtd = qtd2;
                    }
                    //se estiver zerada atribui a qtd ao estoque
                    else
                    {
                        novoProduto[posProduto].qtd = qtd2;
                    }
                }
                //repete os mesmo processo so que com o nome do produto
                else
                {
                    system("cls");
                    cout << "Informe o nome:";
                    cin.ignore();
                    cin.getline(nome,50);
                    codigo = 0;
                    posProduto = BuscaProdutos(novoProduto, pos2, op2, codigo, nome);
                    cout << "Informe a quantidade:";
                    cin >> qtd;
                    if (novoProduto[posProduto].qtd != 0)
                    {
                        int qtd2;
                        qtd2 = novoProduto[posProduto].qtd;
                        qtd = qtd + qtd2;
                        novoProduto[posProduto].qtd = qtd;
                    }
                    else
                    {
                        novoProduto[posProduto].qtd = qtd;
                    }
                }
            }
            system("pause");
            system("cls");
            // Estoque
            break;
        //busca de clientes
        case 5:
            system("cls");
            cout << "Busca por codigo:1\nBusca por nome:2\n";
            cout << "Escolha a opcao:";
            cin >> op2;//recebe o numero informado pelo usuario
            //busca por codigo
            if (op2 == 1)
            {
                system("cls");
                cout << "Informe o Codigo:";
                cin >> codigo;
                strcpy(nome, "NULL");
            }
            //busca por nome
            else
            {
                system("cls");
                cout << "Informe o Nome:";
                cin.ignore();
                cin.getline(nome,50);
                codigo = 0;
            }
            posCliente = BuscaCliente(novoCliente, pos, op2, codigo, nome);
            cout << "Nome:" << novoCliente[posCliente].nome << endl;
            cout << "Codigo:" << novoCliente[posCliente].codigo << endl;
            cout << "Valor Cartao:" << novoCliente[posCliente].cartao << endl;
            system("pause");
            system("cls");
            break;

        case 6:
            //gera os relatorios
            int op4;
            op4 = 0;
            system("cls");
            cout << "Relatorio Clientes:1\nTotal de vendas do empreendimento:2\nTotal de vendas por cliente:3" << endl;
            cout << "Escolha sua Opcao:";
            cin >> op4;//recebe o numero informado pelo usuario
            if (op4 == 1)
            {
                ofstream arquivo("../Relatorios/RelatorioClientes.txt");//abre o arquivo
                //se o arquivo estiver abertor ele ira escrever 
                if (arquivo.is_open())
                {
                    //Escreve dentro do arquivo pela posição de cada cliente
                    for (int i = 0; i < pos; i++)
                    {   
                        arquivo << "|==============================================|" << endl;
                        arquivo << "|Codigo:" << novoCliente[i].codigo << endl;
                        arquivo << "|Nome:" << novoCliente[i].nome << endl;
                        arquivo << "|Valor do Cartao:" << novoCliente[i].cartao << endl;
                        arquivo << "|==============================================|" << endl;
                    }
                }
                //salva o arquivo
                arquivo.close();
            }
            else if (op4 == 2)
            {
                ofstream arquivo("../Relatorios/RelatorioTotalVendas.txt");
                if (arquivo.is_open())
                {
                    for (int i = 0; i < pos3; i++)
                    {
                        arquivo << "|==============================================|" << endl;
                        arquivo << "|Codigo:" << novoVenda[i].codigo << endl;
                        arquivo << "|Valor da venda:" << novoVenda[i].preco << endl;
                        arquivo << "|Total de Itens:" << novoVenda[i].qtd << endl;
                        arquivo << "|Nome do Cleiente:" << novoVenda[i].nome << endl;
                        arquivo << "|==============================================|" << endl;
                    }
                    arquivo << "|==============================================|" << endl;
                    arquivo << "|Valor Toltal das Vendas:" << valorTotalVendas << endl;
                    arquivo << "|==============================================|" << endl;
                }
                arquivo.close();
            }
            else
            {
                ofstream arquivo("../Relatorios/RelatorioVendasPorClientes.txt");
                if (arquivo.is_open())
                {
                    for (int i = 0; i < pos; i++)
                    {

                        arquivo << "|==============================================|" << endl;
                        arquivo << "|Codigo:" << novoCliente[i].codigo << endl;
                        arquivo << "|Nome:" << novoCliente[i].nome << endl;
                        arquivo << "|Valor do Cartao:" << novoCliente[i].cartao << endl;
                        arquivo << "|Total de Compras:" << novoCliente[i].compras << endl;
                        arquivo << "|==============================================|" << endl;
                    }
                    arquivo << "|==============================================|" << endl;
                    arquivo << "|Valor Toltal das Vendas" << valorTotalVendas << endl;
                    arquivo << "|==============================================|" << endl;
                }
                arquivo.close();
            }
            system("pause");
            system("cls");
            break;
        default:
            break;
        }
    }
    return 0;
}

int BuscaProdutos(struct Produtos *Produtos, int tamanho, int op, int codigo, char NomeProduto[50])
{
    int posProduto;
    if (op == 1)
    {
        for (int i = 0; i < tamanho; i++)
        {
            if (Produtos[i].codigo == codigo)
            {
                posProduto = i;
            }
        }
    }
    else
    {
        for (int i = 0; i < tamanho; i++)
        {
            if (strcmp(Produtos[i].nome, NomeProduto) == 0)
            {
                posProduto = i;
            }
        }
    }
    return posProduto;
}

int BuscaCliente(struct Cliente *cliente1, int tamanho, int op, int codigo, char cliente[50])
{
    int posCliente;
    if (op == 1)
    {
        for (int i = 0; i < tamanho; i++)
        {
            if (cliente1[i].codigo == codigo)
            {
                posCliente = i;
            }
        }
    }
    else
    {
        for (int i = 0; i < tamanho; i++)
        {
            if (strcmp(cliente1[i].nome, cliente) == 0)
            {
                posCliente = i;
            }
        }
    }
    return posCliente;
}