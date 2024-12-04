public class isCatPlaying {

    public static boolean isCatPlaying(boolean summer, int temperature) {
        if (summer) {
            // In summer, |
            return temperature >= 25 && temperature <= 45;
        } else {
            //Temperature
            return temperature >= 25 && temperature <= 35;
        }
    }

    public static void main(String[] args) {
        // Test cases
        System.out.println(isCatPlaying(true, 30));  // should return true
        System.out.println(isCatPlaying(true, 46));  // should return false
        System.out.println(isCatPlaying(false, 30)); // should return true
        System.out.println(isCatPlaying(false, 36)); // should return false
    }
}