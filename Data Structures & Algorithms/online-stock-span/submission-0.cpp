class StockSpanner {
    stack<pair<int, int>> stocks;
public:
    StockSpanner() {}
    
    int next(int price) {
        if (stocks.empty()) {
            stocks.push({price, 1});
            return 1;
        }
        int count = 1;
        while(!stocks.empty() && stocks.top().first <= price) {
            count += stocks.top().second;
            stocks.pop();
        }
        stocks.push({price, count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */