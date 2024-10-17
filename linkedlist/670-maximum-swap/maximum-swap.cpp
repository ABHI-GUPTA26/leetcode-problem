class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size();
        vector<int> index(10, -1);

       
        for (int i = 0; i < n; i++) {
            index[str[i] - '0'] = i;
        }

       
        for (int i = 0; i < n; i++) {
            for (int d = 9; d > str[i] - '0'; d--) {
                if (index[d] > i) {
                    swap(str[i], str[index[d]]);
                    int temp = stoi(str);
                    return temp;
                }
            }
        }

        return num;
    }
};
