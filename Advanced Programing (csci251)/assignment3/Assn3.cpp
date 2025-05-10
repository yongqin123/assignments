#include "Assn3.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "MyTemplates.h"
using namespace std;

//These are the what option the user key in
string whatIsoption2 = "Point2D";
string whatIsoption3 = "X ordinate";
string whatIsoption4 = "ASC";
int countLoop = 0;
//vector string contains string of each line of messy.txt
vector <string> new_vectors;

vector <Point2D> pt2D_vectors;

//Point3D vector container
vector <Point3D> pt3D_vectors;

//Line2D vector container
vector <Line2D> line2D_vectors;

//Line3D vector container
vector <Line3D> line3D_vectors;

//split string to vector
vector<string> splitString(string str, string delim) {
	vector<string> result;
	size_t pos = 0;
	string token;
	while ((pos = str.find(delim)) != std::string::npos) {
		token = str.substr(0, pos);
		result.push_back(token);
		str.erase(0, pos + delim.length());
	}
	if (!str.empty())
		result.push_back(str);
	return (result);
}



void option1() {
	string inputfile;
	// Create a text string, which is used to output the text file
	string myText;
	cout << "Please enter file name: ";
	cin >> inputfile;
	cout << endl;
	// Read from the text file
	ifstream MyReadFile(inputfile);

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, myText)) {
		new_vectors.push_back(myText);
	}

	// Close the file
	MyReadFile.close();

	//sort the strings in ascending order
	sort(new_vectors.begin(), new_vectors.end());
	//removes duplicates
	new_vectors.erase(unique(new_vectors.begin(), new_vectors.end()), new_vectors.end());

	//remove ] character
	for (int i = 0; i < new_vectors.size(); i++) {
		new_vectors[i].erase(remove(new_vectors[i].begin(), new_vectors[i].end(), ']'), new_vectors[i].end());
 	}


	for (int i = 0; i < new_vectors.size(); i++) {
		//split string by ", [" then intialise Point2D object and push back into vector
		if (splitString(new_vectors[i], ", ")[0] == "Point2D") {
			vector<string> xAndY = splitString(splitString(new_vectors[i], ", [")[1], ", ");
			pt2D_vectors.push_back(Point2D(stoi(xAndY[0]), stoi(xAndY[1])));
		}
		//split string by ", [" then intialise Point3D object and push back into vector
		if (splitString(new_vectors[i], ", ")[0] == "Point3D") {
			vector<string> xAndY = splitString(splitString(new_vectors[i], ", [")[1], ", ");
			pt3D_vectors.push_back(Point3D(stoi(xAndY[0]), stoi(xAndY[1]), stoi(xAndY[2])));
		}
		//split string by ", [" then intialise Line2D object and push back into vector
		if (splitString(new_vectors[i], ", ")[0] == "Line2D") {
			vector<string> xAndy1 = splitString(splitString(new_vectors[i], ", [")[1], ", "); //first point
			vector<string> xAndy2 = splitString(splitString(new_vectors[i], ", [")[2], ", "); //second point
			line2D_vectors.push_back(Line2D(Point2D(stoi(xAndy1[0]), stoi(xAndy1[1])), Point2D(stoi(xAndy2[0]), stoi(xAndy2[1]))));
		}
		//split string by ", [" then intialise Line3D object and push back into vector
		if (splitString(new_vectors[i], ", ")[0] == "Line3D") {
			vector<string> xAndy1 = splitString(splitString(new_vectors[i], ", [")[1], ", "); //first point
			vector<string> xAndy2 = splitString(splitString(new_vectors[i], ", [")[2], ", "); //second point
			line3D_vectors.push_back(Line3D(Point3D(stoi(xAndy1[0]), stoi(xAndy1[1]), stoi(xAndy1[2])), Point3D(stoi(xAndy2[0]), stoi(xAndy2[1]), stoi(xAndy2[2]))));
		}

	}

}

