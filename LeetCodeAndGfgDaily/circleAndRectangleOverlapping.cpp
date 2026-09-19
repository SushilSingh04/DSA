#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearestX = max(x1, min(x2, xCenter));
        int nearestY = max(y1, min(y2, yCenter));

        long long xSquared = nearestX-xCenter;
        long long ySquared = nearestY-yCenter;

        return xSquared*xSquared + ySquared*ySquared <= 1LL*radius*radius;
    }
};