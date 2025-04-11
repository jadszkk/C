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


int main()
{
    //float salario;
    //float aumentosal;
    //float salarionovo;
    //char cargo[15];
    char opc[5]="sim";
    int cont=0;
    funcionarios dados[10];
    int quantidadeg=0;
    int quantidadee=0;
    float total=0;
    float totala=0;
    int qnt;
    
    do{
    //while(strcmp(opc,"sim")==0){
    //cout << "Digite a quantidade de funcionarios: " << qnt;
    //for(int a=0;a<qnt;a++){
    cout << "Informe o cargo: " << endl;
    cin >> dados[cont].cargo;
    cout << "Informe o salário: " << endl;
    cin >> dados[cont].salario;

    if (strcmp(dados[cont].cargo,"gerente")==0){
        dados[cont].aumentosal = 0.1*dados[cont].salario;
        dados[cont].salarionovo = dados[cont].salario+dados[cont].aumentosal;
    } else if(strcmp(dados[cont].cargo,"engenheiro")==0){
        dados[cont].aumentosal = 0.2*dados[cont].salario;
        dados[cont].salarionovo = dados[cont].salario+dados[cont].aumentosal;
    } else{
        dados[cont].aumentosal = 0.4*dados[cont].salario;
        dados[cont].salarionovo = dados[cont].salario+dados[cont].aumentosal;
    }
    cont++;
    //cout << "Salario novo: " << dados[cont].salarionovo << endl << "Salario antigo: " << dados[cont].salario << endl << "Diferença: " << dados[cont].aumentosal << endl;
    cout << "Deseja realizar a operação novamente?";
    cin >> opc;
    cout << endl;
    //}
    }while(strcmp(opc,"sim")==0);
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
    return 0;
}

