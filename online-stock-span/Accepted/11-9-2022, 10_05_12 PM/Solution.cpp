// https://leetcode.com/problems/online-stock-span

class StockSpanner {
public:
    //decreasing stack(the bottom element is the largest)
    stack<int> prices;
    //number of elements popped before pushing corresponding "price" + 1
    stack<int> weights;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int w = 1; //current element
        while(!prices.empty() && prices.top() <= price){
            prices.pop();
            w += weights.top(); weights.pop(); //number of elements skipped by prices.top()
        }
        
        prices.push(price);
        weights.push(w);
        return w;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */