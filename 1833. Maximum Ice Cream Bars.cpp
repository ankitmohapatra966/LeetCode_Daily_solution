class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = 0;
        for (int cost : costs) {
            if (cost > maxCost) {
                maxCost = cost;
            }
        }
        
        vector<int> count(maxCost + 1, 0);
        for (int cost : costs) {
            count[cost]++;
        }
        
        int bars = 0;
        int remainingCoins = coins;
        
        for (int cost = 1; cost <= maxCost; ++cost) {
            if (count[cost] > 0) {
           
                int canBuy = min(count[cost], remainingCoins / cost);
                bars += canBuy;
                remainingCoins -= canBuy * cost;
                
                if (canBuy == 0) break;
            }
        }
        
        return bars;
    }
};
