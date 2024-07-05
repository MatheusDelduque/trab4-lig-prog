// Linguagem de Programacao - Trabalho 04
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "atleta.h"

// Declaracao da classe template No
template <class T>
class No
{
public:
    T *informacoes;
    No *esquerda;
    No *direita;

    No(T *val) : informacoes(val), esquerda(nullptr), direita(nullptr) {}
};

// Declaracao da classe template Arvore
template <class T>
class Arvore
{
private:
    // Ponteiro para a raiz da arvore
    No<T> *raiz;

    // Fucao auxiliar para inserir um no na arvore
    void inserirAuxiliar(No<T> *&no, T *val);
    // Funcao auxiliar para imprimir a árvore
    void imprimirAuxiliar(No<T> *no, std::ostream &out) const;
    // Funcao auxiliar para buscar um no na arvore
    T *buscarAuxiliar(No<T> *no, const std::string &nome) const;
    // Funcao auxiliar para remover um no da arvore
    No<T> *removerAuxiliar(No<T> *no, const std::string &nome);
    // Funcao auxiliar para deletar a arvore
    void deletarArvore(No<T> *no);

public:
    Arvore() : raiz(nullptr) {}
    ~Arvore() { deletarArvore(raiz); }

    // Verifica se a arvore esta vazia
    bool estaVazia() const { return raiz == nullptr; }
    // Sobrecarga do operador '+' para inserir um no na arvore
    Arvore<T> &operator+(T *val);
    // Sobrecarga do operador '-' para remover um no da arvore
    Arvore<T> &operator-(const std::string &nome);
    // Sobrecarga do operador '()' para buscar um no na arvore
    T *operator()(const std::string &nome) const;

    // Insere um no na arvore
    void inserir(T *val);
    // Remove um no da arvore
    void remover(const std::string &nome);
    // Imprime a arvore
    void imprimir() const;

    // Sobrecarga do operador '<<' para imprimir a arvore
    friend std::ostream &operator<<(std::ostream &out, const Arvore<T> &arvore)
    {
        arvore.imprimir();
        return out;
    }
};

// Funcao auxiliar para deletar a arvore
template <class T>
void Arvore<T>::deletarArvore(No<T> *no)
{
    if (no != nullptr)
    {
        deletarArvore(no->esquerda);
        deletarArvore(no->direita);
        delete no;
    }
}

// Sobrecarga do operador '+' para inserir um no na arvore
template <class T>
Arvore<T> &Arvore<T>::operator+(T *val)
{
    inserir(val);
    return *this;
}

// Sobrecarga do operador '-' para remover um no da arvore
template <class T>
Arvore<T> &Arvore<T>::operator-(const std::string &nome)
{
    remover(nome);
    return *this;
}

// Insere um no na arvore
template <class T>
void Arvore<T>::inserir(T *val)
{
    inserirAuxiliar(raiz, val);
}

// Funcao auxiliar para inserir um no na arvore
template <class T>
void Arvore<T>::inserirAuxiliar(No<T> *&no, T *val)
{
    if (no == nullptr)
    {
        no = new No<T>(val);
    }
    else
    {
        if (*val < *(no->informacoes))
        {
            inserirAuxiliar(no->esquerda, val);
        }
        else if (*(no->informacoes) < *val)
        {
            inserirAuxiliar(no->direita, val);
        }
        else
        {
            throw std::invalid_argument("Atleta com mesmo nome já existe na árvore.");
        }
    }
}

// Sobrecarga do operador '()' para buscar um no na arvore
template <class T>
T *Arvore<T>::operator()(const std::string &nome) const
{
    return buscarAuxiliar(raiz, nome);
}

// Funcao auxiliar para buscar um no na arvore
template <class T>
T *Arvore<T>::buscarAuxiliar(No<T> *no, const std::string &nome) const
{
    if (no == nullptr)
    {
        return nullptr;
    }
    else if (no->informacoes->getNome() == nome)
    {
        return no->informacoes;
    }
    else if (nome < no->informacoes->getNome())
    {
        return buscarAuxiliar(no->esquerda, nome);
    }
    else
    {
        return buscarAuxiliar(no->direita, nome);
    }
}

// Remove um no da arvore
template <class T>
void Arvore<T>::remover(const std::string &nome)
{
    raiz = removerAuxiliar(raiz, nome);
}

// Funcao auxiliar para remover um no da arvore
template <class T>
No<T> *Arvore<T>::removerAuxiliar(No<T> *no, const std::string &nome)
{
    if (no == nullptr)
    {
        throw std::invalid_argument("Atleta não encontrado na árvore.");
    }

    if (nome < no->informacoes->getNome())
    {
        no->esquerda = removerAuxiliar(no->esquerda, nome);
    }
    else if (nome > no->informacoes->getNome())
    {
        no->direita = removerAuxiliar(no->direita, nome);
    }
    else
    {
        if (no->esquerda == nullptr && no->direita == nullptr)
        {
            delete no;
            return nullptr;
        }
        else if (no->esquerda == nullptr)
        {
            No<T> *temporario = no->direita;
            no->direita = nullptr;
            delete no;
            return temporario;
        }
        else if (no->direita == nullptr)
        {
            No<T> *temporario = no->esquerda;
            no->esquerda = nullptr;
            delete no;
            return temporario;
        }
        else
        {
            No<T> *temporario = no->direita;
            while (temporario->esquerda != nullptr)
            {
                temporario = temporario->esquerda;
            }
            no->informacoes = temporario->informacoes;
            no->direita = removerAuxiliar(no->direita, temporario->informacoes->getNome());
        }
    }
    return no;
}

// Imprime a arvore
template <class T>
void Arvore<T>::imprimir() const
{
    imprimirAuxiliar(raiz, std::cout);
}

// Funcao auxiliar para imprimir a arvore
template <class T>
void Arvore<T>::imprimirAuxiliar(No<T> *no, std::ostream &out) const
{
    if (no != nullptr)
    {
        imprimirAuxiliar(no->esquerda, out);
        out << *(no->informacoes) << std::endl;
        imprimirAuxiliar(no->direita, out);
    }
}

// Instanciacao explocita do template para evitar erros de linguagem
template class Arvore<Atleta>;

#endif // ARVORE_H