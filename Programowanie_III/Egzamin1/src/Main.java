import java.io.*;

public class Main {
    public static void main(String[] args) {
        String filename = "Ksiazka.ser";
        serialize(filename);
        deserialize(filename);
    }
    public static void serialize(String filename) {
        Ksiazka book= new Ksiazka("abc");
        File file = new File(filename);
        try (ObjectOutputStream objectOutputStream = new ObjectOutputStream(new FileOutputStream(file))) {
            System.out.println("Object saved to: " + file.getAbsolutePath());
            objectOutputStream.writeObject(book);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void deserialize(String filename)
    {
        File file = new File(filename);
        try(ObjectInputStream objectInputStream = new ObjectInputStream(new FileInputStream(file))){
            Ksiazka book = (Ksiazka) objectInputStream.readObject();
            System.out.println("Object readed from: " + file.getAbsolutePath());
            System.out.println(book);
        }
        catch (IOException | ClassNotFoundException e)
        {
            e.printStackTrace();
        }
    }
}