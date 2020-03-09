#include <iostream>
using namespace std;
    const string    actualPassword          = "123456";
	string          inventory_nameArray[10] = {"a","b","c","d","e","f","g","h","i","j"};
	int             inventoryArray[10]      = {5,1,4,6,2,8,3,9,0,3};
	int             thresholdArray[10]      = {2,2,2,2,2,2,2,2,2,2};
    int             index;
		
	int authenticate(){
		string password;
		do{
    	    fflush(stdin);
            	cout << "Input password:";
        		cin >> password;
        			if (password == actualPassword){
        				return 1;
        				break;
                    }
                    else{
        				cout << "Wrong password, try again\n\n";
        			}
	        }while(password != actualPassword);
	}
	
	void thresholdAlert(int){
		if (inventoryArray[index] < thresholdArray[index]){
			cout << "You are running out of " << inventory_nameArray[index] << ", only " << inventoryArray[index] << " left";
			return;
		}
		else {
			return;
		}
	}
	
	void displayInventory(){
	    cout << "\n\nInventory:\n";
		for (index=0; index < 10; index++){
			cout << index+1 << ".";
			cout << inventory_nameArray[index] << " = ";
			cout << inventoryArray[index] << "\n";
		}
		return;
	}
		
	int fetchItem(){
	    int inventoryNo;
	    int fetchAmount;
			    if(authenticate()){
			        do{
			            cout << "Input inventory number(1-10): ";
    				    cin >> inventoryNo;
    				    } while(inventoryNo<1||inventoryNo>10);
    				}
				    cout << "Input amount to be fetched: ";
				    cin >> fetchAmount;
				    index = inventoryNo-1;
				    inventoryArray[index] = inventoryArray[index] - fetchAmount;
				    thresholdAlert(index);
	}    

	void endProgram(){
        cout<<"You are exiting the program. See you again :)\n\n";
		return;
	}

int main(){

	int option;
	
	
	while(1){
    	cout << "\n\nInput chosen option(1-3):\n1.Display inventory\n2.Fetch item\n3.End Program\n";
    	
    	cin >> option;
    	switch(option){
    		case 1:
    		    displayInventory();
    		    break;
    		case 2:
    		    fetchItem();
    		    break;
    		case 3: 
    		    endProgram();
    	    default:
    	        return 0;
    	    }
    	}
    return 0;
}