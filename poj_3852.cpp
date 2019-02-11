#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
using namespace std;
int main () {
    string in;
    int num_times = 0;
    do {
        cin >> in;
        num_times = atoi(in.c_str());
        int i = num_times;
        string arr[num_times - 1];
        int min_length = MAX_INT;
        while (i) {
            cin >> arr[i - 1];
            min_length = min(min_length, arr[i - 1].length());

            i--;
        }
        i = num_times;
        while(i) {
            for (int j = 0; j < min_length; j++) {
                
            }
            i--;
        }
        
    } while (num_times);
}
