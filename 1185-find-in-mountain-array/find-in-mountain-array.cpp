/**
 * // This is the MountainArray's API interface.
 * // You should not implement it.
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int findInMountainArray(int target, MountainArray &mountainArr) {

        int n = mountainArr.length();

        // --------------------------------
        // 1. Find the peak
        // --------------------------------
        int start = 0;
        int end = n - 1;

        while (start < end) {

            int mid = start + (end - start) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                // We are on increasing side
                start = mid + 1;
            }
            else {
                // We are on decreasing side
                // mid can itself be peak
                end = mid;
            }
        }

        int peak = start;


        // --------------------------------
        // 2. Binary search increasing side
        // --------------------------------
        start = 0;
        end = peak;

        while (start <= end) {

            int mid = start + (end - start) / 2;
            int value = mountainArr.get(mid);

            if (value == target) {
                return mid;
            }
            else if (value < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }


        // --------------------------------
        // 3. Binary search decreasing side
        // --------------------------------
        start = peak + 1;
        end = n - 1;

        while (start <= end) {

            int mid = start + (end - start) / 2;
            int value = mountainArr.get(mid);

            if (value == target) {
                return mid;
            }
            else if (value < target) {
                // Reversed because array is decreasing
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return -1;
    }
};