public class Guitar {

    private String serialNumber;
    private GuitarSpec spec;
    private double price;

    public Guitar(String sn, double price,GuitarSpec spec) {
        this.serialNumber = sn;
        this.price = price;
        this.spec = spec;
    }

    // Getters for each field
    public String getSerialNumber() {
        return serialNumber;
    }

   

    public double getPrice() {
        return price;
    }

    // Override toString method to provide a string representation of the Guitar object
    @Override
    public String toString() {
        return "Guitar{" +
                "serialNumber='" + serialNumber + '\'' +
                ", builder=" + builder +
                ", model='" + model + '\'' +
                ", type=" + type +
                ", backWood=" + wood +
                ", price=" + price +
                '}';
    }
}
