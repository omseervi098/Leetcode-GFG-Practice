class Solution {
    public int largestRectangleArea(int[] heights) {
        ArrayList<Integer> leftsmall=new ArrayList<Integer>();
        int[] rightsmall=new int[heights.length];
        Stack<Integer> s=new Stack<Integer>();
        for(int i=0;i<heights.length;i++){
            while(!s.isEmpty() && heights[i]<=heights[s.peek()]){
                s.pop();
            }
            if(s.isEmpty()){
                leftsmall.add(0);
            }else{
                leftsmall.add(s.peek()+1);
            }
            s.push(i);
        }
        s.clear();
        for(int i=heights.length-1;i>=0;i--){
            while(!s.isEmpty() && heights[i]<=heights[s.peek()]){
                s.pop();
            }
            if(s.isEmpty()){
                rightsmall[i]=heights.length-1;
            }else{
                rightsmall[i]=s.peek()-1;
            }
            s.push(i);
        }
        int mx=0;
        for(int i=0;i<heights.length;i++){
            mx=Math.max(mx,heights[i]*(rightsmall[i]-leftsmall.get(i)+1));
        }
        return mx;
    }
}