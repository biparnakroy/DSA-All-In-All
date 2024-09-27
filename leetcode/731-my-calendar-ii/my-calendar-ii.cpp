class MyCalendarTwo {
private:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlaps;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto x:overlaps){
            if (max(start, x.first) < min(end, x.second)) {
                return false;
            }
        }
        for (auto& booking : bookings) {
            int overlapStart = max(start, booking.first);
            int overlapEnd = min(end, booking.second);
            if (overlapStart < overlapEnd) {
                overlaps.push_back({overlapStart, overlapEnd});
            }
        }
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */