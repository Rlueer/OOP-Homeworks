public class Video extends Base implements visual,playable{

    public Video(String videoname,String vduration,String vother){
        // Constructor for creating an Video object
    // Sets the type, name, duration, other, and dimension of the video
        this.type="video";
        this.name=videoname;
        this.duration=vduration;
        this.other=vother;
        this.dimension="none";
    }
    //Checker function if it is playable
    public void play(){
        System.out.println("Yes");
    }
    // Retrieves the name of the video
    public String getName(){
        return name;
    }
    // Retrieves the dimension of the video
    public String getDimension(){
        return dimension;
    }
    // Retrieves the duration of the video
    public String getDuration(){
        return duration;
    }
    // Retrieves other information about the video
    public String getOther(){
        return other;
    }
    // Retrieves the type of the video
    public String getType(){
        return type;
    }
    // Displays information about the video
    public void info(){
        System.out.println("Info:");
        System.out.println("Name: " + name);
        System.out.println("Duration: " + duration);
        System.out.println("Other: " + other);
        System.out.println("Dimension: " + dimension);
        System.out.println("---------------------------");
    }

};