import javax.swing.*;
import java.awt.*;
import java.awt.geom.Line2D;
import java.awt.geom.Rectangle2D;

public class Panel extends JPanel {
    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        double screenSize = 500.0;
        double halfA = 125.0;

        Graphics2D g2 = (Graphics2D)g;
        Rectangle2D rect = new Rectangle2D.Double(screenSize/2 -halfA, screenSize/2 -halfA, screenSize/2, screenSize/2);
        g2.draw(rect);

        double x1 = screenSize/2-halfA;
        double y1 = screenSize/2-halfA;
        double x2 = x1 + screenSize/2;
        double y2 = y1 + screenSize/2;
        g2.draw(new Line2D.Double(x1,y1,x2,y2));
        g2.draw(new Line2D.Double(x2,y1,x1,y2));
    }
}