void option2() {
	bool incorrect_option2 = true;
	do {
		cout << endl;
		cout << "[ Specifying filtering criteria (current : " << whatIsoption2 << ") ]" << endl;
		cout << endl;
		cout << "   a)       Point2D records" << endl;
		cout << "   b)       Point3D records" << endl;
		cout << "   c)       Line2D records" << endl;
		cout << "   d)       Line3D records" << endl;
		cout << endl;
		cout << "   Please enter your criteria (a-d): " << endl;
		cin >> whatIsoption2;
		if (whatIsoption2 == "a" || whatIsoption2 == "b" || whatIsoption2 == "c" || whatIsoption2 == "d") {
			incorrect_option2 = false;
		}
		else {
			cout << "Please key in values from a-d please" << endl;
		}

	} while (incorrect_option2);

	if (whatIsoption2 == "a") {
		whatIsoption2 = "Point2D";
	}
	if (whatIsoption2 == "b") {
		whatIsoption2 = "Point3D";
	}
	if (whatIsoption2 == "c") {
		whatIsoption2 = "Line2D";
	}
	if (whatIsoption2 == "d") {
		whatIsoption2 = "Line3D";
	}

	cout << "   Filter criteria successfully set to '" << whatIsoption2 << "'!" << endl;
	cout << "..." << endl;
	cout << endl;
	
}

void option3() {
	bool incorrect_option3 = true;
	do {
		if (whatIsoption2 == "Line2D" || whatIsoption2 == "Line3D") {
			whatIsoption3 = "X and Y coordinate	values of Pt. 1";
			cout << endl;
			cout << "[ Specifying filtering criteria (current : " << whatIsoption3 << ") ]" << endl;
			cout << endl;
			cout << "   a)       Pt. 1's (x, y) records" << endl;
			cout << "   b)       Pt. 2's (x, y) records" << endl;
			cout << "   c)       Length value" << endl;

			cout << endl;
			cout << "   Please enter your criteria (a-c): " << endl;
			cin >> whatIsoption3;
			if (whatIsoption3 == "a" || whatIsoption3 == "b" || whatIsoption3 == "c" || whatIsoption3 == "A" || whatIsoption3 == "B" || whatIsoption3 == "C") {
				incorrect_option3 = false;
				if (whatIsoption3 == "a" || whatIsoption3 == "A") {
					whatIsoption3 = "Pt. 1's (x, y) records";
				}

				if (whatIsoption3 == "b" || whatIsoption3 == "B") {
					whatIsoption3 = "Pt. 2's (x, y) records";
				}

				if (whatIsoption3 == "C" || whatIsoption3 == "c") {
					whatIsoption3 = "Length";
				}
			}
			else {
				cout << "Please key in values within (a-d) please" << endl;
			}
		}

		if (whatIsoption2 == "Point2D" || whatIsoption2 == "Point2D") {
			whatIsoption3 = "X ordinate";
			cout << endl;
			cout << "[ Specifying filtering criteria (current : " << whatIsoption3 << ") ]" << endl;
			cout << endl;
			cout << "   a)       X ordinate value" << endl;
			cout << "   b)       Y ordinate value" << endl;
			cout << "   c)       Dist. Fr Origin value" << endl;

			cout << endl;
			cout << "   Please enter your criteria (a-c): " << endl;
			cin >> whatIsoption3;
			if (whatIsoption3 == "a" || whatIsoption3 == "b" || whatIsoption3 == "c" || whatIsoption3 == "A" || whatIsoption3 == "B" || whatIsoption3 == "C") {
				incorrect_option3 = false;
				if (whatIsoption3 == "a" || whatIsoption3 == "A") {
					whatIsoption3 = "X ordinate";
				}

				if (whatIsoption3 == "b" || whatIsoption3 == "B") {
					whatIsoption3 = "Y ordinate";
				}

				if (whatIsoption3 == "C" || whatIsoption3 == "c") {
					whatIsoption3 = "Dist. Fr Origin";
				}
			}
			else {
				cout << "Please key in values within (a-d) please" << endl;
			}
		}

		if (whatIsoption2 == "Point3D" || whatIsoption2 == "Point3D") {
			whatIsoption3 = "X ordinate";
			cout << endl;
			cout << "[ Specifying filtering criteria (current : " << whatIsoption3 << ") ]" << endl;
			cout << endl;
			cout << "   a)       X ordinate value" << endl;
			cout << "   b)       Y ordinate value" << endl;
			cout << "   c)       Z ordinate value" << endl;
			cout << "   d)       Dist. Fr Origin value" << endl;

			cout << endl;
			cout << "   Please enter your criteria (a-d): " << endl;
			cin >> whatIsoption3;
			if (whatIsoption3 == "a" || whatIsoption3 == "b" || whatIsoption3 == "c" || whatIsoption3 == "d" || whatIsoption3 == "A" || whatIsoption3 == "B" || whatIsoption3 == "C" || whatIsoption3 == "D") {
				incorrect_option3 = false;
				if (whatIsoption3 == "a" || whatIsoption3 == "A") {
					whatIsoption3 = "X ordinate";
				}

				if (whatIsoption3 == "b" || whatIsoption3 == "B") {
					whatIsoption3 = "Y ordinate";
				}

				if (whatIsoption3 == "c" || whatIsoption3 == "C") {
					whatIsoption3 = "Z ordinate";
				}

				if (whatIsoption3 == "d" || whatIsoption3 == "d") {
					whatIsoption3 = "Dist. Fr Origin";
				}
			}
			else {
				cout << "Please key in values within (a-d) please" << endl;
			}
		}
	} while (incorrect_option3);
	

	cout << "Sorting criteria successfully set to '" << whatIsoption3 << "'!" << endl;
	cout << "..." << endl;
	cout << endl;

}


