use std::cmp::max;

impl Solution {
    pub fn angle_clock(hour: i32, minutes: i32) -> f64 {
        let mut hour:f64 = (hour*30) as f64 + (minutes as f64)/2.0 as f64;
        let mut minute:f64 = (minutes*6) as f64;
        let mut dif = hour-minute;
        dif = dif.abs();
        if dif<(360.0-dif){return dif;}
        return 360.0-dif;
    }
}