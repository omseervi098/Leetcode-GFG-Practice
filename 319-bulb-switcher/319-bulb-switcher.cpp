class Solution {
public:
    int bulbSwitch(int n) {
//         1 2 3 4 5 6 7 8 9 10 11 12 13 14 
//         n/2
//         1 - 3 - 5 - 7 - 9 -  11 - 13 -  //2
//         1 - - - 5 6 7 - - -  11 12 13 - //3
//         1 - - 4 5 6 7 8 - -  11 12 13 14//4
//         1 - - 4 - 6 7 8 - 10 11 12 13 14//5
//         1 - - 4 - - 7 8 - 10 11 -  13 14//6
//         1 - - 4 - - - 8 - 10 11 -  13 - //7
//         1 - - 4 - - - - - 10 11 -  13 - //8
//         1 - - 4 - - - - 9 10 11 -  13 - //9
//         1 - - 4 - - - - 9 -  11 -  13 - //10
//         1 - - 4 - - - - 9 -  -  -  13 - //11
//         1 - - 4 - - - - 9 -  -  12 13 - //12
//         1 - - 4 - - - - 9 -  -  12 -  - //13
//         1 - - 4 - - - - 9 -  -  12 -  14 //14 
        // 1-3 2-5 3-7 4-9 5-11
//         2 == 1 
//         3 == 1
//         4 == 2
//         5 == 2
//         6 == 2
//         7 == 2
//         8 == 2
//         9 == 3
//         10 = 3
//         11 = 3
//         12 = 3
//         13 = 3
//         14 = 3
//         15 = 3
//         16 = 4
//         17 = 4
//         18 = 4
//         19 = 4
//         20 = 4
//         21 = 4
//         22 = 4
//         23 = 4
//         24 = 4
//         25 = 5
//         26 = 5
//         27 = 5
//         28 = 5
//         29 = 5
//         30 = 5
//         31 = 5
//         32 = 5
//         33 = 5
//         34 = 5
//         35 = 5
//         after 10 rounds 3 bulbs are ON
        return (int)sqrt(n);
        
    }
};