import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Sorting {

    static int count = 0;
    static long time = 0;

    public static void main(String[] args) {

        init();
        for (int i = 0; i <= 100; i++) {
            long start = System.nanoTime();
            quicksort(randomArray(100));
            long end = System.nanoTime();
            time += end - start;
        }
        System.out.print(" 100개:   ");
        System.out.print(count / 100 + "번,  ");
        System.out.println(time / 100 + "ns");

        init();
        for (int i = 0; i <= 100; i++) {
            long start = System.nanoTime();
            quicksort(randomArray(200));
            long end = System.nanoTime();
            time += end - start;
        }
        System.out.print(" 200개:  ");
        System.out.print(count / 100 + "번,  ");
        System.out.println(time / 100 + "ns");

        init();
        for (int i = 0; i <= 100; i++) {
            long start = System.nanoTime();
            quicksort(randomArray(500));
            long end = System.nanoTime();
            time += end - start;
        }
        System.out.print(" 500개:  ");
        System.out.print(count / 100 + "번,  ");
        System.out.println(time / 100 + "ns");

        init();
        for (int i = 0; i <= 100; i++) {
            long start = System.nanoTime();
            quicksort(randomArray(1000));
            long end = System.nanoTime();
            time += end - start;
        }
        System.out.print("1000개: ");
        System.out.print(count / 100 + "번,  ");
        System.out.println(time / 100 + "ns");

        init();
        for (int i = 0; i <= 100; i++) {
            long start = System.nanoTime();
            quicksort(randomArray(2000));
            long end = System.nanoTime();
            time += end - start;
        }
        System.out.print("2000개: ");
        System.out.print(count / 100 + "번, ");
        System.out.println(time / 100 + "ns");

        init();
        for (int i = 0; i <= 100; i++) {
            long start = System.nanoTime();
            quicksort(randomArray(3000));
            long end = System.nanoTime();
            time += end - start;
        }
        System.out.print("3000개: ");
        System.out.print(count / 100 + "번, ");
        System.out.println(time / 100 + "ns");

        init();
        for (int i = 0; i <= 100; i++) {
            long start = System.nanoTime();
            quicksort(randomArray(4000));
            long end = System.nanoTime();
            time += end - start;
        }
        System.out.print("4000개: ");
        System.out.print(count / 100 + "번, ");
        System.out.println(time / 100 + "ns");

        init();
        for (int i = 0; i <= 100; i++) {
            long start = System.nanoTime();
            quicksort(randomArray(5000));
            long end = System.nanoTime();
            time += end - start;
        }
        System.out.print("5000개: ");
        System.out.print(count / 100 + "번, ");
        System.out.println(time / 100 + "ns");

    }

    public static void init() {
        count = 0; time = 0;
    }

    public static ArrayList<Integer> randomArray(int n) {
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr.add(i);
        }
        Collections.shuffle(arr);
        return arr;
    }

    public static ArrayList<Integer> quicksort(ArrayList<Integer> arr){
        if (arr.size() <= 1) return arr;
        int pivot = arr.get(arr.size() / 2);
        ArrayList<Integer> left = new ArrayList<>();
        ArrayList<Integer> equal = new ArrayList<>();
        ArrayList<Integer> right = new ArrayList<>();
        for (int n : arr) {
            count++;
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

    public static ArrayList<Integer> heapsort(ArrayList<Integer> arr){
        return arr;
    }


}
