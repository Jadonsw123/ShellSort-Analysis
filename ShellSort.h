#include <vector>
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
        while((4 * pow(2, k + 1) + 3 * pow(2, k) + 1) < s.size()){
            hlist.insert(hlist.begin(),(int)(4 * pow(2, k + 1) + 3 * pow(2, k) + 1));
            k++;
        }
    }
    // for(auto i : hlist){
    //     cout<<i<<" ";
    // }

    // cout<<endl;

    long unsigned int incrementNum = 0;
    long unsigned int incrementSize = hlist[0];
    while(incrementNum < hlist.size()){
        incrementSize = hlist[incrementNum];
        long unsigned int start = 0;
        while(start < incrementSize){
            long unsigned int curr = start;
            for(long unsigned int i = start; i < s.size()-incrementSize;i+=incrementSize){
                Stuff temp = s[i];
                if(temp < s[i+incrementSize]){
                    swaps++;
                    s[i] = s[i+incrementSize];
                    s[i+incrementSize] = temp;
                    if(i != 0)i-=incrementSize*2;
                    else {
                        curr+= incrementSize;
                        i = curr-incrementSize;
                    }
                } else{
                    curr += incrementSize;
                    i = curr-incrementSize;
                }
            }
            start++;
        }


        incrementNum++;
    }
    // cout<<swaps<<endl;
}