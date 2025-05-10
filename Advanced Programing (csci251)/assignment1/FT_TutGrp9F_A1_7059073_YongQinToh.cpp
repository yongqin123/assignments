#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

struct cityLocation {
	string cityId;
	
	string cityName;
	vector<vector<int>> surroundingGrid;
	vector<int> cloudCover;
	vector<int> atmosphericPressure;
	vector<vector<string>> xy;
	
} city1, city2, city3;

int asd;


vector<vector<string>> city1xy;
vector<vector<string>> city2xy;
vector<vector<string>> city3xy;

//city1,city2,city3  are global variables which can be used throughout the whole program.
//other global variables
string citytxt;
string cloudtxt;
string pressuretxt;

vector <string> gridx;
vector <string> gridy;

//initialise city map
vector< vector<string> > cityMap;

//initialise CI and LMH map for cloudCoverage
vector<vector <int>> cloudCoverageCIMap; //( 9 , vector<int> (9, 0));
vector<vector<char>> cloudCoverageLMHMap; //( 9 , vector<char> (9, 'o'));

//initialise PI and LMH map for atmospheric pressure
vector<vector <int>> pIMap; //( 9 , vector<int> (9, 0));
vector<vector<char>> apLMHMap; //( 9 , vector<char> (9, 'o'));

vector<string> splitString(string str, string delim) {
	vector<string> result;
	size_t pos = 0;
	string token;
	while ((pos = str.find(delim)) != std::string::npos) {
		token = str.substr(0, pos);
		result.push_back(token);
		str.erase(0, pos+delim.length());
	}
	if (!str.empty())
		result.push_back(str);
	return (result);
}
//-----------------------------------------------------------------------------------------------------------------------------

//Appendix B -Read citylocation.txt file
vector<vector<string>> computeCityMap(vector<vector<string>> cityMap, string citytxt, cityLocation city1, cityLocation city2, cityLocation city3) {
	//line represents each line of string in citylocation.txt
	string line_citylocation;
	
	//k represents line_citylocation in vector by removing delimiter '-'
	vector<string> k;
  	ifstream myfile (citytxt);
	
 	if (myfile.is_open())
  	{	
		cout << citytxt << " ... done!" << '\n';
    		while ( getline (myfile,line_citylocation) )
    		{
			k = splitString(line_citylocation,"-");
			
			//dummy_str to capture the data item #1
			string dummy_str = k[0];
			
			//erase to remove the first index = '[' and last index = ']'
			//"[x, y]" -> "x, y"
			dummy_str.erase(0, 1);
			dummy_str.erase(dummy_str.size() - 1);
			
			//splitString to remove delimiter ", "
			//from "x, y" -> vector {x,y}
			vector<string> vector_dataitem1 = splitString(dummy_str, ", ");
			
			switch (stoi(k[1])) {
				case 1:
					city1.xy.push_back(vector_dataitem1);
					//city1xy.push_back(vector_dataitem1);
					//asd = 10;
					break;
				case 2:
					city2.xy.push_back(vector_dataitem1);
					//city2xy.push_back(vector_dataitem1);
					break;
				case 3:
					city3.xy.push_back(vector_dataitem1);
					//city3xy.push_back(vector_dataitem1);
					break;
				default:
					break;				
			}
 			
    		}

		for (int i = 0; i < city1.xy.size(); i++) {
			string x_coord = city1.xy[i][1];
			string y_coord = city1.xy[i][0];
			cityMap[stoi(x_coord)][stoi(y_coord)] = city1.cityId;
		}
	
		for (int i = 0; i < city2.xy.size(); i++) {
			string x_coord = city2.xy[i][1];
			string y_coord = city2.xy[i][0];
			cityMap[stoi(x_coord)][stoi(y_coord)] = city2.cityId;
		}

		for (int i = 0; i < city3.xy.size(); i++) {
			string x_coord = city3.xy[i][1];
			string y_coord = city3.xy[i][0];
			cityMap[stoi(x_coord)][stoi(y_coord)] = city3.cityId;
		}
		myfile.close();
		
		
		return cityMap;
  	}

	else {
		cout << "Unable to open file.";
	}
	return cityMap;
}

