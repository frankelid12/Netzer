#include <bits/stdc++.h>
using namespace std;


const int N = 500; //כמות הקלטים המקסימלית
//מערך גךלובלי למשקולות, מערך ל כוח הליחמה ומערך למציאת המקסימלים
int w[N], f[N], arr[N];

int main() {
  int t; //מספר מקרים
  cin>>t; //קליטת מספר מקרים
  //לולאה שעוברת על כמות המקרים וקולטת ומחשבת
  while (t--) {
    memset(arr, 0, sizeof(arr)); //מאפסת את המערך
    int c,n; //capacity and gadgets
    cin>>c>>n; //קליטה של הערכים
    //קליטה של הכמות של זוגות שצריך
    for (int i = 0; i < n; i++) {
        cin>>w[i]>>f[i];//קליטת מקבל וכוח לחימה למערכים
    }
    for (int i = 0; i < n; i++) {
      for (int j = c; j >= w[i]; j--) {
        arr[j] = max(arr[j], arr[j-w[i]] + f[i]);//חישוב הערך המקסימלי והכנסתו למערך
      }
    }
    int sol = 0;
    for (int i = 0; i <= c; i++){
        sol = max(sol, arr[i]); // מציאת המקסימאלי לאחר השקלולים
    }
    cout << sol << "\n";//הדפסת הערך המקסימלי
  }
     
  return 0;
}
