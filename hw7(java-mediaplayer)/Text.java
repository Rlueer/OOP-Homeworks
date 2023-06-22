public class Text extends Base implements non_playable,non_visual{

    public Text(String textname,String tother){
        // Constructor for creating an Text object
        // Sets the type, name, duration, other, and dimension of the text
        this.type="text";
        this.name=textname;
        this.other=tother;
        this.dimension="none";
        this.duration="none";
    }
    // Retrieves the name of the text
    public String getName(){
        return name;
    }
    // Retrieves the dimension of the text
    public String getDimension(){
        return dimension;
    }
    // Retrieves the duration of the text
    public String getDuration(){
        return duration;
    }
    // Retrieves other information about the text
    public String getOther(){
        return other;
    }
    // Retrieves the type of the text
    public String getType(){
        return type;
    }
    // Displays information about the text
    public void info(){
        System.out.println("Info:");
        System.out.println("Name: " + name);
        System.out.println("Duration: " + duration);
        System.out.println("Other: " + other);
        System.out.println("Dimension: " + dimension);
        System.out.println("---------------------------");
    }

};