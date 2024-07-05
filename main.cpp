// Linguagem de Programacao - Trabalho 04
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#include "sistema.h"
#include <iostream>
#include <string>

void mostrarMenu()
{
}

int main()
{
    Sistema sistema;
    int opcao = 0;
    std::string nome;
    int idade;
    std::string tipo, atributoEspecifico;

    while (opcao != 5)
    {
        std::cout << "\nMenu:\n"
                  << "1. Inserir Atleta\n"
                  << "2. Remover Atleta\n"
                  << "3. Buscar Atleta\n"
                  << "4. Listar todos os Atletas\n"
                  << "5. Sair\n"
                  << "Escolha uma opção: ";
        std::cin >> opcao;
        std::cin.ignore();
        std::cout << std::endl;

        switch (opcao)
        {
        case 1:
            std::cout << "Tipo de Atleta (Futebol/Judo): ";
            std::getline(std::cin, tipo);

            if (tipo != "Futebol" && tipo != "Judo")
            {
                std::cout << std::endl;
                std::cout << "Tipo de atleta desconhecido.\n";
                break;
            }

            std::cout << "Nome: ";
            std::getline(std::cin, nome);
            std::cout << "Idade: ";
            std::cin >> idade;
            std::cin.ignore();

            if (tipo == "Futebol")
            {
                std::cout << "Posição: ";
                std::getline(std::cin, atributoEspecifico);
                sistema.inserirAtleta(new AtletaFutebol(nome, idade, atributoEspecifico));
            }
            else if (tipo == "Judo")
            {
                std::cout << "Faixa: ";
                std::getline(std::cin, atributoEspecifico);
                sistema.inserirAtleta(new AtletaJudo(nome, idade, atributoEspecifico));
            }
            break;

        case 2:
            std::cout << "Nome do Atleta para remover: ";
            std::getline(std::cin, nome);
            sistema.removerAtleta(nome);
            break;

        case 3:
            std::cout << "Nome do Atleta para buscar: ";
            std::getline(std::cin, nome);
            std::cout << std::endl;
            try
            {
                Atleta *atleta = sistema.buscarAtleta(nome);
                std::cout << *atleta << std::endl;
            }
            catch (const std::runtime_error &e)
            {
                std::cerr << "Erro: " << e.what() << std::endl;
            }
            break;

        case 4:
            sistema.listarAtletas();
            break;

        case 5:
            std::cout << "Saindo...\n";
            break;

        default:
            std::cout << "Opção inválida.\n";
            break;
        }
    }

    return 0;
}
