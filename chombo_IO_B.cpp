//Maria Chombo
//23 October 2015
//Description:Write a single program which implements all of the requirements

#include <iostream>
#include <fstream>//files
#include <iomanip>//set position
#include <string>
#include <cstdlib>//exit function 

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    char fileName [12];
    string firstName, lastName;
    double s1, s2, s3, s4, s5, s6, average;
    int num = 0;
    string valB;
    
      cout << "Enter file name: " << endl;
      cin >> fileName;//fileName to call the file
    
      fin.open(fileName);
      fout.open("result.txt");
    
     if (fin.fail())//files failed 
    {
            cout << "Error opening input file" << endl;
            exit(1);
    }  
    
    if (fout.fail())//files for output fail 
    {
            cout << "Error opening output file" << endl;
            exit(1);
    } 
    while (fin >> firstName >> lastName >> s1 >> s2 >> s3 >> s4 >> s5 >> s6)//taking line by   line
    {
        fout.setf(ios::fixed);
        fout.setf(ios::showpoint);
        fout.precision(2);
        fout.setf(ios::left);
        average = (s1 + s2 + s3 + s4 + s5)/5;
        fout << setw(12) << firstName << setw(12) << lastName
                << setw (12) << s1 << setw(12) << s2 << setw(12) << s3 << setw(12) << s4 << setw(
                12) << s5 << setw(12) << average << setw(12) << endl; 
        if ( average > num)
        {
                num = average; 
               valB = firstName +  " " + lastName;
        }
    }
    fout <<"\n Highest score :  " << valB << endl;
    fin.close();
    fout.close();
    return 0;
}