void option4() {
	
	bool incorrect_option4 = true;
	do {
		cout << "[ Specifying sorting order (current : " << whatIsoption4 << ") ]" << endl;
		cout << endl;
		cout << "     a)      ASC (Ascending Order)" << endl;
		cout << "     b)      DSC (Desending Order)" << endl;
		cout << endl;
		cout << "Please enter your criteria (a-b)";
		cin >> whatIsoption4;
		cout << endl;

		if (whatIsoption4 == "a" || whatIsoption4 == "A" || whatIsoption4 == "b" || whatIsoption4 == "B") {
			if (whatIsoption4 == "a" || whatIsoption4 == "A")
				whatIsoption4 = "ASC";
			if (whatIsoption4 == "b" || whatIsoption4 == "B")
				whatIsoption4 = "DSC";
			cout << "Sorting order successfully set to '" << whatIsoption4 << "'!" << endl;

			cout << "..." << endl;
			incorrect_option4 = false;
		}
	} while (incorrect_option4);
}

void reusefunction() {
	countLoop = 0;
	if (whatIsoption2 == "Point2D") {

		for (int i = 0; i < pt2D_vectors.size(); i++) {
			pt2D_vectors[i].sorting = whatIsoption3;
		}

		if (whatIsoption4 == "ASC") {
			sort(pt2D_vectors.begin(), pt2D_vectors.end(), ASC<Point2D>);
		}
		else if (whatIsoption4 == "DSC") {
			sort(pt2D_vectors.begin(), pt2D_vectors.end(), DSC<Point2D>);
		}


		cout << setw(5) << "X"
			<< setw(6) << "Y"
			<< setw(19) << "Dist. Fr Origin"
			<< endl;
		cout << setfill('-') << setw(30) << "-" << endl;
		cout << setfill(' ');
		for (int i = 0; i < pt2D_vectors.size(); i++) {
			cout << pt2D_vectors[i];
			countLoop += 1;
		}
		cout << endl;
		cout << "Going back to main menu..." << endl;
	}
	else if (whatIsoption2 == "Point3D") {
		
		for (int i = 0; i < pt3D_vectors.size(); i++) {
			pt3D_vectors[i].sorting = whatIsoption3;
		}
		if (whatIsoption4 == "ASC") {
			sort(pt3D_vectors.begin(), pt3D_vectors.end(), ASC<Point3D>);
		}
		else if (whatIsoption4 == "DSC") {
			sort(pt3D_vectors.begin(), pt3D_vectors.end(), DSC<Point3D>);
		}
		cout << setw(5) << "X"
			<< setw(5) << "Y"
			<< setw(6) << "Z"
			<< setw(19) << "Dist. Fr Origin"
			<< endl;
		cout << setfill('-') << setw(36) << "-" << endl;
		cout << setfill(' ');
		for (int i = 0; i < pt3D_vectors.size(); i++) {
			cout << pt3D_vectors[i];
			countLoop += 1;
		}
		cout << endl;
		cout << "Going back to main menu..." << endl;
	}

	else if (whatIsoption2 == "Line2D") {
		
		for (int i = 0; i < line2D_vectors.size(); i++) {
			line2D_vectors[i].sorting = whatIsoption3;
		}
		if (whatIsoption4 == "ASC") {
			sort(line2D_vectors.begin(), line2D_vectors.end(), ASC<Line2D>);
		}
		else if (whatIsoption4 == "DSC") {
			sort(line2D_vectors.begin(), line2D_vectors.end(), DSC<Line2D>);
		}
		cout << setw(5) << "P1-X"
			<< setw(6) << "P1-Y"
			<< setw(4) << ""
			<< setw(5) << "P2-X"
			<< setw(6) << "P2-Y"
			<< setw(10) << "Length"
			<< endl;
		cout << setfill('-') << setw(40) << "-" << endl;
		cout << setfill(' ');
		for (int i = 0; i < line2D_vectors.size(); i++) {
			cout << line2D_vectors[i];
			countLoop += 1;
		}
		cout << endl;
		cout << "Going back to main menu..." << endl;
	}
	else if (whatIsoption2 == "Line3D") {
		
		for (int i = 0; i < line3D_vectors.size(); i++) {
			line3D_vectors[i].sorting = whatIsoption3;
		}
		if (whatIsoption4 == "ASC") {
			sort(line3D_vectors.begin(), line3D_vectors.end(), ASC<Line3D>);
		}
		else if (whatIsoption4 == "DSC") {
			sort(line3D_vectors.begin(), line3D_vectors.end(), DSC<Line3D>);
		}
		cout << setw(5) << "P1-X"
			<< setw(6) << "P1-Y"
			<< setw(6) << "P1-Z"
			<< setw(4) << ""
			<< setw(5) << "P2-X"
			<< setw(6) << "P2-Y"
			<< setw(6) << "P2-Z"
			<< setw(10) << "Length"
			<< endl;
		cout << setfill('-') << setw(52) << "-" << endl;
		cout << setfill(' ');
		for (int i = 0; i < line3D_vectors.size(); i++) {
			cout << line3D_vectors[i];
			countLoop += 1;
		}
		cout << endl;
		cout << "Going back to main menu..." << endl;
	}



}

