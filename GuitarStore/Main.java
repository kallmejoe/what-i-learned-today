import java.util.*;

public class Main {
    public static void main(String[] args) {
        Inventory inventory = new Inventory();

        // Adding guitars to the inventory
        inventory.addGuitar("SN001", Builder.FENDER, "Stratocaster", Type.ELECTRIC, Wood.ALDER, 1200.00);
        inventory.addGuitar("SN002", Builder.GIBSON, "Les Paul", Type.ELECTRIC, Wood.MAHOGANY, 1500.00);
        inventory.addGuitar("SN003", Builder.MARTIN, "D-28", Type.ACOUSTIC, Wood.MAHOGANY, 2500.00);

        // Retrieving a guitar by serial number
        Guitar guitar = inventory.getGuitar("SN001");
        System.out.println("Retrieved Guitar: " + (guitar != null ? guitar.getModel() : "Not Found"));

        // Finding matching guitars
        Guitar searchedGuitar = new Guitar("SN004", Builder.FENDER, "Stratocaster", Type.ELECTRIC, Wood.ALDER, 1300.00);
        List<Guitar> matchingGuitars = inventory.Search(searchedGuitar);

        System.out.println("Matching Guitars: ");
        for (Guitar match : matchingGuitars) {
            System.out.println("Model: " + match.getModel() + ", Serial Number: " + match.getSerialNumber());
        }
    }
}



