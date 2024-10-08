class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Sort boxTypes in descending order of units per box
        sort(boxTypes.begin(), boxTypes.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] > b[1]; // Sort by number of units (a[1]) in
                                     // descending order
             });

        int totalUnits = 0;

        // Iterate over each box type and add as many as possible to the truck
        for (auto& box : boxTypes) {
            int boxCount = box[0];    // Number of boxes of this type
            int unitsPerBox = box[1]; // Units per box of this type

            // Add as many boxes as possible
            int boxesToAdd =
                min(truckSize,
                    boxCount); // Take either all available or up to truckSize

            totalUnits +=
                boxesToAdd * unitsPerBox; // Increase total units loaded
            truckSize -= boxesToAdd;      // Decrease truck capacity

            // If truck is full, break out of the loop
            if (truckSize == 0)
                break;
        }

        return totalUnits;
    }
};