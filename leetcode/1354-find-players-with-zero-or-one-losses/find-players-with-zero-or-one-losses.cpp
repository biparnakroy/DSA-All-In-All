class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int>
            lossCount;    // To count the losses for each player
        set<int> players; // To track all players (both winners and losers)

        // Process each match
        for (auto& match : matches) {
            int winner = match[0];
            int loser = match[1];

            // Add players to the set
            players.insert(winner);
            players.insert(loser);

            // Increment loss count for the loser
            lossCount[loser]++;
            // Ensure winner is in the map with 0 losses
            if (lossCount.find(winner) == lossCount.end()) {
                lossCount[winner] = 0;
            }
        }

        vector<int> noLosses, oneLoss;

        // Classify players based on their loss count
        for (int player : players) {
            if (lossCount[player] == 0) {
                noLosses.push_back(player); // Player with 0 losses
            } else if (lossCount[player] == 1) {
                oneLoss.push_back(player); // Player with exactly 1 loss
            }
        }

        // Sorting the results
        sort(noLosses.begin(), noLosses.end());
        sort(oneLoss.begin(), oneLoss.end());

        return {noLosses, oneLoss};
    }
};