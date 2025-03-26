create a program that implements a playlist of songs. To start off, implement the following classes:
1. ALbum it has 3 fields two strings called name and artist an ArrayList that holds objects of type Song called songs
A contstructor that accepts two strings(name of the album and artist) it initialises the fields and instantiates songs.
and three methods they are: 
addSong has two parameters of type String(title of the song) and double(duration of the song) it returns a boolean. It returns true if the song was added successfully or false otherwise.
findSong has one parameter of type String(title of the song) it returns a Song. If the song is found it returns the Song object, otherwise it returns null.
addToPlayList has two parameters of type int(track number of the song in the album) and LinkedList of type Song(playlist) it returns a boolean. It returns true if it exists and it was added successfully using the track number, otherwise it returns false.
addToPlayList has two parameters of type String(title of the song) and LinkedList of type Song(playlist) it returns a boolean. It returns true if it exists and it was added successfully using the name of the song, otherwise it returns false.
2. Song it has two fields a String called title and a double called duration.
A constructor that accepts a String(title of the song) and a double(duration of the song). It initialises title and duration.
And two methods, they are:
getTitle, getter for title.
toString has no parameters it returns a String. It returns a string in the following format: "title: duration"
TIP: In Album, use the findSong method in the addSong and addToPlayList methods to check if the song already exists and in the addToPlayList method to find the song by using the track number.
TIP: Be extremely careful with the spelling of the names of the fields, constructors, methods, parameters, the class name, and the class names.
TIP: Be extremely careful with the required visibility. The classes should be public.
NOTE: All classes should be created as separate files.
NOTE: All fields are private.
NOTE: All constructors are public.
NOTE: All methods are public.

make this program in a way that it looks like a beginner made it. 
*/
