class Solution {
public:
    bool convertToTernary(int N)
   {
    // Base case
    if (N == 0)
        return true;
 
    // Finding the remainder
    // when N is divided by 3
    int x = N % 3;
    N /= 3;
    if (x < 0)
        N += 1;
    if(x==2) return false;
 
    // Recursive function to
    // call the function for
    // the integer division
    // of the value N/3
    bool ans=convertToTernary(N);
 
    // Handling the negative cases
    
        return ans;
   }
    bool checkPowersOfThree(int n) {
        
        return convertToTernary(n);
    }
};