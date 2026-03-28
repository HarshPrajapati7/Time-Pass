class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        string word(n,' ');
        char currentChar= 'a';

        // There is two tep to solve this problem step1: Greedy asign chacter to form lexi order
        for(int i=0;i<n;i++){
            if(word[i]==' '){

                // invlid if th chacter is ore than 265 ords
                if(currentChar>'z'){
                    return "";
                }
                //Asigi curnt chaacte 

                for(int j=i;j<n;j++){
                    if(lcp[i][j]>0){
                        word[j]=currentChar;
                    }
                }
                currentChar++; // move to the next letter
            }
        }

        // Step2 : validate

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int expLCP=0;

                if(word[i]==word[j]){
                    if(i+1<n && j+1<n){
                        expLCP=1+lcp[i+1][j+1];
                    }else{
                        expLCP=1; // base case
                    }
                }
                if(lcp[i][j] != expLCP){
                    return "";
                }
            }
        }
        return word;
        
    }
};