class MedianFinder {
public:
    MedianFinder() {

    }

    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    void addNum(int num) {
        // build your maxi and mini
        maxi.push(num);
        mini.push(maxi.top());
        maxi.pop();

        // balancing
        if (mini.size() > maxi.size()) {
            maxi.push(mini.top());
            mini.pop();
        }
    }

    double findMedian() {
        // if the number of elements are even
        if ((maxi.size() + mini.size()) % 2 == 0) {
            double ans = (double)((maxi.top() + mini.top()) / 2.0);
            return ans;
        }
        return maxi.top(); //if the number of elements are odd.
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */