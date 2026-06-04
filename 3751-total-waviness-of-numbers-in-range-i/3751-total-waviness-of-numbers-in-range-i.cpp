class Solution {
public:
    int totalWaviness(int num1, int num2) {
        long long total=0;
        for(int x=num1;x<= num2;++x){
            string s=to_string(x);
            size_t n =s.size();

            if(n<3) continue;
            int w=0;
            for(size_t i=1;i+1<n;++i){
                if(s[i]>s[i-1] && s[i]>s[i+1]) w++;
                if(s[i]<s[i-1] && s[i]<s[i+1]) w++;
            }
            total+=w;
            
        }
        return total;
    }
};