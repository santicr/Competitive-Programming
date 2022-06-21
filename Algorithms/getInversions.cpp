#include <bits/stdc++.h>

using namespace std;

int getInvCount(int arr[], int n){
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;
  
    return inv_count;
}

int main(){
    int arr[] = {7, 15, 12, 3};

    cout << getInvCount(arr, 4) << endl;

    return 0;
}