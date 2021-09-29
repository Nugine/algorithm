int searchInsert(int *nums, int numsSize, int target) {
    int l = 0;
    int r = numsSize;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
