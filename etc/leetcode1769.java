class Solution {
    public int[] minOperations(String boxes) {
        int boxesSize = boxes.length();
        int[] ans = new int[boxesSize];

        int count = 0, totalCount = 0;
        for(int i = 0; i < boxesSize; i++) {
            ans[i] += totalCount;
            count += boxes.charAt(i) == '1' ? 1 : 0;
            totalCount += count;
        }

        count = 0;
        totalCount = 0;
        for(int i = boxesSize -1; i >= 0; i--) {
            ans[i] += totalCount;
            count += boxes.charAt(i) == '1' ? 1 : 0;
            totalCount += count;
        }
        return ans;
    }
}