//---------------------------------------------
//Appendix C- reading and processing of cloudcoverage.txt into data structures, check if the file is present and loaded successfully
tuple<vector<vector<int>>, vector<vector<char>>> computeCloudCoverageMap(vector<vector<int>> cloudCoverageCIMap , vector<vector<char>> cloudCoverageLMHMap, vector<vector<string>> cityMap, string cloudtxt, cityLocation city1, cityLocation city2, cityLocation city3) {
	string next_line;
  	ifstream cloudcover_file(cloudtxt);
	vector<vector<string>> displayCloudCoverMap;
  	if (cloudcover_file.is_open())
  	{
		cout << cloudtxt << " ... done!" << '\n' ;
    		while (getline (cloudcover_file, next_line))
    		{
      			vector<string> vector_line = splitString(next_line,"-");
			
			//dummy_str to capture the data item #1
			string dummy_str = vector_line[0];
			
			//erase to remove the first index = '[' and last index = ']'
			//"[x, y]" -> "x, y"
			dummy_str.erase(0, 1);
			dummy_str.erase(dummy_str.size() - 1);
			
			//splitString to remove delimiter ", "
			//from "x, y" -> vector {x,y}
			vector<string> vector_coord = splitString(dummy_str, ", ");
			int cloudCoverIndex;
			if (stoi(vector_line[1]) < 10 && stoi(vector_line[1]) > 0) {
				cloudCoverIndex = 0;
			}
			if (stoi(vector_line[1]) < 20 && stoi(vector_line[1]) >= 10) {
				cloudCoverIndex = 1;
			}
			if (stoi(vector_line[1]) < 30 && stoi(vector_line[1]) >= 20) {
				cloudCoverIndex = 2;
			}
			if (stoi(vector_line[1]) < 40 && stoi(vector_line[1]) >= 30) {
				cloudCoverIndex = 3;
			}
			if (stoi(vector_line[1]) < 50 && stoi(vector_line[1]) >= 40) {
				cloudCoverIndex = 4;
			}
			if (stoi(vector_line[1]) < 60 && stoi(vector_line[1]) >= 50) {
				cloudCoverIndex = 5;
			}
			if (stoi(vector_line[1]) < 70 && stoi(vector_line[1]) >= 60) {
				cloudCoverIndex = 6;
			}
			if (stoi(vector_line[1]) < 80 && stoi(vector_line[1]) >= 70) {
				cloudCoverIndex = 7;
			}
			if (stoi(vector_line[1]) < 90 && stoi(vector_line[1]) >= 80) {
				cloudCoverIndex = 8;
			}
			if (stoi(vector_line[1]) < 100 && stoi(vector_line[1]) >= 90) {
				cloudCoverIndex = 9;
			}
			if (stoi(vector_line[1]) >= 0 && stoi(vector_line[1]) < 35) {
				cloudCoverageLMHMap[stoi(vector_coord[1])][stoi(vector_coord[0])] = 'L';
			}
			if (stoi(vector_line[1]) >= 35 && stoi(vector_line[1]) < 65) {
				cloudCoverageLMHMap[stoi(vector_coord[1])][stoi(vector_coord[0])] = 'M';
			}
			if (stoi(vector_line[1]) >= 65 && stoi(vector_line[1]) < 100) {
				cloudCoverageLMHMap[stoi(vector_coord[1])][stoi(vector_coord[0])] = 'H';
			}
			if (cityMap[stoi(vector_coord[1])][stoi(vector_coord[0])] == "1")
				city1.cloudCover.push_back(stoi(vector_line[1]));
			if (cityMap[stoi(vector_coord[1])][stoi(vector_coord[0])] == "2")
				city2.cloudCover.push_back(stoi(vector_line[1]));
			if (cityMap[stoi(vector_coord[1])][stoi(vector_coord[0])] == "3")
				city3.cloudCover.push_back(stoi(vector_line[1]));
			cloudCoverageCIMap[stoi(vector_coord[1])][stoi(vector_coord[0])] = cloudCoverIndex;
    		}
    		cloudcover_file.close();
		return make_tuple(cloudCoverageCIMap, cloudCoverageLMHMap);
  	}

	else
	{
		cout << "Unable to open file";
		return make_tuple(cloudCoverageCIMap, cloudCoverageLMHMap);
	}
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Appendix D- reading and processing of pressure.txt into data structures, check if the file is present and loaded successfully
tuple<vector<vector<int>>, vector<vector<char>>> computeAPMap(vector<vector<int>> pIMap , vector<vector<char>> apLMHMap, vector<vector<string>> cityMap, string pressuretxt, cityLocation city1, cityLocation city2, cityLocation city3) {
	string next_line;
  	ifstream atmoshperic_pressure_file(pressuretxt);
	
  	if (atmoshperic_pressure_file.is_open())
  	{
		cout << pressuretxt << " ... done!" << '\n' ;
    		while (getline (atmoshperic_pressure_file, next_line))
    		{
      			vector<string> vector_line = splitString(next_line,"-");
			
			//dummy_str to capture the data item #1 coordinates xy
			string dummy_str = vector_line[0];
			
			//erase to remove the first index = '[' and last index = ']'
			//"[x, y]" -> "x, y"
			dummy_str.erase(0, 1);
			dummy_str.erase(dummy_str.size() - 1);
			
			//splitString to remove delimiter ", "
			//from "x, y" -> vector {x,y}
			vector<string> vector_coord = splitString(dummy_str, ", ");
			int apIndex;
			if (stoi(vector_line[1]) < 10 && stoi(vector_line[1]) > 0) {
				apIndex = 0;
			}
			if (stoi(vector_line[1]) < 20 && stoi(vector_line[1]) >= 10) {
				apIndex = 1;
			}
			if (stoi(vector_line[1]) < 30 && stoi(vector_line[1]) >= 20) {
				apIndex = 2;
			}
			if (stoi(vector_line[1]) < 40 && stoi(vector_line[1]) >= 30) {
				apIndex = 3;
			}
			if (stoi(vector_line[1]) < 50 && stoi(vector_line[1]) >= 40) {
				apIndex = 4;
			}
			if (stoi(vector_line[1]) < 60 && stoi(vector_line[1]) >= 50) {
				apIndex = 5;
			}
			if (stoi(vector_line[1]) < 70 && stoi(vector_line[1]) >= 60) {
				apIndex = 6;
			}
			if (stoi(vector_line[1]) < 80 && stoi(vector_line[1]) >= 70) {
				apIndex = 7;
			}
			if (stoi(vector_line[1]) < 90 && stoi(vector_line[1]) >= 80) {
				apIndex = 8;
			}
			if (stoi(vector_line[1]) < 100 && stoi(vector_line[1]) >= 90) {
				apIndex = 9;
			}
			if (stoi(vector_line[1]) >= 0 && stoi(vector_line[1]) < 35) {
				apLMHMap[stoi(vector_coord[1])][stoi(vector_coord[0])] = 'L';
			}
			if (stoi(vector_line[1]) >= 35 && stoi(vector_line[1]) < 65) {
				apLMHMap[stoi(vector_coord[1])][stoi(vector_coord[0])] = 'M';
			}
			if (stoi(vector_line[1]) >= 65 && stoi(vector_line[1]) < 100) {
				apLMHMap[stoi(vector_coord[1])][stoi(vector_coord[0])] = 'H';
			}
			
			//Append atmospheric pressures of individual city grids into all cities' atmosphericPressure vector for later calculation of average pressure
			if (cityMap[stoi(vector_coord[1])][stoi(vector_coord[0])] == "1")
				city1.atmosphericPressure.push_back(stoi(vector_line[1]));
			if (cityMap[stoi(vector_coord[1])][stoi(vector_coord[0])] == "2")
				city2.atmosphericPressure.push_back(stoi(vector_line[1]));
			if (cityMap[stoi(vector_coord[1])][stoi(vector_coord[0])] == "3")
				city3.atmosphericPressure.push_back(stoi(vector_line[1]));

			//Set individual grids of pressure index into atmoshpheric pressure map 
			pIMap[stoi(vector_coord[1])][stoi(vector_coord[0])] = apIndex;
    		}
    		atmoshperic_pressure_file.close();
		return make_tuple(pIMap , apLMHMap);
  	}

	else
	{
		cout << "Unable to open file";
		return make_tuple(pIMap , apLMHMap);
	}
}


//------------------------------------------------------

//Appendix B- display city map
void displayCityMap(vector<vector<string>>cityMap) {
	
	cout << "  # ";
	for (int i=0; i < cityMap.size(); i++) {
		cout << "# ";
	}
	cout << "#" << '\n';
	
	for (int i = cityMap.size()-1; i >= 0; i--) {
		cout << i << " # ";
		for (int j = 0; j < cityMap[0].size(); j++) {
			cout << cityMap[i][j] << " ";
		}
		cout << "#" << '\n';
 	}
	cout << "  # ";
	for (int i=0; i < cityMap.size(); i++) {
		cout << "# ";
	}
	cout << "#" << '\n';
	cout << "   ";
	for (int i=0; i < cityMap.size(); i++) {
		cout << " " << i;
	}
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Appendix C-display cloud coverage map (cloudiness index)
void displayCloudCoverageMapInCI(vector<vector<int>> cloudCoverageCIMap) {
	cout << "  # ";
	for (int i=0; i < cloudCoverageCIMap.size(); i++) {
		cout << "# ";
	}
	cout << "#" << '\n';
	
	for (int i = cloudCoverageCIMap.size()-1; i >= 0; i--) {
		cout << i << " # ";
		for (int j = 0; j < cloudCoverageCIMap[0].size(); j++) {
			cout << cloudCoverageCIMap[i][j] << " ";
		}
		cout << "#" << '\n';
 	}
	cout << "  # ";
	for (int i=0; i < cloudCoverageCIMap.size(); i++) {
		cout << "# ";
	}
	cout << "#" << '\n';
	cout << "   ";
	for (int i=0; i < cloudCoverageCIMap.size(); i++) {
		cout << " " << i;
	}
	cout << '\n';

}

//Appendix C-display cloud coverage map (LMH symbols)
void displayCloudCoverageMapInLMH(vector<vector<char>> cloudCoverageLMHMap) {
	cout << '\n' << "  # ";
	for (int i=0; i < cloudCoverageLMHMap.size(); i++) {
		cout << "# ";
	}
	cout << "#" << '\n';
	
	for (int i = cloudCoverageLMHMap.size()-1; i >= 0; i--) {
		cout << i << " # ";
		for (int j = 0; j < cloudCoverageLMHMap[0].size(); j++) {
			cout << cloudCoverageLMHMap[i][j] << " ";
		}
		cout << "#" << '\n';
 	}
	cout << "  # ";
	for (int i=0; i < cloudCoverageLMHMap.size(); i++) {
		cout << "# ";
	}
	cout << "#" << '\n';
	cout << "   ";
	for (int i=0; i < cloudCoverageLMHMap.size(); i++) {
		cout << " " << i;
	}	

}



//Appendix D-display ap index map (atmospheric pressure index)
void displayAPMapInCI(vector<vector<int>> pIMap) {
	cout << "  # ";
	for (int i=0; i < pIMap.size(); i++) {
		cout << "# ";
	}
	cout << "#" << '\n';
	
	for (int i = pIMap.size()-1; i >= 0; i--) {
		cout << i << " # ";
		for (int j = 0; j < pIMap[0].size(); j++) {
			cout << pIMap[i][j] << " ";
		}
		cout << "#" << '\n';
 	}
	cout << "  # ";
	for (int i=0; i < pIMap.size(); i++) {
		cout << "# ";
	}
	cout << "#" << '\n';
	cout << "   ";
	for (int i=0; i < pIMap.size(); i++) {
		cout << " " << i;
	}
	cout << '\n';

}

//Appendix D-display atmospheric pressure map (LMH symbols)
void displayAPMapInLMH(vector<vector<char>> apLMHMap) {
	cout << '\n' << "  # ";
	for (int i=0; i < apLMHMap.size(); i++) {
		cout << "# ";
	}
	cout << "#" << '\n';
	
	for (int i = apLMHMap.size()-1; i >= 0; i--) {
		cout << i << " # ";
		for (int j = 0; j < apLMHMap[0].size(); j++) {
			cout << apLMHMap[i][j] << " ";
		}
		cout << "#" << '\n';
 	}
	cout << "  # ";
	for (int i=0; i < apLMHMap.size(); i++) {
		cout << "# ";
	}
	cout << "#" << '\n';
	cout << "   ";
	for (int i=0; i < apLMHMap.size(); i++) {
		cout << " " << i;
	}	

}

//Appendix A - Read all files and coordinates
void readAllFiles(cityLocation city1, cityLocation city2, cityLocation city3) {
	vector <string> allfiles;
	string config;
	string line;
	
	//initialise config filename as string
	cout << "[ Read in and process a configuration file ]" << '\n';
	string config_file_name;
	cout << "Please enter config filename: ";
		
	//obtain the config filename which to be used for appendix a
	cin >> config_file_name;
	cout << '\n';

	ifstream myfile (config_file_name);
  	if (myfile.is_open())
  	{
    		while ( getline (myfile,line) )
    		{
      			allfiles.push_back(line);
    		}
		
    		myfile.close();
		string citytxt = allfiles[9];
		string cloudtxt = allfiles[13];
		string pressuretxt = allfiles[17];
		
		gridx = splitString(splitString(allfiles[2],"=")[1],"-");
		gridy = splitString(splitString(allfiles[2],"=")[1],"-");
		
		cout << "Reading in GridX_IdxRange :" << splitString(allfiles[2],"=")[1] << " ... done!"<< '\n';
		cout << "Reading in GridY_IdxRange :" << splitString(allfiles[6],"=")[1] << " ... done!" << '\n' << '\n';
		vector< vector<string> >cityMap( stoi(gridx[1]) - stoi(gridx[0]) + 1 , vector<string> (stoi(gridy[1]) - stoi(gridy[0]) + 1, " "));
		

		vector<vector <int>> cloudCoverageCIMap( stoi(gridx[1]) - stoi(gridx[0]) + 1 , vector<int> (stoi(gridy[1]) - stoi(gridy[0]) + 1 , 0));
		
		
		vector<vector<char>> cloudCoverageLMHMap( stoi(gridx[1]) - stoi(gridx[0]) + 1 , vector<char> (stoi(gridy[1]) - stoi(gridy[0]) + 1, 'o'));

		vector<vector<char>> apLMHMap( stoi(gridx[1]) - stoi(gridx[0]) + 1 , vector<char> (stoi(gridy[1]) - stoi(gridy[0]) + 1, 'o'));
		vector<vector <int>> pIMap( stoi(gridx[1]) - stoi(gridx[0]) + 1 , vector<int> (stoi(gridy[1]) - stoi(gridy[0]) + 1, 0));
		
		cityMap = computeCityMap(cityMap, citytxt,city1, city2, city3);
		
		
		//append cloud coverage index n symbols
		tie(cloudCoverageCIMap, cloudCoverageLMHMap) = computeCloudCoverageMap(cloudCoverageCIMap , cloudCoverageLMHMap, cityMap, cloudtxt, city1, city2, city3);
		
		tie(pIMap,apLMHMap) = computeAPMap(pIMap,apLMHMap,cityMap, pressuretxt, city1, city2, city3);
		cout << "All records are successfully stored. Going back to main menu ..." << '\n';
		//menu
		while (true) {
			int x;
			cout << "Please enter a choice: "; // Type a number and press enter
			cin >> x; // Get user input
			if (x == 1) {
				readAllFiles(city1, city2, city3);
				
			}
			
			if (x == 2) {
				displayCityMap(cityMap);
				
			}
			if (x == 3) {
				displayCloudCoverageMapInCI(cloudCoverageCIMap);
				
			}
			if (x == 4) {
				
				displayCloudCoverageMapInLMH(cloudCoverageLMHMap);
			
			}
			if (x == 5) {
				displayAPMapInCI(pIMap);
		
			}
			if (x == 6) {
				displayAPMapInLMH(apLMHMap);
		
			}
			if (x == 7) {
				
			}
			if (x == 8) {
				break;
			}
			cout << '\n' << "Student ID    : 7059073" << '\n';
				cout << "Student Name : Toh Yong Qin" << '\n';
				cout << "-----------------------------------" << '\n';
				cout << "Welcome to Weather Information Processing System!" << '\n';
				cout << '\n';
				cout << "1)     Read in and process a configuration file" << '\n';
				cout << "2)     Display city map" << '\n';
				cout << "3)     Display cloud coverage map (cloudiness index)" << '\n';
				cout << "4)     Display cloud coverage map (LMH symbols)" << '\n';
				cout << "5)     Display atmospheric pressure map (pressure index)" << '\n';
				cout << "6)     Display atmospheric pressure map (LMH symbols)" << '\n';
				cout << "7)     Show weather forecast summary report" << '\n';
				cout << "8)     Quit" <<'\n';
			
		}
		
  	}

  	else {
		cout << "Unable to open file"; 
		

	}


}


//------------------------------------------------------------------------------------------------------------------------------------------
int main() {
	city1.cityId = "1";
	city1.cityName = "Small_City";

	city2.cityId = "2";
	city2.cityName = "Mid_City";

	city3.cityId = "3";
	city3.cityName = "Big_City";
	
	if (true) {
		cout << "Student ID    : 7059073" << '\n';
		cout << "Student Name : Toh Yong Qin" << '\n';
		cout << "-----------------------------------" << '\n';
		cout << "Welcome to Weather Information Processing System!" << '\n';
		cout << '\n';
		cout << "1)     Read in and process a configuration file" << '\n';
		cout << "2)     Display city map" << '\n';
		cout << "3)     Display cloud coverage map (cloudiness index)" << '\n';
		cout << "4)     Display cloud coverage map (LMH symbols)" << '\n';
		cout << "5)     Display atmospheric pressure map (pressure index)" << '\n';
		cout << "6)     Display atmospheric pressure map (LMH symbols)" << '\n';
		cout << "7)     Show weather forecast summary report" << '\n';
		cout << "8)     Quit" <<'\n';

		readAllFiles(city1, city2, city3);
	}
}