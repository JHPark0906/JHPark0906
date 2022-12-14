import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Sorting {

    static final int REPETITION = 10000;

    static int count = 0;

    static long time = 0;

    static int size;

    public static void main(String[] args) {
        int[] inputSize = {100, 200, 500, 1000, 2000, 3000, 4000, 5000};
        int[] result = new int[72];
        boolean check = true;
        String pivotChoice;

        long startTime = System.currentTimeMillis();

        pivotChoice = "First";
        for (int i = 0; i < 8; i++) {
            init();
            for (int j = 0; j < REPETITION; j++) {
                ArrayList arr = randomArray(inputSize[i]);
                long start = System.nanoTime();
                ArrayList<Integer> sorted = quicksort(arr, pivotChoice);
                time += (System.nanoTime() - start);
                check &= checker(sorted);
            }
            result[2 * i] = count / REPETITION;
            result[2 * i + 1] = (int)(time / REPETITION);
        }
        System.out.print("[" + (System.currentTimeMillis() - startTime) / 1000 + "s] ");
        System.out.println("Quicksort that choice first element as pivot is done.");

        pivotChoice = "Random";
        for (int i = 0; i < 8; i++) {
            init();
            for (int j = 0; j < REPETITION; j++) {
                ArrayList arr = randomArray(inputSize[i]);
                long start = System.nanoTime();
                ArrayList<Integer> sorted = quicksort(arr, pivotChoice);
                time += (System.nanoTime() - start);
                check &= checker(sorted);
            }
            result[2 * i + 16] = count / REPETITION;
            result[2 * i + 17] = (int)(time / REPETITION);
        }
        System.out.print("[" + (System.currentTimeMillis() - startTime) / 1000 + "s] ");
        System.out.println("Quicksort that choice random element as pivot is done.");

        pivotChoice = "Median";
        for (int i = 0; i < 8; i++) {
            init();
            for (int j = 0; j < REPETITION; j++) {
                ArrayList arr = randomArray(inputSize[i]);
                long start = System.nanoTime();
                ArrayList<Integer> sorted = quicksort(arr, pivotChoice);
                time += (System.nanoTime() - start);
                check &= checker(sorted);
            }
            result[2 * i + 32] = count / REPETITION;
            result[2 * i + 33] = (int)(time / REPETITION);
        }
        System.out.print("[" + (System.currentTimeMillis() - startTime) / 1000 + "s] ");
        System.out.println("Quicksort that choice median element as pivot is done.");

        for (int i = 0; i < 8; i++) {
            init();
            for (int j = 0; j < REPETITION; j++) {
                ArrayList arr = randomArray(inputSize[i]);
                long start = System.nanoTime();
                ArrayList<Integer> sorted = heapsort(arr);
                time += (System.nanoTime() - start);
                check &= checker(sorted);
            }
            result[2 * i + 48] = count / REPETITION;
            result[2 * i + 49] = (int)(time / REPETITION);
        }
        System.out.print("[" + (System.currentTimeMillis() - startTime) / 1000 + "s] ");
        System.out.println("Heapsort is done.");

        for (int i = 0; i < 8; i++) {
            init();
            for (int j = 0; j < REPETITION; j++) {
                long start = System.nanoTime();
                randomArray(inputSize[i]).sort(new Comparator<Integer>() {
                    @Override
                    public int compare(Integer o1, Integer o2) {
                        return o2 - o1;
                    }
                });
                time += (System.nanoTime() - start);
            }
            result[i + 64] = (int)(time / REPETITION);
        }
        System.out.print("[" + (System.currentTimeMillis() - startTime) / 1000 + "s] ");
        System.out.println("Using sort method is done.");

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

    public static ArrayList<Integer> quicksort(ArrayList<Integer> arr, String pivotChoice){
        if (arr.size() <= 1) return arr;
        int index = 0;
        int pivot;

        switch (pivotChoice) {
            case "First" -> index = 0;
            case "Random" -> index = (int) (Math.random() * arr.size());
            case "Median" -> {
                count++;
                if (arr.get(0) <= arr.get(arr.size() / 2)) {
                    count++;
                    if (arr.get(arr.size() / 2) <= arr.get(arr.size() - 1)) {
                        index = arr.size() / 2;
                    } else {
                        count++;
                        if (arr.get(0) <= arr.get(arr.size() - 1)) {
                            index = arr.size() - 1;
                        } else {
                            index = 0;
                        }
                    }
                } else {
                    count++;
                    if (arr.get(arr.size() / 2) <= arr.get(arr.size() - 1)) {
                        count++;
                        if (arr.get(0) <= arr.get(arr.size() - 1)) {
                            index = 0;
                        } else {
                            index = arr.size() - 1;
                        }
                    } else {
                        index = arr.size() / 2;
                    }
                }
            }
        }

        pivot = arr.get(index);

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

        ArrayList<Integer> result = new ArrayList<>();
        result.addAll(quicksort(left, pivotChoice));
        result.addAll(equal);
        result.addAll(quicksort(right, pivotChoice));

        return result;
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
