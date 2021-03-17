class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour==12)
            hour = 0;
        hour = (double)hour;
        minutes = (double)minutes;
        
        double angle_hr = 30.0*(hour) + (minutes/60.0)*30.0;
        double angle_minutes = (minutes/60.0)*360.0;
        
        double diff = abs(angle_hr-angle_minutes);
        return min(diff, 360.0-diff);
    }
};