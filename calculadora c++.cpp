#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// 1. Resolução da Equação do 2º Grau (Bhaskara)
void resolverBhaskara() {
    double a, b, c;
    cout << "\n--- Equacao do 2º Grau (ax² + bx + c = 0) ---\n";
    cout << "Digite os coeficientes a, b e c: ";
    cin >> a >> b >> c;

    if (a == 0) {
        cout << "[Erro] O coeficiente 'a' não pode ser zero (não é 2º grau).\n";
        return;
    }

    double delta = (b * b) - (4 * a * c);
    cout << "Delta (Δ) = " << delta << "\n";

    if (delta < 0) {
        cout << "A equação não possui raízes reais (Δ < 0).\n";
    } else if (delta == 0) {
        double x = -b / (2 * a);
        cout << "Raiz única (x1 = x2) = " << fixed << setprecision(4) << x << "\n";
    } else {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "Raiz 1 (x1) = " << fixed << setprecision(4) << x1 << "\n";
        cout << "Raiz 2 (x2) = " << fixed << setprecision(4) << x2 << "\n";
    }
}

// Função auxiliar para cálculo de fatorial
unsigned long long calcularFatorial(int n) {
    if (n < 0) return 0;
    if (n == 0 || n == 1) return 1;
    unsigned long long fat = 1;
    for (int i = 2; i <= n; ++i) {
        fat *= i;
    }
    return fat;
}

// 2. Cálculo de Combinação Simples C(n, k)
void calcularCombinatoria() {
    int n, k;
    cout << "\n--- Combinação Simples C(n, k) ---\n";
    cout << "Digite o valor de n e k (n >= k >= 0): ";
    cin >> n >> k;

    if (n < k || n < 0 || k < 0) {
        cout << "[Erro] Valores inválidos! Certifique-se de que n >= k >= 0.\n";
        return;
    }

    unsigned long long numerador = calcularFatorial(n);
    unsigned long long denominador = calcularFatorial(k) * calcularFatorial(n - k);
    
    if (denominador == 0) {
        cout << "[Erro] Divisão por zero no denominador.\n";
        return;
    }

    unsigned long long resultado = numerador / denominador;
    cout << "Resultado de C(" << n << ", " << k << ") = " << resultado << "\n";
}

// 3. Cálculo de Áreas Geométricas
void calcularAreas() {
    int opcao;
    cout << "\n--- Cálculo de Áreas ---\n";
    cout << "1. Círculo\n";
    cout << "2. Triângulo\n";
    cout << "3. Retângulo\n";
    cout << "Escolha uma opção: ";
    cin >> opcao;

    if (opcao == 1) {
        double r;
        cout << "Digite o raio do círculo: ";
        cin >> r;
        if (r < 0) { cout << "[Erro] O raio não pode ser negativo.\n"; return; }
        double area = M_PI * r * r;
        cout << "Área do Círculo = " << fixed << setprecision(4) << area << "\n";
    } 
    else if (opcao == 2) {
        double b, h;
        cout << "Digite a base e a altura do triângulo: ";
        cin >> b >> h;
        if (b < 0 || h < 0) { cout << "[Erro] Valores não podem ser negativos.\n"; return; }
        double area = (b * h) / 2.0;
        cout << "Área do Triângulo = " << fixed << setprecision(4) << area << "\n";
    } 
    else if (opcao == 3) {
        double b, h;
        cout << "Digite a base e a altura do retângulo: ";
        cin >> b >> h;
        if (b < 0 || h < 0) { cout << "[Erro] Valores não podem ser negativos.\n"; return; }
        double area = b * h;
        cout << "Área do Retângulo = " << fixed << setprecision(4) << area << "\n";
    } 
    else {
        cout << "Opção inválida!\n";
    }
}

// Função Principal (Menu)
int main() {
    int escolha;
    do {
        cout << "\n========================================\n";
        cout << "     TOOLKIT DE RESOLUÇÃO MATEMÁTICA    \n";
        cout << "========================================\n";
        cout << "1. Resolver Equação do 2º Grau (Bhaskara)\n";
        cout << "2. Calcular Combinação Simples C(n, k)\n";
        cout << "3. Calcular Áreas Geométricas\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                resolverBhaskara();
                break;
            case 2:
                calcularCombinatoria();
                break;
            case 3:
                calcularAreas();
                break;
            case 0:
                cout << "Encerrando o programa. Até mais!\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (escolha != 0);

    return 0;
}