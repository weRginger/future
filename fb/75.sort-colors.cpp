class Solution {
public:
    void sortColors(vector<int>& nums) {
        int SIZE = nums.size();
        int zero_index = 0;
        int two_index = SIZE-1;

        for(int i=0; i < SIZE && two_index>=i ; i++)
        {
            if(nums[i]==0)
            {
                swap(nums[i],nums[zero_index]);
                zero_index++;
            }

            if(nums[i]==2)
            {
                swap(nums[i],nums[two_index]);
                two_index--;
                i--; // this is the most important step for virtual single pass solution
            }
        }
    }
};

// couting sort method: use a little bit more space
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> map(3, 0);
        for (int num : nums)
            map[num]++;
        int index = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < map[i]; j++)
                nums[index++] = i;
    }
};