class MyCalendar {
public:
    vector<pair<int, int>> calendar;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto event: calendar){
            int bookedStart = event.first;
            int bookedEnd = event.second;
            if (!(end <= bookedStart || start >= bookedEnd)) {
                return false;
            }
        }
        calendar.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */