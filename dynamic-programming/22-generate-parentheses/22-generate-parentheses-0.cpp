class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        function<void(string , int , int , int)>solve = [&](string s , int i , int o , int c){
            if(i == 2*n){
                ans.push_back(s);
                return;
                }
                
            //og sol
            
//             if(o == n){
//                 solve(s + ')' , i+1 , o, c+1);
//             }
            
//             else if(o == c){
//                 solve(s + '(' , i+1 , o+1 , c);
//                 }
//             else{
//                 solve(s + '(' , i + 1 , o +1, c);
//                 solve(s + ')' , i+1 , o,c+1);
                
//                 }
            
            //TODO : explain why
            if(o < n) solve(s + '(' , i + 1 , o + 1 , c);
            if(c < o) solve(s + ')' , i + 1 , o , c + 1);
           
            };
        
        solve("" , 0 , 0 , 0);
        
        return ans;
    }
};

//overwrite - 0