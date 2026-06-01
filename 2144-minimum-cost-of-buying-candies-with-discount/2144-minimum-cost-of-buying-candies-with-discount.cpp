class Solution {
public:
    int minimumCost(vector<int>& cost) {

        // first what i will do i to sort the arry s that i can ge the maxium 2 candies value of cost 

        sort(cost.begin(),cost.end());

        int total = 0;

        for(int x:cost) total+=x;

        int discount=0;
        for (int i = (int)cost.size() - 3; i >= 0; i -= 3) {
            discount += cost[i];
        }

        return total - discount;


        
    }
};