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
}
