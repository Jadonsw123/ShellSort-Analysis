#include <vector>
#include <ctime>		// keep this line if you want to generate different random objects for each run
#include "stuff.h"
#include <cmath>



void ShellSort(vector<Stuff>& s, int code){
    if(code < 0 || code > 4)throw std::invalid_argument("code out of range 0-4");
    int swaps = 0;
    vector<int> hlist;
    if(code == 0) hlist.push_back(1);
    else if(code == 1){
        int maxK = floor(sqrt(s.size()));
        while(maxK >= 1){
            hlist.push_back(maxK * maxK);
            maxK--;
        }
    }else if(code == 2){
        int maxK = floor(log2(s.size()));
        while(maxK >= 1){
            hlist.push_back(exp2(maxK));
            maxK--;
        }
        hlist.push_back(1);
    }else if(code == 3){
        int maxK = floor(log2(s.size()+1));
        while(maxK >= 1){
            hlist.push_back(exp2(maxK)-1);
            maxK--;
        }
        if(hlist.size() == 0){
            hlist.push_back(1);
        }
    }else if(code == 4){
        hlist.push_back(1);
        int k = 0;
        while((pow(4,k+1)+3*exp2(k)+1) < s.size()){
            hlist.insert(hlist.begin(),(int)(pow(4,k+1)+3*exp2(k)+1));
            k++;
        }
    }
    for(auto i : hlist){
        cout<<i<<" ";
    }

    cout<<endl;

    int incrementNum = 0;
    int incrementSize = hlist[0];
    while(incrementNum < hlist.size()){
        incrementSize = hlist[incrementNum];
        long unsigned int start = 0;
        while(start < incrementSize){
            int curr = start;
            for(int i = start; i < s.size()-incrementSize;i+=incrementSize){
                Stuff temp = s[i];
                if(temp < s[i+incrementSize]){
                    swaps++;
                    s[i] = s[i+incrementSize];
                    s[i+incrementSize] = temp;
                    if(i != 0)i-=incrementSize*2;
                } else{
                    curr += incrementSize;
                    i = curr-incrementSize;
                }
            }
            start++;
        }


        incrementNum++;
    }
    cout<<swaps<<endl;
}



int main()
{
    srand(time(0));		// keep this line if you want to generate different random objects for each run
    vector<Stuff> vec;
    int size = 99999;

    for (int i = 0; i < size; i++)
    {
        Stuff s;
        vec.push_back(s);
    }

    // for (int i = 0; i < size; i++)
    // {
    //     cout << vec[i] << endl;
    // }

    cout << "-----\n";

    // uncomment this line when the shell sort is implemented
    ShellSort(vec, 0);
    
    cout << "compareCount : " << Stuff::compareCount << endl;
    bool allRight = true;
    for (int i = 0; i < size-1; i++)
    {
        if(vec[i]<vec[i+1]){
            allRight = false;
        }
    }
    // cout<<boolalpha;
    cout<<allRight<<endl;
    // cout << (vec[0] < vec[1]) << endl;
    return 0;
}
