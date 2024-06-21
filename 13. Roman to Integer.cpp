class Solution {
public:
    int romanToInt(string s) {
        int num = 0, strlen = s.length();
        string stemp;
        
        
        if(s == "IV"){
            return 4;
        }
        
        if(s == "IX"){
            return 9;
        }
        
        if(s == "XL"){
            return 40;
        }
        
        if(s == "XC"){
            return 90;
        }
        
        if(s == "CD"){
            return 400;
        }
        
        if(s == "CM"){
            return 900;
        }
        
        for (int i = 0; i < strlen; i++){
            
            if (s[i] == 'I'){
                if (s[i+1] == 'V'){
                    i++;
                    num = num + 4;
                }
                else if (s[i+1] == 'X'){
                    i++;
                    num = num + 9;
                }
                else{
                   num++; 
                } 
            }
            
            else if(s[i] == 'V'){
                num = num + 5;
            }
            
            else if(s[i] == 'X'){
                if(s[i+1] == 'L'){
                    i++;
                    num = num + 40;
                }
                else if (s[i+1] == 'C'){
                    i++;
                    num = num + 90;
                }
                else{
                    num = num + 10;
                } 
            }
            
            else if(s[i] == 'L'){
                num = num + 50;
            }
            
            else if(s[i] == 'C'){
                if (s[i+1] == 'D'){
                    i++;
                    num = num + 400;
                }
                else if (s[i+1] == 'M'){
                    i++;
                    num = num + 900;
                }
                else{
                    num = num + 100;
                } 
            }
            
            else if(s[i] == 'D'){
                num = num + 500;
            }
            else if(s[i] == 'M'){
                num = num + 1000;
            }
        }
        
        return num;
        
    }
};
