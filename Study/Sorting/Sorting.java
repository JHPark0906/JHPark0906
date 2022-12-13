import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Sorting {

    static final int REPETITION = 100;

    static int count = 0;

    static long time = 0;

    static int[] result = new int[32];

    static int size;

    public static void main(String[] args) {
        int[] inputSize = {100, 200, 500, 1000, 2000, 3000, 4000, 5000};
        boolean check = true;

        for (int i = 0; i < 8; i++) {
            init();
            for (int j = 0; j < REPETITION; j++) {
                ArrayList arr = randomArray(inputSize[i]);
                long start = System.nanoTime();
                ArrayList<Integer> result = quicksort(arr);
                time += (System.nanoTime() - start);
                check &= checker(result);
            }
            result[2 * i] = count / REPETITION;
            result[2 * i + 1] = (int)(time / REPETITION);
        }

        for (int i = 0; i < 8; i++) {
            init();
            for (int j = 0; j < REPETITION; j++) {
                ArrayList arr = randomArray(inputSize[i]);
                long start = System.nanoTime();
                ArrayList<Integer> result = heapsort(arr);
                time += (System.nanoTime() - start);
                check &= checker(result);
            }
            result[2 * i + 16] = count / REPETITION;
            result[2 * i + 17] = (int)(time / REPETITION);
        }

        System.out.println(check);
        System.out.println("Quicksort\t\tHeapsort");
        System.out.println("Count\tTime\tCount\tTime");
        for(int i = 0; i < 8; i++) {
            System.out.println(result[2 * i] + "\t" + result[2 * i + 1] + "\t" + result[2 * i + 16] + "\t" + result[2 * i + 17]);
        }
    }

    public static void init() {
        count = 0;
        time = 0;
    }

    public static ArrayList<Integer> randomArray(int n) {
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr.add(i);
        }
        Collections.shuffle(arr);
        return arr;
    }

    public static boolean checker(ArrayList<Integer> arr) {
        boolean result = true;
        for (int i = 1; i < arr.size(); i++) {
            if (arr.get(i - 1) > arr.get(i)) {
                result = false;
                break;
            }
        }
        return result;
    }

    public static ArrayList<Integer> quicksort(ArrayList<Integer> arr){
        if (arr.size() <= 1) return arr;
        int pivot = arr.get(arr.size() / 2);
        ArrayList<Integer> left = new ArrayList<>();
        ArrayList<Integer> equal = new ArrayList<>();
        ArrayList<Integer> right = new ArrayList<>();
        for (int n : arr) {
            count += 2;
            if (n < pivot) {
                left.add(n);
            }
            else if (n > pivot) {
                right.add(n);
            }
            else {
                equal.add(n);
            }
        }
        return (ArrayList<Integer>) Stream.of(quicksort(left), equal, quicksort(right)).flatMap(Collection::stream).collect(Collectors.toList());
    }

    public static ArrayList<Integer> heapsort(ArrayList<Integer> arr) {
        if (arr.size() <= 1) return arr;
        size = arr.size();
        for (int i = size - 1; i >= 0; i--) {
            heapify(arr, i);
        }
        while (size > 0) {
            Collections.swap(arr, 0, size - 1);
            count++;
            size--;
            heapify(arr, 0);
        }
        return arr;
    }

    public static void heapify(ArrayList<Integer> arr, int i) {
        int next = i;
        if (2 * i + 1 < size && arr.get(2 * i + 1) > arr.get(next)) next = 2 * i + 1;
        if (2 * i + 2 < size && arr.get(2 * i + 2) > arr.get(next)) next = 2 * i + 2;
        count += 2;

        if (next == i) return;
        Collections.swap(arr, i, next);
        count++;
        heapify(arr, next);
    }

}
