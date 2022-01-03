public class Solution {
    /**
     * @param str: An array of char
     * @param left: a left offset
     * @param right: a right offset
     * @return: return a rotate string
     *
     * 描述
     * Given a string(Given in the way of char array), a right offset and a left offset, move the string according to the given offset and save it in a new result set. (left offest represents the offset of a string to the left,right offest represents the offset of a string to the right,the total offset is calculated from the left offset and the right offset, split two strings at the total offset and swap positions)。
     *
     * 注意事项
     * 请注意 left 和 right 有可能溢出 所以要mod 用此来解决复杂度
     *
     * 样例
     * Example 1:
     *
     * Input：str ="abcdefg", left = 3, right = 1
     * Output："cdefgab"
     * Explanation：The left offset is 3, the right offset is 1, and the total offset is left 2. Therefore, the original string moves to the left and becomes "cdefg"+ "ab".
     *
     * Input：str="abcdefg", left = 0, right = 0
     * Output："abcdefg"
     * Explanation：The left offset is 0, the right offset is 0, and the total offset is 0. So the string remains unchanged.
     *
     * Input：str = "abcdefg",left = 1, right = 2
     * Output："gabcdef"
     * Explanation：The left offset is 1, the right offset is 2, and the total offset is right 1. Therefore, the original string moves to the left and becomes "g" + "abcdef".
     */
    public String RotateString2(String str, int left, int right) {
        // write your code here
        int finalshift = 0;
        int strsize = str.length();
        if (left >= right) {
            finalshift = (left - right) % strsize ;
            return str.substring(finalshift) + str.substring(0, finalshift);
        }
        finalshift = (str.length() - (right - left)  % strsize);
        String newleft = str.substring(finalshift);
        String newright = str.substring(0,finalshift);
        return str.substring(finalshift) + str.substring(0, finalshift);
    }
}