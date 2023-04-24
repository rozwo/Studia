//
// Autor: Krzysztof Ostrowski, 336969
// Programowanie obiektowe. Pracownia
// 18.04.2023, Wersja 1.
//
// Lista 7
// Moduł wprowadzający klasę EdytorFilmu
//
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import javax.swing.*;

public class EdytorFilmu extends JComponent implements ActionListener{

    Film film;
    String nazwaPliku;
    JTextField tytul;
    JTextField rezyser;
    JTextField rokProdukcji;

    // Konstruktor przyjmujący obiekt do edycji.
    public EdytorFilmu(Film film, String nazwaPliku){
        this.film = film;
        this.nazwaPliku = nazwaPliku;

        List<String> pola = film.dajPola();
        tytul = new JTextField(pola.get(0));
        rezyser = new JTextField(pola.get(1));
        rokProdukcji = new JTextField(pola.get(2));

        run();
    }

    // Konstruktor wczytujący z pliku obiekt do edycji.
    public EdytorFilmu(String nazwaPliku){

        this.nazwaPliku = nazwaPliku;
        this.film = new Film("", "", 0);

        // Sprawdzanie czy plik istnieje.
        File f = new File(nazwaPliku);
        if(f.exists() && !f.isDirectory()) {
            film.wczytaj(nazwaPliku);
        }

        List<String> pola = film.dajPola();
        tytul = new JTextField(pola.get(0));
        rezyser = new JTextField(pola.get(1));
        rokProdukcji = new JTextField(pola.get(2));

        run();
    }

    // Wyświetlanie okna.
    public void run(){
        JFrame okno = new JFrame("Edytor filmu");
        okno.setSize(400, 200);
        okno.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        okno.setLocationRelativeTo(null);


        Container pojemnik = okno.getContentPane();
        pojemnik.setLayout(new GridLayout(4, 2));
        setContainer(pojemnik);

        okno.setVisible(true);
    }

    // Definicja wyglądu pól tektowych i napisów w oknie.
    void setContainer(Container container){
        container.add(new JLabel("Tytuł"));
        container.add(tytul);
        container.add(new JLabel("Reżyser"));
        container.add(rezyser);
        container.add(new JLabel("Rok produkcji"));
        container.add(rokProdukcji);

        JButton button = new JButton("Zapisz do pliku");
        button.addActionListener(this);
        container.add(button);
    }

    // Obsługa aktywowania przycisku.
    public void actionPerformed(ActionEvent e) {
        
        // Sprawdzenie czy rok jest liczbą.
        try{
            int rok = Integer.parseInt(this.rokProdukcji.getText());
        } catch (NumberFormatException nfe){
            JOptionPane.showMessageDialog(new JFrame(), "Rok musi być liczbą całkowitą.");
            return;
        }

        List<String> wynik = new ArrayList<String>();
        wynik.add(this.tytul.getText());
        wynik.add(this.rezyser.getText());
        wynik.add(this.rokProdukcji.getText());

        film.wczytajPola(wynik);
        film.zapisz(nazwaPliku);
        JOptionPane.showMessageDialog(new JFrame(), "Zapisano.");
    }
}
