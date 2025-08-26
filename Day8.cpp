/* 2040. Kth Smallest Product of Two Sorted Arrays :
Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of
nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length. */


class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        int n1 = nums1.size(), n2 = nums2.size();
        int pos1 = 0, pos2 = 0;
        while (pos1 < n1 && nums1[pos1] < 0) {
            pos1++;
        }
        while (pos2 < n2 && nums2[pos2] < 0) {
            pos2++;
        }
        long long left = -1e10, right = 1e10;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long count = 0;
            for (int i1 = 0, i2 = pos2 - 1; i1 < pos1 && i2 >= 0;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i1++;
                } else {
                    count += pos1 - i1;
                    i2--;
                }
            }
            for (int i1 = pos1, i2 = n2 - 1; i1 < n1 && i2 >= pos2;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i2--;
                } else {
                    count += i2 - pos2 + 1;
                    i1++;
                }
            }
            for (int i1 = 0, i2 = pos2; i1 < pos1 && i2 < n2;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i2++;
                } else {
                    count += n2 - i2;
                    i1++;
                }
            }
            for (int i1 = pos1, i2 = 0; i1 < n1 && i2 < pos2;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i1++;
                } else {
                    count += n1 - i1;
                    i2++;
                }
            }
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
