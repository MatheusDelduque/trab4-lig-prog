// Linguagem de Programacao - Trabalho 04
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#include "sistema.h"

Sistema::Sistema()
{
    arvoreAtletas = new Arvore<Atleta>();
}

Sistema::~Sistema()
{
    delete arvoreAtletas;
}

// Insere um atleta na arvore
void Sistema::inserirAtleta(Atleta *atleta)
{
    try
    {
        // Insere o atleta na arvore usando a sobrecarga do operador '+'
        *arvoreAtletas = *arvoreAtletas + atleta;
    }
    catch (const std::invalid_argument &e)
    {
        // Imprime uma mensagem de erro caso o atleta ja exista
        std::cerr << "Erro ao inserir atleta: " << e.what() << std::endl;
    }
}

// Busca um atleta na arvore
Atleta *Sistema::buscarAtleta(const std::string &nome) const
{
    // Busca o atleta na arvore usando a sobrecarga do operador '()'
    Atleta *atleta = (*arvoreAtletas)(nome);
    if (atleta == nullptr)
    {
        // Lança uma exceção caso o atleta não seja encontrado
        throw std::runtime_error("Atleta '" + nome + "' não encontrado.");
    }
    return atleta;
}

// Remove um atleta da arvore
void Sistema::removerAtleta(const std::string &nome)
{
    try
    {
        // Remove o atleta da arvore usando a sobrecarga do operador '-'
        *arvoreAtletas = *arvoreAtletas - nome;

        std::cout << "Atleta removido com sucesso." << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        // Imprime uma mensagem de erro caso o atleta não seja encontrado
        std::cerr << "Erro ao remover atleta: " << e.what() << std::endl;
    }
}

// Lista todos os atletas na arvore
void Sistema::listarAtletas() const
{
    if (arvoreAtletas->estaVazia())
    {
        // Imprime uma mensagem caso a arvore esteja vazia
        std::cout << "Não há atletas na lista.\n";
    }
    else
    {
        std::cout << "Lista de Atletas:\n";
        std::cout << std::endl;
        // Imprime todos os atletas na arvore
        arvoreAtletas->imprimir();
    }
}
