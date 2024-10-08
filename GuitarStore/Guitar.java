public class Guitar {

    private String serialNumber, model;
    private Builder builder;
    private Type type;
    private Wood wood;
    private double price;

    public Guitar(String sn, Builder builder, String model, Type type, Wood wood, double price) {
        this.serialNumber = sn;
        this.builder = builder;
        this.model = model;
        this.type = type;
        this.wood = wood;
        this.price = price;
    }

    // Getters for each field
    public String getSerialNumber() {
        return serialNumber;
    }

    public String getModel() {
        return model;
    }

    public Builder getBuilder() {
        return builder;
    }

    public Type getType() {
        return type;
    }

    public Wood getWood() {
        return wood;
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