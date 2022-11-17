class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1=(abs(ax2-ax1)*abs(ay2-ay1));
        int area2=(abs(bx2-bx1)*abs(by2-by1));
        int A=min(ax2,bx2);
        int B=max(ax1,bx1);
        int C=min(ay2,by2);
        int D=max(ay1,by1);
        int w=A-B,h=C-D;
        if(w<=0 || h<=0){
            return area1+area2;
        }
        return area1+area2-((A-B)*(C-D));

    }
};