public class MergeSort {

    public static void main(String[] args) {
        int[] array = generateArray(10);
        printArray(array);
        int[] sortedArray = mergeSort(array);
        printArray(sortedArray);
    }

    public static int randInt() {
        return (int) (Math.random() * 100);
    }

    public static int[] generateArray(int size) {
        int[] output = new int[size];
        for (int i = 0; i < size; i++) {
            output[i] = randInt();
        }
        return output;
    }

    public static int[] mergeSort(int[] array) {
        if (array.length <= 1) {
            return array;
        }
        int split = array.length / 2;
        int[] array1 = new int[split];
        int[] array2 = new int[array.length - split];
        for (int i = 0; i < array.length; i++) {
            if (i < split) {
                array1[i] = array[i];
            } else {
                array2[i - split] = array[i];
            }
        }
        return merge(mergeSort(array1), mergeSort(array2));
    }

    public static int[] merge(int[] array1, int[] array2) {
        int index1 = 0;
        int index2 = 0;
        int[] output = new int[array1.length + array2.length];
        while (index1 < array1.length && index2 < array2.length) {
            if (array1[index1] <= array2[index2]) {
                output[index1 + index2] = array1[index1];
                index1++;
            } else {
                output[index1 + index2] = array2[index2];
                index2++;
            }
        }
        while (index1 < array1.length) {
            output[index1 + array2.length] = array1[index1];
            index1++;
        }
        while (index2 < array2.length) {
            output[index2 + array1.length] = array2[index2];
            index2++;
        }
        return output;
    }

    public static void printArray(int[] array) {
        for (int i: array) {
            System.out.print(i + "\t");
        }
        System.out.println();
    }

}