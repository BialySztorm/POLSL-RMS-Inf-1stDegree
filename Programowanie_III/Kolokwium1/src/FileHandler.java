import java.io.BufferedReader;
import java.io.IOException;

public class FileHandler {
    public void readFileContent(String filePath) throws IOException {
        try (BufferedReader reader = new BufferedReader(new java.io.FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            throw new IOException("Error reading the file", e);
        }
    }
}
