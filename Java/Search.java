public class Search {

    public static int linearSearch(int[] array, int target) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] == target) {
                return i;
            }
        }
        return -1;
    }

    public static int recursiveLinearSearch(int[] array, int target) {
        return recursiveLinearSearch(array, target, 0);
    }

    public static int recursiveLinearSearch(int[] array, int target, int index) {
        if (index >= array.length) { return -1; }
        else if (array[index] == target) { return index; }
        else { return recursiveLinearSearch(array, target, index + 1); }
    }

    public static int binarySearch(int[] array, int target) {
        int low = 0;
        int high = array.length - 1;
        int mid = (low + high) / 2;
        while (low <= high) {
            if (array[mid] == target) {
                return mid;
            } else if (array[mid] > target) {
                high = mid - 1;
            } else if (array[mid] < target) {
                low = mid + 1;
            }
            mid = (low + high) / 2;
        }
        return -1;
    }

    public static int recursiveBinarySearch(int[] array, int target) {
        return recursiveBinarySearch(array, target, 0, array.length);
    }

    public static int recursiveBinarySearch(int[] array, int target, int low, int high) {
        int avg = (low + high) / 2;
        if (low == high && array[avg] != target) { return -1; }
        else if (array[avg] == target) { return avg; }
        else if (array[avg] > target) { return recursiveBinarySearch(array, target, low, avg); }
        else if (array[avg] < target) { return recursiveBinarySearch(array, target, avg, high); }
        else { return 0; }
    }
}
