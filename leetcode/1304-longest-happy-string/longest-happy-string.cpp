class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Max-heap of pairs {count, char}
        priority_queue<pair<int, char>> pq;
        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});

        string result = "";

        while (!pq.empty()) {
            auto first = pq.top();
            pq.pop();

            // If last two characters are the same as the most frequent
            // character
            if (result.size() >= 2 && result.back() == first.second &&
                result[result.size() - 2] == first.second) {
                if (pq.empty())
                    break; // No valid second option

                // Get second most frequent character
                auto second = pq.top();
                pq.pop();

                // Add second character to the result
                result += second.second;
                second.first--;

                // Push it back to the heap if there's more of it
                if (second.first > 0)
                    pq.push(second);

                // Push first character back to the heap
                pq.push(first);
            } else {
                // Add the most frequent character to the result
                result += first.second;
                first.first--;

                // Push it back to the heap if there's more of it
                if (first.first > 0)
                    pq.push(first);
            }
        }

        return result;
    }
};