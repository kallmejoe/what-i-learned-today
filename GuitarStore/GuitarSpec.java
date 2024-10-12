class GuitarSpec{

    private int numOfStrings;
    private Builder builder;
    private String model;
    private Type type;
    private Wood wood;

    public GuitarSpec(Builder builder, String model, Type type, Wood wood,int numOfStrings) {
        this.builder = builder;
        this.model = model;
        this.type = type;
        this.wood = wood;
        this.numOfStrings = numOfStrings;
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

    public int getNumOfStrings(){
        return numOfStrings;
    }

    public boolean matches(GuitarSpec otherSpec) {
        if (builder != otherSpec.builder)
          return false;
        if ((model != null) && (!model.equals("")) &&
            (!model.toLowerCase().equals(otherSpec.model.toLowerCase())))
          return false;
        if (type != otherSpec.type)
          return false;
        if (numOfStrings != otherSpec.numOfStrings)
          return false;
        return true;
      }
}
