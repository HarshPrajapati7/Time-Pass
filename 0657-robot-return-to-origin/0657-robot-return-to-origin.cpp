class Solution {
public:
    bool judgeCircle(string moves) {
        int n= moves.length();
        int ucount=0;
        int dcount=0;
        int lcount=0;
        int rcount=0;

        for(int i=0;i<n;i++){
            if(moves[i]=='U'){
                ucount++;
            }
            else if (moves[i]=='D'){
                ucount--;
            }
            else if (moves[i]=='L'){
                lcount++;
            }
            else{
                lcount--;
            }

        }
        if(ucount==0 && lcount==0){
            return true;
        }
        return false;
    }
};