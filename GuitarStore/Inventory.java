
import java.util.*;

public class Inventory {

    List<Guitar> guitars;

    public Inventory() {
        guitars = new ArrayList<>();
    }

    public void addGuitar(String sn, Builder builder, String model, Type type, Wood wood, double price) {
        Guitar guitar = new Guitar(sn, builder, model, type, wood, price);
        guitars.add(guitar);
    }

    public Guitar getGuitar(String sn) {
        // int g = guitars.indexOf(sn);
        // return guitars.get(g);   
        for (Guitar guitar : guitars) {
            if (guitar.getSerialNumber().equals(sn)) {
                return guitar;
            }
        }
        return null;
    }

    //we have a problem here in strings is lowercasw indexing
    //unwanted spacing , a trim thing , invalid characters
    public List<Guitar> Search(Guitar SearchedGuitar) {
        List<Guitar> matchingGuitars = new ArrayList<>();

        for (Guitar guitar : guitars) {
            if (guitar != null) {
                if (!SearchedGuitar.getBuilder().equals(guitar.getBuilder())) {
                    continue;
                }
                if (!SearchedGuitar.getModel().equalsIgnoreCase(guitar.getModel())) {
                    continue;
                } 
            
                if (!SearchedGuitar.getType().equals(guitar.getType())) {
                    continue;
                } 
            
                if (!(SearchedGuitar.getWood().equals(guitar.getWood()))) {
                    continue;
                }
                matchingGuitars.add(guitar); 
            }
        }
        return matchingGuitars;
    }

}
