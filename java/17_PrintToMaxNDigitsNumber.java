package java;

/**
 * Print from 1 to the max n-digit number.
 */
class Q17 {
    // ================= method 1 ===================
    public static void print1ToMaxNDigits(int n) {
        if (n <= 0) {
            System.out.println("Invalid input");
            return;
        }

        char[] num = new char[n];
        for (int i = 0; i < n; i++) { // default value in array is
            num[i] = '0';
        }

        while (!plusOne(num)) {
            printNumber(num);
        }
        System.out.println();
    }

    private static boolean plusOne(char[] num) {
        int carry = 0;
        boolean isOverflow = false;

        for (int i = num.length - 1; i >= 0; i--) {
            int sum = (num[i] - '0') + carry;
            if (i == num.length - 1) {
                sum++;
            }
            if (sum >= 10) {
                if (i == 0) {
                    isOverflow = true;
                } else {
                    sum -= 10;
                    carry = 1;
                    num[i] = (char) ('0' + sum);
                }
            } else {
                num[i] = (char) ('0' + sum);
                break;
            }
        }

        return isOverflow;
    }

    private static void printNumber(char[] num) {
        boolean isLeadingZero = true;

        for (int i = 0; i < num.length; i++) {
            if (isLeadingZero && num[i] != '0') {
                isLeadingZero = false;
            }
            if (!isLeadingZero) {
                System.out.print(num[i]);
            }
        }
        System.out.print(" ");
    }

    // ===================== method 2 =========================
    public static void print1ToMaxNDigits_2(int n) {
        if (n <= 0) {
            System.out.println("Invalid input");
            return;
        }

        char[] num = new char[n];
        helper(num, n, 0);
        System.out.println();
    }

    private static void helper(char[] num, int length, int idx) {
        // recursion terminates
        if (idx == length) {
            printNumber(num);
            return;
        }

        for (int i = 0; i < 10; i++) {
            num[idx] = (char) (i + '0');
            helper(num, length, idx + 1);
        }
    }

    /** Unit testing */
    private static void test(int n) {
        System.out.println("======== n=" + n + " =========");
        print1ToMaxNDigits(n);
        print1ToMaxNDigits_2(n);
    }

    /** Testing driver */
    public static void main(String[] args) {
        test(1);
        test(2);
        test(3);
        test(0);
        test(-1);

        // test(10);
    }
}
