/**
Easy - Maximum Population Year
https://leetcode.com/problems/maximum-population-year/
Written By : LalitN97
**/

class Solution {
public:
    
    /**
    Brute Force : 
    for every year take the count of population by iterating over the input array for each year.
    track the min year with max population and return it.
    Time Complexity - O(N * K)
    Space Complexity - O(1)
    where N is the size of input array
    and K is the maximum year range constraint (in this question not more than 100)
    
    Optimized : Trick
    take a array of years as per the constraints and for each person increment value of the birth year by 1
    and decrement the death year by 1 in that array. 
    Next step is to take the prefix sum i.e. prefix[i] = prefix[i] + prefix[i - 1];
    On iterating from left to right in the prefix array the largest prefix element's year will be our answer.
    Time Complexity - O(N + K)
    Space Complexity - O(N)
    
    **/
    
    int maximumPopulation(vector<vector<int>>& logs) {
        
        // int maxPopulationYear = 1950;
        // int maxPopulation = 0;
        // for(int x = 1950; x <= 2050; x++){
        //     int populationX = 0;
        //     for(vector<int> log : logs){
        //         if(x >= log[0] && x < log[1]) populationX++;
        //     }
        //     if(populationX > maxPopulation) {
        //         maxPopulationYear = x;
        //         maxPopulation = populationX;
        //     }
        // }
        // return maxPopulationYear;
        
        int population[2051];
        memset(population, 0, sizeof population);
        int minInputYear = 2050;
        int maxInputYear = 1950;
        for(vector<int> log : logs){
            population[log[0]]++;
            population[log[1]]--;
            minInputYear = min(minInputYear, log[0]);
            maxInputYear = max(maxInputYear, log[1]);
        }
        
        int year = 0;
        int maxPop = 0;
        for(int i = minInputYear; i <= maxInputYear; i++){
            population[i] += population[i - 1]; // setting prefix sum
            if(population[i] > maxPop) {
                maxPop = population[i];
                year = i;
            }
        }
        return year;
    }
};