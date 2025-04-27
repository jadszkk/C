#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class funcionarios{
	private:
    	float salario, salarionovo, aumentosal;
    	string cargo;
    	string nome;
	public:
    	void leituradedados();
    	void calcularsalario();
    	void exibirfuncionarios();
    	string getcargo() {return cargo;};
    	float getsalario() {return salario;};
    	float getsalarionovo() {return salarionovo;};
};

void funcionarios::leituradedados(){
    cout << "Informe o cargo: " << endl;
    cin >> cargo;
    cout << "Informe o salário: " << endl;
    cin >> salario;
    cout << "Informe o nome: " << endl;
    cin >> nome;
};

void funcionarios::calcularsalario(){
    
    if (cargo=="gerente"){
        aumentosal = 0.1*salario;
    } else if(cargo=="engenheiro"){
        aumentosal = 0.2*salario;
    } else{
        aumentosal = 0.4*salario;
    }
    salarionovo = salario+aumentosal;
};


void funcionarios::exibirfuncionarios(){
    
    cout << "Nome: " << nome << endl << "Cargo: " << cargo << endl << "Salario novo: " << salarionovo << endl << "Salario antigo: " << salario << endl << "Diferença: " << aumentosal << endl;
    cout << endl;
    
};

int main()
{
    string opc="sim";
    int cont=0;
    funcionarios dados[10];
    int quantidadeg=0;
    int quantidadee=0;
    float total=0;
    float totala=0;
    
    do{
    dados[cont].leituradedados();
    dados[cont].calcularsalario();
    cont++;
    cout << "Deseja realizar a operação novamente?";
    cin >> opc;
    cout << endl;
    }while(opc=="sim");
    
    for (int i=0; i<cont; i++){
        cout << "Funcionário " << i + 1 << endl;
        dados[i].exibirfuncionarios();
        
        if(dados[i].getcargo()=="gerente"){
        quantidadeg=quantidadeg + 1;
        } else if (dados[i].getcargo()=="engenheiro"){
            quantidadee=quantidadee + 1;
        }
        
        total=total+dados[i].getsalario();
        totala=totala+dados[i].getsalarionovo();
    }
    
    cout << "Quantidade de gerentes: " << quantidadeg << endl << "Quantidade de engenheiros: " << quantidadee << endl;
    cout << "Custo total antes do aumento: " << total << endl << "Custo total depois do aumento: " << totala;
    
    return 0;
}
