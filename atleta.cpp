// Linguagem de Programacao - Trabalho 04
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#include "atleta.h"

// Implementação do construtor da classe Atleta
Atleta::Atleta(const std::string& nome, int idade) : nome(nome), idade(idade) {}

// Sobrecarga do operador '<<' para imprimir informações do atleta
std::ostream& operator<<(std::ostream& out, const Atleta& atleta) {
    atleta.imprimirInformacoes(out);  // Chama o método virtual puro para imprimir as informações específicas do atleta
    return out;
}

// Implementação do construtor da classe AtletaFutebol
AtletaFutebol::AtletaFutebol(const std::string& nome, int idade, const std::string& posicao)
    : Atleta(nome, idade), posicao(posicao) {}

// Implementação do método para imprimir informações do atleta de futebol
void AtletaFutebol::imprimirInformacoes(std::ostream& out) const {
    out << getTipoEsporte() << " - Nome: " << nome << ", Idade: " << idade << ", Posição: " << posicao;
}

// Sobrecarga do operador '<<' para imprimir informações do atleta de futebol
std::ostream& operator<<(std::ostream& out, const AtletaFutebol& atleta) {
    atleta.imprimirInformacoes(out);
    return out;
}

// Implementação do construtor da classe AtletaJudo
AtletaJudo::AtletaJudo(const std::string& nome, int idade, const std::string& faixa)
    : Atleta(nome, idade), faixa(faixa) {}

// Implementação do método para imprimir informações do atleta de judô
void AtletaJudo::imprimirInformacoes(std::ostream& out) const {
    out << getTipoEsporte() << " - Nome: " << nome << ", Idade: " << idade << ", Faixa: " << faixa;
}

// Sobrecarga do operador '<<' para imprimir informações do atleta de judô
std::ostream& operator<<(std::ostream& out, const AtletaJudo& atleta) {
    atleta.imprimirInformacoes(out);
    return out;
}
