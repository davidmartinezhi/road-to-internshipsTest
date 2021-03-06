#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //1) Listen
                //I receive an integer array called "nums"
                //Move all ceros to the end of the list
                //Must mantain relative order of non-0 elements
                //I must resolve it with constant memory
                //Array size is between 1 and 10,000
                
        
        //2) Example
            //[0, 1, 2, 0, 3] -> [1, 2, 3, 0, 0]
            //[0, 0, 0, 0, 1] -> [1, 0, 0, 0, 0]
            //[0, 1, 2, 3, 4] -> [1, 2, 3, 4, 0]
            //[1, 2, 0, 3, 0] -> [1, 2, 3, 0, 0]
        
        //3) Brute Force
            //Brute force puede ser aplicar switch como en bubble sort, pero solo para recorrer el 0
            //El peor de los casos sería O(N^2)
        
        //4) Optimize
            //Un algoritmos más optimizado puede utilizar 2 pointers
            //uno que recorre el array y al encontrar un 0, manda al otro pointer hacia adelante
                //Si el pointer auxiliar encuentra un valor distinto a 0, hace switch.
                //Si llega al final de la lista, salimos y regresamos
            //Runtime sería entre O(N) y O(N log N)
        
        //5) Walkthrough
            //Creo pointer que recorre la lista
            //Recorre la lista hasta encontrar un 0
            //Al encontrar un 0, manda al otro pointer en busca de un valor distinto a 0
                //Aux encuentra, switch
                //No encuentra, salimos
            //Regresamos
        
        //6) Implement
        
        //7) Test
        
        for(int i = 0; i < nums.size() - 1; i++){

            int aux = i;
            
            //Si encuentra un 0
            if(nums[i] == 0){   
                
                aux++; //Despliego el auxiliar
                
                while(aux <= nums.size()-1){ //Mientras no recorra toda la lista
                    
                    if(nums[aux] != 0){ //Si su valor es diferente a 0
                        //Switch
                        switchNums(nums, i, aux);
                        break;  //Salimos
                    }
                    else{
                        aux++; //Recorremos
                    }
                }     
            }
            
            //Esto es BUD, Remove unnecessary work
            if(aux == nums.size()){ //Si aux llego al final de la lista
                    break;  //Salimos del forloop porque ahora solo quedan numeros 0
                }
        } 


    /* Solución alterna, basado en las notas de optimización
        //Esta solución es O(N). 100% Seguro

            if(nums.size() == 1){
            return;
        }
        

        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            
            //K siempre estará en el 0 más proximo
            while(nums[k] != 0){
                k++;
                //Si k recorre toda la lista
                if(k >= nums.size()-1){
                    break;
                }
            }
            
            //Si k recorre toda la lista
                if(k >= nums.size()-1){
                    break;
                }
            
            
            if(nums[i] != 0 && i > k){
                switchNums(nums, i, k);
            }
        }
    */


    /*
        Luego estudiar esta solución
        //Debo de aprender esta metodología, entender el patron

        class Solution {
        public:
            void moveZeroes(vector<int>& nums) {
                int j = 0;
                // move all the nonzero elements advance

                //Con este for loop, convierto voy acomodando todos los numeros no 0s
                for (int i = 0; i < nums.size(); i++) {
                    if (nums[i] != 0) { //Si el numero es diferente a 0
                        nums[j++] = nums[i];    //nums j es igual a nums i
                                                //Recorro nums j una
                    }
                }

                //Con este codigo dejo los numeros 0s al final
                for (;j < nums.size(); j++) {   //Desde J, que es donde se que hay numero no 0
                                                //Ahora combierto el resto a 0
                    nums[j] = 0;
                }        
            }
        };
    */
        
    }
    
    //Creando mosulos para simplificar el codigo
    void switchNums(vector<int> & nums, int & i, int & j){
        int aux = nums[i];
        nums[i] = nums[j];
        nums[j] = aux;
    }
};

/*
Notas:
    -La metodologia es eficiente para sacar resultados funcionales, de una manera rapida. Llevo 4 días resolviendo el problema a la primera
    -La velocidad aún es un issue leve, ya que me tarde 38 minutos de principio hasta darle submit y que fuese aceptado (Haciendo Tests y todo)
        Fue el mismo aproach que remove_duplicates, con un apuntador en lo que quiero y otro en lo que no
        Si reconocí el patron y pude utilizar la metodologia anterior para este problema.

    -Cumplí con el requisito de usar memoria O(1)
    -Debo checar el runtime de big O. Ya que no lo pude sacar con exactitud cuando mencione mi eficiencia.

    -Posible optimización:
        Podria no regresar el apuntador auxiliar, sino mantenerlo donde se que esta el ultimo 0
        Solo usarlo para hacer switch

    -Debo de dividir mi solución por partes, hacer mas explicitos los modulos y tareas
*/