class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();

        if (n < 3)
            return false;

        int start = 0, end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mid == 0 || mid == n - 1) {
                if (mid == 0)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            else if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {

                // Check left side
                for (int i = 0; i < mid; i++) {
                    if (arr[i] >= arr[i + 1])
                        return false;
                }

                // Check right side
                for (int i = mid; i < n - 1; i++) {
                    if (arr[i] <= arr[i + 1])
                        return false;
                }

                return true;
            }
            else if (arr[mid] < arr[mid + 1]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return false;
    }
};