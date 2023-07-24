#include <iostream>

using namespace std;


class ClasseMecanicas{
    
	private:
        
		//? = casa disponivel, O = casa escolhida pelo jogador, X = casa escolhida pela m�quina
        
		char casas[9] = {'?', '?', '?', '?', '?', '?', '?', '?', '?'};
        
    

	public:
        
		void mostrarCasas(){ 
			cout << "\n" << casas[0] << " " << casas[1] << " " << casas[2] << "\n" << casas[3] << " " << casas[4] << " " << casas[5] << "\n" << casas[6] << " " << casas[7] << " " << casas[8] << "\n";
		};
        
		//checar se um dos jogadores completou uma das sequ�ncias corretamente
        
		bool checarFinal(){
            
			bool retorno = false;
            
			//sequ�ncias que iniciam na casa 0
            
			if(casas[0] == 'X' || casas[0] == 'O'){
                
				//sequ�ncia horizontal
                
				if(casas[1] == casas[0] && casas[2] == casas[0]){
                    
					if(casas[0] == 'X'){ cout << "voc� perdeu!";}
                    
					else{cout << "voc� venceu!";};
                    
					retorno = true; 
                
				}
                
				//sequ�ncia vertical
                
				else if (casas[3] == casas[0] && casas[6] == casas[0]){
                    
					if(casas[0] == 'X'){ cout << "voc� perdeu!";}
                    
					else{ cout << "voc� venceu!";};
                    
					retorno = true;
                
				}
                
				//sequ�ncia diagonal
                
				else if(casas[4] == casas[0] && casas[8] == casas[0]){
					if(casas[0] == 'X'){ cout << "voc� perdeu!";}

					else{ cout << "voc� venceu!";};
					retorno = true;
				};
			}

			//sequ�ncias que iniciam na casa 1
 
			if(casas[1] == 'X' || casas[1] == 'O'){
                
				//sequ�ncia vertical
                
				if(casas[4] == casas[1] && casas[7] == casas[1]){
                    
					if(casas[1] == 'X'){ cout << "voc� perdeu!";}
                    
					else{ cout << "voc� venceu!";};
                    
					retorno = true;
                
				};
            
			}
            
			//sequ�ncias que iniciam na casa 2
            
			if(casas[2] == 'X' || casas[2] == 'O'){
                
				//sequ�ncia diagonal
                
				if(casas[4] == casas[2] && casas[6] == casas[2]){
                    
					if(casas[2] == 'X'){ cout << "voc� perdeu!";}
                    
					else{ cout << "voc� venceu!";};
                    
					retorno = true;
                
				}
                	
				//sequ�ncia vertical
                
				else if (casas[5] == casas[2] && casas[8] == casas[2]){
                    
					if(casas[2] == 'X'){ cout << "voc� perdeu!";}
                    
					else{ cout << "voc� venceu!";};
                    
					retorno = true;
                
				};
            
			}
            
			//sequ�ncias que iniciam na casa 3
            
			if(casas[3] == 'X' || casas[3] == 'O'){
                
				//sequ�ncia horizontal
                
				if(casas[4] == casas[3] && casas[5] == casas[3]){
                    
					if(casas[3] == 'X'){ cout << "voc� perdeu!";}
                    
					else{ cout << "voc� venceu!";};
                    
					retorno = true;
                
				};
            
			}
            
			//sequ�ncias que iniciam na casa 6
            
			if(casas[6] == 'X' || casas[6] == 'O'){
                
				//sequ�ncia horizontal
                
				if(casas[7] == casas[6] && casas[8] == casas[6]){
                    
					if(casas[6] == 'X'){ cout << "voc� perdeu!";}
                    
					else{ cout << "voc� venceu!";};
                    
					retorno = true;
                
				};
            
			};
            
			return retorno;
        
		};
        
		//alterar casa escolhida se ela estiver dispon�vel
        
		bool alterarCasa(int casaEscolhida, string jogadorAtual){
            
			bool retorno = false;
            
			if(casas[casaEscolhida] == '?' ){
                
				if(jogadorAtual == "humano"){casas[casaEscolhida] = 'O';}
                
				else{casas[casaEscolhida] = 'X';};
                
				retorno = true;
            
			}
            
			return retorno;
        
		};

};