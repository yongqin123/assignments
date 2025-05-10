#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

int main() {
	vector <string> allfiles;
	string line;
	ifstream myfile ("config.txt");
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
		
		gridx
		grdy
  	}

  	else {
		cout << "Unable to open file"; 


	}

}