class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<tuple<int, int, int>> events; // stores events (time, type, friend_index)

        // Create events for arrival and departure
        for (int i = 0; i < n; ++i) {
            events.push_back({times[i][0], 1, i}); // arrival event
            events.push_back({times[i][1], 0, i}); // departure event
        }

        // Sort events by time, and for same time, prioritize departure over
        // arrival
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>>
            freeChairs; // min-heap for available chairs
        for (int i = 0; i < n; ++i)
            freeChairs.push(i); // initially all chairs are available

        vector<int> friendToChair(
            n, -1); // stores the chair assigned to each friend

        // Process each event
        for (const auto& [time, type, friendIdx] : events) {
            if (type == 1) { // arrival
                int chair = freeChairs.top();
                freeChairs.pop();
                friendToChair[friendIdx] = chair;
                if (friendIdx == targetFriend) {
                    return chair;
                }
            } else { // departure
                int chair = friendToChair[friendIdx];
                freeChairs.push(chair);
            }
        }
        return -1;
    }
};