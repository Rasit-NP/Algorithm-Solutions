class Solution {

    private int xc, yc;
    private int rSq;

    private int getDistance(int x, int y){
        return (x-xc)*(x-xc) + (y-yc)*(y-yc);
    }

    public boolean checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        this.xc = xCenter;
        this.yc = yCenter;
        this.rSq = radius * radius;

        if (xc >= x1 && xc <= x2 && yc >= y1 && yc <= y2)
            return true;

        for (int x=x1; x<=x2; ++x){
            if (rSq >= Math.min(getDistance(x, y1), getDistance(x, y2)))
                return true;
        }
        for (int y=y1; y<=y2; ++y){
            if (rSq >= Math.min(getDistance(x1, y), getDistance(x2, y)))
                return true;
        }

        return false;
    }
}