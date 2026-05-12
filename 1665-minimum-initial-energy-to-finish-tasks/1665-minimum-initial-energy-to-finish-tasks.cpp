class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Step 1 & 2: Sort tasks by the "buffer" (minimum - actual) in descending order.
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            int bufferA = a[1] - a[0];
            int bufferB = b[1] - b[0];
            return bufferA > bufferB;
        });
        
        int initial_energy = 0;
        int current_energy = 0;
        
        // Step 3: Simulate the process
        for (const auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];
            
            // If we don't have enough energy just to start the task, we MUST 
            // have started with more energy initially.
            if (current_energy < minimum) {
                int deficit = minimum - current_energy;
                initial_energy += deficit;
                current_energy += deficit; // Refill current energy to exactly meet the minimum
            }
            
            // Spend the actual energy required to complete the task
            current_energy -= actual;
        }
        
        return initial_energy;
    }
};