#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std ;

class Solution{
    public:
    int BuySellStock(vector<int>& prices){ 
        int bestBuy = prices[0] ;
        int maxProf = 0 ;
        for(int i = 0 ; i<prices.size() ; i++){
            bestBuy = min(bestBuy,prices[i]);
            maxProf = max(maxProf,prices[i] - bestBuy);
        }
        return maxProf;


    }
};
int main(){
    vector<int> prices = {7,1,5,3,6,4};
    Solution obj ;
    cout << "The maxprofit is : " << obj.BuySellStock(prices);


}