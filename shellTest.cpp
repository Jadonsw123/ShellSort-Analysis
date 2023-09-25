#include <vector>
#include <ctime>		// keep this line if you want to generate different random objects for each run
#include "ShellSort.h"
#include <fstream>



int main()
{
    srand(time(0));		// keep this line if you want to generate different random objects for each run
    ofstream out("output.txt");
    int totalCompareCount = 0;
    for(int setNum = 0; setNum <100;setNum++){
        vector<Stuff> vec;
        int size = 15000;
        int type = 4;

        for (int i = 0; i < size; i++)
        {
            Stuff s;
            vec.push_back(s);
        }

        // for (int i = 0; i < size; i++)
        // {
        //     cout << vec[i] << endl;
        // }

        // cout << "-----\n";

        // uncomment this line when the shell sort is implemented
        ShellSort(vec, type);
        
        out<<Stuff::compareCount<<"\n";
        // cout <<  Stuff::compareCount << endl;
        totalCompareCount += Stuff::compareCount;
            // bool allRight = true;
            // for (int i = 0; i < size-1; i++)
            // {
            //     if(vec[i]<vec[i+1]){
            //         allRight = false;
            //     }
            // }
            // cout<<boolalpha;
            // cout<<allRight<<endl;
        Stuff::compareCount = 0;

    }
    out.close();
    cout<<"Total Compare Count for all sets: "<<totalCompareCount<<endl;
    cout<<"Average Compare Count: "<<totalCompareCount/100<<endl;

    // bool allRight = true;
    // for (int i = 0; i < size-1; i++)
    // {
    //     if(vec[i]<vec[i+1]){
    //         allRight = false;
    //     }
    // }
    // cout<<boolalpha;
    // cout<<allRight<<endl;
    // cout << (vec[0] < vec[1]) << endl;
    return 0;
}
