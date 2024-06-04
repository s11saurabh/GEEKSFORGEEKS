 int k=-1;
        int flag=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0'){
                k=i;
                flag++;
            }
            else break;
        }
        
        if(flag!=0) s.erase(0,k+1);
        
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                s[i] = '1';
                return s;
            }
            else{
                s[i] = '0';
            }
        }
        
        s = "1" + s;
        return s;