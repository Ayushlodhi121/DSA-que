//  Leetcode 1089. Duplicate Zeros
//Time Complexity O(n2) Space Complexity O(1)

class Solution {
    public void duplicateZeros(int[] arr) {
        int j = 0;
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] == 0) {
                for (j = arr.length - 1; j > i; j--) {
                    arr[j] = arr[j - 1];
                }
                arr[i + 1] = 0;
                i++;
            }
        }
    }
}

//  Leetcode 977. Squares of a Sorted Array
// Time Complexity O(n)+O(nlogn)=O(nlogn)  Space Complexity O(n)


class Solution {
    public int[] sortedSquares(int[] nums) {
        int size = nums.length;
        int result[] = new int[size];
        for (int i = 0; i < nums.length; i++) {
            result[i] = nums[i] * nums[i];
        }
        Arrays.sort(result);
        return result;
    }
}

// Leetcode 167. Two Sum II - Input Array Is Sorted
// Time Complexity: O(n) Space Complexity: O(1)

class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int result[] = new int[2];
        int left = 0, right = numbers.length - 1, sum = 0;
        while (left < right) {
            sum = numbers[left] + numbers[right];
            if (sum == target) {
                result[0] = left + 1;
                result[1] = right + 1;
                return result;
            } else if (sum > target) {
                right--;
            } else {
                left++;
            }
        }
        return result;
    }
}

//Leetcode 1299. Replace Elements with Greatest Element on Right Side
//Total time complexity: O(n)  Total space complexity: O(n)
class Solution {
    public int[] replaceElements(int[] arr) {
        int arrSize = arr.length;
        int result[] = new int[arrSize];
         
            int max = -1;
            for (int i = arrSize - 1; i >= 0; i--) {
                result[i] = max;
                if (max < arr[i]) {
                    max = arr[i];
                }
            }
        return result;
    }
}

