class Solution {
private:
    int partition(vector<int>& a, int p, int q) {
        int x = a[q-1];
        int i = p, b = p;
        int temp;
    
        while (i < q-1) {
            if (a[i] <= x) {
                temp = a[i];
                a[i] = a[b];
                a[b] = temp;
                b++;
            }
            i++;
        }
    
        temp = a[b];
        a[b] = a[q-1];
        a[q-1] = temp;
    
        return b;
    }

    void quicksort(vector<int>& a, int p, int q) {
        if (q <= p) return;
        int mid = partition(a, p, q);
        quicksort(a, p, mid);
        quicksort(a, mid+1, q);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size());
        return nums;    
    }
};