void option5() {

	cout << "[View data ...]" << endl;
	cout << "Filtering criteria: " << whatIsoption2 << endl;
	cout << "Sorting criteria: " << whatIsoption3 << endl;
	cout << "Sorting order: " << whatIsoption4 << endl;
	cout << endl;

	reusefunction();
	
}

void option6() {
	string outputfile;
	cout << "Please enter filename: ";
	cin >> outputfile;
	// Create and open a text file
	ofstream Ofile(outputfile);

	// Write to the file
	countLoop = 0;
	if (whatIsoption2 == "Point2D") {

		for (int i = 0; i < pt2D_vectors.size(); i++) {
			pt2D_vectors[i].sorting = whatIsoption3;
		}

		if (whatIsoption4 == "ASC") {
			sort(pt2D_vectors.begin(), pt2D_vectors.end(), ASC<Point2D>);
		}
		else if (whatIsoption4 == "DSC") {
			sort(pt2D_vectors.begin(), pt2D_vectors.end(), DSC<Point2D>);
		}


		Ofile << setw(5) << "X"
			<< setw(6) << "Y"
			<< setw(19) << "Dist. Fr Origin\n";
			
		Ofile << setfill('-') << setw(30) << "-\n";
		Ofile << setfill(' ');
		for (int i = 0; i < pt2D_vectors.size(); i++) {
			Ofile << pt2D_vectors[i];
			countLoop += 1;
		}
		Ofile << '\n';
		
	}
	else if (whatIsoption2 == "Point3D") {

		for (int i = 0; i < pt3D_vectors.size(); i++) {
			pt3D_vectors[i].sorting = whatIsoption3;
		}
		if (whatIsoption4 == "ASC") {
			sort(pt3D_vectors.begin(), pt3D_vectors.end(), ASC<Point3D>);
		}
		else if (whatIsoption4 == "DSC") {
			sort(pt3D_vectors.begin(), pt3D_vectors.end(), DSC<Point3D>);
		}
		Ofile << setw(5) << "X"
			<< setw(5) << "Y"
			<< setw(6) << "Z"
			<< setw(19) << "Dist. Fr Origin\n";
			
		Ofile << setfill('-') << setw(36) << "-\n";
		Ofile << setfill(' ');
		for (int i = 0; i < pt3D_vectors.size(); i++) {
			Ofile << pt3D_vectors[i];
			countLoop += 1;
		}
		Ofile << '\n';
		
	}

	else if (whatIsoption2 == "Line2D") {

		for (int i = 0; i < line2D_vectors.size(); i++) {
			line2D_vectors[i].sorting = whatIsoption3;
		}
		if (whatIsoption4 == "ASC") {
			sort(line2D_vectors.begin(), line2D_vectors.end(), ASC<Line2D>);
		}
		else if (whatIsoption4 == "DSC") {
			sort(line2D_vectors.begin(), line2D_vectors.end(), DSC<Line2D>);
		}
		Ofile << setw(5) << "P1-X"
			<< setw(6) << "P1-Y"
			<< setw(4) << ""
			<< setw(5) << "P2-X"
			<< setw(6) << "P2-Y"
			<< setw(10) << "Length"
			<< '\n';
		Ofile << setfill('-') << setw(40) << "-\n";
		Ofile << setfill(' ');
		for (int i = 0; i < line2D_vectors.size(); i++) {
			Ofile << line2D_vectors[i];
			countLoop += 1;
		}
		Ofile << '\n';
		
	}
	else if (whatIsoption2 == "Line3D") {

		for (int i = 0; i < line3D_vectors.size(); i++) {
			line3D_vectors[i].sorting = whatIsoption3;
		}
		if (whatIsoption4 == "ASC") {
			sort(line3D_vectors.begin(), line3D_vectors.end(), ASC<Line3D>);
		}
		else if (whatIsoption4 == "DSC") {
			sort(line3D_vectors.begin(), line3D_vectors.end(), DSC<Line3D>);
		}
		Ofile << setw(5) << "P1-X"
			<< setw(6) << "P1-Y"
			<< setw(6) << "P1-Z"
			<< setw(4) << ""
			<< setw(5) << "P2-X"
			<< setw(6) << "P2-Y"
			<< setw(6) << "P2-Z"
			<< setw(10) << "Length"
			<< '\n';
		Ofile << setfill('-') << setw(52) << "-\n";
		Ofile << setfill(' ');
		for (int i = 0; i < line3D_vectors.size(); i++) {
			Ofile << line3D_vectors[i];
			countLoop += 1;
		}
		Ofile << endl;
	}

	// Close the file
	Ofile.close();

	cout << countLoop << " records updated successfully!" << endl;
}


