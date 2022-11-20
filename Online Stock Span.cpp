class StockSpanner {
public:
    
    stack<int> prices;
    
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