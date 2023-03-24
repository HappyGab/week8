import java.util.*;

public class week8 {
    
    static {
        System.loadLibrary("stddev");
        System.loadLibrary("mean");
    }
    
    public static native double calculateSTDDev(int[] numbers);
    public static native double calculateMean(int[] numbers);
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of samples to generate: ");
        int numSamples = scanner.nextInt();
        
        Random rand = new Random();
        int[] numbers = new int[numSamples];
        for (int i = 0; i < numSamples; i++) {
            numbers[i] = rand.nextInt(101);
        }
        
        double mean = calculateMean(numbers);
        double stddev = calculateSTDDev(numbers);
        
        System.out.printf("Mean: %.2f\n", mean);
        System.out.printf("Standard Deviation: %.2f\n", stddev);
    }
}