#include <iostream>

#include <random>

using namespace std;

//classe pai

class ClasseJogadores{
    
	public:
        
		//variável que indica a casa escolhida
        
		int escolhaFeita = 10;
        
        
		//retornar a escolha feita
        
		int retornarEscolha(){
            
			return escolhaFeita;
        
		};

};

//classe para o jogador humano

class JogadorHumano: public ClasseJogadores{
    
	public:
        
		//definir a escolha do jogador
        
		void fazerEscolha(){
            
			escolhaFeita = 0;
            
			while(escolhaFeita < 1 || escolhaFeita > 9){
                
				cout << "\nescolha uma das casas disponíveis: ";
                
				cin >> escolhaFeita;
                
				//tratamento caso o usuário insira outro caractere que não seja um numeral
                
				if(cin.fail()){
                    
					cout <<"erro\n";
                    
					cin.clear();
                    
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
				}
                
				//mostrar uma mensagem de erro caso o usuário escolha um número menor que 1 ou maior que 9
                
				else if(escolhaFeita < 1 || escolhaFeita > 9){cout << "escolha inválida!\n";};
            
			};
        
		};

};

//classe da máquina

class JogadorMaquina: public ClasseJogadores{
    
	public:
        
		//definir um número aleatório entre 1 a 9 pra escolha da máquina
        
		void fazerEscolha(){
            
			random_device rd;
            
			mt19937 gen(rd());
            
			uniform_int_distribution<> distr(1, 9);
            
			escolhaFeita = distr(gen);
    
		};

};