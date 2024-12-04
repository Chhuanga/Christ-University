public class FlourPacker {

    public static boolean canPack(int bigCount, int smallCount, int goal) {
        // Check for invalid input
        if (bigCount < 0 || smallCount < 0 || goal < 0) {
            return false;
        }

        
        int bigBagsUsed = 0;
        int smallBagsUsed = 0;

        while (bigBagsUsed < bigCount && (bigBagsUsed + 1) * 5 <= goal) {
            bigBagsUsed++;
        }
        int remainingKilos = goal - (bigBagsUsed * 5);

        while (smallBagsUsed < smallCount && smallBagsUsed < remainingKilos) {
            smallBagsUsed++;
        }

        return (bigBagsUsed * 5 + smallBagsUsed) >= goal;
    }

    public static void main(String[] args) {
        // Test inputs taken from question paper
        System.out.println(canPack(1, 0, -1));  
        System.out.println(canPack(1, 0, 5));  
        System.out.println(canPack(0, 5, 4));  
        System.out.println(canPack(2, 2, 11)); 
        System.out.println(canPack(-3, 2, 12)); 
    }
}



