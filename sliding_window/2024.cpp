class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        // int l = 0;
        // int r = 0;
        // int count = 0;
        // int maxnum = 1;
        // int m = 1;

        // while(l < answerKey.length()){
            // if(answerKey[l] == 'T' && l+1 < answerKey.length()){
            //     r = l + 1;
            //     count = 0;
            //     m = 1;
            //     while(r < answerKey.length()){
            //         if(answerKey[r] == 'F'){
            //             count++;
            //         }
            //         if(count > k)
            //             break;
            //         m++;
            //         r++;
            //     }
            //     maxnum = max(m, maxnum);
            // }
            // if(answerKey[l] == 'F' && l+1 < answerKey.length()){
            //     r = l + 1;
            //     count = 0;
            //     m = 1;
            //     while(r < answerKey.length()){
            //         if(answerKey[r] == 'T'){
            //             count++;
            //         }
            //         if(count > k)
            //             break;
            //         m++;
            //         r++;
            //     }
            //     maxnum = max(m, maxnum);
            // }
            // l++;
            // count = 0;
            // m = 0;
            // r = l;
            // while(r < answerKey.length()){
            //     if(answerKey[r] == 'F'){
            //         count++;
            //     }
            //     if(count > k)
            //         break;
            //     m++;
            //     r++;
            // }
            // maxnum = max(m, maxnum);

            // count = 0;
            // m = 0;
            // r = l;
            // while(r < answerKey.length()){
            //     if(answerKey[r] == 'T'){
            //         count++;
            //     }
            //     if(count > k)
            //         break;
            //     m++;
            //     r++;
            // }
            // maxnum = max(m, maxnum);

            // l++;

        //}


        

        //return maxnum;
    
        int l = 0;
        int r = 0;
        int maxnum = 0;
        int count = 0;
        int m = 0;

        while(r < answerKey.length()){
            if(answerKey[r] == 'T'){
                ++r;
                ++m;
            }
            else if(answerKey[r] == 'F'){
                ++count;
                ++r;
                ++m;
                while(count > k){
                    if(answerKey[l] == 'T'){
                        ++l;
                        --m;
                    }
                    else{
                        ++l;
                        --m;
                        --count;
                    }
                }
            }
            
            maxnum = max(m, maxnum);
        }

        l = 0;
        r = 0;
        m = 0;
        count = 0;

        while(r < answerKey.length()){
            if(answerKey[r] == 'F'){
                ++r;
                ++m;
            }
            else if(answerKey[r] == 'T'){
                ++count;
                ++r;
                ++m;
                while(count > k){
                    if(answerKey[l] == 'F'){
                        ++l;
                        --m;
                    }
                    else{
                        ++l;
                        --m;
                        --count;
                    }
                }
            }
            
            maxnum = max(m, maxnum);
        }
    
        return maxnum;
    }
};
