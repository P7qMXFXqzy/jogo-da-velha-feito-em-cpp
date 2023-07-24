#include <iostream>

#include <random>

using namespace std;

//classe pai

class ClasseJogadores{
    
	public:
        
		//vari�vel que indica a casa escolhida
        
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
                
				cout << "\nescolha uma das casas dispon�veis: ";
                
				cin >> escolhaFeita;
                
				//tratamento caso o usu�rio insira outro caractere que n�o seja um numeral
                
				if(cin.fail()){
                    
					cout <<"erro\n";
                    
					cin.clear();
                    
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
				}
                
				//mostrar uma mensagem de erro caso o usu�rio escolha um n�mero menor que 1 ou maior que 9
                
				else if(escolhaFeita < 1 || escolhaFeita > 9){cout << "escolha inv�lida!\n";};
            
			};
        
		};

};

//classe da m�quina

class JogadorMaquina: public ClasseJogadores{
    
	public:
        
		//definir um n�mero aleat�rio entre 1 a 9 pra escolha da m�quina
        
		void fazerEscolha(){
            
			random_device rd;
            
			mt19937 gen(rd());
            
			uniform_int_distribution<> distr(1, 9);
            
			escolhaFeita = distr(gen);
    
		};

};