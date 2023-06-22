public class Audio extends Base implements playable,non_visual{

    public Audio(String audioname,String aduration,String aother){
        // Constructor for creating an Audio object
        // Sets the type, name, duration, other, and dimension of the audio
        this.type="audio";
        this.name=audioname;
        this.duration=aduration;
        this.other=aother;
        this.dimension="none";
    }
    //Checker function if it is playable
    public void play(){
        System.out.println("Yes");
    }

    // Retrieves the name of the audio
    public String getName(){
        return name;
    }
    // Retrieves the dimension of the audio
    public String getDimension(){
        return dimension;
    }
    // Retrieves the duration of the audio
    public String getDuration(){
        return duration;
    }
    // Retrieves other information about the audio
    public String getOther(){
        return other;
    }
    // Retrieves the type of the audio
    public String getType(){
        return type;
    }
    // Displays information about the audio
    public void info(){
        System.out.println("Info:");
        System.out.println("Name: " + name);
        System.out.println("Duration: " + duration);
        System.out.println("Other: " + other);
        System.out.println("Dimension: " + dimension);
        System.out.println("---------------------------");
    }

};