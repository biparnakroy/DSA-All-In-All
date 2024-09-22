class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        
        // Convert all times to minutes
        for (const string& time : timePoints) {
            int h = stoi(time.substr(0, 2));  // extract hour
            int m = stoi(time.substr(3, 2));  // extract minute
            minutes.push_back(h * 60 + m);    // convert to total minutes
        }
        
        // Sort the times in ascending order
        sort(minutes.begin(), minutes.end());
        
        int minDiff = INT_MAX;
        
        // Calculate the minimum difference between consecutive times
        for (int i = 1; i < minutes.size(); ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        
        // Also calculate the difference between the last and first time (wrap-around)
        int wrapAroundDiff = (1440 - minutes.back()) + minutes[0]; // 1440 minutes in a day
        minDiff = min(minDiff, wrapAroundDiff);
        
        return minDiff;
    }
};