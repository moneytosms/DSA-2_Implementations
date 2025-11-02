#include <vector>
class Solution {
public:
    bool checkStraightLine(std::vector<std::vector<int>>& coordinates) {
        int x1=coordinates[0][0];
        int y1=coordinates[0][1];
        int x2=coordinates[1][0];
        int y2=coordinates[1][1];
        int flag=0;
        float m=0;
        int c=0;
        if(x1==x2){
            flag=1;
        }
        else{
        m = (float)(y2-y1)/(x2-x1);
        c = y2-m*x2;
        }
        for(auto x:coordinates){

            if(flag){
                if(x[0]==x1){
                    continue;
                }
                else{
                    return false;
                }
            }
            else{
            if(x[1]==(m*x[0])+c){
                continue;
            }
            else{
                return false;
            }
            }
        }
        return true;
    }
};
