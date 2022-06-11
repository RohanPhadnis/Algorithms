public class Race {

    public static void main(String[] args) {

        long time;
        int[] array;
        int target;
        final int LENGTH = 1000;

        System.out.println("Linear Search");
        array = generateRandArray(LENGTH);
        printArray(array);
        target = choice(array);
        System.out.println("target " + target);
        time = System.nanoTime();
        System.out.println("output: " + Search.linearSearch(array, target));
        System.out.println("time: " + (double) (System.nanoTime() - time) / Math.pow(10, 9));
        System.out.println();
        System.out.println();
        System.out.println();

        System.out.println("Binary Search");
        array = generateSortedArray(LENGTH);
        printArray(array);
        target = choice(array);
        System.out.println("target " + target);
        time = System.nanoTime();
        System.out.println("output: " + Search.binarySearch(array, target));
        System.out.println("time: " + (double) (System.nanoTime() - time) / Math.pow(10, 9));
        System.out.println();
        System.out.println();
        System.out.println();

        System.out.println("Bubble Sort");
        array = generateRandArray(LENGTH);
        printArray(array);
        time = System.nanoTime();
        System.out.print("output: ");
        Sort.bubbleSort(array);
        printArray(array);
        System.out.println("time: " + (double) (System.nanoTime() - time) / Math.pow(10, 9));
        System.out.println();
        System.out.println();
        System.out.println();

        System.out.println("Insertion Sort");
        array = generateRandArray(LENGTH);
        printArray(array);
        time = System.nanoTime();
        System.out.print("output: ");
        Sort.insertionSort(array);
        printArray(array);
        System.out.println("time: " + (double) (System.nanoTime() - time) / Math.pow(10, 9));
        System.out.println();
        System.out.println();
        System.out.println();

        System.out.println("Selection Sort");
        array = generateRandArray(LENGTH);
        printArray(array);
        time = System.nanoTime();
        System.out.print("output: ");
        Sort.selectionSort(array);
        printArray(array);
        System.out.println("time: " + (double) (System.nanoTime() - time) / Math.pow(10, 9));
        System.out.println();
        System.out.println();
        System.out.println();

    }

    public static void printArray(int[] array) {
        System.out.print("[");
        for (int i = 0; i < array.length; i++) {
            if (i < array.length-1) {
                System.out.print(array[i] + ", ");
            } else {
                System.out.print(array[i]);
            }
        }
        System.out.println("]");
    }

    public static int[] generateRandArray(int len) {
        int[] output = new int[len];
        for (int i = 0; i < len; i++) {
            output[i] = (int) (Math.random() * len * 10 + 1);
        }
        return output;
    }

    public static int[] generateSortedArray(int len) {
        int mult = (int) (Math.random() * 100 + 1);
        int add = (int) (Math.random() * 100 + 1);
        int[] output = new int[len];
        for (int i = 0; i < len; i++) {
            output[i] = i * mult + add;
        }
        return output;
    }

    public static int choice(int[] array) {
        return array[(int) (Math.random() * array.length)];
    }
}
