#include <iostream>
#include "outrosArquivos\mecanicas.cpp"
#include "outrosArquivos\jogadores.cpp"
using namespace std;

//definir que jogador ser� o primeiro
int escolhaAleatoria(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, 1);
    int escolha = distr(gen);
    return escolha;
};

int main(){
    ClasseMecanicas objetoMecanicas;
    JogadorHumano objetoJogador;
    JogadorMaquina objetoCpu;
    bool jogoFinalizado = false;
    int escolhaJogador, escolhaCpu;
    objetoMecanicas.mostrarCasas();
    //0 = jogador come�a, 0 = jogador come�a
    int jogadorIniciante = escolhaAleatoria();
    if(jogadorIniciante == 0){
       while(jogoFinalizado == false){
            escolhaJogador = escolhaCpu = 0;
            while(escolhaJogador < 1 || escolhaJogador > 9){
                objetoJogador.fazerEscolha();
                escolhaJogador = objetoJogador.retornarEscolha();
                if(objetoMecanicas.alterarCasa((escolhaJogador - 1), "humano") == false){
                    cout << "Esta casa n�o est� mais dispon�vel!\n"; 
                    escolhaJogador = 0;
                };
            };
            objetoMecanicas.mostrarCasas();
            jogoFinalizado = objetoMecanicas.checarFinal();
            if(jogoFinalizado == true){break;}
            else{
                while(escolhaCpu < 1 || escolhaCpu > 9){
                    objetoCpu.fazerEscolha();
                    escolhaCpu = objetoCpu.retornarEscolha();
                    if(objetoMecanicas.alterarCasa((escolhaCpu - 1), "cpu") == false){escolhaCpu = 0;};
                };
                objetoMecanicas.mostrarCasas();
                jogoFinalizado = objetoMecanicas.checarFinal();
            };
        };
    }
    else{
       while(jogoFinalizado == false){
            escolhaJogador = escolhaCpu = 0;
            while(escolhaCpu < 1 || escolhaCpu > 9){
                objetoCpu.fazerEscolha();
                escolhaCpu = objetoCpu.retornarEscolha();
                if(objetoMecanicas.alterarCasa((escolhaCpu - 1), "cpu") == false){
                    escolhaCpu = 0;
                };
            };
            objetoMecanicas.mostrarCasas();
            jogoFinalizado = objetoMecanicas.checarFinal();
            if(jogoFinalizado == true){break;}
            else{
                while(escolhaJogador < 1 || escolhaJogador > 9){
                    objetoJogador.fazerEscolha();
                    escolhaJogador = objetoJogador.retornarEscolha();
                    if(objetoMecanicas.alterarCasa((escolhaJogador - 1), "humano") == false){
                        cout << "Esta casa n�o est� mais dispon�vel!\n"; 
                        escolhaJogador = 0;
                    };
                };
                objetoMecanicas.mostrarCasas();
                jogoFinalizado = objetoMecanicas.checarFinal();
            };
        };
    };
    return 0;
};