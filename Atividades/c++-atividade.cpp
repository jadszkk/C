#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct funcionarios{
    float salario;
    float aumentosal;
    float salarionovo;
    char cargo[15];
};

funcionarios calcularsalario(){
    funcionarios dados;
    cout << "Informe o cargo: " << endl;
    cin >> dados.cargo;
    cout << "Informe o salário: " << endl;
    cin >> dados.salario;

    if (strcmp(dados.cargo,"gerente")==0){
        dados.aumentosal = 0.1*dados.salario;
        dados.salarionovo = dados.salario+dados.aumentosal;
    } else if(strcmp(dados.cargo,"engenheiro")==0){
        dados.aumentosal = 0.2*dados.salario;
        dados.salarionovo = dados.salario+dados.aumentosal;
    } else{
        dados.aumentosal = 0.4*dados.salario;
        dados.salarionovo = dados.salario+dados.aumentosal;
    }
    return dados;
}

void exibirfuncionarios(funcionarios dados[10], int cont){
    
    int quantidadeg=0;
    int quantidadee=0;
    float total=0;
    float totala=0;
    
    for (int i=0;i<cont;i++){
        cout << "   Funcionário " << i+1 << endl << "Salario novo: " << dados[i].salarionovo << endl << "Salario antigo: " << dados[i].salario << endl << "Diferença: " << dados[i].aumentosal << endl;
        cout << endl;
        if(strcmp(dados[i].cargo,"gerente")==0){
            quantidadeg= quantidadeg+1;
        } else if (strcmp(dados[i].cargo,"engenheiro")==0){
            quantidadee= quantidadee+1;
        }
        total=total+dados[i].salario;
        totala=totala+dados[i].salarionovo;
    }
    cout << "Quantidade de gerentes: " << quantidadeg << endl << "Quantidade de engenheiros: " << quantidadee << endl;
    cout << "Custo total antes do aumento: " << total << endl << "Custo total depois do aumento: " << totala;
}

int main()
{
    
    char opc[5]="sim";
    int cont=0;
    funcionarios dados[10];
    
    do{
    dados[cont]=calcularsalario();
    cont++;
    cout << "Deseja realizar a operação novamente?";
    cin >> opc;
    cout << endl;
    }while(strcmp(opc,"sim")==0);
    exibirfuncionarios(dados,cont);
    return 0;
}
