#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& en) {
        //<3
        sort(en.begin(), en.end(), [](const auto& a, const auto& b){
            if(a[0]!=b[0]) return a[0] < b[0];
            return a[1]>b[1];
        });
        vector<int> ans;
        ans.push_back(en[0][1]); 
        for(int i=0; i<en.size(); i++){
            if(en[i][1]>ans.back()) ans.push_back(en[i][1]);
            else{
                //lower_bound encuentra el primer elemento no menor que el valor dado
                int index=lower_bound(ans.begin(), ans.end(), en[i][1]) -ans.begin();
                ans[index]=en[i][1];
            }
        }
        return ans.size();
    }
};

int main(){
    return 0;
}