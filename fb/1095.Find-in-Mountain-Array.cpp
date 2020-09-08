/*
通过三分查找定位山的最高点，然后通过两次二分查找分别在山峰的左边和右边查找目标值。
  - 三分查找过程如下：假设待查询的闭区间为 [l, r]。
    如果闭区间长度严格大于 3，则将区间平均切割为三个部分。
    令 mid1 = l + (r - l) / 3 和 mid2 = r - (r - l) / 3，三个区间分别为 [l, mid1]、[mid1, mid2] 和 [mid2, r]。
    如果 mountainArr.get(mid1) > mountainArr.get(mid2)，则 r = mid2，因为 mid2 右侧的区间就没有查询的必要了。
    否则 l = mid1，道理同样是 mid1 左侧的区间就没有查询的必要了。
    最终 l 和 r 的差距少于等于 3 时，退出循环，暴力判断 [l, r] 内哪个点最大。
  - 接下来两次二分查找的过程不再赘述。
链接：https://www.acwing.com/solution/LeetCode/content/2563/
*/
// Time O(logN)
// Space O(1)
class Solution {
private:
    int getHighest(int n, MountainArray &mountainArr) {
        int l = 0, r = n - 1;
        while (l + 2 < r) {
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;
            if (mountainArr.get(mid1) > mountainArr.get(mid2)) {
                r = mid2;
            } else {
                l = mid1;
            }
        }

        if (l == r) {
            return l;
        } else if (l + 1 == r) {
            if (mountainArr.get(l) > mountainArr.get(r))
                return l;
            else
                return r;
        } else {
            int x = mountainArr.get(l);
            int y = mountainArr.get(l + 1);
            int z = mountainArr.get(l + 2);
            if (x > y && x > z)
                return l;
            else if (y > x && y > z)
                return l + 1;
            else
                return l + 2;
        }
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int highest = getHighest(n, mountainArr);

        int l = 0, r = highest;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mountainArr.get(mid) < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        if (mountainArr.get(l) == target)
            return l;

        l = highest; r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mountainArr.get(mid) > target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        if (mountainArr.get(l) == target)
            return l;

        return -1;
    }
};

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
