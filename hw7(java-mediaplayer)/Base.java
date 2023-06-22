public class Base {
    protected String type;          // Stores the type of the base
    protected String name;          // Stores the name of the base
    protected String dimension;     // Stores the dimension of the base
    protected String duration;      // Stores the duration of the base
    protected String other;         // Stores other information about the base


    public Base(){
        // Default constructor - initializes the instance variables to empty values
        this.type="";
        this.name="";
        this.dimension="";
        this.other="";
        this.duration="";
    }
    public Base(String type,String nam,String dimen,String durat,String oth){
        // Parameterized constructor - initializes the instance variables with provided values
        this.type=type;
        this.name=nam;
        this.dimension=dimen;
        this.other=oth;
        this.duration=durat;
    }
    // Retrieves the name of the base
    public String getName(){
        return name;
    }
    // Retrieves the dimension of the base
    public String getDimension(){
        return dimension;
    }
    // Retrieves the duration of the base
    public String getDuration(){
        return duration;
    }
    // Retrieves other information about the base
    public String getOther(){
        return other;
    }
    // Retrieves the type of the base
    public String getType(){
        return type;
    }
    // Displays information about the base
    public void info(){
        System.out.println("Info:");
        System.out.println("Name: " + name);
        System.out.println("Duration: " + duration);
        System.out.println("Other: " + other);
        System.out.println("Dimension: " + dimension);
        System.out.println("---------------------------");
    }

}