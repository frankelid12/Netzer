#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int num_color = 20;
const int max_change = 100000;
const int max_time = 501;

int minChange(vector<int> &colors) {
    int count[max_time][num_color+1][num_color+1];
    for(int c1=0; c1<num_color+1; c1++) {
        for(int c2=0; c2<num_color+1; c2++) {
            
            count[0][c1][c2] = max_change;
        }
    }
    count[0][num_color][num_color] = 0;

    for(int t=1; t<=colors.size(); t++) {
        for(int c1=0; c1<num_color+1; c1++) {
            for(int c2=0; c2<num_color+1; c2++) {
                int min_change = max_change;
                if(c1 == colors[t-1] || c2 == colors[t-1]) {
                    //if to change the second bvrush  to the next color 
                    for(int c=0; c<num_color+1; c++) {
                        min_change = min(min_change, count[t-1][c1][c] + 1);
                    }
                    //if to change the first brush
                    for(int c=0; c<num_color+1; c++) {
                        min_change = min(min_change, count[t-1][c][c2] + 1);
                    }
                    // if cahnge both
                    count[t][c1][c2] = min(min_change, count[t-1][c1][c2]);
                }
                else {
                    //max change the color not in the array
                    count[t][c1][c2] = max_change;
                }
            }
        }
    }
    
    
    int min_change = max_change;
    for(int c1=0; c1<num_color+1; c1++) {
        //find the min change for the chace that i use the second brush in the end or 
        min_change = min(min_change, count[colors.size()][c1][colors.back()]);
        min_change = min(min_change, count[colors.size()][colors.back()][c1]);
    }
    return min_change;
}


int main() {
    int T;
    cin >> T;
    for(int t=0; t<T; t++) {
        int n_color;
        cin >> n_color;
        vector<int> colors;
        int color;
        for(int c=0; c<n_color; c++) {
            cin >> color;
            colors.push_back(color-1);
        }
        cout << minChange(colors) << endl;
    }
    return 0;
}
