# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <map>
# include <cstdlib>
# include <cstdio>
# include <cstring>
using namespace std;

int findPeakElement( vector<int>& nums ){
    // simple binary search , O(logn), violent search O(n)
    int left = 0, right = nums.size() - 1;
    while (left < right){
        int mid = (left + right)/2;
        int mid1 = mid + 1;
        if( nums[mid] < nums[mid1]){
            left = mid1;
        }
        else right = mid;
    }
    return right;
    // or return left;
}

int main(){
    int a[] = {1,2,4,5,4,6};
    vector<int> b(a, a + 6);
    int peak = findPeakElement(b);
    cout << peak<<endl;
    return 0;

}
