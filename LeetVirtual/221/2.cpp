class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {

        // {expiry_day, count}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int n = apples.size();
        int day = 0;
        int ans = 0;

        while (day < n || !pq.empty()) {

            // add today's apples
            if (day < n && apples[day] > 0) {
                pq.push({day + days[day], apples[day]});
            }

            // remove expired apples
            while (!pq.empty() && pq.top().first <= day)
                pq.pop();

            // eat one apple
            if (!pq.empty()) {
                auto a = pq.top();
                pq.pop();
                ans++;
                a.second--;
                if (a.second > 0)
                    pq.push(a);
            }

            day++;
        }

        return ans;
    }
};