int main() {
	//Point2D vector container
	vector <Point2D> pt2D_vectors;

	//Point3D vector container
	vector <Point3D> pt3D_vectors;

	//Line2D vector container
	vector <Line2D> line2D_vectors;

	//Line3D vector container
	vector <Line3D> line3D_vectors;
	string user_input = "";

	do {
		cout << "Student ID    : 7059073" << endl;
		cout << "Student Name  : Yong Qin Toh" << endl;
		cout << "-------------------------------" << endl;
		cout << "Welcome to Assn3 program!" << endl;
		cout << endl;
		cout << "1)    Read in data" << endl;
		cout << "2)    Specify filtering criteria (current : " << whatIsoption2 << ")"<< endl;
		cout << "3)    Specify sorting criteria (current : " << whatIsoption3 << ")" << endl;
		cout << "4)    Specify sorting order (current : " << whatIsoption4 << ")" << endl;
		cout << "5)    View data" << endl;
		cout << "6)    Store data" << endl;
		cout << endl;
		cout << "Please enter your choice: " << endl;
		cin >> user_input;
		cout << endl;

		if (user_input == "1") {
			option1();
			cout << new_vectors.size() << " records read in successfully!" << endl;

		}

		if (user_input == "2") {
			option2();
		}

		if (user_input == "3") {
			option3();
		}

		if (user_input == "4") {
			option4();
		}

		if (user_input == "5") {
			option5();
		}

		if (user_input == "6") {
			option6();
		}

	}

	while (true);


	return 0;
}