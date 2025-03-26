import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);
    private static Album album = new Album("Album1", "Artist1");
    private static LinkedList<Song> playlist = new LinkedList<>();

    public static void main(String[] args) {
        boolean quit = false;
        printMenu();
        while (!quit) {
            System.out.println("Enter your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 0:
                    printMenu();
                    break;
                case 1:
                    addSongToAlbum();
                    break;
                case 2:
                    addSongToPlaylistByTrackNumber();
                    break;
                case 3:
                    addSongToPlaylistByTitle();
                    break;
                case 4:
                    printPlaylist();
                    break;
                case 5:
                    quit = true;
                    break;
            }
        }
    }

    private static void printMenu() {
        System.out.println("Menu:");
        System.out.println("0 - Print menu");
        System.out.println("1 - Add song to album");
        System.out.println("2 - Add song to playlist by track number");
        System.out.println("3 - Add song to playlist by title");
        System.out.println("4 - Print playlist");
        System.out.println("5 - Quit");
    }

    private static void addSongToAlbum() {
        System.out.println("Enter song title: ");
        String title = scanner.nextLine();
        System.out.println("Enter song duration: ");
        double duration = scanner.nextDouble();
        scanner.nextLine();
        if (album.addSong(title, duration)) {
            System.out.println("Song added to album.");
        } else {
            System.out.println("Song already exists in album.");
        }
    }

    private static void addSongToPlaylistByTrackNumber() {
        System.out.println("Enter track number: ");
        int trackNumber = scanner.nextInt();
        scanner.nextLine();
        if (album.addToPlayList(trackNumber, playlist)) {
            System.out.println("Song added to playlist.");
        } else {
            System.out.println("Track number not found.");
        }
    }

    private static void addSongToPlaylistByTitle() {
        System.out.println("Enter song title: ");
        String title = scanner.nextLine();
        if (album.addToPlayList(title, playlist)) {
            System.out.println("Song added to playlist.");
        } else {
            System.out.println("Song not found in album.");
        }
    }

    private static void printPlaylist() {
        System.out.println("Playlist:");
        for (Song song : playlist) {
            System.out.println(song);
        }
    }
}