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
            for (int y = 0; y < array.length - 1; y++) {
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
}
