class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        int n = arr.size();
        
        int k = 3;
        
        int odds = 0;
        
        for(int i = 0 ; i < n && odds != k ; ++i){
            odds = (arr[i]&1) ? odds + 1 : 0;
            }
        
        return odds == k;
        
       
      
         
            
        
      
       
       
          
          
           
        
      
    }
};