#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <iostream>


typedef struct result {
    double total;
    int erro;
    char *msg;
}result;

class calculadora
{
private:
    /* data */
public:
    calculadora(/* args */);
    ~calculadora();

    void somar();
    void subtrair();
    void multiplicar();
    void dividir();
    void potencia();
    void raiz();
    void fatorial();
    void logaritmo();
    void XOR();
    void OR();
    void AND();
    void invert(); 
    void shiftRight();
    void shiftLeft();
    void binarioDecimal();
    void decimalBinario();
    void decimalHexadecimal();
    void hexadecimalDecimal();
    void hexadecimalBinario();
    void binarioHexadecimal();
    void hexadecimalOctal();
    void octalHexadecimal();
    void octalDecimal();
    void decimalOctal();
    void binarioOctal();
    void octalBinario();
    void binarioDecimal();
    void decimalBinario();
    void binarioHexadecimal();
    
};

calculadora::calculadora(/* args */)
{

}

calculadora::~calculadora()
{
    std::cout << "Destruido" << "\n";
}


#endif CALCULADORA_H