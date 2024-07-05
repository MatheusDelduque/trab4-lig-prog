// Linguagem de Programacao - Trabalho 04
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#ifndef SISTEMA_H
#define SISTEMA_H

#include "arvore.h"
#include "atleta.h"
#include <stdexcept>
#include <string>

// Declaracao da classe Sistema
class Sistema
{
private:
    Arvore<Atleta> *arvoreAtletas;

public:
    Sistema();
    ~Sistema();
    // Insere um atleta na arvore
    void inserirAtleta(Atleta *atleta);
    // Busca um atleta na arvore
    Atleta *buscarAtleta(const std::string &nome) const;
    // Remove um atleta da arvore
    void removerAtleta(const std::string &nome);
    // Lista todos os atletas na arvore
    void listarAtletas() const;
};

#endif // SISTEMA_H
