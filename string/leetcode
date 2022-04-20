class Solution {
public:
    int lengthLongestPath(string input) {
        if(!input.find('\n'))
            return 0;

        vector<int> vt;
        int i = 0;
        int j = 0;
        int ans = 0;
        int depth = 0;
        while(j < input.size()-1){
            // cout<<"循环次数"<<endl;
            while(j < input.size() && input[j] != '\n' && input[j] != '\t'){
                j++;
            }
            j--;
            string str = input.substr(i, j-i+1);
            // cout<<str<<endl;
            if(str.find('.') != -1){
                int temp = 0;
                for(int len : vt)
                    temp = temp + len;
                // cout<<temp<<endl;
                temp = temp + str.length();
                ans = max(ans, temp);
                // cout<<"发现file,栈中元素个数："<<vt.size()<<endl;
            }
            else{
                vt.push_back(str.length()+1);
                depth++;
                // cout<<"压入"<<str.length()+1<<endl;
            }

            if(j != input.size())
                j++;
            int localdepth;
            if(input[j] != '\t' && input[j] != '\n')
                localdepth = 0;
            else
                localdepth = -1;
            while(input[j] == '\n' || input[j] == '\t'){
                j += 1;
                localdepth++;
            }
            i = j;
            while(localdepth < depth){
                // cout<<"弹出"<<endl;
                vt.pop_back();
                depth--;
                
            }

        }

        return ans;

    }
};
