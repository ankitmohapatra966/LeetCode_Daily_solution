class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
       int count=0;
       int addi=0;
        for(char c : moves){
            if(c=='L'){
                count--;
            }
            else if(c=='_'){
                addi++;
            }
            else{
                count++;
            }
        }

        if(count>=0){
            return addi+count;
        }

        else{
            return abs(count)+addi;
        }


        
    }
};
