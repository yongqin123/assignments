#include "Assn2.h"
#include <locale> // tolower
const int M = 100; 
const int PI = 3.14159265359;

const int RS = 4;  


//store shapeTwoD objects in vector
vector<shapeTwoD*> new_vector; 
const int C = 12;  

//string lowercase
string to_lower(string s) {        
    for(char &c : s)
        c = tolower(c);
    return s;
}

//first option
void input_sensory_data() {
	int dummy_Y; 
	
	bool ifOk = true; 
	string type_input; 
	string name_shape_input; 
	int static iteration = 0;  
	int dummy_X; 
	
	int srXY = 4; 
	int temp_Radius; 
	float cr = 0; 
	bool containsWS; 
	
	cout << "[Input sensor data]" << endl;
	
	do{
		cout << "Please enter name of shape: ";
		cin >> name_shape_input;
		
		if(name_shape_input == "cross" || name_shape_input == "rectangle" || name_shape_input == "square" || name_shape_input == "circle" || name_shape_input == "CROSS" || name_shape_input == "RECTANGLE" || name_shape_input == "SQUARE" || name_shape_input == "CIRCLE")
		   	ifOk = false;
		else
			cout << "Please enter cross / rectangle / square / circle" << endl;
			
	} while (ifOk == true);
	
	ifOk = true;
	do{
		cout << "Please enter special type: ";
		cin >> type_input;
		//type_input = toLowerCase(type_input);
		if ( type_input == "ns" || type_input == "ws" || type_input == "NS" || type_input == "WS")
			ifOk = false;
		else
			cout << "Please enter WS, (Warp-space) or NS, (Normal-space)" << '\n';
	}
	while (ifOk == true);
	
	if(type_input == "ws" || type_input == "WS")
		containsWS = true;
	else
		containsWS = false;
	
	//Cross
	if(name_shape_input == "cross" || name_shape_input == "CROSS"){
		new_vector.push_back(new cross(name_shape_input, containsWS));
		int x[C];
		int y[C];
		int xAndy = 0;
		for(int a = 0; a < C; a++){
			coord coordin;  //coord c
			ifOk = true;
			bool ifOkay;
			do{
				cout << "Please enter x-oridinate of pt." << a+1 << ": ";
				cin >> dummy_X;
				cout << "Please enter y-oridinate of pt." << a+1 << ": ";
				cin >> dummy_Y;
				ifOkay = true;
				for(int b = 0+1; b < C+1; b++){
					if(dummy_X == x[b-1] && dummy_Y == y[b-1]){
						cout << "You have entered identical x-oridinate and y-ordinate, please enter again" << endl;
						ifOkay = false;
					}
				}
				if(ifOkay){
					x[xAndy] = dummy_X;
					y[xAndy] = dummy_Y;
					coordin.x = dummy_X;
					coordin.y = dummy_Y;
					xAndy += 1;
					new_vector[(new_vector.size() - 1)]->setTheCoordOf(coordin);
					ifOk = false;
				}
				else if (ifOkay == false){
					ifOk = true;
				}
			} while(ifOk == true);
		} 
		cout << '\n';
		cout << "Record successfully stored, Going back to main menu ..." << '\n';
		new_vector[(new_vector.size() - 1)]-> setMinAndMax();
		new_vector[(new_vector.size() - 1)] -> setTheShape(iteration);
		iteration = iteration + 1;
		
		
		
	}
	
	//Rectangle
	else if(name_shape_input == "rectangle" || name_shape_input == "RECTANGLE") {
		new_vector.push_back(new rectangle(name_shape_input, containsWS));
		int xAndy = 0;
		int x[RS];
		int y[RS];
		
		for(int a = 0+1; a < RS+1; a++){
			coord coordin;
			ifOk = true;
			bool ifOkay;
			do{
				cout << "Please enter x-oridinate of pt." << a+1-1 << ": ";
				cin >> dummy_X;
				cout << "Please enter y-oridinate of pt." << a+1-1 << ": ";
				cin >> dummy_Y;
				ifOkay = true;
				for (int b = 0+1; b < RS+1; b++) {
					if(dummy_X == x[b-1] && dummy_Y == y[b-1]){
				
						ifOkay = false;
						cout << "You have entered identical x-oridinate and y-ordinate, please enter again" << '\n';
						
					}
				}
				if(ifOkay){
					x[xAndy] = dummy_X;
					y[xAndy] = dummy_Y;
					coordin.x = dummy_X;
					coordin.y = dummy_Y;
					xAndy += 1;
					new_vector[(new_vector.size() - 1)] -> setTheCoordOf(coordin);
					ifOk = false;
				}
				else if(ifOkay == false){
					ifOk = true;
				}
			}while(ifOk == true);
		} 
		cout << '\n';
		cout << "Record successfully stored, Going back to main menu ..." << '\n';
		new_vector[(new_vector.size() - 1)]-> setMinAndMax();
		new_vector[(new_vector.size() - 1)] -> setTheShape(iteration);
		iteration += 1;
		
		
	}
	
	//square
	else if(name_shape_input == "square" || name_shape_input == "SQUARE"){
		new_vector.push_back(new square(name_shape_input, containsWS));
		int x[RS];
		int y[RS];
		int xAndy = 0;
		for(int a = 0; a < RS; a++){
			coord coordin;
			ifOk = true;
			bool ifOkay;
			do{
				cout << "Please enter x-oridinate of pt." << a+1 << ": ";
				cin >> dummy_X;
				cout << "Please enter y-oridinate of pt." << a+1 << ": ";
				cin >> dummy_Y;
				ifOkay = true;
				for(int b = 0-1; b < RS-1; b++){
					if(dummy_X == x[b+1] && dummy_Y == y[b+1]){
						cout << "You have entered identical x-oridinate and y-ordinate, please enter again" << endl;
						ifOkay = false;
					}
				}

				if(ifOkay){
					x[xAndy] = dummy_X;
					y[xAndy] = dummy_Y;
					coordin.x = dummy_X;
					coordin.y = dummy_Y;
					xAndy += 1;
					new_vector[(new_vector.size() - 1)]->setTheCoordOf(coordin);
					ifOk = false;
				}
				else if(ifOkay == false){
					ifOk = true;
				}
			}
			while(ifOk == true);
		} 
		cout << '\n';
		cout << "Record successfully stored, Going back to main menu ..." << '\n';
		new_vector[(new_vector.size() - 1)]-> setMinAndMax();
		new_vector[(new_vector.size() - 1)] -> setTheShape(iteration);
		iteration += 1;
		
		
	}
	
	//circle
	else if(name_shape_input == "circle" || name_shape_input == "CIRCLE" ){
		new_vector.push_back(new circle(name_shape_input, containsWS));
		coord coordin;
		
		cout << "Please enter x-oridinate of center: ";
		cin >> coordin.x;
		cout << "Please enter y-oridinate of center: ";
		cin >> coordin.y;
		
		new_vector[(new_vector.size() - 1)]->setTheCoordOf(coordin);
		
		int radius;
		cout << "Please enter radius(units): ";
		cin >> radius;
		
		new_vector[(new_vector.size() - 1)]->setTheRadius(cr);
		new_vector[(new_vector.size() - 1)]-> setMinAndMax();
		new_vector[(new_vector.size() - 1)] -> setTheShape(iteration);
		iteration += 1;
		cout << '\n';
		cout << "Record successfully stored, Going back to main menu ..." << '\n';
		
		
	}
}
//----------------------------------------------------------------------------------------------------------------------
//2nd option
void compute_area() {
	if(new_vector.size() == 0)
		cout << " You have not input data" << endl;
	else{
		for(unsigned int a = 0; a < new_vector.size(); a++){
			new_vector[a] -> computeArea();
		}
		
		cout << "Computation completed (" << new_vector.size() << " records were updated)" << '\n';
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------
//3rd option
void print_shape_report() {
	if(new_vector.size() == 0)
		cout << " You have not input data" << endl;
	else{
		cout << "Total no. of records available = " << new_vector.size() << '\n';
		cout << '\n';
		for (unsigned int a = 0; a < new_vector.size(); a++){
			cout << new_vector[a] -> toString() << endl;
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------------------------
//area descending
bool descending(shapeTwoD *m, shapeTwoD *n){
	return m->getArea() > n->getArea();
}

//area ascending
bool ascending(shapeTwoD *m, shapeTwoD *n){
	return n->getArea() > m->getArea();
}

//warp descending
bool wDesc(shapeTwoD *m, shapeTwoD *n){
	if( n->getContainsWarpSpace() != m->getContainsWarpSpace()){
		return m-> getContainsWarpSpace() == true;
	}
	else
		return   m-> getArea() < n->getArea();
}

//-------------------------------------------------------------------------------------------------------------------------------
//4th option
void sort_shapes_data(){
	string user_input_sort;
	static int a = 0;
	if(new_vector.size() == 0)
		cout << "You have not input data" << endl;
	else{
		do{
			cout << "    " << "a)    Sort by area (ascending)" << '\n';
			cout << "    " << "b)    Sort by area (descending)" << '\n';
			cout << "    " << "c)    Sort by special type and area" << '\n';
			cout << "Please select sort option ('q' to go main menu) : ";
			cin >> user_input_sort;
		
			
		
			if (user_input_sort == "a" || user_input_sort == "A"){
				cout << "Sort by area (smallest to largest)" << '\n';
				sort(new_vector.begin(), new_vector.end(), ascending);
				user_input_sort = "q";
			}
			if (user_input_sort == "b" || user_input_sort == "B"){
				cout << "Sort by area (largest to smallest)" << '\n';
				sort(new_vector.begin(), new_vector.end(), descending);
				user_input_sort = "q";
			}
			if (user_input_sort == "c" || user_input_sort == "C"){
				cout << "Sort by special type (WS then NS) and area (largest to smallest)" << '\n';
				sort(new_vector.begin(), new_vector.end(), wDesc);
				user_input_sort = "q";
			}
			if (user_input_sort == "q" || user_input_sort == "Q"){
				
			}
			else{
				cout << "Please input the correct value (a,b,c,q)\n\n";
			}
		} while (user_input_sort != "q");
		
		cout << '\n';
		for(unsigned int b = 0; b < new_vector.size(); b++){
			cout << new_vector[b] -> toString() << '\n';
		}
	}
}

//-----------------------------------------------------------------------------------
//Start up main menu
void main_menu(){
	bool ifOk = true;
	string user_input = "";
	do{
		cout << "Student ID  : 7059073" << '\n';
		cout << "Student Name: Yong Qin Toh" << '\n';
		cout << "--------------------------------" << '\n';
		cout << "Welcome to Assn2 program!" << '\n';
		cout << '\n';
		cout << "1)	Input sensor data" << '\n';
		cout << "2)	Compute area(for all records)" << '\n';
		cout << "3)	Print shapes report" << '\n';
		cout << "4)	Sort shapes data" << '\n';
		cout << "5)	Quit" << '\n';
		cout << '\n';
		cout << "Please enter your choice: ";
		cin >> user_input;

		int user_input_to_integer = stoi(user_input);
	
		switch (user_input_to_integer) {
			case 1:
				cout << '\n';
				input_sensory_data();
				cout << '\n';
				break;
			case 2:
				cout << '\n';
				compute_area();
				cout << '\n';
				break;				
			case 3:
				cout << '\n';
				print_shape_report();
				break;
			case 4:
				cout << '\n';
				sort_shapes_data();
				break;
			
			case 5:
				ifOk = false;
				cout << '\n' << "Thank you for using this program" << '\n' << '\n';
				break;
			default:
				cout << '\n';
				cout << "You have enterered a wrong value, please enter 1 or 2 or 3 or 4 or 5 or 6." << '\n';
				cout << '\n';
				break;
		}
	} while (ifOk == true);
}



//main functions
int main(){
	main_menu();
	return 0;	
}
