# include <iostream>
# include <string>
# include <vector>
# include <map>
using namespace std;
// leetcode already edit the problem
 vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        // map key 类型约束， 必须拥有 < 操作符
        // map 底层使用红黑树实现，查找时间是 O(logN). 而C++ STL hash_map 的查找时间复杂度 是 O(1)
        map<int, int> m;
        if (numbers.size() < 2)
            return result;
        for (int i = 0; i < numbers.size(); i++)
            m[numbers[i]] = i;

        map<int, int>::iterator it;
        for (int i = 0; i < numbers.size(); i++) {
            if ((it = m.find(target - numbers[i])) != m.end())
            {
                if (i == it->second) continue;
                result.push_back(i);
                result.push_back(it->second);
                return result;
            }
        }
        return result;
    }

void print_result(vector<int> &result) {
    for(vector<int>::iterator iter = result.begin(); iter != result.end() ; iter++){
        cout << *iter << ends;
    }
    cout <<endl;
}

int main(){
    int a[] = {3,2,4};
    vector<int> b(a, a+3), result;
    result = twoSum(b, 6);
    print_result(result);
    return 0;
}
