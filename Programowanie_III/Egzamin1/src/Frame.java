import javax.swing.*;
import java.awt.*;

public class Frame extends JFrame {
    private static final int WIDTH = 500;
    private static final int HEIGHT = 500;
    public Frame(String name)
    {
        setTitle(name);
        setSize(WIDTH, HEIGHT);

        Panel panel = new Panel();
        panel.setBackground(Color.yellow);
        Container content = getContentPane();
        content.add(panel);
    }
}
