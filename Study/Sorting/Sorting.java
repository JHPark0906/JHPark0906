import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

public class Sorting {

    static final int REPETITION = 100;
    static int count = 0;
    static long time = 0;
    static int size;
    static long startTime;

    public static void main(String[] args) {
        int[] inputSize = {100, 200, 500, 1000, 2000, 3000, 4000, 5000};
        int[] result = new int[72];
        boolean check = true;

        startTime = System.currentTimeMillis();
        log("Process start.");

        // Quicksort(first)
        for (int i = 0; i < 8; i++) {
            init();
            for (int j = 0; j < REPETITION; j++) {
                int[] arr = randomArray(inputSize[i]);
                long start = System.nanoTime();
                int[] sorted = heapsort(arr);
                time += (System.nanoTime() - start);
                check &= resultCheck(sorted);
            }
            result[2 * i] = count / REPETITION;
            result[2 * i + 1] = (int)(time / REPETITION);
        }
        log("Quicksort that choice first element as pivot is done.");

        // Quicksort(random)
        for (int i = 0; i < 8; i++) {
            init();
            for (int j = 0; j < REPETITION; j++) {
                int[] arr = randomArray(inputSize[i]);
                long start = System.nanoTime();
                int[] sorted = heapsort(arr);
                time += (System.nanoTime() - start);
                check &= resultCheck(sorted);
            }
            result[2 * i + 16] = count / REPETITION;
            result[2 * i + 17] = (int)(time / REPETITION);
        }
        log("Quicksort that choice random element as pivot is done.");

        // Quicksort(median)
        for (int i = 0; i < 8; i++) {
            init();
            for (int j = 0; j < REPETITION; j++) {
                int[] arr = randomArray(inputSize[i]);
                long start = System.nanoTime();
                int[] sorted = heapsort(arr);
                time += (System.nanoTime() - start);
                check &= resultCheck(sorted);
            }
            result[2 * i + 32] = count / REPETITION;
            result[2 * i + 33] = (int)(time / REPETITION);
        }
        log("Quicksort that choice median value of the first, last and middle element as pivot is done.");

        // Heapsort
        for (int i = 0; i < 8; i++) {
            init();
            for (int j = 0; j < REPETITION; j++) {
                int[] arr = randomArray(inputSize[i]);
                long start = System.nanoTime();
                int[] sorted = heapsort(arr);
                time += (System.nanoTime() - start);
                check &= resultCheck(sorted);
            }
            result[2 * i + 48] = count / REPETITION;
            result[2 * i + 49] = (int)(time / REPETITION);
        }
        log("Heapsort is done.");

        // Arrays.sort(arr)
        for (int i = 0; i < 8; i++) {
            init();
            for (int j = 0; j < REPETITION; j++) {
                int[] arr = randomArray(inputSize[i]);
                long start = System.nanoTime();
                Arrays.sort(arr);
                int[] sorted = arr;
                time += (System.nanoTime() - start);
                check &= resultCheck(sorted);
            }
            result[i + 64] = (int)(time / REPETITION);
        }
        log("Using sort method is done.");

        // Print result
        for (int i = 0; i < 80; i++) System.out.print("=");
        System.out.println("");
        System.out.println(check + "\tQS(First)\t\tQS(Random)\t\tQS(Median)\t\tHeapsort\t\t.sort");
        System.out.println("Input\tCount\tTime\tCount\tTime\tCount\tTime\tCount\tTime\tTime");
        for (int i = 0; i < 8; i++) {
            System.out.print(inputSize[i] + "\t");
            if (i < 3) System.out.print("\t");
            System.out.println(result[2 * i] + "\t" + result[2 * i + 1] + "\t"
                    + result[2 * i + 16] + "\t" + result[2 * i + 17] + "\t"
                    + result[2 * i + 32] + "\t" + result[2 * i + 33] + "\t"
                    + result[2 * i + 48] + "\t" + result[2 * i + 49] + "\t"
                    + result[i + 64]);
        }
        for (int i = 0; i < 80; i++) System.out.print("=");
        System.out.println();
        log("Total process is done.");
    }

    public static void init() {
        count = 0;
        time = 0;
    }

    public static void log(String text) {
        int time = (int) ((System.currentTimeMillis() - startTime) / 1000);
        System.out.print("[" + time + "s] ");
        System.out.println(text);
    }

    public static int[] randomArray(int n) {
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr.add(i);
        }
        Collections.shuffle(arr);
        int[] result = new int[n];
        for (int i = 0; i < n; i++) result[i] = arr.get(i);
        return result;
    }

    public static boolean resultCheck(int[] arr) {
        boolean result = true;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i - 1] > arr[i]) {
                result = false;
                break;
            }
        }
        return result;
    }

    public static int[] quicksortFirst(int[] arr, int first, int last) {
        if (last - first <= 1) return arr;

        int pivot = first;

        // quicksort
        return arr;
    }

    public static int[] quicksortRandom(int[] arr, int first, int last) {
        if (last - first <= 1) return arr;

        int pivot = (int) (Math.random() * (last - first));

        // quicksort
        return arr;
    }

    public static int[] quicksortMedian(int[] arr, int first, int last) {
        if (last - first <= 1) return arr;

        int pivot = first;

        // quicksort
        return arr;
    }

    public static int[] heapsort(int[] arr) {
        if (arr.length <= 1) return arr;

        size = arr.length;
        for (int i = size - 1; i >= 0; i--) {
            heapify(arr, i);
        }
        while (size > 0) {
            int temp = arr[0];
            arr[0] = arr[size - 1];
            arr[size - 1] = temp;
            count += 3;
            size--;
            heapify(arr, 0);
        }
        return arr;
    }

    public static void heapify(int[] arr, int i) {
        int next = i;
        if (2 * i + 1 < size && arr[2 * i + 1] > arr[next]) next = 2 * i + 1;
        if (2 * i + 2 < size && arr[2 * i + 2] > arr[next]) next = 2 * i + 2;
        count += 2;

        if (next == i) return;
        int temp = arr[i];
        arr[i] = arr[next];
        arr[next] = temp;
        count++;
        heapify(arr, next);
    }

}
