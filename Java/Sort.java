public class Sort {

    public static int getMinIndex(int[] array, int index) {
        int minIndex = index;
        for (int i = index; i < array.length; i++) {
            if (array[minIndex] > array[i]) {
                minIndex = i;
            }
        }
        return minIndex;
    }

    public static void moveUp(int[] array, int from, int to) {
        for (int i = to; i > from; i--) {
            array[i] = array[i-1];
        }
    }

    public static void bubbleSort(int[] array) {
        int temp;
        for (int x = 0; x < array.length; x++) {
            for (int y = 0; y < array.length - 1 - x; y++) {
                if (array[y] > array[y+1]) {
                    temp = array[y];
                    array[y] = array[y+1];
                    array[y+1] = temp;
                }
            }
        }
    }

    public static void recursiveBubbleSort(int[] array) {
        recursiveBubbleSort(array, 0, true);
    }

    public static void recursiveBubbleSort(int[] array, int x, boolean sorted) {
        int temp;
        int index = x % array.length;
        boolean s = sorted;
        if (index + 1 < array.length && array[index] > array[index + 1]) {
            temp = array[index];
            array[index] = array[index + 1];
            array[index + 1] = temp;
            s = false;
        }
        if (x < Math.pow(array.length, 2) && !(x > 0 && x % array.length == 0 && s)) {
            recursiveBubbleSort(array, x+1, s);
        }
    }

    public static void insertionSort(int[] array) {
        int val;
        boolean inserted;
        for (int x = 1; x < array.length; x++) {
            val = array[x];
            inserted = false;
            if (val < array[x-1]) {
                for (int y = x-1; y >= 0; y--) {
                    if (val > array[y] && !inserted) {
                        moveUp(array, y, x);
                        array[y+1] = val;
                        inserted = true;
                    }
                }
                if (!inserted) {
                    moveUp(array, 0, x);
                    array[0] = val;
                }
            }
        }
    }

    public static void recursiveInsertionSort(int[] array) {
        recursiveInsertionSort(array, 1);
    }

    public static void recursiveInsertionSort(int[] array, int index) {
        int count = 0;
        int temp;
        if (index < array.length) {
            while (array[count] <= array[index] && count < index) {
                count += 1;
            }
            temp = array[index];
            moveUp(array, count, index);
            array[count] = temp;
            recursiveInsertionSort(array, index + 1);
        }
    }

    public static void selectionSort(int[] array) {
        int val;
        int minIndex;
        for (int i = 0; i < array.length; i++) {
            minIndex = getMinIndex(array, i);
            val = array[i];
            array[i] = array[minIndex];
            array[minIndex] = val;
        }
    }

    public static void recursiveSelectionSort(int[] array) {
        recursiveSelectionSort(array, 0);
    }

    public static void recursiveSelectionSort(int[] array, int index) {
        if (index < array.length) {
            int minIndex = getMinIndex(array, index);
            int temp = array[index];
            array[index] = array[minIndex];
            array[minIndex] = temp;
            recursiveSelectionSort(array, index + 1);
        }
    }

    public static int[] mergeSort(int[] array) {
        int breakPoint = array.length / 2 + array.length % 2;
        int[] left = new int[breakPoint];
        int[] right = new int[array.length - breakPoint];
        boolean m = false;
        int temp;
        for (int i = 0; i < breakPoint; i++) {
            left[i] = array[i];
            if (i < right.length) {
                right[i] = array[breakPoint + i];
            }
        }
        return combine(new int[][] {left, right});
    }

    public static int[] combine(int[][] array) {
        if (array[0].length > 1) {
            array[0] = mergeSort(array[0]);
        }
        if (array[1].length > 1) {
            array[1] = mergeSort(array[1]);
        }
        int[] output = new int[array[0].length + array[1].length];
        int left = 0;
        int right = 0;
        int i = 0;
        while (left < array[0].length && right < array[1].length) {
            if (array[0][left] < array[1][right]) {
                output[i] = array[0][left];
                left++;
            } else {
                output[i] = array[1][right];
                right++;
            }
            i++;
        }
        if (left == array[0].length) {
            while (right < array[1].length) {
                output[i] = array[1][right];
                right++;
                i++;
            }
        } else if (right == array[1].length) {
            while (left < array[0].length) {
                output[i] = array[0][left];
                left++;
                i++;
            }
        }
        return output;
    }
}
