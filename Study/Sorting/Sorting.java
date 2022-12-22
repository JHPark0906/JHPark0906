import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Sorting {

    static final int REPETITION = 10000;
    static long count = 0;
    static long time = 0;
    static int size;
    static long startTime;
    static boolean isWarned = false;

    public static void main(String[] args) {
        int[] inputSize = {100, 200, 500, 1000, 2000, 3000, 4000, 5000};
        long[] result = new long[72];
        boolean check = true;

        startTime = System.currentTimeMillis();
        log("Process start.");

        // Quicksort(first)
        log("Quicksort that choice first element as a pivot is starting now.");
        isWarned = false;
        for (int i = 0; i < 8; i++) {
            init();
            for (int j = 0; j < REPETITION; j++) {
                int[] arr = randomArray(inputSize[i]);
                long start = System.nanoTime();
                quicksortFirst(arr, 0, arr.length - 1);
                time += (System.nanoTime() - start);
                check &= resultCheck(arr);
                if (!isWarned && !check) {
                    log("Warning. Result is not sorted.");
                    isWarned = true;
                }
            }
            result[2 * i] = count / REPETITION;
            result[2 * i + 1] = (int)(time / REPETITION);
        }
        log("Quicksort that choice first element as a pivot is done.");

        // Quicksort(random)
        log("Quicksort that choice random element as a pivot is starting now.");
        isWarned = false;
        for (int i = 0; i < 8; i++) {
            init();
            for (int j = 0; j < REPETITION; j++) {
                int[] arr = randomArray(inputSize[i]);
                long start = System.nanoTime();
                quicksortRandom(arr, 0, arr.length - 1);
                time += (System.nanoTime() - start);
                check &= resultCheck(arr);
                if (!isWarned && !check) {
                    log("Warning. Result is not sorted.");
                    isWarned = true;
                }
            }
            result[2 * i + 16] = count / REPETITION;
            result[2 * i + 17] = (int)(time / REPETITION);
        }
        log("Quicksort that choice random element as a pivot is done.");

        // Quicksort(median)
        log("Quicksort that choice median value of the first, last and middle element as a pivot is starting now.");
        isWarned = false;
        for (int i = 0; i < 8; i++) {
            init();
            for (int j = 0; j < REPETITION; j++) {
                int[] arr = randomArray(inputSize[i]);
                long start = System.nanoTime();
                quicksortMedian(arr, 0, arr.length - 1);
                time += (System.nanoTime() - start);
                check &= resultCheck(arr);
                if (!isWarned && !check) {
                    log("Warning. Result is not sorted.");
                    isWarned = true;
                }
            }
            result[2 * i + 32] = count / REPETITION;
            result[2 * i + 33] = (int)(time / REPETITION);
        }
        log("Quicksort that choice median value of the first, last and middle element as a pivot is done.");

        // Heapsort
        log("Heapsort is starting now.");
        isWarned = false;
        for (int i = 0; i < 8; i++) {
            init();
            for (int j = 0; j < REPETITION; j++) {
                int[] arr = randomArray(inputSize[i]);
                long start = System.nanoTime();
                int[] sorted = heapsort(arr);
                time += (System.nanoTime() - start);
                check &= resultCheck(sorted);
                if (!isWarned && !check) {
                    log("Warning. Result is not sorted.");
                    isWarned = true;
                }
            }
            result[2 * i + 48] = count / REPETITION;
            result[2 * i + 49] = (int)(time / REPETITION);
        }
        log("Heapsort is done.");

        // Arrays.sort(arr)
        log("Sort with java's sorting method is starting now.");
        isWarned = false;
        for (int i = 0; i < 8; i++) {
            init();
            for (int j = 0; j < REPETITION; j++) {
                int[] arr = randomArray(inputSize[i]);
                long start = System.nanoTime();
                Arrays.sort(arr);
                time += (System.nanoTime() - start);
                check &= resultCheck(arr);
                if (!isWarned && !check) {
                    log("Warning. Result is not sorted.");
                    isWarned = true;
                }
            }
            result[i + 64] = (int)(time / REPETITION);
        }
        log("Using sort method is done.");

        // Print result
        for (int i = 0; i < 80; i++) System.out.print("=");
        System.out.println("");
        System.out.println(check + "\tQS(First)\t\tQS(Random)\t\tQS(Median)\t\tHeapsort\t\tSort");
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
        if (!check) log("Warning. There are some problems.");
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

    public static void quicksortFirst(int[] arr, int low, int high) {
        if (arr == null || arr.length == 0) {
            return;
        }
        if (low >= high) {
            return;
        }

        // Choice pivot
        int pivot = arr[low];

        int i = low, j = high;
        while (i <= j) {
            count++;
            while (arr[i] < pivot) {
                count++;
                i++;
            }
            while (arr[j] > pivot) {
                count++;
                j--;
            }
            if (i <= j) {
                swap(arr, i, j);
                i++;
                j--;
            }
        }
        count++;
        if (low < j) {
            quicksortFirst(arr, low, j);
        }
        count++;
        if (high > i) {
            quicksortFirst(arr, i, high);
        }
    }

    public static void quicksortRandom(int[] arr, int low, int high) {
        if (arr == null || arr.length == 0) {
            return;
        }
        if (low >= high) {
            return;
        }

        // Choice pivot
        int pivot = arr[(int)(Math.random() * (high - low) + low)];

        int i = low, j = high;
        while (i <= j) {
            count++;
            while (arr[i] < pivot) {
                count++;
                i++;
            }
            while (arr[j] > pivot) {
                count++;
                j--;
            }
            count++;
            if (i <= j) {
                swap(arr, i, j);
                i++;
                j--;
            }
        }
        count++;
        if (low < j) {
            quicksortFirst(arr, low, j);
        }
        count++;
        if (high > i) {
            quicksortFirst(arr, i, high);
        }
    }

    public static void quicksortMedian(int[] arr, int low, int high) {
        if (arr == null || arr.length == 0) {
            return;
        }
        if (low >= high) {
            return;
        }

        // Choice pivot
        int pivot;
        int mid = low + (high - low) / 2;
        count++;
        if (arr[low] <= arr[high]) {
            count++;
            if (arr[mid] <= arr[high]) {
                pivot = arr[mid];
            } else {
                count++;
                if (arr[high] <= arr[low]) {
                    pivot = arr[low];
                } else {
                    pivot = arr[high];
                }
            }
        } else {
            count++;
            if (arr[mid] <= arr[high]) {
                count++;
                if (arr[high] <= arr[low]) {
                    pivot = arr[high];
                } else {
                    pivot = arr[low];
                }
            } else {
                pivot = arr[mid];
            }
        }

        int i = low, j = high;
        while (i <= j) {
            count++;
            while (arr[i] < pivot) {
                count++;
                i++;
            }
            while (arr[j] > pivot) {
                count++;
                j--;
            }
            count++;
            if (i <= j) {
                swap(arr, i, j);
                i++;
                j--;
            }
        }
        count++;
        if (low < j) {
            quicksortFirst(arr, low, j);
        }
        count++;
        if (high > i) {
            quicksortFirst(arr, i, high);
        }
    }

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        count += 3;
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
        count += 3;
        heapify(arr, next);
    }

}
