// Linguagem de Programacao - Trabalho 04
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#ifndef ATLETA_H
#define ATLETA_H

#include <string>
#include <iostream>

// Declaração da classe base Atleta
class Atleta
{
public:
    Atleta(const std::string &nome, int idade);
    virtual ~Atleta() = default;

    std::string getNome() const { return nome; }
    int getIdade() const { return idade; }

    // Método virtual puro para obter o tipo de esporte
    virtual std::string getTipoEsporte() const = 0;

    // Sobrecarga do operador '<' para comparar atletas pelo nome
    bool operator<(const Atleta &other) const { return nome < other.nome; }

    // Sobrecarga do operador '<<' para imprimir informações do atleta
    friend std::ostream &operator<<(std::ostream &out, const Atleta &atleta);

    // Método virtual puro para imprimir informações do atleta
    virtual void imprimirInformacoes(std::ostream &out) const = 0;

protected:
    std::string nome;
    int idade;
};

// Declaração da classe derivada AtletaFutebol
class AtletaFutebol : public Atleta
{
public:
    AtletaFutebol(const std::string &nome, int idade, const std::string &posicao);

    virtual std::string getTipoEsporte() const override { return "Futebol"; }

    // Sobrecarga do operador '<<' para imprimir informações do atleta de futebol
    friend std::ostream &operator<<(std::ostream &out, const AtletaFutebol &atleta);
    // Implementação do método virtual puro para imprimir informações do atleta de futebol
    virtual void imprimirInformacoes(std::ostream &out) const override;

private:
    std::string posicao;
};

// Declaração da classe derivada AtletaJudo
class AtletaJudo : public Atleta
{
private:
    std::string faixa;

public:
    AtletaJudo(const std::string &nome, int idade, const std::string &faixa);
    virtual std::string getTipoEsporte() const override { return "Judô"; }

    // Sobrecarga do operador '<<' para imprimir informações do atleta de judô
    friend std::ostream &operator<<(std::ostream &out, const AtletaJudo &atleta);

    // Implementação do método virtual puro para imprimir informações do atleta de judô
    virtual void imprimirInformacoes(std::ostream &out) const override;
};

#endif // ATLETA_H
